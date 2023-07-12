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
    sc_signal<sc_logic> x = sc_signal<sc_logic>("x");
    sc_signal<sc_logic> out = sc_signal<sc_logic>("out");

    sc_event ready2update;

    sequence* cut;
    itest idd_test = itest("gate_signal_json_file.json", "gate_properties.json");
    std::array<sc_core::sc_signal<sc_dt::sc_logic>*, 20> signal_arr;

    SC_HAS_PROCESS(testbench);
    testbench(sc_module_name _name){
        cut = new sequence("cut");
            cut->clk(clk);
            cut->rst(rst);
            cut->x(x);
            cut->out(out);

        SC_THREAD(signaling);

        SC_METHOD(run_idd_testing);
            sensitive << ready2update;
            dont_initialize();

        access_signals();


    }

    void signaling(void){
        for (int i=0; i < pow(2, 3); i++){
            clk.write(input_signalling(0, i));
            rst.write(input_signalling(1, i));
            x.write(input_signalling(2, i));
            wait(SC_ZERO_TIME);
            std::cout << "--------- Apply New input vector: " << std::endl; 
            std::cout << "input signals:  clk, rst, x = " << clk.read() << rst.read() << x.read()  << std::endl; 
            wait(5, SC_NS);
            ready2update.notify();
            wait(SC_ZERO_TIME);
        }
    }

    void run_idd_testing(void){
        idd_test.update_signal<sc_dt::sc_logic, 20>(signal_arr);
        idd_test.back_trace("out");
        idd_test.mark_multiplath();
        idd_test.print_critical_path_list();
        idd_test.clear_critical_path_list();
    }

    void access_signals(void){
        signal_arr[0] = &(clk);
        idd_test.add_to_port_list("clk");
        signal_arr[1] = &(rst);
        idd_test.add_to_port_list("rst");
        signal_arr[2] = &(x);
        idd_test.add_to_port_list("x");
        signal_arr[3] = &(out);
        signal_arr[4] = &(cut->S0);
        signal_arr[5] = &(cut->S1);
        signal_arr[6] = &(cut->S2);
        signal_arr[7] = &(cut->S3);
        signal_arr[8] = &(cut->S4);
        signal_arr[9] = &(cut->S5);
        signal_arr[10] = &(cut->S6);
        signal_arr[11] = &(cut->S7);
        signal_arr[12] = &(cut->S8);
        signal_arr[13] = &(cut->S9);
        signal_arr[14] = &(cut->S10);
        signal_arr[15] = &(cut->S11);
        signal_arr[16] = &(cut->ns_0);
        signal_arr[17] = &(cut->ns_1);
        signal_arr[18] = &(cut->ps_0);
        signal_arr[19] = &(cut->ps_1);
    }

};
