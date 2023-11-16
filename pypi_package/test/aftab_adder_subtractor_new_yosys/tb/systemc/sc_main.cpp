#include "systemc.h"
#include "testbench.h"

int sc_main(int argc, char* argv[]){
    testbench* fault_simulation = new testbench("testbench");
    
    sc_trace_file *vcdfile;
    vcdfile = sc_create_vcd_trace_file("vcdfile");
    vcdfile->set_time_unit(1, SC_NS);

    sc_trace(vcdfile, fault_simulation->subsel, "subsel");
    sc_trace(vcdfile, fault_simulation->pass, "pass");
    sc_trace(vcdfile, fault_simulation->result[0], "result[0]");
    sc_trace(vcdfile, fault_simulation->result[1], "result[1]");
    sc_trace(vcdfile, fault_simulation->result[2], "result[2]");
    sc_trace(vcdfile, fault_simulation->result[3], "result[3]");
    sc_trace(vcdfile, fault_simulation->result[4], "result[4]");
    sc_trace(vcdfile, fault_simulation->result[5], "result[5]");
    sc_trace(vcdfile, fault_simulation->result[6], "result[6]");
    sc_trace(vcdfile, fault_simulation->result[7], "result[7]");
    sc_trace(vcdfile, fault_simulation->result[8], "result[8]");
    sc_trace(vcdfile, fault_simulation->result[9], "result[9]");
    sc_trace(vcdfile, fault_simulation->result[10], "result[10]");
    sc_trace(vcdfile, fault_simulation->result[11], "result[11]");
    sc_trace(vcdfile, fault_simulation->result[12], "result[12]");
    sc_trace(vcdfile, fault_simulation->result[13], "result[13]");
    sc_trace(vcdfile, fault_simulation->result[14], "result[14]");
    sc_trace(vcdfile, fault_simulation->result[15], "result[15]");
    sc_trace(vcdfile, fault_simulation->result[16], "result[16]");
    sc_trace(vcdfile, fault_simulation->result[17], "result[17]");
    sc_trace(vcdfile, fault_simulation->result[18], "result[18]");
    sc_trace(vcdfile, fault_simulation->result[19], "result[19]");
    sc_trace(vcdfile, fault_simulation->result[20], "result[20]");
    sc_trace(vcdfile, fault_simulation->result[21], "result[21]");
    sc_trace(vcdfile, fault_simulation->result[22], "result[22]");
    sc_trace(vcdfile, fault_simulation->result[23], "result[23]");
    sc_trace(vcdfile, fault_simulation->result[24], "result[24]");
    sc_trace(vcdfile, fault_simulation->result[25], "result[25]");
    sc_trace(vcdfile, fault_simulation->result[26], "result[26]");
    sc_trace(vcdfile, fault_simulation->result[27], "result[27]");
    sc_trace(vcdfile, fault_simulation->result[28], "result[28]");
    sc_trace(vcdfile, fault_simulation->result[29], "result[29]");
    sc_trace(vcdfile, fault_simulation->result[30], "result[30]");
    sc_trace(vcdfile, fault_simulation->result[31], "result[31]");
    sc_trace(vcdfile, fault_simulation->a[0], "a[0]");
    sc_trace(vcdfile, fault_simulation->b[1], "b[1]");

 
    sc_start(500, SC_NS);
    return 0;
}
