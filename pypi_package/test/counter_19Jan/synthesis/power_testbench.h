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
    std::array<sc_signal_pw<sc_logic>*, 47> signal_arr;
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
        power_module->update_signal<sc_dt::sc_logic, 47>(signal_arr);
        std::vector<std::string> input_signal_name = {"clk", "rst", "en", "clkEn"};
        power_module->timing_analysis("test", input_signal_name);
        std::vector<float> pwr_notg_1 = power_module->power_per_gate("notg_1");
        std::vector<float> pwr_notg_2 = power_module->power_per_gate("notg_2");
        std::vector<float> pwr_notg_3 = power_module->power_per_gate("notg_3");
        std::vector<float> pwr_notg_4 = power_module->power_per_gate("notg_4");
        std::vector<float> pwr_notg_5 = power_module->power_per_gate("notg_5");
        std::vector<float> pwr_notg_6 = power_module->power_per_gate("notg_6");
        std::vector<float> pwr_notg_7 = power_module->power_per_gate("notg_7");
        std::vector<float> pwr_notg_8 = power_module->power_per_gate("notg_8");
        std::vector<float> pwr_nand_n_1 = power_module->power_per_gate("nand_n_1");
        std::vector<float> pwr_nand_n_2 = power_module->power_per_gate("nand_n_2");
        std::vector<float> pwr_nand_n_3 = power_module->power_per_gate("nand_n_3");
        std::vector<float> pwr_nand_n_4 = power_module->power_per_gate("nand_n_4");
        std::vector<float> pwr_nand_n_5 = power_module->power_per_gate("nand_n_5");
        std::vector<float> pwr_nand_n_6 = power_module->power_per_gate("nand_n_6");
        std::vector<float> pwr_nand_n_7 = power_module->power_per_gate("nand_n_7");
        std::vector<float> pwr_nand_n_8 = power_module->power_per_gate("nand_n_8");
        std::vector<float> pwr_nand_n_9 = power_module->power_per_gate("nand_n_9");
        std::vector<float> pwr_nand_n_10 = power_module->power_per_gate("nand_n_10");
        std::vector<float> pwr_nand_n_11 = power_module->power_per_gate("nand_n_11");
        std::vector<float> pwr_nor_n_1 = power_module->power_per_gate("nor_n_1");
        std::vector<float> pwr_nor_n_2 = power_module->power_per_gate("nor_n_2");
        std::vector<float> pwr_nor_n_3 = power_module->power_per_gate("nor_n_3");
        std::vector<float> pwr_nor_n_4 = power_module->power_per_gate("nor_n_4");
        std::vector<float> pwr_nor_n_5 = power_module->power_per_gate("nor_n_5");
        std::vector<float> pwr_nor_n_6 = power_module->power_per_gate("nor_n_6");
        std::vector<float> pwr_nor_n_7 = power_module->power_per_gate("nor_n_7");
        std::vector<float> pwr_nor_n_8 = power_module->power_per_gate("nor_n_8");
        std::vector<float> pwr_nor_n_9 = power_module->power_per_gate("nor_n_9");
        std::vector<float> pwr_nor_n_10 = power_module->power_per_gate("nor_n_10");
        std::vector<float> pwr_dff_1 = power_module->power_per_gate("dff_1");
        std::vector<float> pwr_dff_2 = power_module->power_per_gate("dff_2");
        std::vector<float> pwr_dff_3 = power_module->power_per_gate("dff_3");
        std::vector<float> pwr_dff_4 = power_module->power_per_gate("dff_4");
        std::vector<float> pwr_bufg_1 = power_module->power_per_gate("bufg_1");
        std::vector<float> pwr_bufg_2 = power_module->power_per_gate("bufg_2");
        std::vector<float> pwr_bufg_3 = power_module->power_per_gate("bufg_3");
        std::vector<float> pwr_bufg_4 = power_module->power_per_gate("bufg_4");
        std::vector<float> pwr_bufg_5 = power_module->power_per_gate("bufg_5");
        std::vector<float> pwr_bufg_6 = power_module->power_per_gate("bufg_6");
        std::vector<float> pwr_bufg_7 = power_module->power_per_gate("bufg_7");
        std::vector<float> pwr_bufg_8 = power_module->power_per_gate("bufg_8");
        std::vector<float> pwr_bufg_9 = power_module->power_per_gate("bufg_9");

        float dynamic_power = pwr_notg_1[0] + pwr_notg_2[0] + pwr_notg_3[0] + pwr_notg_4[0] + pwr_notg_5[0] + pwr_notg_6[0] + pwr_notg_7[0] + pwr_notg_8[0] + pwr_nand_n_1[0] + pwr_nand_n_2[0] + pwr_nand_n_3[0] + pwr_nand_n_4[0] + pwr_nand_n_5[0] + pwr_nand_n_6[0] + pwr_nand_n_7[0] + pwr_nand_n_8[0] + pwr_nand_n_9[0] + pwr_nand_n_10[0] + pwr_nand_n_11[0] + pwr_nor_n_1[0] + pwr_nor_n_2[0] + pwr_nor_n_3[0] + pwr_nor_n_4[0] + pwr_nor_n_5[0] + pwr_nor_n_6[0] + pwr_nor_n_7[0] + pwr_nor_n_8[0] + pwr_nor_n_9[0] + pwr_nor_n_10[0] + pwr_dff_1[0] + pwr_dff_2[0] + pwr_dff_3[0] + pwr_dff_4[0] + pwr_bufg_1[0] + pwr_bufg_2[0] + pwr_bufg_3[0] + pwr_bufg_4[0] + pwr_bufg_5[0] + pwr_bufg_6[0] + pwr_bufg_7[0] + pwr_bufg_8[0] + pwr_bufg_9[0] ;
        float net_switching_power = pwr_notg_1[1] + pwr_notg_2[1] + pwr_notg_3[1] + pwr_notg_4[1] + pwr_notg_5[1] + pwr_notg_6[1] + pwr_notg_7[1] + pwr_notg_8[1] + pwr_nand_n_1[1] + pwr_nand_n_2[1] + pwr_nand_n_3[1] + pwr_nand_n_4[1] + pwr_nand_n_5[1] + pwr_nand_n_6[1] + pwr_nand_n_7[1] + pwr_nand_n_8[1] + pwr_nand_n_9[1] + pwr_nand_n_10[1] + pwr_nand_n_11[1] + pwr_nor_n_1[1] + pwr_nor_n_2[1] + pwr_nor_n_3[1] + pwr_nor_n_4[1] + pwr_nor_n_5[1] + pwr_nor_n_6[1] + pwr_nor_n_7[1] + pwr_nor_n_8[1] + pwr_nor_n_9[1] + pwr_nor_n_10[1] + pwr_dff_1[1] + pwr_dff_2[1] + pwr_dff_3[1] + pwr_dff_4[1] + pwr_bufg_1[1] + pwr_bufg_2[1] + pwr_bufg_3[1] + pwr_bufg_4[1] + pwr_bufg_5[1] + pwr_bufg_6[1] + pwr_bufg_7[1] + pwr_bufg_8[1] + pwr_bufg_9[1] ;
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
        signal_arr[9] = &(cut->S0);
        signal_arr[10] = &(cut->S1);
        signal_arr[11] = &(cut->S2);
        signal_arr[12] = &(cut->S3);
        signal_arr[13] = &(cut->S4);
        signal_arr[14] = &(cut->S5);
        signal_arr[15] = &(cut->S6);
        signal_arr[16] = &(cut->S7);
        signal_arr[17] = &(cut->S8);
        signal_arr[18] = &(cut->S9);
        signal_arr[19] = &(cut->S10);
        signal_arr[20] = &(cut->S11);
        signal_arr[21] = &(cut->S12);
        signal_arr[22] = &(cut->S13);
        signal_arr[23] = &(cut->S14);
        signal_arr[24] = &(cut->S15);
        signal_arr[25] = &(cut->S16);
        signal_arr[26] = &(cut->S17);
        signal_arr[27] = &(cut->S18);
        signal_arr[28] = &(cut->S19);
        signal_arr[29] = &(cut->S20);
        signal_arr[30] = &(cut->S21);
        signal_arr[31] = &(cut->S22);
        signal_arr[32] = &(cut->S23);
        signal_arr[33] = &(cut->S24);
        signal_arr[34] = &(cut->S25);
        signal_arr[35] = &(cut->S26);
        signal_arr[36] = &(cut->S27);
        signal_arr[37] = &(cut->S28);
        signal_arr[38] = &(cut->S29);
        signal_arr[39] = &(cut->S30);
        signal_arr[40] = &(cut->S31);
        signal_arr[41] = &(cut->S32);
        signal_arr[42] = &(cut->S33);
        signal_arr[43] = &(cut->S34);
        signal_arr[44] = &(cut->S35);
        signal_arr[45] = &(cut->S36);
        signal_arr[46] = &(cut->S37);
        signal_arr[47] = &(cut->S38);
        signal_arr[48] = &(cut->S39);
        signal_arr[49] = &(cut->S40);
    }

};
