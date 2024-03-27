#include <systemc.h>
#include "Complex_NAgate_45.h"



#ifndef __ADD_16_H__
#define __ADD_16_H__
using namespace sc_core;

SC_MODULE( add_16 ) {

    sc_in<sc_logic> in1[16];
    sc_in<sc_logic> in2[16];
    sc_out<sc_logic> outadd[16];

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
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S110[16];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S111[16];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S112[16];

    AND2_X1* AND2_X1_1;
    NOR2_X1* NOR2_X1_1;
    NOR2_X1* NOR2_X1_2;
    AND2_X1* AND2_X1_2;
    INV_X1* INV_X1_1;
    INV_X1* INV_X1_2;
    INV_X1* INV_X1_3;
    NAND2_X1* NAND2_X1_1;
    NAND2_X1* NAND2_X1_2;
    XNOR2_X1* XNOR2_X1_1;
    AOI21_X1* AOI21_X1_1;
    NAND2_X1* NAND2_X1_3;
    OR2_X1* OR2_X1_1;
    NAND2_X1* NAND2_X1_4;
    XOR2_X1* XOR2_X1_1;
    OAI21_X1* OAI21_X1_1;
    NAND2_X1* NAND2_X1_5;
    OR2_X1* OR2_X1_2;
    NAND2_X1* NAND2_X1_6;
    XNOR2_X1* XNOR2_X1_2;
    NAND4_X1* NAND4_X1_1;
    INV_X1* INV_X1_4;
    INV_X1* INV_X1_5;
    AOI21_X1* AOI21_X1_2;
    OAI21_X1* OAI21_X1_2;
    NAND2_X1* NAND2_X1_7;
    OR2_X1* OR2_X1_3;
    NAND2_X1* NAND2_X1_8;
    XNOR2_X1* XNOR2_X1_3;
    INV_X1* INV_X1_6;
    OAI21_X1* OAI21_X1_3;
    NAND2_X1* NAND2_X1_9;
    OR2_X1* OR2_X1_4;
    NAND2_X1* NAND2_X1_10;
    XNOR2_X1* XNOR2_X1_4;
    NAND2_X1* NAND2_X1_11;
    NAND2_X1* NAND2_X1_12;
    INV_X1* INV_X1_7;
    NAND4_X1* NAND4_X1_2;
    INV_X1* INV_X1_8;
    AOI21_X1* AOI21_X1_3;
    NAND2_X1* NAND2_X1_13;
    INV_X1* INV_X1_9;
    INV_X1* INV_X1_10;
    NAND2_X1* NAND2_X1_14;
    NAND2_X1* NAND2_X1_15;
    XOR2_X1* XOR2_X1_2;
    OAI21_X1* OAI21_X1_4;
    NAND2_X1* NAND2_X1_16;
    OR2_X1* OR2_X1_5;
    NAND2_X1* NAND2_X1_17;
    XNOR2_X1* XNOR2_X1_5;
    NAND4_X1* NAND4_X1_3;
    NOR2_X1* NOR2_X1_3;
    NAND3_X1* NAND3_X1_1;
    OAI211_X1* OAI211_X1_1;
    AOI21_X1* AOI21_X1_4;
    NAND2_X1* NAND2_X1_18;
    INV_X1* INV_X1_11;
    NOR2_X1* NOR2_X1_4;
    NOR2_X1* NOR2_X1_5;
    XNOR2_X1* XNOR2_X1_6;
    OAI21_X1* OAI21_X1_5;
    NAND2_X1* NAND2_X1_19;
    NOR2_X1* NOR2_X1_6;
    INV_X1* INV_X1_12;
    NAND2_X1* NAND2_X1_20;
    XNOR2_X1* XNOR2_X1_7;
    INV_X1* INV_X1_13;
    OAI21_X1* OAI21_X1_6;
    NOR3_X1* NOR3_X1_1;
    AOI21_X1* AOI21_X1_5;
    XNOR2_X1* XNOR2_X1_8;
    XOR2_X1* XOR2_X1_3;
    NAND2_X1* NAND2_X1_21;
    NOR2_X1* NOR2_X1_7;
    OAI21_X1* OAI21_X1_7;
    XNOR2_X1* XNOR2_X1_9;
    NAND2_X1* NAND2_X1_22;
    INV_X1* INV_X1_14;
    OAI211_X1* OAI211_X1_2;
    NAND2_X1* NAND2_X1_23;
    NOR2_X1* NOR2_X1_8;
    NAND2_X1* NAND2_X1_24;
    NAND2_X1* NAND2_X1_25;
    OAI21_X1* OAI21_X1_8;
    AOI21_X1* AOI21_X1_6;
    OAI21_X1* OAI21_X1_9;
    NAND2_X1* NAND2_X1_26;
    INV_X1* INV_X1_15;
    NOR2_X1* NOR2_X1_9;
    NOR2_X1* NOR2_X1_10;
    INV_X1* INV_X1_16;
    XNOR2_X1* XNOR2_X1_10;
    AOI21_X1* AOI21_X1_7;
    INV_X1* INV_X1_17;
    INV_X1* INV_X1_18;
    NOR2_X1* NOR2_X1_11;
    NOR2_X1* NOR2_X1_12;
    OR2_X1* OR2_X1_6;
    INV_X1* INV_X1_19;
    XNOR2_X1* XNOR2_X1_11;
    NOR2_X1* NOR2_X1_13;
    INV_X1* INV_X1_20;
    OAI21_X1* OAI21_X1_10;
    AOI21_X1* AOI21_X1_8;
    NAND2_X1* NAND2_X1_27;
    INV_X1* INV_X1_21;
    NOR2_X1* NOR2_X1_14;
    NOR2_X1* NOR2_X1_15;
    XNOR2_X1* XNOR2_X1_12;
    INV_X1* INV_X1_22;
    XNOR2_X1* XNOR2_X1_13;
    INV_X1* INV_X1_23;
    OAI211_X1* OAI211_X1_3;
    NAND2_X1* NAND2_X1_28;
    INV_X1* INV_X1_24;
    NAND2_X1* NAND2_X1_29;
    AOI21_X1* AOI21_X1_9;
    AOI21_X1* AOI21_X1_10;
    INV_X1* INV_X1_25;
    OAI21_X1* OAI21_X1_11;
    INV_X1* INV_X1_26;
    AOI21_X1* AOI21_X1_11;
    OAI21_X1* OAI21_X1_12;
    NAND2_X1* NAND2_X1_30;
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

SC_CTOR( add_16 ) {
    AND2_X1_1 = new AND2_X1("AND2_X1_1");
        AND2_X1_1->A1(S111[0]);
        AND2_X1_1->A2(S110[0]);
        AND2_X1_1->ZN(S66);

    NOR2_X1_1 = new NOR2_X1("NOR2_X1_1");
        NOR2_X1_1->A1(S110[0]);
        NOR2_X1_1->A2(S111[0]);
        NOR2_X1_1->ZN(S67);

    NOR2_X1_2 = new NOR2_X1("NOR2_X1_2");
        NOR2_X1_2->A1(S66);
        NOR2_X1_2->A2(S67);
        NOR2_X1_2->ZN(S112[0]);

    AND2_X1_2 = new AND2_X1("AND2_X1_2");
        AND2_X1_2->A1(S111[1]);
        AND2_X1_2->A2(S110[1]);
        AND2_X1_2->ZN(S68);

    INV_X1_1 = new INV_X1("INV_X1_1");
        INV_X1_1->A(S68);
        INV_X1_1->ZN(S69);

    INV_X1_2 = new INV_X1("INV_X1_2");
        INV_X1_2->A(S110[1]);
        INV_X1_2->ZN(S70);

    INV_X1_3 = new INV_X1("INV_X1_3");
        INV_X1_3->A(S111[1]);
        INV_X1_3->ZN(S71);

    NAND2_X1_1 = new NAND2_X1("NAND2_X1_1");
        NAND2_X1_1->A1(S70);
        NAND2_X1_1->A2(S71);
        NAND2_X1_1->ZN(S72);

    NAND2_X1_2 = new NAND2_X1("NAND2_X1_2");
        NAND2_X1_2->A1(S69);
        NAND2_X1_2->A2(S72);
        NAND2_X1_2->ZN(S73);

    XNOR2_X1_1 = new XNOR2_X1("XNOR2_X1_1");
        XNOR2_X1_1->A(S73);
        XNOR2_X1_1->B(S66);
        XNOR2_X1_1->ZN(S112[1]);

    AOI21_X1_1 = new AOI21_X1("AOI21_X1_1");
        AOI21_X1_1->A(S68);
        AOI21_X1_1->B1(S72);
        AOI21_X1_1->B2(S66);
        AOI21_X1_1->ZN(S74);

    NAND2_X1_3 = new NAND2_X1("NAND2_X1_3");
        NAND2_X1_3->A1(S110[2]);
        NAND2_X1_3->A2(S111[2]);
        NAND2_X1_3->ZN(S75);

    OR2_X1_1 = new OR2_X1("OR2_X1_1");
        OR2_X1_1->A1(S110[2]);
        OR2_X1_1->A2(S111[2]);
        OR2_X1_1->ZN(S76);

    NAND2_X1_4 = new NAND2_X1("NAND2_X1_4");
        NAND2_X1_4->A1(S76);
        NAND2_X1_4->A2(S75);
        NAND2_X1_4->ZN(S77);

    XOR2_X1_1 = new XOR2_X1("XOR2_X1_1");
        XOR2_X1_1->A(S74);
        XOR2_X1_1->B(S77);
        XOR2_X1_1->Z(S112[2]);

    OAI21_X1_1 = new OAI21_X1("OAI21_X1_1");
        OAI21_X1_1->A(S75);
        OAI21_X1_1->B1(S74);
        OAI21_X1_1->B2(S77);
        OAI21_X1_1->ZN(S78);

    NAND2_X1_5 = new NAND2_X1("NAND2_X1_5");
        NAND2_X1_5->A1(S110[3]);
        NAND2_X1_5->A2(S111[3]);
        NAND2_X1_5->ZN(S79);

    OR2_X1_2 = new OR2_X1("OR2_X1_2");
        OR2_X1_2->A1(S110[3]);
        OR2_X1_2->A2(S111[3]);
        OR2_X1_2->ZN(S80);

    NAND2_X1_6 = new NAND2_X1("NAND2_X1_6");
        NAND2_X1_6->A1(S80);
        NAND2_X1_6->A2(S79);
        NAND2_X1_6->ZN(S81);

    XNOR2_X1_2 = new XNOR2_X1("XNOR2_X1_2");
        XNOR2_X1_2->A(S78);
        XNOR2_X1_2->B(S81);
        XNOR2_X1_2->ZN(S112[3]);

    NAND4_X1_1 = new NAND4_X1("NAND4_X1_1");
        NAND4_X1_1->A1(S80);
        NAND4_X1_1->A2(S76);
        NAND4_X1_1->A3(S79);
        NAND4_X1_1->A4(S75);
        NAND4_X1_1->ZN(S82);

    INV_X1_4 = new INV_X1("INV_X1_4");
        INV_X1_4->A(S75);
        INV_X1_4->ZN(S83);

    INV_X1_5 = new INV_X1("INV_X1_5");
        INV_X1_5->A(S79);
        INV_X1_5->ZN(S84);

    AOI21_X1_2 = new AOI21_X1("AOI21_X1_2");
        AOI21_X1_2->A(S84);
        AOI21_X1_2->B1(S80);
        AOI21_X1_2->B2(S83);
        AOI21_X1_2->ZN(S85);

    OAI21_X1_2 = new OAI21_X1("OAI21_X1_2");
        OAI21_X1_2->A(S85);
        OAI21_X1_2->B1(S82);
        OAI21_X1_2->B2(S74);
        OAI21_X1_2->ZN(S86);

    NAND2_X1_7 = new NAND2_X1("NAND2_X1_7");
        NAND2_X1_7->A1(S110[4]);
        NAND2_X1_7->A2(S111[4]);
        NAND2_X1_7->ZN(S87);

    OR2_X1_3 = new OR2_X1("OR2_X1_3");
        OR2_X1_3->A1(S110[4]);
        OR2_X1_3->A2(S111[4]);
        OR2_X1_3->ZN(S88);

    NAND2_X1_8 = new NAND2_X1("NAND2_X1_8");
        NAND2_X1_8->A1(S88);
        NAND2_X1_8->A2(S87);
        NAND2_X1_8->ZN(S89);

    XNOR2_X1_3 = new XNOR2_X1("XNOR2_X1_3");
        XNOR2_X1_3->A(S86);
        XNOR2_X1_3->B(S89);
        XNOR2_X1_3->ZN(S112[4]);

    INV_X1_6 = new INV_X1("INV_X1_6");
        INV_X1_6->A(S86);
        INV_X1_6->ZN(S90);

    OAI21_X1_3 = new OAI21_X1("OAI21_X1_3");
        OAI21_X1_3->A(S87);
        OAI21_X1_3->B1(S90);
        OAI21_X1_3->B2(S89);
        OAI21_X1_3->ZN(S91);

    NAND2_X1_9 = new NAND2_X1("NAND2_X1_9");
        NAND2_X1_9->A1(S110[5]);
        NAND2_X1_9->A2(S111[5]);
        NAND2_X1_9->ZN(S92);

    OR2_X1_4 = new OR2_X1("OR2_X1_4");
        OR2_X1_4->A1(S110[5]);
        OR2_X1_4->A2(S111[5]);
        OR2_X1_4->ZN(S93);

    NAND2_X1_10 = new NAND2_X1("NAND2_X1_10");
        NAND2_X1_10->A1(S93);
        NAND2_X1_10->A2(S92);
        NAND2_X1_10->ZN(S94);

    XNOR2_X1_4 = new XNOR2_X1("XNOR2_X1_4");
        XNOR2_X1_4->A(S91);
        XNOR2_X1_4->B(S94);
        XNOR2_X1_4->ZN(S112[5]);

    NAND2_X1_11 = new NAND2_X1("NAND2_X1_11");
        NAND2_X1_11->A1(S87);
        NAND2_X1_11->A2(S92);
        NAND2_X1_11->ZN(S95);

    NAND2_X1_12 = new NAND2_X1("NAND2_X1_12");
        NAND2_X1_12->A1(S95);
        NAND2_X1_12->A2(S93);
        NAND2_X1_12->ZN(S96);

    INV_X1_7 = new INV_X1("INV_X1_7");
        INV_X1_7->A(S96);
        INV_X1_7->ZN(S97);

    NAND4_X1_2 = new NAND4_X1("NAND4_X1_2");
        NAND4_X1_2->A1(S93);
        NAND4_X1_2->A2(S88);
        NAND4_X1_2->A3(S92);
        NAND4_X1_2->A4(S87);
        NAND4_X1_2->ZN(S98);

    INV_X1_8 = new INV_X1("INV_X1_8");
        INV_X1_8->A(S98);
        INV_X1_8->ZN(S99);

    AOI21_X1_3 = new AOI21_X1("AOI21_X1_3");
        AOI21_X1_3->A(S97);
        AOI21_X1_3->B1(S86);
        AOI21_X1_3->B2(S99);
        AOI21_X1_3->ZN(S100);

    NAND2_X1_13 = new NAND2_X1("NAND2_X1_13");
        NAND2_X1_13->A1(S110[6]);
        NAND2_X1_13->A2(S111[6]);
        NAND2_X1_13->ZN(S101);

    INV_X1_9 = new INV_X1("INV_X1_9");
        INV_X1_9->A(S110[6]);
        INV_X1_9->ZN(S102);

    INV_X1_10 = new INV_X1("INV_X1_10");
        INV_X1_10->A(S111[6]);
        INV_X1_10->ZN(S103);

    NAND2_X1_14 = new NAND2_X1("NAND2_X1_14");
        NAND2_X1_14->A1(S102);
        NAND2_X1_14->A2(S103);
        NAND2_X1_14->ZN(S104);

    NAND2_X1_15 = new NAND2_X1("NAND2_X1_15");
        NAND2_X1_15->A1(S104);
        NAND2_X1_15->A2(S101);
        NAND2_X1_15->ZN(S105);

    XOR2_X1_2 = new XOR2_X1("XOR2_X1_2");
        XOR2_X1_2->A(S100);
        XOR2_X1_2->B(S105);
        XOR2_X1_2->Z(S112[6]);

    OAI21_X1_4 = new OAI21_X1("OAI21_X1_4");
        OAI21_X1_4->A(S101);
        OAI21_X1_4->B1(S100);
        OAI21_X1_4->B2(S105);
        OAI21_X1_4->ZN(S106);

    NAND2_X1_16 = new NAND2_X1("NAND2_X1_16");
        NAND2_X1_16->A1(S110[7]);
        NAND2_X1_16->A2(S111[7]);
        NAND2_X1_16->ZN(S107);

    OR2_X1_5 = new OR2_X1("OR2_X1_5");
        OR2_X1_5->A1(S110[7]);
        OR2_X1_5->A2(S111[7]);
        OR2_X1_5->ZN(S108);

    NAND2_X1_17 = new NAND2_X1("NAND2_X1_17");
        NAND2_X1_17->A1(S108);
        NAND2_X1_17->A2(S107);
        NAND2_X1_17->ZN(S109);

    XNOR2_X1_5 = new XNOR2_X1("XNOR2_X1_5");
        XNOR2_X1_5->A(S106);
        XNOR2_X1_5->B(S109);
        XNOR2_X1_5->ZN(S112[7]);

    NAND4_X1_3 = new NAND4_X1("NAND4_X1_3");
        NAND4_X1_3->A1(S108);
        NAND4_X1_3->A2(S104);
        NAND4_X1_3->A3(S107);
        NAND4_X1_3->A4(S101);
        NAND4_X1_3->ZN(S0);

    NOR2_X1_3 = new NOR2_X1("NOR2_X1_3");
        NOR2_X1_3->A1(S98);
        NOR2_X1_3->A2(S0);
        NOR2_X1_3->ZN(S1);

    NAND3_X1_1 = new NAND3_X1("NAND3_X1_1");
        NAND3_X1_1->A1(S108);
        NAND3_X1_1->A2(S110[6]);
        NAND3_X1_1->A3(S111[6]);
        NAND3_X1_1->ZN(S2);

    OAI211_X1_1 = new OAI211_X1("OAI211_X1_1");
        OAI211_X1_1->A(S2);
        OAI211_X1_1->B(S107);
        OAI211_X1_1->C1(S0);
        OAI211_X1_1->C2(S96);
        OAI211_X1_1->ZN(S3);

    AOI21_X1_4 = new AOI21_X1("AOI21_X1_4");
        AOI21_X1_4->A(S3);
        AOI21_X1_4->B1(S1);
        AOI21_X1_4->B2(S86);
        AOI21_X1_4->ZN(S4);

    NAND2_X1_18 = new NAND2_X1("NAND2_X1_18");
        NAND2_X1_18->A1(S110[8]);
        NAND2_X1_18->A2(S111[8]);
        NAND2_X1_18->ZN(S5);

    INV_X1_11 = new INV_X1("INV_X1_11");
        INV_X1_11->A(S5);
        INV_X1_11->ZN(S6);

    NOR2_X1_4 = new NOR2_X1("NOR2_X1_4");
        NOR2_X1_4->A1(S110[8]);
        NOR2_X1_4->A2(S111[8]);
        NOR2_X1_4->ZN(S7);

    NOR2_X1_5 = new NOR2_X1("NOR2_X1_5");
        NOR2_X1_5->A1(S6);
        NOR2_X1_5->A2(S7);
        NOR2_X1_5->ZN(S8);

    XNOR2_X1_6 = new XNOR2_X1("XNOR2_X1_6");
        XNOR2_X1_6->A(S4);
        XNOR2_X1_6->B(S8);
        XNOR2_X1_6->ZN(S112[8]);

    OAI21_X1_5 = new OAI21_X1("OAI21_X1_5");
        OAI21_X1_5->A(S5);
        OAI21_X1_5->B1(S4);
        OAI21_X1_5->B2(S7);
        OAI21_X1_5->ZN(S9);

    NAND2_X1_19 = new NAND2_X1("NAND2_X1_19");
        NAND2_X1_19->A1(S110[9]);
        NAND2_X1_19->A2(S111[9]);
        NAND2_X1_19->ZN(S10);

    NOR2_X1_6 = new NOR2_X1("NOR2_X1_6");
        NOR2_X1_6->A1(S110[9]);
        NOR2_X1_6->A2(S111[9]);
        NOR2_X1_6->ZN(S11);

    INV_X1_12 = new INV_X1("INV_X1_12");
        INV_X1_12->A(S11);
        INV_X1_12->ZN(S12);

    NAND2_X1_20 = new NAND2_X1("NAND2_X1_20");
        NAND2_X1_20->A1(S12);
        NAND2_X1_20->A2(S10);
        NAND2_X1_20->ZN(S13);

    XNOR2_X1_7 = new XNOR2_X1("XNOR2_X1_7");
        XNOR2_X1_7->A(S9);
        XNOR2_X1_7->B(S13);
        XNOR2_X1_7->ZN(S112[9]);

    INV_X1_13 = new INV_X1("INV_X1_13");
        INV_X1_13->A(S4);
        INV_X1_13->ZN(S14);

    OAI21_X1_6 = new OAI21_X1("OAI21_X1_6");
        OAI21_X1_6->A(S10);
        OAI21_X1_6->B1(S11);
        OAI21_X1_6->B2(S5);
        OAI21_X1_6->ZN(S15);

    NOR3_X1_1 = new NOR3_X1("NOR3_X1_1");
        NOR3_X1_1->A1(S13);
        NOR3_X1_1->A2(S7);
        NOR3_X1_1->A3(S6);
        NOR3_X1_1->ZN(S16);

    AOI21_X1_5 = new AOI21_X1("AOI21_X1_5");
        AOI21_X1_5->A(S15);
        AOI21_X1_5->B1(S14);
        AOI21_X1_5->B2(S16);
        AOI21_X1_5->ZN(S17);

    XNOR2_X1_8 = new XNOR2_X1("XNOR2_X1_8");
        XNOR2_X1_8->A(S110[10]);
        XNOR2_X1_8->B(S111[10]);
        XNOR2_X1_8->ZN(S18);

    XOR2_X1_3 = new XOR2_X1("XOR2_X1_3");
        XOR2_X1_3->A(S17);
        XOR2_X1_3->B(S18);
        XOR2_X1_3->Z(S112[10]);

    NAND2_X1_21 = new NAND2_X1("NAND2_X1_21");
        NAND2_X1_21->A1(S110[10]);
        NAND2_X1_21->A2(S111[10]);
        NAND2_X1_21->ZN(S19);

    NOR2_X1_7 = new NOR2_X1("NOR2_X1_7");
        NOR2_X1_7->A1(S110[10]);
        NOR2_X1_7->A2(S111[10]);
        NOR2_X1_7->ZN(S20);

    OAI21_X1_7 = new OAI21_X1("OAI21_X1_7");
        OAI21_X1_7->A(S19);
        OAI21_X1_7->B1(S17);
        OAI21_X1_7->B2(S20);
        OAI21_X1_7->ZN(S21);

    XNOR2_X1_9 = new XNOR2_X1("XNOR2_X1_9");
        XNOR2_X1_9->A(S110[11]);
        XNOR2_X1_9->B(S111[11]);
        XNOR2_X1_9->ZN(S22);

    NAND2_X1_22 = new NAND2_X1("NAND2_X1_22");
        NAND2_X1_22->A1(S21);
        NAND2_X1_22->A2(S22);
        NAND2_X1_22->ZN(S23);

    INV_X1_14 = new INV_X1("INV_X1_14");
        INV_X1_14->A(S22);
        INV_X1_14->ZN(S24);

    OAI211_X1_2 = new OAI211_X1("OAI211_X1_2");
        OAI211_X1_2->A(S19);
        OAI211_X1_2->B(S24);
        OAI211_X1_2->C1(S17);
        OAI211_X1_2->C2(S20);
        OAI211_X1_2->ZN(S25);

    NAND2_X1_23 = new NAND2_X1("NAND2_X1_23");
        NAND2_X1_23->A1(S23);
        NAND2_X1_23->A2(S25);
        NAND2_X1_23->ZN(S112[11]);

    NOR2_X1_8 = new NOR2_X1("NOR2_X1_8");
        NOR2_X1_8->A1(S18);
        NOR2_X1_8->A2(S22);
        NOR2_X1_8->ZN(S26);

    NAND2_X1_24 = new NAND2_X1("NAND2_X1_24");
        NAND2_X1_24->A1(S16);
        NAND2_X1_24->A2(S26);
        NAND2_X1_24->ZN(S27);

    NAND2_X1_25 = new NAND2_X1("NAND2_X1_25");
        NAND2_X1_25->A1(S110[11]);
        NAND2_X1_25->A2(S111[11]);
        NAND2_X1_25->ZN(S28);

    OAI21_X1_8 = new OAI21_X1("OAI21_X1_8");
        OAI21_X1_8->A(S28);
        OAI21_X1_8->B1(S22);
        OAI21_X1_8->B2(S19);
        OAI21_X1_8->ZN(S29);

    AOI21_X1_6 = new AOI21_X1("AOI21_X1_6");
        AOI21_X1_6->A(S29);
        AOI21_X1_6->B1(S26);
        AOI21_X1_6->B2(S15);
        AOI21_X1_6->ZN(S30);

    OAI21_X1_9 = new OAI21_X1("OAI21_X1_9");
        OAI21_X1_9->A(S30);
        OAI21_X1_9->B1(S4);
        OAI21_X1_9->B2(S27);
        OAI21_X1_9->ZN(S31);

    NAND2_X1_26 = new NAND2_X1("NAND2_X1_26");
        NAND2_X1_26->A1(S110[12]);
        NAND2_X1_26->A2(S111[12]);
        NAND2_X1_26->ZN(S32);

    INV_X1_15 = new INV_X1("INV_X1_15");
        INV_X1_15->A(S32);
        INV_X1_15->ZN(S33);

    NOR2_X1_9 = new NOR2_X1("NOR2_X1_9");
        NOR2_X1_9->A1(S110[12]);
        NOR2_X1_9->A2(S111[12]);
        NOR2_X1_9->ZN(S34);

    NOR2_X1_10 = new NOR2_X1("NOR2_X1_10");
        NOR2_X1_10->A1(S33);
        NOR2_X1_10->A2(S34);
        NOR2_X1_10->ZN(S35);

    INV_X1_16 = new INV_X1("INV_X1_16");
        INV_X1_16->A(S35);
        INV_X1_16->ZN(S36);

    XNOR2_X1_10 = new XNOR2_X1("XNOR2_X1_10");
        XNOR2_X1_10->A(S31);
        XNOR2_X1_10->B(S36);
        XNOR2_X1_10->ZN(S112[12]);

    AOI21_X1_7 = new AOI21_X1("AOI21_X1_7");
        AOI21_X1_7->A(S33);
        AOI21_X1_7->B1(S31);
        AOI21_X1_7->B2(S35);
        AOI21_X1_7->ZN(S37);

    INV_X1_17 = new INV_X1("INV_X1_17");
        INV_X1_17->A(S110[13]);
        INV_X1_17->ZN(S38);

    INV_X1_18 = new INV_X1("INV_X1_18");
        INV_X1_18->A(S111[13]);
        INV_X1_18->ZN(S39);

    NOR2_X1_11 = new NOR2_X1("NOR2_X1_11");
        NOR2_X1_11->A1(S38);
        NOR2_X1_11->A2(S39);
        NOR2_X1_11->ZN(S40);

    NOR2_X1_12 = new NOR2_X1("NOR2_X1_12");
        NOR2_X1_12->A1(S110[13]);
        NOR2_X1_12->A2(S111[13]);
        NOR2_X1_12->ZN(S41);

    OR2_X1_6 = new OR2_X1("OR2_X1_6");
        OR2_X1_6->A1(S40);
        OR2_X1_6->A2(S41);
        OR2_X1_6->ZN(S42);

    INV_X1_19 = new INV_X1("INV_X1_19");
        INV_X1_19->A(S42);
        INV_X1_19->ZN(S43);

    XNOR2_X1_11 = new XNOR2_X1("XNOR2_X1_11");
        XNOR2_X1_11->A(S37);
        XNOR2_X1_11->B(S43);
        XNOR2_X1_11->ZN(S112[13]);

    NOR2_X1_13 = new NOR2_X1("NOR2_X1_13");
        NOR2_X1_13->A1(S42);
        NOR2_X1_13->A2(S36);
        NOR2_X1_13->ZN(S44);

    INV_X1_20 = new INV_X1("INV_X1_20");
        INV_X1_20->A(S40);
        INV_X1_20->ZN(S45);

    OAI21_X1_10 = new OAI21_X1("OAI21_X1_10");
        OAI21_X1_10->A(S45);
        OAI21_X1_10->B1(S32);
        OAI21_X1_10->B2(S41);
        OAI21_X1_10->ZN(S46);

    AOI21_X1_8 = new AOI21_X1("AOI21_X1_8");
        AOI21_X1_8->A(S46);
        AOI21_X1_8->B1(S31);
        AOI21_X1_8->B2(S44);
        AOI21_X1_8->ZN(S47);

    NAND2_X1_27 = new NAND2_X1("NAND2_X1_27");
        NAND2_X1_27->A1(S110[14]);
        NAND2_X1_27->A2(S111[14]);
        NAND2_X1_27->ZN(S48);

    INV_X1_21 = new INV_X1("INV_X1_21");
        INV_X1_21->A(S48);
        INV_X1_21->ZN(S49);

    NOR2_X1_14 = new NOR2_X1("NOR2_X1_14");
        NOR2_X1_14->A1(S110[14]);
        NOR2_X1_14->A2(S111[14]);
        NOR2_X1_14->ZN(S50);

    NOR2_X1_15 = new NOR2_X1("NOR2_X1_15");
        NOR2_X1_15->A1(S49);
        NOR2_X1_15->A2(S50);
        NOR2_X1_15->ZN(S51);

    XNOR2_X1_12 = new XNOR2_X1("XNOR2_X1_12");
        XNOR2_X1_12->A(S47);
        XNOR2_X1_12->B(S51);
        XNOR2_X1_12->ZN(S112[14]);

    INV_X1_22 = new INV_X1("INV_X1_22");
        INV_X1_22->A(S51);
        INV_X1_22->ZN(S52);

    XNOR2_X1_13 = new XNOR2_X1("XNOR2_X1_13");
        XNOR2_X1_13->A(S110[15]);
        XNOR2_X1_13->B(S111[15]);
        XNOR2_X1_13->ZN(S53);

    INV_X1_23 = new INV_X1("INV_X1_23");
        INV_X1_23->A(S53);
        INV_X1_23->ZN(S54);

    OAI211_X1_3 = new OAI211_X1("OAI211_X1_3");
        OAI211_X1_3->A(S48);
        OAI211_X1_3->B(S54);
        OAI211_X1_3->C1(S47);
        OAI211_X1_3->C2(S52);
        OAI211_X1_3->ZN(S55);

    NAND2_X1_28 = new NAND2_X1("NAND2_X1_28");
        NAND2_X1_28->A1(S86);
        NAND2_X1_28->A2(S1);
        NAND2_X1_28->ZN(S56);

    INV_X1_24 = new INV_X1("INV_X1_24");
        INV_X1_24->A(S0);
        INV_X1_24->ZN(S57);

    NAND2_X1_29 = new NAND2_X1("NAND2_X1_29");
        NAND2_X1_29->A1(S2);
        NAND2_X1_29->A2(S107);
        NAND2_X1_29->ZN(S58);

    AOI21_X1_9 = new AOI21_X1("AOI21_X1_9");
        AOI21_X1_9->A(S58);
        AOI21_X1_9->B1(S57);
        AOI21_X1_9->B2(S97);
        AOI21_X1_9->ZN(S59);

    AOI21_X1_10 = new AOI21_X1("AOI21_X1_10");
        AOI21_X1_10->A(S27);
        AOI21_X1_10->B1(S56);
        AOI21_X1_10->B2(S59);
        AOI21_X1_10->ZN(S60);

    INV_X1_25 = new INV_X1("INV_X1_25");
        INV_X1_25->A(S30);
        INV_X1_25->ZN(S61);

    OAI21_X1_11 = new OAI21_X1("OAI21_X1_11");
        OAI21_X1_11->A(S44);
        OAI21_X1_11->B1(S60);
        OAI21_X1_11->B2(S61);
        OAI21_X1_11->ZN(S62);

    INV_X1_26 = new INV_X1("INV_X1_26");
        INV_X1_26->A(S46);
        INV_X1_26->ZN(S63);

    AOI21_X1_11 = new AOI21_X1("AOI21_X1_11");
        AOI21_X1_11->A(S52);
        AOI21_X1_11->B1(S62);
        AOI21_X1_11->B2(S63);
        AOI21_X1_11->ZN(S64);

    OAI21_X1_12 = new OAI21_X1("OAI21_X1_12");
        OAI21_X1_12->A(S53);
        OAI21_X1_12->B1(S64);
        OAI21_X1_12->B2(S49);
        OAI21_X1_12->ZN(S65);

    NAND2_X1_30 = new NAND2_X1("NAND2_X1_30");
        NAND2_X1_30->A1(S65);
        NAND2_X1_30->A2(S55);
        NAND2_X1_30->ZN(S112[15]);

    BUF_X1_1 = new BUF_X1("BUF_X1_1");
        BUF_X1_1->A(in1[0]);
        BUF_X1_1->Z(S110[0]);

    BUF_X1_2 = new BUF_X1("BUF_X1_2");
        BUF_X1_2->A(in1[1]);
        BUF_X1_2->Z(S110[1]);

    BUF_X1_3 = new BUF_X1("BUF_X1_3");
        BUF_X1_3->A(in1[10]);
        BUF_X1_3->Z(S110[10]);

    BUF_X1_4 = new BUF_X1("BUF_X1_4");
        BUF_X1_4->A(in1[11]);
        BUF_X1_4->Z(S110[11]);

    BUF_X1_5 = new BUF_X1("BUF_X1_5");
        BUF_X1_5->A(in1[12]);
        BUF_X1_5->Z(S110[12]);

    BUF_X1_6 = new BUF_X1("BUF_X1_6");
        BUF_X1_6->A(in1[13]);
        BUF_X1_6->Z(S110[13]);

    BUF_X1_7 = new BUF_X1("BUF_X1_7");
        BUF_X1_7->A(in1[14]);
        BUF_X1_7->Z(S110[14]);

    BUF_X1_8 = new BUF_X1("BUF_X1_8");
        BUF_X1_8->A(in1[15]);
        BUF_X1_8->Z(S110[15]);

    BUF_X1_9 = new BUF_X1("BUF_X1_9");
        BUF_X1_9->A(in1[2]);
        BUF_X1_9->Z(S110[2]);

    BUF_X1_10 = new BUF_X1("BUF_X1_10");
        BUF_X1_10->A(in1[3]);
        BUF_X1_10->Z(S110[3]);

    BUF_X1_11 = new BUF_X1("BUF_X1_11");
        BUF_X1_11->A(in1[4]);
        BUF_X1_11->Z(S110[4]);

    BUF_X1_12 = new BUF_X1("BUF_X1_12");
        BUF_X1_12->A(in1[5]);
        BUF_X1_12->Z(S110[5]);

    BUF_X1_13 = new BUF_X1("BUF_X1_13");
        BUF_X1_13->A(in1[6]);
        BUF_X1_13->Z(S110[6]);

    BUF_X1_14 = new BUF_X1("BUF_X1_14");
        BUF_X1_14->A(in1[7]);
        BUF_X1_14->Z(S110[7]);

    BUF_X1_15 = new BUF_X1("BUF_X1_15");
        BUF_X1_15->A(in1[8]);
        BUF_X1_15->Z(S110[8]);

    BUF_X1_16 = new BUF_X1("BUF_X1_16");
        BUF_X1_16->A(in1[9]);
        BUF_X1_16->Z(S110[9]);

    BUF_X1_17 = new BUF_X1("BUF_X1_17");
        BUF_X1_17->A(in2[0]);
        BUF_X1_17->Z(S111[0]);

    BUF_X1_18 = new BUF_X1("BUF_X1_18");
        BUF_X1_18->A(in2[1]);
        BUF_X1_18->Z(S111[1]);

    BUF_X1_19 = new BUF_X1("BUF_X1_19");
        BUF_X1_19->A(in2[10]);
        BUF_X1_19->Z(S111[10]);

    BUF_X1_20 = new BUF_X1("BUF_X1_20");
        BUF_X1_20->A(in2[11]);
        BUF_X1_20->Z(S111[11]);

    BUF_X1_21 = new BUF_X1("BUF_X1_21");
        BUF_X1_21->A(in2[12]);
        BUF_X1_21->Z(S111[12]);

    BUF_X1_22 = new BUF_X1("BUF_X1_22");
        BUF_X1_22->A(in2[13]);
        BUF_X1_22->Z(S111[13]);

    BUF_X1_23 = new BUF_X1("BUF_X1_23");
        BUF_X1_23->A(in2[14]);
        BUF_X1_23->Z(S111[14]);

    BUF_X1_24 = new BUF_X1("BUF_X1_24");
        BUF_X1_24->A(in2[15]);
        BUF_X1_24->Z(S111[15]);

    BUF_X1_25 = new BUF_X1("BUF_X1_25");
        BUF_X1_25->A(in2[2]);
        BUF_X1_25->Z(S111[2]);

    BUF_X1_26 = new BUF_X1("BUF_X1_26");
        BUF_X1_26->A(in2[3]);
        BUF_X1_26->Z(S111[3]);

    BUF_X1_27 = new BUF_X1("BUF_X1_27");
        BUF_X1_27->A(in2[4]);
        BUF_X1_27->Z(S111[4]);

    BUF_X1_28 = new BUF_X1("BUF_X1_28");
        BUF_X1_28->A(in2[5]);
        BUF_X1_28->Z(S111[5]);

    BUF_X1_29 = new BUF_X1("BUF_X1_29");
        BUF_X1_29->A(in2[6]);
        BUF_X1_29->Z(S111[6]);

    BUF_X1_30 = new BUF_X1("BUF_X1_30");
        BUF_X1_30->A(in2[7]);
        BUF_X1_30->Z(S111[7]);

    BUF_X1_31 = new BUF_X1("BUF_X1_31");
        BUF_X1_31->A(in2[8]);
        BUF_X1_31->Z(S111[8]);

    BUF_X1_32 = new BUF_X1("BUF_X1_32");
        BUF_X1_32->A(in2[9]);
        BUF_X1_32->Z(S111[9]);

    BUF_X1_33 = new BUF_X1("BUF_X1_33");
        BUF_X1_33->A(S112[0]);
        BUF_X1_33->Z(outadd[0]);

    BUF_X1_34 = new BUF_X1("BUF_X1_34");
        BUF_X1_34->A(S112[1]);
        BUF_X1_34->Z(outadd[1]);

    BUF_X1_35 = new BUF_X1("BUF_X1_35");
        BUF_X1_35->A(S112[10]);
        BUF_X1_35->Z(outadd[10]);

    BUF_X1_36 = new BUF_X1("BUF_X1_36");
        BUF_X1_36->A(S112[11]);
        BUF_X1_36->Z(outadd[11]);

    BUF_X1_37 = new BUF_X1("BUF_X1_37");
        BUF_X1_37->A(S112[12]);
        BUF_X1_37->Z(outadd[12]);

    BUF_X1_38 = new BUF_X1("BUF_X1_38");
        BUF_X1_38->A(S112[13]);
        BUF_X1_38->Z(outadd[13]);

    BUF_X1_39 = new BUF_X1("BUF_X1_39");
        BUF_X1_39->A(S112[14]);
        BUF_X1_39->Z(outadd[14]);

    BUF_X1_40 = new BUF_X1("BUF_X1_40");
        BUF_X1_40->A(S112[15]);
        BUF_X1_40->Z(outadd[15]);

    BUF_X1_41 = new BUF_X1("BUF_X1_41");
        BUF_X1_41->A(S112[2]);
        BUF_X1_41->Z(outadd[2]);

    BUF_X1_42 = new BUF_X1("BUF_X1_42");
        BUF_X1_42->A(S112[3]);
        BUF_X1_42->Z(outadd[3]);

    BUF_X1_43 = new BUF_X1("BUF_X1_43");
        BUF_X1_43->A(S112[4]);
        BUF_X1_43->Z(outadd[4]);

    BUF_X1_44 = new BUF_X1("BUF_X1_44");
        BUF_X1_44->A(S112[5]);
        BUF_X1_44->Z(outadd[5]);

    BUF_X1_45 = new BUF_X1("BUF_X1_45");
        BUF_X1_45->A(S112[6]);
        BUF_X1_45->Z(outadd[6]);

    BUF_X1_46 = new BUF_X1("BUF_X1_46");
        BUF_X1_46->A(S112[7]);
        BUF_X1_46->Z(outadd[7]);

    BUF_X1_47 = new BUF_X1("BUF_X1_47");
        BUF_X1_47->A(S112[8]);
        BUF_X1_47->Z(outadd[8]);

    BUF_X1_48 = new BUF_X1("BUF_X1_48");
        BUF_X1_48->A(S112[9]);
        BUF_X1_48->Z(outadd[9]);


    SC_METHOD(sc_logic_signal_assignment);

    }

    void sc_logic_signal_assignment(void){ 
        sc_logic_1_signal.write(SC_LOGIC_1);
        sc_logic_0_signal.write(SC_LOGIC_0);
    }
};
#endif /* __ADD_16_H__ */

