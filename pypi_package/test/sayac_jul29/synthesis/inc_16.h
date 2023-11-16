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
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S31 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S31");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S32 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S32");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S33 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S33");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S34 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S34");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S35 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S35");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S36 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S36");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S37 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S37");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S38 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S38");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S39 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S39");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S40 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S40");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S41 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S41");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S42 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S42");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S43 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S43");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S44 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S44");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S45 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S45");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S46 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S46");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S47 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S47");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S48 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S48");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S49 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S49");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S50 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S50");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S51 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S51");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S52 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S52");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S53 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S53");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S54 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S54");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S55 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S55");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S56 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S56");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S57 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S57");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S58 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S58");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S59 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S59");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S60 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S60");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S61 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S61");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> carry_0_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("carry_0_");

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
        INV_X1_1->A(carry_0_);
        INV_X1_1->ZN(S46);

    XOR2_X1_1 = new XOR2_X1("XOR2_X1_1");
        XOR2_X1_1->A(carry_0_);
        XOR2_X1_1->B(S37);
        XOR2_X1_1->Z(S53);

    NAND2_X1_1 = new NAND2_X1("NAND2_X1_1");
        NAND2_X1_1->A1(carry_0_);
        NAND2_X1_1->A2(S37);
        NAND2_X1_1->ZN(S0);

    XNOR2_X1_1 = new XNOR2_X1("XNOR2_X1_1");
        XNOR2_X1_1->A(S0);
        XNOR2_X1_1->B(S38);
        XNOR2_X1_1->ZN(S54);

    NAND3_X1_1 = new NAND3_X1("NAND3_X1_1");
        NAND3_X1_1->A1(carry_0_);
        NAND3_X1_1->A2(S37);
        NAND3_X1_1->A3(S38);
        NAND3_X1_1->ZN(S1);

    XNOR2_X1_2 = new XNOR2_X1("XNOR2_X1_2");
        XNOR2_X1_2->A(S1);
        XNOR2_X1_2->B(S39);
        XNOR2_X1_2->ZN(S55);

    NAND4_X1_1 = new NAND4_X1("NAND4_X1_1");
        NAND4_X1_1->A1(S38);
        NAND4_X1_1->A2(S39);
        NAND4_X1_1->A3(carry_0_);
        NAND4_X1_1->A4(S37);
        NAND4_X1_1->ZN(S2);

    XNOR2_X1_3 = new XNOR2_X1("XNOR2_X1_3");
        XNOR2_X1_3->A(S2);
        XNOR2_X1_3->B(S40);
        XNOR2_X1_3->ZN(S56);

    INV_X1_2 = new INV_X1("INV_X1_2");
        INV_X1_2->A(S41);
        INV_X1_2->ZN(S3);

    INV_X1_3 = new INV_X1("INV_X1_3");
        INV_X1_3->A(S40);
        INV_X1_3->ZN(S4);

    NOR2_X1_1 = new NOR2_X1("NOR2_X1_1");
        NOR2_X1_1->A1(S2);
        NOR2_X1_1->A2(S4);
        NOR2_X1_1->ZN(S5);

    XNOR2_X1_4 = new XNOR2_X1("XNOR2_X1_4");
        XNOR2_X1_4->A(S5);
        XNOR2_X1_4->B(S3);
        XNOR2_X1_4->ZN(S57);

    INV_X1_4 = new INV_X1("INV_X1_4");
        INV_X1_4->A(S42);
        INV_X1_4->ZN(S6);

    NOR4_X1_1 = new NOR4_X1("NOR4_X1_1");
        NOR4_X1_1->A1(S2);
        NOR4_X1_1->A2(S6);
        NOR4_X1_1->A3(S3);
        NOR4_X1_1->A4(S4);
        NOR4_X1_1->ZN(S7);

    AOI21_X1_1 = new AOI21_X1("AOI21_X1_1");
        AOI21_X1_1->A(S42);
        AOI21_X1_1->B1(S5);
        AOI21_X1_1->B2(S41);
        AOI21_X1_1->ZN(S8);

    NOR2_X1_2 = new NOR2_X1("NOR2_X1_2");
        NOR2_X1_2->A1(S8);
        NOR2_X1_2->A2(S7);
        NOR2_X1_2->ZN(S58);

    XOR2_X1_2 = new XOR2_X1("XOR2_X1_2");
        XOR2_X1_2->A(S7);
        XOR2_X1_2->B(S43);
        XOR2_X1_2->Z(S59);

    NAND2_X1_2 = new NAND2_X1("NAND2_X1_2");
        NAND2_X1_2->A1(S7);
        NAND2_X1_2->A2(S43);
        NAND2_X1_2->ZN(S9);

    XNOR2_X1_5 = new XNOR2_X1("XNOR2_X1_5");
        XNOR2_X1_5->A(S9);
        XNOR2_X1_5->B(S44);
        XNOR2_X1_5->ZN(S60);

    NAND4_X1_2 = new NAND4_X1("NAND4_X1_2");
        NAND4_X1_2->A1(S7);
        NAND4_X1_2->A2(S45);
        NAND4_X1_2->A3(S44);
        NAND4_X1_2->A4(S43);
        NAND4_X1_2->ZN(S10);

    INV_X1_5 = new INV_X1("INV_X1_5");
        INV_X1_5->A(S44);
        INV_X1_5->ZN(S11);

    INV_X1_6 = new INV_X1("INV_X1_6");
        INV_X1_6->A(S45);
        INV_X1_6->ZN(S12);

    OAI21_X1_1 = new OAI21_X1("OAI21_X1_1");
        OAI21_X1_1->A(S12);
        OAI21_X1_1->B1(S9);
        OAI21_X1_1->B2(S11);
        OAI21_X1_1->ZN(S13);

    AND2_X1_1 = new AND2_X1("AND2_X1_1");
        AND2_X1_1->A1(S13);
        AND2_X1_1->A2(S10);
        AND2_X1_1->ZN(S61);

    XNOR2_X1_6 = new XNOR2_X1("XNOR2_X1_6");
        XNOR2_X1_6->A(S10);
        XNOR2_X1_6->B(S31);
        XNOR2_X1_6->ZN(S47);

    INV_X1_7 = new INV_X1("INV_X1_7");
        INV_X1_7->A(S31);
        INV_X1_7->ZN(S14);

    INV_X1_8 = new INV_X1("INV_X1_8");
        INV_X1_8->A(S32);
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
        NOR2_X1_4->A2(S32);
        NOR2_X1_4->ZN(S18);

    NOR2_X1_5 = new NOR2_X1("NOR2_X1_5");
        NOR2_X1_5->A1(S18);
        NOR2_X1_5->A2(S16);
        NOR2_X1_5->ZN(S48);

    INV_X1_9 = new INV_X1("INV_X1_9");
        INV_X1_9->A(S33);
        INV_X1_9->ZN(S19);

    NOR4_X1_2 = new NOR4_X1("NOR4_X1_2");
        NOR4_X1_2->A1(S10);
        NOR4_X1_2->A2(S19);
        NOR4_X1_2->A3(S15);
        NOR4_X1_2->A4(S14);
        NOR4_X1_2->ZN(S20);

    NOR2_X1_6 = new NOR2_X1("NOR2_X1_6");
        NOR2_X1_6->A1(S16);
        NOR2_X1_6->A2(S33);
        NOR2_X1_6->ZN(S21);

    NOR2_X1_7 = new NOR2_X1("NOR2_X1_7");
        NOR2_X1_7->A1(S21);
        NOR2_X1_7->A2(S20);
        NOR2_X1_7->ZN(S49);

    INV_X1_10 = new INV_X1("INV_X1_10");
        INV_X1_10->A(S34);
        INV_X1_10->ZN(S22);

    XNOR2_X1_7 = new XNOR2_X1("XNOR2_X1_7");
        XNOR2_X1_7->A(S20);
        XNOR2_X1_7->B(S22);
        XNOR2_X1_7->ZN(S50);

    NAND2_X1_3 = new NAND2_X1("NAND2_X1_3");
        NAND2_X1_3->A1(S20);
        NAND2_X1_3->A2(S34);
        NAND2_X1_3->ZN(S23);

    NAND2_X1_4 = new NAND2_X1("NAND2_X1_4");
        NAND2_X1_4->A1(S23);
        NAND2_X1_4->A2(S35);
        NAND2_X1_4->ZN(S24);

    INV_X1_11 = new INV_X1("INV_X1_11");
        INV_X1_11->A(S35);
        INV_X1_11->ZN(S25);

    NAND3_X1_2 = new NAND3_X1("NAND3_X1_2");
        NAND3_X1_2->A1(S20);
        NAND3_X1_2->A2(S34);
        NAND3_X1_2->A3(S25);
        NAND3_X1_2->ZN(S26);

    NAND2_X1_5 = new NAND2_X1("NAND2_X1_5");
        NAND2_X1_5->A1(S24);
        NAND2_X1_5->A2(S26);
        NAND2_X1_5->ZN(S51);

    NAND4_X1_3 = new NAND4_X1("NAND4_X1_3");
        NAND4_X1_3->A1(S16);
        NAND4_X1_3->A2(S35);
        NAND4_X1_3->A3(S34);
        NAND4_X1_3->A4(S33);
        NAND4_X1_3->ZN(S27);

    NAND2_X1_6 = new NAND2_X1("NAND2_X1_6");
        NAND2_X1_6->A1(S27);
        NAND2_X1_6->A2(S36);
        NAND2_X1_6->ZN(S28);

    INV_X1_12 = new INV_X1("INV_X1_12");
        INV_X1_12->A(S36);
        INV_X1_12->ZN(S29);

    NAND4_X1_4 = new NAND4_X1("NAND4_X1_4");
        NAND4_X1_4->A1(S20);
        NAND4_X1_4->A2(S29);
        NAND4_X1_4->A3(S35);
        NAND4_X1_4->A4(S34);
        NAND4_X1_4->ZN(S30);

    NAND2_X1_7 = new NAND2_X1("NAND2_X1_7");
        NAND2_X1_7->A1(S28);
        NAND2_X1_7->A2(S30);
        NAND2_X1_7->ZN(S52);

    BUF_X1_1 = new BUF_X1("BUF_X1_1");
        BUF_X1_1->A(ininc[0]);
        BUF_X1_1->Z(carry_0_);

    BUF_X1_2 = new BUF_X1("BUF_X1_2");
        BUF_X1_2->A(ininc[1]);
        BUF_X1_2->Z(S37);

    BUF_X1_3 = new BUF_X1("BUF_X1_3");
        BUF_X1_3->A(ininc[10]);
        BUF_X1_3->Z(S31);

    BUF_X1_4 = new BUF_X1("BUF_X1_4");
        BUF_X1_4->A(ininc[11]);
        BUF_X1_4->Z(S32);

    BUF_X1_5 = new BUF_X1("BUF_X1_5");
        BUF_X1_5->A(ininc[12]);
        BUF_X1_5->Z(S33);

    BUF_X1_6 = new BUF_X1("BUF_X1_6");
        BUF_X1_6->A(ininc[13]);
        BUF_X1_6->Z(S34);

    BUF_X1_7 = new BUF_X1("BUF_X1_7");
        BUF_X1_7->A(ininc[14]);
        BUF_X1_7->Z(S35);

    BUF_X1_8 = new BUF_X1("BUF_X1_8");
        BUF_X1_8->A(ininc[15]);
        BUF_X1_8->Z(S36);

    BUF_X1_9 = new BUF_X1("BUF_X1_9");
        BUF_X1_9->A(ininc[2]);
        BUF_X1_9->Z(S38);

    BUF_X1_10 = new BUF_X1("BUF_X1_10");
        BUF_X1_10->A(ininc[3]);
        BUF_X1_10->Z(S39);

    BUF_X1_11 = new BUF_X1("BUF_X1_11");
        BUF_X1_11->A(ininc[4]);
        BUF_X1_11->Z(S40);

    BUF_X1_12 = new BUF_X1("BUF_X1_12");
        BUF_X1_12->A(ininc[5]);
        BUF_X1_12->Z(S41);

    BUF_X1_13 = new BUF_X1("BUF_X1_13");
        BUF_X1_13->A(ininc[6]);
        BUF_X1_13->Z(S42);

    BUF_X1_14 = new BUF_X1("BUF_X1_14");
        BUF_X1_14->A(ininc[7]);
        BUF_X1_14->Z(S43);

    BUF_X1_15 = new BUF_X1("BUF_X1_15");
        BUF_X1_15->A(ininc[8]);
        BUF_X1_15->Z(S44);

    BUF_X1_16 = new BUF_X1("BUF_X1_16");
        BUF_X1_16->A(ininc[9]);
        BUF_X1_16->Z(S45);

    BUF_X1_17 = new BUF_X1("BUF_X1_17");
        BUF_X1_17->A(S46);
        BUF_X1_17->Z(outinc[0]);

    BUF_X1_18 = new BUF_X1("BUF_X1_18");
        BUF_X1_18->A(S53);
        BUF_X1_18->Z(outinc[1]);

    BUF_X1_19 = new BUF_X1("BUF_X1_19");
        BUF_X1_19->A(S47);
        BUF_X1_19->Z(outinc[10]);

    BUF_X1_20 = new BUF_X1("BUF_X1_20");
        BUF_X1_20->A(S48);
        BUF_X1_20->Z(outinc[11]);

    BUF_X1_21 = new BUF_X1("BUF_X1_21");
        BUF_X1_21->A(S49);
        BUF_X1_21->Z(outinc[12]);

    BUF_X1_22 = new BUF_X1("BUF_X1_22");
        BUF_X1_22->A(S50);
        BUF_X1_22->Z(outinc[13]);

    BUF_X1_23 = new BUF_X1("BUF_X1_23");
        BUF_X1_23->A(S51);
        BUF_X1_23->Z(outinc[14]);

    BUF_X1_24 = new BUF_X1("BUF_X1_24");
        BUF_X1_24->A(S52);
        BUF_X1_24->Z(outinc[15]);

    BUF_X1_25 = new BUF_X1("BUF_X1_25");
        BUF_X1_25->A(S54);
        BUF_X1_25->Z(outinc[2]);

    BUF_X1_26 = new BUF_X1("BUF_X1_26");
        BUF_X1_26->A(S55);
        BUF_X1_26->Z(outinc[3]);

    BUF_X1_27 = new BUF_X1("BUF_X1_27");
        BUF_X1_27->A(S56);
        BUF_X1_27->Z(outinc[4]);

    BUF_X1_28 = new BUF_X1("BUF_X1_28");
        BUF_X1_28->A(S57);
        BUF_X1_28->Z(outinc[5]);

    BUF_X1_29 = new BUF_X1("BUF_X1_29");
        BUF_X1_29->A(S58);
        BUF_X1_29->Z(outinc[6]);

    BUF_X1_30 = new BUF_X1("BUF_X1_30");
        BUF_X1_30->A(S59);
        BUF_X1_30->Z(outinc[7]);

    BUF_X1_31 = new BUF_X1("BUF_X1_31");
        BUF_X1_31->A(S60);
        BUF_X1_31->Z(outinc[8]);

    BUF_X1_32 = new BUF_X1("BUF_X1_32");
        BUF_X1_32->A(S61);
        BUF_X1_32->Z(outinc[9]);


    SC_METHOD(sc_logic_signal_assignment);

    }

    void sc_logic_signal_assignment(void){ 
        sc_logic_1_signal.write(SC_LOGIC_1);
        sc_logic_0_signal.write(SC_LOGIC_0);
    }
};
#endif /* __INC_16_H__ */

