#include <systemc.h>
#include "Complex_NAgate_45.h"

using namespace sc_core;

SC_MODULE( fulladder ) {

    sc_in<sc_logic> i0;
    sc_in<sc_logic> i1;
    sc_in<sc_logic> ci;
    sc_out<sc_logic> s;
    sc_out<sc_logic> co;

    sc_signal<sc_logic> sc_logic_1_signal;
    sc_signal<sc_logic> sc_logic_0_signal;

    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _0_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_0_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _10_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_10_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _1_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_1_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _2_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_2_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _3_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_3_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _4_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_4_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _5_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_5_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _6_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_6_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _7_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_7_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _8_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_8_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _9_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_9_");

    INV_X1* INV_X1_1;
    NAND2_X1* NAND2_X1_1;
    INV_X1* INV_X1_2;
    INV_X1* INV_X1_3;
    NAND2_X1* NAND2_X1_2;
    NAND3_X1* NAND3_X1_1;
    NAND2_X1* NAND2_X1_3;
    OAI21_X1* OAI21_X1_1;
    AND2_X1* AND2_X1_1;
    NOR2_X1* NOR2_X1_1;
    OAI21_X1* OAI21_X1_2;
    BUF_X1* BUF_X1_1;
    BUF_X1* BUF_X1_2;

SC_CTOR( fulladder ) {
    INV_X1_1 = new INV_X1("INV_X1_1");
        INV_X1_1->A(i0);
        INV_X1_1->ZN(_8_);

    NAND2_X1_1 = new NAND2_X1("NAND2_X1_1");
        NAND2_X1_1->A1(i1);
        NAND2_X1_1->A2(ci);
        NAND2_X1_1->ZN(_0_);

    INV_X1_2 = new INV_X1("INV_X1_2");
        INV_X1_2->A(i1);
        INV_X1_2->ZN(_1_);

    INV_X1_3 = new INV_X1("INV_X1_3");
        INV_X1_3->A(ci);
        INV_X1_3->ZN(_2_);

    NAND2_X1_2 = new NAND2_X1("NAND2_X1_2");
        NAND2_X1_2->A1(_1_);
        NAND2_X1_2->A2(_2_);
        NAND2_X1_2->ZN(_3_);

    NAND3_X1_1 = new NAND3_X1("NAND3_X1_1");
        NAND3_X1_1->A1(_3_);
        NAND3_X1_1->A2(_8_);
        NAND3_X1_1->A3(_0_);
        NAND3_X1_1->ZN(_4_);

    NAND2_X1_3 = new NAND2_X1("NAND2_X1_3");
        NAND2_X1_3->A1(_7_);
        NAND2_X1_3->A2(_4_);
        NAND2_X1_3->ZN(_10_);

    OAI21_X1_1 = new OAI21_X1("OAI21_X1_1");
        OAI21_X1_1->A(_0_);
        OAI21_X1_1->B1(_6_);
        OAI21_X1_1->B2(_8_);
        OAI21_X1_1->ZN(_9_);

    AND2_X1_1 = new AND2_X1("AND2_X1_1");
        AND2_X1_1->A1(ci);
        AND2_X1_1->A2(i1);
        AND2_X1_1->ZN(_5_);

    NOR2_X1_1 = new NOR2_X1("NOR2_X1_1");
        NOR2_X1_1->A1(i1);
        NOR2_X1_1->A2(ci);
        NOR2_X1_1->ZN(_6_);

    OAI21_X1_2 = new OAI21_X1("OAI21_X1_2");
        OAI21_X1_2->A(i0);
        OAI21_X1_2->B1(_5_);
        OAI21_X1_2->B2(_6_);
        OAI21_X1_2->ZN(_7_);

    BUF_X1_1 = new BUF_X1("BUF_X1_1");
        BUF_X1_1->A(_9_);
        BUF_X1_1->Z(co);

    BUF_X1_2 = new BUF_X1("BUF_X1_2");
        BUF_X1_2->A(_10_);
        BUF_X1_2->Z(s);


    SC_METHOD(sc_logic_signal_assignment);

    }

    void sc_logic_signal_assignment(void){ 
        sc_logic_1_signal.write(SC_LOGIC_1);
        sc_logic_0_signal.write(SC_LOGIC_0);
    }
};
