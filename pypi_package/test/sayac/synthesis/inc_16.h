#include <systemc.h>
#include "Complex_NAgate_45.h"



#ifndef __INC_16_H__
#define __INC_16_H__
using namespace sc_core;

SC_MODULE( inc_16 ) {

    sc_in<sc_logic> ininc[16];
    sc_out<sc_logic> outinc[16];

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
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S10 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S10");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S11 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S11");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S12 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S12");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S13 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S13");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S14 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S14");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S15 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S15");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S16 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S16");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S17 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S17");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S18 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S18");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S19 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S19");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S20 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S20");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S21 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S21");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S22 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S22");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S23 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S23");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S24 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S24");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S25 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S25");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S26 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S26");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S27 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S27");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S28 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S28");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S29 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S29");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S30 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S30");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S31[16];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S32[16];

    INV_X1* INV_X1_1;
    XOR2_X1* XOR2_X1_1;
    NAND2_X1* NAND2_X1_1;
    XNOR2_X1* XNOR2_X1_1;
    NAND3_X1* NAND3_X1_1;
    XNOR2_X1* XNOR2_X1_2;
    NAND4_X1* NAND4_X1_1;
    XNOR2_X1* XNOR2_X1_3;
    INV_X1* INV_X1_2;
    INV_X1* INV_X1_3;
    NOR2_X1* NOR2_X1_1;
    XNOR2_X1* XNOR2_X1_4;
    INV_X1* INV_X1_4;
    NOR4_X1* NOR4_X1_1;
    AOI21_X1* AOI21_X1_1;
    NOR2_X1* NOR2_X1_2;
    XOR2_X1* XOR2_X1_2;
    NAND2_X1* NAND2_X1_2;
    XNOR2_X1* XNOR2_X1_5;
    NAND4_X1* NAND4_X1_2;
    INV_X1* INV_X1_5;
    INV_X1* INV_X1_6;
    OAI21_X1* OAI21_X1_1;
    AND2_X1* AND2_X1_1;
    XNOR2_X1* XNOR2_X1_6;
    INV_X1* INV_X1_7;
    INV_X1* INV_X1_8;
    NOR3_X1* NOR3_X1_1;
    NOR2_X1* NOR2_X1_3;
    NOR2_X1* NOR2_X1_4;
    NOR2_X1* NOR2_X1_5;
    INV_X1* INV_X1_9;
    NOR4_X1* NOR4_X1_2;
    NOR2_X1* NOR2_X1_6;
    NOR2_X1* NOR2_X1_7;
    INV_X1* INV_X1_10;
    XNOR2_X1* XNOR2_X1_7;
    NAND2_X1* NAND2_X1_3;
    NAND2_X1* NAND2_X1_4;
    INV_X1* INV_X1_11;
    NAND3_X1* NAND3_X1_2;
    NAND2_X1* NAND2_X1_5;
    NAND4_X1* NAND4_X1_3;
    NAND2_X1* NAND2_X1_6;
    INV_X1* INV_X1_12;
    NAND4_X1* NAND4_X1_4;
    NAND2_X1* NAND2_X1_7;
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
    BUF_X1* BUF_X1_18;
    BUF_X1* BUF_X1_19;
    BUF_X1* BUF_X1_20;
    BUF_X1* BUF_X1_21;
    BUF_X1* BUF_X1_22;
    BUF_X1* BUF_X1_23;
    BUF_X1* BUF_X1_24;
    BUF_X1* BUF_X1_25;
    BUF_X1* BUF_X1_26;
    BUF_X1* BUF_X1_27;
    BUF_X1* BUF_X1_28;
    BUF_X1* BUF_X1_29;
    BUF_X1* BUF_X1_30;
    BUF_X1* BUF_X1_31;
    BUF_X1* BUF_X1_32;

SC_CTOR( inc_16 ) {
    INV_X1_1 = new INV_X1("INV_X1_1");
        INV_X1_1->A(S31[0]);
        INV_X1_1->ZN(S32[0]);

    XOR2_X1_1 = new XOR2_X1("XOR2_X1_1");
        XOR2_X1_1->A(S31[0]);
        XOR2_X1_1->B(S31[1]);
        XOR2_X1_1->Z(S32[1]);

    NAND2_X1_1 = new NAND2_X1("NAND2_X1_1");
        NAND2_X1_1->A1(S31[0]);
        NAND2_X1_1->A2(S31[1]);
        NAND2_X1_1->ZN(S0);

    XNOR2_X1_1 = new XNOR2_X1("XNOR2_X1_1");
        XNOR2_X1_1->A(S0);
        XNOR2_X1_1->B(S31[2]);
        XNOR2_X1_1->ZN(S32[2]);

    NAND3_X1_1 = new NAND3_X1("NAND3_X1_1");
        NAND3_X1_1->A1(S31[0]);
        NAND3_X1_1->A2(S31[1]);
        NAND3_X1_1->A3(S31[2]);
        NAND3_X1_1->ZN(S1);

    XNOR2_X1_2 = new XNOR2_X1("XNOR2_X1_2");
        XNOR2_X1_2->A(S1);
        XNOR2_X1_2->B(S31[3]);
        XNOR2_X1_2->ZN(S32[3]);

    NAND4_X1_1 = new NAND4_X1("NAND4_X1_1");
        NAND4_X1_1->A1(S31[2]);
        NAND4_X1_1->A2(S31[3]);
        NAND4_X1_1->A3(S31[0]);
        NAND4_X1_1->A4(S31[1]);
        NAND4_X1_1->ZN(S2);

    XNOR2_X1_3 = new XNOR2_X1("XNOR2_X1_3");
        XNOR2_X1_3->A(S2);
        XNOR2_X1_3->B(S31[4]);
        XNOR2_X1_3->ZN(S32[4]);

    INV_X1_2 = new INV_X1("INV_X1_2");
        INV_X1_2->A(S31[5]);
        INV_X1_2->ZN(S3);

    INV_X1_3 = new INV_X1("INV_X1_3");
        INV_X1_3->A(S31[4]);
        INV_X1_3->ZN(S4);

    NOR2_X1_1 = new NOR2_X1("NOR2_X1_1");
        NOR2_X1_1->A1(S2);
        NOR2_X1_1->A2(S4);
        NOR2_X1_1->ZN(S5);

    XNOR2_X1_4 = new XNOR2_X1("XNOR2_X1_4");
        XNOR2_X1_4->A(S5);
        XNOR2_X1_4->B(S3);
        XNOR2_X1_4->ZN(S32[5]);

    INV_X1_4 = new INV_X1("INV_X1_4");
        INV_X1_4->A(S31[6]);
        INV_X1_4->ZN(S6);

    NOR4_X1_1 = new NOR4_X1("NOR4_X1_1");
        NOR4_X1_1->A1(S2);
        NOR4_X1_1->A2(S6);
        NOR4_X1_1->A3(S3);
        NOR4_X1_1->A4(S4);
        NOR4_X1_1->ZN(S7);

    AOI21_X1_1 = new AOI21_X1("AOI21_X1_1");
        AOI21_X1_1->A(S31[6]);
        AOI21_X1_1->B1(S5);
        AOI21_X1_1->B2(S31[5]);
        AOI21_X1_1->ZN(S8);

    NOR2_X1_2 = new NOR2_X1("NOR2_X1_2");
        NOR2_X1_2->A1(S8);
        NOR2_X1_2->A2(S7);
        NOR2_X1_2->ZN(S32[6]);

    XOR2_X1_2 = new XOR2_X1("XOR2_X1_2");
        XOR2_X1_2->A(S7);
        XOR2_X1_2->B(S31[7]);
        XOR2_X1_2->Z(S32[7]);

    NAND2_X1_2 = new NAND2_X1("NAND2_X1_2");
        NAND2_X1_2->A1(S7);
        NAND2_X1_2->A2(S31[7]);
        NAND2_X1_2->ZN(S9);

    XNOR2_X1_5 = new XNOR2_X1("XNOR2_X1_5");
        XNOR2_X1_5->A(S9);
        XNOR2_X1_5->B(S31[8]);
        XNOR2_X1_5->ZN(S32[8]);

    NAND4_X1_2 = new NAND4_X1("NAND4_X1_2");
        NAND4_X1_2->A1(S7);
        NAND4_X1_2->A2(S31[9]);
        NAND4_X1_2->A3(S31[8]);
        NAND4_X1_2->A4(S31[7]);
        NAND4_X1_2->ZN(S10);

    INV_X1_5 = new INV_X1("INV_X1_5");
        INV_X1_5->A(S31[8]);
        INV_X1_5->ZN(S11);

    INV_X1_6 = new INV_X1("INV_X1_6");
        INV_X1_6->A(S31[9]);
        INV_X1_6->ZN(S12);

    OAI21_X1_1 = new OAI21_X1("OAI21_X1_1");
        OAI21_X1_1->A(S12);
        OAI21_X1_1->B1(S9);
        OAI21_X1_1->B2(S11);
        OAI21_X1_1->ZN(S13);

    AND2_X1_1 = new AND2_X1("AND2_X1_1");
        AND2_X1_1->A1(S13);
        AND2_X1_1->A2(S10);
        AND2_X1_1->ZN(S32[9]);

    XNOR2_X1_6 = new XNOR2_X1("XNOR2_X1_6");
        XNOR2_X1_6->A(S10);
        XNOR2_X1_6->B(S31[10]);
        XNOR2_X1_6->ZN(S32[10]);

    INV_X1_7 = new INV_X1("INV_X1_7");
        INV_X1_7->A(S31[10]);
        INV_X1_7->ZN(S14);

    INV_X1_8 = new INV_X1("INV_X1_8");
        INV_X1_8->A(S31[11]);
        INV_X1_8->ZN(S15);

    NOR3_X1_1 = new NOR3_X1("NOR3_X1_1");
        NOR3_X1_1->A1(S10);
        NOR3_X1_1->A2(S15);
        NOR3_X1_1->A3(S14);
        NOR3_X1_1->ZN(S16);

    NOR2_X1_3 = new NOR2_X1("NOR2_X1_3");
        NOR2_X1_3->A1(S10);
        NOR2_X1_3->A2(S14);
        NOR2_X1_3->ZN(S17);

    NOR2_X1_4 = new NOR2_X1("NOR2_X1_4");
        NOR2_X1_4->A1(S17);
        NOR2_X1_4->A2(S31[11]);
        NOR2_X1_4->ZN(S18);

    NOR2_X1_5 = new NOR2_X1("NOR2_X1_5");
        NOR2_X1_5->A1(S18);
        NOR2_X1_5->A2(S16);
        NOR2_X1_5->ZN(S32[11]);

    INV_X1_9 = new INV_X1("INV_X1_9");
        INV_X1_9->A(S31[12]);
        INV_X1_9->ZN(S19);

    NOR4_X1_2 = new NOR4_X1("NOR4_X1_2");
        NOR4_X1_2->A1(S10);
        NOR4_X1_2->A2(S19);
        NOR4_X1_2->A3(S15);
        NOR4_X1_2->A4(S14);
        NOR4_X1_2->ZN(S20);

    NOR2_X1_6 = new NOR2_X1("NOR2_X1_6");
        NOR2_X1_6->A1(S16);
        NOR2_X1_6->A2(S31[12]);
        NOR2_X1_6->ZN(S21);

    NOR2_X1_7 = new NOR2_X1("NOR2_X1_7");
        NOR2_X1_7->A1(S21);
        NOR2_X1_7->A2(S20);
        NOR2_X1_7->ZN(S32[12]);

    INV_X1_10 = new INV_X1("INV_X1_10");
        INV_X1_10->A(S31[13]);
        INV_X1_10->ZN(S22);

    XNOR2_X1_7 = new XNOR2_X1("XNOR2_X1_7");
        XNOR2_X1_7->A(S20);
        XNOR2_X1_7->B(S22);
        XNOR2_X1_7->ZN(S32[13]);

    NAND2_X1_3 = new NAND2_X1("NAND2_X1_3");
        NAND2_X1_3->A1(S20);
        NAND2_X1_3->A2(S31[13]);
        NAND2_X1_3->ZN(S23);

    NAND2_X1_4 = new NAND2_X1("NAND2_X1_4");
        NAND2_X1_4->A1(S23);
        NAND2_X1_4->A2(S31[14]);
        NAND2_X1_4->ZN(S24);

    INV_X1_11 = new INV_X1("INV_X1_11");
        INV_X1_11->A(S31[14]);
        INV_X1_11->ZN(S25);

    NAND3_X1_2 = new NAND3_X1("NAND3_X1_2");
        NAND3_X1_2->A1(S20);
        NAND3_X1_2->A2(S31[13]);
        NAND3_X1_2->A3(S25);
        NAND3_X1_2->ZN(S26);

    NAND2_X1_5 = new NAND2_X1("NAND2_X1_5");
        NAND2_X1_5->A1(S24);
        NAND2_X1_5->A2(S26);
        NAND2_X1_5->ZN(S32[14]);

    NAND4_X1_3 = new NAND4_X1("NAND4_X1_3");
        NAND4_X1_3->A1(S16);
        NAND4_X1_3->A2(S31[14]);
        NAND4_X1_3->A3(S31[13]);
        NAND4_X1_3->A4(S31[12]);
        NAND4_X1_3->ZN(S27);

    NAND2_X1_6 = new NAND2_X1("NAND2_X1_6");
        NAND2_X1_6->A1(S27);
        NAND2_X1_6->A2(S31[15]);
        NAND2_X1_6->ZN(S28);

    INV_X1_12 = new INV_X1("INV_X1_12");
        INV_X1_12->A(S31[15]);
        INV_X1_12->ZN(S29);

    NAND4_X1_4 = new NAND4_X1("NAND4_X1_4");
        NAND4_X1_4->A1(S20);
        NAND4_X1_4->A2(S29);
        NAND4_X1_4->A3(S31[14]);
        NAND4_X1_4->A4(S31[13]);
        NAND4_X1_4->ZN(S30);

    NAND2_X1_7 = new NAND2_X1("NAND2_X1_7");
        NAND2_X1_7->A1(S28);
        NAND2_X1_7->A2(S30);
        NAND2_X1_7->ZN(S32[15]);

    BUF_X1_1 = new BUF_X1("BUF_X1_1");
        BUF_X1_1->A(ininc[0]);
        BUF_X1_1->Z(S31[0]);

    BUF_X1_2 = new BUF_X1("BUF_X1_2");
        BUF_X1_2->A(ininc[1]);
        BUF_X1_2->Z(S31[1]);

    BUF_X1_3 = new BUF_X1("BUF_X1_3");
        BUF_X1_3->A(ininc[10]);
        BUF_X1_3->Z(S31[10]);

    BUF_X1_4 = new BUF_X1("BUF_X1_4");
        BUF_X1_4->A(ininc[11]);
        BUF_X1_4->Z(S31[11]);

    BUF_X1_5 = new BUF_X1("BUF_X1_5");
        BUF_X1_5->A(ininc[12]);
        BUF_X1_5->Z(S31[12]);

    BUF_X1_6 = new BUF_X1("BUF_X1_6");
        BUF_X1_6->A(ininc[13]);
        BUF_X1_6->Z(S31[13]);

    BUF_X1_7 = new BUF_X1("BUF_X1_7");
        BUF_X1_7->A(ininc[14]);
        BUF_X1_7->Z(S31[14]);

    BUF_X1_8 = new BUF_X1("BUF_X1_8");
        BUF_X1_8->A(ininc[15]);
        BUF_X1_8->Z(S31[15]);

    BUF_X1_9 = new BUF_X1("BUF_X1_9");
        BUF_X1_9->A(ininc[2]);
        BUF_X1_9->Z(S31[2]);

    BUF_X1_10 = new BUF_X1("BUF_X1_10");
        BUF_X1_10->A(ininc[3]);
        BUF_X1_10->Z(S31[3]);

    BUF_X1_11 = new BUF_X1("BUF_X1_11");
        BUF_X1_11->A(ininc[4]);
        BUF_X1_11->Z(S31[4]);

    BUF_X1_12 = new BUF_X1("BUF_X1_12");
        BUF_X1_12->A(ininc[5]);
        BUF_X1_12->Z(S31[5]);

    BUF_X1_13 = new BUF_X1("BUF_X1_13");
        BUF_X1_13->A(ininc[6]);
        BUF_X1_13->Z(S31[6]);

    BUF_X1_14 = new BUF_X1("BUF_X1_14");
        BUF_X1_14->A(ininc[7]);
        BUF_X1_14->Z(S31[7]);

    BUF_X1_15 = new BUF_X1("BUF_X1_15");
        BUF_X1_15->A(ininc[8]);
        BUF_X1_15->Z(S31[8]);

    BUF_X1_16 = new BUF_X1("BUF_X1_16");
        BUF_X1_16->A(ininc[9]);
        BUF_X1_16->Z(S31[9]);

    BUF_X1_17 = new BUF_X1("BUF_X1_17");
        BUF_X1_17->A(S32[0]);
        BUF_X1_17->Z(outinc[0]);

    BUF_X1_18 = new BUF_X1("BUF_X1_18");
        BUF_X1_18->A(S32[1]);
        BUF_X1_18->Z(outinc[1]);

    BUF_X1_19 = new BUF_X1("BUF_X1_19");
        BUF_X1_19->A(S32[10]);
        BUF_X1_19->Z(outinc[10]);

    BUF_X1_20 = new BUF_X1("BUF_X1_20");
        BUF_X1_20->A(S32[11]);
        BUF_X1_20->Z(outinc[11]);

    BUF_X1_21 = new BUF_X1("BUF_X1_21");
        BUF_X1_21->A(S32[12]);
        BUF_X1_21->Z(outinc[12]);

    BUF_X1_22 = new BUF_X1("BUF_X1_22");
        BUF_X1_22->A(S32[13]);
        BUF_X1_22->Z(outinc[13]);

    BUF_X1_23 = new BUF_X1("BUF_X1_23");
        BUF_X1_23->A(S32[14]);
        BUF_X1_23->Z(outinc[14]);

    BUF_X1_24 = new BUF_X1("BUF_X1_24");
        BUF_X1_24->A(S32[15]);
        BUF_X1_24->Z(outinc[15]);

    BUF_X1_25 = new BUF_X1("BUF_X1_25");
        BUF_X1_25->A(S32[2]);
        BUF_X1_25->Z(outinc[2]);

    BUF_X1_26 = new BUF_X1("BUF_X1_26");
        BUF_X1_26->A(S32[3]);
        BUF_X1_26->Z(outinc[3]);

    BUF_X1_27 = new BUF_X1("BUF_X1_27");
        BUF_X1_27->A(S32[4]);
        BUF_X1_27->Z(outinc[4]);

    BUF_X1_28 = new BUF_X1("BUF_X1_28");
        BUF_X1_28->A(S32[5]);
        BUF_X1_28->Z(outinc[5]);

    BUF_X1_29 = new BUF_X1("BUF_X1_29");
        BUF_X1_29->A(S32[6]);
        BUF_X1_29->Z(outinc[6]);

    BUF_X1_30 = new BUF_X1("BUF_X1_30");
        BUF_X1_30->A(S32[7]);
        BUF_X1_30->Z(outinc[7]);

    BUF_X1_31 = new BUF_X1("BUF_X1_31");
        BUF_X1_31->A(S32[8]);
        BUF_X1_31->Z(outinc[8]);

    BUF_X1_32 = new BUF_X1("BUF_X1_32");
        BUF_X1_32->A(S32[9]);
        BUF_X1_32->Z(outinc[9]);


    SC_METHOD(sc_logic_signal_assignment);

    }

    void sc_logic_signal_assignment(void){ 
        sc_logic_1_signal.write(SC_LOGIC_1);
        sc_logic_0_signal.write(SC_LOGIC_0);
    }
};
#endif /* __INC_16_H__ */

