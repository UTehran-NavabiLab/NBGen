#include <systemc.h>
#include "Complex_NAgate_45.h"



#ifndef __MUX2OFNBITS_5_H__
#define __MUX2OFNBITS_5_H__
using namespace sc_core;

SC_MODULE( mux2ofnbits_5 ) {

    sc_in<sc_logic> in1[5];
    sc_in<sc_logic> in2[5];
    sc_in<sc_logic> sel1;
    sc_in<sc_logic> sel2;
    sc_out<sc_logic> outmux[5];

    sc_signal<sc_logic> sc_logic_1_signal;
    sc_signal<sc_logic> sc_logic_0_signal;

    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S0 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S0");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S1 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S1");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S2 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S2");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S3 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S3");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S4 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S4");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S5 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S5");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S6 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S6");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S7 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S7");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S8 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S8");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S9 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S9");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S10[5];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S11[5];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S12[5];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S13 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S13");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S14 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S14");

    NAND2_X1* NAND2_X1_1;
    NAND2_X1* NAND2_X1_2;
    OAI21_X1* OAI21_X1_1;
    NAND2_X1* NAND2_X1_3;
    NAND2_X1* NAND2_X1_4;
    OAI21_X1* OAI21_X1_2;
    NAND2_X1* NAND2_X1_5;
    NAND2_X1* NAND2_X1_6;
    OAI21_X1* OAI21_X1_3;
    NAND2_X1* NAND2_X1_7;
    NAND2_X1* NAND2_X1_8;
    OAI21_X1* OAI21_X1_4;
    NAND2_X1* NAND2_X1_9;
    NAND2_X1* NAND2_X1_10;
    OAI21_X1* OAI21_X1_5;
    BUF_X1* BUF_X1_1;
    BUF_X1* BUF_X1_2;
    BUF_X1* BUF_X1_3;
    BUF_X1* BUF_X1_4;
    BUF_X1* BUF_X1_5;
    BUF_X1* BUF_X1_6;
    BUF_X1* BUF_X1_7;
    BUF_X1* BUF_X1_8;
    BUF_X1* BUF_X1_9;
    BUF_X1* BUF_X1_10;
    BUF_X1* BUF_X1_11;
    BUF_X1* BUF_X1_12;
    BUF_X1* BUF_X1_13;
    BUF_X1* BUF_X1_14;
    BUF_X1* BUF_X1_15;
    BUF_X1* BUF_X1_16;
    BUF_X1* BUF_X1_17;

SC_CTOR( mux2ofnbits_5 ) {
    NAND2_X1_1 = new NAND2_X1("NAND2_X1_1");
        NAND2_X1_1->A1(S14);
        NAND2_X1_1->A2(S11[0]);
        NAND2_X1_1->ZN(S0);

    NAND2_X1_2 = new NAND2_X1("NAND2_X1_2");
        NAND2_X1_2->A1(S10[0]);
        NAND2_X1_2->A2(S13);
        NAND2_X1_2->ZN(S1);

    OAI21_X1_1 = new OAI21_X1("OAI21_X1_1");
        OAI21_X1_1->A(S1);
        OAI21_X1_1->B1(S0);
        OAI21_X1_1->B2(S13);
        OAI21_X1_1->ZN(S12[0]);

    NAND2_X1_3 = new NAND2_X1("NAND2_X1_3");
        NAND2_X1_3->A1(S14);
        NAND2_X1_3->A2(S11[1]);
        NAND2_X1_3->ZN(S2);

    NAND2_X1_4 = new NAND2_X1("NAND2_X1_4");
        NAND2_X1_4->A1(S13);
        NAND2_X1_4->A2(S10[1]);
        NAND2_X1_4->ZN(S3);

    OAI21_X1_2 = new OAI21_X1("OAI21_X1_2");
        OAI21_X1_2->A(S3);
        OAI21_X1_2->B1(S2);
        OAI21_X1_2->B2(S13);
        OAI21_X1_2->ZN(S12[1]);

    NAND2_X1_5 = new NAND2_X1("NAND2_X1_5");
        NAND2_X1_5->A1(S14);
        NAND2_X1_5->A2(S11[2]);
        NAND2_X1_5->ZN(S4);

    NAND2_X1_6 = new NAND2_X1("NAND2_X1_6");
        NAND2_X1_6->A1(S13);
        NAND2_X1_6->A2(S10[2]);
        NAND2_X1_6->ZN(S5);

    OAI21_X1_3 = new OAI21_X1("OAI21_X1_3");
        OAI21_X1_3->A(S5);
        OAI21_X1_3->B1(S4);
        OAI21_X1_3->B2(S13);
        OAI21_X1_3->ZN(S12[2]);

    NAND2_X1_7 = new NAND2_X1("NAND2_X1_7");
        NAND2_X1_7->A1(S14);
        NAND2_X1_7->A2(S11[3]);
        NAND2_X1_7->ZN(S6);

    NAND2_X1_8 = new NAND2_X1("NAND2_X1_8");
        NAND2_X1_8->A1(S13);
        NAND2_X1_8->A2(S10[3]);
        NAND2_X1_8->ZN(S7);

    OAI21_X1_4 = new OAI21_X1("OAI21_X1_4");
        OAI21_X1_4->A(S7);
        OAI21_X1_4->B1(S6);
        OAI21_X1_4->B2(S13);
        OAI21_X1_4->ZN(S12[3]);

    NAND2_X1_9 = new NAND2_X1("NAND2_X1_9");
        NAND2_X1_9->A1(S14);
        NAND2_X1_9->A2(S11[4]);
        NAND2_X1_9->ZN(S8);

    NAND2_X1_10 = new NAND2_X1("NAND2_X1_10");
        NAND2_X1_10->A1(S13);
        NAND2_X1_10->A2(S10[4]);
        NAND2_X1_10->ZN(S9);

    OAI21_X1_5 = new OAI21_X1("OAI21_X1_5");
        OAI21_X1_5->A(S9);
        OAI21_X1_5->B1(S8);
        OAI21_X1_5->B2(S13);
        OAI21_X1_5->ZN(S12[4]);

    BUF_X1_1 = new BUF_X1("BUF_X1_1");
        BUF_X1_1->A(in1[0]);
        BUF_X1_1->Z(S10[0]);

    BUF_X1_2 = new BUF_X1("BUF_X1_2");
        BUF_X1_2->A(in1[1]);
        BUF_X1_2->Z(S10[1]);

    BUF_X1_3 = new BUF_X1("BUF_X1_3");
        BUF_X1_3->A(in1[2]);
        BUF_X1_3->Z(S10[2]);

    BUF_X1_4 = new BUF_X1("BUF_X1_4");
        BUF_X1_4->A(in1[3]);
        BUF_X1_4->Z(S10[3]);

    BUF_X1_5 = new BUF_X1("BUF_X1_5");
        BUF_X1_5->A(in1[4]);
        BUF_X1_5->Z(S10[4]);

    BUF_X1_6 = new BUF_X1("BUF_X1_6");
        BUF_X1_6->A(in2[0]);
        BUF_X1_6->Z(S11[0]);

    BUF_X1_7 = new BUF_X1("BUF_X1_7");
        BUF_X1_7->A(in2[1]);
        BUF_X1_7->Z(S11[1]);

    BUF_X1_8 = new BUF_X1("BUF_X1_8");
        BUF_X1_8->A(in2[2]);
        BUF_X1_8->Z(S11[2]);

    BUF_X1_9 = new BUF_X1("BUF_X1_9");
        BUF_X1_9->A(in2[3]);
        BUF_X1_9->Z(S11[3]);

    BUF_X1_10 = new BUF_X1("BUF_X1_10");
        BUF_X1_10->A(in2[4]);
        BUF_X1_10->Z(S11[4]);

    BUF_X1_11 = new BUF_X1("BUF_X1_11");
        BUF_X1_11->A(S12[0]);
        BUF_X1_11->Z(outmux[0]);

    BUF_X1_12 = new BUF_X1("BUF_X1_12");
        BUF_X1_12->A(S12[1]);
        BUF_X1_12->Z(outmux[1]);

    BUF_X1_13 = new BUF_X1("BUF_X1_13");
        BUF_X1_13->A(S12[2]);
        BUF_X1_13->Z(outmux[2]);

    BUF_X1_14 = new BUF_X1("BUF_X1_14");
        BUF_X1_14->A(S12[3]);
        BUF_X1_14->Z(outmux[3]);

    BUF_X1_15 = new BUF_X1("BUF_X1_15");
        BUF_X1_15->A(S12[4]);
        BUF_X1_15->Z(outmux[4]);

    BUF_X1_16 = new BUF_X1("BUF_X1_16");
        BUF_X1_16->A(sel1);
        BUF_X1_16->Z(S13);

    BUF_X1_17 = new BUF_X1("BUF_X1_17");
        BUF_X1_17->A(sel2);
        BUF_X1_17->Z(S14);


    SC_METHOD(sc_logic_signal_assignment);

    }

    void sc_logic_signal_assignment(void){ 
        sc_logic_1_signal.write(SC_LOGIC_1);
        sc_logic_0_signal.write(SC_LOGIC_0);
    }
};
#endif /* __MUX2OFNBITS_5_H__ */
