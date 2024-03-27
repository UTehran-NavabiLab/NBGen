#include <systemc.h>
#include "Complex_NAgate_45.h"



#ifndef __IMM_H__
#define __IMM_H__
using namespace sc_core;

SC_MODULE( imm ) {

    sc_in<sc_logic> in1[8];
    sc_in<sc_logic> in2[8];
    sc_in<sc_logic> se5bits;
    sc_in<sc_logic> se6bits;
    sc_in<sc_logic> use8bits;
    sc_in<sc_logic> se8bits;
    sc_in<sc_logic> p1lowbits;
    sc_out<sc_logic> outimm[16];

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
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S58[8];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S59[8];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S60[16];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S61 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S61");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S62 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S62");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S63 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S63");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S64 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S64");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S65 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S65");

    NAND2_X1* NAND2_X1_1;
    INV_X1* INV_X1_1;
    INV_X1* INV_X1_2;
    NOR2_X1* NOR2_X1_1;
    NAND3_X1* NAND3_X1_1;
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
    NAND2_X1* NAND2_X1_11;
    AOI21_X1* AOI21_X1_1;
    NAND2_X1* NAND2_X1_12;
    AND2_X1* AND2_X1_1;
    OAI21_X1* OAI21_X1_6;
    OAI21_X1* OAI21_X1_7;
    NAND2_X1* NAND2_X1_13;
    INV_X1* INV_X1_3;
    INV_X1* INV_X1_4;
    OAI21_X1* OAI21_X1_8;
    NAND2_X1* NAND2_X1_14;
    AOI21_X1* AOI21_X1_2;
    AOI21_X1* AOI21_X1_3;
    OAI21_X1* OAI21_X1_9;
    INV_X1* INV_X1_5;
    OAI21_X1* OAI21_X1_10;
    NAND2_X1* NAND2_X1_15;
    AOI21_X1* AOI21_X1_4;
    AOI21_X1* AOI21_X1_5;
    OAI21_X1* OAI21_X1_11;
    AOI21_X1* AOI21_X1_6;
    INV_X1* INV_X1_6;
    INV_X1* INV_X1_7;
    OAI211_X1* OAI211_X1_1;
    OAI21_X1* OAI21_X1_12;
    NAND2_X1* NAND2_X1_16;
    NAND2_X1* NAND2_X1_17;
    AOI21_X1* AOI21_X1_7;
    OAI21_X1* OAI21_X1_13;
    NAND2_X1* NAND2_X1_18;
    NAND2_X1* NAND2_X1_19;
    AOI21_X1* AOI21_X1_8;
    OAI21_X1* OAI21_X1_14;
    NAND2_X1* NAND2_X1_20;
    NAND2_X1* NAND2_X1_21;
    AOI21_X1* AOI21_X1_9;
    OAI21_X1* OAI21_X1_15;
    NAND2_X1* NAND2_X1_22;
    NAND2_X1* NAND2_X1_23;
    AOI21_X1* AOI21_X1_10;
    OAI21_X1* OAI21_X1_16;
    NAND2_X1* NAND2_X1_24;
    NAND2_X1* NAND2_X1_25;
    AOI21_X1* AOI21_X1_11;
    OAI21_X1* OAI21_X1_17;
    NAND2_X1* NAND2_X1_26;
    NAND2_X1* NAND2_X1_27;
    AOI21_X1* AOI21_X1_12;
    OAI21_X1* OAI21_X1_18;
    NAND2_X1* NAND2_X1_28;
    NAND2_X1* NAND2_X1_29;
    OAI21_X1* OAI21_X1_19;
    NOR2_X1* NOR2_X1_2;
    AOI21_X1* AOI21_X1_13;
    OAI21_X1* OAI21_X1_20;
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
    BUF_X1* BUF_X1_34;
    BUF_X1* BUF_X1_35;
    BUF_X1* BUF_X1_36;
    BUF_X1* BUF_X1_37;

SC_CTOR( imm ) {
    NAND2_X1_1 = new NAND2_X1("NAND2_X1_1");
        NAND2_X1_1->A1(S61);
        NAND2_X1_1->A2(S59[0]);
        NAND2_X1_1->ZN(S9);

    INV_X1_1 = new INV_X1("INV_X1_1");
        INV_X1_1->A(S63);
        INV_X1_1->ZN(S10);

    INV_X1_2 = new INV_X1("INV_X1_2");
        INV_X1_2->A(S62);
        INV_X1_2->ZN(S11);

    NOR2_X1_1 = new NOR2_X1("NOR2_X1_1");
        NOR2_X1_1->A1(S64);
        NOR2_X1_1->A2(S65);
        NOR2_X1_1->ZN(S12);

    NAND3_X1_1 = new NAND3_X1("NAND3_X1_1");
        NAND3_X1_1->A1(S12);
        NAND3_X1_1->A2(S10);
        NAND3_X1_1->A3(S11);
        NAND3_X1_1->ZN(S13);

    NAND2_X1_2 = new NAND2_X1("NAND2_X1_2");
        NAND2_X1_2->A1(S13);
        NAND2_X1_2->A2(S58[0]);
        NAND2_X1_2->ZN(S14);

    OAI21_X1_1 = new OAI21_X1("OAI21_X1_1");
        OAI21_X1_1->A(S14);
        OAI21_X1_1->B1(S9);
        OAI21_X1_1->B2(S13);
        OAI21_X1_1->ZN(S60[0]);

    NAND2_X1_3 = new NAND2_X1("NAND2_X1_3");
        NAND2_X1_3->A1(S61);
        NAND2_X1_3->A2(S59[1]);
        NAND2_X1_3->ZN(S15);

    NAND2_X1_4 = new NAND2_X1("NAND2_X1_4");
        NAND2_X1_4->A1(S13);
        NAND2_X1_4->A2(S58[1]);
        NAND2_X1_4->ZN(S16);

    OAI21_X1_2 = new OAI21_X1("OAI21_X1_2");
        OAI21_X1_2->A(S16);
        OAI21_X1_2->B1(S13);
        OAI21_X1_2->B2(S15);
        OAI21_X1_2->ZN(S60[1]);

    NAND2_X1_5 = new NAND2_X1("NAND2_X1_5");
        NAND2_X1_5->A1(S61);
        NAND2_X1_5->A2(S59[2]);
        NAND2_X1_5->ZN(S17);

    NAND2_X1_6 = new NAND2_X1("NAND2_X1_6");
        NAND2_X1_6->A1(S13);
        NAND2_X1_6->A2(S58[2]);
        NAND2_X1_6->ZN(S18);

    OAI21_X1_3 = new OAI21_X1("OAI21_X1_3");
        OAI21_X1_3->A(S18);
        OAI21_X1_3->B1(S13);
        OAI21_X1_3->B2(S17);
        OAI21_X1_3->ZN(S60[2]);

    NAND2_X1_7 = new NAND2_X1("NAND2_X1_7");
        NAND2_X1_7->A1(S61);
        NAND2_X1_7->A2(S59[3]);
        NAND2_X1_7->ZN(S19);

    NAND2_X1_8 = new NAND2_X1("NAND2_X1_8");
        NAND2_X1_8->A1(S13);
        NAND2_X1_8->A2(S58[3]);
        NAND2_X1_8->ZN(S20);

    OAI21_X1_4 = new OAI21_X1("OAI21_X1_4");
        OAI21_X1_4->A(S20);
        OAI21_X1_4->B1(S13);
        OAI21_X1_4->B2(S19);
        OAI21_X1_4->ZN(S60[3]);

    NAND2_X1_9 = new NAND2_X1("NAND2_X1_9");
        NAND2_X1_9->A1(S61);
        NAND2_X1_9->A2(S59[4]);
        NAND2_X1_9->ZN(S21);

    NAND2_X1_10 = new NAND2_X1("NAND2_X1_10");
        NAND2_X1_10->A1(S13);
        NAND2_X1_10->A2(S58[4]);
        NAND2_X1_10->ZN(S22);

    OAI21_X1_5 = new OAI21_X1("OAI21_X1_5");
        OAI21_X1_5->A(S22);
        OAI21_X1_5->B1(S13);
        OAI21_X1_5->B2(S21);
        OAI21_X1_5->ZN(S60[4]);

    NAND2_X1_11 = new NAND2_X1("NAND2_X1_11");
        NAND2_X1_11->A1(S62);
        NAND2_X1_11->A2(S58[4]);
        NAND2_X1_11->ZN(S23);

    AOI21_X1_1 = new AOI21_X1("AOI21_X1_1");
        AOI21_X1_1->A(S58[5]);
        AOI21_X1_1->B1(S12);
        AOI21_X1_1->B2(S10);
        AOI21_X1_1->ZN(S24);

    NAND2_X1_12 = new NAND2_X1("NAND2_X1_12");
        NAND2_X1_12->A1(S12);
        NAND2_X1_12->A2(S10);
        NAND2_X1_12->ZN(S25);

    AND2_X1_1 = new AND2_X1("AND2_X1_1");
        AND2_X1_1->A1(S59[5]);
        AND2_X1_1->A2(S61);
        AND2_X1_1->ZN(S26);

    OAI21_X1_6 = new OAI21_X1("OAI21_X1_6");
        OAI21_X1_6->A(S11);
        OAI21_X1_6->B1(S25);
        OAI21_X1_6->B2(S26);
        OAI21_X1_6->ZN(S27);

    OAI21_X1_7 = new OAI21_X1("OAI21_X1_7");
        OAI21_X1_7->A(S23);
        OAI21_X1_7->B1(S27);
        OAI21_X1_7->B2(S24);
        OAI21_X1_7->ZN(S60[5]);

    NAND2_X1_13 = new NAND2_X1("NAND2_X1_13");
        NAND2_X1_13->A1(S63);
        NAND2_X1_13->A2(S58[5]);
        NAND2_X1_13->ZN(S28);

    INV_X1_3 = new INV_X1("INV_X1_3");
        INV_X1_3->A(S28);
        INV_X1_3->ZN(S29);

    INV_X1_4 = new INV_X1("INV_X1_4");
        INV_X1_4->A(S58[6]);
        INV_X1_4->ZN(S30);

    OAI21_X1_8 = new OAI21_X1("OAI21_X1_8");
        OAI21_X1_8->A(S30);
        OAI21_X1_8->B1(S64);
        OAI21_X1_8->B2(S65);
        OAI21_X1_8->ZN(S31);

    NAND2_X1_14 = new NAND2_X1("NAND2_X1_14");
        NAND2_X1_14->A1(S61);
        NAND2_X1_14->A2(S59[6]);
        NAND2_X1_14->ZN(S32);

    AOI21_X1_2 = new AOI21_X1("AOI21_X1_2");
        AOI21_X1_2->A(S63);
        AOI21_X1_2->B1(S12);
        AOI21_X1_2->B2(S32);
        AOI21_X1_2->ZN(S33);

    AOI21_X1_3 = new AOI21_X1("AOI21_X1_3");
        AOI21_X1_3->A(S29);
        AOI21_X1_3->B1(S33);
        AOI21_X1_3->B2(S31);
        AOI21_X1_3->ZN(S34);

    OAI21_X1_9 = new OAI21_X1("OAI21_X1_9");
        OAI21_X1_9->A(S23);
        OAI21_X1_9->B1(S34);
        OAI21_X1_9->B2(S62);
        OAI21_X1_9->ZN(S60[6]);

    INV_X1_5 = new INV_X1("INV_X1_5");
        INV_X1_5->A(S58[7]);
        INV_X1_5->ZN(S35);

    OAI21_X1_10 = new OAI21_X1("OAI21_X1_10");
        OAI21_X1_10->A(S35);
        OAI21_X1_10->B1(S64);
        OAI21_X1_10->B2(S65);
        OAI21_X1_10->ZN(S36);

    NAND2_X1_15 = new NAND2_X1("NAND2_X1_15");
        NAND2_X1_15->A1(S61);
        NAND2_X1_15->A2(S59[7]);
        NAND2_X1_15->ZN(S37);

    AOI21_X1_4 = new AOI21_X1("AOI21_X1_4");
        AOI21_X1_4->A(S63);
        AOI21_X1_4->B1(S12);
        AOI21_X1_4->B2(S37);
        AOI21_X1_4->ZN(S38);

    AOI21_X1_5 = new AOI21_X1("AOI21_X1_5");
        AOI21_X1_5->A(S29);
        AOI21_X1_5->B1(S38);
        AOI21_X1_5->B2(S36);
        AOI21_X1_5->ZN(S39);

    OAI21_X1_11 = new OAI21_X1("OAI21_X1_11");
        OAI21_X1_11->A(S23);
        OAI21_X1_11->B1(S39);
        OAI21_X1_11->B2(S62);
        OAI21_X1_11->ZN(S60[7]);

    AOI21_X1_6 = new AOI21_X1("AOI21_X1_6");
        AOI21_X1_6->A(S64);
        AOI21_X1_6->B1(S58[0]);
        AOI21_X1_6->B2(S61);
        AOI21_X1_6->ZN(S40);

    INV_X1_6 = new INV_X1("INV_X1_6");
        INV_X1_6->A(S64);
        INV_X1_6->ZN(S41);

    INV_X1_7 = new INV_X1("INV_X1_7");
        INV_X1_7->A(S65);
        INV_X1_7->ZN(S42);

    OAI211_X1_1 = new OAI211_X1("OAI211_X1_1");
        OAI211_X1_1->A(S10);
        OAI211_X1_1->B(S42);
        OAI211_X1_1->C1(S41);
        OAI211_X1_1->C2(S58[7]);
        OAI211_X1_1->ZN(S43);

    OAI21_X1_12 = new OAI21_X1("OAI21_X1_12");
        OAI21_X1_12->A(S28);
        OAI21_X1_12->B1(S43);
        OAI21_X1_12->B2(S40);
        OAI21_X1_12->ZN(S44);

    NAND2_X1_16 = new NAND2_X1("NAND2_X1_16");
        NAND2_X1_16->A1(S44);
        NAND2_X1_16->A2(S11);
        NAND2_X1_16->ZN(S45);

    NAND2_X1_17 = new NAND2_X1("NAND2_X1_17");
        NAND2_X1_17->A1(S45);
        NAND2_X1_17->A2(S23);
        NAND2_X1_17->ZN(S60[8]);

    AOI21_X1_7 = new AOI21_X1("AOI21_X1_7");
        AOI21_X1_7->A(S64);
        AOI21_X1_7->B1(S61);
        AOI21_X1_7->B2(S58[1]);
        AOI21_X1_7->ZN(S46);

    OAI21_X1_13 = new OAI21_X1("OAI21_X1_13");
        OAI21_X1_13->A(S28);
        OAI21_X1_13->B1(S43);
        OAI21_X1_13->B2(S46);
        OAI21_X1_13->ZN(S47);

    NAND2_X1_18 = new NAND2_X1("NAND2_X1_18");
        NAND2_X1_18->A1(S47);
        NAND2_X1_18->A2(S11);
        NAND2_X1_18->ZN(S48);

    NAND2_X1_19 = new NAND2_X1("NAND2_X1_19");
        NAND2_X1_19->A1(S48);
        NAND2_X1_19->A2(S23);
        NAND2_X1_19->ZN(S60[9]);

    AOI21_X1_8 = new AOI21_X1("AOI21_X1_8");
        AOI21_X1_8->A(S64);
        AOI21_X1_8->B1(S61);
        AOI21_X1_8->B2(S58[2]);
        AOI21_X1_8->ZN(S49);

    OAI21_X1_14 = new OAI21_X1("OAI21_X1_14");
        OAI21_X1_14->A(S28);
        OAI21_X1_14->B1(S43);
        OAI21_X1_14->B2(S49);
        OAI21_X1_14->ZN(S50);

    NAND2_X1_20 = new NAND2_X1("NAND2_X1_20");
        NAND2_X1_20->A1(S50);
        NAND2_X1_20->A2(S11);
        NAND2_X1_20->ZN(S51);

    NAND2_X1_21 = new NAND2_X1("NAND2_X1_21");
        NAND2_X1_21->A1(S51);
        NAND2_X1_21->A2(S23);
        NAND2_X1_21->ZN(S60[10]);

    AOI21_X1_9 = new AOI21_X1("AOI21_X1_9");
        AOI21_X1_9->A(S64);
        AOI21_X1_9->B1(S61);
        AOI21_X1_9->B2(S58[3]);
        AOI21_X1_9->ZN(S52);

    OAI21_X1_15 = new OAI21_X1("OAI21_X1_15");
        OAI21_X1_15->A(S28);
        OAI21_X1_15->B1(S43);
        OAI21_X1_15->B2(S52);
        OAI21_X1_15->ZN(S53);

    NAND2_X1_22 = new NAND2_X1("NAND2_X1_22");
        NAND2_X1_22->A1(S53);
        NAND2_X1_22->A2(S11);
        NAND2_X1_22->ZN(S54);

    NAND2_X1_23 = new NAND2_X1("NAND2_X1_23");
        NAND2_X1_23->A1(S54);
        NAND2_X1_23->A2(S23);
        NAND2_X1_23->ZN(S60[11]);

    AOI21_X1_10 = new AOI21_X1("AOI21_X1_10");
        AOI21_X1_10->A(S64);
        AOI21_X1_10->B1(S61);
        AOI21_X1_10->B2(S58[4]);
        AOI21_X1_10->ZN(S55);

    OAI21_X1_16 = new OAI21_X1("OAI21_X1_16");
        OAI21_X1_16->A(S28);
        OAI21_X1_16->B1(S43);
        OAI21_X1_16->B2(S55);
        OAI21_X1_16->ZN(S56);

    NAND2_X1_24 = new NAND2_X1("NAND2_X1_24");
        NAND2_X1_24->A1(S56);
        NAND2_X1_24->A2(S11);
        NAND2_X1_24->ZN(S57);

    NAND2_X1_25 = new NAND2_X1("NAND2_X1_25");
        NAND2_X1_25->A1(S57);
        NAND2_X1_25->A2(S23);
        NAND2_X1_25->ZN(S60[12]);

    AOI21_X1_11 = new AOI21_X1("AOI21_X1_11");
        AOI21_X1_11->A(S64);
        AOI21_X1_11->B1(S61);
        AOI21_X1_11->B2(S58[5]);
        AOI21_X1_11->ZN(S0);

    OAI21_X1_17 = new OAI21_X1("OAI21_X1_17");
        OAI21_X1_17->A(S28);
        OAI21_X1_17->B1(S43);
        OAI21_X1_17->B2(S0);
        OAI21_X1_17->ZN(S1);

    NAND2_X1_26 = new NAND2_X1("NAND2_X1_26");
        NAND2_X1_26->A1(S1);
        NAND2_X1_26->A2(S11);
        NAND2_X1_26->ZN(S2);

    NAND2_X1_27 = new NAND2_X1("NAND2_X1_27");
        NAND2_X1_27->A1(S2);
        NAND2_X1_27->A2(S23);
        NAND2_X1_27->ZN(S60[13]);

    AOI21_X1_12 = new AOI21_X1("AOI21_X1_12");
        AOI21_X1_12->A(S64);
        AOI21_X1_12->B1(S61);
        AOI21_X1_12->B2(S58[6]);
        AOI21_X1_12->ZN(S3);

    OAI21_X1_18 = new OAI21_X1("OAI21_X1_18");
        OAI21_X1_18->A(S28);
        OAI21_X1_18->B1(S43);
        OAI21_X1_18->B2(S3);
        OAI21_X1_18->ZN(S4);

    NAND2_X1_28 = new NAND2_X1("NAND2_X1_28");
        NAND2_X1_28->A1(S4);
        NAND2_X1_28->A2(S11);
        NAND2_X1_28->ZN(S5);

    NAND2_X1_29 = new NAND2_X1("NAND2_X1_29");
        NAND2_X1_29->A1(S5);
        NAND2_X1_29->A2(S23);
        NAND2_X1_29->ZN(S60[14]);

    OAI21_X1_19 = new OAI21_X1("OAI21_X1_19");
        OAI21_X1_19->A(S58[7]);
        OAI21_X1_19->B1(S61);
        OAI21_X1_19->B2(S64);
        OAI21_X1_19->ZN(S6);

    NOR2_X1_2 = new NOR2_X1("NOR2_X1_2");
        NOR2_X1_2->A1(S6);
        NOR2_X1_2->A2(S65);
        NOR2_X1_2->ZN(S7);

    AOI21_X1_13 = new AOI21_X1("AOI21_X1_13");
        AOI21_X1_13->A(S29);
        AOI21_X1_13->B1(S7);
        AOI21_X1_13->B2(S10);
        AOI21_X1_13->ZN(S8);

    OAI21_X1_20 = new OAI21_X1("OAI21_X1_20");
        OAI21_X1_20->A(S23);
        OAI21_X1_20->B1(S8);
        OAI21_X1_20->B2(S62);
        OAI21_X1_20->ZN(S60[15]);

    BUF_X1_1 = new BUF_X1("BUF_X1_1");
        BUF_X1_1->A(in1[0]);
        BUF_X1_1->Z(S58[0]);

    BUF_X1_2 = new BUF_X1("BUF_X1_2");
        BUF_X1_2->A(in1[1]);
        BUF_X1_2->Z(S58[1]);

    BUF_X1_3 = new BUF_X1("BUF_X1_3");
        BUF_X1_3->A(in1[2]);
        BUF_X1_3->Z(S58[2]);

    BUF_X1_4 = new BUF_X1("BUF_X1_4");
        BUF_X1_4->A(in1[3]);
        BUF_X1_4->Z(S58[3]);

    BUF_X1_5 = new BUF_X1("BUF_X1_5");
        BUF_X1_5->A(in1[4]);
        BUF_X1_5->Z(S58[4]);

    BUF_X1_6 = new BUF_X1("BUF_X1_6");
        BUF_X1_6->A(in1[5]);
        BUF_X1_6->Z(S58[5]);

    BUF_X1_7 = new BUF_X1("BUF_X1_7");
        BUF_X1_7->A(in1[6]);
        BUF_X1_7->Z(S58[6]);

    BUF_X1_8 = new BUF_X1("BUF_X1_8");
        BUF_X1_8->A(in1[7]);
        BUF_X1_8->Z(S58[7]);

    BUF_X1_9 = new BUF_X1("BUF_X1_9");
        BUF_X1_9->A(in2[0]);
        BUF_X1_9->Z(S59[0]);

    BUF_X1_10 = new BUF_X1("BUF_X1_10");
        BUF_X1_10->A(in2[1]);
        BUF_X1_10->Z(S59[1]);

    BUF_X1_11 = new BUF_X1("BUF_X1_11");
        BUF_X1_11->A(in2[2]);
        BUF_X1_11->Z(S59[2]);

    BUF_X1_12 = new BUF_X1("BUF_X1_12");
        BUF_X1_12->A(in2[3]);
        BUF_X1_12->Z(S59[3]);

    BUF_X1_13 = new BUF_X1("BUF_X1_13");
        BUF_X1_13->A(in2[4]);
        BUF_X1_13->Z(S59[4]);

    BUF_X1_14 = new BUF_X1("BUF_X1_14");
        BUF_X1_14->A(in2[5]);
        BUF_X1_14->Z(S59[5]);

    BUF_X1_15 = new BUF_X1("BUF_X1_15");
        BUF_X1_15->A(in2[6]);
        BUF_X1_15->Z(S59[6]);

    BUF_X1_16 = new BUF_X1("BUF_X1_16");
        BUF_X1_16->A(in2[7]);
        BUF_X1_16->Z(S59[7]);

    BUF_X1_17 = new BUF_X1("BUF_X1_17");
        BUF_X1_17->A(S60[0]);
        BUF_X1_17->Z(outimm[0]);

    BUF_X1_18 = new BUF_X1("BUF_X1_18");
        BUF_X1_18->A(S60[1]);
        BUF_X1_18->Z(outimm[1]);

    BUF_X1_19 = new BUF_X1("BUF_X1_19");
        BUF_X1_19->A(S60[10]);
        BUF_X1_19->Z(outimm[10]);

    BUF_X1_20 = new BUF_X1("BUF_X1_20");
        BUF_X1_20->A(S60[11]);
        BUF_X1_20->Z(outimm[11]);

    BUF_X1_21 = new BUF_X1("BUF_X1_21");
        BUF_X1_21->A(S60[12]);
        BUF_X1_21->Z(outimm[12]);

    BUF_X1_22 = new BUF_X1("BUF_X1_22");
        BUF_X1_22->A(S60[13]);
        BUF_X1_22->Z(outimm[13]);

    BUF_X1_23 = new BUF_X1("BUF_X1_23");
        BUF_X1_23->A(S60[14]);
        BUF_X1_23->Z(outimm[14]);

    BUF_X1_24 = new BUF_X1("BUF_X1_24");
        BUF_X1_24->A(S60[15]);
        BUF_X1_24->Z(outimm[15]);

    BUF_X1_25 = new BUF_X1("BUF_X1_25");
        BUF_X1_25->A(S60[2]);
        BUF_X1_25->Z(outimm[2]);

    BUF_X1_26 = new BUF_X1("BUF_X1_26");
        BUF_X1_26->A(S60[3]);
        BUF_X1_26->Z(outimm[3]);

    BUF_X1_27 = new BUF_X1("BUF_X1_27");
        BUF_X1_27->A(S60[4]);
        BUF_X1_27->Z(outimm[4]);

    BUF_X1_28 = new BUF_X1("BUF_X1_28");
        BUF_X1_28->A(S60[5]);
        BUF_X1_28->Z(outimm[5]);

    BUF_X1_29 = new BUF_X1("BUF_X1_29");
        BUF_X1_29->A(S60[6]);
        BUF_X1_29->Z(outimm[6]);

    BUF_X1_30 = new BUF_X1("BUF_X1_30");
        BUF_X1_30->A(S60[7]);
        BUF_X1_30->Z(outimm[7]);

    BUF_X1_31 = new BUF_X1("BUF_X1_31");
        BUF_X1_31->A(S60[8]);
        BUF_X1_31->Z(outimm[8]);

    BUF_X1_32 = new BUF_X1("BUF_X1_32");
        BUF_X1_32->A(S60[9]);
        BUF_X1_32->Z(outimm[9]);

    BUF_X1_33 = new BUF_X1("BUF_X1_33");
        BUF_X1_33->A(p1lowbits);
        BUF_X1_33->Z(S61);

    BUF_X1_34 = new BUF_X1("BUF_X1_34");
        BUF_X1_34->A(se5bits);
        BUF_X1_34->Z(S62);

    BUF_X1_35 = new BUF_X1("BUF_X1_35");
        BUF_X1_35->A(se6bits);
        BUF_X1_35->Z(S63);

    BUF_X1_36 = new BUF_X1("BUF_X1_36");
        BUF_X1_36->A(se8bits);
        BUF_X1_36->Z(S64);

    BUF_X1_37 = new BUF_X1("BUF_X1_37");
        BUF_X1_37->A(use8bits);
        BUF_X1_37->Z(S65);


    SC_METHOD(sc_logic_signal_assignment);

    }

    void sc_logic_signal_assignment(void){ 
        sc_logic_1_signal.write(SC_LOGIC_1);
        sc_logic_0_signal.write(SC_LOGIC_0);
    }
};
#endif /* __IMM_H__ */

