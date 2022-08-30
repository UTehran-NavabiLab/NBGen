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

    sc_signal<sc_logic> S0;
    sc_signal<sc_logic> S1;
    sc_signal<sc_logic> S2;
    sc_signal<sc_logic> S3;
    sc_signal<sc_logic> S4;
    sc_signal<sc_logic> S5;
    sc_signal<sc_logic> S6;
    sc_signal<sc_logic> S7;

    OAI21_X1* OAI21_X1_0;
    NAND2_X1* NAND2_X1_1;
    NAND2_X1* NAND2_X1_2;
    XNOR2_X1* XNOR2_X1_3;
    XNOR2_X1* XNOR2_X1_4;
    BUF_X1* BUF_X1_5;
    BUF_X1* BUF_X1_6;
    BUF_X1* BUF_X1_7;
    BUF_X1* BUF_X1_8;
    BUF_X1* BUF_X1_9;

SC_CTOR( fulladder ) {
    OAI21_X1_0 = new OAI21_X1("OAI21_X1_0");
        OAI21_X1_0->A1(S6);
        OAI21_X1_0->A2(S3);
        OAI21_X1_0->B(S5);
        OAI21_X1_0->ZN(S2);

    NAND2_X1_1 = new NAND2_X1("NAND2_X1_1");
        NAND2_X1_1->A1(S0);
        NAND2_X1_1->A2(S2);
        NAND2_X1_1->ZN(S4);

    NAND2_X1_2 = new NAND2_X1("NAND2_X1_2");
        NAND2_X1_2->A1(S6);
        NAND2_X1_2->A2(S3);
        NAND2_X1_2->ZN(S0);

    XNOR2_X1_3 = new XNOR2_X1("XNOR2_X1_3");
        XNOR2_X1_3->A1(S6);
        XNOR2_X1_3->A2(S3);
        XNOR2_X1_3->ZN(S1);

    XNOR2_X1_4 = new XNOR2_X1("XNOR2_X1_4");
        XNOR2_X1_4->A1(S5);
        XNOR2_X1_4->A2(S1);
        XNOR2_X1_4->ZN(S7);

    BUF_X1_5 = new BUF_X1("BUF_X1_5");
        BUF_X1_5->I(ci);
        BUF_X1_5->Z(S3);

    BUF_X1_6 = new BUF_X1("BUF_X1_6");
        BUF_X1_6->I(S4);
        BUF_X1_6->Z(co);

    BUF_X1_7 = new BUF_X1("BUF_X1_7");
        BUF_X1_7->I(i0);
        BUF_X1_7->Z(S5);

    BUF_X1_8 = new BUF_X1("BUF_X1_8");
        BUF_X1_8->I(i1);
        BUF_X1_8->Z(S6);

    BUF_X1_9 = new BUF_X1("BUF_X1_9");
        BUF_X1_9->I(S7);
        BUF_X1_9->Z(s);


    SC_METHOD(sc_logic_signal_assignment);

    }

    void sc_logic_signal_assignment(void){ 
        sc_logic_1_signal.write(SC_LOGIC_1);
        sc_logic_0_signal.write(SC_LOGIC_0);
    }
};
