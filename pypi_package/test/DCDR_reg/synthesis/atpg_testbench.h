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
    sc_signal<sc_logic> A[4] = sc_signal<sc_logic>("A");
    sc_signal<sc_logic> B[4] = sc_signal<sc_logic>("B");
    sc_signal<sc_logic> C[4] = sc_signal<sc_logic>("C");
    sc_signal<sc_logic> Q1[4] = sc_signal<sc_logic>("Q1");
    sc_signal<sc_logic> Q2[4] = sc_signal<sc_logic>("Q2");
    sc_signal<sc_logic> Q3[4] = sc_signal<sc_logic>("Q3");

    sc_event ready2update;

    register* cut;
    itest idd_test = itest("gate_signal_json_file.json", "gate_properties.json");
    std::array<sc_core::sc_signal<sc_dt::sc_logic>*, 54> signal_arr;

    SC_HAS_PROCESS(testbench);
    testbench(sc_module_name _name){
        cut = new register("cut");
            cut->clk(clk);
            cut->rst(rst);
            cut->A[0](A[0]);
            cut->A[1](A[1]);
            cut->A[2](A[2]);
            cut->A[3](A[3]);
            cut->B[0](B[0]);
            cut->B[1](B[1]);
            cut->B[2](B[2]);
            cut->B[3](B[3]);
            cut->C[0](C[0]);
            cut->C[1](C[1]);
            cut->C[2](C[2]);
            cut->C[3](C[3]);
            cut->Q1[0](Q1[0]);
            cut->Q1[1](Q1[1]);
            cut->Q1[2](Q1[2]);
            cut->Q1[3](Q1[3]);
            cut->Q2[0](Q2[0]);
            cut->Q2[1](Q2[1]);
            cut->Q2[2](Q2[2]);
            cut->Q2[3](Q2[3]);
            cut->Q3[0](Q3[0]);
            cut->Q3[1](Q3[1]);
            cut->Q3[2](Q3[2]);
            cut->Q3[3](Q3[3]);

        SC_THREAD(signaling);

        SC_METHOD(run_idd_testing);
            sensitive << ready2update;
            dont_initialize();

        access_signals();


    }

    void signaling(void){
        for (int i=0; i < pow(2, 14); i++){
            clk.write(input_signalling(0, i));
            rst.write(input_signalling(1, i));
            A.write(input_signalling(2, i));
            B.write(input_signalling(3, i));
            C.write(input_signalling(4, i));
            wait(SC_ZERO_TIME);
            std::cout << "--------- Apply New input vector: " << std::endl; 
            std::cout << "input signals:  clk, rst, A, B, C = " << clk.read() << rst.read() << A.read() << B.read() << C.read()  << std::endl; 
            wait(5, SC_NS);
            ready2update.notify();
            wait(SC_ZERO_TIME);
        }
    }

    void run_idd_testing(void){
        idd_test.update_signal<sc_dt::sc_logic, 54>(signal_arr);
        idd_test.back_trace("Q1");
        idd_test.back_trace("Q2");
        idd_test.back_trace("Q3");
        idd_test.mark_multiplath();
        idd_test.print_critical_path_list();
        idd_test.clear_critical_path_list();
    }

    void access_signals(void){
        signal_arr[0] = &(clk);
        idd_test.add_to_port_list("clk");
        signal_arr[1] = &(rst);
        idd_test.add_to_port_list("rst");
        signal_arr[2] = &(A[0]);
        idd_test.add_to_port_list("A");
        signal_arr[3] = &(A[1]);
        idd_test.add_to_port_list("A");
        signal_arr[4] = &(A[2]);
        idd_test.add_to_port_list("A");
        signal_arr[5] = &(A[3]);
        idd_test.add_to_port_list("A");
        signal_arr[6] = &(B[0]);
        idd_test.add_to_port_list("B");
        signal_arr[7] = &(B[1]);
        idd_test.add_to_port_list("B");
        signal_arr[8] = &(B[2]);
        idd_test.add_to_port_list("B");
        signal_arr[9] = &(B[3]);
        idd_test.add_to_port_list("B");
        signal_arr[10] = &(C[0]);
        idd_test.add_to_port_list("C");
        signal_arr[11] = &(C[1]);
        idd_test.add_to_port_list("C");
        signal_arr[12] = &(C[2]);
        idd_test.add_to_port_list("C");
        signal_arr[13] = &(C[3]);
        idd_test.add_to_port_list("C");
        signal_arr[14] = &(Q1[0]);
        signal_arr[15] = &(Q1[1]);
        signal_arr[16] = &(Q1[2]);
        signal_arr[17] = &(Q1[3]);
        signal_arr[18] = &(Q2[0]);
        signal_arr[19] = &(Q2[1]);
        signal_arr[20] = &(Q2[2]);
        signal_arr[21] = &(Q2[3]);
        signal_arr[22] = &(Q3[0]);
        signal_arr[23] = &(Q3[1]);
        signal_arr[24] = &(Q3[2]);
        signal_arr[25] = &(Q3[3]);
        signal_arr[26] = &(cut->S0);
        signal_arr[27] = &(cut->S1);
        signal_arr[28] = &(cut->S2);
        signal_arr[29] = &(cut->S3);
        signal_arr[30] = &(cut->S4);
        signal_arr[31] = &(cut->S5);
        signal_arr[32] = &(cut->S6);
        signal_arr[33] = &(cut->S7);
        signal_arr[34] = &(cut->S8);
        signal_arr[35] = &(cut->S9);
        signal_arr[36] = &(cut->S10);
        signal_arr[37] = &(cut->S11);
        signal_arr[38] = &(cut->S12);
        signal_arr[39] = &(cut->S13);
        signal_arr[40] = &(cut->S14);
        signal_arr[41] = &(cut->S15);
        signal_arr[42] = &(cut->S16);
        signal_arr[43] = &(cut->S17);
        signal_arr[44] = &(cut->S18);
        signal_arr[45] = &(cut->S19);
        signal_arr[46] = &(cut->S20);
        signal_arr[47] = &(cut->S21);
        signal_arr[48] = &(cut->S22);
        signal_arr[49] = &(cut->S23);
        signal_arr[50] = &(cut->S24);
        signal_arr[51] = &(cut->S25);
        signal_arr[52] = &(cut->S26);
        signal_arr[53] = &(cut->S27);
        signal_arr[54] = &(cut->S28);
        signal_arr[55] = &(cut->S29);
        signal_arr[56] = &(cut->S30);
        signal_arr[57] = &(cut->S31);
        signal_arr[58] = &(cut->S32);
        signal_arr[59] = &(cut->S33);
        signal_arr[60] = &(cut->S34);
        signal_arr[61] = &(cut->S35);
        signal_arr[62] = &(cut->S36);
        signal_arr[63] = &(cut->S37);
        signal_arr[64] = &(cut->S38);
        signal_arr[65] = &(cut->S39);
        signal_arr[66] = &(cut->CK);
        signal_arr[67] = &(cut->R);
        signal_arr[68] = &(cut->cnt_0);
        signal_arr[69] = &(cut->cnt_1);
        signal_arr[70] = &(cut->cnt_2);
        signal_arr[71] = &(cut->cnt_3);
    }

};
