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
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S35[16];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S36 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S36");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S37[16];

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
        XNOR2_X1_1->A(S36);
        XNOR2_X1_1->B(S35[0]);
        XNOR2_X1_1->ZN(S37[0]);

    INV_X1_1 = new INV_X1("INV_X1_1");
        INV_X1_1->A(S36);
        INV_X1_1->ZN(S0);

    NOR3_X1_1 = new NOR3_X1("NOR3_X1_1");
        NOR3_X1_1->A1(S0);
        NOR3_X1_1->A2(S35[0]);
        NOR3_X1_1->A3(S35[1]);
        NOR3_X1_1->ZN(S1);

    INV_X1_2 = new INV_X1("INV_X1_2");
        INV_X1_2->A(S35[0]);
        INV_X1_2->ZN(S2);

    INV_X1_3 = new INV_X1("INV_X1_3");
        INV_X1_3->A(S35[1]);
        INV_X1_3->ZN(S3);

    AOI21_X1_1 = new AOI21_X1("AOI21_X1_1");
        AOI21_X1_1->A(S3);
        AOI21_X1_1->B1(S2);
        AOI21_X1_1->B2(S36);
        AOI21_X1_1->ZN(S4);

    NOR2_X1_1 = new NOR2_X1("NOR2_X1_1");
        NOR2_X1_1->A1(S4);
        NOR2_X1_1->A2(S1);
        NOR2_X1_1->ZN(S37[1]);

    XNOR2_X1_2 = new XNOR2_X1("XNOR2_X1_2");
        XNOR2_X1_2->A(S1);
        XNOR2_X1_2->B(S35[2]);
        XNOR2_X1_2->ZN(S37[2]);

    INV_X1_4 = new INV_X1("INV_X1_4");
        INV_X1_4->A(S35[3]);
        INV_X1_4->ZN(S5);

    INV_X1_5 = new INV_X1("INV_X1_5");
        INV_X1_5->A(S35[2]);
        INV_X1_5->ZN(S6);

    NAND4_X1_1 = new NAND4_X1("NAND4_X1_1");
        NAND4_X1_1->A1(S6);
        NAND4_X1_1->A2(S3);
        NAND4_X1_1->A3(S2);
        NAND4_X1_1->A4(S36);
        NAND4_X1_1->ZN(S7);

    XNOR2_X1_3 = new XNOR2_X1("XNOR2_X1_3");
        XNOR2_X1_3->A(S7);
        XNOR2_X1_3->B(S5);
        XNOR2_X1_3->ZN(S37[3]);

    INV_X1_6 = new INV_X1("INV_X1_6");
        INV_X1_6->A(S35[4]);
        INV_X1_6->ZN(S8);

    NAND4_X1_2 = new NAND4_X1("NAND4_X1_2");
        NAND4_X1_2->A1(S1);
        NAND4_X1_2->A2(S8);
        NAND4_X1_2->A3(S5);
        NAND4_X1_2->A4(S6);
        NAND4_X1_2->ZN(S9);

    OAI21_X1_1 = new OAI21_X1("OAI21_X1_1");
        OAI21_X1_1->A(S35[4]);
        OAI21_X1_1->B1(S7);
        OAI21_X1_1->B2(S35[3]);
        OAI21_X1_1->ZN(S10);

    AND2_X1_1 = new AND2_X1("AND2_X1_1");
        AND2_X1_1->A1(S10);
        AND2_X1_1->A2(S9);
        AND2_X1_1->ZN(S37[4]);

    XOR2_X1_1 = new XOR2_X1("XOR2_X1_1");
        XOR2_X1_1->A(S9);
        XOR2_X1_1->B(S35[5]);
        XOR2_X1_1->Z(S37[5]);

    NOR4_X1_1 = new NOR4_X1("NOR4_X1_1");
        NOR4_X1_1->A1(S7);
        NOR4_X1_1->A2(S35[5]);
        NOR4_X1_1->A3(S35[4]);
        NOR4_X1_1->A4(S35[3]);
        NOR4_X1_1->ZN(S11);

    XNOR2_X1_4 = new XNOR2_X1("XNOR2_X1_4");
        XNOR2_X1_4->A(S11);
        XNOR2_X1_4->B(S35[6]);
        XNOR2_X1_4->ZN(S37[6]);

    NOR4_X1_2 = new NOR4_X1("NOR4_X1_2");
        NOR4_X1_2->A1(S9);
        NOR4_X1_2->A2(S35[7]);
        NOR4_X1_2->A3(S35[6]);
        NOR4_X1_2->A4(S35[5]);
        NOR4_X1_2->ZN(S12);

    INV_X1_7 = new INV_X1("INV_X1_7");
        INV_X1_7->A(S35[6]);
        INV_X1_7->ZN(S13);

    INV_X1_8 = new INV_X1("INV_X1_8");
        INV_X1_8->A(S35[7]);
        INV_X1_8->ZN(S14);

    AOI21_X1_2 = new AOI21_X1("AOI21_X1_2");
        AOI21_X1_2->A(S14);
        AOI21_X1_2->B1(S11);
        AOI21_X1_2->B2(S13);
        AOI21_X1_2->ZN(S15);

    NOR2_X1_2 = new NOR2_X1("NOR2_X1_2");
        NOR2_X1_2->A1(S15);
        NOR2_X1_2->A2(S12);
        NOR2_X1_2->ZN(S37[7]);

    XNOR2_X1_5 = new XNOR2_X1("XNOR2_X1_5");
        XNOR2_X1_5->A(S12);
        XNOR2_X1_5->B(S35[8]);
        XNOR2_X1_5->ZN(S37[8]);

    INV_X1_9 = new INV_X1("INV_X1_9");
        INV_X1_9->A(S35[9]);
        INV_X1_9->ZN(S16);

    INV_X1_10 = new INV_X1("INV_X1_10");
        INV_X1_10->A(S35[8]);
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
        XNOR2_X1_6->ZN(S37[9]);

    INV_X1_11 = new INV_X1("INV_X1_11");
        INV_X1_11->A(S35[10]);
        INV_X1_11->ZN(S19);

    NAND4_X1_4 = new NAND4_X1("NAND4_X1_4");
        NAND4_X1_4->A1(S12);
        NAND4_X1_4->A2(S19);
        NAND4_X1_4->A3(S16);
        NAND4_X1_4->A4(S17);
        NAND4_X1_4->ZN(S20);

    OAI21_X1_2 = new OAI21_X1("OAI21_X1_2");
        OAI21_X1_2->A(S35[10]);
        OAI21_X1_2->B1(S18);
        OAI21_X1_2->B2(S35[9]);
        OAI21_X1_2->ZN(S21);

    AND2_X1_2 = new AND2_X1("AND2_X1_2");
        AND2_X1_2->A1(S21);
        AND2_X1_2->A2(S20);
        AND2_X1_2->ZN(S37[10]);

    XOR2_X1_2 = new XOR2_X1("XOR2_X1_2");
        XOR2_X1_2->A(S20);
        XOR2_X1_2->B(S35[11]);
        XOR2_X1_2->Z(S37[11]);

    NOR3_X1_2 = new NOR3_X1("NOR3_X1_2");
        NOR3_X1_2->A1(S20);
        NOR3_X1_2->A2(S35[12]);
        NOR3_X1_2->A3(S35[11]);
        NOR3_X1_2->ZN(S22);

    INV_X1_12 = new INV_X1("INV_X1_12");
        INV_X1_12->A(S35[12]);
        INV_X1_12->ZN(S23);

    NOR4_X1_3 = new NOR4_X1("NOR4_X1_3");
        NOR4_X1_3->A1(S18);
        NOR4_X1_3->A2(S35[11]);
        NOR4_X1_3->A3(S35[10]);
        NOR4_X1_3->A4(S35[9]);
        NOR4_X1_3->ZN(S24);

    NOR2_X1_3 = new NOR2_X1("NOR2_X1_3");
        NOR2_X1_3->A1(S24);
        NOR2_X1_3->A2(S23);
        NOR2_X1_3->ZN(S25);

    NOR2_X1_4 = new NOR2_X1("NOR2_X1_4");
        NOR2_X1_4->A1(S25);
        NOR2_X1_4->A2(S22);
        NOR2_X1_4->ZN(S37[12]);

    XNOR2_X1_7 = new XNOR2_X1("XNOR2_X1_7");
        XNOR2_X1_7->A(S22);
        XNOR2_X1_7->B(S35[13]);
        XNOR2_X1_7->ZN(S37[13]);

    INV_X1_13 = new INV_X1("INV_X1_13");
        INV_X1_13->A(S35[13]);
        INV_X1_13->ZN(S26);

    NAND3_X1_1 = new NAND3_X1("NAND3_X1_1");
        NAND3_X1_1->A1(S22);
        NAND3_X1_1->A2(S26);
        NAND3_X1_1->A3(S35[14]);
        NAND3_X1_1->ZN(S27);

    INV_X1_14 = new INV_X1("INV_X1_14");
        INV_X1_14->A(S35[14]);
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
        NAND2_X1_2->ZN(S37[14]);

    NAND4_X1_5 = new NAND4_X1("NAND4_X1_5");
        NAND4_X1_5->A1(S22);
        NAND4_X1_5->A2(S35[15]);
        NAND4_X1_5->A3(S28);
        NAND4_X1_5->A4(S26);
        NAND4_X1_5->ZN(S31);

    INV_X1_15 = new INV_X1("INV_X1_15");
        INV_X1_15->A(S35[15]);
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
        NAND2_X1_4->ZN(S37[15]);

    BUF_X1_1 = new BUF_X1("BUF_X1_1");
        BUF_X1_1->A(incomp[0]);
        BUF_X1_1->Z(S35[0]);

    BUF_X1_2 = new BUF_X1("BUF_X1_2");
        BUF_X1_2->A(incomp[1]);
        BUF_X1_2->Z(S35[1]);

    BUF_X1_3 = new BUF_X1("BUF_X1_3");
        BUF_X1_3->A(incomp[10]);
        BUF_X1_3->Z(S35[10]);

    BUF_X1_4 = new BUF_X1("BUF_X1_4");
        BUF_X1_4->A(incomp[11]);
        BUF_X1_4->Z(S35[11]);

    BUF_X1_5 = new BUF_X1("BUF_X1_5");
        BUF_X1_5->A(incomp[12]);
        BUF_X1_5->Z(S35[12]);

    BUF_X1_6 = new BUF_X1("BUF_X1_6");
        BUF_X1_6->A(incomp[13]);
        BUF_X1_6->Z(S35[13]);

    BUF_X1_7 = new BUF_X1("BUF_X1_7");
        BUF_X1_7->A(incomp[14]);
        BUF_X1_7->Z(S35[14]);

    BUF_X1_8 = new BUF_X1("BUF_X1_8");
        BUF_X1_8->A(incomp[15]);
        BUF_X1_8->Z(S35[15]);

    BUF_X1_9 = new BUF_X1("BUF_X1_9");
        BUF_X1_9->A(incomp[2]);
        BUF_X1_9->Z(S35[2]);

    BUF_X1_10 = new BUF_X1("BUF_X1_10");
        BUF_X1_10->A(incomp[3]);
        BUF_X1_10->Z(S35[3]);

    BUF_X1_11 = new BUF_X1("BUF_X1_11");
        BUF_X1_11->A(incomp[4]);
        BUF_X1_11->Z(S35[4]);

    BUF_X1_12 = new BUF_X1("BUF_X1_12");
        BUF_X1_12->A(incomp[5]);
        BUF_X1_12->Z(S35[5]);

    BUF_X1_13 = new BUF_X1("BUF_X1_13");
        BUF_X1_13->A(incomp[6]);
        BUF_X1_13->Z(S35[6]);

    BUF_X1_14 = new BUF_X1("BUF_X1_14");
        BUF_X1_14->A(incomp[7]);
        BUF_X1_14->Z(S35[7]);

    BUF_X1_15 = new BUF_X1("BUF_X1_15");
        BUF_X1_15->A(incomp[8]);
        BUF_X1_15->Z(S35[8]);

    BUF_X1_16 = new BUF_X1("BUF_X1_16");
        BUF_X1_16->A(incomp[9]);
        BUF_X1_16->Z(S35[9]);

    BUF_X1_17 = new BUF_X1("BUF_X1_17");
        BUF_X1_17->A(onebartwo);
        BUF_X1_17->Z(S36);

    BUF_X1_18 = new BUF_X1("BUF_X1_18");
        BUF_X1_18->A(S37[0]);
        BUF_X1_18->Z(outcomp[0]);

    BUF_X1_19 = new BUF_X1("BUF_X1_19");
        BUF_X1_19->A(S37[1]);
        BUF_X1_19->Z(outcomp[1]);

    BUF_X1_20 = new BUF_X1("BUF_X1_20");
        BUF_X1_20->A(S37[10]);
        BUF_X1_20->Z(outcomp[10]);

    BUF_X1_21 = new BUF_X1("BUF_X1_21");
        BUF_X1_21->A(S37[11]);
        BUF_X1_21->Z(outcomp[11]);

    BUF_X1_22 = new BUF_X1("BUF_X1_22");
        BUF_X1_22->A(S37[12]);
        BUF_X1_22->Z(outcomp[12]);

    BUF_X1_23 = new BUF_X1("BUF_X1_23");
        BUF_X1_23->A(S37[13]);
        BUF_X1_23->Z(outcomp[13]);

    BUF_X1_24 = new BUF_X1("BUF_X1_24");
        BUF_X1_24->A(S37[14]);
        BUF_X1_24->Z(outcomp[14]);

    BUF_X1_25 = new BUF_X1("BUF_X1_25");
        BUF_X1_25->A(S37[15]);
        BUF_X1_25->Z(outcomp[15]);

    BUF_X1_26 = new BUF_X1("BUF_X1_26");
        BUF_X1_26->A(S37[2]);
        BUF_X1_26->Z(outcomp[2]);

    BUF_X1_27 = new BUF_X1("BUF_X1_27");
        BUF_X1_27->A(S37[3]);
        BUF_X1_27->Z(outcomp[3]);

    BUF_X1_28 = new BUF_X1("BUF_X1_28");
        BUF_X1_28->A(S37[4]);
        BUF_X1_28->Z(outcomp[4]);

    BUF_X1_29 = new BUF_X1("BUF_X1_29");
        BUF_X1_29->A(S37[5]);
        BUF_X1_29->Z(outcomp[5]);

    BUF_X1_30 = new BUF_X1("BUF_X1_30");
        BUF_X1_30->A(S37[6]);
        BUF_X1_30->Z(outcomp[6]);

    BUF_X1_31 = new BUF_X1("BUF_X1_31");
        BUF_X1_31->A(S37[7]);
        BUF_X1_31->Z(outcomp[7]);

    BUF_X1_32 = new BUF_X1("BUF_X1_32");
        BUF_X1_32->A(S37[8]);
        BUF_X1_32->Z(outcomp[8]);

    BUF_X1_33 = new BUF_X1("BUF_X1_33");
        BUF_X1_33->A(S37[9]);
        BUF_X1_33->Z(outcomp[9]);


    SC_METHOD(sc_logic_signal_assignment);

    }

    void sc_logic_signal_assignment(void){ 
        sc_logic_1_signal.write(SC_LOGIC_1);
        sc_logic_0_signal.write(SC_LOGIC_0);
    }
};
#endif /* __COMP_H__ */

