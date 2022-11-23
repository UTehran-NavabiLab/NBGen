#include <iostream>
#include <fstream>
#include <string>
#include "systemc.h"
#include "js2sc.h"
#include "fault_injector.h"

using namespace sc_core;

SC_MODULE( testbench ) {

    sc_signal<sc_logic> clk;
    sc_signal<sc_logic> rst;
    sc_signal<sc_logic> en;
    sc_signal<sc_logic> co_gld;
    sc_signal<sc_logic> co_flt;
    sc_signal<sc_logic> counter_gld[4];
    sc_signal<sc_logic> counter_flt[4];

    counter* flt_dut;
    counter* gld_dut;
    fault_injector* flt_injector;
    faultRegistry* accessRegistry;

    SC_HAS_PROCESS(testbench);
    testbench(sc_module_name _name){
        accessRegistry = new faultRegistry();
        flt_injector = new fault_injector("fault_injector", accessRegistry);
            flt_injector->output_ports(clk);
            flt_injector->output_ports(rst);
            flt_injector->output_ports(en);
            flt_injector->input_ports(co_gld);
            flt_injector->input_ports(co_flt);
            flt_injector->input_ports(counter_gld[0]);
            flt_injector->input_ports(counter_flt[0]);
            flt_injector->input_ports(counter_gld[1]);
            flt_injector->input_ports(counter_flt[1]);
            flt_injector->input_ports(counter_gld[2]);
            flt_injector->input_ports(counter_flt[2]);
            flt_injector->input_ports(counter_gld[3]);
            flt_injector->input_ports(counter_flt[3]);
        gld_dut = new fulladder("counter_gold", accessRegistry);
            gld_dut->clk(clk);
            gld_dut->rst(rst);
            gld_dut->en(en);
            gld_dut->co(co_gld);
            gld_dut->counter(counter_gld[0]);
            gld_dut->counter(counter_gld[1]);
            gld_dut->counter(counter_gld[2]);
            gld_dut->counter(counter_gld[3]);
        flt_dut = new fulladder("counter_faulty", accessRegistry);
            flt_dut->clk(clk);
            flt_dut->rst(rst);
            flt_dut->en(en);
            flt_dut->co(co_flt);
            flt_dut->counter(counter_flt[0]);
            flt_dut->counter(counter_flt[1]);
            flt_dut->counter(counter_flt[2]);
            flt_dut->counter(counter_flt[3]);

    }
};
