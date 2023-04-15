#include <systemc.h>
#include "Complex_NAgate_45.h"

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

    notg* notg_1;
    notg* notg_2;
    notg* notg_3;
    notg* notg_4;
    notg* notg_5;
    nand_n* nand_n_1;
    nand_n* nand_n_2;
    nor_n* nor_n_1;
    nand_n* nand_n_3;
    nor_n* nor_n_2;
    notg* notg_6;
    nand_n* nand_n_4;
    nand_n* nand_n_5;
    nor_n* nor_n_3;
    nor_n* nor_n_4;
    nand_n* nand_n_6;
    nor_n* nor_n_5;
    nor_n* nor_n_6;
    nand_n* nand_n_7;
    notg* notg_7;
    nand_n* nand_n_8;
    nor_n* nor_n_7;
    nor_n* nor_n_8;
    nand_n* nand_n_9;
    notg* notg_8;
    nor_n* nor_n_9;
    nand_n* nand_n_10;
    nand_n* nand_n_11;
    nor_n* nor_n_10;
    dff* dff_1;
    dff* dff_2;
    dff* dff_3;
    dff* dff_4;
    bufg* bufg_1;
    bufg* bufg_2;
    bufg* bufg_3;
    bufg* bufg_4;
    bufg* bufg_5;
    bufg* bufg_6;
    bufg* bufg_7;
    bufg* bufg_8;
    bufg* bufg_9;

SC_CTOR( counter ) {
    notg_1 = new notg("notg_1");
        notg_1->A(S31[0]);
        notg_1->Y(S4);

    notg_2 = new notg("notg_2");
        notg_2->A(S31[3]);
        notg_2->Y(S5);

    notg_3 = new notg("notg_3");
        notg_3->A(S31[2]);
        notg_3->Y(S6);

    notg_4 = new notg("notg_4");
        notg_4->A(S31[1]);
        notg_4->Y(S7);

    notg_5 = new notg("notg_5");
        notg_5->A(S33);
        notg_5->Y(S8);

    nand_n_1 = new nand_n("nand_n_1");
        nand_n_1->A[0](S31[3]);
        nand_n_1->A[1](S4);
        nand_n_1->Y(S9);

    nand_n_2 = new nand_n("nand_n_2");
        nand_n_2->A[0](S31[1]);
        nand_n_2->A[1](S6);
        nand_n_2->Y(S10);

    nor_n_1 = new nor_n("nor_n_1");
        nor_n_1->A[0](S10);
        nor_n_1->A[1](S9);
        nor_n_1->Y(S30);

    nand_n_3 = new nand_n("nand_n_3");
        nand_n_3->A[0](S32);
        nand_n_3->A[1](S29);
        nand_n_3->Y(S11);

    nor_n_2 = new nor_n("nor_n_2");
        nor_n_2->A[0](S11);
        nor_n_2->A[1](S4);
        nor_n_2->Y(S12);

    notg_6 = new notg("notg_6");
        notg_6->A(S12);
        notg_6->Y(S13);

    nand_n_4 = new nand_n("nand_n_4");
        nand_n_4->A[0](S11);
        nand_n_4->A[1](S4);
        nand_n_4->Y(S14);

    nand_n_5 = new nand_n("nand_n_5");
        nand_n_5->A[0](S14);
        nand_n_5->A[1](S8);
        nand_n_5->Y(S15);

    nor_n_3 = new nor_n("nor_n_3");
        nor_n_3->A[0](S15);
        nor_n_3->A[1](S12);
        nor_n_3->Y(S0);

    nor_n_4 = new nor_n("nor_n_4");
        nor_n_4->A[0](S13);
        nor_n_4->A[1](S7);
        nor_n_4->Y(S16);

    nand_n_6 = new nand_n("nand_n_6");
        nand_n_6->A[0](S12);
        nand_n_6->A[1](S31[1]);
        nand_n_6->Y(S17);

    nor_n_5 = new nor_n("nor_n_5");
        nor_n_5->A[0](S12);
        nor_n_5->A[1](S31[1]);
        nor_n_5->Y(S18);

    nor_n_6 = new nor_n("nor_n_6");
        nor_n_6->A[0](S18);
        nor_n_6->A[1](S33);
        nor_n_6->Y(S19);

    nand_n_7 = new nand_n("nand_n_7");
        nand_n_7->A[0](S19);
        nand_n_7->A[1](S17);
        nand_n_7->Y(S20);

    notg_7 = new notg("notg_7");
        notg_7->A(S20);
        notg_7->Y(S1);

    nand_n_8 = new nand_n("nand_n_8");
        nand_n_8->A[0](S16);
        nand_n_8->A[1](S31[2]);
        nand_n_8->Y(S21);

    nor_n_7 = new nor_n("nor_n_7");
        nor_n_7->A[0](S16);
        nor_n_7->A[1](S31[2]);
        nor_n_7->Y(S22);

    nor_n_8 = new nor_n("nor_n_8");
        nor_n_8->A[0](S22);
        nor_n_8->A[1](S33);
        nor_n_8->Y(S23);

    nand_n_9 = new nand_n("nand_n_9");
        nand_n_9->A[0](S23);
        nand_n_9->A[1](S21);
        nand_n_9->Y(S24);

    notg_8 = new notg("notg_8");
        notg_8->A(S24);
        notg_8->Y(S2);

    nor_n_9 = new nor_n("nor_n_9");
        nor_n_9->A[0](S21);
        nor_n_9->A[1](S5);
        nor_n_9->Y(S25);

    nand_n_10 = new nand_n("nand_n_10");
        nand_n_10->A[0](S21);
        nand_n_10->A[1](S5);
        nand_n_10->Y(S26);

    nand_n_11 = new nand_n("nand_n_11");
        nand_n_11->A[0](S26);
        nand_n_11->A[1](S8);
        nand_n_11->Y(S27);

    nor_n_10 = new nor_n("nor_n_10");
        nor_n_10->A[0](S27);
        nor_n_10->A[1](S25);
        nor_n_10->Y(S3);

    dff_1 = new dff("dff_1");
        dff_1->C(S28);
        dff_1->CE(sc_logic_1_signal);
        dff_1->D(S0);
        dff_1->NbarT(sc_logic_0_signal);
        dff_1->PRE(sc_logic_0_signal);
        dff_1->Q(S31[0]);
        dff_1->R(sc_logic_0_signal);
        dff_1->Si(S34);
        dff_1->global_reset(sc_logic_0_signal);

    dff_2 = new dff("dff_2");
        dff_2->C(S28);
        dff_2->CE(sc_logic_1_signal);
        dff_2->D(S1);
        dff_2->NbarT(sc_logic_0_signal);
        dff_2->PRE(sc_logic_0_signal);
        dff_2->Q(S31[1]);
        dff_2->R(sc_logic_0_signal);
        dff_2->Si(S35);
        dff_2->global_reset(sc_logic_0_signal);

    dff_3 = new dff("dff_3");
        dff_3->C(S28);
        dff_3->CE(sc_logic_1_signal);
        dff_3->D(S2);
        dff_3->NbarT(sc_logic_0_signal);
        dff_3->PRE(sc_logic_0_signal);
        dff_3->Q(S31[2]);
        dff_3->R(sc_logic_0_signal);
        dff_3->Si(S36);
        dff_3->global_reset(sc_logic_0_signal);

    dff_4 = new dff("dff_4");
        dff_4->C(S28);
        dff_4->CE(sc_logic_1_signal);
        dff_4->D(S3);
        dff_4->NbarT(sc_logic_0_signal);
        dff_4->PRE(sc_logic_0_signal);
        dff_4->Q(S31[3]);
        dff_4->R(sc_logic_0_signal);
        dff_4->Si(S37);
        dff_4->global_reset(sc_logic_0_signal);

    bufg_1 = new bufg("bufg_1");
        bufg_1->A(clk);
        bufg_1->Y(S28);

    bufg_2 = new bufg("bufg_2");
        bufg_2->A(clkEn);
        bufg_2->Y(S29);

    bufg_3 = new bufg("bufg_3");
        bufg_3->A(S30);
        bufg_3->Y(co);

    bufg_4 = new bufg("bufg_4");
        bufg_4->A(S31[0]);
        bufg_4->Y(count[0]);

    bufg_5 = new bufg("bufg_5");
        bufg_5->A(S31[1]);
        bufg_5->Y(count[1]);

    bufg_6 = new bufg("bufg_6");
        bufg_6->A(S31[2]);
        bufg_6->Y(count[2]);

    bufg_7 = new bufg("bufg_7");
        bufg_7->A(S31[3]);
        bufg_7->Y(count[3]);

    bufg_8 = new bufg("bufg_8");
        bufg_8->A(en);
        bufg_8->Y(S32);

    bufg_9 = new bufg("bufg_9");
        bufg_9->A(rst);
        bufg_9->Y(S33);


    SC_METHOD(sc_logic_signal_assignment);

    }

    void sc_logic_signal_assignment(void){ 
        sc_logic_1_signal.write(SC_LOGIC_1);
        sc_logic_0_signal.write(SC_LOGIC_0);
    }
};
