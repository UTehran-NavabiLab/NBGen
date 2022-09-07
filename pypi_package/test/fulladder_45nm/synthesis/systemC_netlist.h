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

    sc_signal<sc_logic> new__0_;
    sc_signal<sc_logic> new__10_;
    sc_signal<sc_logic> new__1_;
    sc_signal<sc_logic> new__2_;
    sc_signal<sc_logic> new__3_;
    sc_signal<sc_logic> new__4_;
    sc_signal<sc_logic> new__5_;
    sc_signal<sc_logic> new__6_;
    sc_signal<sc_logic> new__7_;
    sc_signal<sc_logic> new__8_;
    sc_signal<sc_logic> new__9_;

    INV_X1* INV_X1_0;
    NAND2_X1* NAND2_X1_1;
    INV_X1* INV_X1_2;
    INV_X1* INV_X1_3;
    NAND2_X1* NAND2_X1_4;
    NAND3_X1* NAND3_X1_5;
    NAND2_X1* NAND2_X1_6;
    OAI21_X1* OAI21_X1_7;
    AND2_X1* AND2_X1_8;
    NOR2_X1* NOR2_X1_9;
    OAI21_X1* OAI21_X1_10;
    BUF_X1* BUF_X1_11;
    BUF_X1* BUF_X1_12;

SC_CTOR( fulladder ) {
    INV_X1_0 = new INV_X1("INV_X1_0");
        INV_X1_0->A(i0);
        INV_X1_0->ZN(new__8_);

    NAND2_X1_1 = new NAND2_X1("NAND2_X1_1");
        NAND2_X1_1->A1(i1);
        NAND2_X1_1->A2(ci);
        NAND2_X1_1->ZN(new__0_);

    INV_X1_2 = new INV_X1("INV_X1_2");
        INV_X1_2->A(i1);
        INV_X1_2->ZN(new__1_);

    INV_X1_3 = new INV_X1("INV_X1_3");
        INV_X1_3->A(ci);
        INV_X1_3->ZN(new__2_);

    NAND2_X1_4 = new NAND2_X1("NAND2_X1_4");
        NAND2_X1_4->A1(new__1_);
        NAND2_X1_4->A2(new__2_);
        NAND2_X1_4->ZN(new__3_);

    NAND3_X1_5 = new NAND3_X1("NAND3_X1_5");
        NAND3_X1_5->A1(new__3_);
        NAND3_X1_5->A2(new__8_);
        NAND3_X1_5->A3(new__0_);
        NAND3_X1_5->ZN(new__4_);

    NAND2_X1_6 = new NAND2_X1("NAND2_X1_6");
        NAND2_X1_6->A1(new__7_);
        NAND2_X1_6->A2(new__4_);
        NAND2_X1_6->ZN(new__10_);

    OAI21_X1_7 = new OAI21_X1("OAI21_X1_7");
        OAI21_X1_7->A(new__0_);
        OAI21_X1_7->B1(new__6_);
        OAI21_X1_7->B2(new__8_);
        OAI21_X1_7->ZN(new__9_);

    AND2_X1_8 = new AND2_X1("AND2_X1_8");
        AND2_X1_8->A1(ci);
        AND2_X1_8->A2(i1);
        AND2_X1_8->ZN(new__5_);

    NOR2_X1_9 = new NOR2_X1("NOR2_X1_9");
        NOR2_X1_9->A1(i1);
        NOR2_X1_9->A2(ci);
        NOR2_X1_9->ZN(new__6_);

    OAI21_X1_10 = new OAI21_X1("OAI21_X1_10");
        OAI21_X1_10->A(i0);
        OAI21_X1_10->B1(new__5_);
        OAI21_X1_10->B2(new__6_);
        OAI21_X1_10->ZN(new__7_);

    BUF_X1_11 = new BUF_X1("BUF_X1_11");
        BUF_X1_11->A(new__9_);
        BUF_X1_11->Z(co);

    BUF_X1_12 = new BUF_X1("BUF_X1_12");
        BUF_X1_12->A(new__10_);
        BUF_X1_12->Z(s);


    SC_METHOD(sc_logic_signal_assignment);

    }

    void sc_logic_signal_assignment(void){ 
        sc_logic_1_signal.write(SC_LOGIC_1);
        sc_logic_0_signal.write(SC_LOGIC_0);
    }
};
