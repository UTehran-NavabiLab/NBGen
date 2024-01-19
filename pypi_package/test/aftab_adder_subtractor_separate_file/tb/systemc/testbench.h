#include <iostream>
#include <fstream>
#include <string>
#include "systemc.h"
#include "systemC_netlist.h"

using namespace sc_core;

SC_MODULE( testbench ) {
    sc_signal<sc_logic> a[32];
    sc_signal<sc_logic> b[32];
    sc_signal<sc_logic> subsel;
    sc_signal<sc_logic> pass;
    sc_signal<sc_logic> cout;
    sc_signal<sc_logic> result[32];

    aftab_adder_subtractor* dut;

    SC_HAS_PROCESS(testbench);
    testbench(sc_module_name _name){
        dut = new aftab_adder_subtractor("adder_sub_aftab");
            dut->subsel(subsel);
            dut->pass(pass);
            dut->cout(cout);
            dut->a[0](a[0]);
            dut->a[1](a[1]);
            dut->a[2](a[2]);
            dut->a[3](a[3]);
            dut->a[4](a[4]);
            dut->a[5](a[5]);
            dut->a[6](a[6]);
            dut->a[7](a[7]);
            dut->a[8](a[8]);
            dut->a[9](a[9]);
            dut->a[10](a[10]);
            dut->a[11](a[11]);
            dut->a[12](a[12]);
            dut->a[13](a[13]);
            dut->a[14](a[14]);
            dut->a[15](a[15]);
            dut->a[16](a[16]);
            dut->a[17](a[17]);
            dut->a[18](a[18]);
            dut->a[19](a[19]);
            dut->a[20](a[20]);
            dut->a[21](a[21]);
            dut->a[22](a[22]);
            dut->a[23](a[23]);
            dut->a[24](a[24]);
            dut->a[25](a[25]);
            dut->a[26](a[26]);
            dut->a[27](a[27]);
            dut->a[28](a[28]);
            dut->a[29](a[29]);
            dut->a[30](a[30]);
            dut->a[31](a[31]);
            dut->b[0](b[0]);
            dut->b[1](b[1]);
            dut->b[2](b[2]);
            dut->b[3](b[3]);
            dut->b[4](b[4]);
            dut->b[5](b[5]);
            dut->b[6](b[6]);
            dut->b[7](b[7]);
            dut->b[8](b[8]);
            dut->b[9](b[9]);
            dut->b[10](b[10]);
            dut->b[11](b[11]);
            dut->b[12](b[12]);
            dut->b[13](b[13]);
            dut->b[14](b[14]);
            dut->b[15](b[15]);
            dut->b[16](b[16]);
            dut->b[17](b[17]);
            dut->b[18](b[18]);
            dut->b[19](b[19]);
            dut->b[20](b[20]);
            dut->b[21](b[21]);
            dut->b[22](b[22]);
            dut->b[23](b[23]);
            dut->b[24](b[24]);
            dut->b[25](b[25]);
            dut->b[26](b[26]);
            dut->b[27](b[27]);
            dut->b[28](b[28]);
            dut->b[29](b[29]);
            dut->b[30](b[30]);
            dut->b[31](b[31]);

            dut->result[0](result[0]);
            dut->result[1](result[1]);
            dut->result[2](result[2]);
            dut->result[3](result[3]);
            dut->result[4](result[4]);
            dut->result[5](result[5]);
            dut->result[6](result[6]);
            dut->result[7](result[7]);
            dut->result[8](result[8]);
            dut->result[9](result[9]);
            dut->result[10](result[10]);
            dut->result[11](result[11]);
            dut->result[12](result[12]);
            dut->result[13](result[13]);
            dut->result[14](result[14]);
            dut->result[15](result[15]);
            dut->result[16](result[16]);
            dut->result[17](result[17]);
            dut->result[18](result[18]);
            dut->result[19](result[19]);
            dut->result[20](result[20]);
            dut->result[21](result[21]);
            dut->result[22](result[22]);
            dut->result[23](result[23]);
            dut->result[24](result[24]);
            dut->result[25](result[25]);
            dut->result[26](result[26]);
            dut->result[27](result[27]);
            dut->result[28](result[28]);
            dut->result[29](result[29]);
            dut->result[30](result[30]);
            dut->result[31](result[31]);
                                                                                                
        SC_THREAD(signaling);

    }

    void signaling(void){
        subsel.write(SC_LOGIC_0);
        pass.write(SC_LOGIC_0);

        a[0].write(SC_LOGIC_0);
        a[1].write(SC_LOGIC_0);
        a[2].write(SC_LOGIC_0);
        a[3].write(SC_LOGIC_0);
        a[4].write(SC_LOGIC_0);
        a[5].write(SC_LOGIC_0);
        a[6].write(SC_LOGIC_0);
        a[7].write(SC_LOGIC_0);
        a[8].write(SC_LOGIC_0);
        a[9].write(SC_LOGIC_0);
        a[10].write(SC_LOGIC_0);
        a[11].write(SC_LOGIC_0);
        a[12].write(SC_LOGIC_0);
        a[13].write(SC_LOGIC_0);
        a[14].write(SC_LOGIC_0);
        a[15].write(SC_LOGIC_0);
        a[16].write(SC_LOGIC_0);
        a[17].write(SC_LOGIC_0);
        a[18].write(SC_LOGIC_0);
        a[19].write(SC_LOGIC_0);
        a[20].write(SC_LOGIC_0);
        a[21].write(SC_LOGIC_0);
        a[22].write(SC_LOGIC_0);
        a[23].write(SC_LOGIC_0);
        a[24].write(SC_LOGIC_0);
        a[25].write(SC_LOGIC_0);
        a[26].write(SC_LOGIC_0);
        a[27].write(SC_LOGIC_0);
        a[28].write(SC_LOGIC_0);
        a[29].write(SC_LOGIC_0);
        a[30].write(SC_LOGIC_0);
        a[31].write(SC_LOGIC_0);
        b[0].write(SC_LOGIC_0);
        b[1].write(SC_LOGIC_0);
        b[2].write(SC_LOGIC_0);
        b[3].write(SC_LOGIC_0);
        b[4].write(SC_LOGIC_0);
        b[5].write(SC_LOGIC_0);
        b[6].write(SC_LOGIC_0);
        b[7].write(SC_LOGIC_0);
        b[8].write(SC_LOGIC_0);
        b[9].write(SC_LOGIC_0);
        b[10].write(SC_LOGIC_0);
        b[11].write(SC_LOGIC_0);
        b[12].write(SC_LOGIC_0);
        b[13].write(SC_LOGIC_0);
        b[14].write(SC_LOGIC_0);
        b[15].write(SC_LOGIC_0);
        b[16].write(SC_LOGIC_0);
        b[17].write(SC_LOGIC_0);
        b[18].write(SC_LOGIC_0);
        b[19].write(SC_LOGIC_0);
        b[20].write(SC_LOGIC_0);
        b[21].write(SC_LOGIC_0);
        b[22].write(SC_LOGIC_0);
        b[23].write(SC_LOGIC_0);
        b[24].write(SC_LOGIC_0);
        b[25].write(SC_LOGIC_0);
        b[26].write(SC_LOGIC_0);
        b[27].write(SC_LOGIC_0);
        b[28].write(SC_LOGIC_0);
        b[29].write(SC_LOGIC_0);
        b[30].write(SC_LOGIC_0);
        b[31].write(SC_LOGIC_0);

        wait(20, SC_NS);

        // add 40 + 2 = 42
        a[3].write(SC_LOGIC_1);
        a[5].write(SC_LOGIC_1);
        b[1].write(SC_LOGIC_1);
        wait(20, SC_NS);
        
        // add 50 + 2 = 52
        a[1].write(SC_LOGIC_1);
        a[3].write(SC_LOGIC_0);
        a[4].write(SC_LOGIC_1);
        a[5].write(SC_LOGIC_1);
        b[1].write(SC_LOGIC_1);
        wait(20, SC_NS);

        // sub 10 + 2 = 8
        subsel.write(SC_LOGIC_1);
        a[1].write(SC_LOGIC_1);
        a[3].write(SC_LOGIC_1);
        a[5].write(SC_LOGIC_0);
        a[4].write(SC_LOGIC_0);
        wait(20, SC_NS);

        // sub 20 + 2 = 18
        a[1].write(SC_LOGIC_0);
        a[2].write(SC_LOGIC_1);
        a[3].write(SC_LOGIC_0);
        a[4].write(SC_LOGIC_1);
        
        // test pass 
        wait(20, SC_NS);
        pass.write(SC_LOGIC_1);
        a[7].write(SC_LOGIC_1);
        b[3].write(SC_LOGIC_0);
        wait(20, SC_NS);
        
        subsel.write(SC_LOGIC_1);
        wait(20, SC_NS);

    }
};
