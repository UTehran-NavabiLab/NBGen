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
    sc_signal<sc_logic> en = sc_signal<sc_logic>("en");
    sc_signal<sc_logic> clkEn = sc_signal<sc_logic>("clkEn");
    sc_signal<sc_logic> count[4] = sc_signal<sc_logic>("count");
    sc_signal<sc_logic> co = sc_signal<sc_logic>("co");

    sc_event ready_for_analysis;
    sc_event ready2reset;

    counter* cut;
    power_analysis* power_module;
    sc_trace_file* dict_trace_file;
    std::array<sc_signal<sc_logic>*, 4> input_arr = {&(clk), &(rst), &(en), &(clkEn)};

    SC_HAS_PROCESS(testbench);
    testbench(sc_module_name _name){
        dict_trace_file = sc_create_dict_trace_var("two_level_nand");
        power_module = new power_analysis();
            power_module->tech_parameter_json("input_files/45nm_timing_power.json");
            power_module->read_netlist_json("input_files/gate_properties.json");
            power_module->read_net_cap_json("input_files/gate_cap.json);
            power_module->initialize_trace_file("dict_trace_file");
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

        SC_METHOD(analyze);
            sensitive << ready_for_analysis;
            dont_initialize();

        registration_and_tracing();


    }

    void signaling(void){
        wait(SC_ZERO_TIME);
        // apply input as string
        // apply_input_vector<3>(input_arr, ("0000"));
        // notify ready_to_analyze event
        // ready2reportTrace.notify();
        apply_input_vector<sc_dt::sc_logic, 4>(input_arr, ("0000"));
    }

    void analyze(void){
    }

    void registration_and_tracing(void){
        power_module->register_gate(cut->$abc$192$auto$blifparse.cc:381:parse_blif$193);
        power_module->register_gate(cut->$abc$192$auto$blifparse.cc:381:parse_blif$194);
        power_module->register_gate(cut->$abc$192$auto$blifparse.cc:381:parse_blif$195);
        power_module->register_gate(cut->$abc$192$auto$blifparse.cc:381:parse_blif$196);
        power_module->register_gate(cut->$abc$192$auto$blifparse.cc:381:parse_blif$197);
        power_module->register_gate(cut->$abc$192$auto$blifparse.cc:381:parse_blif$198);
        power_module->register_gate(cut->$abc$192$auto$blifparse.cc:381:parse_blif$199);
        power_module->register_gate(cut->$abc$192$auto$blifparse.cc:381:parse_blif$200);
        power_module->register_gate(cut->$abc$192$auto$blifparse.cc:381:parse_blif$201);
        power_module->register_gate(cut->$abc$192$auto$blifparse.cc:381:parse_blif$202);
        power_module->register_gate(cut->$abc$192$auto$blifparse.cc:381:parse_blif$203);
        power_module->register_gate(cut->$abc$192$auto$blifparse.cc:381:parse_blif$204);
        power_module->register_gate(cut->$abc$192$auto$blifparse.cc:381:parse_blif$205);
        power_module->register_gate(cut->$abc$192$auto$blifparse.cc:381:parse_blif$206);
        power_module->register_gate(cut->$abc$192$auto$blifparse.cc:381:parse_blif$207);
        power_module->register_gate(cut->$abc$192$auto$blifparse.cc:381:parse_blif$208);
        power_module->register_gate(cut->$abc$192$auto$blifparse.cc:381:parse_blif$209);
        power_module->register_gate(cut->$abc$192$auto$blifparse.cc:381:parse_blif$210);
        power_module->register_gate(cut->$abc$192$auto$blifparse.cc:381:parse_blif$211);
        power_module->register_gate(cut->$abc$192$auto$blifparse.cc:381:parse_blif$212);
        power_module->register_gate(cut->$abc$192$auto$blifparse.cc:381:parse_blif$213);
        power_module->register_gate(cut->$abc$192$auto$blifparse.cc:381:parse_blif$214);
        power_module->register_gate(cut->$abc$192$auto$blifparse.cc:381:parse_blif$215);
        power_module->register_gate(cut->$abc$192$auto$blifparse.cc:381:parse_blif$216);
        power_module->register_gate(cut->$abc$192$auto$blifparse.cc:381:parse_blif$217);
        power_module->register_gate(cut->$abc$192$auto$blifparse.cc:381:parse_blif$218);
        power_module->register_gate(cut->$abc$192$auto$blifparse.cc:381:parse_blif$219);
        power_module->register_gate(cut->$abc$192$auto$blifparse.cc:381:parse_blif$220);
        power_module->register_gate(cut->$abc$192$auto$blifparse.cc:381:parse_blif$221);
        power_module->register_gate(cut->$auto$simplemap.cc:377:simplemap_ff$110);
        power_module->register_gate(cut->$auto$simplemap.cc:377:simplemap_ff$111);
        power_module->register_gate(cut->$auto$simplemap.cc:377:simplemap_ff$112);
        power_module->register_gate(cut->$auto$simplemap.cc:377:simplemap_ff$113);
        power_module->register_gate(cut->$iopadmap$counter.clk);
        power_module->register_gate(cut->$iopadmap$counter.clkEn);
        power_module->register_gate(cut->$iopadmap$counter.co);
        power_module->register_gate(cut->$iopadmap$counter.count);
        power_module->register_gate(cut->$iopadmap$counter.count_1);
        power_module->register_gate(cut->$iopadmap$counter.count_2);
        power_module->register_gate(cut->$iopadmap$counter.count_3);
        power_module->register_gate(cut->$iopadmap$counter.en);
        power_module->register_gate(cut->$iopadmap$counter.rst);
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
        power_module->register_signal(&(clk));
        power_module->register_signal(&(rst));
        power_module->register_signal(&(en));
        power_module->register_signal(&(clkEn));
        power_module->register_signal(&(count[0]));
        power_module->register_signal(&(count[1]));
        power_module->register_signal(&(count[2]));
        power_module->register_signal(&(count[3]));
        power_module->register_signal(&(co));
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
        sc_trace(dict_trace_file, clk, "clk");
        sc_trace(dict_trace_file, rst, "rst");
        sc_trace(dict_trace_file, en, "en");
        sc_trace(dict_trace_file, clkEn, "clkEn");
        sc_trace(dict_trace_file, count[0], "count[0]");
        sc_trace(dict_trace_file, count[1], "count[1]");
        sc_trace(dict_trace_file, count[2], "count[2]");
        sc_trace(dict_trace_file, count[3], "count[3]");
        sc_trace(dict_trace_file, co, "co");
        power_module->find_primary_inputs();
        power_module->find_primary_outputs();
        // set transition time of primary input
        power_module->set_primary_input_transition_time("");
    }

};
