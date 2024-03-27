#include <systemc.h>
#include "Complex_NAgate_45.h"



#ifndef __REG_H__
#define __REG_H__
using namespace sc_core;

SC_MODULE( reg ) {

    sc_in<sc_logic> clk;
    sc_in<sc_logic> rst;
    sc_in<sc_logic> ld;
    sc_in<sc_logic> inreg[16];
    sc_out<sc_logic> outreg[16];

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
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S66[16];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S67 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S67");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S68[16];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S69 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S69");

    INV_X1* INV_X1_1;
    INV_X1* INV_X1_2;
    NAND2_X1* NAND2_X1_1;
    OAI21_X1* OAI21_X1_1;
    INV_X1* INV_X1_3;
    NAND2_X1* NAND2_X1_2;
    OAI21_X1* OAI21_X1_2;
    INV_X1* INV_X1_4;
    NAND2_X1* NAND2_X1_3;
    OAI21_X1* OAI21_X1_3;
    INV_X1* INV_X1_5;
    NAND2_X1* NAND2_X1_4;
    OAI21_X1* OAI21_X1_4;
    INV_X1* INV_X1_6;
    NAND2_X1* NAND2_X1_5;
    OAI21_X1* OAI21_X1_5;
    INV_X1* INV_X1_7;
    NAND2_X1* NAND2_X1_6;
    OAI21_X1* OAI21_X1_6;
    INV_X1* INV_X1_8;
    NAND2_X1* NAND2_X1_7;
    OAI21_X1* OAI21_X1_7;
    INV_X1* INV_X1_9;
    NAND2_X1* NAND2_X1_8;
    OAI21_X1* OAI21_X1_8;
    INV_X1* INV_X1_10;
    NAND2_X1* NAND2_X1_9;
    OAI21_X1* OAI21_X1_9;
    INV_X1* INV_X1_11;
    NAND2_X1* NAND2_X1_10;
    OAI21_X1* OAI21_X1_10;
    INV_X1* INV_X1_12;
    NAND2_X1* NAND2_X1_11;
    OAI21_X1* OAI21_X1_11;
    INV_X1* INV_X1_13;
    NAND2_X1* NAND2_X1_12;
    OAI21_X1* OAI21_X1_12;
    INV_X1* INV_X1_14;
    NAND2_X1* NAND2_X1_13;
    OAI21_X1* OAI21_X1_13;
    INV_X1* INV_X1_15;
    NAND2_X1* NAND2_X1_14;
    OAI21_X1* OAI21_X1_14;
    INV_X1* INV_X1_16;
    NAND2_X1* NAND2_X1_15;
    OAI21_X1* OAI21_X1_15;
    INV_X1* INV_X1_17;
    NAND2_X1* NAND2_X1_16;
    OAI21_X1* OAI21_X1_16;
    DFFR_X1* DFFR_X1_1;
    DFFR_X1* DFFR_X1_2;
    DFFR_X1* DFFR_X1_3;
    DFFR_X1* DFFR_X1_4;
    DFFR_X1* DFFR_X1_5;
    DFFR_X1* DFFR_X1_6;
    DFFR_X1* DFFR_X1_7;
    DFFR_X1* DFFR_X1_8;
    DFFR_X1* DFFR_X1_9;
    DFFR_X1* DFFR_X1_10;
    DFFR_X1* DFFR_X1_11;
    DFFR_X1* DFFR_X1_12;
    DFFR_X1* DFFR_X1_13;
    DFFR_X1* DFFR_X1_14;
    DFFR_X1* DFFR_X1_15;
    DFFR_X1* DFFR_X1_16;
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

SC_CTOR( reg ) {
    INV_X1_1 = new INV_X1("INV_X1_1");
        INV_X1_1->A(S69);
        INV_X1_1->ZN(S0);

    INV_X1_2 = new INV_X1("INV_X1_2");
        INV_X1_2->A(S68[0]);
        INV_X1_2->ZN(S17);

    NAND2_X1_1 = new NAND2_X1("NAND2_X1_1");
        NAND2_X1_1->A1(S66[0]);
        NAND2_X1_1->A2(S67);
        NAND2_X1_1->ZN(S18);

    OAI21_X1_1 = new OAI21_X1("OAI21_X1_1");
        OAI21_X1_1->A(S18);
        OAI21_X1_1->B1(S17);
        OAI21_X1_1->B2(S67);
        OAI21_X1_1->ZN(S1);

    INV_X1_3 = new INV_X1("INV_X1_3");
        INV_X1_3->A(S68[1]);
        INV_X1_3->ZN(S19);

    NAND2_X1_2 = new NAND2_X1("NAND2_X1_2");
        NAND2_X1_2->A1(S67);
        NAND2_X1_2->A2(S66[1]);
        NAND2_X1_2->ZN(S20);

    OAI21_X1_2 = new OAI21_X1("OAI21_X1_2");
        OAI21_X1_2->A(S20);
        OAI21_X1_2->B1(S19);
        OAI21_X1_2->B2(S67);
        OAI21_X1_2->ZN(S2);

    INV_X1_4 = new INV_X1("INV_X1_4");
        INV_X1_4->A(S68[2]);
        INV_X1_4->ZN(S21);

    NAND2_X1_3 = new NAND2_X1("NAND2_X1_3");
        NAND2_X1_3->A1(S67);
        NAND2_X1_3->A2(S66[2]);
        NAND2_X1_3->ZN(S22);

    OAI21_X1_3 = new OAI21_X1("OAI21_X1_3");
        OAI21_X1_3->A(S22);
        OAI21_X1_3->B1(S21);
        OAI21_X1_3->B2(S67);
        OAI21_X1_3->ZN(S3);

    INV_X1_5 = new INV_X1("INV_X1_5");
        INV_X1_5->A(S68[3]);
        INV_X1_5->ZN(S23);

    NAND2_X1_4 = new NAND2_X1("NAND2_X1_4");
        NAND2_X1_4->A1(S67);
        NAND2_X1_4->A2(S66[3]);
        NAND2_X1_4->ZN(S24);

    OAI21_X1_4 = new OAI21_X1("OAI21_X1_4");
        OAI21_X1_4->A(S24);
        OAI21_X1_4->B1(S23);
        OAI21_X1_4->B2(S67);
        OAI21_X1_4->ZN(S4);

    INV_X1_6 = new INV_X1("INV_X1_6");
        INV_X1_6->A(S68[4]);
        INV_X1_6->ZN(S25);

    NAND2_X1_5 = new NAND2_X1("NAND2_X1_5");
        NAND2_X1_5->A1(S67);
        NAND2_X1_5->A2(S66[4]);
        NAND2_X1_5->ZN(S26);

    OAI21_X1_5 = new OAI21_X1("OAI21_X1_5");
        OAI21_X1_5->A(S26);
        OAI21_X1_5->B1(S25);
        OAI21_X1_5->B2(S67);
        OAI21_X1_5->ZN(S5);

    INV_X1_7 = new INV_X1("INV_X1_7");
        INV_X1_7->A(S68[5]);
        INV_X1_7->ZN(S27);

    NAND2_X1_6 = new NAND2_X1("NAND2_X1_6");
        NAND2_X1_6->A1(S67);
        NAND2_X1_6->A2(S66[5]);
        NAND2_X1_6->ZN(S28);

    OAI21_X1_6 = new OAI21_X1("OAI21_X1_6");
        OAI21_X1_6->A(S28);
        OAI21_X1_6->B1(S27);
        OAI21_X1_6->B2(S67);
        OAI21_X1_6->ZN(S6);

    INV_X1_8 = new INV_X1("INV_X1_8");
        INV_X1_8->A(S68[6]);
        INV_X1_8->ZN(S29);

    NAND2_X1_7 = new NAND2_X1("NAND2_X1_7");
        NAND2_X1_7->A1(S67);
        NAND2_X1_7->A2(S66[6]);
        NAND2_X1_7->ZN(S30);

    OAI21_X1_7 = new OAI21_X1("OAI21_X1_7");
        OAI21_X1_7->A(S30);
        OAI21_X1_7->B1(S29);
        OAI21_X1_7->B2(S67);
        OAI21_X1_7->ZN(S7);

    INV_X1_9 = new INV_X1("INV_X1_9");
        INV_X1_9->A(S68[7]);
        INV_X1_9->ZN(S31);

    NAND2_X1_8 = new NAND2_X1("NAND2_X1_8");
        NAND2_X1_8->A1(S67);
        NAND2_X1_8->A2(S66[7]);
        NAND2_X1_8->ZN(S32);

    OAI21_X1_8 = new OAI21_X1("OAI21_X1_8");
        OAI21_X1_8->A(S32);
        OAI21_X1_8->B1(S31);
        OAI21_X1_8->B2(S67);
        OAI21_X1_8->ZN(S8);

    INV_X1_10 = new INV_X1("INV_X1_10");
        INV_X1_10->A(S68[8]);
        INV_X1_10->ZN(S33);

    NAND2_X1_9 = new NAND2_X1("NAND2_X1_9");
        NAND2_X1_9->A1(S67);
        NAND2_X1_9->A2(S66[8]);
        NAND2_X1_9->ZN(S34);

    OAI21_X1_9 = new OAI21_X1("OAI21_X1_9");
        OAI21_X1_9->A(S34);
        OAI21_X1_9->B1(S33);
        OAI21_X1_9->B2(S67);
        OAI21_X1_9->ZN(S9);

    INV_X1_11 = new INV_X1("INV_X1_11");
        INV_X1_11->A(S68[9]);
        INV_X1_11->ZN(S35);

    NAND2_X1_10 = new NAND2_X1("NAND2_X1_10");
        NAND2_X1_10->A1(S67);
        NAND2_X1_10->A2(S66[9]);
        NAND2_X1_10->ZN(S36);

    OAI21_X1_10 = new OAI21_X1("OAI21_X1_10");
        OAI21_X1_10->A(S36);
        OAI21_X1_10->B1(S35);
        OAI21_X1_10->B2(S67);
        OAI21_X1_10->ZN(S10);

    INV_X1_12 = new INV_X1("INV_X1_12");
        INV_X1_12->A(S68[10]);
        INV_X1_12->ZN(S37);

    NAND2_X1_11 = new NAND2_X1("NAND2_X1_11");
        NAND2_X1_11->A1(S67);
        NAND2_X1_11->A2(S66[10]);
        NAND2_X1_11->ZN(S38);

    OAI21_X1_11 = new OAI21_X1("OAI21_X1_11");
        OAI21_X1_11->A(S38);
        OAI21_X1_11->B1(S37);
        OAI21_X1_11->B2(S67);
        OAI21_X1_11->ZN(S11);

    INV_X1_13 = new INV_X1("INV_X1_13");
        INV_X1_13->A(S68[11]);
        INV_X1_13->ZN(S39);

    NAND2_X1_12 = new NAND2_X1("NAND2_X1_12");
        NAND2_X1_12->A1(S67);
        NAND2_X1_12->A2(S66[11]);
        NAND2_X1_12->ZN(S40);

    OAI21_X1_12 = new OAI21_X1("OAI21_X1_12");
        OAI21_X1_12->A(S40);
        OAI21_X1_12->B1(S39);
        OAI21_X1_12->B2(S67);
        OAI21_X1_12->ZN(S12);

    INV_X1_14 = new INV_X1("INV_X1_14");
        INV_X1_14->A(S68[12]);
        INV_X1_14->ZN(S41);

    NAND2_X1_13 = new NAND2_X1("NAND2_X1_13");
        NAND2_X1_13->A1(S67);
        NAND2_X1_13->A2(S66[12]);
        NAND2_X1_13->ZN(S42);

    OAI21_X1_13 = new OAI21_X1("OAI21_X1_13");
        OAI21_X1_13->A(S42);
        OAI21_X1_13->B1(S41);
        OAI21_X1_13->B2(S67);
        OAI21_X1_13->ZN(S13);

    INV_X1_15 = new INV_X1("INV_X1_15");
        INV_X1_15->A(S68[13]);
        INV_X1_15->ZN(S43);

    NAND2_X1_14 = new NAND2_X1("NAND2_X1_14");
        NAND2_X1_14->A1(S67);
        NAND2_X1_14->A2(S66[13]);
        NAND2_X1_14->ZN(S44);

    OAI21_X1_14 = new OAI21_X1("OAI21_X1_14");
        OAI21_X1_14->A(S44);
        OAI21_X1_14->B1(S43);
        OAI21_X1_14->B2(S67);
        OAI21_X1_14->ZN(S14);

    INV_X1_16 = new INV_X1("INV_X1_16");
        INV_X1_16->A(S68[14]);
        INV_X1_16->ZN(S45);

    NAND2_X1_15 = new NAND2_X1("NAND2_X1_15");
        NAND2_X1_15->A1(S67);
        NAND2_X1_15->A2(S66[14]);
        NAND2_X1_15->ZN(S46);

    OAI21_X1_15 = new OAI21_X1("OAI21_X1_15");
        OAI21_X1_15->A(S46);
        OAI21_X1_15->B1(S45);
        OAI21_X1_15->B2(S67);
        OAI21_X1_15->ZN(S15);

    INV_X1_17 = new INV_X1("INV_X1_17");
        INV_X1_17->A(S68[15]);
        INV_X1_17->ZN(S47);

    NAND2_X1_16 = new NAND2_X1("NAND2_X1_16");
        NAND2_X1_16->A1(S67);
        NAND2_X1_16->A2(S66[15]);
        NAND2_X1_16->ZN(S48);

    OAI21_X1_16 = new OAI21_X1("OAI21_X1_16");
        OAI21_X1_16->A(S48);
        OAI21_X1_16->B1(S47);
        OAI21_X1_16->B2(S67);
        OAI21_X1_16->ZN(S16);

    DFFR_X1_1 = new DFFR_X1("DFFR_X1_1");
        DFFR_X1_1->CK(S65);
        DFFR_X1_1->D(S1);
        DFFR_X1_1->Q(S68[0]);
        DFFR_X1_1->QN(S64);
        DFFR_X1_1->RN(S0);

    DFFR_X1_2 = new DFFR_X1("DFFR_X1_2");
        DFFR_X1_2->CK(S65);
        DFFR_X1_2->D(S2);
        DFFR_X1_2->Q(S68[1]);
        DFFR_X1_2->QN(S63);
        DFFR_X1_2->RN(S0);

    DFFR_X1_3 = new DFFR_X1("DFFR_X1_3");
        DFFR_X1_3->CK(S65);
        DFFR_X1_3->D(S3);
        DFFR_X1_3->Q(S68[2]);
        DFFR_X1_3->QN(S62);
        DFFR_X1_3->RN(S0);

    DFFR_X1_4 = new DFFR_X1("DFFR_X1_4");
        DFFR_X1_4->CK(S65);
        DFFR_X1_4->D(S4);
        DFFR_X1_4->Q(S68[3]);
        DFFR_X1_4->QN(S61);
        DFFR_X1_4->RN(S0);

    DFFR_X1_5 = new DFFR_X1("DFFR_X1_5");
        DFFR_X1_5->CK(S65);
        DFFR_X1_5->D(S5);
        DFFR_X1_5->Q(S68[4]);
        DFFR_X1_5->QN(S60);
        DFFR_X1_5->RN(S0);

    DFFR_X1_6 = new DFFR_X1("DFFR_X1_6");
        DFFR_X1_6->CK(S65);
        DFFR_X1_6->D(S6);
        DFFR_X1_6->Q(S68[5]);
        DFFR_X1_6->QN(S59);
        DFFR_X1_6->RN(S0);

    DFFR_X1_7 = new DFFR_X1("DFFR_X1_7");
        DFFR_X1_7->CK(S65);
        DFFR_X1_7->D(S7);
        DFFR_X1_7->Q(S68[6]);
        DFFR_X1_7->QN(S58);
        DFFR_X1_7->RN(S0);

    DFFR_X1_8 = new DFFR_X1("DFFR_X1_8");
        DFFR_X1_8->CK(S65);
        DFFR_X1_8->D(S8);
        DFFR_X1_8->Q(S68[7]);
        DFFR_X1_8->QN(S57);
        DFFR_X1_8->RN(S0);

    DFFR_X1_9 = new DFFR_X1("DFFR_X1_9");
        DFFR_X1_9->CK(S65);
        DFFR_X1_9->D(S9);
        DFFR_X1_9->Q(S68[8]);
        DFFR_X1_9->QN(S56);
        DFFR_X1_9->RN(S0);

    DFFR_X1_10 = new DFFR_X1("DFFR_X1_10");
        DFFR_X1_10->CK(S65);
        DFFR_X1_10->D(S10);
        DFFR_X1_10->Q(S68[9]);
        DFFR_X1_10->QN(S55);
        DFFR_X1_10->RN(S0);

    DFFR_X1_11 = new DFFR_X1("DFFR_X1_11");
        DFFR_X1_11->CK(S65);
        DFFR_X1_11->D(S11);
        DFFR_X1_11->Q(S68[10]);
        DFFR_X1_11->QN(S54);
        DFFR_X1_11->RN(S0);

    DFFR_X1_12 = new DFFR_X1("DFFR_X1_12");
        DFFR_X1_12->CK(S65);
        DFFR_X1_12->D(S12);
        DFFR_X1_12->Q(S68[11]);
        DFFR_X1_12->QN(S53);
        DFFR_X1_12->RN(S0);

    DFFR_X1_13 = new DFFR_X1("DFFR_X1_13");
        DFFR_X1_13->CK(S65);
        DFFR_X1_13->D(S13);
        DFFR_X1_13->Q(S68[12]);
        DFFR_X1_13->QN(S52);
        DFFR_X1_13->RN(S0);

    DFFR_X1_14 = new DFFR_X1("DFFR_X1_14");
        DFFR_X1_14->CK(S65);
        DFFR_X1_14->D(S14);
        DFFR_X1_14->Q(S68[13]);
        DFFR_X1_14->QN(S51);
        DFFR_X1_14->RN(S0);

    DFFR_X1_15 = new DFFR_X1("DFFR_X1_15");
        DFFR_X1_15->CK(S65);
        DFFR_X1_15->D(S15);
        DFFR_X1_15->Q(S68[14]);
        DFFR_X1_15->QN(S50);
        DFFR_X1_15->RN(S0);

    DFFR_X1_16 = new DFFR_X1("DFFR_X1_16");
        DFFR_X1_16->CK(S65);
        DFFR_X1_16->D(S16);
        DFFR_X1_16->Q(S68[15]);
        DFFR_X1_16->QN(S49);
        DFFR_X1_16->RN(S0);

    BUF_X1_1 = new BUF_X1("BUF_X1_1");
        BUF_X1_1->A(clk);
        BUF_X1_1->Z(S65);

    BUF_X1_2 = new BUF_X1("BUF_X1_2");
        BUF_X1_2->A(inreg[0]);
        BUF_X1_2->Z(S66[0]);

    BUF_X1_3 = new BUF_X1("BUF_X1_3");
        BUF_X1_3->A(inreg[1]);
        BUF_X1_3->Z(S66[1]);

    BUF_X1_4 = new BUF_X1("BUF_X1_4");
        BUF_X1_4->A(inreg[10]);
        BUF_X1_4->Z(S66[10]);

    BUF_X1_5 = new BUF_X1("BUF_X1_5");
        BUF_X1_5->A(inreg[11]);
        BUF_X1_5->Z(S66[11]);

    BUF_X1_6 = new BUF_X1("BUF_X1_6");
        BUF_X1_6->A(inreg[12]);
        BUF_X1_6->Z(S66[12]);

    BUF_X1_7 = new BUF_X1("BUF_X1_7");
        BUF_X1_7->A(inreg[13]);
        BUF_X1_7->Z(S66[13]);

    BUF_X1_8 = new BUF_X1("BUF_X1_8");
        BUF_X1_8->A(inreg[14]);
        BUF_X1_8->Z(S66[14]);

    BUF_X1_9 = new BUF_X1("BUF_X1_9");
        BUF_X1_9->A(inreg[15]);
        BUF_X1_9->Z(S66[15]);

    BUF_X1_10 = new BUF_X1("BUF_X1_10");
        BUF_X1_10->A(inreg[2]);
        BUF_X1_10->Z(S66[2]);

    BUF_X1_11 = new BUF_X1("BUF_X1_11");
        BUF_X1_11->A(inreg[3]);
        BUF_X1_11->Z(S66[3]);

    BUF_X1_12 = new BUF_X1("BUF_X1_12");
        BUF_X1_12->A(inreg[4]);
        BUF_X1_12->Z(S66[4]);

    BUF_X1_13 = new BUF_X1("BUF_X1_13");
        BUF_X1_13->A(inreg[5]);
        BUF_X1_13->Z(S66[5]);

    BUF_X1_14 = new BUF_X1("BUF_X1_14");
        BUF_X1_14->A(inreg[6]);
        BUF_X1_14->Z(S66[6]);

    BUF_X1_15 = new BUF_X1("BUF_X1_15");
        BUF_X1_15->A(inreg[7]);
        BUF_X1_15->Z(S66[7]);

    BUF_X1_16 = new BUF_X1("BUF_X1_16");
        BUF_X1_16->A(inreg[8]);
        BUF_X1_16->Z(S66[8]);

    BUF_X1_17 = new BUF_X1("BUF_X1_17");
        BUF_X1_17->A(inreg[9]);
        BUF_X1_17->Z(S66[9]);

    BUF_X1_18 = new BUF_X1("BUF_X1_18");
        BUF_X1_18->A(ld);
        BUF_X1_18->Z(S67);

    BUF_X1_19 = new BUF_X1("BUF_X1_19");
        BUF_X1_19->A(S68[0]);
        BUF_X1_19->Z(outreg[0]);

    BUF_X1_20 = new BUF_X1("BUF_X1_20");
        BUF_X1_20->A(S68[1]);
        BUF_X1_20->Z(outreg[1]);

    BUF_X1_21 = new BUF_X1("BUF_X1_21");
        BUF_X1_21->A(S68[10]);
        BUF_X1_21->Z(outreg[10]);

    BUF_X1_22 = new BUF_X1("BUF_X1_22");
        BUF_X1_22->A(S68[11]);
        BUF_X1_22->Z(outreg[11]);

    BUF_X1_23 = new BUF_X1("BUF_X1_23");
        BUF_X1_23->A(S68[12]);
        BUF_X1_23->Z(outreg[12]);

    BUF_X1_24 = new BUF_X1("BUF_X1_24");
        BUF_X1_24->A(S68[13]);
        BUF_X1_24->Z(outreg[13]);

    BUF_X1_25 = new BUF_X1("BUF_X1_25");
        BUF_X1_25->A(S68[14]);
        BUF_X1_25->Z(outreg[14]);

    BUF_X1_26 = new BUF_X1("BUF_X1_26");
        BUF_X1_26->A(S68[15]);
        BUF_X1_26->Z(outreg[15]);

    BUF_X1_27 = new BUF_X1("BUF_X1_27");
        BUF_X1_27->A(S68[2]);
        BUF_X1_27->Z(outreg[2]);

    BUF_X1_28 = new BUF_X1("BUF_X1_28");
        BUF_X1_28->A(S68[3]);
        BUF_X1_28->Z(outreg[3]);

    BUF_X1_29 = new BUF_X1("BUF_X1_29");
        BUF_X1_29->A(S68[4]);
        BUF_X1_29->Z(outreg[4]);

    BUF_X1_30 = new BUF_X1("BUF_X1_30");
        BUF_X1_30->A(S68[5]);
        BUF_X1_30->Z(outreg[5]);

    BUF_X1_31 = new BUF_X1("BUF_X1_31");
        BUF_X1_31->A(S68[6]);
        BUF_X1_31->Z(outreg[6]);

    BUF_X1_32 = new BUF_X1("BUF_X1_32");
        BUF_X1_32->A(S68[7]);
        BUF_X1_32->Z(outreg[7]);

    BUF_X1_33 = new BUF_X1("BUF_X1_33");
        BUF_X1_33->A(S68[8]);
        BUF_X1_33->Z(outreg[8]);

    BUF_X1_34 = new BUF_X1("BUF_X1_34");
        BUF_X1_34->A(S68[9]);
        BUF_X1_34->Z(outreg[9]);

    BUF_X1_35 = new BUF_X1("BUF_X1_35");
        BUF_X1_35->A(rst);
        BUF_X1_35->Z(S69);


    SC_METHOD(sc_logic_signal_assignment);

    }

    void sc_logic_signal_assignment(void){ 
        sc_logic_1_signal.write(SC_LOGIC_1);
        sc_logic_0_signal.write(SC_LOGIC_0);
    }
};
#endif /* __REG_H__ */

