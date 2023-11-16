#include <systemc.h>
#include "Complex_NAgate_45.h"



#ifndef __COUNTER_H__
#define __COUNTER_H__
using namespace sc_core;

SC_MODULE( counter ) {

    sc_in<sc_logic> clk;
    sc_in<sc_logic> rst;
    sc_in<sc_logic> en;
    sc_in<sc_logic> clkEn;
    sc_out<sc_logic> count[4];
    sc_out<sc_logic> co;

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
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S27[4];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S28 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S28");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S29 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S29");

    INV_X1* INV_X1_1;
    AND4_X1* AND4_X1_1;
    INV_X1* INV_X1_2;
    NAND2_X1* NAND2_X1_1;
    INV_X1* INV_X1_3;
    OAI21_X1* OAI21_X1_1;
    AOI21_X1* AOI21_X1_1;
    INV_X1* INV_X1_4;
    NAND3_X1* NAND3_X1_1;
    NAND4_X1* NAND4_X1_1;
    NAND2_X1* NAND2_X1_2;
    AOI21_X1* AOI21_X1_2;
    NAND2_X1* NAND2_X1_3;
    OAI21_X1* OAI21_X1_2;
    AOI21_X1* AOI21_X1_3;
    OAI21_X1* OAI21_X1_3;
    INV_X1* INV_X1_5;
    AND3_X1* AND3_X1_1;
    AND2_X1* AND2_X1_1;
    NAND3_X1* NAND3_X1_2;
    AOI21_X1* AOI21_X1_4;
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
    BUF_X1* BUF_X1_8;
    BUF_X1* BUF_X1_9;

SC_CTOR( counter ) {
    INV_X1_1 = new INV_X1("INV_X1_1");
        INV_X1_1->A(S27[2]);
        INV_X1_1->ZN(S4);

    AND4_X1_1 = new AND4_X1("AND4_X1_1");
        AND4_X1_1->A1(S4);
        AND4_X1_1->A2(S27[3]);
        AND4_X1_1->A3(S27[1]);
        AND4_X1_1->A4(S20);
        AND4_X1_1->ZN(S26);

    INV_X1_2 = new INV_X1("INV_X1_2");
        INV_X1_2->A(S27[0]);
        INV_X1_2->ZN(S5);

    NAND2_X1_1 = new NAND2_X1("NAND2_X1_1");
        NAND2_X1_1->A1(S25);
        NAND2_X1_1->A2(S28);
        NAND2_X1_1->ZN(S6);

    INV_X1_3 = new INV_X1("INV_X1_3");
        INV_X1_3->A(S29);
        INV_X1_3->ZN(S7);

    OAI21_X1_1 = new OAI21_X1("OAI21_X1_1");
        OAI21_X1_1->A(S7);
        OAI21_X1_1->B1(S6);
        OAI21_X1_1->B2(S20);
        OAI21_X1_1->ZN(S8);

    AOI21_X1_1 = new AOI21_X1("AOI21_X1_1");
        AOI21_X1_1->A(S8);
        AOI21_X1_1->B1(S6);
        AOI21_X1_1->B2(S5);
        AOI21_X1_1->ZN(S0);

    INV_X1_4 = new INV_X1("INV_X1_4");
        INV_X1_4->A(S27[1]);
        INV_X1_4->ZN(S9);

    NAND3_X1_1 = new NAND3_X1("NAND3_X1_1");
        NAND3_X1_1->A1(S25);
        NAND3_X1_1->A2(S28);
        NAND3_X1_1->A3(S27[0]);
        NAND3_X1_1->ZN(S10);

    NAND4_X1_1 = new NAND4_X1("NAND4_X1_1");
        NAND4_X1_1->A1(S27[1]);
        NAND4_X1_1->A2(S27[0]);
        NAND4_X1_1->A3(S25);
        NAND4_X1_1->A4(S28);
        NAND4_X1_1->ZN(S11);

    NAND2_X1_2 = new NAND2_X1("NAND2_X1_2");
        NAND2_X1_2->A1(S11);
        NAND2_X1_2->A2(S7);
        NAND2_X1_2->ZN(S12);

    AOI21_X1_2 = new AOI21_X1("AOI21_X1_2");
        AOI21_X1_2->A(S12);
        AOI21_X1_2->B1(S10);
        AOI21_X1_2->B2(S9);
        AOI21_X1_2->ZN(S1);

    NAND2_X1_3 = new NAND2_X1("NAND2_X1_3");
        NAND2_X1_3->A1(S27[2]);
        NAND2_X1_3->A2(S27[1]);
        NAND2_X1_3->ZN(S13);

    OAI21_X1_2 = new OAI21_X1("OAI21_X1_2");
        OAI21_X1_2->A(S7);
        OAI21_X1_2->B1(S10);
        OAI21_X1_2->B2(S13);
        OAI21_X1_2->ZN(S14);

    AOI21_X1_3 = new AOI21_X1("AOI21_X1_3");
        AOI21_X1_3->A(S14);
        AOI21_X1_3->B1(S11);
        AOI21_X1_3->B2(S4);
        AOI21_X1_3->ZN(S2);

    OAI21_X1_3 = new OAI21_X1("OAI21_X1_3");
        OAI21_X1_3->A(S27[3]);
        OAI21_X1_3->B1(S10);
        OAI21_X1_3->B2(S13);
        OAI21_X1_3->ZN(S15);

    INV_X1_5 = new INV_X1("INV_X1_5");
        INV_X1_5->A(S27[3]);
        INV_X1_5->ZN(S16);

    AND3_X1_1 = new AND3_X1("AND3_X1_1");
        AND3_X1_1->A1(S27[0]);
        AND3_X1_1->A2(S28);
        AND3_X1_1->A3(S25);
        AND3_X1_1->ZN(S17);

    AND2_X1_1 = new AND2_X1("AND2_X1_1");
        AND2_X1_1->A1(S27[1]);
        AND2_X1_1->A2(S27[2]);
        AND2_X1_1->ZN(S18);

    NAND3_X1_2 = new NAND3_X1("NAND3_X1_2");
        NAND3_X1_2->A1(S17);
        NAND3_X1_2->A2(S16);
        NAND3_X1_2->A3(S18);
        NAND3_X1_2->ZN(S19);

    AOI21_X1_4 = new AOI21_X1("AOI21_X1_4");
        AOI21_X1_4->A(S29);
        AOI21_X1_4->B1(S19);
        AOI21_X1_4->B2(S15);
        AOI21_X1_4->ZN(S3);

    DFF_X1_1 = new DFF_X1("DFF_X1_1");
        DFF_X1_1->CK(S24);
        DFF_X1_1->D(S0);
        DFF_X1_1->Q(S27[0]);
        DFF_X1_1->QN(S20);

    DFF_X1_2 = new DFF_X1("DFF_X1_2");
        DFF_X1_2->CK(S24);
        DFF_X1_2->D(S1);
        DFF_X1_2->Q(S27[1]);
        DFF_X1_2->QN(S23);

    DFF_X1_3 = new DFF_X1("DFF_X1_3");
        DFF_X1_3->CK(S24);
        DFF_X1_3->D(S2);
        DFF_X1_3->Q(S27[2]);
        DFF_X1_3->QN(S22);

    DFF_X1_4 = new DFF_X1("DFF_X1_4");
        DFF_X1_4->CK(S24);
        DFF_X1_4->D(S3);
        DFF_X1_4->Q(S27[3]);
        DFF_X1_4->QN(S21);

    BUF_X1_1 = new BUF_X1("BUF_X1_1");
        BUF_X1_1->A(clk);
        BUF_X1_1->Z(S24);

    BUF_X1_2 = new BUF_X1("BUF_X1_2");
        BUF_X1_2->A(clkEn);
        BUF_X1_2->Z(S25);

    BUF_X1_3 = new BUF_X1("BUF_X1_3");
        BUF_X1_3->A(S26);
        BUF_X1_3->Z(co);

    BUF_X1_4 = new BUF_X1("BUF_X1_4");
        BUF_X1_4->A(S27[0]);
        BUF_X1_4->Z(count[0]);

    BUF_X1_5 = new BUF_X1("BUF_X1_5");
        BUF_X1_5->A(S27[1]);
        BUF_X1_5->Z(count[1]);

    BUF_X1_6 = new BUF_X1("BUF_X1_6");
        BUF_X1_6->A(S27[2]);
        BUF_X1_6->Z(count[2]);

    BUF_X1_7 = new BUF_X1("BUF_X1_7");
        BUF_X1_7->A(S27[3]);
        BUF_X1_7->Z(count[3]);

    BUF_X1_8 = new BUF_X1("BUF_X1_8");
        BUF_X1_8->A(en);
        BUF_X1_8->Z(S28);

    BUF_X1_9 = new BUF_X1("BUF_X1_9");
        BUF_X1_9->A(rst);
        BUF_X1_9->Z(S29);


    SC_METHOD(sc_logic_signal_assignment);

    }

    void sc_logic_signal_assignment(void){ 
        sc_logic_1_signal.write(SC_LOGIC_1);
        sc_logic_0_signal.write(SC_LOGIC_0);
    }
};
#endif /* __COUNTER_H__ */

