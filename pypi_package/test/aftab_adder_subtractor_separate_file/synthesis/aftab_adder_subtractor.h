#include <systemc.h>
#include "Complex_NAgate_45.h"

#include "_paramod_aftab_adder_size_s32_00000000000000000000000000100000.h"


#ifndef __AFTAB_ADDER_SUBTRACTOR_H__
#define __AFTAB_ADDER_SUBTRACTOR_H__
using namespace sc_core;

SC_MODULE( aftab_adder_subtractor ) {

    sc_in<sc_logic> a[32];
    sc_in<sc_logic> b[32];
    sc_in<sc_logic> subsel;
    sc_in<sc_logic> pass;
    sc_out<sc_logic> cout;
    sc_out<sc_logic> result[32];

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
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S128[32];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S129[32];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S130 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S130");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S131 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S131");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S132[32];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S133 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S133");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> addSubRes_0_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("addSubRes_0_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> addSubRes_10_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("addSubRes_10_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> addSubRes_11_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("addSubRes_11_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> addSubRes_12_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("addSubRes_12_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> addSubRes_13_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("addSubRes_13_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> addSubRes_14_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("addSubRes_14_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> addSubRes_15_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("addSubRes_15_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> addSubRes_16_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("addSubRes_16_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> addSubRes_17_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("addSubRes_17_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> addSubRes_18_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("addSubRes_18_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> addSubRes_19_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("addSubRes_19_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> addSubRes_1_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("addSubRes_1_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> addSubRes_20_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("addSubRes_20_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> addSubRes_21_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("addSubRes_21_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> addSubRes_22_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("addSubRes_22_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> addSubRes_23_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("addSubRes_23_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> addSubRes_24_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("addSubRes_24_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> addSubRes_25_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("addSubRes_25_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> addSubRes_26_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("addSubRes_26_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> addSubRes_27_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("addSubRes_27_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> addSubRes_28_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("addSubRes_28_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> addSubRes_29_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("addSubRes_29_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> addSubRes_2_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("addSubRes_2_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> addSubRes_30_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("addSubRes_30_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> addSubRes_31_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("addSubRes_31_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> addSubRes_3_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("addSubRes_3_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> addSubRes_4_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("addSubRes_4_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> addSubRes_5_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("addSubRes_5_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> addSubRes_6_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("addSubRes_6_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> addSubRes_7_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("addSubRes_7_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> addSubRes_8_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("addSubRes_8_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> addSubRes_9_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("addSubRes_9_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> bsel_0_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("bsel_0_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> bsel_10_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("bsel_10_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> bsel_11_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("bsel_11_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> bsel_12_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("bsel_12_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> bsel_13_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("bsel_13_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> bsel_14_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("bsel_14_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> bsel_15_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("bsel_15_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> bsel_16_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("bsel_16_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> bsel_17_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("bsel_17_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> bsel_18_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("bsel_18_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> bsel_19_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("bsel_19_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> bsel_1_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("bsel_1_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> bsel_20_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("bsel_20_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> bsel_21_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("bsel_21_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> bsel_22_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("bsel_22_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> bsel_23_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("bsel_23_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> bsel_24_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("bsel_24_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> bsel_25_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("bsel_25_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> bsel_26_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("bsel_26_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> bsel_27_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("bsel_27_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> bsel_28_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("bsel_28_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> bsel_29_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("bsel_29_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> bsel_2_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("bsel_2_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> bsel_30_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("bsel_30_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> bsel_31_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("bsel_31_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> bsel_3_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("bsel_3_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> bsel_4_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("bsel_4_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> bsel_5_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("bsel_5_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> bsel_6_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("bsel_6_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> bsel_7_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("bsel_7_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> bsel_8_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("bsel_8_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> bsel_9_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("bsel_9_");

    NOR2_X1* NOR2_X1_1;
    AND2_X1* AND2_X1_1;
    NOR2_X1* NOR2_X1_2;
    NOR2_X1* NOR2_X1_3;
    AND2_X1* AND2_X1_2;
    NOR2_X1* NOR2_X1_4;
    NOR2_X1* NOR2_X1_5;
    AND2_X1* AND2_X1_3;
    NOR2_X1* NOR2_X1_6;
    NOR2_X1* NOR2_X1_7;
    AND2_X1* AND2_X1_4;
    NOR2_X1* NOR2_X1_8;
    NOR2_X1* NOR2_X1_9;
    AND2_X1* AND2_X1_5;
    NOR2_X1* NOR2_X1_10;
    NOR2_X1* NOR2_X1_11;
    AND2_X1* AND2_X1_6;
    NOR2_X1* NOR2_X1_12;
    NOR2_X1* NOR2_X1_13;
    AND2_X1* AND2_X1_7;
    NOR2_X1* NOR2_X1_14;
    NOR2_X1* NOR2_X1_15;
    AND2_X1* AND2_X1_8;
    NOR2_X1* NOR2_X1_16;
    NOR2_X1* NOR2_X1_17;
    AND2_X1* AND2_X1_9;
    NOR2_X1* NOR2_X1_18;
    NOR2_X1* NOR2_X1_19;
    AND2_X1* AND2_X1_10;
    NOR2_X1* NOR2_X1_20;
    NOR2_X1* NOR2_X1_21;
    AND2_X1* AND2_X1_11;
    NOR2_X1* NOR2_X1_22;
    NOR2_X1* NOR2_X1_23;
    AND2_X1* AND2_X1_12;
    NOR2_X1* NOR2_X1_24;
    NOR2_X1* NOR2_X1_25;
    AND2_X1* AND2_X1_13;
    NOR2_X1* NOR2_X1_26;
    NOR2_X1* NOR2_X1_27;
    AND2_X1* AND2_X1_14;
    NOR2_X1* NOR2_X1_28;
    NOR2_X1* NOR2_X1_29;
    AND2_X1* AND2_X1_15;
    NOR2_X1* NOR2_X1_30;
    NOR2_X1* NOR2_X1_31;
    AND2_X1* AND2_X1_16;
    NOR2_X1* NOR2_X1_32;
    NOR2_X1* NOR2_X1_33;
    AND2_X1* AND2_X1_17;
    NOR2_X1* NOR2_X1_34;
    NOR2_X1* NOR2_X1_35;
    AND2_X1* AND2_X1_18;
    NOR2_X1* NOR2_X1_36;
    NOR2_X1* NOR2_X1_37;
    AND2_X1* AND2_X1_19;
    NOR2_X1* NOR2_X1_38;
    NOR2_X1* NOR2_X1_39;
    AND2_X1* AND2_X1_20;
    NOR2_X1* NOR2_X1_40;
    NOR2_X1* NOR2_X1_41;
    AND2_X1* AND2_X1_21;
    NOR2_X1* NOR2_X1_42;
    NOR2_X1* NOR2_X1_43;
    AND2_X1* AND2_X1_22;
    NOR2_X1* NOR2_X1_44;
    NOR2_X1* NOR2_X1_45;
    AND2_X1* AND2_X1_23;
    NOR2_X1* NOR2_X1_46;
    NOR2_X1* NOR2_X1_47;
    AND2_X1* AND2_X1_24;
    NOR2_X1* NOR2_X1_48;
    NOR2_X1* NOR2_X1_49;
    AND2_X1* AND2_X1_25;
    NOR2_X1* NOR2_X1_50;
    NOR2_X1* NOR2_X1_51;
    AND2_X1* AND2_X1_26;
    NOR2_X1* NOR2_X1_52;
    NOR2_X1* NOR2_X1_53;
    AND2_X1* AND2_X1_27;
    NOR2_X1* NOR2_X1_54;
    NOR2_X1* NOR2_X1_55;
    AND2_X1* AND2_X1_28;
    NOR2_X1* NOR2_X1_56;
    NOR2_X1* NOR2_X1_57;
    AND2_X1* AND2_X1_29;
    NOR2_X1* NOR2_X1_58;
    NOR2_X1* NOR2_X1_59;
    AND2_X1* AND2_X1_30;
    NOR2_X1* NOR2_X1_60;
    NOR2_X1* NOR2_X1_61;
    AND2_X1* AND2_X1_31;
    NOR2_X1* NOR2_X1_62;
    NOR2_X1* NOR2_X1_63;
    AND2_X1* AND2_X1_32;
    NOR2_X1* NOR2_X1_64;
    INV_X1* INV_X1_1;
    NAND2_X1* NAND2_X1_1;
    OAI21_X1* OAI21_X1_1;
    INV_X1* INV_X1_2;
    NAND2_X1* NAND2_X1_2;
    OAI21_X1* OAI21_X1_2;
    INV_X1* INV_X1_3;
    NAND2_X1* NAND2_X1_3;
    OAI21_X1* OAI21_X1_3;
    INV_X1* INV_X1_4;
    NAND2_X1* NAND2_X1_4;
    OAI21_X1* OAI21_X1_4;
    INV_X1* INV_X1_5;
    NAND2_X1* NAND2_X1_5;
    OAI21_X1* OAI21_X1_5;
    INV_X1* INV_X1_6;
    NAND2_X1* NAND2_X1_6;
    OAI21_X1* OAI21_X1_6;
    INV_X1* INV_X1_7;
    NAND2_X1* NAND2_X1_7;
    OAI21_X1* OAI21_X1_7;
    INV_X1* INV_X1_8;
    NAND2_X1* NAND2_X1_8;
    OAI21_X1* OAI21_X1_8;
    INV_X1* INV_X1_9;
    NAND2_X1* NAND2_X1_9;
    OAI21_X1* OAI21_X1_9;
    INV_X1* INV_X1_10;
    NAND2_X1* NAND2_X1_10;
    OAI21_X1* OAI21_X1_10;
    INV_X1* INV_X1_11;
    NAND2_X1* NAND2_X1_11;
    OAI21_X1* OAI21_X1_11;
    INV_X1* INV_X1_12;
    NAND2_X1* NAND2_X1_12;
    OAI21_X1* OAI21_X1_12;
    INV_X1* INV_X1_13;
    NAND2_X1* NAND2_X1_13;
    OAI21_X1* OAI21_X1_13;
    INV_X1* INV_X1_14;
    NAND2_X1* NAND2_X1_14;
    OAI21_X1* OAI21_X1_14;
    INV_X1* INV_X1_15;
    NAND2_X1* NAND2_X1_15;
    OAI21_X1* OAI21_X1_15;
    INV_X1* INV_X1_16;
    NAND2_X1* NAND2_X1_16;
    OAI21_X1* OAI21_X1_16;
    INV_X1* INV_X1_17;
    NAND2_X1* NAND2_X1_17;
    OAI21_X1* OAI21_X1_17;
    INV_X1* INV_X1_18;
    NAND2_X1* NAND2_X1_18;
    OAI21_X1* OAI21_X1_18;
    INV_X1* INV_X1_19;
    NAND2_X1* NAND2_X1_19;
    OAI21_X1* OAI21_X1_19;
    INV_X1* INV_X1_20;
    NAND2_X1* NAND2_X1_20;
    OAI21_X1* OAI21_X1_20;
    INV_X1* INV_X1_21;
    NAND2_X1* NAND2_X1_21;
    OAI21_X1* OAI21_X1_21;
    INV_X1* INV_X1_22;
    NAND2_X1* NAND2_X1_22;
    OAI21_X1* OAI21_X1_22;
    INV_X1* INV_X1_23;
    NAND2_X1* NAND2_X1_23;
    OAI21_X1* OAI21_X1_23;
    INV_X1* INV_X1_24;
    NAND2_X1* NAND2_X1_24;
    OAI21_X1* OAI21_X1_24;
    INV_X1* INV_X1_25;
    NAND2_X1* NAND2_X1_25;
    OAI21_X1* OAI21_X1_25;
    INV_X1* INV_X1_26;
    NAND2_X1* NAND2_X1_26;
    OAI21_X1* OAI21_X1_26;
    INV_X1* INV_X1_27;
    NAND2_X1* NAND2_X1_27;
    OAI21_X1* OAI21_X1_27;
    INV_X1* INV_X1_28;
    NAND2_X1* NAND2_X1_28;
    OAI21_X1* OAI21_X1_28;
    INV_X1* INV_X1_29;
    NAND2_X1* NAND2_X1_29;
    OAI21_X1* OAI21_X1_29;
    INV_X1* INV_X1_30;
    NAND2_X1* NAND2_X1_30;
    OAI21_X1* OAI21_X1_30;
    INV_X1* INV_X1_31;
    NAND2_X1* NAND2_X1_31;
    OAI21_X1* OAI21_X1_31;
    INV_X1* INV_X1_32;
    NAND2_X1* NAND2_X1_32;
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
    BUF_X1* BUF_X1_52;
    BUF_X1* BUF_X1_53;
    BUF_X1* BUF_X1_54;
    BUF_X1* BUF_X1_55;
    BUF_X1* BUF_X1_56;
    BUF_X1* BUF_X1_57;
    BUF_X1* BUF_X1_58;
    BUF_X1* BUF_X1_59;
    BUF_X1* BUF_X1_60;
    BUF_X1* BUF_X1_61;
    BUF_X1* BUF_X1_62;
    BUF_X1* BUF_X1_63;
    BUF_X1* BUF_X1_64;
    BUF_X1* BUF_X1_65;
    BUF_X1* BUF_X1_66;
    BUF_X1* BUF_X1_67;
    BUF_X1* BUF_X1_68;
    BUF_X1* BUF_X1_69;
    BUF_X1* BUF_X1_70;
    BUF_X1* BUF_X1_71;
    BUF_X1* BUF_X1_72;
    BUF_X1* BUF_X1_73;
    BUF_X1* BUF_X1_74;
    BUF_X1* BUF_X1_75;
    BUF_X1* BUF_X1_76;
    BUF_X1* BUF_X1_77;
    BUF_X1* BUF_X1_78;
    BUF_X1* BUF_X1_79;
    BUF_X1* BUF_X1_80;
    BUF_X1* BUF_X1_81;
    BUF_X1* BUF_X1_82;
    BUF_X1* BUF_X1_83;
    BUF_X1* BUF_X1_84;
    BUF_X1* BUF_X1_85;
    BUF_X1* BUF_X1_86;
    BUF_X1* BUF_X1_87;
    BUF_X1* BUF_X1_88;
    BUF_X1* BUF_X1_89;
    BUF_X1* BUF_X1_90;
    BUF_X1* BUF_X1_91;
    BUF_X1* BUF_X1_92;
    BUF_X1* BUF_X1_93;
    BUF_X1* BUF_X1_94;
    BUF_X1* BUF_X1_95;
    BUF_X1* BUF_X1_96;
    BUF_X1* BUF_X1_97;
    BUF_X1* BUF_X1_98;
    BUF_X1* BUF_X1_99;
    _paramod_aftab_adder_size_s32_00000000000000000000000000100000* adder_sub;

SC_CTOR( aftab_adder_subtractor ) {
    NOR2_X1_1 = new NOR2_X1("NOR2_X1_1");
        NOR2_X1_1->A1(S133);
        NOR2_X1_1->A2(S129[0]);
        NOR2_X1_1->ZN(S0);

    AND2_X1_1 = new AND2_X1("AND2_X1_1");
        AND2_X1_1->A1(S129[0]);
        AND2_X1_1->A2(S133);
        AND2_X1_1->ZN(S1);

    NOR2_X1_2 = new NOR2_X1("NOR2_X1_2");
        NOR2_X1_2->A1(S1);
        NOR2_X1_2->A2(S0);
        NOR2_X1_2->ZN(bsel_0_);

    NOR2_X1_3 = new NOR2_X1("NOR2_X1_3");
        NOR2_X1_3->A1(S133);
        NOR2_X1_3->A2(S129[1]);
        NOR2_X1_3->ZN(S2);

    AND2_X1_2 = new AND2_X1("AND2_X1_2");
        AND2_X1_2->A1(S129[1]);
        AND2_X1_2->A2(S133);
        AND2_X1_2->ZN(S3);

    NOR2_X1_4 = new NOR2_X1("NOR2_X1_4");
        NOR2_X1_4->A1(S3);
        NOR2_X1_4->A2(S2);
        NOR2_X1_4->ZN(bsel_1_);

    NOR2_X1_5 = new NOR2_X1("NOR2_X1_5");
        NOR2_X1_5->A1(S133);
        NOR2_X1_5->A2(S129[2]);
        NOR2_X1_5->ZN(S4);

    AND2_X1_3 = new AND2_X1("AND2_X1_3");
        AND2_X1_3->A1(S129[2]);
        AND2_X1_3->A2(S133);
        AND2_X1_3->ZN(S5);

    NOR2_X1_6 = new NOR2_X1("NOR2_X1_6");
        NOR2_X1_6->A1(S5);
        NOR2_X1_6->A2(S4);
        NOR2_X1_6->ZN(bsel_2_);

    NOR2_X1_7 = new NOR2_X1("NOR2_X1_7");
        NOR2_X1_7->A1(S133);
        NOR2_X1_7->A2(S129[3]);
        NOR2_X1_7->ZN(S6);

    AND2_X1_4 = new AND2_X1("AND2_X1_4");
        AND2_X1_4->A1(S129[3]);
        AND2_X1_4->A2(S133);
        AND2_X1_4->ZN(S7);

    NOR2_X1_8 = new NOR2_X1("NOR2_X1_8");
        NOR2_X1_8->A1(S7);
        NOR2_X1_8->A2(S6);
        NOR2_X1_8->ZN(bsel_3_);

    NOR2_X1_9 = new NOR2_X1("NOR2_X1_9");
        NOR2_X1_9->A1(S133);
        NOR2_X1_9->A2(S129[4]);
        NOR2_X1_9->ZN(S8);

    AND2_X1_5 = new AND2_X1("AND2_X1_5");
        AND2_X1_5->A1(S129[4]);
        AND2_X1_5->A2(S133);
        AND2_X1_5->ZN(S9);

    NOR2_X1_10 = new NOR2_X1("NOR2_X1_10");
        NOR2_X1_10->A1(S9);
        NOR2_X1_10->A2(S8);
        NOR2_X1_10->ZN(bsel_4_);

    NOR2_X1_11 = new NOR2_X1("NOR2_X1_11");
        NOR2_X1_11->A1(S133);
        NOR2_X1_11->A2(S129[5]);
        NOR2_X1_11->ZN(S10);

    AND2_X1_6 = new AND2_X1("AND2_X1_6");
        AND2_X1_6->A1(S129[5]);
        AND2_X1_6->A2(S133);
        AND2_X1_6->ZN(S11);

    NOR2_X1_12 = new NOR2_X1("NOR2_X1_12");
        NOR2_X1_12->A1(S11);
        NOR2_X1_12->A2(S10);
        NOR2_X1_12->ZN(bsel_5_);

    NOR2_X1_13 = new NOR2_X1("NOR2_X1_13");
        NOR2_X1_13->A1(S133);
        NOR2_X1_13->A2(S129[6]);
        NOR2_X1_13->ZN(S12);

    AND2_X1_7 = new AND2_X1("AND2_X1_7");
        AND2_X1_7->A1(S129[6]);
        AND2_X1_7->A2(S133);
        AND2_X1_7->ZN(S13);

    NOR2_X1_14 = new NOR2_X1("NOR2_X1_14");
        NOR2_X1_14->A1(S13);
        NOR2_X1_14->A2(S12);
        NOR2_X1_14->ZN(bsel_6_);

    NOR2_X1_15 = new NOR2_X1("NOR2_X1_15");
        NOR2_X1_15->A1(S133);
        NOR2_X1_15->A2(S129[7]);
        NOR2_X1_15->ZN(S14);

    AND2_X1_8 = new AND2_X1("AND2_X1_8");
        AND2_X1_8->A1(S129[7]);
        AND2_X1_8->A2(S133);
        AND2_X1_8->ZN(S15);

    NOR2_X1_16 = new NOR2_X1("NOR2_X1_16");
        NOR2_X1_16->A1(S15);
        NOR2_X1_16->A2(S14);
        NOR2_X1_16->ZN(bsel_7_);

    NOR2_X1_17 = new NOR2_X1("NOR2_X1_17");
        NOR2_X1_17->A1(S133);
        NOR2_X1_17->A2(S129[8]);
        NOR2_X1_17->ZN(S16);

    AND2_X1_9 = new AND2_X1("AND2_X1_9");
        AND2_X1_9->A1(S129[8]);
        AND2_X1_9->A2(S133);
        AND2_X1_9->ZN(S17);

    NOR2_X1_18 = new NOR2_X1("NOR2_X1_18");
        NOR2_X1_18->A1(S17);
        NOR2_X1_18->A2(S16);
        NOR2_X1_18->ZN(bsel_8_);

    NOR2_X1_19 = new NOR2_X1("NOR2_X1_19");
        NOR2_X1_19->A1(S133);
        NOR2_X1_19->A2(S129[9]);
        NOR2_X1_19->ZN(S18);

    AND2_X1_10 = new AND2_X1("AND2_X1_10");
        AND2_X1_10->A1(S129[9]);
        AND2_X1_10->A2(S133);
        AND2_X1_10->ZN(S19);

    NOR2_X1_20 = new NOR2_X1("NOR2_X1_20");
        NOR2_X1_20->A1(S19);
        NOR2_X1_20->A2(S18);
        NOR2_X1_20->ZN(bsel_9_);

    NOR2_X1_21 = new NOR2_X1("NOR2_X1_21");
        NOR2_X1_21->A1(S133);
        NOR2_X1_21->A2(S129[10]);
        NOR2_X1_21->ZN(S20);

    AND2_X1_11 = new AND2_X1("AND2_X1_11");
        AND2_X1_11->A1(S129[10]);
        AND2_X1_11->A2(S133);
        AND2_X1_11->ZN(S21);

    NOR2_X1_22 = new NOR2_X1("NOR2_X1_22");
        NOR2_X1_22->A1(S21);
        NOR2_X1_22->A2(S20);
        NOR2_X1_22->ZN(bsel_10_);

    NOR2_X1_23 = new NOR2_X1("NOR2_X1_23");
        NOR2_X1_23->A1(S133);
        NOR2_X1_23->A2(S129[11]);
        NOR2_X1_23->ZN(S22);

    AND2_X1_12 = new AND2_X1("AND2_X1_12");
        AND2_X1_12->A1(S129[11]);
        AND2_X1_12->A2(S133);
        AND2_X1_12->ZN(S23);

    NOR2_X1_24 = new NOR2_X1("NOR2_X1_24");
        NOR2_X1_24->A1(S23);
        NOR2_X1_24->A2(S22);
        NOR2_X1_24->ZN(bsel_11_);

    NOR2_X1_25 = new NOR2_X1("NOR2_X1_25");
        NOR2_X1_25->A1(S133);
        NOR2_X1_25->A2(S129[12]);
        NOR2_X1_25->ZN(S24);

    AND2_X1_13 = new AND2_X1("AND2_X1_13");
        AND2_X1_13->A1(S129[12]);
        AND2_X1_13->A2(S133);
        AND2_X1_13->ZN(S25);

    NOR2_X1_26 = new NOR2_X1("NOR2_X1_26");
        NOR2_X1_26->A1(S25);
        NOR2_X1_26->A2(S24);
        NOR2_X1_26->ZN(bsel_12_);

    NOR2_X1_27 = new NOR2_X1("NOR2_X1_27");
        NOR2_X1_27->A1(S133);
        NOR2_X1_27->A2(S129[13]);
        NOR2_X1_27->ZN(S26);

    AND2_X1_14 = new AND2_X1("AND2_X1_14");
        AND2_X1_14->A1(S129[13]);
        AND2_X1_14->A2(S133);
        AND2_X1_14->ZN(S27);

    NOR2_X1_28 = new NOR2_X1("NOR2_X1_28");
        NOR2_X1_28->A1(S27);
        NOR2_X1_28->A2(S26);
        NOR2_X1_28->ZN(bsel_13_);

    NOR2_X1_29 = new NOR2_X1("NOR2_X1_29");
        NOR2_X1_29->A1(S133);
        NOR2_X1_29->A2(S129[14]);
        NOR2_X1_29->ZN(S28);

    AND2_X1_15 = new AND2_X1("AND2_X1_15");
        AND2_X1_15->A1(S129[14]);
        AND2_X1_15->A2(S133);
        AND2_X1_15->ZN(S29);

    NOR2_X1_30 = new NOR2_X1("NOR2_X1_30");
        NOR2_X1_30->A1(S29);
        NOR2_X1_30->A2(S28);
        NOR2_X1_30->ZN(bsel_14_);

    NOR2_X1_31 = new NOR2_X1("NOR2_X1_31");
        NOR2_X1_31->A1(S133);
        NOR2_X1_31->A2(S129[15]);
        NOR2_X1_31->ZN(S30);

    AND2_X1_16 = new AND2_X1("AND2_X1_16");
        AND2_X1_16->A1(S129[15]);
        AND2_X1_16->A2(S133);
        AND2_X1_16->ZN(S31);

    NOR2_X1_32 = new NOR2_X1("NOR2_X1_32");
        NOR2_X1_32->A1(S31);
        NOR2_X1_32->A2(S30);
        NOR2_X1_32->ZN(bsel_15_);

    NOR2_X1_33 = new NOR2_X1("NOR2_X1_33");
        NOR2_X1_33->A1(S133);
        NOR2_X1_33->A2(S129[16]);
        NOR2_X1_33->ZN(S32);

    AND2_X1_17 = new AND2_X1("AND2_X1_17");
        AND2_X1_17->A1(S129[16]);
        AND2_X1_17->A2(S133);
        AND2_X1_17->ZN(S33);

    NOR2_X1_34 = new NOR2_X1("NOR2_X1_34");
        NOR2_X1_34->A1(S33);
        NOR2_X1_34->A2(S32);
        NOR2_X1_34->ZN(bsel_16_);

    NOR2_X1_35 = new NOR2_X1("NOR2_X1_35");
        NOR2_X1_35->A1(S133);
        NOR2_X1_35->A2(S129[17]);
        NOR2_X1_35->ZN(S34);

    AND2_X1_18 = new AND2_X1("AND2_X1_18");
        AND2_X1_18->A1(S129[17]);
        AND2_X1_18->A2(S133);
        AND2_X1_18->ZN(S35);

    NOR2_X1_36 = new NOR2_X1("NOR2_X1_36");
        NOR2_X1_36->A1(S35);
        NOR2_X1_36->A2(S34);
        NOR2_X1_36->ZN(bsel_17_);

    NOR2_X1_37 = new NOR2_X1("NOR2_X1_37");
        NOR2_X1_37->A1(S133);
        NOR2_X1_37->A2(S129[18]);
        NOR2_X1_37->ZN(S36);

    AND2_X1_19 = new AND2_X1("AND2_X1_19");
        AND2_X1_19->A1(S129[18]);
        AND2_X1_19->A2(S133);
        AND2_X1_19->ZN(S37);

    NOR2_X1_38 = new NOR2_X1("NOR2_X1_38");
        NOR2_X1_38->A1(S37);
        NOR2_X1_38->A2(S36);
        NOR2_X1_38->ZN(bsel_18_);

    NOR2_X1_39 = new NOR2_X1("NOR2_X1_39");
        NOR2_X1_39->A1(S133);
        NOR2_X1_39->A2(S129[19]);
        NOR2_X1_39->ZN(S38);

    AND2_X1_20 = new AND2_X1("AND2_X1_20");
        AND2_X1_20->A1(S129[19]);
        AND2_X1_20->A2(S133);
        AND2_X1_20->ZN(S39);

    NOR2_X1_40 = new NOR2_X1("NOR2_X1_40");
        NOR2_X1_40->A1(S39);
        NOR2_X1_40->A2(S38);
        NOR2_X1_40->ZN(bsel_19_);

    NOR2_X1_41 = new NOR2_X1("NOR2_X1_41");
        NOR2_X1_41->A1(S133);
        NOR2_X1_41->A2(S129[20]);
        NOR2_X1_41->ZN(S40);

    AND2_X1_21 = new AND2_X1("AND2_X1_21");
        AND2_X1_21->A1(S129[20]);
        AND2_X1_21->A2(S133);
        AND2_X1_21->ZN(S41);

    NOR2_X1_42 = new NOR2_X1("NOR2_X1_42");
        NOR2_X1_42->A1(S41);
        NOR2_X1_42->A2(S40);
        NOR2_X1_42->ZN(bsel_20_);

    NOR2_X1_43 = new NOR2_X1("NOR2_X1_43");
        NOR2_X1_43->A1(S133);
        NOR2_X1_43->A2(S129[21]);
        NOR2_X1_43->ZN(S42);

    AND2_X1_22 = new AND2_X1("AND2_X1_22");
        AND2_X1_22->A1(S129[21]);
        AND2_X1_22->A2(S133);
        AND2_X1_22->ZN(S43);

    NOR2_X1_44 = new NOR2_X1("NOR2_X1_44");
        NOR2_X1_44->A1(S43);
        NOR2_X1_44->A2(S42);
        NOR2_X1_44->ZN(bsel_21_);

    NOR2_X1_45 = new NOR2_X1("NOR2_X1_45");
        NOR2_X1_45->A1(S133);
        NOR2_X1_45->A2(S129[22]);
        NOR2_X1_45->ZN(S44);

    AND2_X1_23 = new AND2_X1("AND2_X1_23");
        AND2_X1_23->A1(S129[22]);
        AND2_X1_23->A2(S133);
        AND2_X1_23->ZN(S45);

    NOR2_X1_46 = new NOR2_X1("NOR2_X1_46");
        NOR2_X1_46->A1(S45);
        NOR2_X1_46->A2(S44);
        NOR2_X1_46->ZN(bsel_22_);

    NOR2_X1_47 = new NOR2_X1("NOR2_X1_47");
        NOR2_X1_47->A1(S133);
        NOR2_X1_47->A2(S129[23]);
        NOR2_X1_47->ZN(S46);

    AND2_X1_24 = new AND2_X1("AND2_X1_24");
        AND2_X1_24->A1(S129[23]);
        AND2_X1_24->A2(S133);
        AND2_X1_24->ZN(S47);

    NOR2_X1_48 = new NOR2_X1("NOR2_X1_48");
        NOR2_X1_48->A1(S47);
        NOR2_X1_48->A2(S46);
        NOR2_X1_48->ZN(bsel_23_);

    NOR2_X1_49 = new NOR2_X1("NOR2_X1_49");
        NOR2_X1_49->A1(S133);
        NOR2_X1_49->A2(S129[24]);
        NOR2_X1_49->ZN(S48);

    AND2_X1_25 = new AND2_X1("AND2_X1_25");
        AND2_X1_25->A1(S129[24]);
        AND2_X1_25->A2(S133);
        AND2_X1_25->ZN(S49);

    NOR2_X1_50 = new NOR2_X1("NOR2_X1_50");
        NOR2_X1_50->A1(S49);
        NOR2_X1_50->A2(S48);
        NOR2_X1_50->ZN(bsel_24_);

    NOR2_X1_51 = new NOR2_X1("NOR2_X1_51");
        NOR2_X1_51->A1(S133);
        NOR2_X1_51->A2(S129[25]);
        NOR2_X1_51->ZN(S50);

    AND2_X1_26 = new AND2_X1("AND2_X1_26");
        AND2_X1_26->A1(S129[25]);
        AND2_X1_26->A2(S133);
        AND2_X1_26->ZN(S51);

    NOR2_X1_52 = new NOR2_X1("NOR2_X1_52");
        NOR2_X1_52->A1(S51);
        NOR2_X1_52->A2(S50);
        NOR2_X1_52->ZN(bsel_25_);

    NOR2_X1_53 = new NOR2_X1("NOR2_X1_53");
        NOR2_X1_53->A1(S133);
        NOR2_X1_53->A2(S129[26]);
        NOR2_X1_53->ZN(S52);

    AND2_X1_27 = new AND2_X1("AND2_X1_27");
        AND2_X1_27->A1(S129[26]);
        AND2_X1_27->A2(S133);
        AND2_X1_27->ZN(S53);

    NOR2_X1_54 = new NOR2_X1("NOR2_X1_54");
        NOR2_X1_54->A1(S53);
        NOR2_X1_54->A2(S52);
        NOR2_X1_54->ZN(bsel_26_);

    NOR2_X1_55 = new NOR2_X1("NOR2_X1_55");
        NOR2_X1_55->A1(S133);
        NOR2_X1_55->A2(S129[27]);
        NOR2_X1_55->ZN(S54);

    AND2_X1_28 = new AND2_X1("AND2_X1_28");
        AND2_X1_28->A1(S129[27]);
        AND2_X1_28->A2(S133);
        AND2_X1_28->ZN(S55);

    NOR2_X1_56 = new NOR2_X1("NOR2_X1_56");
        NOR2_X1_56->A1(S55);
        NOR2_X1_56->A2(S54);
        NOR2_X1_56->ZN(bsel_27_);

    NOR2_X1_57 = new NOR2_X1("NOR2_X1_57");
        NOR2_X1_57->A1(S133);
        NOR2_X1_57->A2(S129[28]);
        NOR2_X1_57->ZN(S56);

    AND2_X1_29 = new AND2_X1("AND2_X1_29");
        AND2_X1_29->A1(S129[28]);
        AND2_X1_29->A2(S133);
        AND2_X1_29->ZN(S57);

    NOR2_X1_58 = new NOR2_X1("NOR2_X1_58");
        NOR2_X1_58->A1(S57);
        NOR2_X1_58->A2(S56);
        NOR2_X1_58->ZN(bsel_28_);

    NOR2_X1_59 = new NOR2_X1("NOR2_X1_59");
        NOR2_X1_59->A1(S133);
        NOR2_X1_59->A2(S129[29]);
        NOR2_X1_59->ZN(S58);

    AND2_X1_30 = new AND2_X1("AND2_X1_30");
        AND2_X1_30->A1(S129[29]);
        AND2_X1_30->A2(S133);
        AND2_X1_30->ZN(S59);

    NOR2_X1_60 = new NOR2_X1("NOR2_X1_60");
        NOR2_X1_60->A1(S59);
        NOR2_X1_60->A2(S58);
        NOR2_X1_60->ZN(bsel_29_);

    NOR2_X1_61 = new NOR2_X1("NOR2_X1_61");
        NOR2_X1_61->A1(S133);
        NOR2_X1_61->A2(S129[30]);
        NOR2_X1_61->ZN(S60);

    AND2_X1_31 = new AND2_X1("AND2_X1_31");
        AND2_X1_31->A1(S129[30]);
        AND2_X1_31->A2(S133);
        AND2_X1_31->ZN(S61);

    NOR2_X1_62 = new NOR2_X1("NOR2_X1_62");
        NOR2_X1_62->A1(S61);
        NOR2_X1_62->A2(S60);
        NOR2_X1_62->ZN(bsel_30_);

    NOR2_X1_63 = new NOR2_X1("NOR2_X1_63");
        NOR2_X1_63->A1(S133);
        NOR2_X1_63->A2(S129[31]);
        NOR2_X1_63->ZN(S62);

    AND2_X1_32 = new AND2_X1("AND2_X1_32");
        AND2_X1_32->A1(S129[31]);
        AND2_X1_32->A2(S133);
        AND2_X1_32->ZN(S63);

    NOR2_X1_64 = new NOR2_X1("NOR2_X1_64");
        NOR2_X1_64->A1(S63);
        NOR2_X1_64->A2(S62);
        NOR2_X1_64->ZN(bsel_31_);

    INV_X1_1 = new INV_X1("INV_X1_1");
        INV_X1_1->A(addSubRes_0_);
        INV_X1_1->ZN(S64);

    NAND2_X1_1 = new NAND2_X1("NAND2_X1_1");
        NAND2_X1_1->A1(S129[0]);
        NAND2_X1_1->A2(S131);
        NAND2_X1_1->ZN(S65);

    OAI21_X1_1 = new OAI21_X1("OAI21_X1_1");
        OAI21_X1_1->A(S65);
        OAI21_X1_1->B1(S64);
        OAI21_X1_1->B2(S131);
        OAI21_X1_1->ZN(S132[0]);

    INV_X1_2 = new INV_X1("INV_X1_2");
        INV_X1_2->A(addSubRes_1_);
        INV_X1_2->ZN(S66);

    NAND2_X1_2 = new NAND2_X1("NAND2_X1_2");
        NAND2_X1_2->A1(S129[1]);
        NAND2_X1_2->A2(S131);
        NAND2_X1_2->ZN(S67);

    OAI21_X1_2 = new OAI21_X1("OAI21_X1_2");
        OAI21_X1_2->A(S67);
        OAI21_X1_2->B1(S66);
        OAI21_X1_2->B2(S131);
        OAI21_X1_2->ZN(S132[1]);

    INV_X1_3 = new INV_X1("INV_X1_3");
        INV_X1_3->A(addSubRes_2_);
        INV_X1_3->ZN(S68);

    NAND2_X1_3 = new NAND2_X1("NAND2_X1_3");
        NAND2_X1_3->A1(S129[2]);
        NAND2_X1_3->A2(S131);
        NAND2_X1_3->ZN(S69);

    OAI21_X1_3 = new OAI21_X1("OAI21_X1_3");
        OAI21_X1_3->A(S69);
        OAI21_X1_3->B1(S68);
        OAI21_X1_3->B2(S131);
        OAI21_X1_3->ZN(S132[2]);

    INV_X1_4 = new INV_X1("INV_X1_4");
        INV_X1_4->A(addSubRes_3_);
        INV_X1_4->ZN(S70);

    NAND2_X1_4 = new NAND2_X1("NAND2_X1_4");
        NAND2_X1_4->A1(S129[3]);
        NAND2_X1_4->A2(S131);
        NAND2_X1_4->ZN(S71);

    OAI21_X1_4 = new OAI21_X1("OAI21_X1_4");
        OAI21_X1_4->A(S71);
        OAI21_X1_4->B1(S70);
        OAI21_X1_4->B2(S131);
        OAI21_X1_4->ZN(S132[3]);

    INV_X1_5 = new INV_X1("INV_X1_5");
        INV_X1_5->A(addSubRes_4_);
        INV_X1_5->ZN(S72);

    NAND2_X1_5 = new NAND2_X1("NAND2_X1_5");
        NAND2_X1_5->A1(S129[4]);
        NAND2_X1_5->A2(S131);
        NAND2_X1_5->ZN(S73);

    OAI21_X1_5 = new OAI21_X1("OAI21_X1_5");
        OAI21_X1_5->A(S73);
        OAI21_X1_5->B1(S72);
        OAI21_X1_5->B2(S131);
        OAI21_X1_5->ZN(S132[4]);

    INV_X1_6 = new INV_X1("INV_X1_6");
        INV_X1_6->A(addSubRes_5_);
        INV_X1_6->ZN(S74);

    NAND2_X1_6 = new NAND2_X1("NAND2_X1_6");
        NAND2_X1_6->A1(S129[5]);
        NAND2_X1_6->A2(S131);
        NAND2_X1_6->ZN(S75);

    OAI21_X1_6 = new OAI21_X1("OAI21_X1_6");
        OAI21_X1_6->A(S75);
        OAI21_X1_6->B1(S74);
        OAI21_X1_6->B2(S131);
        OAI21_X1_6->ZN(S132[5]);

    INV_X1_7 = new INV_X1("INV_X1_7");
        INV_X1_7->A(addSubRes_6_);
        INV_X1_7->ZN(S76);

    NAND2_X1_7 = new NAND2_X1("NAND2_X1_7");
        NAND2_X1_7->A1(S129[6]);
        NAND2_X1_7->A2(S131);
        NAND2_X1_7->ZN(S77);

    OAI21_X1_7 = new OAI21_X1("OAI21_X1_7");
        OAI21_X1_7->A(S77);
        OAI21_X1_7->B1(S76);
        OAI21_X1_7->B2(S131);
        OAI21_X1_7->ZN(S132[6]);

    INV_X1_8 = new INV_X1("INV_X1_8");
        INV_X1_8->A(addSubRes_7_);
        INV_X1_8->ZN(S78);

    NAND2_X1_8 = new NAND2_X1("NAND2_X1_8");
        NAND2_X1_8->A1(S129[7]);
        NAND2_X1_8->A2(S131);
        NAND2_X1_8->ZN(S79);

    OAI21_X1_8 = new OAI21_X1("OAI21_X1_8");
        OAI21_X1_8->A(S79);
        OAI21_X1_8->B1(S78);
        OAI21_X1_8->B2(S131);
        OAI21_X1_8->ZN(S132[7]);

    INV_X1_9 = new INV_X1("INV_X1_9");
        INV_X1_9->A(addSubRes_8_);
        INV_X1_9->ZN(S80);

    NAND2_X1_9 = new NAND2_X1("NAND2_X1_9");
        NAND2_X1_9->A1(S129[8]);
        NAND2_X1_9->A2(S131);
        NAND2_X1_9->ZN(S81);

    OAI21_X1_9 = new OAI21_X1("OAI21_X1_9");
        OAI21_X1_9->A(S81);
        OAI21_X1_9->B1(S80);
        OAI21_X1_9->B2(S131);
        OAI21_X1_9->ZN(S132[8]);

    INV_X1_10 = new INV_X1("INV_X1_10");
        INV_X1_10->A(addSubRes_9_);
        INV_X1_10->ZN(S82);

    NAND2_X1_10 = new NAND2_X1("NAND2_X1_10");
        NAND2_X1_10->A1(S129[9]);
        NAND2_X1_10->A2(S131);
        NAND2_X1_10->ZN(S83);

    OAI21_X1_10 = new OAI21_X1("OAI21_X1_10");
        OAI21_X1_10->A(S83);
        OAI21_X1_10->B1(S82);
        OAI21_X1_10->B2(S131);
        OAI21_X1_10->ZN(S132[9]);

    INV_X1_11 = new INV_X1("INV_X1_11");
        INV_X1_11->A(addSubRes_10_);
        INV_X1_11->ZN(S84);

    NAND2_X1_11 = new NAND2_X1("NAND2_X1_11");
        NAND2_X1_11->A1(S129[10]);
        NAND2_X1_11->A2(S131);
        NAND2_X1_11->ZN(S85);

    OAI21_X1_11 = new OAI21_X1("OAI21_X1_11");
        OAI21_X1_11->A(S85);
        OAI21_X1_11->B1(S84);
        OAI21_X1_11->B2(S131);
        OAI21_X1_11->ZN(S132[10]);

    INV_X1_12 = new INV_X1("INV_X1_12");
        INV_X1_12->A(addSubRes_11_);
        INV_X1_12->ZN(S86);

    NAND2_X1_12 = new NAND2_X1("NAND2_X1_12");
        NAND2_X1_12->A1(S129[11]);
        NAND2_X1_12->A2(S131);
        NAND2_X1_12->ZN(S87);

    OAI21_X1_12 = new OAI21_X1("OAI21_X1_12");
        OAI21_X1_12->A(S87);
        OAI21_X1_12->B1(S86);
        OAI21_X1_12->B2(S131);
        OAI21_X1_12->ZN(S132[11]);

    INV_X1_13 = new INV_X1("INV_X1_13");
        INV_X1_13->A(addSubRes_12_);
        INV_X1_13->ZN(S88);

    NAND2_X1_13 = new NAND2_X1("NAND2_X1_13");
        NAND2_X1_13->A1(S129[12]);
        NAND2_X1_13->A2(S131);
        NAND2_X1_13->ZN(S89);

    OAI21_X1_13 = new OAI21_X1("OAI21_X1_13");
        OAI21_X1_13->A(S89);
        OAI21_X1_13->B1(S88);
        OAI21_X1_13->B2(S131);
        OAI21_X1_13->ZN(S132[12]);

    INV_X1_14 = new INV_X1("INV_X1_14");
        INV_X1_14->A(addSubRes_13_);
        INV_X1_14->ZN(S90);

    NAND2_X1_14 = new NAND2_X1("NAND2_X1_14");
        NAND2_X1_14->A1(S129[13]);
        NAND2_X1_14->A2(S131);
        NAND2_X1_14->ZN(S91);

    OAI21_X1_14 = new OAI21_X1("OAI21_X1_14");
        OAI21_X1_14->A(S91);
        OAI21_X1_14->B1(S90);
        OAI21_X1_14->B2(S131);
        OAI21_X1_14->ZN(S132[13]);

    INV_X1_15 = new INV_X1("INV_X1_15");
        INV_X1_15->A(addSubRes_14_);
        INV_X1_15->ZN(S92);

    NAND2_X1_15 = new NAND2_X1("NAND2_X1_15");
        NAND2_X1_15->A1(S129[14]);
        NAND2_X1_15->A2(S131);
        NAND2_X1_15->ZN(S93);

    OAI21_X1_15 = new OAI21_X1("OAI21_X1_15");
        OAI21_X1_15->A(S93);
        OAI21_X1_15->B1(S92);
        OAI21_X1_15->B2(S131);
        OAI21_X1_15->ZN(S132[14]);

    INV_X1_16 = new INV_X1("INV_X1_16");
        INV_X1_16->A(addSubRes_15_);
        INV_X1_16->ZN(S94);

    NAND2_X1_16 = new NAND2_X1("NAND2_X1_16");
        NAND2_X1_16->A1(S129[15]);
        NAND2_X1_16->A2(S131);
        NAND2_X1_16->ZN(S95);

    OAI21_X1_16 = new OAI21_X1("OAI21_X1_16");
        OAI21_X1_16->A(S95);
        OAI21_X1_16->B1(S94);
        OAI21_X1_16->B2(S131);
        OAI21_X1_16->ZN(S132[15]);

    INV_X1_17 = new INV_X1("INV_X1_17");
        INV_X1_17->A(addSubRes_16_);
        INV_X1_17->ZN(S96);

    NAND2_X1_17 = new NAND2_X1("NAND2_X1_17");
        NAND2_X1_17->A1(S129[16]);
        NAND2_X1_17->A2(S131);
        NAND2_X1_17->ZN(S97);

    OAI21_X1_17 = new OAI21_X1("OAI21_X1_17");
        OAI21_X1_17->A(S97);
        OAI21_X1_17->B1(S96);
        OAI21_X1_17->B2(S131);
        OAI21_X1_17->ZN(S132[16]);

    INV_X1_18 = new INV_X1("INV_X1_18");
        INV_X1_18->A(addSubRes_17_);
        INV_X1_18->ZN(S98);

    NAND2_X1_18 = new NAND2_X1("NAND2_X1_18");
        NAND2_X1_18->A1(S129[17]);
        NAND2_X1_18->A2(S131);
        NAND2_X1_18->ZN(S99);

    OAI21_X1_18 = new OAI21_X1("OAI21_X1_18");
        OAI21_X1_18->A(S99);
        OAI21_X1_18->B1(S98);
        OAI21_X1_18->B2(S131);
        OAI21_X1_18->ZN(S132[17]);

    INV_X1_19 = new INV_X1("INV_X1_19");
        INV_X1_19->A(addSubRes_18_);
        INV_X1_19->ZN(S100);

    NAND2_X1_19 = new NAND2_X1("NAND2_X1_19");
        NAND2_X1_19->A1(S129[18]);
        NAND2_X1_19->A2(S131);
        NAND2_X1_19->ZN(S101);

    OAI21_X1_19 = new OAI21_X1("OAI21_X1_19");
        OAI21_X1_19->A(S101);
        OAI21_X1_19->B1(S100);
        OAI21_X1_19->B2(S131);
        OAI21_X1_19->ZN(S132[18]);

    INV_X1_20 = new INV_X1("INV_X1_20");
        INV_X1_20->A(addSubRes_19_);
        INV_X1_20->ZN(S102);

    NAND2_X1_20 = new NAND2_X1("NAND2_X1_20");
        NAND2_X1_20->A1(S129[19]);
        NAND2_X1_20->A2(S131);
        NAND2_X1_20->ZN(S103);

    OAI21_X1_20 = new OAI21_X1("OAI21_X1_20");
        OAI21_X1_20->A(S103);
        OAI21_X1_20->B1(S102);
        OAI21_X1_20->B2(S131);
        OAI21_X1_20->ZN(S132[19]);

    INV_X1_21 = new INV_X1("INV_X1_21");
        INV_X1_21->A(addSubRes_20_);
        INV_X1_21->ZN(S104);

    NAND2_X1_21 = new NAND2_X1("NAND2_X1_21");
        NAND2_X1_21->A1(S129[20]);
        NAND2_X1_21->A2(S131);
        NAND2_X1_21->ZN(S105);

    OAI21_X1_21 = new OAI21_X1("OAI21_X1_21");
        OAI21_X1_21->A(S105);
        OAI21_X1_21->B1(S104);
        OAI21_X1_21->B2(S131);
        OAI21_X1_21->ZN(S132[20]);

    INV_X1_22 = new INV_X1("INV_X1_22");
        INV_X1_22->A(addSubRes_21_);
        INV_X1_22->ZN(S106);

    NAND2_X1_22 = new NAND2_X1("NAND2_X1_22");
        NAND2_X1_22->A1(S129[21]);
        NAND2_X1_22->A2(S131);
        NAND2_X1_22->ZN(S107);

    OAI21_X1_22 = new OAI21_X1("OAI21_X1_22");
        OAI21_X1_22->A(S107);
        OAI21_X1_22->B1(S106);
        OAI21_X1_22->B2(S131);
        OAI21_X1_22->ZN(S132[21]);

    INV_X1_23 = new INV_X1("INV_X1_23");
        INV_X1_23->A(addSubRes_22_);
        INV_X1_23->ZN(S108);

    NAND2_X1_23 = new NAND2_X1("NAND2_X1_23");
        NAND2_X1_23->A1(S129[22]);
        NAND2_X1_23->A2(S131);
        NAND2_X1_23->ZN(S109);

    OAI21_X1_23 = new OAI21_X1("OAI21_X1_23");
        OAI21_X1_23->A(S109);
        OAI21_X1_23->B1(S108);
        OAI21_X1_23->B2(S131);
        OAI21_X1_23->ZN(S132[22]);

    INV_X1_24 = new INV_X1("INV_X1_24");
        INV_X1_24->A(addSubRes_23_);
        INV_X1_24->ZN(S110);

    NAND2_X1_24 = new NAND2_X1("NAND2_X1_24");
        NAND2_X1_24->A1(S129[23]);
        NAND2_X1_24->A2(S131);
        NAND2_X1_24->ZN(S111);

    OAI21_X1_24 = new OAI21_X1("OAI21_X1_24");
        OAI21_X1_24->A(S111);
        OAI21_X1_24->B1(S110);
        OAI21_X1_24->B2(S131);
        OAI21_X1_24->ZN(S132[23]);

    INV_X1_25 = new INV_X1("INV_X1_25");
        INV_X1_25->A(addSubRes_24_);
        INV_X1_25->ZN(S112);

    NAND2_X1_25 = new NAND2_X1("NAND2_X1_25");
        NAND2_X1_25->A1(S129[24]);
        NAND2_X1_25->A2(S131);
        NAND2_X1_25->ZN(S113);

    OAI21_X1_25 = new OAI21_X1("OAI21_X1_25");
        OAI21_X1_25->A(S113);
        OAI21_X1_25->B1(S112);
        OAI21_X1_25->B2(S131);
        OAI21_X1_25->ZN(S132[24]);

    INV_X1_26 = new INV_X1("INV_X1_26");
        INV_X1_26->A(addSubRes_25_);
        INV_X1_26->ZN(S114);

    NAND2_X1_26 = new NAND2_X1("NAND2_X1_26");
        NAND2_X1_26->A1(S129[25]);
        NAND2_X1_26->A2(S131);
        NAND2_X1_26->ZN(S115);

    OAI21_X1_26 = new OAI21_X1("OAI21_X1_26");
        OAI21_X1_26->A(S115);
        OAI21_X1_26->B1(S114);
        OAI21_X1_26->B2(S131);
        OAI21_X1_26->ZN(S132[25]);

    INV_X1_27 = new INV_X1("INV_X1_27");
        INV_X1_27->A(addSubRes_26_);
        INV_X1_27->ZN(S116);

    NAND2_X1_27 = new NAND2_X1("NAND2_X1_27");
        NAND2_X1_27->A1(S129[26]);
        NAND2_X1_27->A2(S131);
        NAND2_X1_27->ZN(S117);

    OAI21_X1_27 = new OAI21_X1("OAI21_X1_27");
        OAI21_X1_27->A(S117);
        OAI21_X1_27->B1(S116);
        OAI21_X1_27->B2(S131);
        OAI21_X1_27->ZN(S132[26]);

    INV_X1_28 = new INV_X1("INV_X1_28");
        INV_X1_28->A(addSubRes_27_);
        INV_X1_28->ZN(S118);

    NAND2_X1_28 = new NAND2_X1("NAND2_X1_28");
        NAND2_X1_28->A1(S129[27]);
        NAND2_X1_28->A2(S131);
        NAND2_X1_28->ZN(S119);

    OAI21_X1_28 = new OAI21_X1("OAI21_X1_28");
        OAI21_X1_28->A(S119);
        OAI21_X1_28->B1(S118);
        OAI21_X1_28->B2(S131);
        OAI21_X1_28->ZN(S132[27]);

    INV_X1_29 = new INV_X1("INV_X1_29");
        INV_X1_29->A(addSubRes_28_);
        INV_X1_29->ZN(S120);

    NAND2_X1_29 = new NAND2_X1("NAND2_X1_29");
        NAND2_X1_29->A1(S129[28]);
        NAND2_X1_29->A2(S131);
        NAND2_X1_29->ZN(S121);

    OAI21_X1_29 = new OAI21_X1("OAI21_X1_29");
        OAI21_X1_29->A(S121);
        OAI21_X1_29->B1(S120);
        OAI21_X1_29->B2(S131);
        OAI21_X1_29->ZN(S132[28]);

    INV_X1_30 = new INV_X1("INV_X1_30");
        INV_X1_30->A(addSubRes_29_);
        INV_X1_30->ZN(S122);

    NAND2_X1_30 = new NAND2_X1("NAND2_X1_30");
        NAND2_X1_30->A1(S129[29]);
        NAND2_X1_30->A2(S131);
        NAND2_X1_30->ZN(S123);

    OAI21_X1_30 = new OAI21_X1("OAI21_X1_30");
        OAI21_X1_30->A(S123);
        OAI21_X1_30->B1(S122);
        OAI21_X1_30->B2(S131);
        OAI21_X1_30->ZN(S132[29]);

    INV_X1_31 = new INV_X1("INV_X1_31");
        INV_X1_31->A(addSubRes_30_);
        INV_X1_31->ZN(S124);

    NAND2_X1_31 = new NAND2_X1("NAND2_X1_31");
        NAND2_X1_31->A1(S129[30]);
        NAND2_X1_31->A2(S131);
        NAND2_X1_31->ZN(S125);

    OAI21_X1_31 = new OAI21_X1("OAI21_X1_31");
        OAI21_X1_31->A(S125);
        OAI21_X1_31->B1(S124);
        OAI21_X1_31->B2(S131);
        OAI21_X1_31->ZN(S132[30]);

    INV_X1_32 = new INV_X1("INV_X1_32");
        INV_X1_32->A(addSubRes_31_);
        INV_X1_32->ZN(S126);

    NAND2_X1_32 = new NAND2_X1("NAND2_X1_32");
        NAND2_X1_32->A1(S129[31]);
        NAND2_X1_32->A2(S131);
        NAND2_X1_32->ZN(S127);

    OAI21_X1_32 = new OAI21_X1("OAI21_X1_32");
        OAI21_X1_32->A(S127);
        OAI21_X1_32->B1(S126);
        OAI21_X1_32->B2(S131);
        OAI21_X1_32->ZN(S132[31]);

    BUF_X1_1 = new BUF_X1("BUF_X1_1");
        BUF_X1_1->A(a[0]);
        BUF_X1_1->Z(S128[0]);

    BUF_X1_2 = new BUF_X1("BUF_X1_2");
        BUF_X1_2->A(a[1]);
        BUF_X1_2->Z(S128[1]);

    BUF_X1_3 = new BUF_X1("BUF_X1_3");
        BUF_X1_3->A(a[10]);
        BUF_X1_3->Z(S128[10]);

    BUF_X1_4 = new BUF_X1("BUF_X1_4");
        BUF_X1_4->A(a[11]);
        BUF_X1_4->Z(S128[11]);

    BUF_X1_5 = new BUF_X1("BUF_X1_5");
        BUF_X1_5->A(a[12]);
        BUF_X1_5->Z(S128[12]);

    BUF_X1_6 = new BUF_X1("BUF_X1_6");
        BUF_X1_6->A(a[13]);
        BUF_X1_6->Z(S128[13]);

    BUF_X1_7 = new BUF_X1("BUF_X1_7");
        BUF_X1_7->A(a[14]);
        BUF_X1_7->Z(S128[14]);

    BUF_X1_8 = new BUF_X1("BUF_X1_8");
        BUF_X1_8->A(a[15]);
        BUF_X1_8->Z(S128[15]);

    BUF_X1_9 = new BUF_X1("BUF_X1_9");
        BUF_X1_9->A(a[16]);
        BUF_X1_9->Z(S128[16]);

    BUF_X1_10 = new BUF_X1("BUF_X1_10");
        BUF_X1_10->A(a[17]);
        BUF_X1_10->Z(S128[17]);

    BUF_X1_11 = new BUF_X1("BUF_X1_11");
        BUF_X1_11->A(a[18]);
        BUF_X1_11->Z(S128[18]);

    BUF_X1_12 = new BUF_X1("BUF_X1_12");
        BUF_X1_12->A(a[19]);
        BUF_X1_12->Z(S128[19]);

    BUF_X1_13 = new BUF_X1("BUF_X1_13");
        BUF_X1_13->A(a[2]);
        BUF_X1_13->Z(S128[2]);

    BUF_X1_14 = new BUF_X1("BUF_X1_14");
        BUF_X1_14->A(a[20]);
        BUF_X1_14->Z(S128[20]);

    BUF_X1_15 = new BUF_X1("BUF_X1_15");
        BUF_X1_15->A(a[21]);
        BUF_X1_15->Z(S128[21]);

    BUF_X1_16 = new BUF_X1("BUF_X1_16");
        BUF_X1_16->A(a[22]);
        BUF_X1_16->Z(S128[22]);

    BUF_X1_17 = new BUF_X1("BUF_X1_17");
        BUF_X1_17->A(a[23]);
        BUF_X1_17->Z(S128[23]);

    BUF_X1_18 = new BUF_X1("BUF_X1_18");
        BUF_X1_18->A(a[24]);
        BUF_X1_18->Z(S128[24]);

    BUF_X1_19 = new BUF_X1("BUF_X1_19");
        BUF_X1_19->A(a[25]);
        BUF_X1_19->Z(S128[25]);

    BUF_X1_20 = new BUF_X1("BUF_X1_20");
        BUF_X1_20->A(a[26]);
        BUF_X1_20->Z(S128[26]);

    BUF_X1_21 = new BUF_X1("BUF_X1_21");
        BUF_X1_21->A(a[27]);
        BUF_X1_21->Z(S128[27]);

    BUF_X1_22 = new BUF_X1("BUF_X1_22");
        BUF_X1_22->A(a[28]);
        BUF_X1_22->Z(S128[28]);

    BUF_X1_23 = new BUF_X1("BUF_X1_23");
        BUF_X1_23->A(a[29]);
        BUF_X1_23->Z(S128[29]);

    BUF_X1_24 = new BUF_X1("BUF_X1_24");
        BUF_X1_24->A(a[3]);
        BUF_X1_24->Z(S128[3]);

    BUF_X1_25 = new BUF_X1("BUF_X1_25");
        BUF_X1_25->A(a[30]);
        BUF_X1_25->Z(S128[30]);

    BUF_X1_26 = new BUF_X1("BUF_X1_26");
        BUF_X1_26->A(a[31]);
        BUF_X1_26->Z(S128[31]);

    BUF_X1_27 = new BUF_X1("BUF_X1_27");
        BUF_X1_27->A(a[4]);
        BUF_X1_27->Z(S128[4]);

    BUF_X1_28 = new BUF_X1("BUF_X1_28");
        BUF_X1_28->A(a[5]);
        BUF_X1_28->Z(S128[5]);

    BUF_X1_29 = new BUF_X1("BUF_X1_29");
        BUF_X1_29->A(a[6]);
        BUF_X1_29->Z(S128[6]);

    BUF_X1_30 = new BUF_X1("BUF_X1_30");
        BUF_X1_30->A(a[7]);
        BUF_X1_30->Z(S128[7]);

    BUF_X1_31 = new BUF_X1("BUF_X1_31");
        BUF_X1_31->A(a[8]);
        BUF_X1_31->Z(S128[8]);

    BUF_X1_32 = new BUF_X1("BUF_X1_32");
        BUF_X1_32->A(a[9]);
        BUF_X1_32->Z(S128[9]);

    BUF_X1_33 = new BUF_X1("BUF_X1_33");
        BUF_X1_33->A(b[0]);
        BUF_X1_33->Z(S129[0]);

    BUF_X1_34 = new BUF_X1("BUF_X1_34");
        BUF_X1_34->A(b[1]);
        BUF_X1_34->Z(S129[1]);

    BUF_X1_35 = new BUF_X1("BUF_X1_35");
        BUF_X1_35->A(b[10]);
        BUF_X1_35->Z(S129[10]);

    BUF_X1_36 = new BUF_X1("BUF_X1_36");
        BUF_X1_36->A(b[11]);
        BUF_X1_36->Z(S129[11]);

    BUF_X1_37 = new BUF_X1("BUF_X1_37");
        BUF_X1_37->A(b[12]);
        BUF_X1_37->Z(S129[12]);

    BUF_X1_38 = new BUF_X1("BUF_X1_38");
        BUF_X1_38->A(b[13]);
        BUF_X1_38->Z(S129[13]);

    BUF_X1_39 = new BUF_X1("BUF_X1_39");
        BUF_X1_39->A(b[14]);
        BUF_X1_39->Z(S129[14]);

    BUF_X1_40 = new BUF_X1("BUF_X1_40");
        BUF_X1_40->A(b[15]);
        BUF_X1_40->Z(S129[15]);

    BUF_X1_41 = new BUF_X1("BUF_X1_41");
        BUF_X1_41->A(b[16]);
        BUF_X1_41->Z(S129[16]);

    BUF_X1_42 = new BUF_X1("BUF_X1_42");
        BUF_X1_42->A(b[17]);
        BUF_X1_42->Z(S129[17]);

    BUF_X1_43 = new BUF_X1("BUF_X1_43");
        BUF_X1_43->A(b[18]);
        BUF_X1_43->Z(S129[18]);

    BUF_X1_44 = new BUF_X1("BUF_X1_44");
        BUF_X1_44->A(b[19]);
        BUF_X1_44->Z(S129[19]);

    BUF_X1_45 = new BUF_X1("BUF_X1_45");
        BUF_X1_45->A(b[2]);
        BUF_X1_45->Z(S129[2]);

    BUF_X1_46 = new BUF_X1("BUF_X1_46");
        BUF_X1_46->A(b[20]);
        BUF_X1_46->Z(S129[20]);

    BUF_X1_47 = new BUF_X1("BUF_X1_47");
        BUF_X1_47->A(b[21]);
        BUF_X1_47->Z(S129[21]);

    BUF_X1_48 = new BUF_X1("BUF_X1_48");
        BUF_X1_48->A(b[22]);
        BUF_X1_48->Z(S129[22]);

    BUF_X1_49 = new BUF_X1("BUF_X1_49");
        BUF_X1_49->A(b[23]);
        BUF_X1_49->Z(S129[23]);

    BUF_X1_50 = new BUF_X1("BUF_X1_50");
        BUF_X1_50->A(b[24]);
        BUF_X1_50->Z(S129[24]);

    BUF_X1_51 = new BUF_X1("BUF_X1_51");
        BUF_X1_51->A(b[25]);
        BUF_X1_51->Z(S129[25]);

    BUF_X1_52 = new BUF_X1("BUF_X1_52");
        BUF_X1_52->A(b[26]);
        BUF_X1_52->Z(S129[26]);

    BUF_X1_53 = new BUF_X1("BUF_X1_53");
        BUF_X1_53->A(b[27]);
        BUF_X1_53->Z(S129[27]);

    BUF_X1_54 = new BUF_X1("BUF_X1_54");
        BUF_X1_54->A(b[28]);
        BUF_X1_54->Z(S129[28]);

    BUF_X1_55 = new BUF_X1("BUF_X1_55");
        BUF_X1_55->A(b[29]);
        BUF_X1_55->Z(S129[29]);

    BUF_X1_56 = new BUF_X1("BUF_X1_56");
        BUF_X1_56->A(b[3]);
        BUF_X1_56->Z(S129[3]);

    BUF_X1_57 = new BUF_X1("BUF_X1_57");
        BUF_X1_57->A(b[30]);
        BUF_X1_57->Z(S129[30]);

    BUF_X1_58 = new BUF_X1("BUF_X1_58");
        BUF_X1_58->A(b[31]);
        BUF_X1_58->Z(S129[31]);

    BUF_X1_59 = new BUF_X1("BUF_X1_59");
        BUF_X1_59->A(b[4]);
        BUF_X1_59->Z(S129[4]);

    BUF_X1_60 = new BUF_X1("BUF_X1_60");
        BUF_X1_60->A(b[5]);
        BUF_X1_60->Z(S129[5]);

    BUF_X1_61 = new BUF_X1("BUF_X1_61");
        BUF_X1_61->A(b[6]);
        BUF_X1_61->Z(S129[6]);

    BUF_X1_62 = new BUF_X1("BUF_X1_62");
        BUF_X1_62->A(b[7]);
        BUF_X1_62->Z(S129[7]);

    BUF_X1_63 = new BUF_X1("BUF_X1_63");
        BUF_X1_63->A(b[8]);
        BUF_X1_63->Z(S129[8]);

    BUF_X1_64 = new BUF_X1("BUF_X1_64");
        BUF_X1_64->A(b[9]);
        BUF_X1_64->Z(S129[9]);

    BUF_X1_65 = new BUF_X1("BUF_X1_65");
        BUF_X1_65->A(S130);
        BUF_X1_65->Z(cout);

    BUF_X1_66 = new BUF_X1("BUF_X1_66");
        BUF_X1_66->A(pass);
        BUF_X1_66->Z(S131);

    BUF_X1_67 = new BUF_X1("BUF_X1_67");
        BUF_X1_67->A(S132[0]);
        BUF_X1_67->Z(result[0]);

    BUF_X1_68 = new BUF_X1("BUF_X1_68");
        BUF_X1_68->A(S132[1]);
        BUF_X1_68->Z(result[1]);

    BUF_X1_69 = new BUF_X1("BUF_X1_69");
        BUF_X1_69->A(S132[10]);
        BUF_X1_69->Z(result[10]);

    BUF_X1_70 = new BUF_X1("BUF_X1_70");
        BUF_X1_70->A(S132[11]);
        BUF_X1_70->Z(result[11]);

    BUF_X1_71 = new BUF_X1("BUF_X1_71");
        BUF_X1_71->A(S132[12]);
        BUF_X1_71->Z(result[12]);

    BUF_X1_72 = new BUF_X1("BUF_X1_72");
        BUF_X1_72->A(S132[13]);
        BUF_X1_72->Z(result[13]);

    BUF_X1_73 = new BUF_X1("BUF_X1_73");
        BUF_X1_73->A(S132[14]);
        BUF_X1_73->Z(result[14]);

    BUF_X1_74 = new BUF_X1("BUF_X1_74");
        BUF_X1_74->A(S132[15]);
        BUF_X1_74->Z(result[15]);

    BUF_X1_75 = new BUF_X1("BUF_X1_75");
        BUF_X1_75->A(S132[16]);
        BUF_X1_75->Z(result[16]);

    BUF_X1_76 = new BUF_X1("BUF_X1_76");
        BUF_X1_76->A(S132[17]);
        BUF_X1_76->Z(result[17]);

    BUF_X1_77 = new BUF_X1("BUF_X1_77");
        BUF_X1_77->A(S132[18]);
        BUF_X1_77->Z(result[18]);

    BUF_X1_78 = new BUF_X1("BUF_X1_78");
        BUF_X1_78->A(S132[19]);
        BUF_X1_78->Z(result[19]);

    BUF_X1_79 = new BUF_X1("BUF_X1_79");
        BUF_X1_79->A(S132[2]);
        BUF_X1_79->Z(result[2]);

    BUF_X1_80 = new BUF_X1("BUF_X1_80");
        BUF_X1_80->A(S132[20]);
        BUF_X1_80->Z(result[20]);

    BUF_X1_81 = new BUF_X1("BUF_X1_81");
        BUF_X1_81->A(S132[21]);
        BUF_X1_81->Z(result[21]);

    BUF_X1_82 = new BUF_X1("BUF_X1_82");
        BUF_X1_82->A(S132[22]);
        BUF_X1_82->Z(result[22]);

    BUF_X1_83 = new BUF_X1("BUF_X1_83");
        BUF_X1_83->A(S132[23]);
        BUF_X1_83->Z(result[23]);

    BUF_X1_84 = new BUF_X1("BUF_X1_84");
        BUF_X1_84->A(S132[24]);
        BUF_X1_84->Z(result[24]);

    BUF_X1_85 = new BUF_X1("BUF_X1_85");
        BUF_X1_85->A(S132[25]);
        BUF_X1_85->Z(result[25]);

    BUF_X1_86 = new BUF_X1("BUF_X1_86");
        BUF_X1_86->A(S132[26]);
        BUF_X1_86->Z(result[26]);

    BUF_X1_87 = new BUF_X1("BUF_X1_87");
        BUF_X1_87->A(S132[27]);
        BUF_X1_87->Z(result[27]);

    BUF_X1_88 = new BUF_X1("BUF_X1_88");
        BUF_X1_88->A(S132[28]);
        BUF_X1_88->Z(result[28]);

    BUF_X1_89 = new BUF_X1("BUF_X1_89");
        BUF_X1_89->A(S132[29]);
        BUF_X1_89->Z(result[29]);

    BUF_X1_90 = new BUF_X1("BUF_X1_90");
        BUF_X1_90->A(S132[3]);
        BUF_X1_90->Z(result[3]);

    BUF_X1_91 = new BUF_X1("BUF_X1_91");
        BUF_X1_91->A(S132[30]);
        BUF_X1_91->Z(result[30]);

    BUF_X1_92 = new BUF_X1("BUF_X1_92");
        BUF_X1_92->A(S132[31]);
        BUF_X1_92->Z(result[31]);

    BUF_X1_93 = new BUF_X1("BUF_X1_93");
        BUF_X1_93->A(S132[4]);
        BUF_X1_93->Z(result[4]);

    BUF_X1_94 = new BUF_X1("BUF_X1_94");
        BUF_X1_94->A(S132[5]);
        BUF_X1_94->Z(result[5]);

    BUF_X1_95 = new BUF_X1("BUF_X1_95");
        BUF_X1_95->A(S132[6]);
        BUF_X1_95->Z(result[6]);

    BUF_X1_96 = new BUF_X1("BUF_X1_96");
        BUF_X1_96->A(S132[7]);
        BUF_X1_96->Z(result[7]);

    BUF_X1_97 = new BUF_X1("BUF_X1_97");
        BUF_X1_97->A(S132[8]);
        BUF_X1_97->Z(result[8]);

    BUF_X1_98 = new BUF_X1("BUF_X1_98");
        BUF_X1_98->A(S132[9]);
        BUF_X1_98->Z(result[9]);

    BUF_X1_99 = new BUF_X1("BUF_X1_99");
        BUF_X1_99->A(subsel);
        BUF_X1_99->Z(S133);

    adder_sub = new _paramod_aftab_adder_size_s32_00000000000000000000000000100000("adder_sub");
        adder_sub->a[0](S128[0]);
        adder_sub->a[1](S128[1]);
        adder_sub->a[2](S128[2]);
        adder_sub->a[3](S128[3]);
        adder_sub->a[4](S128[4]);
        adder_sub->a[5](S128[5]);
        adder_sub->a[6](S128[6]);
        adder_sub->a[7](S128[7]);
        adder_sub->a[8](S128[8]);
        adder_sub->a[9](S128[9]);
        adder_sub->a[10](S128[10]);
        adder_sub->a[11](S128[11]);
        adder_sub->a[12](S128[12]);
        adder_sub->a[13](S128[13]);
        adder_sub->a[14](S128[14]);
        adder_sub->a[15](S128[15]);
        adder_sub->a[16](S128[16]);
        adder_sub->a[17](S128[17]);
        adder_sub->a[18](S128[18]);
        adder_sub->a[19](S128[19]);
        adder_sub->a[20](S128[20]);
        adder_sub->a[21](S128[21]);
        adder_sub->a[22](S128[22]);
        adder_sub->a[23](S128[23]);
        adder_sub->a[24](S128[24]);
        adder_sub->a[25](S128[25]);
        adder_sub->a[26](S128[26]);
        adder_sub->a[27](S128[27]);
        adder_sub->a[28](S128[28]);
        adder_sub->a[29](S128[29]);
        adder_sub->a[30](S128[30]);
        adder_sub->a[31](S128[31]);
        adder_sub->b[0](bsel_0_);
        adder_sub->b[1](bsel_1_);
        adder_sub->b[2](bsel_2_);
        adder_sub->b[3](bsel_3_);
        adder_sub->b[4](bsel_4_);
        adder_sub->b[5](bsel_5_);
        adder_sub->b[6](bsel_6_);
        adder_sub->b[7](bsel_7_);
        adder_sub->b[8](bsel_8_);
        adder_sub->b[9](bsel_9_);
        adder_sub->b[10](bsel_10_);
        adder_sub->b[11](bsel_11_);
        adder_sub->b[12](bsel_12_);
        adder_sub->b[13](bsel_13_);
        adder_sub->b[14](bsel_14_);
        adder_sub->b[15](bsel_15_);
        adder_sub->b[16](bsel_16_);
        adder_sub->b[17](bsel_17_);
        adder_sub->b[18](bsel_18_);
        adder_sub->b[19](bsel_19_);
        adder_sub->b[20](bsel_20_);
        adder_sub->b[21](bsel_21_);
        adder_sub->b[22](bsel_22_);
        adder_sub->b[23](bsel_23_);
        adder_sub->b[24](bsel_24_);
        adder_sub->b[25](bsel_25_);
        adder_sub->b[26](bsel_26_);
        adder_sub->b[27](bsel_27_);
        adder_sub->b[28](bsel_28_);
        adder_sub->b[29](bsel_29_);
        adder_sub->b[30](bsel_30_);
        adder_sub->b[31](bsel_31_);
        adder_sub->cin(S133);
        adder_sub->cout(S130);
        adder_sub->sum[0](addSubRes_0_);
        adder_sub->sum[1](addSubRes_1_);
        adder_sub->sum[2](addSubRes_2_);
        adder_sub->sum[3](addSubRes_3_);
        adder_sub->sum[4](addSubRes_4_);
        adder_sub->sum[5](addSubRes_5_);
        adder_sub->sum[6](addSubRes_6_);
        adder_sub->sum[7](addSubRes_7_);
        adder_sub->sum[8](addSubRes_8_);
        adder_sub->sum[9](addSubRes_9_);
        adder_sub->sum[10](addSubRes_10_);
        adder_sub->sum[11](addSubRes_11_);
        adder_sub->sum[12](addSubRes_12_);
        adder_sub->sum[13](addSubRes_13_);
        adder_sub->sum[14](addSubRes_14_);
        adder_sub->sum[15](addSubRes_15_);
        adder_sub->sum[16](addSubRes_16_);
        adder_sub->sum[17](addSubRes_17_);
        adder_sub->sum[18](addSubRes_18_);
        adder_sub->sum[19](addSubRes_19_);
        adder_sub->sum[20](addSubRes_20_);
        adder_sub->sum[21](addSubRes_21_);
        adder_sub->sum[22](addSubRes_22_);
        adder_sub->sum[23](addSubRes_23_);
        adder_sub->sum[24](addSubRes_24_);
        adder_sub->sum[25](addSubRes_25_);
        adder_sub->sum[26](addSubRes_26_);
        adder_sub->sum[27](addSubRes_27_);
        adder_sub->sum[28](addSubRes_28_);
        adder_sub->sum[29](addSubRes_29_);
        adder_sub->sum[30](addSubRes_30_);
        adder_sub->sum[31](addSubRes_31_);


    SC_METHOD(sc_logic_signal_assignment);

    }

    void sc_logic_signal_assignment(void){ 
        sc_logic_1_signal.write(SC_LOGIC_1);
        sc_logic_0_signal.write(SC_LOGIC_0);
    }
};
#endif /* __AFTAB_ADDER_SUBTRACTOR_H__ */

