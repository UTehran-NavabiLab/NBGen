#include <systemc.h>
#include "Complex_NAgate_45.h"

#include "comp.h"


#ifndef __LLU_H__
#define __LLU_H__
using namespace sc_core;

SC_MODULE( llu ) {

    sc_in<sc_logic> in1[16];
    sc_in<sc_logic> in2[16];
    sc_in<sc_logic> logicand;
    sc_in<sc_logic> onescomp;
    sc_in<sc_logic> twoscomp;
    sc_out<sc_logic> outllu[16];

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
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S82 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S82");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S83 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S83");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> onebartwo = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("onebartwo");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outcomp_0_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outcomp_0_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outcomp_10_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outcomp_10_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outcomp_11_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outcomp_11_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outcomp_12_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outcomp_12_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outcomp_13_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outcomp_13_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outcomp_14_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outcomp_14_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outcomp_15_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outcomp_15_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outcomp_1_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outcomp_1_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outcomp_2_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outcomp_2_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outcomp_3_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outcomp_3_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outcomp_4_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outcomp_4_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outcomp_5_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outcomp_5_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outcomp_6_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outcomp_6_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outcomp_7_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outcomp_7_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outcomp_8_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outcomp_8_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outcomp_9_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outcomp_9_");

    INV_X1* INV_X1_1;
    NOR2_X1* NOR2_X1_1;
    OAI21_X1* OAI21_X1_1;
    NAND3_X1* NAND3_X1_1;
    OAI21_X1* OAI21_X1_2;
    OAI21_X1* OAI21_X1_3;
    NAND3_X1* NAND3_X1_2;
    OAI21_X1* OAI21_X1_4;
    OAI21_X1* OAI21_X1_5;
    NAND3_X1* NAND3_X1_3;
    OAI21_X1* OAI21_X1_6;
    OAI21_X1* OAI21_X1_7;
    NAND3_X1* NAND3_X1_4;
    OAI21_X1* OAI21_X1_8;
    OAI21_X1* OAI21_X1_9;
    NAND3_X1* NAND3_X1_5;
    OAI21_X1* OAI21_X1_10;
    OAI21_X1* OAI21_X1_11;
    NAND3_X1* NAND3_X1_6;
    OAI21_X1* OAI21_X1_12;
    OAI21_X1* OAI21_X1_13;
    NAND3_X1* NAND3_X1_7;
    OAI21_X1* OAI21_X1_14;
    OAI21_X1* OAI21_X1_15;
    NAND3_X1* NAND3_X1_8;
    OAI21_X1* OAI21_X1_16;
    OAI21_X1* OAI21_X1_17;
    NAND3_X1* NAND3_X1_9;
    OAI21_X1* OAI21_X1_18;
    OAI21_X1* OAI21_X1_19;
    NAND3_X1* NAND3_X1_10;
    OAI21_X1* OAI21_X1_20;
    OAI21_X1* OAI21_X1_21;
    NAND3_X1* NAND3_X1_11;
    OAI21_X1* OAI21_X1_22;
    OAI21_X1* OAI21_X1_23;
    NAND3_X1* NAND3_X1_12;
    OAI21_X1* OAI21_X1_24;
    OAI21_X1* OAI21_X1_25;
    NAND3_X1* NAND3_X1_13;
    OAI21_X1* OAI21_X1_26;
    OAI21_X1* OAI21_X1_27;
    NAND3_X1* NAND3_X1_14;
    OAI21_X1* OAI21_X1_28;
    OAI21_X1* OAI21_X1_29;
    NAND3_X1* NAND3_X1_15;
    OAI21_X1* OAI21_X1_30;
    OAI21_X1* OAI21_X1_31;
    NAND3_X1* NAND3_X1_16;
    OAI21_X1* OAI21_X1_32;
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
    BUF_X1* BUF_X1_51;
    comp* complementer;

SC_CTOR( llu ) {
    INV_X1_1 = new INV_X1("INV_X1_1");
        INV_X1_1->A(S83);
        INV_X1_1->ZN(S12);

    NOR2_X1_1 = new NOR2_X1("NOR2_X1_1");
        NOR2_X1_1->A1(S12);
        NOR2_X1_1->A2(S66);
        NOR2_X1_1->ZN(onebartwo);

    OAI21_X1_1 = new OAI21_X1("OAI21_X1_1");
        OAI21_X1_1->A(outcomp_0_);
        OAI21_X1_1->B1(S83);
        OAI21_X1_1->B2(S66);
        OAI21_X1_1->ZN(S13);

    NAND3_X1_1 = new NAND3_X1("NAND3_X1_1");
        NAND3_X1_1->A1(S49);
        NAND3_X1_1->A2(S33);
        NAND3_X1_1->A3(S65);
        NAND3_X1_1->ZN(S14);

    OAI21_X1_2 = new OAI21_X1("OAI21_X1_2");
        OAI21_X1_2->A(S14);
        OAI21_X1_2->B1(S13);
        OAI21_X1_2->B2(S65);
        OAI21_X1_2->ZN(S67);

    OAI21_X1_3 = new OAI21_X1("OAI21_X1_3");
        OAI21_X1_3->A(outcomp_1_);
        OAI21_X1_3->B1(S83);
        OAI21_X1_3->B2(S66);
        OAI21_X1_3->ZN(S15);

    NAND3_X1_2 = new NAND3_X1("NAND3_X1_2");
        NAND3_X1_2->A1(S65);
        NAND3_X1_2->A2(S56);
        NAND3_X1_2->A3(S40);
        NAND3_X1_2->ZN(S16);

    OAI21_X1_4 = new OAI21_X1("OAI21_X1_4");
        OAI21_X1_4->A(S16);
        OAI21_X1_4->B1(S15);
        OAI21_X1_4->B2(S65);
        OAI21_X1_4->ZN(S74);

    OAI21_X1_5 = new OAI21_X1("OAI21_X1_5");
        OAI21_X1_5->A(outcomp_2_);
        OAI21_X1_5->B1(S83);
        OAI21_X1_5->B2(S66);
        OAI21_X1_5->ZN(S17);

    NAND3_X1_3 = new NAND3_X1("NAND3_X1_3");
        NAND3_X1_3->A1(S65);
        NAND3_X1_3->A2(S57);
        NAND3_X1_3->A3(S41);
        NAND3_X1_3->ZN(S18);

    OAI21_X1_6 = new OAI21_X1("OAI21_X1_6");
        OAI21_X1_6->A(S18);
        OAI21_X1_6->B1(S17);
        OAI21_X1_6->B2(S65);
        OAI21_X1_6->ZN(S75);

    OAI21_X1_7 = new OAI21_X1("OAI21_X1_7");
        OAI21_X1_7->A(outcomp_3_);
        OAI21_X1_7->B1(S83);
        OAI21_X1_7->B2(S66);
        OAI21_X1_7->ZN(S19);

    NAND3_X1_4 = new NAND3_X1("NAND3_X1_4");
        NAND3_X1_4->A1(S65);
        NAND3_X1_4->A2(S58);
        NAND3_X1_4->A3(S42);
        NAND3_X1_4->ZN(S20);

    OAI21_X1_8 = new OAI21_X1("OAI21_X1_8");
        OAI21_X1_8->A(S20);
        OAI21_X1_8->B1(S19);
        OAI21_X1_8->B2(S65);
        OAI21_X1_8->ZN(S76);

    OAI21_X1_9 = new OAI21_X1("OAI21_X1_9");
        OAI21_X1_9->A(outcomp_4_);
        OAI21_X1_9->B1(S83);
        OAI21_X1_9->B2(S66);
        OAI21_X1_9->ZN(S21);

    NAND3_X1_5 = new NAND3_X1("NAND3_X1_5");
        NAND3_X1_5->A1(S65);
        NAND3_X1_5->A2(S59);
        NAND3_X1_5->A3(S43);
        NAND3_X1_5->ZN(S22);

    OAI21_X1_10 = new OAI21_X1("OAI21_X1_10");
        OAI21_X1_10->A(S22);
        OAI21_X1_10->B1(S21);
        OAI21_X1_10->B2(S65);
        OAI21_X1_10->ZN(S77);

    OAI21_X1_11 = new OAI21_X1("OAI21_X1_11");
        OAI21_X1_11->A(outcomp_5_);
        OAI21_X1_11->B1(S83);
        OAI21_X1_11->B2(S66);
        OAI21_X1_11->ZN(S23);

    NAND3_X1_6 = new NAND3_X1("NAND3_X1_6");
        NAND3_X1_6->A1(S65);
        NAND3_X1_6->A2(S60);
        NAND3_X1_6->A3(S44);
        NAND3_X1_6->ZN(S24);

    OAI21_X1_12 = new OAI21_X1("OAI21_X1_12");
        OAI21_X1_12->A(S24);
        OAI21_X1_12->B1(S23);
        OAI21_X1_12->B2(S65);
        OAI21_X1_12->ZN(S78);

    OAI21_X1_13 = new OAI21_X1("OAI21_X1_13");
        OAI21_X1_13->A(outcomp_6_);
        OAI21_X1_13->B1(S83);
        OAI21_X1_13->B2(S66);
        OAI21_X1_13->ZN(S25);

    NAND3_X1_7 = new NAND3_X1("NAND3_X1_7");
        NAND3_X1_7->A1(S65);
        NAND3_X1_7->A2(S61);
        NAND3_X1_7->A3(S45);
        NAND3_X1_7->ZN(S26);

    OAI21_X1_14 = new OAI21_X1("OAI21_X1_14");
        OAI21_X1_14->A(S26);
        OAI21_X1_14->B1(S25);
        OAI21_X1_14->B2(S65);
        OAI21_X1_14->ZN(S79);

    OAI21_X1_15 = new OAI21_X1("OAI21_X1_15");
        OAI21_X1_15->A(outcomp_7_);
        OAI21_X1_15->B1(S83);
        OAI21_X1_15->B2(S66);
        OAI21_X1_15->ZN(S27);

    NAND3_X1_8 = new NAND3_X1("NAND3_X1_8");
        NAND3_X1_8->A1(S65);
        NAND3_X1_8->A2(S62);
        NAND3_X1_8->A3(S46);
        NAND3_X1_8->ZN(S28);

    OAI21_X1_16 = new OAI21_X1("OAI21_X1_16");
        OAI21_X1_16->A(S28);
        OAI21_X1_16->B1(S27);
        OAI21_X1_16->B2(S65);
        OAI21_X1_16->ZN(S80);

    OAI21_X1_17 = new OAI21_X1("OAI21_X1_17");
        OAI21_X1_17->A(outcomp_8_);
        OAI21_X1_17->B1(S83);
        OAI21_X1_17->B2(S66);
        OAI21_X1_17->ZN(S29);

    NAND3_X1_9 = new NAND3_X1("NAND3_X1_9");
        NAND3_X1_9->A1(S65);
        NAND3_X1_9->A2(S63);
        NAND3_X1_9->A3(S47);
        NAND3_X1_9->ZN(S30);

    OAI21_X1_18 = new OAI21_X1("OAI21_X1_18");
        OAI21_X1_18->A(S30);
        OAI21_X1_18->B1(S29);
        OAI21_X1_18->B2(S65);
        OAI21_X1_18->ZN(S81);

    OAI21_X1_19 = new OAI21_X1("OAI21_X1_19");
        OAI21_X1_19->A(outcomp_9_);
        OAI21_X1_19->B1(S83);
        OAI21_X1_19->B2(S66);
        OAI21_X1_19->ZN(S31);

    NAND3_X1_10 = new NAND3_X1("NAND3_X1_10");
        NAND3_X1_10->A1(S65);
        NAND3_X1_10->A2(S64);
        NAND3_X1_10->A3(S48);
        NAND3_X1_10->ZN(S32);

    OAI21_X1_20 = new OAI21_X1("OAI21_X1_20");
        OAI21_X1_20->A(S32);
        OAI21_X1_20->B1(S31);
        OAI21_X1_20->B2(S65);
        OAI21_X1_20->ZN(S82);

    OAI21_X1_21 = new OAI21_X1("OAI21_X1_21");
        OAI21_X1_21->A(outcomp_10_);
        OAI21_X1_21->B1(S83);
        OAI21_X1_21->B2(S66);
        OAI21_X1_21->ZN(S0);

    NAND3_X1_11 = new NAND3_X1("NAND3_X1_11");
        NAND3_X1_11->A1(S65);
        NAND3_X1_11->A2(S50);
        NAND3_X1_11->A3(S34);
        NAND3_X1_11->ZN(S1);

    OAI21_X1_22 = new OAI21_X1("OAI21_X1_22");
        OAI21_X1_22->A(S1);
        OAI21_X1_22->B1(S0);
        OAI21_X1_22->B2(S65);
        OAI21_X1_22->ZN(S68);

    OAI21_X1_23 = new OAI21_X1("OAI21_X1_23");
        OAI21_X1_23->A(outcomp_11_);
        OAI21_X1_23->B1(S83);
        OAI21_X1_23->B2(S66);
        OAI21_X1_23->ZN(S2);

    NAND3_X1_12 = new NAND3_X1("NAND3_X1_12");
        NAND3_X1_12->A1(S65);
        NAND3_X1_12->A2(S51);
        NAND3_X1_12->A3(S35);
        NAND3_X1_12->ZN(S3);

    OAI21_X1_24 = new OAI21_X1("OAI21_X1_24");
        OAI21_X1_24->A(S3);
        OAI21_X1_24->B1(S2);
        OAI21_X1_24->B2(S65);
        OAI21_X1_24->ZN(S69);

    OAI21_X1_25 = new OAI21_X1("OAI21_X1_25");
        OAI21_X1_25->A(outcomp_12_);
        OAI21_X1_25->B1(S83);
        OAI21_X1_25->B2(S66);
        OAI21_X1_25->ZN(S4);

    NAND3_X1_13 = new NAND3_X1("NAND3_X1_13");
        NAND3_X1_13->A1(S65);
        NAND3_X1_13->A2(S52);
        NAND3_X1_13->A3(S36);
        NAND3_X1_13->ZN(S5);

    OAI21_X1_26 = new OAI21_X1("OAI21_X1_26");
        OAI21_X1_26->A(S5);
        OAI21_X1_26->B1(S4);
        OAI21_X1_26->B2(S65);
        OAI21_X1_26->ZN(S70);

    OAI21_X1_27 = new OAI21_X1("OAI21_X1_27");
        OAI21_X1_27->A(outcomp_13_);
        OAI21_X1_27->B1(S83);
        OAI21_X1_27->B2(S66);
        OAI21_X1_27->ZN(S6);

    NAND3_X1_14 = new NAND3_X1("NAND3_X1_14");
        NAND3_X1_14->A1(S65);
        NAND3_X1_14->A2(S53);
        NAND3_X1_14->A3(S37);
        NAND3_X1_14->ZN(S7);

    OAI21_X1_28 = new OAI21_X1("OAI21_X1_28");
        OAI21_X1_28->A(S7);
        OAI21_X1_28->B1(S6);
        OAI21_X1_28->B2(S65);
        OAI21_X1_28->ZN(S71);

    OAI21_X1_29 = new OAI21_X1("OAI21_X1_29");
        OAI21_X1_29->A(outcomp_14_);
        OAI21_X1_29->B1(S83);
        OAI21_X1_29->B2(S66);
        OAI21_X1_29->ZN(S8);

    NAND3_X1_15 = new NAND3_X1("NAND3_X1_15");
        NAND3_X1_15->A1(S65);
        NAND3_X1_15->A2(S54);
        NAND3_X1_15->A3(S38);
        NAND3_X1_15->ZN(S9);

    OAI21_X1_30 = new OAI21_X1("OAI21_X1_30");
        OAI21_X1_30->A(S9);
        OAI21_X1_30->B1(S8);
        OAI21_X1_30->B2(S65);
        OAI21_X1_30->ZN(S72);

    OAI21_X1_31 = new OAI21_X1("OAI21_X1_31");
        OAI21_X1_31->A(outcomp_15_);
        OAI21_X1_31->B1(S83);
        OAI21_X1_31->B2(S66);
        OAI21_X1_31->ZN(S10);

    NAND3_X1_16 = new NAND3_X1("NAND3_X1_16");
        NAND3_X1_16->A1(S65);
        NAND3_X1_16->A2(S55);
        NAND3_X1_16->A3(S39);
        NAND3_X1_16->ZN(S11);

    OAI21_X1_32 = new OAI21_X1("OAI21_X1_32");
        OAI21_X1_32->A(S11);
        OAI21_X1_32->B1(S10);
        OAI21_X1_32->B2(S65);
        OAI21_X1_32->ZN(S73);

    BUF_X1_1 = new BUF_X1("BUF_X1_1");
        BUF_X1_1->A(in1[0]);
        BUF_X1_1->Z(S33);

    BUF_X1_2 = new BUF_X1("BUF_X1_2");
        BUF_X1_2->A(in1[1]);
        BUF_X1_2->Z(S40);

    BUF_X1_3 = new BUF_X1("BUF_X1_3");
        BUF_X1_3->A(in1[10]);
        BUF_X1_3->Z(S34);

    BUF_X1_4 = new BUF_X1("BUF_X1_4");
        BUF_X1_4->A(in1[11]);
        BUF_X1_4->Z(S35);

    BUF_X1_5 = new BUF_X1("BUF_X1_5");
        BUF_X1_5->A(in1[12]);
        BUF_X1_5->Z(S36);

    BUF_X1_6 = new BUF_X1("BUF_X1_6");
        BUF_X1_6->A(in1[13]);
        BUF_X1_6->Z(S37);

    BUF_X1_7 = new BUF_X1("BUF_X1_7");
        BUF_X1_7->A(in1[14]);
        BUF_X1_7->Z(S38);

    BUF_X1_8 = new BUF_X1("BUF_X1_8");
        BUF_X1_8->A(in1[15]);
        BUF_X1_8->Z(S39);

    BUF_X1_9 = new BUF_X1("BUF_X1_9");
        BUF_X1_9->A(in1[2]);
        BUF_X1_9->Z(S41);

    BUF_X1_10 = new BUF_X1("BUF_X1_10");
        BUF_X1_10->A(in1[3]);
        BUF_X1_10->Z(S42);

    BUF_X1_11 = new BUF_X1("BUF_X1_11");
        BUF_X1_11->A(in1[4]);
        BUF_X1_11->Z(S43);

    BUF_X1_12 = new BUF_X1("BUF_X1_12");
        BUF_X1_12->A(in1[5]);
        BUF_X1_12->Z(S44);

    BUF_X1_13 = new BUF_X1("BUF_X1_13");
        BUF_X1_13->A(in1[6]);
        BUF_X1_13->Z(S45);

    BUF_X1_14 = new BUF_X1("BUF_X1_14");
        BUF_X1_14->A(in1[7]);
        BUF_X1_14->Z(S46);

    BUF_X1_15 = new BUF_X1("BUF_X1_15");
        BUF_X1_15->A(in1[8]);
        BUF_X1_15->Z(S47);

    BUF_X1_16 = new BUF_X1("BUF_X1_16");
        BUF_X1_16->A(in1[9]);
        BUF_X1_16->Z(S48);

    BUF_X1_17 = new BUF_X1("BUF_X1_17");
        BUF_X1_17->A(in2[0]);
        BUF_X1_17->Z(S49);

    BUF_X1_18 = new BUF_X1("BUF_X1_18");
        BUF_X1_18->A(in2[1]);
        BUF_X1_18->Z(S56);

    BUF_X1_19 = new BUF_X1("BUF_X1_19");
        BUF_X1_19->A(in2[10]);
        BUF_X1_19->Z(S50);

    BUF_X1_20 = new BUF_X1("BUF_X1_20");
        BUF_X1_20->A(in2[11]);
        BUF_X1_20->Z(S51);

    BUF_X1_21 = new BUF_X1("BUF_X1_21");
        BUF_X1_21->A(in2[12]);
        BUF_X1_21->Z(S52);

    BUF_X1_22 = new BUF_X1("BUF_X1_22");
        BUF_X1_22->A(in2[13]);
        BUF_X1_22->Z(S53);

    BUF_X1_23 = new BUF_X1("BUF_X1_23");
        BUF_X1_23->A(in2[14]);
        BUF_X1_23->Z(S54);

    BUF_X1_24 = new BUF_X1("BUF_X1_24");
        BUF_X1_24->A(in2[15]);
        BUF_X1_24->Z(S55);

    BUF_X1_25 = new BUF_X1("BUF_X1_25");
        BUF_X1_25->A(in2[2]);
        BUF_X1_25->Z(S57);

    BUF_X1_26 = new BUF_X1("BUF_X1_26");
        BUF_X1_26->A(in2[3]);
        BUF_X1_26->Z(S58);

    BUF_X1_27 = new BUF_X1("BUF_X1_27");
        BUF_X1_27->A(in2[4]);
        BUF_X1_27->Z(S59);

    BUF_X1_28 = new BUF_X1("BUF_X1_28");
        BUF_X1_28->A(in2[5]);
        BUF_X1_28->Z(S60);

    BUF_X1_29 = new BUF_X1("BUF_X1_29");
        BUF_X1_29->A(in2[6]);
        BUF_X1_29->Z(S61);

    BUF_X1_30 = new BUF_X1("BUF_X1_30");
        BUF_X1_30->A(in2[7]);
        BUF_X1_30->Z(S62);

    BUF_X1_31 = new BUF_X1("BUF_X1_31");
        BUF_X1_31->A(in2[8]);
        BUF_X1_31->Z(S63);

    BUF_X1_32 = new BUF_X1("BUF_X1_32");
        BUF_X1_32->A(in2[9]);
        BUF_X1_32->Z(S64);

    BUF_X1_33 = new BUF_X1("BUF_X1_33");
        BUF_X1_33->A(logicand);
        BUF_X1_33->Z(S65);

    BUF_X1_34 = new BUF_X1("BUF_X1_34");
        BUF_X1_34->A(onescomp);
        BUF_X1_34->Z(S66);

    BUF_X1_35 = new BUF_X1("BUF_X1_35");
        BUF_X1_35->A(S67);
        BUF_X1_35->Z(outllu[0]);

    BUF_X1_36 = new BUF_X1("BUF_X1_36");
        BUF_X1_36->A(S74);
        BUF_X1_36->Z(outllu[1]);

    BUF_X1_37 = new BUF_X1("BUF_X1_37");
        BUF_X1_37->A(S68);
        BUF_X1_37->Z(outllu[10]);

    BUF_X1_38 = new BUF_X1("BUF_X1_38");
        BUF_X1_38->A(S69);
        BUF_X1_38->Z(outllu[11]);

    BUF_X1_39 = new BUF_X1("BUF_X1_39");
        BUF_X1_39->A(S70);
        BUF_X1_39->Z(outllu[12]);

    BUF_X1_40 = new BUF_X1("BUF_X1_40");
        BUF_X1_40->A(S71);
        BUF_X1_40->Z(outllu[13]);

    BUF_X1_41 = new BUF_X1("BUF_X1_41");
        BUF_X1_41->A(S72);
        BUF_X1_41->Z(outllu[14]);

    BUF_X1_42 = new BUF_X1("BUF_X1_42");
        BUF_X1_42->A(S73);
        BUF_X1_42->Z(outllu[15]);

    BUF_X1_43 = new BUF_X1("BUF_X1_43");
        BUF_X1_43->A(S75);
        BUF_X1_43->Z(outllu[2]);

    BUF_X1_44 = new BUF_X1("BUF_X1_44");
        BUF_X1_44->A(S76);
        BUF_X1_44->Z(outllu[3]);

    BUF_X1_45 = new BUF_X1("BUF_X1_45");
        BUF_X1_45->A(S77);
        BUF_X1_45->Z(outllu[4]);

    BUF_X1_46 = new BUF_X1("BUF_X1_46");
        BUF_X1_46->A(S78);
        BUF_X1_46->Z(outllu[5]);

    BUF_X1_47 = new BUF_X1("BUF_X1_47");
        BUF_X1_47->A(S79);
        BUF_X1_47->Z(outllu[6]);

    BUF_X1_48 = new BUF_X1("BUF_X1_48");
        BUF_X1_48->A(S80);
        BUF_X1_48->Z(outllu[7]);

    BUF_X1_49 = new BUF_X1("BUF_X1_49");
        BUF_X1_49->A(S81);
        BUF_X1_49->Z(outllu[8]);

    BUF_X1_50 = new BUF_X1("BUF_X1_50");
        BUF_X1_50->A(S82);
        BUF_X1_50->Z(outllu[9]);

    BUF_X1_51 = new BUF_X1("BUF_X1_51");
        BUF_X1_51->A(twoscomp);
        BUF_X1_51->Z(S83);

    complementer = new comp("complementer");
        complementer->incomp[0](S33);
        complementer->incomp[1](S40);
        complementer->incomp[2](S41);
        complementer->incomp[3](S42);
        complementer->incomp[4](S43);
        complementer->incomp[5](S44);
        complementer->incomp[6](S45);
        complementer->incomp[7](S46);
        complementer->incomp[8](S47);
        complementer->incomp[9](S48);
        complementer->incomp[10](S34);
        complementer->incomp[11](S35);
        complementer->incomp[12](S36);
        complementer->incomp[13](S37);
        complementer->incomp[14](S38);
        complementer->incomp[15](S39);
        complementer->onebartwo(onebartwo);
        complementer->outcomp[0](outcomp_0_);
        complementer->outcomp[1](outcomp_1_);
        complementer->outcomp[2](outcomp_2_);
        complementer->outcomp[3](outcomp_3_);
        complementer->outcomp[4](outcomp_4_);
        complementer->outcomp[5](outcomp_5_);
        complementer->outcomp[6](outcomp_6_);
        complementer->outcomp[7](outcomp_7_);
        complementer->outcomp[8](outcomp_8_);
        complementer->outcomp[9](outcomp_9_);
        complementer->outcomp[10](outcomp_10_);
        complementer->outcomp[11](outcomp_11_);
        complementer->outcomp[12](outcomp_12_);
        complementer->outcomp[13](outcomp_13_);
        complementer->outcomp[14](outcomp_14_);
        complementer->outcomp[15](outcomp_15_);


    SC_METHOD(sc_logic_signal_assignment);

    }

    void sc_logic_signal_assignment(void){ 
        sc_logic_1_signal.write(SC_LOGIC_1);
        sc_logic_0_signal.write(SC_LOGIC_0);
    }
};
#endif /* __LLU_H__ */

