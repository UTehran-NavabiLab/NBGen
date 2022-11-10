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
    std::array<sc_signal_pw<sc_logic>*, 14> signal_arr;
    std::array<sc_signal_pw<sc_logic>*, 3> input_arr;

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
        apply_input_vector<sc_dt::sc_logic, 3>(input_arr, ("111"));
        wait(SC_ZERO_TIME);
        wait(10, SC_NS);
        ready2update.notify();
    }

    void power_on_cycle(void){
        power_module->update_signal<sc_dt::sc_logic, 14>(signal_arr);
        std::vector<std::string> input_signal_name = {"i0", "i1", "ci"};
        power_module->timing_analysis("test", input_signal_name);
        std::vector<float> pwr_NAND2_X1_1 = power_module->power_per_gate("NAND2_X1_1");
        std::vector<float> pwr_NAND2_X1_2 = power_module->power_per_gate("NAND2_X1_2");
        std::vector<float> pwr_NAND2_X1_3 = power_module->power_per_gate("NAND2_X1_3");
        std::vector<float> pwr_INV_X1_1 = power_module->power_per_gate("INV_X1_1");
        std::vector<float> pwr_INV_X1_2 = power_module->power_per_gate("INV_X1_2");
        std::vector<float> pwr_INV_X1_3 = power_module->power_per_gate("INV_X1_3");
        std::vector<float> pwr_NAND3_X1_1 = power_module->power_per_gate("NAND3_X1_1");
        std::vector<float> pwr_OAI21_X1_1 = power_module->power_per_gate("OAI21_X1_1");
        std::vector<float> pwr_OAI21_X1_2 = power_module->power_per_gate("OAI21_X1_2");
        std::vector<float> pwr_AND2_X1_1 = power_module->power_per_gate("AND2_X1_1");
        std::vector<float> pwr_NOR2_X1_1 = power_module->power_per_gate("NOR2_X1_1");

        float dynamic_power = pwr_NAND2_X1_1[0] + pwr_NAND2_X1_2[0] + pwr_NAND2_X1_3[0] + pwr_INV_X1_1[0] + pwr_INV_X1_2[0] + pwr_INV_X1_3[0] + pwr_NAND3_X1_1[0] + pwr_OAI21_X1_1[0] + pwr_OAI21_X1_2[0] + pwr_AND2_X1_1[0] + pwr_NOR2_X1_1[0] ;
        float net_switching_power = pwr_NAND2_X1_1[1] + pwr_NAND2_X1_2[1] + pwr_NAND2_X1_3[1] + pwr_INV_X1_1[1] + pwr_INV_X1_2[1] + pwr_INV_X1_3[1] + pwr_NAND3_X1_1[1] + pwr_OAI21_X1_1[1] + pwr_OAI21_X1_2[1] + pwr_AND2_X1_1[1] + pwr_NOR2_X1_1[1] ;
        float total_power = dynamic_power + net_switching_power;
        std::cout << "net switching power: " << net_switching_power << std::endl;
        std::cout << "dynamic power : " << dynamic_power << std::endl;
        std::cout << "total power per cycle: " << total_power << std::endl;
        reset_togglings();
    }

    void reset_togglings(void){
        for(auto& signal_pointer: signal_arr){
            signal_pointer->reset_toggling();
            }
    }

    void access_signals(void){
        signal_arr[0] = &(i0);
        input_arr[0] = &(i0);
        power_module->set_transition_time("i0", 0.0);
        signal_arr[1] = &(i1);
        input_arr[1] = &(i1);
        power_module->set_transition_time("i1", 0.0);
        signal_arr[2] = &(ci);
        input_arr[2] = &(ci);
        power_module->set_transition_time("ci", 0.0);
        signal_arr[3] = &(s);
        signal_arr[4] = &(co);
        signal_arr[5] = &(cut->_0_);
        signal_arr[6] = &(cut->_1_);
        signal_arr[7] = &(cut->_2_);
        signal_arr[8] = &(cut->_3_);
        signal_arr[9] = &(cut->_4_);
        signal_arr[10] = &(cut->_5_);
        signal_arr[11] = &(cut->_6_);
        signal_arr[12] = &(cut->_7_);
        signal_arr[13] = &(cut->_8_);
    }

};
