#include <systemc.h>
#include "Complex_NAgate_45.h"



#ifndef __COUNTER_3_H__
#define __COUNTER_3_H__
using namespace sc_core;

SC_MODULE( counter_3 ) {

    sc_in<sc_logic> clk;
    sc_in<sc_logic> rst;
    sc_in<sc_logic> en;
    sc_out<sc_logic> c[4];

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
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S21[4];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S22 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S22");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S23 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S23");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S24 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S24");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> counter_0_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("counter_0_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> counter_1_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("counter_1_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> counter_2_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("counter_2_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> counter_3_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("counter_3_");

    INV_X1* INV_X1_1;
    NOR2_X1* NOR2_X1_1;
    AOI211_X1* AOI211_X1_1;
    AND3_X1* AND3_X1_1;
    INV_X1* INV_X1_2;
    AND2_X1* AND2_X1_1;
    OAI21_X1* OAI21_X1_1;
    NOR2_X1* NOR2_X1_2;
    NOR2_X1* NOR2_X1_3;
    NAND4_X1* NAND4_X1_1;
    NAND2_X1* NAND2_X1_1;
    NOR2_X1* NOR2_X1_4;
    NAND2_X1* NAND2_X1_2;
    INV_X1* INV_X1_3;
    AND2_X1* AND2_X1_2;
    NAND3_X1* NAND3_X1_1;
    AOI21_X1* AOI21_X1_1;
    DFF_X1* DFF_X1_1;
    DFF_X1* DFF_X1_2;
    DFF_X1* DFF_X1_3;
    DFF_X1* DFF_X1_4;
    BUF_X1* BUF_X1_1;
    BUF_X1* BUF_X1_2;
    BUF_X1* BUF_X1_3;
    BUF_X1* BUF_X1_4;
    BUF_X1* BUF_X1_5;
    BUF_X1* BUF_X1_6;
    BUF_X1* BUF_X1_7;

SC_CTOR( counter_3 ) {
    INV_X1_1 = new INV_X1("INV_X1_1");
        INV_X1_1->A(S17);
        INV_X1_1->ZN(S4);

    NOR2_X1_1 = new NOR2_X1("NOR2_X1_1");
        NOR2_X1_1->A1(S21[0]);
        NOR2_X1_1->A2(S23);
        NOR2_X1_1->ZN(S5);

    AOI211_X1_1 = new AOI211_X1("AOI211_X1_1");
        AOI211_X1_1->A(S24);
        AOI211_X1_1->B(S5);
        AOI211_X1_1->C1(S23);
        AOI211_X1_1->C2(S4);
        AOI211_X1_1->ZN(S0);

    AND3_X1_1 = new AND3_X1("AND3_X1_1");
        AND3_X1_1->A1(S23);
        AND3_X1_1->A2(S21[0]);
        AND3_X1_1->A3(S21[1]);
        AND3_X1_1->ZN(S6);

    INV_X1_2 = new INV_X1("INV_X1_2");
        INV_X1_2->A(S24);
        INV_X1_2->ZN(S7);

    AND2_X1_1 = new AND2_X1("AND2_X1_1");
        AND2_X1_1->A1(S23);
        AND2_X1_1->A2(S21[0]);
        AND2_X1_1->ZN(S8);

    OAI21_X1_1 = new OAI21_X1("OAI21_X1_1");
        OAI21_X1_1->A(S7);
        OAI21_X1_1->B1(S8);
        OAI21_X1_1->B2(S21[1]);
        OAI21_X1_1->ZN(S9);

    NOR2_X1_2 = new NOR2_X1("NOR2_X1_2");
        NOR2_X1_2->A1(S9);
        NOR2_X1_2->A2(S6);
        NOR2_X1_2->ZN(S1);

    NOR2_X1_3 = new NOR2_X1("NOR2_X1_3");
        NOR2_X1_3->A1(S6);
        NOR2_X1_3->A2(S21[2]);
        NOR2_X1_3->ZN(S10);

    NAND4_X1_1 = new NAND4_X1("NAND4_X1_1");
        NAND4_X1_1->A1(S21[2]);
        NAND4_X1_1->A2(S23);
        NAND4_X1_1->A3(S21[1]);
        NAND4_X1_1->A4(S21[0]);
        NAND4_X1_1->ZN(S11);

    NAND2_X1_1 = new NAND2_X1("NAND2_X1_1");
        NAND2_X1_1->A1(S11);
        NAND2_X1_1->A2(S7);
        NAND2_X1_1->ZN(S12);

    NOR2_X1_4 = new NOR2_X1("NOR2_X1_4");
        NOR2_X1_4->A1(S10);
        NOR2_X1_4->A2(S12);
        NOR2_X1_4->ZN(S2);

    NAND2_X1_2 = new NAND2_X1("NAND2_X1_2");
        NAND2_X1_2->A1(S11);
        NAND2_X1_2->A2(S21[3]);
        NAND2_X1_2->ZN(S13);

    INV_X1_3 = new INV_X1("INV_X1_3");
        INV_X1_3->A(S21[3]);
        INV_X1_3->ZN(S14);

    AND2_X1_2 = new AND2_X1("AND2_X1_2");
        AND2_X1_2->A1(S21[2]);
        AND2_X1_2->A2(S21[1]);
        AND2_X1_2->ZN(S15);

    NAND3_X1_1 = new NAND3_X1("NAND3_X1_1");
        NAND3_X1_1->A1(S8);
        NAND3_X1_1->A2(S15);
        NAND3_X1_1->A3(S14);
        NAND3_X1_1->ZN(S16);

    AOI21_X1_1 = new AOI21_X1("AOI21_X1_1");
        AOI21_X1_1->A(S24);
        AOI21_X1_1->B1(S16);
        AOI21_X1_1->B2(S13);
        AOI21_X1_1->ZN(S3);

    DFF_X1_1 = new DFF_X1("DFF_X1_1");
        DFF_X1_1->CK(S22);
        DFF_X1_1->D(S0);
        DFF_X1_1->Q(S21[0]);
        DFF_X1_1->QN(S17);

    DFF_X1_2 = new DFF_X1("DFF_X1_2");
        DFF_X1_2->CK(S22);
        DFF_X1_2->D(S1);
        DFF_X1_2->Q(S21[1]);
        DFF_X1_2->QN(S20);

    DFF_X1_3 = new DFF_X1("DFF_X1_3");
        DFF_X1_3->CK(S22);
        DFF_X1_3->D(S2);
        DFF_X1_3->Q(S21[2]);
        DFF_X1_3->QN(S19);

    DFF_X1_4 = new DFF_X1("DFF_X1_4");
        DFF_X1_4->CK(S22);
        DFF_X1_4->D(S3);
        DFF_X1_4->Q(S21[3]);
        DFF_X1_4->QN(S18);

    BUF_X1_1 = new BUF_X1("BUF_X1_1");
        BUF_X1_1->A(S21[0]);
        BUF_X1_1->Z(c[0]);

    BUF_X1_2 = new BUF_X1("BUF_X1_2");
        BUF_X1_2->A(S21[1]);
        BUF_X1_2->Z(c[1]);

    BUF_X1_3 = new BUF_X1("BUF_X1_3");
        BUF_X1_3->A(S21[2]);
        BUF_X1_3->Z(c[2]);

    BUF_X1_4 = new BUF_X1("BUF_X1_4");
        BUF_X1_4->A(S21[3]);
        BUF_X1_4->Z(c[3]);

    BUF_X1_5 = new BUF_X1("BUF_X1_5");
        BUF_X1_5->A(clk);
        BUF_X1_5->Z(S22);

    BUF_X1_6 = new BUF_X1("BUF_X1_6");
        BUF_X1_6->A(en);
        BUF_X1_6->Z(S23);

    BUF_X1_7 = new BUF_X1("BUF_X1_7");
        BUF_X1_7->A(rst);
        BUF_X1_7->Z(S24);


    SC_METHOD(sc_logic_signal_assignment);

    }

    void sc_logic_signal_assignment(void){ 
        sc_logic_1_signal.write(SC_LOGIC_1);
        sc_logic_0_signal.write(SC_LOGIC_0);
    }
};
#endif /* __COUNTER_3_H__ */

