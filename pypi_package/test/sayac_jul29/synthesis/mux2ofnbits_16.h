#include <systemc.h>
#include "Complex_NAgate_45.h"



#ifndef __MUX2OFNBITS_16_H__
#define __MUX2OFNBITS_16_H__
using namespace sc_core;

SC_MODULE( mux2ofnbits_16 ) {

    sc_in<sc_logic> in1[16];
    sc_in<sc_logic> in2[16];
    sc_in<sc_logic> sel1;
    sc_in<sc_logic> sel2;
    sc_out<sc_logic> outmux[16];

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
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S68 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S68");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S69 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S69");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S70 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S70");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S71 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S71");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S72 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S72");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S73 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S73");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S74 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S74");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S75 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S75");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S76 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S76");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S77 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S77");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S78 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S78");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S79 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S79");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S80 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S80");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S81 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S81");

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
    NAND2_X1* NAND2_X1_11;
    NAND2_X1* NAND2_X1_12;
    OAI21_X1* OAI21_X1_6;
    NAND2_X1* NAND2_X1_13;
    NAND2_X1* NAND2_X1_14;
    OAI21_X1* OAI21_X1_7;
    NAND2_X1* NAND2_X1_15;
    NAND2_X1* NAND2_X1_16;
    OAI21_X1* OAI21_X1_8;
    NAND2_X1* NAND2_X1_17;
    NAND2_X1* NAND2_X1_18;
    OAI21_X1* OAI21_X1_9;
    NAND2_X1* NAND2_X1_19;
    NAND2_X1* NAND2_X1_20;
    OAI21_X1* OAI21_X1_10;
    NAND2_X1* NAND2_X1_21;
    NAND2_X1* NAND2_X1_22;
    OAI21_X1* OAI21_X1_11;
    NAND2_X1* NAND2_X1_23;
    NAND2_X1* NAND2_X1_24;
    OAI21_X1* OAI21_X1_12;
    NAND2_X1* NAND2_X1_25;
    NAND2_X1* NAND2_X1_26;
    OAI21_X1* OAI21_X1_13;
    NAND2_X1* NAND2_X1_27;
    NAND2_X1* NAND2_X1_28;
    OAI21_X1* OAI21_X1_14;
    NAND2_X1* NAND2_X1_29;
    NAND2_X1* NAND2_X1_30;
    OAI21_X1* OAI21_X1_15;
    NAND2_X1* NAND2_X1_31;
    NAND2_X1* NAND2_X1_32;
    OAI21_X1* OAI21_X1_16;
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
    BUF_X1* BUF_X1_38;
    BUF_X1* BUF_X1_39;
    BUF_X1* BUF_X1_40;
    BUF_X1* BUF_X1_41;
    BUF_X1* BUF_X1_42;
    BUF_X1* BUF_X1_43;
    BUF_X1* BUF_X1_44;
    BUF_X1* BUF_X1_45;
    BUF_X1* BUF_X1_46;
    BUF_X1* BUF_X1_47;
    BUF_X1* BUF_X1_48;
    BUF_X1* BUF_X1_49;
    BUF_X1* BUF_X1_50;

SC_CTOR( mux2ofnbits_16 ) {
    NAND2_X1_1 = new NAND2_X1("NAND2_X1_1");
        NAND2_X1_1->A1(S81);
        NAND2_X1_1->A2(S48);
        NAND2_X1_1->ZN(S0);

    NAND2_X1_2 = new NAND2_X1("NAND2_X1_2");
        NAND2_X1_2->A1(S32);
        NAND2_X1_2->A2(S80);
        NAND2_X1_2->ZN(S1);

    OAI21_X1_1 = new OAI21_X1("OAI21_X1_1");
        OAI21_X1_1->A(S1);
        OAI21_X1_1->B1(S0);
        OAI21_X1_1->B2(S80);
        OAI21_X1_1->ZN(S64);

    NAND2_X1_3 = new NAND2_X1("NAND2_X1_3");
        NAND2_X1_3->A1(S81);
        NAND2_X1_3->A2(S55);
        NAND2_X1_3->ZN(S2);

    NAND2_X1_4 = new NAND2_X1("NAND2_X1_4");
        NAND2_X1_4->A1(S80);
        NAND2_X1_4->A2(S39);
        NAND2_X1_4->ZN(S3);

    OAI21_X1_2 = new OAI21_X1("OAI21_X1_2");
        OAI21_X1_2->A(S3);
        OAI21_X1_2->B1(S2);
        OAI21_X1_2->B2(S80);
        OAI21_X1_2->ZN(S71);

    NAND2_X1_5 = new NAND2_X1("NAND2_X1_5");
        NAND2_X1_5->A1(S81);
        NAND2_X1_5->A2(S56);
        NAND2_X1_5->ZN(S4);

    NAND2_X1_6 = new NAND2_X1("NAND2_X1_6");
        NAND2_X1_6->A1(S80);
        NAND2_X1_6->A2(S40);
        NAND2_X1_6->ZN(S5);

    OAI21_X1_3 = new OAI21_X1("OAI21_X1_3");
        OAI21_X1_3->A(S5);
        OAI21_X1_3->B1(S4);
        OAI21_X1_3->B2(S80);
        OAI21_X1_3->ZN(S72);

    NAND2_X1_7 = new NAND2_X1("NAND2_X1_7");
        NAND2_X1_7->A1(S81);
        NAND2_X1_7->A2(S57);
        NAND2_X1_7->ZN(S6);

    NAND2_X1_8 = new NAND2_X1("NAND2_X1_8");
        NAND2_X1_8->A1(S80);
        NAND2_X1_8->A2(S41);
        NAND2_X1_8->ZN(S7);

    OAI21_X1_4 = new OAI21_X1("OAI21_X1_4");
        OAI21_X1_4->A(S7);
        OAI21_X1_4->B1(S6);
        OAI21_X1_4->B2(S80);
        OAI21_X1_4->ZN(S73);

    NAND2_X1_9 = new NAND2_X1("NAND2_X1_9");
        NAND2_X1_9->A1(S81);
        NAND2_X1_9->A2(S58);
        NAND2_X1_9->ZN(S8);

    NAND2_X1_10 = new NAND2_X1("NAND2_X1_10");
        NAND2_X1_10->A1(S80);
        NAND2_X1_10->A2(S42);
        NAND2_X1_10->ZN(S9);

    OAI21_X1_5 = new OAI21_X1("OAI21_X1_5");
        OAI21_X1_5->A(S9);
        OAI21_X1_5->B1(S8);
        OAI21_X1_5->B2(S80);
        OAI21_X1_5->ZN(S74);

    NAND2_X1_11 = new NAND2_X1("NAND2_X1_11");
        NAND2_X1_11->A1(S81);
        NAND2_X1_11->A2(S59);
        NAND2_X1_11->ZN(S10);

    NAND2_X1_12 = new NAND2_X1("NAND2_X1_12");
        NAND2_X1_12->A1(S80);
        NAND2_X1_12->A2(S43);
        NAND2_X1_12->ZN(S11);

    OAI21_X1_6 = new OAI21_X1("OAI21_X1_6");
        OAI21_X1_6->A(S11);
        OAI21_X1_6->B1(S10);
        OAI21_X1_6->B2(S80);
        OAI21_X1_6->ZN(S75);

    NAND2_X1_13 = new NAND2_X1("NAND2_X1_13");
        NAND2_X1_13->A1(S81);
        NAND2_X1_13->A2(S60);
        NAND2_X1_13->ZN(S12);

    NAND2_X1_14 = new NAND2_X1("NAND2_X1_14");
        NAND2_X1_14->A1(S80);
        NAND2_X1_14->A2(S44);
        NAND2_X1_14->ZN(S13);

    OAI21_X1_7 = new OAI21_X1("OAI21_X1_7");
        OAI21_X1_7->A(S13);
        OAI21_X1_7->B1(S12);
        OAI21_X1_7->B2(S80);
        OAI21_X1_7->ZN(S76);

    NAND2_X1_15 = new NAND2_X1("NAND2_X1_15");
        NAND2_X1_15->A1(S81);
        NAND2_X1_15->A2(S61);
        NAND2_X1_15->ZN(S14);

    NAND2_X1_16 = new NAND2_X1("NAND2_X1_16");
        NAND2_X1_16->A1(S80);
        NAND2_X1_16->A2(S45);
        NAND2_X1_16->ZN(S15);

    OAI21_X1_8 = new OAI21_X1("OAI21_X1_8");
        OAI21_X1_8->A(S15);
        OAI21_X1_8->B1(S14);
        OAI21_X1_8->B2(S80);
        OAI21_X1_8->ZN(S77);

    NAND2_X1_17 = new NAND2_X1("NAND2_X1_17");
        NAND2_X1_17->A1(S81);
        NAND2_X1_17->A2(S62);
        NAND2_X1_17->ZN(S16);

    NAND2_X1_18 = new NAND2_X1("NAND2_X1_18");
        NAND2_X1_18->A1(S80);
        NAND2_X1_18->A2(S46);
        NAND2_X1_18->ZN(S17);

    OAI21_X1_9 = new OAI21_X1("OAI21_X1_9");
        OAI21_X1_9->A(S17);
        OAI21_X1_9->B1(S16);
        OAI21_X1_9->B2(S80);
        OAI21_X1_9->ZN(S78);

    NAND2_X1_19 = new NAND2_X1("NAND2_X1_19");
        NAND2_X1_19->A1(S81);
        NAND2_X1_19->A2(S63);
        NAND2_X1_19->ZN(S18);

    NAND2_X1_20 = new NAND2_X1("NAND2_X1_20");
        NAND2_X1_20->A1(S80);
        NAND2_X1_20->A2(S47);
        NAND2_X1_20->ZN(S19);

    OAI21_X1_10 = new OAI21_X1("OAI21_X1_10");
        OAI21_X1_10->A(S19);
        OAI21_X1_10->B1(S18);
        OAI21_X1_10->B2(S80);
        OAI21_X1_10->ZN(S79);

    NAND2_X1_21 = new NAND2_X1("NAND2_X1_21");
        NAND2_X1_21->A1(S81);
        NAND2_X1_21->A2(S49);
        NAND2_X1_21->ZN(S20);

    NAND2_X1_22 = new NAND2_X1("NAND2_X1_22");
        NAND2_X1_22->A1(S80);
        NAND2_X1_22->A2(S33);
        NAND2_X1_22->ZN(S21);

    OAI21_X1_11 = new OAI21_X1("OAI21_X1_11");
        OAI21_X1_11->A(S21);
        OAI21_X1_11->B1(S20);
        OAI21_X1_11->B2(S80);
        OAI21_X1_11->ZN(S65);

    NAND2_X1_23 = new NAND2_X1("NAND2_X1_23");
        NAND2_X1_23->A1(S81);
        NAND2_X1_23->A2(S50);
        NAND2_X1_23->ZN(S22);

    NAND2_X1_24 = new NAND2_X1("NAND2_X1_24");
        NAND2_X1_24->A1(S80);
        NAND2_X1_24->A2(S34);
        NAND2_X1_24->ZN(S23);

    OAI21_X1_12 = new OAI21_X1("OAI21_X1_12");
        OAI21_X1_12->A(S23);
        OAI21_X1_12->B1(S22);
        OAI21_X1_12->B2(S80);
        OAI21_X1_12->ZN(S66);

    NAND2_X1_25 = new NAND2_X1("NAND2_X1_25");
        NAND2_X1_25->A1(S81);
        NAND2_X1_25->A2(S51);
        NAND2_X1_25->ZN(S24);

    NAND2_X1_26 = new NAND2_X1("NAND2_X1_26");
        NAND2_X1_26->A1(S80);
        NAND2_X1_26->A2(S35);
        NAND2_X1_26->ZN(S25);

    OAI21_X1_13 = new OAI21_X1("OAI21_X1_13");
        OAI21_X1_13->A(S25);
        OAI21_X1_13->B1(S24);
        OAI21_X1_13->B2(S80);
        OAI21_X1_13->ZN(S67);

    NAND2_X1_27 = new NAND2_X1("NAND2_X1_27");
        NAND2_X1_27->A1(S81);
        NAND2_X1_27->A2(S52);
        NAND2_X1_27->ZN(S26);

    NAND2_X1_28 = new NAND2_X1("NAND2_X1_28");
        NAND2_X1_28->A1(S80);
        NAND2_X1_28->A2(S36);
        NAND2_X1_28->ZN(S27);

    OAI21_X1_14 = new OAI21_X1("OAI21_X1_14");
        OAI21_X1_14->A(S27);
        OAI21_X1_14->B1(S26);
        OAI21_X1_14->B2(S80);
        OAI21_X1_14->ZN(S68);

    NAND2_X1_29 = new NAND2_X1("NAND2_X1_29");
        NAND2_X1_29->A1(S81);
        NAND2_X1_29->A2(S53);
        NAND2_X1_29->ZN(S28);

    NAND2_X1_30 = new NAND2_X1("NAND2_X1_30");
        NAND2_X1_30->A1(S80);
        NAND2_X1_30->A2(S37);
        NAND2_X1_30->ZN(S29);

    OAI21_X1_15 = new OAI21_X1("OAI21_X1_15");
        OAI21_X1_15->A(S29);
        OAI21_X1_15->B1(S28);
        OAI21_X1_15->B2(S80);
        OAI21_X1_15->ZN(S69);

    NAND2_X1_31 = new NAND2_X1("NAND2_X1_31");
        NAND2_X1_31->A1(S81);
        NAND2_X1_31->A2(S54);
        NAND2_X1_31->ZN(S30);

    NAND2_X1_32 = new NAND2_X1("NAND2_X1_32");
        NAND2_X1_32->A1(S80);
        NAND2_X1_32->A2(S38);
        NAND2_X1_32->ZN(S31);

    OAI21_X1_16 = new OAI21_X1("OAI21_X1_16");
        OAI21_X1_16->A(S31);
        OAI21_X1_16->B1(S30);
        OAI21_X1_16->B2(S80);
        OAI21_X1_16->ZN(S70);

    BUF_X1_1 = new BUF_X1("BUF_X1_1");
        BUF_X1_1->A(in1[0]);
        BUF_X1_1->Z(S32);

    BUF_X1_2 = new BUF_X1("BUF_X1_2");
        BUF_X1_2->A(in1[1]);
        BUF_X1_2->Z(S39);

    BUF_X1_3 = new BUF_X1("BUF_X1_3");
        BUF_X1_3->A(in1[10]);
        BUF_X1_3->Z(S33);

    BUF_X1_4 = new BUF_X1("BUF_X1_4");
        BUF_X1_4->A(in1[11]);
        BUF_X1_4->Z(S34);

    BUF_X1_5 = new BUF_X1("BUF_X1_5");
        BUF_X1_5->A(in1[12]);
        BUF_X1_5->Z(S35);

    BUF_X1_6 = new BUF_X1("BUF_X1_6");
        BUF_X1_6->A(in1[13]);
        BUF_X1_6->Z(S36);

    BUF_X1_7 = new BUF_X1("BUF_X1_7");
        BUF_X1_7->A(in1[14]);
        BUF_X1_7->Z(S37);

    BUF_X1_8 = new BUF_X1("BUF_X1_8");
        BUF_X1_8->A(in1[15]);
        BUF_X1_8->Z(S38);

    BUF_X1_9 = new BUF_X1("BUF_X1_9");
        BUF_X1_9->A(in1[2]);
        BUF_X1_9->Z(S40);

    BUF_X1_10 = new BUF_X1("BUF_X1_10");
        BUF_X1_10->A(in1[3]);
        BUF_X1_10->Z(S41);

    BUF_X1_11 = new BUF_X1("BUF_X1_11");
        BUF_X1_11->A(in1[4]);
        BUF_X1_11->Z(S42);

    BUF_X1_12 = new BUF_X1("BUF_X1_12");
        BUF_X1_12->A(in1[5]);
        BUF_X1_12->Z(S43);

    BUF_X1_13 = new BUF_X1("BUF_X1_13");
        BUF_X1_13->A(in1[6]);
        BUF_X1_13->Z(S44);

    BUF_X1_14 = new BUF_X1("BUF_X1_14");
        BUF_X1_14->A(in1[7]);
        BUF_X1_14->Z(S45);

    BUF_X1_15 = new BUF_X1("BUF_X1_15");
        BUF_X1_15->A(in1[8]);
        BUF_X1_15->Z(S46);

    BUF_X1_16 = new BUF_X1("BUF_X1_16");
        BUF_X1_16->A(in1[9]);
        BUF_X1_16->Z(S47);

    BUF_X1_17 = new BUF_X1("BUF_X1_17");
        BUF_X1_17->A(in2[0]);
        BUF_X1_17->Z(S48);

    BUF_X1_18 = new BUF_X1("BUF_X1_18");
        BUF_X1_18->A(in2[1]);
        BUF_X1_18->Z(S55);

    BUF_X1_19 = new BUF_X1("BUF_X1_19");
        BUF_X1_19->A(in2[10]);
        BUF_X1_19->Z(S49);

    BUF_X1_20 = new BUF_X1("BUF_X1_20");
        BUF_X1_20->A(in2[11]);
        BUF_X1_20->Z(S50);

    BUF_X1_21 = new BUF_X1("BUF_X1_21");
        BUF_X1_21->A(in2[12]);
        BUF_X1_21->Z(S51);

    BUF_X1_22 = new BUF_X1("BUF_X1_22");
        BUF_X1_22->A(in2[13]);
        BUF_X1_22->Z(S52);

    BUF_X1_23 = new BUF_X1("BUF_X1_23");
        BUF_X1_23->A(in2[14]);
        BUF_X1_23->Z(S53);

    BUF_X1_24 = new BUF_X1("BUF_X1_24");
        BUF_X1_24->A(in2[15]);
        BUF_X1_24->Z(S54);

    BUF_X1_25 = new BUF_X1("BUF_X1_25");
        BUF_X1_25->A(in2[2]);
        BUF_X1_25->Z(S56);

    BUF_X1_26 = new BUF_X1("BUF_X1_26");
        BUF_X1_26->A(in2[3]);
        BUF_X1_26->Z(S57);

    BUF_X1_27 = new BUF_X1("BUF_X1_27");
        BUF_X1_27->A(in2[4]);
        BUF_X1_27->Z(S58);

    BUF_X1_28 = new BUF_X1("BUF_X1_28");
        BUF_X1_28->A(in2[5]);
        BUF_X1_28->Z(S59);

    BUF_X1_29 = new BUF_X1("BUF_X1_29");
        BUF_X1_29->A(in2[6]);
        BUF_X1_29->Z(S60);

    BUF_X1_30 = new BUF_X1("BUF_X1_30");
        BUF_X1_30->A(in2[7]);
        BUF_X1_30->Z(S61);

    BUF_X1_31 = new BUF_X1("BUF_X1_31");
        BUF_X1_31->A(in2[8]);
        BUF_X1_31->Z(S62);

    BUF_X1_32 = new BUF_X1("BUF_X1_32");
        BUF_X1_32->A(in2[9]);
        BUF_X1_32->Z(S63);

    BUF_X1_33 = new BUF_X1("BUF_X1_33");
        BUF_X1_33->A(S64);
        BUF_X1_33->Z(outmux[0]);

    BUF_X1_34 = new BUF_X1("BUF_X1_34");
        BUF_X1_34->A(S71);
        BUF_X1_34->Z(outmux[1]);

    BUF_X1_35 = new BUF_X1("BUF_X1_35");
        BUF_X1_35->A(S65);
        BUF_X1_35->Z(outmux[10]);

    BUF_X1_36 = new BUF_X1("BUF_X1_36");
        BUF_X1_36->A(S66);
        BUF_X1_36->Z(outmux[11]);

    BUF_X1_37 = new BUF_X1("BUF_X1_37");
        BUF_X1_37->A(S67);
        BUF_X1_37->Z(outmux[12]);

    BUF_X1_38 = new BUF_X1("BUF_X1_38");
        BUF_X1_38->A(S68);
        BUF_X1_38->Z(outmux[13]);

    BUF_X1_39 = new BUF_X1("BUF_X1_39");
        BUF_X1_39->A(S69);
        BUF_X1_39->Z(outmux[14]);

    BUF_X1_40 = new BUF_X1("BUF_X1_40");
        BUF_X1_40->A(S70);
        BUF_X1_40->Z(outmux[15]);

    BUF_X1_41 = new BUF_X1("BUF_X1_41");
        BUF_X1_41->A(S72);
        BUF_X1_41->Z(outmux[2]);

    BUF_X1_42 = new BUF_X1("BUF_X1_42");
        BUF_X1_42->A(S73);
        BUF_X1_42->Z(outmux[3]);

    BUF_X1_43 = new BUF_X1("BUF_X1_43");
        BUF_X1_43->A(S74);
        BUF_X1_43->Z(outmux[4]);

    BUF_X1_44 = new BUF_X1("BUF_X1_44");
        BUF_X1_44->A(S75);
        BUF_X1_44->Z(outmux[5]);

    BUF_X1_45 = new BUF_X1("BUF_X1_45");
        BUF_X1_45->A(S76);
        BUF_X1_45->Z(outmux[6]);

    BUF_X1_46 = new BUF_X1("BUF_X1_46");
        BUF_X1_46->A(S77);
        BUF_X1_46->Z(outmux[7]);

    BUF_X1_47 = new BUF_X1("BUF_X1_47");
        BUF_X1_47->A(S78);
        BUF_X1_47->Z(outmux[8]);

    BUF_X1_48 = new BUF_X1("BUF_X1_48");
        BUF_X1_48->A(S79);
        BUF_X1_48->Z(outmux[9]);

    BUF_X1_49 = new BUF_X1("BUF_X1_49");
        BUF_X1_49->A(sel1);
        BUF_X1_49->Z(S80);

    BUF_X1_50 = new BUF_X1("BUF_X1_50");
        BUF_X1_50->A(sel2);
        BUF_X1_50->Z(S81);


    SC_METHOD(sc_logic_signal_assignment);

    }

    void sc_logic_signal_assignment(void){ 
        sc_logic_1_signal.write(SC_LOGIC_1);
        sc_logic_0_signal.write(SC_LOGIC_0);
    }
};
#endif /* __MUX2OFNBITS_16_H__ */

