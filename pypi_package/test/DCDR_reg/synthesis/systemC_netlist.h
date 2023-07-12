#include <systemc.h>
#include "Complex_NAgate_45.h"

using namespace sc_core;

SC_MODULE( register ) {

    sc_in<sc_logic> clk;
    sc_in<sc_logic> rst;
    sc_in<sc_logic> A[4];
    sc_in<sc_logic> B[4];
    sc_in<sc_logic> C[4];
    sc_out<sc_logic> Q1[4];
    sc_out<sc_logic> Q2[4];
    sc_out<sc_logic> Q3[4];

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
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> CK = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("CK");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> R = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("R");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> cnt_0 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("cnt_0");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> cnt_1 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("cnt_1");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> cnt_2 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("cnt_2");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> cnt_3 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("cnt_3");

    notg* notg_1;
    notg* notg_2;
    notg* notg_3;
    notg* notg_4;
    notg* notg_5;
    nor_n* nor_n_1;
    nand_n* nand_n_1;
    nor_n* nor_n_2;
    nor_n* nor_n_3;
    nor_n* nor_n_4;
    nand_n* nand_n_2;
    nor_n* nor_n_5;
    nor_n* nor_n_6;
    nor_n* nor_n_7;
    nor_n* nor_n_8;
    nor_n* nor_n_9;
    dff* dff_1;
    dff* dff_2;
    dff* dff_3;
    dff* dff_4;
    dff* dff_5;
    dff* dff_6;
    dff* dff_7;
    dff* dff_8;
    dff* dff_9;
    dff* dff_10;
    dff* dff_11;
    dff* dff_12;
    dff* dff_13;
    dff* dff_14;
    dff* dff_15;
    dff* dff_16;
    dff* dff_17;
    BUFX2* BUFX2_1;
    BUFX2* BUFX2_2;
    BUFX2* BUFX2_3;
    BUFX2* BUFX2_4;
    BUFX2* BUFX2_5;
    BUFX2* BUFX2_6;
    BUFX2* BUFX2_7;
    BUFX2* BUFX2_8;
    BUFX2* BUFX2_9;
    BUFX2* BUFX2_10;
    BUFX2* BUFX2_11;
    BUFX2* BUFX2_12;
    BUFX2* BUFX2_13;
    BUFX2* BUFX2_14;
    BUFX2* BUFX2_15;
    BUFX2* BUFX2_16;
    BUFX2* BUFX2_17;
    BUFX2* BUFX2_18;
    BUFX2* BUFX2_19;
    BUFX2* BUFX2_20;
    BUFX2* BUFX2_21;
    BUFX2* BUFX2_22;
    BUFX2* BUFX2_23;
    BUFX2* BUFX2_24;
    BUFX2* BUFX2_25;
    BUFX2* BUFX2_26;

SC_CTOR( register ) {
    notg_1 = new notg("notg_1");
        notg_1->A(cnt_0);
        notg_1->Y(S11);

    notg_2 = new notg("notg_2");
        notg_2->A(CK);
        notg_2->Y(S0);

    notg_3 = new notg("notg_3");
        notg_3->A(cnt_1);
        notg_3->Y(S1);

    notg_4 = new notg("notg_4");
        notg_4->A(cnt_2);
        notg_4->Y(S2);

    notg_5 = new notg("notg_5");
        notg_5->A(cnt_3);
        notg_5->Y(S3);

    nor_n_1 = new nor_n("nor_n_1");
        nor_n_1->A[0](S1);
        nor_n_1->A[1](S11);
        nor_n_1->Y(S4);

    nand_n_1 = new nand_n("nand_n_1");
        nand_n_1->A[0](cnt_1);
        nand_n_1->A[1](cnt_0);
        nand_n_1->Y(S5);

    nor_n_2 = new nor_n("nor_n_2");
        nor_n_2->A[0](cnt_1);
        nor_n_2->A[1](cnt_0);
        nor_n_2->Y(S6);

    nor_n_3 = new nor_n("nor_n_3");
        nor_n_3->A[0](S6);
        nor_n_3->A[1](S4);
        nor_n_3->Y(S12);

    nor_n_4 = new nor_n("nor_n_4");
        nor_n_4->A[0](S5);
        nor_n_4->A[1](S2);
        nor_n_4->Y(S7);

    nand_n_2 = new nand_n("nand_n_2");
        nand_n_2->A[0](S4);
        nand_n_2->A[1](cnt_2);
        nand_n_2->Y(S8);

    nor_n_5 = new nor_n("nor_n_5");
        nor_n_5->A[0](S4);
        nor_n_5->A[1](cnt_2);
        nor_n_5->Y(S9);

    nor_n_6 = new nor_n("nor_n_6");
        nor_n_6->A[0](S9);
        nor_n_6->A[1](S7);
        nor_n_6->Y(S13);

    nor_n_7 = new nor_n("nor_n_7");
        nor_n_7->A[0](S8);
        nor_n_7->A[1](S3);
        nor_n_7->Y(R);

    nor_n_8 = new nor_n("nor_n_8");
        nor_n_8->A[0](S7);
        nor_n_8->A[1](cnt_3);
        nor_n_8->Y(S10);

    nor_n_9 = new nor_n("nor_n_9");
        nor_n_9->A[0](S10);
        nor_n_9->A[1](R);
        nor_n_9->Y(S14);

    dff_1 = new dff("dff_1");
        dff_1->C(CK);
        dff_1->CE(sc_logic_1_signal);
        dff_1->D(S17[0]);
        dff_1->NbarT(sc_logic_0_signal);
        dff_1->PRE(sc_logic_0_signal);
        dff_1->Q(S20[0]);
        dff_1->R(R);
        dff_1->Si(S25);
        dff_1->global_reset(sc_logic_0_signal);

    dff_2 = new dff("dff_2");
        dff_2->C(CK);
        dff_2->CE(sc_logic_1_signal);
        dff_2->D(S17[1]);
        dff_2->NbarT(sc_logic_0_signal);
        dff_2->PRE(sc_logic_0_signal);
        dff_2->Q(S20[1]);
        dff_2->R(R);
        dff_2->Si(S30);
        dff_2->global_reset(sc_logic_0_signal);

    dff_3 = new dff("dff_3");
        dff_3->C(CK);
        dff_3->CE(sc_logic_1_signal);
        dff_3->D(S17[2]);
        dff_3->NbarT(sc_logic_0_signal);
        dff_3->PRE(sc_logic_0_signal);
        dff_3->Q(S20[2]);
        dff_3->R(R);
        dff_3->Si(S29);
        dff_3->global_reset(sc_logic_0_signal);

    dff_4 = new dff("dff_4");
        dff_4->C(CK);
        dff_4->CE(sc_logic_1_signal);
        dff_4->D(S17[3]);
        dff_4->NbarT(sc_logic_0_signal);
        dff_4->PRE(sc_logic_0_signal);
        dff_4->Q(S20[3]);
        dff_4->R(R);
        dff_4->Si(S24);
        dff_4->global_reset(sc_logic_0_signal);

    dff_5 = new dff("dff_5");
        dff_5->C(S21);
        dff_5->CE(sc_logic_1_signal);
        dff_5->D(S16[0]);
        dff_5->NbarT(sc_logic_0_signal);
        dff_5->PRE(sc_logic_0_signal);
        dff_5->Q(S19[0]);
        dff_5->R(R);
        dff_5->Si(S26);
        dff_5->global_reset(sc_logic_0_signal);

    dff_6 = new dff("dff_6");
        dff_6->C(S21);
        dff_6->CE(sc_logic_1_signal);
        dff_6->D(S16[1]);
        dff_6->NbarT(sc_logic_0_signal);
        dff_6->PRE(sc_logic_0_signal);
        dff_6->Q(S19[1]);
        dff_6->R(R);
        dff_6->Si(S31);
        dff_6->global_reset(sc_logic_0_signal);

    dff_7 = new dff("dff_7");
        dff_7->C(S21);
        dff_7->CE(sc_logic_1_signal);
        dff_7->D(S16[2]);
        dff_7->NbarT(sc_logic_0_signal);
        dff_7->PRE(sc_logic_0_signal);
        dff_7->Q(S19[2]);
        dff_7->R(R);
        dff_7->Si(S32);
        dff_7->global_reset(sc_logic_0_signal);

    dff_8 = new dff("dff_8");
        dff_8->C(S21);
        dff_8->CE(sc_logic_1_signal);
        dff_8->D(S16[3]);
        dff_8->NbarT(sc_logic_0_signal);
        dff_8->PRE(sc_logic_0_signal);
        dff_8->Q(S19[3]);
        dff_8->R(R);
        dff_8->Si(S33);
        dff_8->global_reset(sc_logic_0_signal);

    dff_9 = new dff("dff_9");
        dff_9->C(S21);
        dff_9->CE(sc_logic_1_signal);
        dff_9->D(S11);
        dff_9->NbarT(sc_logic_0_signal);
        dff_9->PRE(sc_logic_0_signal);
        dff_9->Q(cnt_0);
        dff_9->R(S22);
        dff_9->Si(S27);
        dff_9->global_reset(sc_logic_0_signal);

    dff_10 = new dff("dff_10");
        dff_10->C(S21);
        dff_10->CE(sc_logic_1_signal);
        dff_10->D(S12);
        dff_10->NbarT(sc_logic_0_signal);
        dff_10->PRE(sc_logic_0_signal);
        dff_10->Q(cnt_1);
        dff_10->R(S22);
        dff_10->Si(S34);
        dff_10->global_reset(sc_logic_0_signal);

    dff_11 = new dff("dff_11");
        dff_11->C(S21);
        dff_11->CE(sc_logic_1_signal);
        dff_11->D(S13);
        dff_11->NbarT(sc_logic_0_signal);
        dff_11->PRE(sc_logic_0_signal);
        dff_11->Q(cnt_2);
        dff_11->R(S22);
        dff_11->Si(S35);
        dff_11->global_reset(sc_logic_0_signal);

    dff_12 = new dff("dff_12");
        dff_12->C(S21);
        dff_12->CE(sc_logic_1_signal);
        dff_12->D(S14);
        dff_12->NbarT(sc_logic_0_signal);
        dff_12->PRE(sc_logic_0_signal);
        dff_12->Q(cnt_3);
        dff_12->R(S22);
        dff_12->Si(S36);
        dff_12->global_reset(sc_logic_0_signal);

    dff_13 = new dff("dff_13");
        dff_13->C(CK);
        dff_13->CE(sc_logic_1_signal);
        dff_13->D(S15[0]);
        dff_13->NbarT(sc_logic_0_signal);
        dff_13->PRE(sc_logic_0_signal);
        dff_13->Q(S18[0]);
        dff_13->R(S22);
        dff_13->Si(S28);
        dff_13->global_reset(sc_logic_0_signal);

    dff_14 = new dff("dff_14");
        dff_14->C(CK);
        dff_14->CE(sc_logic_1_signal);
        dff_14->D(S15[1]);
        dff_14->NbarT(sc_logic_0_signal);
        dff_14->PRE(sc_logic_0_signal);
        dff_14->Q(S18[1]);
        dff_14->R(S22);
        dff_14->Si(S37);
        dff_14->global_reset(sc_logic_0_signal);

    dff_15 = new dff("dff_15");
        dff_15->C(CK);
        dff_15->CE(sc_logic_1_signal);
        dff_15->D(S15[2]);
        dff_15->NbarT(sc_logic_0_signal);
        dff_15->PRE(sc_logic_0_signal);
        dff_15->Q(S18[2]);
        dff_15->R(S22);
        dff_15->Si(S38);
        dff_15->global_reset(sc_logic_0_signal);

    dff_16 = new dff("dff_16");
        dff_16->C(CK);
        dff_16->CE(sc_logic_1_signal);
        dff_16->D(S15[3]);
        dff_16->NbarT(sc_logic_0_signal);
        dff_16->PRE(sc_logic_0_signal);
        dff_16->Q(S18[3]);
        dff_16->R(S22);
        dff_16->Si(S39);
        dff_16->global_reset(sc_logic_0_signal);

    dff_17 = new dff("dff_17");
        dff_17->C(S21);
        dff_17->CE(sc_logic_1_signal);
        dff_17->D(S0);
        dff_17->NbarT(sc_logic_0_signal);
        dff_17->PRE(sc_logic_0_signal);
        dff_17->Q(CK);
        dff_17->R(S22);
        dff_17->Si(S23);
        dff_17->global_reset(sc_logic_0_signal);

    BUFX2_1 = new BUFX2("BUFX2_1");
        BUFX2_1->A(A[0]);
        BUFX2_1->Y(S15[0]);

    BUFX2_2 = new BUFX2("BUFX2_2");
        BUFX2_2->A(A[1]);
        BUFX2_2->Y(S15[1]);

    BUFX2_3 = new BUFX2("BUFX2_3");
        BUFX2_3->A(A[2]);
        BUFX2_3->Y(S15[2]);

    BUFX2_4 = new BUFX2("BUFX2_4");
        BUFX2_4->A(A[3]);
        BUFX2_4->Y(S15[3]);

    BUFX2_5 = new BUFX2("BUFX2_5");
        BUFX2_5->A(B[0]);
        BUFX2_5->Y(S16[0]);

    BUFX2_6 = new BUFX2("BUFX2_6");
        BUFX2_6->A(B[1]);
        BUFX2_6->Y(S16[1]);

    BUFX2_7 = new BUFX2("BUFX2_7");
        BUFX2_7->A(B[2]);
        BUFX2_7->Y(S16[2]);

    BUFX2_8 = new BUFX2("BUFX2_8");
        BUFX2_8->A(B[3]);
        BUFX2_8->Y(S16[3]);

    BUFX2_9 = new BUFX2("BUFX2_9");
        BUFX2_9->A(C[0]);
        BUFX2_9->Y(S17[0]);

    BUFX2_10 = new BUFX2("BUFX2_10");
        BUFX2_10->A(C[1]);
        BUFX2_10->Y(S17[1]);

    BUFX2_11 = new BUFX2("BUFX2_11");
        BUFX2_11->A(C[2]);
        BUFX2_11->Y(S17[2]);

    BUFX2_12 = new BUFX2("BUFX2_12");
        BUFX2_12->A(C[3]);
        BUFX2_12->Y(S17[3]);

    BUFX2_13 = new BUFX2("BUFX2_13");
        BUFX2_13->A(S18[0]);
        BUFX2_13->Y(Q1[0]);

    BUFX2_14 = new BUFX2("BUFX2_14");
        BUFX2_14->A(S18[1]);
        BUFX2_14->Y(Q1[1]);

    BUFX2_15 = new BUFX2("BUFX2_15");
        BUFX2_15->A(S18[2]);
        BUFX2_15->Y(Q1[2]);

    BUFX2_16 = new BUFX2("BUFX2_16");
        BUFX2_16->A(S18[3]);
        BUFX2_16->Y(Q1[3]);

    BUFX2_17 = new BUFX2("BUFX2_17");
        BUFX2_17->A(S19[0]);
        BUFX2_17->Y(Q2[0]);

    BUFX2_18 = new BUFX2("BUFX2_18");
        BUFX2_18->A(S19[1]);
        BUFX2_18->Y(Q2[1]);

    BUFX2_19 = new BUFX2("BUFX2_19");
        BUFX2_19->A(S19[2]);
        BUFX2_19->Y(Q2[2]);

    BUFX2_20 = new BUFX2("BUFX2_20");
        BUFX2_20->A(S19[3]);
        BUFX2_20->Y(Q2[3]);

    BUFX2_21 = new BUFX2("BUFX2_21");
        BUFX2_21->A(S20[0]);
        BUFX2_21->Y(Q3[0]);

    BUFX2_22 = new BUFX2("BUFX2_22");
        BUFX2_22->A(S20[1]);
        BUFX2_22->Y(Q3[1]);

    BUFX2_23 = new BUFX2("BUFX2_23");
        BUFX2_23->A(S20[2]);
        BUFX2_23->Y(Q3[2]);

    BUFX2_24 = new BUFX2("BUFX2_24");
        BUFX2_24->A(S20[3]);
        BUFX2_24->Y(Q3[3]);

    BUFX2_25 = new BUFX2("BUFX2_25");
        BUFX2_25->A(clk);
        BUFX2_25->Y(S21);

    BUFX2_26 = new BUFX2("BUFX2_26");
        BUFX2_26->A(rst);
        BUFX2_26->Y(S22);


    SC_METHOD(sc_logic_signal_assignment);

    }

    void sc_logic_signal_assignment(void){ 
        sc_logic_1_signal.write(SC_LOGIC_1);
        sc_logic_0_signal.write(SC_LOGIC_0);
    }
};
