#include <systemc.h>
#include "Complex_NAgate_45.h"



#ifndef __COMP_H__
#define __COMP_H__
using namespace sc_core;

SC_MODULE( comp ) {

    sc_in<sc_logic> incomp[16];
    sc_in<sc_logic> onebartwo;
    sc_out<sc_logic> outcomp[16];

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
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S62 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S62");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S63 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S63");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S64 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S64");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S65 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S65");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S66 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S66");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S67 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S67");

    XNOR2_X1* XNOR2_X1_1;
    INV_X1* INV_X1_1;
    NOR3_X1* NOR3_X1_1;
    INV_X1* INV_X1_2;
    INV_X1* INV_X1_3;
    AOI21_X1* AOI21_X1_1;
    NOR2_X1* NOR2_X1_1;
    XNOR2_X1* XNOR2_X1_2;
    INV_X1* INV_X1_4;
    INV_X1* INV_X1_5;
    NAND4_X1* NAND4_X1_1;
    XNOR2_X1* XNOR2_X1_3;
    INV_X1* INV_X1_6;
    NAND4_X1* NAND4_X1_2;
    OAI21_X1* OAI21_X1_1;
    AND2_X1* AND2_X1_1;
    XOR2_X1* XOR2_X1_1;
    NOR4_X1* NOR4_X1_1;
    XNOR2_X1* XNOR2_X1_4;
    NOR4_X1* NOR4_X1_2;
    INV_X1* INV_X1_7;
    INV_X1* INV_X1_8;
    AOI21_X1* AOI21_X1_2;
    NOR2_X1* NOR2_X1_2;
    XNOR2_X1* XNOR2_X1_5;
    INV_X1* INV_X1_9;
    INV_X1* INV_X1_10;
    NAND4_X1* NAND4_X1_3;
    XNOR2_X1* XNOR2_X1_6;
    INV_X1* INV_X1_11;
    NAND4_X1* NAND4_X1_4;
    OAI21_X1* OAI21_X1_2;
    AND2_X1* AND2_X1_2;
    XOR2_X1* XOR2_X1_2;
    NOR3_X1* NOR3_X1_2;
    INV_X1* INV_X1_12;
    NOR4_X1* NOR4_X1_3;
    NOR2_X1* NOR2_X1_3;
    NOR2_X1* NOR2_X1_4;
    XNOR2_X1* XNOR2_X1_7;
    INV_X1* INV_X1_13;
    NAND3_X1* NAND3_X1_1;
    INV_X1* INV_X1_14;
    NAND3_X1* NAND3_X1_2;
    NAND2_X1* NAND2_X1_1;
    NAND2_X1* NAND2_X1_2;
    NAND4_X1* NAND4_X1_5;
    INV_X1* INV_X1_15;
    NAND4_X1* NAND4_X1_6;
    NAND2_X1* NAND2_X1_3;
    NAND2_X1* NAND2_X1_4;
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
    BUF_X1* BUF_X1_33;

SC_CTOR( comp ) {
    XNOR2_X1_1 = new XNOR2_X1("XNOR2_X1_1");
        XNOR2_X1_1->A(S51);
        XNOR2_X1_1->B(S35);
        XNOR2_X1_1->ZN(S52);

    INV_X1_1 = new INV_X1("INV_X1_1");
        INV_X1_1->A(S51);
        INV_X1_1->ZN(S0);

    NOR3_X1_1 = new NOR3_X1("NOR3_X1_1");
        NOR3_X1_1->A1(S0);
        NOR3_X1_1->A2(S35);
        NOR3_X1_1->A3(S42);
        NOR3_X1_1->ZN(S1);

    INV_X1_2 = new INV_X1("INV_X1_2");
        INV_X1_2->A(S35);
        INV_X1_2->ZN(S2);

    INV_X1_3 = new INV_X1("INV_X1_3");
        INV_X1_3->A(S42);
        INV_X1_3->ZN(S3);

    AOI21_X1_1 = new AOI21_X1("AOI21_X1_1");
        AOI21_X1_1->A(S3);
        AOI21_X1_1->B1(S2);
        AOI21_X1_1->B2(S51);
        AOI21_X1_1->ZN(S4);

    NOR2_X1_1 = new NOR2_X1("NOR2_X1_1");
        NOR2_X1_1->A1(S4);
        NOR2_X1_1->A2(S1);
        NOR2_X1_1->ZN(S59);

    XNOR2_X1_2 = new XNOR2_X1("XNOR2_X1_2");
        XNOR2_X1_2->A(S1);
        XNOR2_X1_2->B(S43);
        XNOR2_X1_2->ZN(S60);

    INV_X1_4 = new INV_X1("INV_X1_4");
        INV_X1_4->A(S44);
        INV_X1_4->ZN(S5);

    INV_X1_5 = new INV_X1("INV_X1_5");
        INV_X1_5->A(S43);
        INV_X1_5->ZN(S6);

    NAND4_X1_1 = new NAND4_X1("NAND4_X1_1");
        NAND4_X1_1->A1(S6);
        NAND4_X1_1->A2(S3);
        NAND4_X1_1->A3(S2);
        NAND4_X1_1->A4(S51);
        NAND4_X1_1->ZN(S7);

    XNOR2_X1_3 = new XNOR2_X1("XNOR2_X1_3");
        XNOR2_X1_3->A(S7);
        XNOR2_X1_3->B(S5);
        XNOR2_X1_3->ZN(S61);

    INV_X1_6 = new INV_X1("INV_X1_6");
        INV_X1_6->A(S45);
        INV_X1_6->ZN(S8);

    NAND4_X1_2 = new NAND4_X1("NAND4_X1_2");
        NAND4_X1_2->A1(S1);
        NAND4_X1_2->A2(S8);
        NAND4_X1_2->A3(S5);
        NAND4_X1_2->A4(S6);
        NAND4_X1_2->ZN(S9);

    OAI21_X1_1 = new OAI21_X1("OAI21_X1_1");
        OAI21_X1_1->A(S45);
        OAI21_X1_1->B1(S7);
        OAI21_X1_1->B2(S44);
        OAI21_X1_1->ZN(S10);

    AND2_X1_1 = new AND2_X1("AND2_X1_1");
        AND2_X1_1->A1(S10);
        AND2_X1_1->A2(S9);
        AND2_X1_1->ZN(S62);

    XOR2_X1_1 = new XOR2_X1("XOR2_X1_1");
        XOR2_X1_1->A(S9);
        XOR2_X1_1->B(S46);
        XOR2_X1_1->Z(S63);

    NOR4_X1_1 = new NOR4_X1("NOR4_X1_1");
        NOR4_X1_1->A1(S7);
        NOR4_X1_1->A2(S46);
        NOR4_X1_1->A3(S45);
        NOR4_X1_1->A4(S44);
        NOR4_X1_1->ZN(S11);

    XNOR2_X1_4 = new XNOR2_X1("XNOR2_X1_4");
        XNOR2_X1_4->A(S11);
        XNOR2_X1_4->B(S47);
        XNOR2_X1_4->ZN(S64);

    NOR4_X1_2 = new NOR4_X1("NOR4_X1_2");
        NOR4_X1_2->A1(S9);
        NOR4_X1_2->A2(S48);
        NOR4_X1_2->A3(S47);
        NOR4_X1_2->A4(S46);
        NOR4_X1_2->ZN(S12);

    INV_X1_7 = new INV_X1("INV_X1_7");
        INV_X1_7->A(S47);
        INV_X1_7->ZN(S13);

    INV_X1_8 = new INV_X1("INV_X1_8");
        INV_X1_8->A(S48);
        INV_X1_8->ZN(S14);

    AOI21_X1_2 = new AOI21_X1("AOI21_X1_2");
        AOI21_X1_2->A(S14);
        AOI21_X1_2->B1(S11);
        AOI21_X1_2->B2(S13);
        AOI21_X1_2->ZN(S15);

    NOR2_X1_2 = new NOR2_X1("NOR2_X1_2");
        NOR2_X1_2->A1(S15);
        NOR2_X1_2->A2(S12);
        NOR2_X1_2->ZN(S65);

    XNOR2_X1_5 = new XNOR2_X1("XNOR2_X1_5");
        XNOR2_X1_5->A(S12);
        XNOR2_X1_5->B(S49);
        XNOR2_X1_5->ZN(S66);

    INV_X1_9 = new INV_X1("INV_X1_9");
        INV_X1_9->A(S50);
        INV_X1_9->ZN(S16);

    INV_X1_10 = new INV_X1("INV_X1_10");
        INV_X1_10->A(S49);
        INV_X1_10->ZN(S17);

    NAND4_X1_3 = new NAND4_X1("NAND4_X1_3");
        NAND4_X1_3->A1(S11);
        NAND4_X1_3->A2(S17);
        NAND4_X1_3->A3(S14);
        NAND4_X1_3->A4(S13);
        NAND4_X1_3->ZN(S18);

    XNOR2_X1_6 = new XNOR2_X1("XNOR2_X1_6");
        XNOR2_X1_6->A(S18);
        XNOR2_X1_6->B(S16);
        XNOR2_X1_6->ZN(S67);

    INV_X1_11 = new INV_X1("INV_X1_11");
        INV_X1_11->A(S36);
        INV_X1_11->ZN(S19);

    NAND4_X1_4 = new NAND4_X1("NAND4_X1_4");
        NAND4_X1_4->A1(S12);
        NAND4_X1_4->A2(S19);
        NAND4_X1_4->A3(S16);
        NAND4_X1_4->A4(S17);
        NAND4_X1_4->ZN(S20);

    OAI21_X1_2 = new OAI21_X1("OAI21_X1_2");
        OAI21_X1_2->A(S36);
        OAI21_X1_2->B1(S18);
        OAI21_X1_2->B2(S50);
        OAI21_X1_2->ZN(S21);

    AND2_X1_2 = new AND2_X1("AND2_X1_2");
        AND2_X1_2->A1(S21);
        AND2_X1_2->A2(S20);
        AND2_X1_2->ZN(S53);

    XOR2_X1_2 = new XOR2_X1("XOR2_X1_2");
        XOR2_X1_2->A(S20);
        XOR2_X1_2->B(S37);
        XOR2_X1_2->Z(S54);

    NOR3_X1_2 = new NOR3_X1("NOR3_X1_2");
        NOR3_X1_2->A1(S20);
        NOR3_X1_2->A2(S38);
        NOR3_X1_2->A3(S37);
        NOR3_X1_2->ZN(S22);

    INV_X1_12 = new INV_X1("INV_X1_12");
        INV_X1_12->A(S38);
        INV_X1_12->ZN(S23);

    NOR4_X1_3 = new NOR4_X1("NOR4_X1_3");
        NOR4_X1_3->A1(S18);
        NOR4_X1_3->A2(S37);
        NOR4_X1_3->A3(S36);
        NOR4_X1_3->A4(S50);
        NOR4_X1_3->ZN(S24);

    NOR2_X1_3 = new NOR2_X1("NOR2_X1_3");
        NOR2_X1_3->A1(S24);
        NOR2_X1_3->A2(S23);
        NOR2_X1_3->ZN(S25);

    NOR2_X1_4 = new NOR2_X1("NOR2_X1_4");
        NOR2_X1_4->A1(S25);
        NOR2_X1_4->A2(S22);
        NOR2_X1_4->ZN(S55);

    XNOR2_X1_7 = new XNOR2_X1("XNOR2_X1_7");
        XNOR2_X1_7->A(S22);
        XNOR2_X1_7->B(S39);
        XNOR2_X1_7->ZN(S56);

    INV_X1_13 = new INV_X1("INV_X1_13");
        INV_X1_13->A(S39);
        INV_X1_13->ZN(S26);

    NAND3_X1_1 = new NAND3_X1("NAND3_X1_1");
        NAND3_X1_1->A1(S22);
        NAND3_X1_1->A2(S26);
        NAND3_X1_1->A3(S40);
        NAND3_X1_1->ZN(S27);

    INV_X1_14 = new INV_X1("INV_X1_14");
        INV_X1_14->A(S40);
        INV_X1_14->ZN(S28);

    NAND3_X1_2 = new NAND3_X1("NAND3_X1_2");
        NAND3_X1_2->A1(S24);
        NAND3_X1_2->A2(S23);
        NAND3_X1_2->A3(S26);
        NAND3_X1_2->ZN(S29);

    NAND2_X1_1 = new NAND2_X1("NAND2_X1_1");
        NAND2_X1_1->A1(S29);
        NAND2_X1_1->A2(S28);
        NAND2_X1_1->ZN(S30);

    NAND2_X1_2 = new NAND2_X1("NAND2_X1_2");
        NAND2_X1_2->A1(S30);
        NAND2_X1_2->A2(S27);
        NAND2_X1_2->ZN(S57);

    NAND4_X1_5 = new NAND4_X1("NAND4_X1_5");
        NAND4_X1_5->A1(S22);
        NAND4_X1_5->A2(S41);
        NAND4_X1_5->A3(S28);
        NAND4_X1_5->A4(S26);
        NAND4_X1_5->ZN(S31);

    INV_X1_15 = new INV_X1("INV_X1_15");
        INV_X1_15->A(S41);
        INV_X1_15->ZN(S32);

    NAND4_X1_6 = new NAND4_X1("NAND4_X1_6");
        NAND4_X1_6->A1(S24);
        NAND4_X1_6->A2(S28);
        NAND4_X1_6->A3(S26);
        NAND4_X1_6->A4(S23);
        NAND4_X1_6->ZN(S33);

    NAND2_X1_3 = new NAND2_X1("NAND2_X1_3");
        NAND2_X1_3->A1(S33);
        NAND2_X1_3->A2(S32);
        NAND2_X1_3->ZN(S34);

    NAND2_X1_4 = new NAND2_X1("NAND2_X1_4");
        NAND2_X1_4->A1(S34);
        NAND2_X1_4->A2(S31);
        NAND2_X1_4->ZN(S58);

    BUF_X1_1 = new BUF_X1("BUF_X1_1");
        BUF_X1_1->A(incomp[0]);
        BUF_X1_1->Z(S35);

    BUF_X1_2 = new BUF_X1("BUF_X1_2");
        BUF_X1_2->A(incomp[1]);
        BUF_X1_2->Z(S42);

    BUF_X1_3 = new BUF_X1("BUF_X1_3");
        BUF_X1_3->A(incomp[10]);
        BUF_X1_3->Z(S36);

    BUF_X1_4 = new BUF_X1("BUF_X1_4");
        BUF_X1_4->A(incomp[11]);
        BUF_X1_4->Z(S37);

    BUF_X1_5 = new BUF_X1("BUF_X1_5");
        BUF_X1_5->A(incomp[12]);
        BUF_X1_5->Z(S38);

    BUF_X1_6 = new BUF_X1("BUF_X1_6");
        BUF_X1_6->A(incomp[13]);
        BUF_X1_6->Z(S39);

    BUF_X1_7 = new BUF_X1("BUF_X1_7");
        BUF_X1_7->A(incomp[14]);
        BUF_X1_7->Z(S40);

    BUF_X1_8 = new BUF_X1("BUF_X1_8");
        BUF_X1_8->A(incomp[15]);
        BUF_X1_8->Z(S41);

    BUF_X1_9 = new BUF_X1("BUF_X1_9");
        BUF_X1_9->A(incomp[2]);
        BUF_X1_9->Z(S43);

    BUF_X1_10 = new BUF_X1("BUF_X1_10");
        BUF_X1_10->A(incomp[3]);
        BUF_X1_10->Z(S44);

    BUF_X1_11 = new BUF_X1("BUF_X1_11");
        BUF_X1_11->A(incomp[4]);
        BUF_X1_11->Z(S45);

    BUF_X1_12 = new BUF_X1("BUF_X1_12");
        BUF_X1_12->A(incomp[5]);
        BUF_X1_12->Z(S46);

    BUF_X1_13 = new BUF_X1("BUF_X1_13");
        BUF_X1_13->A(incomp[6]);
        BUF_X1_13->Z(S47);

    BUF_X1_14 = new BUF_X1("BUF_X1_14");
        BUF_X1_14->A(incomp[7]);
        BUF_X1_14->Z(S48);

    BUF_X1_15 = new BUF_X1("BUF_X1_15");
        BUF_X1_15->A(incomp[8]);
        BUF_X1_15->Z(S49);

    BUF_X1_16 = new BUF_X1("BUF_X1_16");
        BUF_X1_16->A(incomp[9]);
        BUF_X1_16->Z(S50);

    BUF_X1_17 = new BUF_X1("BUF_X1_17");
        BUF_X1_17->A(onebartwo);
        BUF_X1_17->Z(S51);

    BUF_X1_18 = new BUF_X1("BUF_X1_18");
        BUF_X1_18->A(S52);
        BUF_X1_18->Z(outcomp[0]);

    BUF_X1_19 = new BUF_X1("BUF_X1_19");
        BUF_X1_19->A(S59);
        BUF_X1_19->Z(outcomp[1]);

    BUF_X1_20 = new BUF_X1("BUF_X1_20");
        BUF_X1_20->A(S53);
        BUF_X1_20->Z(outcomp[10]);

    BUF_X1_21 = new BUF_X1("BUF_X1_21");
        BUF_X1_21->A(S54);
        BUF_X1_21->Z(outcomp[11]);

    BUF_X1_22 = new BUF_X1("BUF_X1_22");
        BUF_X1_22->A(S55);
        BUF_X1_22->Z(outcomp[12]);

    BUF_X1_23 = new BUF_X1("BUF_X1_23");
        BUF_X1_23->A(S56);
        BUF_X1_23->Z(outcomp[13]);

    BUF_X1_24 = new BUF_X1("BUF_X1_24");
        BUF_X1_24->A(S57);
        BUF_X1_24->Z(outcomp[14]);

    BUF_X1_25 = new BUF_X1("BUF_X1_25");
        BUF_X1_25->A(S58);
        BUF_X1_25->Z(outcomp[15]);

    BUF_X1_26 = new BUF_X1("BUF_X1_26");
        BUF_X1_26->A(S60);
        BUF_X1_26->Z(outcomp[2]);

    BUF_X1_27 = new BUF_X1("BUF_X1_27");
        BUF_X1_27->A(S61);
        BUF_X1_27->Z(outcomp[3]);

    BUF_X1_28 = new BUF_X1("BUF_X1_28");
        BUF_X1_28->A(S62);
        BUF_X1_28->Z(outcomp[4]);

    BUF_X1_29 = new BUF_X1("BUF_X1_29");
        BUF_X1_29->A(S63);
        BUF_X1_29->Z(outcomp[5]);

    BUF_X1_30 = new BUF_X1("BUF_X1_30");
        BUF_X1_30->A(S64);
        BUF_X1_30->Z(outcomp[6]);

    BUF_X1_31 = new BUF_X1("BUF_X1_31");
        BUF_X1_31->A(S65);
        BUF_X1_31->Z(outcomp[7]);

    BUF_X1_32 = new BUF_X1("BUF_X1_32");
        BUF_X1_32->A(S66);
        BUF_X1_32->Z(outcomp[8]);

    BUF_X1_33 = new BUF_X1("BUF_X1_33");
        BUF_X1_33->A(S67);
        BUF_X1_33->Z(outcomp[9]);


    SC_METHOD(sc_logic_signal_assignment);

    }

    void sc_logic_signal_assignment(void){ 
        sc_logic_1_signal.write(SC_LOGIC_1);
        sc_logic_0_signal.write(SC_LOGIC_0);
    }
};
#endif /* __COMP_H__ */

