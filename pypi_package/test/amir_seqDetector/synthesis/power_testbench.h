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
    sc_signal<sc_logic> serIn = sc_signal<sc_logic>("serIn");
    sc_signal<sc_logic> serOutValid = sc_signal<sc_logic>("serOutValid");

    sc_event ready_for_analysis;
    sc_event ready2reset;

    seqDetector* cut;
    power_analysis* power_module;
    sc_trace_file* dict_trace_file;
    std::array<sc_signal<sc_logic>*, 3> input_arr = {&(clk), &(rst), &(serIn)};

    SC_HAS_PROCESS(testbench);
    testbench(sc_module_name _name){
        dict_trace_file = sc_create_dict_trace_var("two_level_nand");
        power_module = new power_analysis();
            power_module->tech_parameter_json("input_files/45nm_timing_power.json");
            power_module->read_netlist_json("input_files/gate_properties.json");
            power_module->read_net_cap_json("input_files/gate_cap.json);
            power_module->initialize_trace_file("dict_trace_file");
        cut = new seqDetector("cut");
            cut->clk(clk);
            cut->rst(rst);
            cut->serIn(serIn);
            cut->serOutValid(serOutValid);

        SC_THREAD(signaling);

        SC_METHOD(analyze);
            sensitive << ready_for_analysis;
            dont_initialize();

        registration_and_tracing();


    }

    void signaling(void){
        wait(SC_ZERO_TIME);
        // apply input as string
        // apply_input_vector<3>(input_arr, ("000"));
        // notify ready_to_analyze event
        // ready2reportTrace.notify();
        apply_input_vector<sc_dt::sc_logic, 3>(input_arr, ("000"));
    }

    void analyze(void){
    }

    void registration_and_tracing(void){
        power_module->register_gate(cut->$abc$182$auto$blifparse.cc:381:parse_blif$183);
        power_module->register_gate(cut->$abc$182$auto$blifparse.cc:381:parse_blif$184);
        power_module->register_gate(cut->$abc$182$auto$blifparse.cc:381:parse_blif$185);
        power_module->register_gate(cut->$abc$182$auto$blifparse.cc:381:parse_blif$186);
        power_module->register_gate(cut->$abc$182$auto$blifparse.cc:381:parse_blif$187);
        power_module->register_gate(cut->$abc$182$auto$blifparse.cc:381:parse_blif$188);
        power_module->register_gate(cut->$abc$182$auto$blifparse.cc:381:parse_blif$189);
        power_module->register_gate(cut->$abc$182$auto$blifparse.cc:381:parse_blif$190);
        power_module->register_gate(cut->$abc$182$auto$blifparse.cc:381:parse_blif$191);
        power_module->register_gate(cut->$abc$182$auto$blifparse.cc:381:parse_blif$192);
        power_module->register_gate(cut->$abc$182$auto$blifparse.cc:381:parse_blif$193);
        power_module->register_gate(cut->$abc$182$auto$blifparse.cc:381:parse_blif$194);
        power_module->register_gate(cut->$abc$182$auto$blifparse.cc:381:parse_blif$195);
        power_module->register_gate(cut->$abc$182$auto$blifparse.cc:381:parse_blif$196);
        power_module->register_gate(cut->$abc$182$auto$blifparse.cc:381:parse_blif$197);
        power_module->register_gate(cut->$auto$simplemap.cc:377:simplemap_ff$164);
        power_module->register_gate(cut->$auto$simplemap.cc:377:simplemap_ff$165);
        power_module->register_gate(cut->$auto$simplemap.cc:377:simplemap_ff$166);
        power_module->register_gate(cut->$auto$simplemap.cc:377:simplemap_ff$167);
        power_module->register_gate(cut->$iopadmap$seqDetector.clk);
        power_module->register_gate(cut->$iopadmap$seqDetector.rst);
        power_module->register_gate(cut->$iopadmap$seqDetector.serIn);
        power_module->register_gate(cut->$iopadmap$seqDetector.serOutValid);
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
        power_module->register_signal(&(cut->ps_0));
        power_module->register_signal(&(cut->ps_1));
        power_module->register_signal(&(cut->ps_2));
        power_module->register_signal(&(clk));
        power_module->register_signal(&(rst));
        power_module->register_signal(&(serIn));
        power_module->register_signal(&(serOutValid));
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
        sc_trace(dict_trace_file, cut->ps_0, "ps_0");
        sc_trace(dict_trace_file, cut->ps_1, "ps_1");
        sc_trace(dict_trace_file, cut->ps_2, "ps_2");
        sc_trace(dict_trace_file, clk, "clk");
        sc_trace(dict_trace_file, rst, "rst");
        sc_trace(dict_trace_file, serIn, "serIn");
        sc_trace(dict_trace_file, serOutValid, "serOutValid");
        power_module->find_primary_inputs();
        power_module->find_primary_outputs();
        // set transition time of primary input
        power_module->set_primary_input_transition_time("");
    }

};
