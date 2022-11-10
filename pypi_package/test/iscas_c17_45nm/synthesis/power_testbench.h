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

    sc_signal_pw<sc_logic> N1 = sc_signal_pw<sc_logic>("N1");
    sc_signal_pw<sc_logic> N2 = sc_signal_pw<sc_logic>("N2");
    sc_signal_pw<sc_logic> N3 = sc_signal_pw<sc_logic>("N3");
    sc_signal_pw<sc_logic> N6 = sc_signal_pw<sc_logic>("N6");
    sc_signal_pw<sc_logic> N7 = sc_signal_pw<sc_logic>("N7");
    sc_signal_pw<sc_logic> N22 = sc_signal_pw<sc_logic>("N22");
    sc_signal_pw<sc_logic> N23 = sc_signal_pw<sc_logic>("N23");
    sc_event ready2update;
    sc_event ready2reset;

    c17* cut;
    power_analysis* power_module;
    std::array<sc_signal_pw<sc_logic>*, 12> signal_arr;
    std::array<sc_signal_pw<sc_logic>*, 5> input_arr;

    SC_HAS_PROCESS(testbench);
    testbench(sc_module_name _name){
        power_module = new power_analysis();
            power_module->read_gate_prop_json("gate_properties.json");
            power_module->read_gate_signal_json("gate_signal_json_file.json", "gate_properties.json");
            power_module->tech_parameter_json("45nm_timing_power.json");
            power_module->read_net_cap_json("gate_cap.json");
        cut = new c17("cut");
            cut->N1(N1);
            cut->N2(N2);
            cut->N3(N3);
            cut->N6(N6);
            cut->N7(N7);
            cut->N22(N22);
            cut->N23(N23);

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
        apply_input_vector<sc_dt::sc_logic, 5>(input_arr, ("11111"));
        wait(SC_ZERO_TIME);
        wait(10, SC_NS);
        ready2update.notify();
    }

    void power_on_cycle(void){
        power_module->update_signal<sc_dt::sc_logic, 12>(signal_arr);
        std::vector<std::string> input_signal_name = {"N1", "N2", "N3", "N6", "N7"};
        power_module->timing_analysis("test", input_signal_name);
        std::vector<float> pwr_INV_X1_1 = power_module->power_per_gate("INV_X1_1");
        std::vector<float> pwr_INV_X1_2 = power_module->power_per_gate("INV_X1_2");
        std::vector<float> pwr_AOI22_X1_1 = power_module->power_per_gate("AOI22_X1_1");
        std::vector<float> pwr_NAND2_X1_1 = power_module->power_per_gate("NAND2_X1_1");
        std::vector<float> pwr_NAND2_X1_2 = power_module->power_per_gate("NAND2_X1_2");
        std::vector<float> pwr_NAND2_X1_3 = power_module->power_per_gate("NAND2_X1_3");
        std::vector<float> pwr_NAND2_X1_4 = power_module->power_per_gate("NAND2_X1_4");

        float dynamic_power = pwr_INV_X1_1[0] + pwr_INV_X1_2[0] + pwr_AOI22_X1_1[0] + pwr_NAND2_X1_1[0] + pwr_NAND2_X1_2[0] + pwr_NAND2_X1_3[0] + pwr_NAND2_X1_4[0] ;
        float net_switching_power = pwr_INV_X1_1[1] + pwr_INV_X1_2[1] + pwr_AOI22_X1_1[1] + pwr_NAND2_X1_1[1] + pwr_NAND2_X1_2[1] + pwr_NAND2_X1_3[1] + pwr_NAND2_X1_4[1] ;
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
        signal_arr[0] = &(N1);
        input_arr[0] = &(N1);
        power_module->set_transition_time("N1", 0.0);
        signal_arr[1] = &(N2);
        input_arr[1] = &(N2);
        power_module->set_transition_time("N2", 0.0);
        signal_arr[2] = &(N3);
        input_arr[2] = &(N3);
        power_module->set_transition_time("N3", 0.0);
        signal_arr[3] = &(N6);
        input_arr[3] = &(N6);
        power_module->set_transition_time("N6", 0.0);
        signal_arr[4] = &(N7);
        input_arr[4] = &(N7);
        power_module->set_transition_time("N7", 0.0);
        signal_arr[5] = &(N22);
        signal_arr[6] = &(N23);
        signal_arr[14] = &(cut->_0_);
        signal_arr[15] = &(cut->_1_);
        signal_arr[16] = &(cut->_2_);
        signal_arr[17] = &(cut->_3_);
        signal_arr[18] = &(cut->_4_);
    }

};
