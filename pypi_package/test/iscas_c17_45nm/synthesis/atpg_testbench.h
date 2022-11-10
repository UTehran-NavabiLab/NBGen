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

    sc_signal<sc_logic> N1 = sc_signal<sc_logic>("N1");
    sc_signal<sc_logic> N2 = sc_signal<sc_logic>("N2");
    sc_signal<sc_logic> N3 = sc_signal<sc_logic>("N3");
    sc_signal<sc_logic> N6 = sc_signal<sc_logic>("N6");
    sc_signal<sc_logic> N7 = sc_signal<sc_logic>("N7");
    sc_signal<sc_logic> N22 = sc_signal<sc_logic>("N22");
    sc_signal<sc_logic> N23 = sc_signal<sc_logic>("N23");

    sc_event ready2update;

    c17* cut;
    itest idd_test = itest("gate_signal_json_file.json", "gate_properties.json");
    std::array<sc_core::sc_signal<sc_dt::sc_logic>*, 12> signal_arr;

    SC_HAS_PROCESS(testbench);
    testbench(sc_module_name _name){
        cut = new c17("cut");
            cut->N1(N1);
            cut->N2(N2);
            cut->N3(N3);
            cut->N6(N6);
            cut->N7(N7);
            cut->N22(N22);
            cut->N23(N23);

        SC_THREAD(signaling);

        SC_METHOD(run_idd_testing);
            sensitive << ready2update;
            dont_initialize();

        access_signals();


    }

    void signaling(void){
        for (int i=0; i < pow(2, 5); i++){
            N1.write(input_signalling(0, i));
            N2.write(input_signalling(1, i));
            N3.write(input_signalling(2, i));
            N6.write(input_signalling(3, i));
            N7.write(input_signalling(4, i));
            wait(SC_ZERO_TIME);
            std::cout << "--------- Apply New input vector: " << std::endl; 
            std::cout << "input signals:  N1, N2, N3, N6, N7 = " << N1.read() << N2.read() << N3.read() << N6.read() << N7.read()  << std::endl; 
            wait(5, SC_NS);
            ready2update.notify();
            wait(SC_ZERO_TIME);
        }
    }

    void run_idd_testing(void){
        idd_test.update_signal<sc_dt::sc_logic, 12>(signal_arr);
        idd_test.back_trace("N22");
        idd_test.back_trace("N23");
        idd_test.mark_multiplath();
        idd_test.print_critical_path_list();
        idd_test.clear_critical_path_list();
    }

    void access_signals(void){
        signal_arr[0] = &(N1);
        idd_test.add_to_port_list("N1");
        signal_arr[1] = &(N2);
        idd_test.add_to_port_list("N2");
        signal_arr[2] = &(N3);
        idd_test.add_to_port_list("N3");
        signal_arr[3] = &(N6);
        idd_test.add_to_port_list("N6");
        signal_arr[4] = &(N7);
        idd_test.add_to_port_list("N7");
        signal_arr[5] = &(N22);
        signal_arr[6] = &(N23);
        signal_arr[7] = &(cut->_0_);
        signal_arr[8] = &(cut->_1_);
        signal_arr[9] = &(cut->_2_);
        signal_arr[10] = &(cut->_3_);
        signal_arr[11] = &(cut->_4_);
    }

};
