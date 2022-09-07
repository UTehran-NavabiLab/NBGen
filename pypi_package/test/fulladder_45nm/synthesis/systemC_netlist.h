#include <systemc.h>
#include "component_library.h"

using namespace sc_core;

SC_MODULE( fulladder ) {

    sc_in<sc_logic> i0;
    sc_in<sc_logic> i1;
    sc_in<sc_logic> ci;
    sc_out<sc_logic> s;
    sc_out<sc_logic> co;

    sc_signal<sc_logic> sc_logic_1_signal;
    sc_signal<sc_logic> sc_logic_0_signal;

    sc_signal<sc_logic> _0_;
    sc_signal<sc_logic> _10_;
    sc_signal<sc_logic> _1_;
    sc_signal<sc_logic> _2_;
    sc_signal<sc_logic> _3_;
    sc_signal<sc_logic> _4_;
    sc_signal<sc_logic> _5_;
    sc_signal<sc_logic> _6_;
    sc_signal<sc_logic> _7_;
    sc_signal<sc_logic> _8_;
    sc_signal<sc_logic> _9_;

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
    INV_X1_4 = new INV_X1("INV_X1_4");
        INV_X1_4->A(i0);
        INV_X1_4->ZN(_8_);

    NAND2_X1_4 = new NAND2_X1("NAND2_X1_4");
        NAND2_X1_4->A1(i1);
        NAND2_X1_4->A2(ci);
        NAND2_X1_4->ZN(_0_);

    INV_X1_5 = new INV_X1("INV_X1_5");
        INV_X1_5->A(i1);
        INV_X1_5->ZN(_1_);

    INV_X1_6 = new INV_X1("INV_X1_6");
        INV_X1_6->A(ci);
        INV_X1_6->ZN(_2_);

    NAND2_X1_5 = new NAND2_X1("NAND2_X1_5");
        NAND2_X1_5->A1(_1_);
        NAND2_X1_5->A2(_2_);
        NAND2_X1_5->ZN(_3_);

    NAND3_X1_2 = new NAND3_X1("NAND3_X1_2");
        NAND3_X1_2->A1(_3_);
        NAND3_X1_2->A2(_8_);
        NAND3_X1_2->A3(_0_);
        NAND3_X1_2->ZN(_4_);

    NAND2_X1_6 = new NAND2_X1("NAND2_X1_6");
        NAND2_X1_6->A1(_7_);
        NAND2_X1_6->A2(_4_);
        NAND2_X1_6->ZN(_10_);

    OAI21_X1_3 = new OAI21_X1("OAI21_X1_3");
        OAI21_X1_3->A(_0_);
        OAI21_X1_3->B1(_6_);
        OAI21_X1_3->B2(_8_);
        OAI21_X1_3->ZN(_9_);

    AND2_X1_2 = new AND2_X1("AND2_X1_2");
        AND2_X1_2->A1(ci);
        AND2_X1_2->A2(i1);
        AND2_X1_2->ZN(_5_);

    NOR2_X1_2 = new NOR2_X1("NOR2_X1_2");
        NOR2_X1_2->A1(i1);
        NOR2_X1_2->A2(ci);
        NOR2_X1_2->ZN(_6_);

    OAI21_X1_4 = new OAI21_X1("OAI21_X1_4");
        OAI21_X1_4->A(i0);
        OAI21_X1_4->B1(_5_);
        OAI21_X1_4->B2(_6_);
        OAI21_X1_4->ZN(_7_);

    BUF_X1_3 = new BUF_X1("BUF_X1_3");
        BUF_X1_3->A(_9_);
        BUF_X1_3->Z(co);

    BUF_X1_4 = new BUF_X1("BUF_X1_4");
        BUF_X1_4->A(_10_);
        BUF_X1_4->Z(s);


    SC_METHOD(sc_logic_signal_assignment);

    }

    void sc_logic_signal_assignment(void){ 
        sc_logic_1_signal.write(SC_LOGIC_1);
        sc_logic_0_signal.write(SC_LOGIC_0);
    }
};
