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

    sc_signal_pw<sc_logic> clk = sc_signal_pw<sc_logic>("clk");
    sc_signal_pw<sc_logic> rst = sc_signal_pw<sc_logic>("rst");
    sc_signal_pw<sc_logic> en = sc_signal_pw<sc_logic>("en");
    sc_signal_pw<sc_logic> clkEn = sc_signal_pw<sc_logic>("clkEn");
    sc_signal_pw<sc_logic> count[4] = sc_signal_pw<sc_logic>("count");
    sc_signal_pw<sc_logic> co = sc_signal_pw<sc_logic>("co");

    sc_event ready2update;
    sc_event ready2reset;

    counter* cut;
    power_analysis* power_module;
    std::array<sc_signal_pw<sc_logic>*, 32> signal_arr;
    std::array<sc_signal_pw<sc_logic>*, 4> input_arr;

    SC_HAS_PROCESS(testbench);
    testbench(sc_module_name _name){
        power_module = new power_analysis();
            power_module->read_gate_prop_json("gate_properties.json");
            power_module->read_gate_signal_json("gate_signal_json_file.json", "gate_properties.json");
            power_module->tech_parameter_json("45nm_timing_power.json");
            power_module->read_net_cap_json("gate_cap.json");
        cut = new counter("cut");
            cut->clk(clk);
            cut->rst(rst);
            cut->en(en);
            cut->clkEn(clkEn);
            cut->count[0](count[0]);
            cut->count[1](count[1]);
            cut->count[2](count[2]);
            cut->count[3](count[3]);
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
        apply_input_vector<sc_dt::sc_logic, 4>(input_arr, ("1111"));
        wait(SC_ZERO_TIME);
        wait(10, SC_NS);
        ready2update.notify();
    }

    void power_on_cycle(void){
        power_module->update_signal<sc_dt::sc_logic, 32>(signal_arr);
        std::vector<std::string> input_signal_name = {"clk", "rst", "en", "clkEn"};
        power_module->timing_analysis("test", input_signal_name);
        std::vector<float> pwr_INV_X1_1 = power_module->power_per_gate("INV_X1_1");
        std::vector<float> pwr_INV_X1_2 = power_module->power_per_gate("INV_X1_2");
        std::vector<float> pwr_INV_X1_3 = power_module->power_per_gate("INV_X1_3");
        std::vector<float> pwr_INV_X1_4 = power_module->power_per_gate("INV_X1_4");
        std::vector<float> pwr_INV_X1_5 = power_module->power_per_gate("INV_X1_5");
        std::vector<float> pwr_AND4_X1_1 = power_module->power_per_gate("AND4_X1_1");
        std::vector<float> pwr_NAND2_X1_1 = power_module->power_per_gate("NAND2_X1_1");
        std::vector<float> pwr_NAND2_X1_2 = power_module->power_per_gate("NAND2_X1_2");
        std::vector<float> pwr_NAND2_X1_3 = power_module->power_per_gate("NAND2_X1_3");
        std::vector<float> pwr_OAI21_X1_1 = power_module->power_per_gate("OAI21_X1_1");
        std::vector<float> pwr_OAI21_X1_2 = power_module->power_per_gate("OAI21_X1_2");
        std::vector<float> pwr_OAI21_X1_3 = power_module->power_per_gate("OAI21_X1_3");
        std::vector<float> pwr_AOI21_X1_1 = power_module->power_per_gate("AOI21_X1_1");
        std::vector<float> pwr_AOI21_X1_2 = power_module->power_per_gate("AOI21_X1_2");
        std::vector<float> pwr_AOI21_X1_3 = power_module->power_per_gate("AOI21_X1_3");
        std::vector<float> pwr_AOI21_X1_4 = power_module->power_per_gate("AOI21_X1_4");
        std::vector<float> pwr_NAND3_X1_1 = power_module->power_per_gate("NAND3_X1_1");
        std::vector<float> pwr_NAND3_X1_2 = power_module->power_per_gate("NAND3_X1_2");
        std::vector<float> pwr_NAND4_X1_1 = power_module->power_per_gate("NAND4_X1_1");
        std::vector<float> pwr_AND3_X1_1 = power_module->power_per_gate("AND3_X1_1");
        std::vector<float> pwr_AND2_X1_1 = power_module->power_per_gate("AND2_X1_1");
        std::vector<float> pwr_DFF_X1_1 = power_module->power_per_gate("DFF_X1_1");
        std::vector<float> pwr_DFF_X1_2 = power_module->power_per_gate("DFF_X1_2");
        std::vector<float> pwr_DFF_X1_3 = power_module->power_per_gate("DFF_X1_3");
        std::vector<float> pwr_DFF_X1_4 = power_module->power_per_gate("DFF_X1_4");
        std::vector<float> pwr_BUF_X1_1 = power_module->power_per_gate("BUF_X1_1");
        std::vector<float> pwr_BUF_X1_2 = power_module->power_per_gate("BUF_X1_2");
        std::vector<float> pwr_BUF_X1_3 = power_module->power_per_gate("BUF_X1_3");
        std::vector<float> pwr_BUF_X1_4 = power_module->power_per_gate("BUF_X1_4");
        std::vector<float> pwr_BUF_X1_5 = power_module->power_per_gate("BUF_X1_5");

        float dynamic_power = pwr_INV_X1_1[0] + pwr_INV_X1_2[0] + pwr_INV_X1_3[0] + pwr_INV_X1_4[0] + pwr_INV_X1_5[0] + pwr_AND4_X1_1[0] + pwr_NAND2_X1_1[0] + pwr_NAND2_X1_2[0] + pwr_NAND2_X1_3[0] + pwr_OAI21_X1_1[0] + pwr_OAI21_X1_2[0] + pwr_OAI21_X1_3[0] + pwr_AOI21_X1_1[0] + pwr_AOI21_X1_2[0] + pwr_AOI21_X1_3[0] + pwr_AOI21_X1_4[0] + pwr_NAND3_X1_1[0] + pwr_NAND3_X1_2[0] + pwr_NAND4_X1_1[0] + pwr_AND3_X1_1[0] + pwr_AND2_X1_1[0] + pwr_DFF_X1_1[0] + pwr_DFF_X1_2[0] + pwr_DFF_X1_3[0] + pwr_DFF_X1_4[0] + pwr_BUF_X1_1[0] + pwr_BUF_X1_2[0] + pwr_BUF_X1_3[0] + pwr_BUF_X1_4[0] + pwr_BUF_X1_5[0] ;
        float net_switching_power = pwr_INV_X1_1[1] + pwr_INV_X1_2[1] + pwr_INV_X1_3[1] + pwr_INV_X1_4[1] + pwr_INV_X1_5[1] + pwr_AND4_X1_1[1] + pwr_NAND2_X1_1[1] + pwr_NAND2_X1_2[1] + pwr_NAND2_X1_3[1] + pwr_OAI21_X1_1[1] + pwr_OAI21_X1_2[1] + pwr_OAI21_X1_3[1] + pwr_AOI21_X1_1[1] + pwr_AOI21_X1_2[1] + pwr_AOI21_X1_3[1] + pwr_AOI21_X1_4[1] + pwr_NAND3_X1_1[1] + pwr_NAND3_X1_2[1] + pwr_NAND4_X1_1[1] + pwr_AND3_X1_1[1] + pwr_AND2_X1_1[1] + pwr_DFF_X1_1[1] + pwr_DFF_X1_2[1] + pwr_DFF_X1_3[1] + pwr_DFF_X1_4[1] + pwr_BUF_X1_1[1] + pwr_BUF_X1_2[1] + pwr_BUF_X1_3[1] + pwr_BUF_X1_4[1] + pwr_BUF_X1_5[1] ;
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
        signal_arr[0] = &(clk);
        input_arr[0] = &(clk);
        power_module->set_transition_time("clk", 0.0);
        signal_arr[1] = &(rst);
        input_arr[1] = &(rst);
        power_module->set_transition_time("rst", 0.0);
        signal_arr[2] = &(en);
        input_arr[2] = &(en);
        power_module->set_transition_time("en", 0.0);
        signal_arr[3] = &(clkEn);
        input_arr[3] = &(clkEn);
        power_module->set_transition_time("clkEn", 0.0);
        signal_arr[4] = &(count[0]);
        signal_arr[5] = &(count[1]);
        signal_arr[6] = &(count[2]);
        signal_arr[7] = &(count[3]);
        signal_arr[8] = &(co);
        signal_arr[9] = &(cut->_0_);
        signal_arr[10] = &(cut->_10_);
        signal_arr[11] = &(cut->_11_);
        signal_arr[12] = &(cut->_12_);
        signal_arr[13] = &(cut->_13_);
        signal_arr[14] = &(cut->_14_);
        signal_arr[15] = &(cut->_15_);
        signal_arr[16] = &(cut->_16_);
        signal_arr[17] = &(cut->_17_);
        signal_arr[18] = &(cut->_18_);
        signal_arr[19] = &(cut->_19_);
        signal_arr[20] = &(cut->_1_);
        signal_arr[21] = &(cut->_20_);
        signal_arr[22] = &(cut->_21_);
        signal_arr[23] = &(cut->_22_);
        signal_arr[24] = &(cut->_23_);
        signal_arr[25] = &(cut->_24_);
        signal_arr[26] = &(cut->_25_);
        signal_arr[27] = &(cut->_2_);
        signal_arr[28] = &(cut->_3_);
        signal_arr[29] = &(cut->_4_);
        signal_arr[30] = &(cut->_5_);
        signal_arr[31] = &(cut->_6_);
        signal_arr[32] = &(cut->_7_);
        signal_arr[33] = &(cut->_8_);
        signal_arr[34] = &(cut->_9_);
    }

};
