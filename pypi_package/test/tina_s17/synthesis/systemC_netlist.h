#include <systemc.h>
#include "Complex_NAgate_45.h"

using namespace sc_core;

SC_MODULE( sequence ) {

    sc_in<sc_logic> clk;
    sc_in<sc_logic> rst;
    sc_in<sc_logic> x;
    sc_out<sc_logic> out;

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
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> ns_0 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("ns_0");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> ns_1 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("ns_1");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> ps_0 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("ps_0");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> ps_1 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("ps_1");

    notg* notg_1;
    notg* notg_2;
    nand_n* nand_n_1;
    notg* notg_3;
    nor_n* nor_n_1;
    nand_n* nand_n_2;
    nand_n* nand_n_3;
    nand_n* nand_n_4;
    bufg* bufg_1;
    dff* dff_1;
    dff* dff_2;
    bufg* bufg_2;
    bufg* bufg_3;
    bufg* bufg_4;
    bufg* bufg_5;

SC_CTOR( sequence ) {
    notg_1 = new notg("notg_1");
        notg_1->A(ps_1);
        notg_1->Y(S3);

    notg_2 = new notg("notg_2");
        notg_2->A(S9);
        notg_2->Y(S4);

    nand_n_1 = new nand_n("nand_n_1");
        nand_n_1->A[0](ps_0);
        nand_n_1->A[1](ps_1);
        nand_n_1->Y(S5);

    notg_3 = new notg("notg_3");
        notg_3->A(S5);
        notg_3->Y(S7);

    nor_n_1 = new nor_n("nor_n_1");
        nor_n_1->A[0](ps_0);
        nor_n_1->A[1](S3);
        nor_n_1->Y(S0);

    nand_n_2 = new nand_n("nand_n_2");
        nand_n_2->A[0](S0);
        nand_n_2->A[1](S9);
        nand_n_2->Y(S1);

    nand_n_3 = new nand_n("nand_n_3");
        nand_n_3->A[0](S4);
        nand_n_3->A[1](ps_0);
        nand_n_3->Y(S2);

    nand_n_4 = new nand_n("nand_n_4");
        nand_n_4->A[0](S2);
        nand_n_4->A[1](S1);
        nand_n_4->Y(ns_1);

    bufg_1 = new bufg("bufg_1");
        bufg_1->A(S9);
        bufg_1->Y(ns_0);

    dff_1 = new dff("dff_1");
        dff_1->C(S6);
        dff_1->CE(sc_logic_1_signal);
        dff_1->D(ns_0);
        dff_1->NbarT(sc_logic_0_signal);
        dff_1->PRE(sc_logic_0_signal);
        dff_1->Q(ps_0);
        dff_1->R(S8);
        dff_1->Si(S10);
        dff_1->global_reset(sc_logic_0_signal);

    dff_2 = new dff("dff_2");
        dff_2->C(S6);
        dff_2->CE(sc_logic_1_signal);
        dff_2->D(ns_1);
        dff_2->NbarT(sc_logic_0_signal);
        dff_2->PRE(sc_logic_0_signal);
        dff_2->Q(ps_1);
        dff_2->R(S8);
        dff_2->Si(S11);
        dff_2->global_reset(sc_logic_0_signal);

    bufg_2 = new bufg("bufg_2");
        bufg_2->A(clk);
        bufg_2->Y(S6);

    bufg_3 = new bufg("bufg_3");
        bufg_3->A(S7);
        bufg_3->Y(out);

    bufg_4 = new bufg("bufg_4");
        bufg_4->A(rst);
        bufg_4->Y(S8);

    bufg_5 = new bufg("bufg_5");
        bufg_5->A(x);
        bufg_5->Y(S9);


    SC_METHOD(sc_logic_signal_assignment);

    }

    void sc_logic_signal_assignment(void){ 
        sc_logic_1_signal.write(SC_LOGIC_1);
        sc_logic_0_signal.write(SC_LOGIC_0);
    }
};
