#include <systemc.h>
#include "Complex_NAgate_45.h"
#include "sc_signal_pw.h"

using namespace sc_core;

SC_MODULE( three_level_gate ) {

    sc_in<sc_logic> i0;
    sc_in<sc_logic> i1;
    sc_in<sc_logic> i2;
    sc_out<sc_logic> o;

    sc_signal<sc_logic> sc_logic_1_signal;
    sc_signal<sc_logic> sc_logic_0_signal;

    sc_signal_pw<sc_logic> _0_ = sc_signal_pw<sc_logic>("_0_");
    sc_signal_pw<sc_logic> _1_ = sc_signal_pw<sc_logic>("_1_");

    INV_X1* INV_X1_1;
    NAND2_X1* NAND2_X1_1;
    NAND2_X1* NAND2_X1_2;

SC_CTOR( three_level_gate ) {
    INV_X1_1 = new INV_X1("INV_X1_1");
        INV_X1_1->A(i2);
        INV_X1_1->ZN(_0_);

    NAND2_X1_1 = new NAND2_X1("NAND2_X1_1");
        NAND2_X1_1->A1(i1);
        NAND2_X1_1->A2(i0);
        NAND2_X1_1->ZN(_1_);

    NAND2_X1_2 = new NAND2_X1("NAND2_X1_2");
        NAND2_X1_2->A1(_1_);
        NAND2_X1_2->A2(_0_);
        NAND2_X1_2->ZN(o);


    SC_METHOD(sc_logic_signal_assignment);

    }

    void sc_logic_signal_assignment(void){ 
        sc_logic_1_signal.write(SC_LOGIC_1);
        sc_logic_0_signal.write(SC_LOGIC_0);
    }
};
