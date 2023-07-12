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
    sc_signal<sc_logic> x = sc_signal<sc_logic>("x");
    sc_signal<sc_logic> out = sc_signal<sc_logic>("out");

    sc_event ready_for_analysis;
    sc_event ready2reset;

    sequence* cut;
    power_analysis* power_module;
    sc_trace_file* dict_trace_file;
    std::array<sc_signal<sc_logic>*, 3> input_arr = {&(clk), &(rst), &(x)};

    SC_HAS_PROCESS(testbench);
    testbench(sc_module_name _name){
        dict_trace_file = sc_create_dict_trace_var("two_level_nand");
        power_module = new power_analysis();
            power_module->tech_parameter_json("input_files/45nm_timing_power.json");
            power_module->read_netlist_json("input_files/gate_properties.json");
            power_module->read_net_cap_json("input_files/gate_cap.json);
            power_module->initialize_trace_file("dict_trace_file");
        cut = new sequence("cut");
            cut->clk(clk);
            cut->rst(rst);
            cut->x(x);
            cut->out(out);

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
        power_module->register_gate(cut->$abc$193$auto$blifparse.cc:381:parse_blif$194);
        power_module->register_gate(cut->$abc$193$auto$blifparse.cc:381:parse_blif$195);
        power_module->register_gate(cut->$abc$193$auto$blifparse.cc:381:parse_blif$196);
        power_module->register_gate(cut->$abc$193$auto$blifparse.cc:381:parse_blif$197);
        power_module->register_gate(cut->$abc$193$auto$blifparse.cc:381:parse_blif$198);
        power_module->register_gate(cut->$abc$193$auto$blifparse.cc:381:parse_blif$199);
        power_module->register_gate(cut->$abc$193$auto$blifparse.cc:381:parse_blif$200);
        power_module->register_gate(cut->$abc$193$auto$blifparse.cc:381:parse_blif$201);
        power_module->register_gate(cut->$abc$193$auto$blifparse.cc:381:parse_blif$202);
        power_module->register_gate(cut->$auto$simplemap.cc:377:simplemap_ff$147);
        power_module->register_gate(cut->$auto$simplemap.cc:377:simplemap_ff$148);
        power_module->register_gate(cut->$iopadmap$sequence.clk);
        power_module->register_gate(cut->$iopadmap$sequence.out);
        power_module->register_gate(cut->$iopadmap$sequence.rst);
        power_module->register_gate(cut->$iopadmap$sequence.x);
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
        power_module->register_signal(&(cut->ns_0));
        power_module->register_signal(&(cut->ns_1));
        power_module->register_signal(&(cut->ps_0));
        power_module->register_signal(&(cut->ps_1));
        power_module->register_signal(&(clk));
        power_module->register_signal(&(rst));
        power_module->register_signal(&(x));
        power_module->register_signal(&(out));
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
        sc_trace(dict_trace_file, cut->ns_0, "ns_0");
        sc_trace(dict_trace_file, cut->ns_1, "ns_1");
        sc_trace(dict_trace_file, cut->ps_0, "ps_0");
        sc_trace(dict_trace_file, cut->ps_1, "ps_1");
        sc_trace(dict_trace_file, clk, "clk");
        sc_trace(dict_trace_file, rst, "rst");
        sc_trace(dict_trace_file, x, "x");
        sc_trace(dict_trace_file, out, "out");
        power_module->find_primary_inputs();
        power_module->find_primary_outputs();
        // set transition time of primary input
        power_module->set_primary_input_transition_time("");
    }

};
