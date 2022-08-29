#include <systemc.h>
#include "component_library.h"

using namespace sc_core;

SC_MODULE( fulladder ) {

    sc_in<sc_logic> i0;
    sc_in<sc_logic> i1;
    sc_in<sc_logic> ci;
    sc_out<sc_logic> s;
    sc_out<sc_logic> co;

    sc_signal<sc_logic> sc_logic_1_signal;
    sc_signal<sc_logic> sc_logic_0_signal;

    sc_signal<sc_logic> S0;
    sc_signal<sc_logic> S1;
    sc_signal<sc_logic> S2;
    sc_signal<sc_logic> S3;
    sc_signal<sc_logic> S4;
    sc_signal<sc_logic> S5;
    sc_signal<sc_logic> S6;
    sc_signal<sc_logic> S7;
    sc_signal<sc_logic> S8;
    sc_signal<sc_logic> S9;
    sc_signal<sc_logic> S10;
    sc_signal<sc_logic> S11;
    sc_signal<sc_logic> S12;
    sc_signal<sc_logic> S13;
    sc_signal<sc_logic> S14;
    sc_signal<sc_logic> S15;
    sc_signal<sc_logic> S16;

    nor_n* nor_n_0;
    nand_n* nand_n_1;
    nand_n* nand_n_2;
    notg* notg_3;
    nor_n* nor_n_4;
    nand_n* nand_n_5;
    nand_n* nand_n_6;
    nand_n* nand_n_7;
    nand_n* nand_n_8;
    nand_n* nand_n_9;
    nand_n* nand_n_10;
    notg* notg_11;
    notg* notg_12;
    notg* notg_13;
    bufg* bufg_14;
    bufg* bufg_15;
    bufg* bufg_16;
    bufg* bufg_17;
    bufg* bufg_18;

SC_CTOR( fulladder ) {
    nor_n_0 = new nor_n("nor_n_0");
        nor_n_0->in1[0](S12);
        nor_n_0->in1[1](S15);
        nor_n_0->out1(S11);

    nand_n_1 = new nand_n("nand_n_1");
        nand_n_1->in1[0](S10);
        nand_n_1->in1[1](S8);
        nand_n_1->out1(S0);

    nand_n_2 = new nand_n("nand_n_2");
        nand_n_2->in1[0](S12);
        nand_n_2->in1[1](S15);
        nand_n_2->out1(S1);

    notg_3 = new notg("notg_3");
        notg_3->in1(S1);
        notg_3->out1(S2);

    nor_n_4 = new nor_n("nor_n_4");
        nor_n_4->in1[0](S2);
        nor_n_4->in1[1](S11);
        nor_n_4->out1(S3);

    nand_n_5 = new nand_n("nand_n_5");
        nand_n_5->in1[0](S1);
        nand_n_5->in1[1](S0);
        nand_n_5->out1(S4);

    nand_n_6 = new nand_n("nand_n_6");
        nand_n_6->in1[0](S4);
        nand_n_6->in1[1](S14);
        nand_n_6->out1(S5);

    nand_n_7 = new nand_n("nand_n_7");
        nand_n_7->in1[0](S3);
        nand_n_7->in1[1](S9);
        nand_n_7->out1(S6);

    nand_n_8 = new nand_n("nand_n_8");
        nand_n_8->in1[0](S6);
        nand_n_8->in1[1](S5);
        nand_n_8->out1(S16);

    nand_n_9 = new nand_n("nand_n_9");
        nand_n_9->in1[0](S0);
        nand_n_9->in1[1](S14);
        nand_n_9->out1(S7);

    nand_n_10 = new nand_n("nand_n_10");
        nand_n_10->in1[0](S7);
        nand_n_10->in1[1](S1);
        nand_n_10->out1(S13);

    notg_11 = new notg("notg_11");
        notg_11->in1(S15);
        notg_11->out1(S8);

    notg_12 = new notg("notg_12");
        notg_12->in1(S14);
        notg_12->out1(S9);

    notg_13 = new notg("notg_13");
        notg_13->in1(S12);
        notg_13->out1(S10);

    bufg_14 = new bufg("bufg_14");
        bufg_14->in1(ci);
        bufg_14->out1(S12);

    bufg_15 = new bufg("bufg_15");
        bufg_15->in1(S13);
        bufg_15->out1(co);

    bufg_16 = new bufg("bufg_16");
        bufg_16->in1(i0);
        bufg_16->out1(S14);

    bufg_17 = new bufg("bufg_17");
        bufg_17->in1(i1);
        bufg_17->out1(S15);

    bufg_18 = new bufg("bufg_18");
        bufg_18->in1(S16);
        bufg_18->out1(s);


    SC_METHOD(sc_logic_signal_assignment);

    }

    void sc_logic_signal_assignment(void){ 
        sc_logic_1_signal.write(SC_LOGIC_1);
        sc_logic_0_signal.write(SC_LOGIC_0);
    }
};
