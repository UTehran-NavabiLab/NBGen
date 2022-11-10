#include <systemc.h>
#include "Complex_NAgate_45.h"

using namespace sc_core;

SC_MODULE( c17 ) {

    sc_in<sc_logic> N1;
    sc_in<sc_logic> N2;
    sc_in<sc_logic> N3;
    sc_in<sc_logic> N6;
    sc_in<sc_logic> N7;
    sc_out<sc_logic> N22;
    sc_out<sc_logic> N23;

    sc_signal<sc_logic> sc_logic_1_signal;
    sc_signal<sc_logic> sc_logic_0_signal;

    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _0_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_0_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _1_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_1_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _2_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_2_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _3_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_3_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _4_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_4_");

    INV_X1* INV_X1_1;
    AOI22_X1* AOI22_X1_1;
    NAND2_X1* NAND2_X1_1;
    NAND2_X1* NAND2_X1_2;
    NAND2_X1* NAND2_X1_3;
    NAND2_X1* NAND2_X1_4;
    INV_X1* INV_X1_2;

SC_CTOR( c17 ) {
    INV_X1_1 = new INV_X1("INV_X1_1");
        INV_X1_1->A(N7);
        INV_X1_1->ZN(_2_);

    AOI22_X1_1 = new AOI22_X1("AOI22_X1_1");
        AOI22_X1_1->A1(_1_);
        AOI22_X1_1->A2(_2_);
        AOI22_X1_1->B1(N3);
        AOI22_X1_1->B2(N6);
        AOI22_X1_1->ZN(N23);

    NAND2_X1_1 = new NAND2_X1("NAND2_X1_1");
        NAND2_X1_1->A1(N6);
        NAND2_X1_1->A2(N3);
        NAND2_X1_1->ZN(_3_);

    NAND2_X1_2 = new NAND2_X1("NAND2_X1_2");
        NAND2_X1_2->A1(_3_);
        NAND2_X1_2->A2(N2);
        NAND2_X1_2->ZN(_4_);

    NAND2_X1_3 = new NAND2_X1("NAND2_X1_3");
        NAND2_X1_3->A1(N3);
        NAND2_X1_3->A2(N1);
        NAND2_X1_3->ZN(_0_);

    NAND2_X1_4 = new NAND2_X1("NAND2_X1_4");
        NAND2_X1_4->A1(_4_);
        NAND2_X1_4->A2(_0_);
        NAND2_X1_4->ZN(N22);

    INV_X1_2 = new INV_X1("INV_X1_2");
        INV_X1_2->A(N2);
        INV_X1_2->ZN(_1_);


    SC_METHOD(sc_logic_signal_assignment);

    }

    void sc_logic_signal_assignment(void){ 
        sc_logic_1_signal.write(SC_LOGIC_1);
        sc_logic_0_signal.write(SC_LOGIC_0);
    }
};
