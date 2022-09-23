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
    sc_signal_pw<sc_logic> i2 = sc_signal_pw<sc_logic>("i2");
    sc_signal_pw<sc_logic> o = sc_signal_pw<sc_logic>("o");
    sc_event ready2update;
    sc_event ready2reset;

    three_level_gate* cut;
    power_analysis* power_module;
    std::array<sc_signal_pw<sc_logic>*, 6> signal_arr;

    SC_HAS_PROCESS(testbench);
    testbench(sc_module_name _name){
        power_analysis* power_module = new power_analysis();
            power_module->read_gate_prop_json("gate_properties_json.json");
            power_module->read_gate_signal_json("gate_signal_json_file.json", "gate_properties_json.json");
            power_module->tech_parameter_json("45nm_timing_power.json");
            power_module->read_net_cap_json("gate_cap.json");
        cut = new three_level_gate("cut");
            cut->i0(i0);
            cut->i1(i1);
            cut->i2(i2);
            cut->o(o);

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
        i2.write(SC_LOGIC_1);
        wait(SC_ZERO_TIME);
        wait(10, SC_NS);
        ready2update.notify();
    }

    void power_on_cycle(void){
        power_module->update_signal<sc_dt::sc_logic, 6>(signal_arr);
        std::vector<std::string> input_signal_name = {"i0", "i1", "i2"};
        power_module->timing_analysis("test", input_signal_name);
        power_module->print_gate();
        float pwr_INV_X1_0 = power_module->power_per_gate("INV_X1_0");
        float pwr_NAND2_X1_0 = power_module->power_per_gate("NAND2_X1_0");
        float pwr_NAND2_X1_1 = power_module->power_per_gate("NAND2_X1_1");
        float pp_total = pwr_INV_X1_0 + pwr_NAND2_X1_0 + pwr_NAND2_X1_1 ;
        std::cout << "total power per cycle: " << pp_total << std::endl;
        reset_togglings();
    }

    void reset_togglings(void){
        for(auto& signal_pointer: signal_arr){
            signal_pointer->reset_toggling();
            }
    }

    void access_signals(void){
        signal_arr[0] = &(cut->_0_);
        signal_arr[1] = &(cut->_1_);
        signal_arr[2] = &(i0);
        power_module->set_transition_time("i0", 0.0);
        signal_arr[3] = &(i1);
        power_module->set_transition_time("i1", 0.0);
        signal_arr[4] = &(i2);
        power_module->set_transition_time("i2", 0.0);
        signal_arr[5] = &(o);
        power_module->set_transition_time("o", 0.0);
    }

};
