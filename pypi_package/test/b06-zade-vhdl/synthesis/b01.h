#include <systemc.h>
#include "Complex_NAgate_45.h"



#ifndef __B01_H__
#define __B01_H__
using namespace sc_core;

SC_MODULE( b01 ) {

    sc_in<sc_logic> line1;
    sc_in<sc_logic> line2;
    sc_in<sc_logic> reset;
    sc_in<sc_logic> clock;
    sc_out<sc_logic> outp;
    sc_out<sc_logic> overflw;

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
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _2_stato_0_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_2_stato_0_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _2_stato_1_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_2_stato_1_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _2_stato_2_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_2_stato_2_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _79_Y_0_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_79_Y_0_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _79_Y_1_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_79_Y_1_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _79_Y_2_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_79_Y_2_");

    INV_X1* INV_X1_1;
    INV_X1* INV_X1_2;
    NAND3_X1* NAND3_X1_1;
    NAND2_X1* NAND2_X1_1;
    NAND2_X1* NAND2_X1_2;
    INV_X1* INV_X1_3;
    NOR2_X1* NOR2_X1_1;
    NOR2_X1* NOR2_X1_2;
    XNOR2_X1* XNOR2_X1_1;
    INV_X1* INV_X1_4;
    INV_X1* INV_X1_5;
    NAND3_X1* NAND3_X1_2;
    AOI21_X1* AOI21_X1_1;
    NAND4_X1* NAND4_X1_1;
    NOR3_X1* NOR3_X1_1;
    NOR3_X1* NOR3_X1_2;
    AOI22_X1* AOI22_X1_1;
    NAND3_X1* NAND3_X1_3;
    NOR2_X1* NOR2_X1_3;
    NAND3_X1* NAND3_X1_4;
    NAND3_X1* NAND3_X1_5;
    AOI21_X1* AOI21_X1_2;
    NOR2_X1* NOR2_X1_4;
    NOR2_X1* NOR2_X1_5;
    NOR2_X1* NOR2_X1_6;
    NOR2_X1* NOR2_X1_7;
    NAND4_X1* NAND4_X1_2;
    NOR2_X1* NOR2_X1_8;
    NOR2_X1* NOR2_X1_9;
    NOR2_X1* NOR2_X1_10;
    AOI21_X1* AOI21_X1_3;
    NAND2_X1* NAND2_X1_3;
    NAND4_X1* NAND4_X1_3;
    AOI21_X1* AOI21_X1_4;
    NAND2_X1* NAND2_X1_4;
    NAND2_X1* NAND2_X1_5;
    NAND3_X1* NAND3_X1_6;
    AOI21_X1* AOI21_X1_5;
    NOR2_X1* NOR2_X1_11;
    INV_X1* INV_X1_6;
    DFFR_X1* DFFR_X1_1;
    DFFR_X1* DFFR_X1_2;
    DFFR_X1* DFFR_X1_3;
    DFFR_X1* DFFR_X1_4;
    DFFR_X1* DFFR_X1_5;
    BUF_X1* BUF_X1_1;
    BUF_X1* BUF_X1_2;
    BUF_X1* BUF_X1_3;
    BUF_X1* BUF_X1_4;
    BUF_X1* BUF_X1_5;
    BUF_X1* BUF_X1_6;

SC_CTOR( b01 ) {
    INV_X1_1 = new INV_X1("INV_X1_1");
        INV_X1_1->A(S2);
        INV_X1_1->ZN(S4);

    INV_X1_2 = new INV_X1("INV_X1_2");
        INV_X1_2->A(_2_stato_0_);
        INV_X1_2->ZN(S5);

    NAND3_X1_1 = new NAND3_X1("NAND3_X1_1");
        NAND3_X1_1->A1(S5);
        NAND3_X1_1->A2(_2_stato_1_);
        NAND3_X1_1->A3(_2_stato_2_);
        NAND3_X1_1->ZN(S6);

    NAND2_X1_1 = new NAND2_X1("NAND2_X1_1");
        NAND2_X1_1->A1(S6);
        NAND2_X1_1->A2(S4);
        NAND2_X1_1->ZN(S7);

    NAND2_X1_2 = new NAND2_X1("NAND2_X1_2");
        NAND2_X1_2->A1(S44);
        NAND2_X1_2->A2(S43);
        NAND2_X1_2->ZN(S8);

    INV_X1_3 = new INV_X1("INV_X1_3");
        INV_X1_3->A(S8);
        INV_X1_3->ZN(S9);

    NOR2_X1_1 = new NOR2_X1("NOR2_X1_1");
        NOR2_X1_1->A1(S44);
        NOR2_X1_1->A2(S43);
        NOR2_X1_1->ZN(S10);

    NOR2_X1_2 = new NOR2_X1("NOR2_X1_2");
        NOR2_X1_2->A1(S9);
        NOR2_X1_2->A2(S10);
        NOR2_X1_2->ZN(S11);

    XNOR2_X1_1 = new XNOR2_X1("XNOR2_X1_1");
        XNOR2_X1_1->A(S11);
        XNOR2_X1_1->B(S7);
        XNOR2_X1_1->ZN(S0);

    INV_X1_4 = new INV_X1("INV_X1_4");
        INV_X1_4->A(S10);
        INV_X1_4->ZN(S12);

    INV_X1_5 = new INV_X1("INV_X1_5");
        INV_X1_5->A(_2_stato_1_);
        INV_X1_5->ZN(S13);

    NAND3_X1_2 = new NAND3_X1("NAND3_X1_2");
        NAND3_X1_2->A1(S13);
        NAND3_X1_2->A2(_2_stato_0_);
        NAND3_X1_2->A3(_2_stato_2_);
        NAND3_X1_2->ZN(S14);

    AOI21_X1_1 = new AOI21_X1("AOI21_X1_1");
        AOI21_X1_1->A(S2);
        AOI21_X1_1->B1(S5);
        AOI21_X1_1->B2(S13);
        AOI21_X1_1->ZN(S15);

    NAND4_X1_1 = new NAND4_X1("NAND4_X1_1");
        NAND4_X1_1->A1(S15);
        NAND4_X1_1->A2(S12);
        NAND4_X1_1->A3(S14);
        NAND4_X1_1->A4(S6);
        NAND4_X1_1->ZN(S16);

    NOR3_X1_1 = new NOR3_X1("NOR3_X1_1");
        NOR3_X1_1->A1(S4);
        NOR3_X1_1->A2(S13);
        NOR3_X1_1->A3(_2_stato_0_);
        NOR3_X1_1->ZN(S17);

    NOR3_X1_2 = new NOR3_X1("NOR3_X1_2");
        NOR3_X1_2->A1(_2_stato_1_);
        NOR3_X1_2->A2(_2_stato_0_);
        NOR3_X1_2->A3(S2);
        NOR3_X1_2->ZN(S18);

    AOI22_X1_1 = new AOI22_X1("AOI22_X1_1");
        AOI22_X1_1->A1(S17);
        AOI22_X1_1->A2(S9);
        AOI22_X1_1->B1(S18);
        AOI22_X1_1->B2(S12);
        AOI22_X1_1->ZN(S19);

    NAND3_X1_3 = new NAND3_X1("NAND3_X1_3");
        NAND3_X1_3->A1(S13);
        NAND3_X1_3->A2(_2_stato_0_);
        NAND3_X1_3->A3(S2);
        NAND3_X1_3->ZN(S20);

    NOR2_X1_3 = new NOR2_X1("NOR2_X1_3");
        NOR2_X1_3->A1(S20);
        NOR2_X1_3->A2(S8);
        NOR2_X1_3->ZN(S21);

    NAND3_X1_4 = new NAND3_X1("NAND3_X1_4");
        NAND3_X1_4->A1(_2_stato_1_);
        NAND3_X1_4->A2(_2_stato_0_);
        NAND3_X1_4->A3(S2);
        NAND3_X1_4->ZN(S22);

    NAND3_X1_5 = new NAND3_X1("NAND3_X1_5");
        NAND3_X1_5->A1(S13);
        NAND3_X1_5->A2(S5);
        NAND3_X1_5->A3(S2);
        NAND3_X1_5->ZN(S23);

    AOI21_X1_2 = new AOI21_X1("AOI21_X1_2");
        AOI21_X1_2->A(S9);
        AOI21_X1_2->B1(S23);
        AOI21_X1_2->B2(S22);
        AOI21_X1_2->ZN(S24);

    NOR2_X1_4 = new NOR2_X1("NOR2_X1_4");
        NOR2_X1_4->A1(S24);
        NOR2_X1_4->A2(S21);
        NOR2_X1_4->ZN(S25);

    NOR2_X1_5 = new NOR2_X1("NOR2_X1_5");
        NOR2_X1_5->A1(S14);
        NOR2_X1_5->A2(S10);
        NOR2_X1_5->ZN(S26);

    NOR2_X1_6 = new NOR2_X1("NOR2_X1_6");
        NOR2_X1_6->A1(S6);
        NOR2_X1_6->A2(S8);
        NOR2_X1_6->ZN(S27);

    NOR2_X1_7 = new NOR2_X1("NOR2_X1_7");
        NOR2_X1_7->A1(S26);
        NOR2_X1_7->A2(S27);
        NOR2_X1_7->ZN(S28);

    NAND4_X1_2 = new NAND4_X1("NAND4_X1_2");
        NAND4_X1_2->A1(S25);
        NAND4_X1_2->A2(S28);
        NAND4_X1_2->A3(S16);
        NAND4_X1_2->A4(S19);
        NAND4_X1_2->ZN(_79_Y_0_);

    NOR2_X1_8 = new NOR2_X1("NOR2_X1_8");
        NOR2_X1_8->A1(S20);
        NOR2_X1_8->A2(S9);
        NOR2_X1_8->ZN(S29);

    NOR2_X1_9 = new NOR2_X1("NOR2_X1_9");
        NOR2_X1_9->A1(S29);
        NOR2_X1_9->A2(S27);
        NOR2_X1_9->ZN(S30);

    NOR2_X1_10 = new NOR2_X1("NOR2_X1_10");
        NOR2_X1_10->A1(S5);
        NOR2_X1_10->A2(_2_stato_1_);
        NOR2_X1_10->ZN(S31);

    AOI21_X1_3 = new AOI21_X1("AOI21_X1_3");
        AOI21_X1_3->A(S17);
        AOI21_X1_3->B1(S31);
        AOI21_X1_3->B2(_2_stato_2_);
        AOI21_X1_3->ZN(S32);

    NAND2_X1_3 = new NAND2_X1("NAND2_X1_3");
        NAND2_X1_3->A1(S18);
        NAND2_X1_3->A2(S10);
        NAND2_X1_3->ZN(S33);

    NAND4_X1_3 = new NAND4_X1("NAND4_X1_3");
        NAND4_X1_3->A1(S30);
        NAND4_X1_3->A2(S32);
        NAND4_X1_3->A3(S16);
        NAND4_X1_3->A4(S33);
        NAND4_X1_3->ZN(_79_Y_1_);

    AOI21_X1_4 = new AOI21_X1("AOI21_X1_4");
        AOI21_X1_4->A(S21);
        AOI21_X1_4->B1(S18);
        AOI21_X1_4->B2(S12);
        AOI21_X1_4->ZN(S34);

    NAND2_X1_4 = new NAND2_X1("NAND2_X1_4");
        NAND2_X1_4->A1(S23);
        NAND2_X1_4->A2(S22);
        NAND2_X1_4->ZN(S35);

    NAND2_X1_5 = new NAND2_X1("NAND2_X1_5");
        NAND2_X1_5->A1(S35);
        NAND2_X1_5->A2(S9);
        NAND2_X1_5->ZN(S36);

    NAND3_X1_6 = new NAND3_X1("NAND3_X1_6");
        NAND3_X1_6->A1(S34);
        NAND3_X1_6->A2(S32);
        NAND3_X1_6->A3(S36);
        NAND3_X1_6->ZN(_79_Y_2_);

    AOI21_X1_5 = new AOI21_X1("AOI21_X1_5");
        AOI21_X1_5->A(S15);
        AOI21_X1_5->B1(_2_stato_0_);
        AOI21_X1_5->B2(_2_stato_1_);
        AOI21_X1_5->ZN(S37);

    NOR2_X1_11 = new NOR2_X1("NOR2_X1_11");
        NOR2_X1_11->A1(S37);
        NOR2_X1_11->A2(_2_stato_2_);
        NOR2_X1_11->ZN(S1);

    INV_X1_6 = new INV_X1("INV_X1_6");
        INV_X1_6->A(S47);
        INV_X1_6->ZN(S3);

    DFFR_X1_1 = new DFFR_X1("DFFR_X1_1");
        DFFR_X1_1->CK(S42);
        DFFR_X1_1->D(_79_Y_0_);
        DFFR_X1_1->Q(_2_stato_0_);
        DFFR_X1_1->QN(S41);
        DFFR_X1_1->RN(S3);

    DFFR_X1_2 = new DFFR_X1("DFFR_X1_2");
        DFFR_X1_2->CK(S42);
        DFFR_X1_2->D(_79_Y_1_);
        DFFR_X1_2->Q(_2_stato_1_);
        DFFR_X1_2->QN(S40);
        DFFR_X1_2->RN(S3);

    DFFR_X1_3 = new DFFR_X1("DFFR_X1_3");
        DFFR_X1_3->CK(S42);
        DFFR_X1_3->D(_79_Y_2_);
        DFFR_X1_3->Q(_2_stato_2_);
        DFFR_X1_3->QN(S2);
        DFFR_X1_3->RN(S3);

    DFFR_X1_4 = new DFFR_X1("DFFR_X1_4");
        DFFR_X1_4->CK(S42);
        DFFR_X1_4->D(S0);
        DFFR_X1_4->Q(S45);
        DFFR_X1_4->QN(S39);
        DFFR_X1_4->RN(S3);

    DFFR_X1_5 = new DFFR_X1("DFFR_X1_5");
        DFFR_X1_5->CK(S42);
        DFFR_X1_5->D(S1);
        DFFR_X1_5->Q(S46);
        DFFR_X1_5->QN(S38);
        DFFR_X1_5->RN(S3);

    BUF_X1_1 = new BUF_X1("BUF_X1_1");
        BUF_X1_1->A(clock);
        BUF_X1_1->Z(S42);

    BUF_X1_2 = new BUF_X1("BUF_X1_2");
        BUF_X1_2->A(line1);
        BUF_X1_2->Z(S43);

    BUF_X1_3 = new BUF_X1("BUF_X1_3");
        BUF_X1_3->A(line2);
        BUF_X1_3->Z(S44);

    BUF_X1_4 = new BUF_X1("BUF_X1_4");
        BUF_X1_4->A(S45);
        BUF_X1_4->Z(outp);

    BUF_X1_5 = new BUF_X1("BUF_X1_5");
        BUF_X1_5->A(S46);
        BUF_X1_5->Z(overflw);

    BUF_X1_6 = new BUF_X1("BUF_X1_6");
        BUF_X1_6->A(reset);
        BUF_X1_6->Z(S47);


    SC_METHOD(sc_logic_signal_assignment);

    }

    void sc_logic_signal_assignment(void){ 
        sc_logic_1_signal.write(SC_LOGIC_1);
        sc_logic_0_signal.write(SC_LOGIC_0);
    }
};
#endif /* __B01_H__ */

