#include <systemc.h>
#include "Complex_NAgate_45.h"



#ifndef __MAP_CONTROLLER_H__
#define __MAP_CONTROLLER_H__
using namespace sc_core;

SC_MODULE( map_controller ) {

    sc_in<sc_logic> clk;
    sc_in<sc_logic> rst;
    sc_in<sc_logic> run;
    sc_in<sc_logic> pause;
    sc_in<sc_logic> count[4];
    sc_out<sc_logic> add_reg;
    sc_out<sc_logic> out_reg;

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
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S75[4];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S76 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S76");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S77 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S77");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S78 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S78");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S79 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S79");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> c_0_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("c_0_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> c_1_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("c_1_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> c_2_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("c_2_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> c_3_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("c_3_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> i_0_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("i_0_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> i_1_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("i_1_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> i_2_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("i_2_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> i_3_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("i_3_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> ps_0_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("ps_0_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> ps_2_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("ps_2_");

    INV_X1* INV_X1_1;
    NAND2_X1* NAND2_X1_1;
    NOR2_X1* NOR2_X1_1;
    AOI21_X1* AOI21_X1_1;
    INV_X1* INV_X1_2;
    NOR2_X1* NOR2_X1_2;
    AOI21_X1* AOI21_X1_2;
    INV_X1* INV_X1_3;
    NOR2_X1* NOR2_X1_3;
    AOI21_X1* AOI21_X1_3;
    INV_X1* INV_X1_4;
    NOR2_X1* NOR2_X1_4;
    AOI21_X1* AOI21_X1_4;
    INV_X1* INV_X1_5;
    NAND3_X1* NAND3_X1_1;
    NAND2_X1* NAND2_X1_2;
    NOR2_X1* NOR2_X1_5;
    NAND3_X1* NAND3_X1_2;
    NAND3_X1* NAND3_X1_3;
    NOR2_X1* NOR2_X1_6;
    NAND2_X1* NAND2_X1_3;
    INV_X1* INV_X1_6;
    NAND2_X1* NAND2_X1_4;
    NAND3_X1* NAND3_X1_4;
    NAND2_X1* NAND2_X1_5;
    NAND2_X1* NAND2_X1_6;
    NAND4_X1* NAND4_X1_1;
    NAND2_X1* NAND2_X1_7;
    NAND2_X1* NAND2_X1_8;
    NAND3_X1* NAND3_X1_5;
    NAND2_X1* NAND2_X1_9;
    NAND3_X1* NAND3_X1_6;
    INV_X1* INV_X1_7;
    OAI21_X1* OAI21_X1_1;
    NAND3_X1* NAND3_X1_7;
    OAI21_X1* OAI21_X1_2;
    NAND2_X1* NAND2_X1_10;
    NAND3_X1* NAND3_X1_8;
    NAND2_X1* NAND2_X1_11;
    NAND2_X1* NAND2_X1_12;
    INV_X1* INV_X1_8;
    NOR3_X1* NOR3_X1_1;
    OAI21_X1* OAI21_X1_3;
    INV_X1* INV_X1_9;
    INV_X1* INV_X1_10;
    INV_X1* INV_X1_11;
    NAND2_X1* NAND2_X1_13;
    NAND3_X1* NAND3_X1_9;
    NAND2_X1* NAND2_X1_14;
    OAI21_X1* OAI21_X1_4;
    NOR2_X1* NOR2_X1_7;
    INV_X1* INV_X1_12;
    INV_X1* INV_X1_13;
    OAI211_X1* OAI211_X1_1;
    INV_X1* INV_X1_14;
    NOR3_X1* NOR3_X1_2;
    NAND2_X1* NAND2_X1_15;
    NAND2_X1* NAND2_X1_16;
    AOI21_X1* AOI21_X1_5;
    NAND3_X1* NAND3_X1_10;
    INV_X1* INV_X1_15;
    AOI21_X1* AOI21_X1_6;
    NOR3_X1* NOR3_X1_3;
    NOR2_X1* NOR2_X1_8;
    NOR2_X1* NOR2_X1_9;
    NOR3_X1* NOR3_X1_4;
    OAI21_X1* OAI21_X1_5;
    NAND2_X1* NAND2_X1_17;
    AOI21_X1* AOI21_X1_7;
    DFF_X1* DFF_X1_1;
    DFF_X1* DFF_X1_2;
    DFF_X1* DFF_X1_3;
    DFF_X1* DFF_X1_4;
    DFF_X1* DFF_X1_5;
    DFF_X1* DFF_X1_6;
    DFF_X1* DFF_X1_7;
    DFF_X1* DFF_X1_8;
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

SC_CTOR( map_controller ) {
    INV_X1_1 = new INV_X1("INV_X1_1");
        INV_X1_1->A(c_0_);
        INV_X1_1->ZN(S9);

    NAND2_X1_1 = new NAND2_X1("NAND2_X1_1");
        NAND2_X1_1->A1(S79);
        NAND2_X1_1->A2(ps_0_);
        NAND2_X1_1->ZN(S10);

    NOR2_X1_1 = new NOR2_X1("NOR2_X1_1");
        NOR2_X1_1->A1(S10);
        NOR2_X1_1->A2(S75[0]);
        NOR2_X1_1->ZN(S11);

    AOI21_X1_1 = new AOI21_X1("AOI21_X1_1");
        AOI21_X1_1->A(S11);
        AOI21_X1_1->B1(S10);
        AOI21_X1_1->B2(S9);
        AOI21_X1_1->ZN(c_0_);

    INV_X1_2 = new INV_X1("INV_X1_2");
        INV_X1_2->A(c_1_);
        INV_X1_2->ZN(S12);

    NOR2_X1_2 = new NOR2_X1("NOR2_X1_2");
        NOR2_X1_2->A1(S10);
        NOR2_X1_2->A2(S75[1]);
        NOR2_X1_2->ZN(S13);

    AOI21_X1_2 = new AOI21_X1("AOI21_X1_2");
        AOI21_X1_2->A(S13);
        AOI21_X1_2->B1(S10);
        AOI21_X1_2->B2(S12);
        AOI21_X1_2->ZN(c_1_);

    INV_X1_3 = new INV_X1("INV_X1_3");
        INV_X1_3->A(c_2_);
        INV_X1_3->ZN(S14);

    NOR2_X1_3 = new NOR2_X1("NOR2_X1_3");
        NOR2_X1_3->A1(S10);
        NOR2_X1_3->A2(S75[2]);
        NOR2_X1_3->ZN(S15);

    AOI21_X1_3 = new AOI21_X1("AOI21_X1_3");
        AOI21_X1_3->A(S15);
        AOI21_X1_3->B1(S10);
        AOI21_X1_3->B2(S14);
        AOI21_X1_3->ZN(c_2_);

    INV_X1_4 = new INV_X1("INV_X1_4");
        INV_X1_4->A(c_3_);
        INV_X1_4->ZN(S16);

    NOR2_X1_4 = new NOR2_X1("NOR2_X1_4");
        NOR2_X1_4->A1(S10);
        NOR2_X1_4->A2(S75[3]);
        NOR2_X1_4->ZN(S17);

    AOI21_X1_4 = new AOI21_X1("AOI21_X1_4");
        AOI21_X1_4->A(S17);
        AOI21_X1_4->B1(S10);
        AOI21_X1_4->B2(S16);
        AOI21_X1_4->ZN(c_3_);

    INV_X1_5 = new INV_X1("INV_X1_5");
        INV_X1_5->A(i_3_);
        INV_X1_5->ZN(S18);

    NAND3_X1_1 = new NAND3_X1("NAND3_X1_1");
        NAND3_X1_1->A1(S9);
        NAND3_X1_1->A2(S14);
        NAND3_X1_1->A3(S12);
        NAND3_X1_1->ZN(S19);

    NAND2_X1_2 = new NAND2_X1("NAND2_X1_2");
        NAND2_X1_2->A1(S19);
        NAND2_X1_2->A2(S16);
        NAND2_X1_2->ZN(S20);

    NOR2_X1_5 = new NOR2_X1("NOR2_X1_5");
        NOR2_X1_5->A1(c_0_);
        NOR2_X1_5->A2(c_1_);
        NOR2_X1_5->ZN(S21);

    NAND3_X1_2 = new NAND3_X1("NAND3_X1_2");
        NAND3_X1_2->A1(S21);
        NAND3_X1_2->A2(S14);
        NAND3_X1_2->A3(c_3_);
        NAND3_X1_2->ZN(S22);

    NAND3_X1_3 = new NAND3_X1("NAND3_X1_3");
        NAND3_X1_3->A1(S20);
        NAND3_X1_3->A2(S18);
        NAND3_X1_3->A3(S22);
        NAND3_X1_3->ZN(S23);

    NOR2_X1_6 = new NOR2_X1("NOR2_X1_6");
        NOR2_X1_6->A1(S9);
        NOR2_X1_6->A2(i_0_);
        NOR2_X1_6->ZN(S24);

    NAND2_X1_3 = new NAND2_X1("NAND2_X1_3");
        NAND2_X1_3->A1(S12);
        NAND2_X1_3->A2(i_1_);
        NAND2_X1_3->ZN(S25);

    INV_X1_6 = new INV_X1("INV_X1_6");
        INV_X1_6->A(i_1_);
        INV_X1_6->ZN(S26);

    NAND2_X1_4 = new NAND2_X1("NAND2_X1_4");
        NAND2_X1_4->A1(S26);
        NAND2_X1_4->A2(c_1_);
        NAND2_X1_4->ZN(S27);

    NAND3_X1_4 = new NAND3_X1("NAND3_X1_4");
        NAND3_X1_4->A1(S24);
        NAND3_X1_4->A2(S25);
        NAND3_X1_4->A3(S27);
        NAND3_X1_4->ZN(S28);

    NAND2_X1_5 = new NAND2_X1("NAND2_X1_5");
        NAND2_X1_5->A1(i_1_);
        NAND2_X1_5->A2(c_1_);
        NAND2_X1_5->ZN(S29);

    NAND2_X1_6 = new NAND2_X1("NAND2_X1_6");
        NAND2_X1_6->A1(S26);
        NAND2_X1_6->A2(S12);
        NAND2_X1_6->ZN(S30);

    NAND4_X1_1 = new NAND4_X1("NAND4_X1_1");
        NAND4_X1_1->A1(S30);
        NAND4_X1_1->A2(S29);
        NAND4_X1_1->A3(S9);
        NAND4_X1_1->A4(i_0_);
        NAND4_X1_1->ZN(S31);

    NAND2_X1_7 = new NAND2_X1("NAND2_X1_7");
        NAND2_X1_7->A1(S31);
        NAND2_X1_7->A2(S28);
        NAND2_X1_7->ZN(S32);

    NAND2_X1_8 = new NAND2_X1("NAND2_X1_8");
        NAND2_X1_8->A1(S23);
        NAND2_X1_8->A2(S32);
        NAND2_X1_8->ZN(S33);

    NAND3_X1_5 = new NAND3_X1("NAND3_X1_5");
        NAND3_X1_5->A1(S21);
        NAND3_X1_5->A2(S14);
        NAND3_X1_5->A3(S16);
        NAND3_X1_5->ZN(S34);

    NAND2_X1_9 = new NAND2_X1("NAND2_X1_9");
        NAND2_X1_9->A1(S19);
        NAND2_X1_9->A2(c_3_);
        NAND2_X1_9->ZN(S35);

    NAND3_X1_6 = new NAND3_X1("NAND3_X1_6");
        NAND3_X1_6->A1(S35);
        NAND3_X1_6->A2(i_3_);
        NAND3_X1_6->A3(S34);
        NAND3_X1_6->ZN(S36);

    INV_X1_7 = new INV_X1("INV_X1_7");
        INV_X1_7->A(i_2_);
        INV_X1_7->ZN(S37);

    OAI21_X1_1 = new OAI21_X1("OAI21_X1_1");
        OAI21_X1_1->A(c_2_);
        OAI21_X1_1->B1(c_0_);
        OAI21_X1_1->B2(c_1_);
        OAI21_X1_1->ZN(S38);

    NAND3_X1_7 = new NAND3_X1("NAND3_X1_7");
        NAND3_X1_7->A1(S19);
        NAND3_X1_7->A2(S37);
        NAND3_X1_7->A3(S38);
        NAND3_X1_7->ZN(S39);

    OAI21_X1_2 = new OAI21_X1("OAI21_X1_2");
        OAI21_X1_2->A(S14);
        OAI21_X1_2->B1(c_0_);
        OAI21_X1_2->B2(c_1_);
        OAI21_X1_2->ZN(S40);

    NAND2_X1_10 = new NAND2_X1("NAND2_X1_10");
        NAND2_X1_10->A1(S21);
        NAND2_X1_10->A2(c_2_);
        NAND2_X1_10->ZN(S41);

    NAND3_X1_8 = new NAND3_X1("NAND3_X1_8");
        NAND3_X1_8->A1(S41);
        NAND3_X1_8->A2(i_2_);
        NAND3_X1_8->A3(S40);
        NAND3_X1_8->ZN(S42);

    NAND2_X1_11 = new NAND2_X1("NAND2_X1_11");
        NAND2_X1_11->A1(S42);
        NAND2_X1_11->A2(S39);
        NAND2_X1_11->ZN(S43);

    NAND2_X1_12 = new NAND2_X1("NAND2_X1_12");
        NAND2_X1_12->A1(S43);
        NAND2_X1_12->A2(S36);
        NAND2_X1_12->ZN(S44);

    INV_X1_8 = new INV_X1("INV_X1_8");
        INV_X1_8->A(S73);
        INV_X1_8->ZN(S45);

    NOR3_X1_1 = new NOR3_X1("NOR3_X1_1");
        NOR3_X1_1->A1(S45);
        NOR3_X1_1->A2(S77);
        NOR3_X1_1->A3(S78);
        NOR3_X1_1->ZN(S46);

    OAI21_X1_3 = new OAI21_X1("OAI21_X1_3");
        OAI21_X1_3->A(S46);
        OAI21_X1_3->B1(S44);
        OAI21_X1_3->B2(S33);
        OAI21_X1_3->ZN(S47);

    INV_X1_9 = new INV_X1("INV_X1_9");
        INV_X1_9->A(S78);
        INV_X1_9->ZN(S48);

    INV_X1_10 = new INV_X1("INV_X1_10");
        INV_X1_10->A(S77);
        INV_X1_10->ZN(S49);

    INV_X1_11 = new INV_X1("INV_X1_11");
        INV_X1_11->A(ps_2_);
        INV_X1_11->ZN(S50);

    NAND2_X1_13 = new NAND2_X1("NAND2_X1_13");
        NAND2_X1_13->A1(S10);
        NAND2_X1_13->A2(S50);
        NAND2_X1_13->ZN(S51);

    NAND3_X1_9 = new NAND3_X1("NAND3_X1_9");
        NAND3_X1_9->A1(S51);
        NAND3_X1_9->A2(S48);
        NAND3_X1_9->A3(S49);
        NAND3_X1_9->ZN(S52);

    NAND2_X1_14 = new NAND2_X1("NAND2_X1_14");
        NAND2_X1_14->A1(S47);
        NAND2_X1_14->A2(S52);
        NAND2_X1_14->ZN(S2);

    OAI21_X1_4 = new OAI21_X1("OAI21_X1_4");
        OAI21_X1_4->A(S77);
        OAI21_X1_4->B1(S51);
        OAI21_X1_4->B2(S73);
        OAI21_X1_4->ZN(S53);

    NOR2_X1_7 = new NOR2_X1("NOR2_X1_7");
        NOR2_X1_7->A1(S53);
        NOR2_X1_7->A2(S78);
        NOR2_X1_7->ZN(S3);

    INV_X1_12 = new INV_X1("INV_X1_12");
        INV_X1_12->A(ps_0_);
        INV_X1_12->ZN(S54);

    INV_X1_13 = new INV_X1("INV_X1_13");
        INV_X1_13->A(S76);
        INV_X1_13->ZN(S55);

    OAI211_X1_1 = new OAI211_X1("OAI211_X1_1");
        OAI211_X1_1->A(S48);
        OAI211_X1_1->B(S55);
        OAI211_X1_1->C1(S54);
        OAI211_X1_1->C2(S79);
        OAI211_X1_1->ZN(S1);

    INV_X1_14 = new INV_X1("INV_X1_14");
        INV_X1_14->A(S46);
        INV_X1_14->ZN(S56);

    NOR3_X1_2 = new NOR3_X1("NOR3_X1_2");
        NOR3_X1_2->A1(S44);
        NOR3_X1_2->A2(S33);
        NOR3_X1_2->A3(S56);
        NOR3_X1_2->ZN(S0);

    NAND2_X1_15 = new NAND2_X1("NAND2_X1_15");
        NAND2_X1_15->A1(S73);
        NAND2_X1_15->A2(S65);
        NAND2_X1_15->ZN(S57);

    NAND2_X1_16 = new NAND2_X1("NAND2_X1_16");
        NAND2_X1_16->A1(S45);
        NAND2_X1_16->A2(i_0_);
        NAND2_X1_16->ZN(S58);

    AOI21_X1_5 = new AOI21_X1("AOI21_X1_5");
        AOI21_X1_5->A(S79);
        AOI21_X1_5->B1(S58);
        AOI21_X1_5->B2(S57);
        AOI21_X1_5->ZN(S4);

    NAND3_X1_10 = new NAND3_X1("NAND3_X1_10");
        NAND3_X1_10->A1(i_0_);
        NAND3_X1_10->A2(i_1_);
        NAND3_X1_10->A3(S73);
        NAND3_X1_10->ZN(S59);

    INV_X1_15 = new INV_X1("INV_X1_15");
        INV_X1_15->A(S59);
        INV_X1_15->ZN(S60);

    AOI21_X1_6 = new AOI21_X1("AOI21_X1_6");
        AOI21_X1_6->A(i_1_);
        AOI21_X1_6->B1(i_0_);
        AOI21_X1_6->B2(S73);
        AOI21_X1_6->ZN(S61);

    NOR3_X1_3 = new NOR3_X1("NOR3_X1_3");
        NOR3_X1_3->A1(S60);
        NOR3_X1_3->A2(S61);
        NOR3_X1_3->A3(S79);
        NOR3_X1_3->ZN(S5);

    NOR2_X1_8 = new NOR2_X1("NOR2_X1_8");
        NOR2_X1_8->A1(S59);
        NOR2_X1_8->A2(S37);
        NOR2_X1_8->ZN(S62);

    NOR2_X1_9 = new NOR2_X1("NOR2_X1_9");
        NOR2_X1_9->A1(S60);
        NOR2_X1_9->A2(i_2_);
        NOR2_X1_9->ZN(S63);

    NOR3_X1_4 = new NOR3_X1("NOR3_X1_4");
        NOR3_X1_4->A1(S63);
        NOR3_X1_4->A2(S62);
        NOR3_X1_4->A3(S79);
        NOR3_X1_4->ZN(S6);

    OAI21_X1_5 = new OAI21_X1("OAI21_X1_5");
        OAI21_X1_5->A(i_3_);
        OAI21_X1_5->B1(S59);
        OAI21_X1_5->B2(S37);
        OAI21_X1_5->ZN(S64);

    NAND2_X1_17 = new NAND2_X1("NAND2_X1_17");
        NAND2_X1_17->A1(S62);
        NAND2_X1_17->A2(S18);
        NAND2_X1_17->ZN(S8);

    AOI21_X1_7 = new AOI21_X1("AOI21_X1_7");
        AOI21_X1_7->A(S79);
        AOI21_X1_7->B1(S8);
        AOI21_X1_7->B2(S64);
        AOI21_X1_7->ZN(S7);

    DFF_X1_1 = new DFF_X1("DFF_X1_1");
        DFF_X1_1->CK(S74);
        DFF_X1_1->D(S1);
        DFF_X1_1->Q(ps_0_);
        DFF_X1_1->QN(S70);

    DFF_X1_2 = new DFF_X1("DFF_X1_2");
        DFF_X1_2->CK(S74);
        DFF_X1_2->D(S2);
        DFF_X1_2->Q(S73);
        DFF_X1_2->QN(S71);

    DFF_X1_3 = new DFF_X1("DFF_X1_3");
        DFF_X1_3->CK(S74);
        DFF_X1_3->D(S3);
        DFF_X1_3->Q(ps_2_);
        DFF_X1_3->QN(S72);

    DFF_X1_4 = new DFF_X1("DFF_X1_4");
        DFF_X1_4->CK(S74);
        DFF_X1_4->D(S0);
        DFF_X1_4->Q(S76);
        DFF_X1_4->QN(S69);

    DFF_X1_5 = new DFF_X1("DFF_X1_5");
        DFF_X1_5->CK(S74);
        DFF_X1_5->D(S4);
        DFF_X1_5->Q(i_0_);
        DFF_X1_5->QN(S65);

    DFF_X1_6 = new DFF_X1("DFF_X1_6");
        DFF_X1_6->CK(S74);
        DFF_X1_6->D(S5);
        DFF_X1_6->Q(i_1_);
        DFF_X1_6->QN(S68);

    DFF_X1_7 = new DFF_X1("DFF_X1_7");
        DFF_X1_7->CK(S74);
        DFF_X1_7->D(S6);
        DFF_X1_7->Q(i_2_);
        DFF_X1_7->QN(S67);

    DFF_X1_8 = new DFF_X1("DFF_X1_8");
        DFF_X1_8->CK(S74);
        DFF_X1_8->D(S7);
        DFF_X1_8->Q(i_3_);
        DFF_X1_8->QN(S66);

    BUF_X1_1 = new BUF_X1("BUF_X1_1");
        BUF_X1_1->A(S73);
        BUF_X1_1->Z(add_reg);

    BUF_X1_2 = new BUF_X1("BUF_X1_2");
        BUF_X1_2->A(clk);
        BUF_X1_2->Z(S74);

    BUF_X1_3 = new BUF_X1("BUF_X1_3");
        BUF_X1_3->A(count[0]);
        BUF_X1_3->Z(S75[0]);

    BUF_X1_4 = new BUF_X1("BUF_X1_4");
        BUF_X1_4->A(count[1]);
        BUF_X1_4->Z(S75[1]);

    BUF_X1_5 = new BUF_X1("BUF_X1_5");
        BUF_X1_5->A(count[2]);
        BUF_X1_5->Z(S75[2]);

    BUF_X1_6 = new BUF_X1("BUF_X1_6");
        BUF_X1_6->A(count[3]);
        BUF_X1_6->Z(S75[3]);

    BUF_X1_7 = new BUF_X1("BUF_X1_7");
        BUF_X1_7->A(S76);
        BUF_X1_7->Z(out_reg);

    BUF_X1_8 = new BUF_X1("BUF_X1_8");
        BUF_X1_8->A(pause);
        BUF_X1_8->Z(S77);

    BUF_X1_9 = new BUF_X1("BUF_X1_9");
        BUF_X1_9->A(rst);
        BUF_X1_9->Z(S78);

    BUF_X1_10 = new BUF_X1("BUF_X1_10");
        BUF_X1_10->A(run);
        BUF_X1_10->Z(S79);


    SC_METHOD(sc_logic_signal_assignment);

    }

    void sc_logic_signal_assignment(void){ 
        sc_logic_1_signal.write(SC_LOGIC_1);
        sc_logic_0_signal.write(SC_LOGIC_0);
    }
};
#endif /* __MAP_CONTROLLER_H__ */

