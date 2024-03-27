#include <systemc.h>
#include "Complex_NAgate_45.h"



#ifndef __MUX3OF16BITS_H__
#define __MUX3OF16BITS_H__
using namespace sc_core;

SC_MODULE( mux3of16bits ) {

    sc_in<sc_logic> in1[16];
    sc_in<sc_logic> in2[16];
    sc_in<sc_logic> in3[16];
    sc_in<sc_logic> sel1;
    sc_in<sc_logic> sel2;
    sc_in<sc_logic> sel3;
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
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S49[16];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S50[16];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S51[16];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S52[16];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S53 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S53");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S54 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S54");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S55 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S55");

    INV_X1* INV_X1_1;
    INV_X1* INV_X1_2;
    NAND3_X1* NAND3_X1_1;
    AOI21_X1* AOI21_X1_1;
    AOI22_X1* AOI22_X1_1;
    INV_X1* INV_X1_3;
    NAND3_X1* NAND3_X1_2;
    AOI21_X1* AOI21_X1_2;
    AOI22_X1* AOI22_X1_2;
    INV_X1* INV_X1_4;
    NAND3_X1* NAND3_X1_3;
    AOI21_X1* AOI21_X1_3;
    AOI22_X1* AOI22_X1_3;
    INV_X1* INV_X1_5;
    NAND3_X1* NAND3_X1_4;
    AOI21_X1* AOI21_X1_4;
    AOI22_X1* AOI22_X1_4;
    INV_X1* INV_X1_6;
    NAND3_X1* NAND3_X1_5;
    AOI21_X1* AOI21_X1_5;
    AOI22_X1* AOI22_X1_5;
    INV_X1* INV_X1_7;
    NAND3_X1* NAND3_X1_6;
    AOI21_X1* AOI21_X1_6;
    AOI22_X1* AOI22_X1_6;
    INV_X1* INV_X1_8;
    NAND3_X1* NAND3_X1_7;
    AOI21_X1* AOI21_X1_7;
    AOI22_X1* AOI22_X1_7;
    INV_X1* INV_X1_9;
    NAND3_X1* NAND3_X1_8;
    AOI21_X1* AOI21_X1_8;
    AOI22_X1* AOI22_X1_8;
    INV_X1* INV_X1_10;
    NAND3_X1* NAND3_X1_9;
    AOI21_X1* AOI21_X1_9;
    AOI22_X1* AOI22_X1_9;
    INV_X1* INV_X1_11;
    NAND3_X1* NAND3_X1_10;
    AOI21_X1* AOI21_X1_10;
    AOI22_X1* AOI22_X1_10;
    INV_X1* INV_X1_12;
    NAND3_X1* NAND3_X1_11;
    AOI21_X1* AOI21_X1_11;
    AOI22_X1* AOI22_X1_11;
    INV_X1* INV_X1_13;
    NAND3_X1* NAND3_X1_12;
    AOI21_X1* AOI21_X1_12;
    AOI22_X1* AOI22_X1_12;
    INV_X1* INV_X1_14;
    NAND3_X1* NAND3_X1_13;
    AOI21_X1* AOI21_X1_13;
    AOI22_X1* AOI22_X1_13;
    INV_X1* INV_X1_15;
    NAND3_X1* NAND3_X1_14;
    AOI21_X1* AOI21_X1_14;
    AOI22_X1* AOI22_X1_14;
    INV_X1* INV_X1_16;
    NAND3_X1* NAND3_X1_15;
    AOI21_X1* AOI21_X1_15;
    AOI22_X1* AOI22_X1_15;
    INV_X1* INV_X1_17;
    NAND3_X1* NAND3_X1_16;
    AOI21_X1* AOI21_X1_16;
    AOI22_X1* AOI22_X1_16;
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

SC_CTOR( mux3of16bits ) {
    INV_X1_1 = new INV_X1("INV_X1_1");
        INV_X1_1->A(S49[0]);
        INV_X1_1->ZN(S24);

    INV_X1_2 = new INV_X1("INV_X1_2");
        INV_X1_2->A(S54);
        INV_X1_2->ZN(S25);

    NAND3_X1_1 = new NAND3_X1("NAND3_X1_1");
        NAND3_X1_1->A1(S25);
        NAND3_X1_1->A2(S55);
        NAND3_X1_1->A3(S51[0]);
        NAND3_X1_1->ZN(S26);

    AOI21_X1_1 = new AOI21_X1("AOI21_X1_1");
        AOI21_X1_1->A(S53);
        AOI21_X1_1->B1(S54);
        AOI21_X1_1->B2(S50[0]);
        AOI21_X1_1->ZN(S27);

    AOI22_X1_1 = new AOI22_X1("AOI22_X1_1");
        AOI22_X1_1->A1(S26);
        AOI22_X1_1->A2(S27);
        AOI22_X1_1->B1(S53);
        AOI22_X1_1->B2(S24);
        AOI22_X1_1->ZN(S52[0]);

    INV_X1_3 = new INV_X1("INV_X1_3");
        INV_X1_3->A(S49[1]);
        INV_X1_3->ZN(S28);

    NAND3_X1_2 = new NAND3_X1("NAND3_X1_2");
        NAND3_X1_2->A1(S25);
        NAND3_X1_2->A2(S55);
        NAND3_X1_2->A3(S51[1]);
        NAND3_X1_2->ZN(S29);

    AOI21_X1_2 = new AOI21_X1("AOI21_X1_2");
        AOI21_X1_2->A(S53);
        AOI21_X1_2->B1(S54);
        AOI21_X1_2->B2(S50[1]);
        AOI21_X1_2->ZN(S30);

    AOI22_X1_2 = new AOI22_X1("AOI22_X1_2");
        AOI22_X1_2->A1(S29);
        AOI22_X1_2->A2(S30);
        AOI22_X1_2->B1(S28);
        AOI22_X1_2->B2(S53);
        AOI22_X1_2->ZN(S52[1]);

    INV_X1_4 = new INV_X1("INV_X1_4");
        INV_X1_4->A(S49[2]);
        INV_X1_4->ZN(S31);

    NAND3_X1_3 = new NAND3_X1("NAND3_X1_3");
        NAND3_X1_3->A1(S25);
        NAND3_X1_3->A2(S55);
        NAND3_X1_3->A3(S51[2]);
        NAND3_X1_3->ZN(S32);

    AOI21_X1_3 = new AOI21_X1("AOI21_X1_3");
        AOI21_X1_3->A(S53);
        AOI21_X1_3->B1(S54);
        AOI21_X1_3->B2(S50[2]);
        AOI21_X1_3->ZN(S33);

    AOI22_X1_3 = new AOI22_X1("AOI22_X1_3");
        AOI22_X1_3->A1(S32);
        AOI22_X1_3->A2(S33);
        AOI22_X1_3->B1(S31);
        AOI22_X1_3->B2(S53);
        AOI22_X1_3->ZN(S52[2]);

    INV_X1_5 = new INV_X1("INV_X1_5");
        INV_X1_5->A(S49[3]);
        INV_X1_5->ZN(S34);

    NAND3_X1_4 = new NAND3_X1("NAND3_X1_4");
        NAND3_X1_4->A1(S25);
        NAND3_X1_4->A2(S55);
        NAND3_X1_4->A3(S51[3]);
        NAND3_X1_4->ZN(S35);

    AOI21_X1_4 = new AOI21_X1("AOI21_X1_4");
        AOI21_X1_4->A(S53);
        AOI21_X1_4->B1(S54);
        AOI21_X1_4->B2(S50[3]);
        AOI21_X1_4->ZN(S36);

    AOI22_X1_4 = new AOI22_X1("AOI22_X1_4");
        AOI22_X1_4->A1(S35);
        AOI22_X1_4->A2(S36);
        AOI22_X1_4->B1(S34);
        AOI22_X1_4->B2(S53);
        AOI22_X1_4->ZN(S52[3]);

    INV_X1_6 = new INV_X1("INV_X1_6");
        INV_X1_6->A(S49[4]);
        INV_X1_6->ZN(S37);

    NAND3_X1_5 = new NAND3_X1("NAND3_X1_5");
        NAND3_X1_5->A1(S25);
        NAND3_X1_5->A2(S55);
        NAND3_X1_5->A3(S51[4]);
        NAND3_X1_5->ZN(S38);

    AOI21_X1_5 = new AOI21_X1("AOI21_X1_5");
        AOI21_X1_5->A(S53);
        AOI21_X1_5->B1(S54);
        AOI21_X1_5->B2(S50[4]);
        AOI21_X1_5->ZN(S39);

    AOI22_X1_5 = new AOI22_X1("AOI22_X1_5");
        AOI22_X1_5->A1(S38);
        AOI22_X1_5->A2(S39);
        AOI22_X1_5->B1(S37);
        AOI22_X1_5->B2(S53);
        AOI22_X1_5->ZN(S52[4]);

    INV_X1_7 = new INV_X1("INV_X1_7");
        INV_X1_7->A(S49[5]);
        INV_X1_7->ZN(S40);

    NAND3_X1_6 = new NAND3_X1("NAND3_X1_6");
        NAND3_X1_6->A1(S25);
        NAND3_X1_6->A2(S55);
        NAND3_X1_6->A3(S51[5]);
        NAND3_X1_6->ZN(S41);

    AOI21_X1_6 = new AOI21_X1("AOI21_X1_6");
        AOI21_X1_6->A(S53);
        AOI21_X1_6->B1(S54);
        AOI21_X1_6->B2(S50[5]);
        AOI21_X1_6->ZN(S42);

    AOI22_X1_6 = new AOI22_X1("AOI22_X1_6");
        AOI22_X1_6->A1(S41);
        AOI22_X1_6->A2(S42);
        AOI22_X1_6->B1(S40);
        AOI22_X1_6->B2(S53);
        AOI22_X1_6->ZN(S52[5]);

    INV_X1_8 = new INV_X1("INV_X1_8");
        INV_X1_8->A(S49[6]);
        INV_X1_8->ZN(S43);

    NAND3_X1_7 = new NAND3_X1("NAND3_X1_7");
        NAND3_X1_7->A1(S25);
        NAND3_X1_7->A2(S55);
        NAND3_X1_7->A3(S51[6]);
        NAND3_X1_7->ZN(S44);

    AOI21_X1_7 = new AOI21_X1("AOI21_X1_7");
        AOI21_X1_7->A(S53);
        AOI21_X1_7->B1(S54);
        AOI21_X1_7->B2(S50[6]);
        AOI21_X1_7->ZN(S45);

    AOI22_X1_7 = new AOI22_X1("AOI22_X1_7");
        AOI22_X1_7->A1(S44);
        AOI22_X1_7->A2(S45);
        AOI22_X1_7->B1(S43);
        AOI22_X1_7->B2(S53);
        AOI22_X1_7->ZN(S52[6]);

    INV_X1_9 = new INV_X1("INV_X1_9");
        INV_X1_9->A(S49[7]);
        INV_X1_9->ZN(S46);

    NAND3_X1_8 = new NAND3_X1("NAND3_X1_8");
        NAND3_X1_8->A1(S25);
        NAND3_X1_8->A2(S55);
        NAND3_X1_8->A3(S51[7]);
        NAND3_X1_8->ZN(S47);

    AOI21_X1_8 = new AOI21_X1("AOI21_X1_8");
        AOI21_X1_8->A(S53);
        AOI21_X1_8->B1(S54);
        AOI21_X1_8->B2(S50[7]);
        AOI21_X1_8->ZN(S48);

    AOI22_X1_8 = new AOI22_X1("AOI22_X1_8");
        AOI22_X1_8->A1(S47);
        AOI22_X1_8->A2(S48);
        AOI22_X1_8->B1(S46);
        AOI22_X1_8->B2(S53);
        AOI22_X1_8->ZN(S52[7]);

    INV_X1_10 = new INV_X1("INV_X1_10");
        INV_X1_10->A(S49[8]);
        INV_X1_10->ZN(S0);

    NAND3_X1_9 = new NAND3_X1("NAND3_X1_9");
        NAND3_X1_9->A1(S25);
        NAND3_X1_9->A2(S55);
        NAND3_X1_9->A3(S51[8]);
        NAND3_X1_9->ZN(S1);

    AOI21_X1_9 = new AOI21_X1("AOI21_X1_9");
        AOI21_X1_9->A(S53);
        AOI21_X1_9->B1(S54);
        AOI21_X1_9->B2(S50[8]);
        AOI21_X1_9->ZN(S2);

    AOI22_X1_9 = new AOI22_X1("AOI22_X1_9");
        AOI22_X1_9->A1(S1);
        AOI22_X1_9->A2(S2);
        AOI22_X1_9->B1(S0);
        AOI22_X1_9->B2(S53);
        AOI22_X1_9->ZN(S52[8]);

    INV_X1_11 = new INV_X1("INV_X1_11");
        INV_X1_11->A(S49[9]);
        INV_X1_11->ZN(S3);

    NAND3_X1_10 = new NAND3_X1("NAND3_X1_10");
        NAND3_X1_10->A1(S25);
        NAND3_X1_10->A2(S55);
        NAND3_X1_10->A3(S51[9]);
        NAND3_X1_10->ZN(S4);

    AOI21_X1_10 = new AOI21_X1("AOI21_X1_10");
        AOI21_X1_10->A(S53);
        AOI21_X1_10->B1(S54);
        AOI21_X1_10->B2(S50[9]);
        AOI21_X1_10->ZN(S5);

    AOI22_X1_10 = new AOI22_X1("AOI22_X1_10");
        AOI22_X1_10->A1(S4);
        AOI22_X1_10->A2(S5);
        AOI22_X1_10->B1(S3);
        AOI22_X1_10->B2(S53);
        AOI22_X1_10->ZN(S52[9]);

    INV_X1_12 = new INV_X1("INV_X1_12");
        INV_X1_12->A(S49[10]);
        INV_X1_12->ZN(S6);

    NAND3_X1_11 = new NAND3_X1("NAND3_X1_11");
        NAND3_X1_11->A1(S25);
        NAND3_X1_11->A2(S55);
        NAND3_X1_11->A3(S51[10]);
        NAND3_X1_11->ZN(S7);

    AOI21_X1_11 = new AOI21_X1("AOI21_X1_11");
        AOI21_X1_11->A(S53);
        AOI21_X1_11->B1(S54);
        AOI21_X1_11->B2(S50[10]);
        AOI21_X1_11->ZN(S8);

    AOI22_X1_11 = new AOI22_X1("AOI22_X1_11");
        AOI22_X1_11->A1(S7);
        AOI22_X1_11->A2(S8);
        AOI22_X1_11->B1(S6);
        AOI22_X1_11->B2(S53);
        AOI22_X1_11->ZN(S52[10]);

    INV_X1_13 = new INV_X1("INV_X1_13");
        INV_X1_13->A(S49[11]);
        INV_X1_13->ZN(S9);

    NAND3_X1_12 = new NAND3_X1("NAND3_X1_12");
        NAND3_X1_12->A1(S25);
        NAND3_X1_12->A2(S55);
        NAND3_X1_12->A3(S51[11]);
        NAND3_X1_12->ZN(S10);

    AOI21_X1_12 = new AOI21_X1("AOI21_X1_12");
        AOI21_X1_12->A(S53);
        AOI21_X1_12->B1(S54);
        AOI21_X1_12->B2(S50[11]);
        AOI21_X1_12->ZN(S11);

    AOI22_X1_12 = new AOI22_X1("AOI22_X1_12");
        AOI22_X1_12->A1(S10);
        AOI22_X1_12->A2(S11);
        AOI22_X1_12->B1(S9);
        AOI22_X1_12->B2(S53);
        AOI22_X1_12->ZN(S52[11]);

    INV_X1_14 = new INV_X1("INV_X1_14");
        INV_X1_14->A(S49[12]);
        INV_X1_14->ZN(S12);

    NAND3_X1_13 = new NAND3_X1("NAND3_X1_13");
        NAND3_X1_13->A1(S25);
        NAND3_X1_13->A2(S55);
        NAND3_X1_13->A3(S51[12]);
        NAND3_X1_13->ZN(S13);

    AOI21_X1_13 = new AOI21_X1("AOI21_X1_13");
        AOI21_X1_13->A(S53);
        AOI21_X1_13->B1(S54);
        AOI21_X1_13->B2(S50[12]);
        AOI21_X1_13->ZN(S14);

    AOI22_X1_13 = new AOI22_X1("AOI22_X1_13");
        AOI22_X1_13->A1(S13);
        AOI22_X1_13->A2(S14);
        AOI22_X1_13->B1(S12);
        AOI22_X1_13->B2(S53);
        AOI22_X1_13->ZN(S52[12]);

    INV_X1_15 = new INV_X1("INV_X1_15");
        INV_X1_15->A(S49[13]);
        INV_X1_15->ZN(S15);

    NAND3_X1_14 = new NAND3_X1("NAND3_X1_14");
        NAND3_X1_14->A1(S25);
        NAND3_X1_14->A2(S55);
        NAND3_X1_14->A3(S51[13]);
        NAND3_X1_14->ZN(S16);

    AOI21_X1_14 = new AOI21_X1("AOI21_X1_14");
        AOI21_X1_14->A(S53);
        AOI21_X1_14->B1(S54);
        AOI21_X1_14->B2(S50[13]);
        AOI21_X1_14->ZN(S17);

    AOI22_X1_14 = new AOI22_X1("AOI22_X1_14");
        AOI22_X1_14->A1(S16);
        AOI22_X1_14->A2(S17);
        AOI22_X1_14->B1(S15);
        AOI22_X1_14->B2(S53);
        AOI22_X1_14->ZN(S52[13]);

    INV_X1_16 = new INV_X1("INV_X1_16");
        INV_X1_16->A(S49[14]);
        INV_X1_16->ZN(S18);

    NAND3_X1_15 = new NAND3_X1("NAND3_X1_15");
        NAND3_X1_15->A1(S25);
        NAND3_X1_15->A2(S55);
        NAND3_X1_15->A3(S51[14]);
        NAND3_X1_15->ZN(S19);

    AOI21_X1_15 = new AOI21_X1("AOI21_X1_15");
        AOI21_X1_15->A(S53);
        AOI21_X1_15->B1(S54);
        AOI21_X1_15->B2(S50[14]);
        AOI21_X1_15->ZN(S20);

    AOI22_X1_15 = new AOI22_X1("AOI22_X1_15");
        AOI22_X1_15->A1(S19);
        AOI22_X1_15->A2(S20);
        AOI22_X1_15->B1(S18);
        AOI22_X1_15->B2(S53);
        AOI22_X1_15->ZN(S52[14]);

    INV_X1_17 = new INV_X1("INV_X1_17");
        INV_X1_17->A(S49[15]);
        INV_X1_17->ZN(S21);

    NAND3_X1_16 = new NAND3_X1("NAND3_X1_16");
        NAND3_X1_16->A1(S25);
        NAND3_X1_16->A2(S55);
        NAND3_X1_16->A3(S51[15]);
        NAND3_X1_16->ZN(S22);

    AOI21_X1_16 = new AOI21_X1("AOI21_X1_16");
        AOI21_X1_16->A(S53);
        AOI21_X1_16->B1(S54);
        AOI21_X1_16->B2(S50[15]);
        AOI21_X1_16->ZN(S23);

    AOI22_X1_16 = new AOI22_X1("AOI22_X1_16");
        AOI22_X1_16->A1(S22);
        AOI22_X1_16->A2(S23);
        AOI22_X1_16->B1(S21);
        AOI22_X1_16->B2(S53);
        AOI22_X1_16->ZN(S52[15]);

    BUF_X1_1 = new BUF_X1("BUF_X1_1");
        BUF_X1_1->A(in1[0]);
        BUF_X1_1->Z(S49[0]);

    BUF_X1_2 = new BUF_X1("BUF_X1_2");
        BUF_X1_2->A(in1[1]);
        BUF_X1_2->Z(S49[1]);

    BUF_X1_3 = new BUF_X1("BUF_X1_3");
        BUF_X1_3->A(in1[10]);
        BUF_X1_3->Z(S49[10]);

    BUF_X1_4 = new BUF_X1("BUF_X1_4");
        BUF_X1_4->A(in1[11]);
        BUF_X1_4->Z(S49[11]);

    BUF_X1_5 = new BUF_X1("BUF_X1_5");
        BUF_X1_5->A(in1[12]);
        BUF_X1_5->Z(S49[12]);

    BUF_X1_6 = new BUF_X1("BUF_X1_6");
        BUF_X1_6->A(in1[13]);
        BUF_X1_6->Z(S49[13]);

    BUF_X1_7 = new BUF_X1("BUF_X1_7");
        BUF_X1_7->A(in1[14]);
        BUF_X1_7->Z(S49[14]);

    BUF_X1_8 = new BUF_X1("BUF_X1_8");
        BUF_X1_8->A(in1[15]);
        BUF_X1_8->Z(S49[15]);

    BUF_X1_9 = new BUF_X1("BUF_X1_9");
        BUF_X1_9->A(in1[2]);
        BUF_X1_9->Z(S49[2]);

    BUF_X1_10 = new BUF_X1("BUF_X1_10");
        BUF_X1_10->A(in1[3]);
        BUF_X1_10->Z(S49[3]);

    BUF_X1_11 = new BUF_X1("BUF_X1_11");
        BUF_X1_11->A(in1[4]);
        BUF_X1_11->Z(S49[4]);

    BUF_X1_12 = new BUF_X1("BUF_X1_12");
        BUF_X1_12->A(in1[5]);
        BUF_X1_12->Z(S49[5]);

    BUF_X1_13 = new BUF_X1("BUF_X1_13");
        BUF_X1_13->A(in1[6]);
        BUF_X1_13->Z(S49[6]);

    BUF_X1_14 = new BUF_X1("BUF_X1_14");
        BUF_X1_14->A(in1[7]);
        BUF_X1_14->Z(S49[7]);

    BUF_X1_15 = new BUF_X1("BUF_X1_15");
        BUF_X1_15->A(in1[8]);
        BUF_X1_15->Z(S49[8]);

    BUF_X1_16 = new BUF_X1("BUF_X1_16");
        BUF_X1_16->A(in1[9]);
        BUF_X1_16->Z(S49[9]);

    BUF_X1_17 = new BUF_X1("BUF_X1_17");
        BUF_X1_17->A(in2[0]);
        BUF_X1_17->Z(S50[0]);

    BUF_X1_18 = new BUF_X1("BUF_X1_18");
        BUF_X1_18->A(in2[1]);
        BUF_X1_18->Z(S50[1]);

    BUF_X1_19 = new BUF_X1("BUF_X1_19");
        BUF_X1_19->A(in2[10]);
        BUF_X1_19->Z(S50[10]);

    BUF_X1_20 = new BUF_X1("BUF_X1_20");
        BUF_X1_20->A(in2[11]);
        BUF_X1_20->Z(S50[11]);

    BUF_X1_21 = new BUF_X1("BUF_X1_21");
        BUF_X1_21->A(in2[12]);
        BUF_X1_21->Z(S50[12]);

    BUF_X1_22 = new BUF_X1("BUF_X1_22");
        BUF_X1_22->A(in2[13]);
        BUF_X1_22->Z(S50[13]);

    BUF_X1_23 = new BUF_X1("BUF_X1_23");
        BUF_X1_23->A(in2[14]);
        BUF_X1_23->Z(S50[14]);

    BUF_X1_24 = new BUF_X1("BUF_X1_24");
        BUF_X1_24->A(in2[15]);
        BUF_X1_24->Z(S50[15]);

    BUF_X1_25 = new BUF_X1("BUF_X1_25");
        BUF_X1_25->A(in2[2]);
        BUF_X1_25->Z(S50[2]);

    BUF_X1_26 = new BUF_X1("BUF_X1_26");
        BUF_X1_26->A(in2[3]);
        BUF_X1_26->Z(S50[3]);

    BUF_X1_27 = new BUF_X1("BUF_X1_27");
        BUF_X1_27->A(in2[4]);
        BUF_X1_27->Z(S50[4]);

    BUF_X1_28 = new BUF_X1("BUF_X1_28");
        BUF_X1_28->A(in2[5]);
        BUF_X1_28->Z(S50[5]);

    BUF_X1_29 = new BUF_X1("BUF_X1_29");
        BUF_X1_29->A(in2[6]);
        BUF_X1_29->Z(S50[6]);

    BUF_X1_30 = new BUF_X1("BUF_X1_30");
        BUF_X1_30->A(in2[7]);
        BUF_X1_30->Z(S50[7]);

    BUF_X1_31 = new BUF_X1("BUF_X1_31");
        BUF_X1_31->A(in2[8]);
        BUF_X1_31->Z(S50[8]);

    BUF_X1_32 = new BUF_X1("BUF_X1_32");
        BUF_X1_32->A(in2[9]);
        BUF_X1_32->Z(S50[9]);

    BUF_X1_33 = new BUF_X1("BUF_X1_33");
        BUF_X1_33->A(in3[0]);
        BUF_X1_33->Z(S51[0]);

    BUF_X1_34 = new BUF_X1("BUF_X1_34");
        BUF_X1_34->A(in3[1]);
        BUF_X1_34->Z(S51[1]);

    BUF_X1_35 = new BUF_X1("BUF_X1_35");
        BUF_X1_35->A(in3[10]);
        BUF_X1_35->Z(S51[10]);

    BUF_X1_36 = new BUF_X1("BUF_X1_36");
        BUF_X1_36->A(in3[11]);
        BUF_X1_36->Z(S51[11]);

    BUF_X1_37 = new BUF_X1("BUF_X1_37");
        BUF_X1_37->A(in3[12]);
        BUF_X1_37->Z(S51[12]);

    BUF_X1_38 = new BUF_X1("BUF_X1_38");
        BUF_X1_38->A(in3[13]);
        BUF_X1_38->Z(S51[13]);

    BUF_X1_39 = new BUF_X1("BUF_X1_39");
        BUF_X1_39->A(in3[14]);
        BUF_X1_39->Z(S51[14]);

    BUF_X1_40 = new BUF_X1("BUF_X1_40");
        BUF_X1_40->A(in3[15]);
        BUF_X1_40->Z(S51[15]);

    BUF_X1_41 = new BUF_X1("BUF_X1_41");
        BUF_X1_41->A(in3[2]);
        BUF_X1_41->Z(S51[2]);

    BUF_X1_42 = new BUF_X1("BUF_X1_42");
        BUF_X1_42->A(in3[3]);
        BUF_X1_42->Z(S51[3]);

    BUF_X1_43 = new BUF_X1("BUF_X1_43");
        BUF_X1_43->A(in3[4]);
        BUF_X1_43->Z(S51[4]);

    BUF_X1_44 = new BUF_X1("BUF_X1_44");
        BUF_X1_44->A(in3[5]);
        BUF_X1_44->Z(S51[5]);

    BUF_X1_45 = new BUF_X1("BUF_X1_45");
        BUF_X1_45->A(in3[6]);
        BUF_X1_45->Z(S51[6]);

    BUF_X1_46 = new BUF_X1("BUF_X1_46");
        BUF_X1_46->A(in3[7]);
        BUF_X1_46->Z(S51[7]);

    BUF_X1_47 = new BUF_X1("BUF_X1_47");
        BUF_X1_47->A(in3[8]);
        BUF_X1_47->Z(S51[8]);

    BUF_X1_48 = new BUF_X1("BUF_X1_48");
        BUF_X1_48->A(in3[9]);
        BUF_X1_48->Z(S51[9]);

    BUF_X1_49 = new BUF_X1("BUF_X1_49");
        BUF_X1_49->A(S52[0]);
        BUF_X1_49->Z(outmux[0]);

    BUF_X1_50 = new BUF_X1("BUF_X1_50");
        BUF_X1_50->A(S52[1]);
        BUF_X1_50->Z(outmux[1]);

    BUF_X1_51 = new BUF_X1("BUF_X1_51");
        BUF_X1_51->A(S52[10]);
        BUF_X1_51->Z(outmux[10]);

    BUF_X1_52 = new BUF_X1("BUF_X1_52");
        BUF_X1_52->A(S52[11]);
        BUF_X1_52->Z(outmux[11]);

    BUF_X1_53 = new BUF_X1("BUF_X1_53");
        BUF_X1_53->A(S52[12]);
        BUF_X1_53->Z(outmux[12]);

    BUF_X1_54 = new BUF_X1("BUF_X1_54");
        BUF_X1_54->A(S52[13]);
        BUF_X1_54->Z(outmux[13]);

    BUF_X1_55 = new BUF_X1("BUF_X1_55");
        BUF_X1_55->A(S52[14]);
        BUF_X1_55->Z(outmux[14]);

    BUF_X1_56 = new BUF_X1("BUF_X1_56");
        BUF_X1_56->A(S52[15]);
        BUF_X1_56->Z(outmux[15]);

    BUF_X1_57 = new BUF_X1("BUF_X1_57");
        BUF_X1_57->A(S52[2]);
        BUF_X1_57->Z(outmux[2]);

    BUF_X1_58 = new BUF_X1("BUF_X1_58");
        BUF_X1_58->A(S52[3]);
        BUF_X1_58->Z(outmux[3]);

    BUF_X1_59 = new BUF_X1("BUF_X1_59");
        BUF_X1_59->A(S52[4]);
        BUF_X1_59->Z(outmux[4]);

    BUF_X1_60 = new BUF_X1("BUF_X1_60");
        BUF_X1_60->A(S52[5]);
        BUF_X1_60->Z(outmux[5]);

    BUF_X1_61 = new BUF_X1("BUF_X1_61");
        BUF_X1_61->A(S52[6]);
        BUF_X1_61->Z(outmux[6]);

    BUF_X1_62 = new BUF_X1("BUF_X1_62");
        BUF_X1_62->A(S52[7]);
        BUF_X1_62->Z(outmux[7]);

    BUF_X1_63 = new BUF_X1("BUF_X1_63");
        BUF_X1_63->A(S52[8]);
        BUF_X1_63->Z(outmux[8]);

    BUF_X1_64 = new BUF_X1("BUF_X1_64");
        BUF_X1_64->A(S52[9]);
        BUF_X1_64->Z(outmux[9]);

    BUF_X1_65 = new BUF_X1("BUF_X1_65");
        BUF_X1_65->A(sel1);
        BUF_X1_65->Z(S53);

    BUF_X1_66 = new BUF_X1("BUF_X1_66");
        BUF_X1_66->A(sel2);
        BUF_X1_66->Z(S54);

    BUF_X1_67 = new BUF_X1("BUF_X1_67");
        BUF_X1_67->A(sel3);
        BUF_X1_67->Z(S55);


    SC_METHOD(sc_logic_signal_assignment);

    }

    void sc_logic_signal_assignment(void){ 
        sc_logic_1_signal.write(SC_LOGIC_1);
        sc_logic_0_signal.write(SC_LOGIC_0);
    }
};
#endif /* __MUX3OF16BITS_H__ */

