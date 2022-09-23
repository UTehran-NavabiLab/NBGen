#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include "systemc.h"
#include "power_netlist.h"
#include "utilities.h"
#include "power_analysis.h"


using namespace sc_core;

SC_MODULE( testbench ) {

    sc_signal_pw<sc_logic> i0 = sc_signal_pw<sc_logic>("i0");
    sc_signal_pw<sc_logic> i1 = sc_signal_pw<sc_logic>("i1");
    sc_signal_pw<sc_logic> ci = sc_signal_pw<sc_logic>("ci");
    sc_signal_pw<sc_logic> s = sc_signal_pw<sc_logic>("s");
    sc_signal_pw<sc_logic> co = sc_signal_pw<sc_logic>("co");
    sc_event ready2update;
    sc_event ready2reset;

    fulladder* cut;
    power_analysis* power_module;
    std::array<sc_signal_pw<sc_logic>*, 7> signal_arr;

    SC_HAS_PROCESS(testbench);
    testbench(sc_module_name _name){
        power_module = new power_analysis();
            power_module->read_gate_prop_json("gate_properties.json");
            power_module->read_gate_signal_json("gate_signal_json_file.json", "gate_properties.json");
            power_module->tech_parameter_json("45nm_timing_power.json");
            power_module->read_net_cap_json("gate_cap.json");
        cut = new fulladder("cut");
            cut->i0(i0);
            cut->i1(i1);
            cut->ci(ci);
            cut->s(s);
            cut->co(co);

        SC_THREAD(signaling);
        SC_METHOD(power_on_cycle);
            sensitive << ready2update;
            dont_initialize();
        access_signals();

    }

    void signaling(void){
        wait(SC_ZERO_TIME);
        reset_togglings();
        wait(10, SC_NS);
        i0.write(SC_LOGIC_1);
        i1.write(SC_LOGIC_1);
        ci.write(SC_LOGIC_1);
        wait(SC_ZERO_TIME);
        wait(10, SC_NS);
        ready2update.notify();
    }

    void power_on_cycle(void){
        power_module->update_signal<sc_dt::sc_logic, 7>(signal_arr);
        std::vector<std::string> input_signal_name = {"i0", "i1", "ci"};
        power_module->timing_analysis("test", input_signal_name);
        power_module->print_gate();
        float pwr_XOR2_X1_0 = power_module->power_per_gate("XOR2_X1_0");
        float pwr_XOR2_X1_1 = power_module->power_per_gate("XOR2_X1_1");
        float pwr_INV_X1_0 = power_module->power_per_gate("INV_X1_0");
        float pwr_AOI22_X1_0 = power_module->power_per_gate("AOI22_X1_0");
        float pp_total = pwr_XOR2_X1_0 + pwr_XOR2_X1_1 + pwr_INV_X1_0 + pwr_AOI22_X1_0 ;
        std::cout << "total power per cycle: " << pp_total << std::endl;
        reset_togglings();
    }

    void reset_togglings(void){
        for(auto& signal_pointer: signal_arr){
            signal_pointer->reset_toggling();
            }
    }

    void access_signals(void){
        signal_arr[0] = &(i0);
        power_module->set_transition_time("i0", 0.0);
        signal_arr[1] = &(i1);
        power_module->set_transition_time("i1", 0.0);
        signal_arr[2] = &(ci);
        power_module->set_transition_time("ci", 0.0);
        signal_arr[3] = &(s);
        signal_arr[4] = &(co);
        signal_arr[9] = &(cut->n4);
        signal_arr[10] = &(cut->n5);
    }

};
