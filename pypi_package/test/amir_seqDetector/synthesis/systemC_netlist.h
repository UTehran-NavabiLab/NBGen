#include <systemc.h>
#include "Complex_NAgate_45.h"

using namespace sc_core;

SC_MODULE( seqDetector ) {

    sc_in<sc_logic> clk;
    sc_in<sc_logic> rst;
    sc_in<sc_logic> serIn;
    sc_out<sc_logic> serOutValid;

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
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> ps_0 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("ps_0");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> ps_1 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("ps_1");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> ps_2 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("ps_2");

    notg* notg_1;
    notg* notg_2;
    nand_n* nand_n_1;
    notg* notg_3;
    nor_n* nor_n_1;
    notg* notg_4;
    nor_n* nor_n_2;
    nor_n* nor_n_3;
    nor_n* nor_n_4;
    notg* notg_5;
    nor_n* nor_n_5;
    nor_n* nor_n_6;
    nand_n* nand_n_2;
    nor_n* nor_n_7;
    nor_n* nor_n_8;
    dff* dff_1;
    dff* dff_2;
    dff* dff_3;
    dff* dff_4;
    BUFX2* BUFX2_1;
    BUFX2* BUFX2_2;
    BUFX2* BUFX2_3;
    BUFX2* BUFX2_4;

SC_CTOR( seqDetector ) {
    notg_1 = new notg("notg_1");
        notg_1->A(S16);
        notg_1->Y(S4);

    notg_2 = new notg("notg_2");
        notg_2->A(ps_1);
        notg_2->Y(S5);

    nand_n_1 = new nand_n("nand_n_1");
        nand_n_1->A[0](S17);
        nand_n_1->A[1](S4);
        nand_n_1->Y(S6);

    notg_3 = new notg("notg_3");
        notg_3->A(S6);
        notg_3->Y(S7);

    nor_n_1 = new nor_n("nor_n_1");
        nor_n_1->A[0](ps_1);
        nor_n_1->A[1](S16);
        nor_n_1->Y(S8);

    notg_4 = new notg("notg_4");
        notg_4->A(S8);
        notg_4->Y(S9);

    nor_n_2 = new nor_n("nor_n_2");
        nor_n_2->A[0](S9);
        nor_n_2->A[1](ps_0);
        nor_n_2->Y(S10);

    nor_n_3 = new nor_n("nor_n_3");
        nor_n_3->A[0](S10);
        nor_n_3->A[1](S7);
        nor_n_3->Y(S3);

    nor_n_4 = new nor_n("nor_n_4");
        nor_n_4->A[0](S18);
        nor_n_4->A[1](ps_2);
        nor_n_4->Y(S11);

    notg_5 = new notg("notg_5");
        notg_5->A(S11);
        notg_5->Y(S12);

    nor_n_5 = new nor_n("nor_n_5");
        nor_n_5->A[0](S12);
        nor_n_5->A[1](ps_0);
        nor_n_5->Y(S13);

    nor_n_6 = new nor_n("nor_n_6");
        nor_n_6->A[0](S13);
        nor_n_6->A[1](S6);
        nor_n_6->Y(S1);

    nand_n_2 = new nand_n("nand_n_2");
        nand_n_2->A[0](S12);
        nand_n_2->A[1](S4);
        nand_n_2->Y(S14);

    nor_n_7 = new nor_n("nor_n_7");
        nor_n_7->A[0](S14);
        nor_n_7->A[1](S17);
        nor_n_7->Y(S0);

    nor_n_8 = new nor_n("nor_n_8");
        nor_n_8->A[0](S6);
        nor_n_8->A[1](S5);
        nor_n_8->Y(S2);

    dff_1 = new dff("dff_1");
        dff_1->C(S15);
        dff_1->CE(sc_logic_1_signal);
        dff_1->D(S3);
        dff_1->NbarT(sc_logic_0_signal);
        dff_1->PRE(sc_logic_0_signal);
        dff_1->Q(ps_0);
        dff_1->R(sc_logic_0_signal);
        dff_1->Si(S19);
        dff_1->global_reset(sc_logic_0_signal);

    dff_2 = new dff("dff_2");
        dff_2->C(S15);
        dff_2->CE(sc_logic_1_signal);
        dff_2->D(S0);
        dff_2->NbarT(sc_logic_0_signal);
        dff_2->PRE(sc_logic_0_signal);
        dff_2->Q(ps_1);
        dff_2->R(sc_logic_0_signal);
        dff_2->Si(S20);
        dff_2->global_reset(sc_logic_0_signal);

    dff_3 = new dff("dff_3");
        dff_3->C(S15);
        dff_3->CE(sc_logic_1_signal);
        dff_3->D(S1);
        dff_3->NbarT(sc_logic_0_signal);
        dff_3->PRE(sc_logic_0_signal);
        dff_3->Q(ps_2);
        dff_3->R(sc_logic_0_signal);
        dff_3->Si(S21);
        dff_3->global_reset(sc_logic_0_signal);

    dff_4 = new dff("dff_4");
        dff_4->C(S15);
        dff_4->CE(sc_logic_1_signal);
        dff_4->D(S2);
        dff_4->NbarT(sc_logic_0_signal);
        dff_4->PRE(sc_logic_0_signal);
        dff_4->Q(S18);
        dff_4->R(sc_logic_0_signal);
        dff_4->Si(S22);
        dff_4->global_reset(sc_logic_0_signal);

    BUFX2_1 = new BUFX2("BUFX2_1");
        BUFX2_1->A(clk);
        BUFX2_1->Y(S15);

    BUFX2_2 = new BUFX2("BUFX2_2");
        BUFX2_2->A(rst);
        BUFX2_2->Y(S16);

    BUFX2_3 = new BUFX2("BUFX2_3");
        BUFX2_3->A(serIn);
        BUFX2_3->Y(S17);

    BUFX2_4 = new BUFX2("BUFX2_4");
        BUFX2_4->A(S18);
        BUFX2_4->Y(serOutValid);


    SC_METHOD(sc_logic_signal_assignment);

    }

    void sc_logic_signal_assignment(void){ 
        sc_logic_1_signal.write(SC_LOGIC_1);
        sc_logic_0_signal.write(SC_LOGIC_0);
    }
};
