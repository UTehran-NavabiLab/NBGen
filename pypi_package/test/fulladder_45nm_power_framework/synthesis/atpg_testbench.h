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

    sc_signal<sc_logic> i0 = sc_signal<sc_logic>("i0");
    sc_signal<sc_logic> i1 = sc_signal<sc_logic>("i1");
    sc_signal<sc_logic> ci = sc_signal<sc_logic>("ci");
    sc_signal<sc_logic> s = sc_signal<sc_logic>("s");
    sc_signal<sc_logic> co = sc_signal<sc_logic>("co");

    sc_event ready2update;

    fulladder* cut;
    itest idd_test = itest("gate_signal_json_file.json", "gate_properties.json");
    std::array<sc_core::sc_signal<sc_dt::sc_logic>*, 16> signal_arr;

    SC_HAS_PROCESS(testbench);
    testbench(sc_module_name _name){
        cut = new fulladder("cut");
            cut->i0(i0);
            cut->i1(i1);
            cut->ci(ci);
            cut->s(s);
            cut->co(co);

        SC_THREAD(signaling);

        SC_METHOD(run_idd_testing);
            sensitive << ready2update;
            dont_initialize();

        access_signals();


    }

    void signaling(void){
        for (int i=0; i < pow(2, 3); i++){
            i0.write(input_signalling(0, i));
            i1.write(input_signalling(1, i));
            ci.write(input_signalling(2, i));
            wait(SC_ZERO_TIME);
            std::cout << "--------- Apply New input vector: " << std::endl; 
            std::cout << "input signals:  i0, i1, ci = " << i0.read() << i1.read() << ci.read()  << std::endl; 
            wait(5, SC_NS);
            ready2update.notify();
            wait(SC_ZERO_TIME);
        }
    }

    void run_idd_testing(void){
        idd_test.update_signal<sc_dt::sc_logic, 16>(signal_arr);
        idd_test.back_trace("s");
        idd_test.back_trace("co");
        idd_test.mark_multiplath();
        idd_test.print_critical_path_list();
        idd_test.clear_critical_path_list();
    }

    void access_signals(void){
        signal_arr[0] = &(i0);
        idd_test.add_to_port_list("i0");
        signal_arr[1] = &(i1);
        idd_test.add_to_port_list("i1");
        signal_arr[2] = &(ci);
        idd_test.add_to_port_list("ci");
        signal_arr[3] = &(s);
        signal_arr[4] = &(co);
        signal_arr[5] = &(cut->_0_);
        signal_arr[6] = &(cut->_10_);
        signal_arr[7] = &(cut->_1_);
        signal_arr[8] = &(cut->_2_);
        signal_arr[9] = &(cut->_3_);
        signal_arr[10] = &(cut->_4_);
        signal_arr[11] = &(cut->_5_);
        signal_arr[12] = &(cut->_6_);
        signal_arr[13] = &(cut->_7_);
        signal_arr[14] = &(cut->_8_);
        signal_arr[15] = &(cut->_9_);
    }

};
