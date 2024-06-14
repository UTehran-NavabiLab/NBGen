#include <systemc.h>
#include "Complex_NAgate_45.h"

#include "counter_3.h"


#ifndef __CAP_CONTROLLER_H__
#define __CAP_CONTROLLER_H__
using namespace sc_core;

SC_MODULE( cap_controller ) {

    sc_in<sc_logic> clk;
    sc_in<sc_logic> rst;
    sc_in<sc_logic> run;
    sc_in<sc_logic> count[4];
    sc_out<sc_logic> sel[4];
    sc_out<sc_logic> in_reg;
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
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S42[4];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S43 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S43");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S44 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S44");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S45 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S45");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S46 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S46");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S47[4];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> ps_2_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("ps_2_");

    INV_X1* INV_X1_1;
    AOI211_X1* AOI211_X1_1;
    NOR2_X1* NOR2_X1_1;
    INV_X1* INV_X1_2;
    INV_X1* INV_X1_3;
    OAI21_X1* OAI21_X1_1;
    NOR2_X1* NOR2_X1_2;
    NAND2_X1* NAND2_X1_1;
    NAND3_X1* NAND3_X1_1;
    INV_X1* INV_X1_4;
    INV_X1* INV_X1_5;
    NAND2_X1* NAND2_X1_2;
    INV_X1* INV_X1_6;
    NAND2_X1* NAND2_X1_3;
    NAND3_X1* NAND3_X1_2;
    AOI21_X1* AOI21_X1_1;
    OAI21_X1* OAI21_X1_2;
    OAI21_X1* OAI21_X1_3;
    NAND2_X1* NAND2_X1_4;
    NAND3_X1* NAND3_X1_3;
    NAND2_X1* NAND2_X1_5;
    NAND2_X1* NAND2_X1_6;
    NAND3_X1* NAND3_X1_4;
    OR2_X1* OR2_X1_1;
    INV_X1* INV_X1_7;
    NAND2_X1* NAND2_X1_7;
    OAI21_X1* OAI21_X1_4;
    NAND2_X1* NAND2_X1_8;
    AND4_X1* AND4_X1_1;
    INV_X1* INV_X1_8;
    NAND2_X1* NAND2_X1_9;
    INV_X1* INV_X1_9;
    OAI21_X1* OAI21_X1_5;
    NAND3_X1* NAND3_X1_5;
    NAND2_X1* NAND2_X1_10;
    NOR3_X1* NOR3_X1_1;
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
    BUF_X1* BUF_X1_10;
    BUF_X1* BUF_X1_11;
    BUF_X1* BUF_X1_12;
    BUF_X1* BUF_X1_13;
    BUF_X1* BUF_X1_14;
    counter_3* count_i;

SC_CTOR( cap_controller ) {
    INV_X1_1 = new INV_X1("INV_X1_1");
        INV_X1_1->A(S46);
        INV_X1_1->ZN(S3);

    AOI211_X1_1 = new AOI211_X1("AOI211_X1_1");
        AOI211_X1_1->A(S44);
        AOI211_X1_1->B(S43);
        AOI211_X1_1->C1(S3);
        AOI211_X1_1->C2(ps_2_);
        AOI211_X1_1->ZN(S4);

    NOR2_X1_1 = new NOR2_X1("NOR2_X1_1");
        NOR2_X1_1->A1(S4);
        NOR2_X1_1->A2(S45);
        NOR2_X1_1->ZN(S2);

    INV_X1_2 = new INV_X1("INV_X1_2");
        INV_X1_2->A(S47[3]);
        INV_X1_2->ZN(S5);

    INV_X1_3 = new INV_X1("INV_X1_3");
        INV_X1_3->A(S42[3]);
        INV_X1_3->ZN(S6);

    OAI21_X1_1 = new OAI21_X1("OAI21_X1_1");
        OAI21_X1_1->A(S6);
        OAI21_X1_1->B1(S42[1]);
        OAI21_X1_1->B2(S42[2]);
        OAI21_X1_1->ZN(S7);

    NOR2_X1_2 = new NOR2_X1("NOR2_X1_2");
        NOR2_X1_2->A1(S42[1]);
        NOR2_X1_2->A2(S42[2]);
        NOR2_X1_2->ZN(S8);

    NAND2_X1_1 = new NAND2_X1("NAND2_X1_1");
        NAND2_X1_1->A1(S8);
        NAND2_X1_1->A2(S42[3]);
        NAND2_X1_1->ZN(S9);

    NAND3_X1_1 = new NAND3_X1("NAND3_X1_1");
        NAND3_X1_1->A1(S9);
        NAND3_X1_1->A2(S5);
        NAND3_X1_1->A3(S7);
        NAND3_X1_1->ZN(S10);

    INV_X1_4 = new INV_X1("INV_X1_4");
        INV_X1_4->A(S47[2]);
        INV_X1_4->ZN(S11);

    INV_X1_5 = new INV_X1("INV_X1_5");
        INV_X1_5->A(S42[2]);
        INV_X1_5->ZN(S12);

    NAND2_X1_2 = new NAND2_X1("NAND2_X1_2");
        NAND2_X1_2->A1(S12);
        NAND2_X1_2->A2(S42[1]);
        NAND2_X1_2->ZN(S13);

    INV_X1_6 = new INV_X1("INV_X1_6");
        INV_X1_6->A(S42[1]);
        INV_X1_6->ZN(S14);

    NAND2_X1_3 = new NAND2_X1("NAND2_X1_3");
        NAND2_X1_3->A1(S14);
        NAND2_X1_3->A2(S42[2]);
        NAND2_X1_3->ZN(S15);

    NAND3_X1_2 = new NAND3_X1("NAND3_X1_2");
        NAND3_X1_2->A1(S13);
        NAND3_X1_2->A2(S15);
        NAND3_X1_2->A3(S11);
        NAND3_X1_2->ZN(S16);

    AOI21_X1_1 = new AOI21_X1("AOI21_X1_1");
        AOI21_X1_1->A(S5);
        AOI21_X1_1->B1(S9);
        AOI21_X1_1->B2(S7);
        AOI21_X1_1->ZN(S17);

    OAI21_X1_2 = new OAI21_X1("OAI21_X1_2");
        OAI21_X1_2->A(S10);
        OAI21_X1_2->B1(S17);
        OAI21_X1_2->B2(S16);
        OAI21_X1_2->ZN(S18);

    OAI21_X1_3 = new OAI21_X1("OAI21_X1_3");
        OAI21_X1_3->A(S42[3]);
        OAI21_X1_3->B1(S42[1]);
        OAI21_X1_3->B2(S42[2]);
        OAI21_X1_3->ZN(S19);

    NAND2_X1_4 = new NAND2_X1("NAND2_X1_4");
        NAND2_X1_4->A1(S8);
        NAND2_X1_4->A2(S6);
        NAND2_X1_4->ZN(S20);

    NAND3_X1_3 = new NAND3_X1("NAND3_X1_3");
        NAND3_X1_3->A1(S20);
        NAND3_X1_3->A2(S47[3]);
        NAND3_X1_3->A3(S19);
        NAND3_X1_3->ZN(S21);

    NAND2_X1_5 = new NAND2_X1("NAND2_X1_5");
        NAND2_X1_5->A1(S14);
        NAND2_X1_5->A2(S12);
        NAND2_X1_5->ZN(S22);

    NAND2_X1_6 = new NAND2_X1("NAND2_X1_6");
        NAND2_X1_6->A1(S42[1]);
        NAND2_X1_6->A2(S42[2]);
        NAND2_X1_6->ZN(S23);

    NAND3_X1_4 = new NAND3_X1("NAND3_X1_4");
        NAND3_X1_4->A1(S22);
        NAND3_X1_4->A2(S47[2]);
        NAND3_X1_4->A3(S23);
        NAND3_X1_4->ZN(S24);

    OR2_X1_1 = new OR2_X1("OR2_X1_1");
        OR2_X1_1->A1(S42[1]);
        OR2_X1_1->A2(S47[1]);
        OR2_X1_1->ZN(S25);

    INV_X1_7 = new INV_X1("INV_X1_7");
        INV_X1_7->A(S47[0]);
        INV_X1_7->ZN(S26);

    NAND2_X1_7 = new NAND2_X1("NAND2_X1_7");
        NAND2_X1_7->A1(S42[1]);
        NAND2_X1_7->A2(S47[1]);
        NAND2_X1_7->ZN(S27);

    OAI21_X1_4 = new OAI21_X1("OAI21_X1_4");
        OAI21_X1_4->A(S27);
        OAI21_X1_4->B1(S26);
        OAI21_X1_4->B2(S42[0]);
        OAI21_X1_4->ZN(S28);

    NAND2_X1_8 = new NAND2_X1("NAND2_X1_8");
        NAND2_X1_8->A1(S28);
        NAND2_X1_8->A2(S25);
        NAND2_X1_8->ZN(S29);

    AND4_X1_1 = new AND4_X1("AND4_X1_1");
        AND4_X1_1->A1(S21);
        AND4_X1_1->A2(S16);
        AND4_X1_1->A3(S29);
        AND4_X1_1->A4(S24);
        AND4_X1_1->ZN(S30);

    INV_X1_8 = new INV_X1("INV_X1_8");
        INV_X1_8->A(S45);
        INV_X1_8->ZN(S31);

    NAND2_X1_9 = new NAND2_X1("NAND2_X1_9");
        NAND2_X1_9->A1(S31);
        NAND2_X1_9->A2(S40);
        NAND2_X1_9->ZN(S32);

    INV_X1_9 = new INV_X1("INV_X1_9");
        INV_X1_9->A(S32);
        INV_X1_9->ZN(S33);

    OAI21_X1_5 = new OAI21_X1("OAI21_X1_5");
        OAI21_X1_5->A(S33);
        OAI21_X1_5->B1(S30);
        OAI21_X1_5->B2(S18);
        OAI21_X1_5->ZN(S34);

    NAND3_X1_5 = new NAND3_X1("NAND3_X1_5");
        NAND3_X1_5->A1(S31);
        NAND3_X1_5->A2(S46);
        NAND3_X1_5->A3(ps_2_);
        NAND3_X1_5->ZN(S35);

    NAND2_X1_10 = new NAND2_X1("NAND2_X1_10");
        NAND2_X1_10->A1(S34);
        NAND2_X1_10->A2(S35);
        NAND2_X1_10->ZN(S1);

    NOR3_X1_1 = new NOR3_X1("NOR3_X1_1");
        NOR3_X1_1->A1(S30);
        NOR3_X1_1->A2(S18);
        NOR3_X1_1->A3(S32);
        NOR3_X1_1->ZN(S0);

    DFF_X1_1 = new DFF_X1("DFF_X1_1");
        DFF_X1_1->CK(S41);
        DFF_X1_1->D(S45);
        DFF_X1_1->Q(S43);
        DFF_X1_1->QN(S37);

    DFF_X1_2 = new DFF_X1("DFF_X1_2");
        DFF_X1_2->CK(S41);
        DFF_X1_2->D(S1);
        DFF_X1_2->Q(S40);
        DFF_X1_2->QN(S38);

    DFF_X1_3 = new DFF_X1("DFF_X1_3");
        DFF_X1_3->CK(S41);
        DFF_X1_3->D(S2);
        DFF_X1_3->Q(ps_2_);
        DFF_X1_3->QN(S39);

    DFF_X1_4 = new DFF_X1("DFF_X1_4");
        DFF_X1_4->CK(S41);
        DFF_X1_4->D(S0);
        DFF_X1_4->Q(S44);
        DFF_X1_4->QN(S36);

    BUF_X1_1 = new BUF_X1("BUF_X1_1");
        BUF_X1_1->A(S40);
        BUF_X1_1->Z(add_reg);

    BUF_X1_2 = new BUF_X1("BUF_X1_2");
        BUF_X1_2->A(clk);
        BUF_X1_2->Z(S41);

    BUF_X1_3 = new BUF_X1("BUF_X1_3");
        BUF_X1_3->A(count[0]);
        BUF_X1_3->Z(S42[0]);

    BUF_X1_4 = new BUF_X1("BUF_X1_4");
        BUF_X1_4->A(count[1]);
        BUF_X1_4->Z(S42[1]);

    BUF_X1_5 = new BUF_X1("BUF_X1_5");
        BUF_X1_5->A(count[2]);
        BUF_X1_5->Z(S42[2]);

    BUF_X1_6 = new BUF_X1("BUF_X1_6");
        BUF_X1_6->A(count[3]);
        BUF_X1_6->Z(S42[3]);

    BUF_X1_7 = new BUF_X1("BUF_X1_7");
        BUF_X1_7->A(S43);
        BUF_X1_7->Z(in_reg);

    BUF_X1_8 = new BUF_X1("BUF_X1_8");
        BUF_X1_8->A(S44);
        BUF_X1_8->Z(out_reg);

    BUF_X1_9 = new BUF_X1("BUF_X1_9");
        BUF_X1_9->A(rst);
        BUF_X1_9->Z(S45);

    BUF_X1_10 = new BUF_X1("BUF_X1_10");
        BUF_X1_10->A(run);
        BUF_X1_10->Z(S46);

    BUF_X1_11 = new BUF_X1("BUF_X1_11");
        BUF_X1_11->A(S47[0]);
        BUF_X1_11->Z(sel[0]);

    BUF_X1_12 = new BUF_X1("BUF_X1_12");
        BUF_X1_12->A(S47[1]);
        BUF_X1_12->Z(sel[1]);

    BUF_X1_13 = new BUF_X1("BUF_X1_13");
        BUF_X1_13->A(S47[2]);
        BUF_X1_13->Z(sel[2]);

    BUF_X1_14 = new BUF_X1("BUF_X1_14");
        BUF_X1_14->A(S47[3]);
        BUF_X1_14->Z(sel[3]);

    count_i = new counter_3("count_i");
        count_i->c[0](S47[0]);
        count_i->c[1](S47[1]);
        count_i->c[2](S47[2]);
        count_i->c[3](S47[3]);
        count_i->clk(S41);
        count_i->en(S40);
        count_i->rst(S46);


    SC_METHOD(sc_logic_signal_assignment);

    }

    void sc_logic_signal_assignment(void){ 
        sc_logic_1_signal.write(SC_LOGIC_1);
        sc_logic_0_signal.write(SC_LOGIC_0);
    }
};
#endif /* __CAP_CONTROLLER_H__ */

