#include <systemc.h>
#include "Complex_NAgate_45.h"



#ifndef __CMP_H__
#define __CMP_H__
using namespace sc_core;

SC_MODULE( cmp ) {

    sc_in<sc_logic> in1[16];
    sc_in<sc_logic> in2[16];
    sc_out<sc_logic> eq;
    sc_out<sc_logic> gt;

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
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S84 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S84");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S85 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S85");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S86 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S86");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S87 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S87");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S88 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S88");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S89 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S89");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S90 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S90");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S91 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S91");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S92 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S92");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S93 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S93");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S94 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S94");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S95 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S95");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S96 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S96");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S97 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S97");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S98 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S98");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S99 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S99");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S100 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S100");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S101 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S101");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S102 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S102");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S103 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S103");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S104 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S104");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S105 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S105");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S106 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S106");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S107 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S107");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S108 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S108");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S109 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S109");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S110 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S110");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S111 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S111");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S112 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S112");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S113 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S113");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S114 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S114");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S115 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S115");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S116 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S116");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S117 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S117");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S118 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S118");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S119 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S119");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S120 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S120");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S121 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S121");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S122 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S122");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S123 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S123");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S124 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S124");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S125 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S125");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S126 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S126");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S127 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S127");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S128 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S128");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S129 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S129");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S130 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S130");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S131 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S131");

    INV_X1* INV_X1_1;
    NAND2_X1* NAND2_X1_1;
    INV_X1* INV_X1_2;
    NAND2_X1* NAND2_X1_2;
    INV_X1* INV_X1_3;
    NAND2_X1* NAND2_X1_3;
    INV_X1* INV_X1_4;
    NAND2_X1* NAND2_X1_4;
    AND4_X1* AND4_X1_1;
    INV_X1* INV_X1_5;
    NAND2_X1* NAND2_X1_5;
    INV_X1* INV_X1_6;
    NAND2_X1* NAND2_X1_6;
    INV_X1* INV_X1_7;
    NAND2_X1* NAND2_X1_7;
    INV_X1* INV_X1_8;
    NAND2_X1* NAND2_X1_8;
    AND4_X1* AND4_X1_2;
    INV_X1* INV_X1_9;
    NAND2_X1* NAND2_X1_9;
    INV_X1* INV_X1_10;
    NAND2_X1* NAND2_X1_10;
    INV_X1* INV_X1_11;
    NAND2_X1* NAND2_X1_11;
    INV_X1* INV_X1_12;
    NAND2_X1* NAND2_X1_12;
    NAND4_X1* NAND4_X1_1;
    INV_X1* INV_X1_13;
    INV_X1* INV_X1_14;
    INV_X1* INV_X1_15;
    AOI22_X1* AOI22_X1_1;
    INV_X1* INV_X1_16;
    INV_X1* INV_X1_17;
    AOI22_X1* AOI22_X1_2;
    AND2_X1* AND2_X1_1;
    NAND4_X1* NAND4_X1_2;
    XNOR2_X1* XNOR2_X1_1;
    XNOR2_X1* XNOR2_X1_2;
    NAND2_X1* NAND2_X1_13;
    INV_X1* INV_X1_18;
    INV_X1* INV_X1_19;
    INV_X1* INV_X1_20;
    AOI22_X1* AOI22_X1_3;
    INV_X1* INV_X1_21;
    INV_X1* INV_X1_22;
    AOI22_X1* AOI22_X1_4;
    AND2_X1* AND2_X1_2;
    XNOR2_X1* XNOR2_X1_3;
    XNOR2_X1* XNOR2_X1_4;
    AND2_X1* AND2_X1_3;
    INV_X1* INV_X1_23;
    INV_X1* INV_X1_24;
    OAI22_X1* OAI22_X1_1;
    INV_X1* INV_X1_25;
    NOR2_X1* NOR2_X1_1;
    INV_X1* INV_X1_26;
    NOR2_X1* NOR2_X1_2;
    NOR3_X1* NOR3_X1_1;
    NAND4_X1* NAND4_X1_3;
    NOR2_X1* NOR2_X1_3;
    NAND2_X1* NAND2_X1_14;
    AND2_X1* AND2_X1_4;
    AND2_X1* AND2_X1_5;
    NAND4_X1* NAND4_X1_4;
    NOR2_X1* NOR2_X1_4;
    NAND4_X1* NAND4_X1_5;
    AOI22_X1* AOI22_X1_5;
    OAI211_X1* OAI211_X1_1;
    INV_X1* INV_X1_27;
    NOR2_X1* NOR2_X1_5;
    INV_X1* INV_X1_28;
    NOR2_X1* NOR2_X1_6;
    AOI21_X1* AOI21_X1_1;
    AOI21_X1* AOI21_X1_2;
    NOR2_X1* NOR2_X1_7;
    NAND2_X1* NAND2_X1_15;
    NOR2_X1* NOR2_X1_8;
    AOI21_X1* AOI21_X1_3;
    INV_X1* INV_X1_29;
    NOR2_X1* NOR2_X1_9;
    INV_X1* INV_X1_30;
    NOR2_X1* NOR2_X1_10;
    AOI21_X1* AOI21_X1_4;
    OAI21_X1* OAI21_X1_1;
    OAI21_X1* OAI21_X1_2;
    INV_X1* INV_X1_31;
    NOR2_X1* NOR2_X1_11;
    NAND2_X1* NAND2_X1_16;
    NOR2_X1* NOR2_X1_12;
    AOI21_X1* AOI21_X1_5;
    NAND3_X1* NAND3_X1_1;
    OAI211_X1* OAI211_X1_2;
    NAND4_X1* NAND4_X1_6;
    NOR2_X1* NOR2_X1_13;
    INV_X1* INV_X1_32;
    AOI21_X1* AOI21_X1_6;
    NAND3_X1* NAND3_X1_2;
    OAI211_X1* OAI211_X1_3;
    AOI21_X1* AOI21_X1_7;
    AOI21_X1* AOI21_X1_8;
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

SC_CTOR( cmp ) {
    INV_X1_1 = new INV_X1("INV_X1_1");
        INV_X1_1->A(S106);
        INV_X1_1->ZN(S34);

    NAND2_X1_1 = new NAND2_X1("NAND2_X1_1");
        NAND2_X1_1->A1(S34);
        NAND2_X1_1->A2(S122);
        NAND2_X1_1->ZN(S35);

    INV_X1_2 = new INV_X1("INV_X1_2");
        INV_X1_2->A(S121);
        INV_X1_2->ZN(S36);

    NAND2_X1_2 = new NAND2_X1("NAND2_X1_2");
        NAND2_X1_2->A1(S36);
        NAND2_X1_2->A2(S105);
        NAND2_X1_2->ZN(S37);

    INV_X1_3 = new INV_X1("INV_X1_3");
        INV_X1_3->A(S122);
        INV_X1_3->ZN(S38);

    NAND2_X1_3 = new NAND2_X1("NAND2_X1_3");
        NAND2_X1_3->A1(S38);
        NAND2_X1_3->A2(S106);
        NAND2_X1_3->ZN(S39);

    INV_X1_4 = new INV_X1("INV_X1_4");
        INV_X1_4->A(S105);
        INV_X1_4->ZN(S40);

    NAND2_X1_4 = new NAND2_X1("NAND2_X1_4");
        NAND2_X1_4->A1(S40);
        NAND2_X1_4->A2(S121);
        NAND2_X1_4->ZN(S41);

    AND4_X1_1 = new AND4_X1("AND4_X1_1");
        AND4_X1_1->A1(S35);
        AND4_X1_1->A2(S39);
        AND4_X1_1->A3(S41);
        AND4_X1_1->A4(S37);
        AND4_X1_1->ZN(S42);

    INV_X1_5 = new INV_X1("INV_X1_5");
        INV_X1_5->A(S104);
        INV_X1_5->ZN(S43);

    NAND2_X1_5 = new NAND2_X1("NAND2_X1_5");
        NAND2_X1_5->A1(S43);
        NAND2_X1_5->A2(S120);
        NAND2_X1_5->ZN(S44);

    INV_X1_6 = new INV_X1("INV_X1_6");
        INV_X1_6->A(S119);
        INV_X1_6->ZN(S45);

    NAND2_X1_6 = new NAND2_X1("NAND2_X1_6");
        NAND2_X1_6->A1(S45);
        NAND2_X1_6->A2(S103);
        NAND2_X1_6->ZN(S46);

    INV_X1_7 = new INV_X1("INV_X1_7");
        INV_X1_7->A(S120);
        INV_X1_7->ZN(S47);

    NAND2_X1_7 = new NAND2_X1("NAND2_X1_7");
        NAND2_X1_7->A1(S47);
        NAND2_X1_7->A2(S104);
        NAND2_X1_7->ZN(S48);

    INV_X1_8 = new INV_X1("INV_X1_8");
        INV_X1_8->A(S103);
        INV_X1_8->ZN(S49);

    NAND2_X1_8 = new NAND2_X1("NAND2_X1_8");
        NAND2_X1_8->A1(S49);
        NAND2_X1_8->A2(S119);
        NAND2_X1_8->ZN(S50);

    AND4_X1_2 = new AND4_X1("AND4_X1_2");
        AND4_X1_2->A1(S44);
        AND4_X1_2->A2(S48);
        AND4_X1_2->A3(S50);
        AND4_X1_2->A4(S46);
        AND4_X1_2->ZN(S51);

    INV_X1_9 = new INV_X1("INV_X1_9");
        INV_X1_9->A(S101);
        INV_X1_9->ZN(S52);

    NAND2_X1_9 = new NAND2_X1("NAND2_X1_9");
        NAND2_X1_9->A1(S52);
        NAND2_X1_9->A2(S117);
        NAND2_X1_9->ZN(S53);

    INV_X1_10 = new INV_X1("INV_X1_10");
        INV_X1_10->A(S117);
        INV_X1_10->ZN(S54);

    NAND2_X1_10 = new NAND2_X1("NAND2_X1_10");
        NAND2_X1_10->A1(S54);
        NAND2_X1_10->A2(S101);
        NAND2_X1_10->ZN(S55);

    INV_X1_11 = new INV_X1("INV_X1_11");
        INV_X1_11->A(S102);
        INV_X1_11->ZN(S56);

    NAND2_X1_11 = new NAND2_X1("NAND2_X1_11");
        NAND2_X1_11->A1(S56);
        NAND2_X1_11->A2(S118);
        NAND2_X1_11->ZN(S57);

    INV_X1_12 = new INV_X1("INV_X1_12");
        INV_X1_12->A(S118);
        INV_X1_12->ZN(S58);

    NAND2_X1_12 = new NAND2_X1("NAND2_X1_12");
        NAND2_X1_12->A1(S58);
        NAND2_X1_12->A2(S102);
        NAND2_X1_12->ZN(S59);

    NAND4_X1_1 = new NAND4_X1("NAND4_X1_1");
        NAND4_X1_1->A1(S57);
        NAND4_X1_1->A2(S59);
        NAND4_X1_1->A3(S53);
        NAND4_X1_1->A4(S55);
        NAND4_X1_1->ZN(S60);

    INV_X1_13 = new INV_X1("INV_X1_13");
        INV_X1_13->A(S60);
        INV_X1_13->ZN(S61);

    INV_X1_14 = new INV_X1("INV_X1_14");
        INV_X1_14->A(S131);
        INV_X1_14->ZN(S62);

    INV_X1_15 = new INV_X1("INV_X1_15");
        INV_X1_15->A(S114);
        INV_X1_15->ZN(S63);

    AOI22_X1_1 = new AOI22_X1("AOI22_X1_1");
        AOI22_X1_1->A1(S62);
        AOI22_X1_1->A2(S115);
        AOI22_X1_1->B1(S63);
        AOI22_X1_1->B2(S130);
        AOI22_X1_1->ZN(S64);

    INV_X1_16 = new INV_X1("INV_X1_16");
        INV_X1_16->A(S115);
        INV_X1_16->ZN(S65);

    INV_X1_17 = new INV_X1("INV_X1_17");
        INV_X1_17->A(S130);
        INV_X1_17->ZN(S66);

    AOI22_X1_2 = new AOI22_X1("AOI22_X1_2");
        AOI22_X1_2->A1(S66);
        AOI22_X1_2->A2(S114);
        AOI22_X1_2->B1(S65);
        AOI22_X1_2->B2(S131);
        AOI22_X1_2->ZN(S67);

    AND2_X1_1 = new AND2_X1("AND2_X1_1");
        AND2_X1_1->A1(S67);
        AND2_X1_1->A2(S64);
        AND2_X1_1->ZN(S68);

    NAND4_X1_2 = new NAND4_X1("NAND4_X1_2");
        NAND4_X1_2->A1(S68);
        NAND4_X1_2->A2(S61);
        NAND4_X1_2->A3(S51);
        NAND4_X1_2->A4(S42);
        NAND4_X1_2->ZN(S69);

    XNOR2_X1_1 = new XNOR2_X1("XNOR2_X1_1");
        XNOR2_X1_1->A(S129);
        XNOR2_X1_1->B(S113);
        XNOR2_X1_1->ZN(S70);

    XNOR2_X1_2 = new XNOR2_X1("XNOR2_X1_2");
        XNOR2_X1_2->A(S128);
        XNOR2_X1_2->B(S112);
        XNOR2_X1_2->ZN(S71);

    NAND2_X1_13 = new NAND2_X1("NAND2_X1_13");
        NAND2_X1_13->A1(S70);
        NAND2_X1_13->A2(S71);
        NAND2_X1_13->ZN(S72);

    INV_X1_18 = new INV_X1("INV_X1_18");
        INV_X1_18->A(S72);
        INV_X1_18->ZN(S73);

    INV_X1_19 = new INV_X1("INV_X1_19");
        INV_X1_19->A(S111);
        INV_X1_19->ZN(S74);

    INV_X1_20 = new INV_X1("INV_X1_20");
        INV_X1_20->A(S126);
        INV_X1_20->ZN(S75);

    AOI22_X1_3 = new AOI22_X1("AOI22_X1_3");
        AOI22_X1_3->A1(S75);
        AOI22_X1_3->A2(S110);
        AOI22_X1_3->B1(S74);
        AOI22_X1_3->B2(S127);
        AOI22_X1_3->ZN(S76);

    INV_X1_21 = new INV_X1("INV_X1_21");
        INV_X1_21->A(S127);
        INV_X1_21->ZN(S77);

    INV_X1_22 = new INV_X1("INV_X1_22");
        INV_X1_22->A(S110);
        INV_X1_22->ZN(S78);

    AOI22_X1_4 = new AOI22_X1("AOI22_X1_4");
        AOI22_X1_4->A1(S77);
        AOI22_X1_4->A2(S111);
        AOI22_X1_4->B1(S78);
        AOI22_X1_4->B2(S126);
        AOI22_X1_4->ZN(S79);

    AND2_X1_2 = new AND2_X1("AND2_X1_2");
        AND2_X1_2->A1(S79);
        AND2_X1_2->A2(S76);
        AND2_X1_2->ZN(S80);

    XNOR2_X1_3 = new XNOR2_X1("XNOR2_X1_3");
        XNOR2_X1_3->A(S125);
        XNOR2_X1_3->B(S109);
        XNOR2_X1_3->ZN(S81);

    XNOR2_X1_4 = new XNOR2_X1("XNOR2_X1_4");
        XNOR2_X1_4->A(S124);
        XNOR2_X1_4->B(S108);
        XNOR2_X1_4->ZN(S82);

    AND2_X1_3 = new AND2_X1("AND2_X1_3");
        AND2_X1_3->A1(S82);
        AND2_X1_3->A2(S81);
        AND2_X1_3->ZN(S83);

    INV_X1_23 = new INV_X1("INV_X1_23");
        INV_X1_23->A(S100);
        INV_X1_23->ZN(S84);

    INV_X1_24 = new INV_X1("INV_X1_24");
        INV_X1_24->A(S107);
        INV_X1_24->ZN(S85);

    OAI22_X1_1 = new OAI22_X1("OAI22_X1_1");
        OAI22_X1_1->A1(S116);
        OAI22_X1_1->A2(S84);
        OAI22_X1_1->B1(S85);
        OAI22_X1_1->B2(S123);
        OAI22_X1_1->ZN(S86);

    INV_X1_25 = new INV_X1("INV_X1_25");
        INV_X1_25->A(S123);
        INV_X1_25->ZN(S87);

    NOR2_X1_1 = new NOR2_X1("NOR2_X1_1");
        NOR2_X1_1->A1(S87);
        NOR2_X1_1->A2(S107);
        NOR2_X1_1->ZN(S88);

    INV_X1_26 = new INV_X1("INV_X1_26");
        INV_X1_26->A(S116);
        INV_X1_26->ZN(S89);

    NOR2_X1_2 = new NOR2_X1("NOR2_X1_2");
        NOR2_X1_2->A1(S89);
        NOR2_X1_2->A2(S100);
        NOR2_X1_2->ZN(S90);

    NOR3_X1_1 = new NOR3_X1("NOR3_X1_1");
        NOR3_X1_1->A1(S86);
        NOR3_X1_1->A2(S88);
        NOR3_X1_1->A3(S90);
        NOR3_X1_1->ZN(S91);

    NAND4_X1_3 = new NAND4_X1("NAND4_X1_3");
        NAND4_X1_3->A1(S73);
        NAND4_X1_3->A2(S83);
        NAND4_X1_3->A3(S80);
        NAND4_X1_3->A4(S91);
        NAND4_X1_3->ZN(S92);

    NOR2_X1_3 = new NOR2_X1("NOR2_X1_3");
        NOR2_X1_3->A1(S92);
        NOR2_X1_3->A2(S69);
        NOR2_X1_3->ZN(S98);

    NAND2_X1_14 = new NAND2_X1("NAND2_X1_14");
        NAND2_X1_14->A1(S51);
        NAND2_X1_14->A2(S42);
        NAND2_X1_14->ZN(S93);

    AND2_X1_4 = new AND2_X1("AND2_X1_4");
        AND2_X1_4->A1(S55);
        AND2_X1_4->A2(S53);
        AND2_X1_4->ZN(S94);

    AND2_X1_5 = new AND2_X1("AND2_X1_5");
        AND2_X1_5->A1(S59);
        AND2_X1_5->A2(S57);
        AND2_X1_5->ZN(S95);

    NAND4_X1_4 = new NAND4_X1("NAND4_X1_4");
        NAND4_X1_4->A1(S95);
        NAND4_X1_4->A2(S94);
        NAND4_X1_4->A3(S64);
        NAND4_X1_4->A4(S67);
        NAND4_X1_4->ZN(S96);

    NOR2_X1_4 = new NOR2_X1("NOR2_X1_4");
        NOR2_X1_4->A1(S93);
        NOR2_X1_4->A2(S96);
        NOR2_X1_4->ZN(S97);

    NAND4_X1_5 = new NAND4_X1("NAND4_X1_5");
        NAND4_X1_5->A1(S79);
        NAND4_X1_5->A2(S71);
        NAND4_X1_5->A3(S70);
        NAND4_X1_5->A4(S76);
        NAND4_X1_5->ZN(S0);

    AOI22_X1_5 = new AOI22_X1("AOI22_X1_5");
        AOI22_X1_5->A1(S100);
        AOI22_X1_5->A2(S89);
        AOI22_X1_5->B1(S87);
        AOI22_X1_5->B2(S107);
        AOI22_X1_5->ZN(S1);

    OAI211_X1_1 = new OAI211_X1("OAI211_X1_1");
        OAI211_X1_1->A(S82);
        OAI211_X1_1->B(S81);
        OAI211_X1_1->C1(S1);
        OAI211_X1_1->C2(S88);
        OAI211_X1_1->ZN(S2);

    INV_X1_27 = new INV_X1("INV_X1_27");
        INV_X1_27->A(S125);
        INV_X1_27->ZN(S3);

    NOR2_X1_5 = new NOR2_X1("NOR2_X1_5");
        NOR2_X1_5->A1(S3);
        NOR2_X1_5->A2(S109);
        NOR2_X1_5->ZN(S4);

    INV_X1_28 = new INV_X1("INV_X1_28");
        INV_X1_28->A(S124);
        INV_X1_28->ZN(S5);

    NOR2_X1_6 = new NOR2_X1("NOR2_X1_6");
        NOR2_X1_6->A1(S5);
        NOR2_X1_6->A2(S108);
        NOR2_X1_6->ZN(S6);

    AOI21_X1_1 = new AOI21_X1("AOI21_X1_1");
        AOI21_X1_1->A(S4);
        AOI21_X1_1->B1(S81);
        AOI21_X1_1->B2(S6);
        AOI21_X1_1->ZN(S7);

    AOI21_X1_2 = new AOI21_X1("AOI21_X1_2");
        AOI21_X1_2->A(S0);
        AOI21_X1_2->B1(S2);
        AOI21_X1_2->B2(S7);
        AOI21_X1_2->ZN(S8);

    NOR2_X1_7 = new NOR2_X1("NOR2_X1_7");
        NOR2_X1_7->A1(S77);
        NOR2_X1_7->A2(S111);
        NOR2_X1_7->ZN(S9);

    NAND2_X1_15 = new NAND2_X1("NAND2_X1_15");
        NAND2_X1_15->A1(S77);
        NAND2_X1_15->A2(S111);
        NAND2_X1_15->ZN(S10);

    NOR2_X1_8 = new NOR2_X1("NOR2_X1_8");
        NOR2_X1_8->A1(S75);
        NOR2_X1_8->A2(S110);
        NOR2_X1_8->ZN(S11);

    AOI21_X1_3 = new AOI21_X1("AOI21_X1_3");
        AOI21_X1_3->A(S9);
        AOI21_X1_3->B1(S10);
        AOI21_X1_3->B2(S11);
        AOI21_X1_3->ZN(S12);

    INV_X1_29 = new INV_X1("INV_X1_29");
        INV_X1_29->A(S129);
        INV_X1_29->ZN(S13);

    NOR2_X1_9 = new NOR2_X1("NOR2_X1_9");
        NOR2_X1_9->A1(S13);
        NOR2_X1_9->A2(S113);
        NOR2_X1_9->ZN(S14);

    INV_X1_30 = new INV_X1("INV_X1_30");
        INV_X1_30->A(S128);
        INV_X1_30->ZN(S15);

    NOR2_X1_10 = new NOR2_X1("NOR2_X1_10");
        NOR2_X1_10->A1(S15);
        NOR2_X1_10->A2(S112);
        NOR2_X1_10->ZN(S16);

    AOI21_X1_4 = new AOI21_X1("AOI21_X1_4");
        AOI21_X1_4->A(S14);
        AOI21_X1_4->B1(S70);
        AOI21_X1_4->B2(S16);
        AOI21_X1_4->ZN(S17);

    OAI21_X1_1 = new OAI21_X1("OAI21_X1_1");
        OAI21_X1_1->A(S17);
        OAI21_X1_1->B1(S72);
        OAI21_X1_1->B2(S12);
        OAI21_X1_1->ZN(S18);

    OAI21_X1_2 = new OAI21_X1("OAI21_X1_2");
        OAI21_X1_2->A(S97);
        OAI21_X1_2->B1(S8);
        OAI21_X1_2->B2(S18);
        OAI21_X1_2->ZN(S19);

    INV_X1_31 = new INV_X1("INV_X1_31");
        INV_X1_31->A(S93);
        INV_X1_31->ZN(S20);

    NOR2_X1_11 = new NOR2_X1("NOR2_X1_11");
        NOR2_X1_11->A1(S66);
        NOR2_X1_11->A2(S114);
        NOR2_X1_11->ZN(S21);

    NAND2_X1_16 = new NAND2_X1("NAND2_X1_16");
        NAND2_X1_16->A1(S62);
        NAND2_X1_16->A2(S115);
        NAND2_X1_16->ZN(S22);

    NOR2_X1_12 = new NOR2_X1("NOR2_X1_12");
        NOR2_X1_12->A1(S62);
        NOR2_X1_12->A2(S115);
        NOR2_X1_12->ZN(S23);

    AOI21_X1_5 = new AOI21_X1("AOI21_X1_5");
        AOI21_X1_5->A(S23);
        AOI21_X1_5->B1(S22);
        AOI21_X1_5->B2(S21);
        AOI21_X1_5->ZN(S24);

    NAND3_X1_1 = new NAND3_X1("NAND3_X1_1");
        NAND3_X1_1->A1(S59);
        NAND3_X1_1->A2(S117);
        NAND3_X1_1->A3(S52);
        NAND3_X1_1->ZN(S25);

    OAI211_X1_2 = new OAI211_X1("OAI211_X1_2");
        OAI211_X1_2->A(S57);
        OAI211_X1_2->B(S25);
        OAI211_X1_2->C1(S24);
        OAI211_X1_2->C2(S60);
        OAI211_X1_2->ZN(S26);

    NAND4_X1_6 = new NAND4_X1("NAND4_X1_6");
        NAND4_X1_6->A1(S39);
        NAND4_X1_6->A2(S41);
        NAND4_X1_6->A3(S35);
        NAND4_X1_6->A4(S37);
        NAND4_X1_6->ZN(S27);

    NOR2_X1_13 = new NOR2_X1("NOR2_X1_13");
        NOR2_X1_13->A1(S47);
        NOR2_X1_13->A2(S104);
        NOR2_X1_13->ZN(S28);

    INV_X1_32 = new INV_X1("INV_X1_32");
        INV_X1_32->A(S50);
        INV_X1_32->ZN(S29);

    AOI21_X1_6 = new AOI21_X1("AOI21_X1_6");
        AOI21_X1_6->A(S28);
        AOI21_X1_6->B1(S29);
        AOI21_X1_6->B2(S48);
        AOI21_X1_6->ZN(S30);

    NAND3_X1_2 = new NAND3_X1("NAND3_X1_2");
        NAND3_X1_2->A1(S39);
        NAND3_X1_2->A2(S121);
        NAND3_X1_2->A3(S40);
        NAND3_X1_2->ZN(S31);

    OAI211_X1_3 = new OAI211_X1("OAI211_X1_3");
        OAI211_X1_3->A(S35);
        OAI211_X1_3->B(S31);
        OAI211_X1_3->C1(S30);
        OAI211_X1_3->C2(S27);
        OAI211_X1_3->ZN(S32);

    AOI21_X1_7 = new AOI21_X1("AOI21_X1_7");
        AOI21_X1_7->A(S32);
        AOI21_X1_7->B1(S20);
        AOI21_X1_7->B2(S26);
        AOI21_X1_7->ZN(S33);

    AOI21_X1_8 = new AOI21_X1("AOI21_X1_8");
        AOI21_X1_8->A(S98);
        AOI21_X1_8->B1(S19);
        AOI21_X1_8->B2(S33);
        AOI21_X1_8->ZN(S99);

    BUF_X1_1 = new BUF_X1("BUF_X1_1");
        BUF_X1_1->A(S98);
        BUF_X1_1->Z(eq);

    BUF_X1_2 = new BUF_X1("BUF_X1_2");
        BUF_X1_2->A(S99);
        BUF_X1_2->Z(gt);

    BUF_X1_3 = new BUF_X1("BUF_X1_3");
        BUF_X1_3->A(in1[0]);
        BUF_X1_3->Z(S100);

    BUF_X1_4 = new BUF_X1("BUF_X1_4");
        BUF_X1_4->A(in1[1]);
        BUF_X1_4->Z(S107);

    BUF_X1_5 = new BUF_X1("BUF_X1_5");
        BUF_X1_5->A(in1[10]);
        BUF_X1_5->Z(S101);

    BUF_X1_6 = new BUF_X1("BUF_X1_6");
        BUF_X1_6->A(in1[11]);
        BUF_X1_6->Z(S102);

    BUF_X1_7 = new BUF_X1("BUF_X1_7");
        BUF_X1_7->A(in1[12]);
        BUF_X1_7->Z(S103);

    BUF_X1_8 = new BUF_X1("BUF_X1_8");
        BUF_X1_8->A(in1[13]);
        BUF_X1_8->Z(S104);

    BUF_X1_9 = new BUF_X1("BUF_X1_9");
        BUF_X1_9->A(in1[14]);
        BUF_X1_9->Z(S105);

    BUF_X1_10 = new BUF_X1("BUF_X1_10");
        BUF_X1_10->A(in1[15]);
        BUF_X1_10->Z(S106);

    BUF_X1_11 = new BUF_X1("BUF_X1_11");
        BUF_X1_11->A(in1[2]);
        BUF_X1_11->Z(S108);

    BUF_X1_12 = new BUF_X1("BUF_X1_12");
        BUF_X1_12->A(in1[3]);
        BUF_X1_12->Z(S109);

    BUF_X1_13 = new BUF_X1("BUF_X1_13");
        BUF_X1_13->A(in1[4]);
        BUF_X1_13->Z(S110);

    BUF_X1_14 = new BUF_X1("BUF_X1_14");
        BUF_X1_14->A(in1[5]);
        BUF_X1_14->Z(S111);

    BUF_X1_15 = new BUF_X1("BUF_X1_15");
        BUF_X1_15->A(in1[6]);
        BUF_X1_15->Z(S112);

    BUF_X1_16 = new BUF_X1("BUF_X1_16");
        BUF_X1_16->A(in1[7]);
        BUF_X1_16->Z(S113);

    BUF_X1_17 = new BUF_X1("BUF_X1_17");
        BUF_X1_17->A(in1[8]);
        BUF_X1_17->Z(S114);

    BUF_X1_18 = new BUF_X1("BUF_X1_18");
        BUF_X1_18->A(in1[9]);
        BUF_X1_18->Z(S115);

    BUF_X1_19 = new BUF_X1("BUF_X1_19");
        BUF_X1_19->A(in2[0]);
        BUF_X1_19->Z(S116);

    BUF_X1_20 = new BUF_X1("BUF_X1_20");
        BUF_X1_20->A(in2[1]);
        BUF_X1_20->Z(S123);

    BUF_X1_21 = new BUF_X1("BUF_X1_21");
        BUF_X1_21->A(in2[10]);
        BUF_X1_21->Z(S117);

    BUF_X1_22 = new BUF_X1("BUF_X1_22");
        BUF_X1_22->A(in2[11]);
        BUF_X1_22->Z(S118);

    BUF_X1_23 = new BUF_X1("BUF_X1_23");
        BUF_X1_23->A(in2[12]);
        BUF_X1_23->Z(S119);

    BUF_X1_24 = new BUF_X1("BUF_X1_24");
        BUF_X1_24->A(in2[13]);
        BUF_X1_24->Z(S120);

    BUF_X1_25 = new BUF_X1("BUF_X1_25");
        BUF_X1_25->A(in2[14]);
        BUF_X1_25->Z(S121);

    BUF_X1_26 = new BUF_X1("BUF_X1_26");
        BUF_X1_26->A(in2[15]);
        BUF_X1_26->Z(S122);

    BUF_X1_27 = new BUF_X1("BUF_X1_27");
        BUF_X1_27->A(in2[2]);
        BUF_X1_27->Z(S124);

    BUF_X1_28 = new BUF_X1("BUF_X1_28");
        BUF_X1_28->A(in2[3]);
        BUF_X1_28->Z(S125);

    BUF_X1_29 = new BUF_X1("BUF_X1_29");
        BUF_X1_29->A(in2[4]);
        BUF_X1_29->Z(S126);

    BUF_X1_30 = new BUF_X1("BUF_X1_30");
        BUF_X1_30->A(in2[5]);
        BUF_X1_30->Z(S127);

    BUF_X1_31 = new BUF_X1("BUF_X1_31");
        BUF_X1_31->A(in2[6]);
        BUF_X1_31->Z(S128);

    BUF_X1_32 = new BUF_X1("BUF_X1_32");
        BUF_X1_32->A(in2[7]);
        BUF_X1_32->Z(S129);

    BUF_X1_33 = new BUF_X1("BUF_X1_33");
        BUF_X1_33->A(in2[8]);
        BUF_X1_33->Z(S130);

    BUF_X1_34 = new BUF_X1("BUF_X1_34");
        BUF_X1_34->A(in2[9]);
        BUF_X1_34->Z(S131);


    SC_METHOD(sc_logic_signal_assignment);

    }

    void sc_logic_signal_assignment(void){ 
        sc_logic_1_signal.write(SC_LOGIC_1);
        sc_logic_0_signal.write(SC_LOGIC_0);
    }
};
#endif /* __CMP_H__ */

