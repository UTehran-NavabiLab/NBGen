#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include "systemc.h"
#include "input_files/systemC_netlist.h"
#include "src/utility_functions.h"
#include "src/power_analysis.h"
#include "src/dict_trace_var.h"


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

    sc_event ready_for_analysis;
    sc_event ready2reset;

    register* cut;
    power_analysis* power_module;
    sc_trace_file* dict_trace_file;
    std::array<sc_signal<sc_logic>*, 14> input_arr = {&(clk), &(rst), &(A[0]), &(A[1]), &(A[2]), &(A[3]), &(B[0]), &(B[1]), &(B[2]), &(B[3]), &(C[0]), &(C[1]), &(C[2]), &(C[3])};

    SC_HAS_PROCESS(testbench);
    testbench(sc_module_name _name){
        dict_trace_file = sc_create_dict_trace_var("two_level_nand");
        power_module = new power_analysis();
            power_module->tech_parameter_json("input_files/45nm_timing_power.json");
            power_module->read_netlist_json("input_files/gate_properties.json");
            power_module->read_net_cap_json("input_files/gate_cap.json);
            power_module->initialize_trace_file("dict_trace_file");
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

        SC_METHOD(analyze);
            sensitive << ready_for_analysis;
            dont_initialize();

        registration_and_tracing();


    }

    void signaling(void){
        wait(SC_ZERO_TIME);
        // apply input as string
        // apply_input_vector<3>(input_arr, ("00000000000000"));
        // notify ready_to_analyze event
        // ready2reportTrace.notify();
        apply_input_vector<sc_dt::sc_logic, 14>(input_arr, ("00000000000000"));
    }

    void analyze(void){
    }

    void registration_and_tracing(void){
        power_module->register_gate(cut->$abc$181$auto$blifparse.cc:381:parse_blif$182);
        power_module->register_gate(cut->$abc$181$auto$blifparse.cc:381:parse_blif$183);
        power_module->register_gate(cut->$abc$181$auto$blifparse.cc:381:parse_blif$184);
        power_module->register_gate(cut->$abc$181$auto$blifparse.cc:381:parse_blif$185);
        power_module->register_gate(cut->$abc$181$auto$blifparse.cc:381:parse_blif$186);
        power_module->register_gate(cut->$abc$181$auto$blifparse.cc:381:parse_blif$187);
        power_module->register_gate(cut->$abc$181$auto$blifparse.cc:381:parse_blif$188);
        power_module->register_gate(cut->$abc$181$auto$blifparse.cc:381:parse_blif$189);
        power_module->register_gate(cut->$abc$181$auto$blifparse.cc:381:parse_blif$190);
        power_module->register_gate(cut->$abc$181$auto$blifparse.cc:381:parse_blif$191);
        power_module->register_gate(cut->$abc$181$auto$blifparse.cc:381:parse_blif$192);
        power_module->register_gate(cut->$abc$181$auto$blifparse.cc:381:parse_blif$193);
        power_module->register_gate(cut->$abc$181$auto$blifparse.cc:381:parse_blif$194);
        power_module->register_gate(cut->$abc$181$auto$blifparse.cc:381:parse_blif$195);
        power_module->register_gate(cut->$abc$181$auto$blifparse.cc:381:parse_blif$196);
        power_module->register_gate(cut->$abc$181$auto$blifparse.cc:381:parse_blif$197);
        power_module->register_gate(cut->$auto$simplemap.cc:377:simplemap_ff$105);
        power_module->register_gate(cut->$auto$simplemap.cc:377:simplemap_ff$106);
        power_module->register_gate(cut->$auto$simplemap.cc:377:simplemap_ff$107);
        power_module->register_gate(cut->$auto$simplemap.cc:377:simplemap_ff$108);
        power_module->register_gate(cut->$auto$simplemap.cc:377:simplemap_ff$109);
        power_module->register_gate(cut->$auto$simplemap.cc:377:simplemap_ff$110);
        power_module->register_gate(cut->$auto$simplemap.cc:377:simplemap_ff$111);
        power_module->register_gate(cut->$auto$simplemap.cc:377:simplemap_ff$112);
        power_module->register_gate(cut->$auto$simplemap.cc:377:simplemap_ff$113);
        power_module->register_gate(cut->$auto$simplemap.cc:377:simplemap_ff$114);
        power_module->register_gate(cut->$auto$simplemap.cc:377:simplemap_ff$115);
        power_module->register_gate(cut->$auto$simplemap.cc:377:simplemap_ff$116);
        power_module->register_gate(cut->$auto$simplemap.cc:377:simplemap_ff$117);
        power_module->register_gate(cut->$auto$simplemap.cc:377:simplemap_ff$118);
        power_module->register_gate(cut->$auto$simplemap.cc:377:simplemap_ff$119);
        power_module->register_gate(cut->$auto$simplemap.cc:377:simplemap_ff$120);
        power_module->register_gate(cut->$auto$simplemap.cc:377:simplemap_ff$121);
        power_module->register_gate(cut->$iopadmap$register.A);
        power_module->register_gate(cut->$iopadmap$register.A_1);
        power_module->register_gate(cut->$iopadmap$register.A_2);
        power_module->register_gate(cut->$iopadmap$register.A_3);
        power_module->register_gate(cut->$iopadmap$register.B);
        power_module->register_gate(cut->$iopadmap$register.B_1);
        power_module->register_gate(cut->$iopadmap$register.B_2);
        power_module->register_gate(cut->$iopadmap$register.B_3);
        power_module->register_gate(cut->$iopadmap$register.C);
        power_module->register_gate(cut->$iopadmap$register.C_1);
        power_module->register_gate(cut->$iopadmap$register.C_2);
        power_module->register_gate(cut->$iopadmap$register.C_3);
        power_module->register_gate(cut->$iopadmap$register.Q1);
        power_module->register_gate(cut->$iopadmap$register.Q1_1);
        power_module->register_gate(cut->$iopadmap$register.Q1_2);
        power_module->register_gate(cut->$iopadmap$register.Q1_3);
        power_module->register_gate(cut->$iopadmap$register.Q2);
        power_module->register_gate(cut->$iopadmap$register.Q2_1);
        power_module->register_gate(cut->$iopadmap$register.Q2_2);
        power_module->register_gate(cut->$iopadmap$register.Q2_3);
        power_module->register_gate(cut->$iopadmap$register.Q3);
        power_module->register_gate(cut->$iopadmap$register.Q3_1);
        power_module->register_gate(cut->$iopadmap$register.Q3_2);
        power_module->register_gate(cut->$iopadmap$register.Q3_3);
        power_module->register_gate(cut->$iopadmap$register.clk);
        power_module->register_gate(cut->$iopadmap$register.rst);
        power_module->register_signal(&(cut->S0));
        power_module->register_signal(&(cut->S1));
        power_module->register_signal(&(cut->S2));
        power_module->register_signal(&(cut->S3));
        power_module->register_signal(&(cut->S4));
        power_module->register_signal(&(cut->S5));
        power_module->register_signal(&(cut->S6));
        power_module->register_signal(&(cut->S7));
        power_module->register_signal(&(cut->S8));
        power_module->register_signal(&(cut->S9));
        power_module->register_signal(&(cut->S10));
        power_module->register_signal(&(cut->S11));
        power_module->register_signal(&(cut->S12));
        power_module->register_signal(&(cut->S13));
        power_module->register_signal(&(cut->S14));
        power_module->register_signal(&(cut->S15));
        power_module->register_signal(&(cut->S16));
        power_module->register_signal(&(cut->S17));
        power_module->register_signal(&(cut->S18));
        power_module->register_signal(&(cut->S19));
        power_module->register_signal(&(cut->S20));
        power_module->register_signal(&(cut->S21));
        power_module->register_signal(&(cut->S22));
        power_module->register_signal(&(cut->S23));
        power_module->register_signal(&(cut->S24));
        power_module->register_signal(&(cut->S25));
        power_module->register_signal(&(cut->S26));
        power_module->register_signal(&(cut->S27));
        power_module->register_signal(&(cut->S28));
        power_module->register_signal(&(cut->S29));
        power_module->register_signal(&(cut->S30));
        power_module->register_signal(&(cut->S31));
        power_module->register_signal(&(cut->S32));
        power_module->register_signal(&(cut->S33));
        power_module->register_signal(&(cut->S34));
        power_module->register_signal(&(cut->S35));
        power_module->register_signal(&(cut->S36));
        power_module->register_signal(&(cut->S37));
        power_module->register_signal(&(cut->S38));
        power_module->register_signal(&(cut->S39));
        power_module->register_signal(&(cut->CK));
        power_module->register_signal(&(cut->R));
        power_module->register_signal(&(cut->cnt_0));
        power_module->register_signal(&(cut->cnt_1));
        power_module->register_signal(&(cut->cnt_2));
        power_module->register_signal(&(cut->cnt_3));
        power_module->register_signal(&(clk));
        power_module->register_signal(&(rst));
        power_module->register_signal(&(A[0]));
        power_module->register_signal(&(A[1]));
        power_module->register_signal(&(A[2]));
        power_module->register_signal(&(A[3]));
        power_module->register_signal(&(B[0]));
        power_module->register_signal(&(B[1]));
        power_module->register_signal(&(B[2]));
        power_module->register_signal(&(B[3]));
        power_module->register_signal(&(C[0]));
        power_module->register_signal(&(C[1]));
        power_module->register_signal(&(C[2]));
        power_module->register_signal(&(C[3]));
        power_module->register_signal(&(Q1[0]));
        power_module->register_signal(&(Q1[1]));
        power_module->register_signal(&(Q1[2]));
        power_module->register_signal(&(Q1[3]));
        power_module->register_signal(&(Q2[0]));
        power_module->register_signal(&(Q2[1]));
        power_module->register_signal(&(Q2[2]));
        power_module->register_signal(&(Q2[3]));
        power_module->register_signal(&(Q3[0]));
        power_module->register_signal(&(Q3[1]));
        power_module->register_signal(&(Q3[2]));
        power_module->register_signal(&(Q3[3]));
        sc_trace(dict_trace_file, cut->S0, "S0");
        sc_trace(dict_trace_file, cut->S1, "S1");
        sc_trace(dict_trace_file, cut->S2, "S2");
        sc_trace(dict_trace_file, cut->S3, "S3");
        sc_trace(dict_trace_file, cut->S4, "S4");
        sc_trace(dict_trace_file, cut->S5, "S5");
        sc_trace(dict_trace_file, cut->S6, "S6");
        sc_trace(dict_trace_file, cut->S7, "S7");
        sc_trace(dict_trace_file, cut->S8, "S8");
        sc_trace(dict_trace_file, cut->S9, "S9");
        sc_trace(dict_trace_file, cut->S10, "S10");
        sc_trace(dict_trace_file, cut->S11, "S11");
        sc_trace(dict_trace_file, cut->S12, "S12");
        sc_trace(dict_trace_file, cut->S13, "S13");
        sc_trace(dict_trace_file, cut->S14, "S14");
        sc_trace(dict_trace_file, cut->S15, "S15");
        sc_trace(dict_trace_file, cut->S16, "S16");
        sc_trace(dict_trace_file, cut->S17, "S17");
        sc_trace(dict_trace_file, cut->S18, "S18");
        sc_trace(dict_trace_file, cut->S19, "S19");
        sc_trace(dict_trace_file, cut->S20, "S20");
        sc_trace(dict_trace_file, cut->S21, "S21");
        sc_trace(dict_trace_file, cut->S22, "S22");
        sc_trace(dict_trace_file, cut->S23, "S23");
        sc_trace(dict_trace_file, cut->S24, "S24");
        sc_trace(dict_trace_file, cut->S25, "S25");
        sc_trace(dict_trace_file, cut->S26, "S26");
        sc_trace(dict_trace_file, cut->S27, "S27");
        sc_trace(dict_trace_file, cut->S28, "S28");
        sc_trace(dict_trace_file, cut->S29, "S29");
        sc_trace(dict_trace_file, cut->S30, "S30");
        sc_trace(dict_trace_file, cut->S31, "S31");
        sc_trace(dict_trace_file, cut->S32, "S32");
        sc_trace(dict_trace_file, cut->S33, "S33");
        sc_trace(dict_trace_file, cut->S34, "S34");
        sc_trace(dict_trace_file, cut->S35, "S35");
        sc_trace(dict_trace_file, cut->S36, "S36");
        sc_trace(dict_trace_file, cut->S37, "S37");
        sc_trace(dict_trace_file, cut->S38, "S38");
        sc_trace(dict_trace_file, cut->S39, "S39");
        sc_trace(dict_trace_file, cut->CK, "CK");
        sc_trace(dict_trace_file, cut->R, "R");
        sc_trace(dict_trace_file, cut->cnt_0, "cnt_0");
        sc_trace(dict_trace_file, cut->cnt_1, "cnt_1");
        sc_trace(dict_trace_file, cut->cnt_2, "cnt_2");
        sc_trace(dict_trace_file, cut->cnt_3, "cnt_3");
        sc_trace(dict_trace_file, clk, "clk");
        sc_trace(dict_trace_file, rst, "rst");
        sc_trace(dict_trace_file, A[0], "A[0]");
        sc_trace(dict_trace_file, A[1], "A[1]");
        sc_trace(dict_trace_file, A[2], "A[2]");
        sc_trace(dict_trace_file, A[3], "A[3]");
        sc_trace(dict_trace_file, B[0], "B[0]");
        sc_trace(dict_trace_file, B[1], "B[1]");
        sc_trace(dict_trace_file, B[2], "B[2]");
        sc_trace(dict_trace_file, B[3], "B[3]");
        sc_trace(dict_trace_file, C[0], "C[0]");
        sc_trace(dict_trace_file, C[1], "C[1]");
        sc_trace(dict_trace_file, C[2], "C[2]");
        sc_trace(dict_trace_file, C[3], "C[3]");
        sc_trace(dict_trace_file, Q1[0], "Q1[0]");
        sc_trace(dict_trace_file, Q1[1], "Q1[1]");
        sc_trace(dict_trace_file, Q1[2], "Q1[2]");
        sc_trace(dict_trace_file, Q1[3], "Q1[3]");
        sc_trace(dict_trace_file, Q2[0], "Q2[0]");
        sc_trace(dict_trace_file, Q2[1], "Q2[1]");
        sc_trace(dict_trace_file, Q2[2], "Q2[2]");
        sc_trace(dict_trace_file, Q2[3], "Q2[3]");
        sc_trace(dict_trace_file, Q3[0], "Q3[0]");
        sc_trace(dict_trace_file, Q3[1], "Q3[1]");
        sc_trace(dict_trace_file, Q3[2], "Q3[2]");
        sc_trace(dict_trace_file, Q3[3], "Q3[3]");
        power_module->find_primary_inputs();
        power_module->find_primary_outputs();
        // set transition time of primary input
        power_module->set_primary_input_transition_time("");
    }

};
