#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include "systemc.h"
#include "systemC_netlist.h"
#include "idd_testing.h"
#include "utilities.h"


using namespace sc_core;

SC_MODULE( testbench ) {

    sc_signal<sc_logic> clk = sc_signal<sc_logic>("clk");
    sc_signal<sc_logic> rst = sc_signal<sc_logic>("rst");
    sc_signal<sc_logic> en = sc_signal<sc_logic>("en");
    sc_signal<sc_logic> clkEn = sc_signal<sc_logic>("clkEn");
    sc_signal<sc_logic> count[4] = sc_signal<sc_logic>("count");
    sc_signal<sc_logic> co = sc_signal<sc_logic>("co");

    sc_event ready2update;

    counter* cut;
    itest idd_test = itest("gate_signal_json_file.json", "gate_properties.json");
    std::array<sc_core::sc_signal<sc_dt::sc_logic>*, 44> signal_arr;

    SC_HAS_PROCESS(testbench);
    testbench(sc_module_name _name){
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

        SC_METHOD(run_idd_testing);
            sensitive << ready2update;
            dont_initialize();

        access_signals();


    }

    void signaling(void){
        for (int i=0; i < pow(2, 4); i++){
            clk.write(input_signalling(0, i));
            rst.write(input_signalling(1, i));
            en.write(input_signalling(2, i));
            clkEn.write(input_signalling(3, i));
            wait(SC_ZERO_TIME);
            std::cout << "--------- Apply New input vector: " << std::endl; 
            std::cout << "input signals:  clk, rst, en, clkEn = " << clk.read() << rst.read() << en.read() << clkEn.read()  << std::endl; 
            wait(5, SC_NS);
            ready2update.notify();
            wait(SC_ZERO_TIME);
        }
    }

    void run_idd_testing(void){
        idd_test.update_signal<sc_dt::sc_logic, 44>(signal_arr);
        idd_test.back_trace("count");
        idd_test.back_trace("co");
        idd_test.mark_multiplath();
        idd_test.print_critical_path_list();
        idd_test.clear_critical_path_list();
    }

    void access_signals(void){
        signal_arr[0] = &(clk);
        idd_test.add_to_port_list("clk");
        signal_arr[1] = &(rst);
        idd_test.add_to_port_list("rst");
        signal_arr[2] = &(en);
        idd_test.add_to_port_list("en");
        signal_arr[3] = &(clkEn);
        idd_test.add_to_port_list("clkEn");
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
    }

};
