#include <systemc.h>
#include "component_library.h"

using namespace sc_core;

SC_MODULE( counter_4bit ) {

    sc_in<sc_logic> clk;
    sc_in<sc_logic> rst;
    sc_in<sc_logic> en;
    sc_out<sc_logic> co;
    sc_out<sc_logic> counter[4];

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
    sc_signal<sc_logic> S17;
    sc_signal<sc_logic> S18;
    sc_signal<sc_logic> S19;
    sc_signal<sc_logic> S20;
    sc_signal<sc_logic> S21;
    sc_signal<sc_logic> S22;
    sc_signal<sc_logic> S23;
    sc_signal<sc_logic> S24;
    sc_signal<sc_logic> S25;
    sc_signal<sc_logic> new_counter_reg_0;
    sc_signal<sc_logic> new_counter_reg_1;
    sc_signal<sc_logic> new_counter_reg_2;
    sc_signal<sc_logic> new_counter_reg_3;

    notg* notg_0;
    notg* notg_1;
    notg* notg_2;
    nand_n* nand_n_3;
    nand_n* nand_n_4;
    nor_n* nor_n_5;
    nor_n* nor_n_6;
    nor_n* nor_n_7;
    nor_n* nor_n_8;
    nor_n* nor_n_9;
    nor_n* nor_n_10;
    nor_n* nor_n_11;
    nand_n* nand_n_12;
    notg* notg_13;
    nor_n* nor_n_14;
    nor_n* nor_n_15;
    nor_n* nor_n_16;
    nor_n* nor_n_17;
    nor_n* nor_n_18;
    dff* dff_19;
    dff* dff_20;
    dff* dff_21;
    dff* dff_22;
    pin* pin_23;
    pout* pout_24;
    pout* pout_25;
    pout* pout_26;
    pout* pout_27;
    pout* pout_28;
    pin* pin_29;
    pin* pin_30;

SC_CTOR( counter_4bit ) {
    notg_0 = new notg("notg_0");
        notg_0->A(new_counter_reg_0);
        notg_0->Y(S4);

    notg_1 = new notg("notg_1");
        notg_1->A(new_counter_reg_3);
        notg_1->Y(S5);

    notg_2 = new notg("notg_2");
        notg_2->A(S20);
        notg_2->Y(S6);

    nand_n_3 = new nand_n("nand_n_3");
        nand_n_3->A[0](new_counter_reg_1);
        nand_n_3->A[1](new_counter_reg_0);
        nand_n_3->Y(S7);

    nand_n_4 = new nand_n("nand_n_4");
        nand_n_4->A[0](new_counter_reg_2);
        nand_n_4->A[1](new_counter_reg_3);
        nand_n_4->Y(S8);

    nor_n_5 = new nor_n("nor_n_5");
        nor_n_5->A[0](S8);
        nor_n_5->A[1](S7);
        nor_n_5->Y(S19);

    nor_n_6 = new nor_n("nor_n_6");
        nor_n_6->A[0](S6);
        nor_n_6->A[1](S4);
        nor_n_6->Y(S9);

    nor_n_7 = new nor_n("nor_n_7");
        nor_n_7->A[0](S20);
        nor_n_7->A[1](new_counter_reg_0);
        nor_n_7->Y(S10);

    nor_n_8 = new nor_n("nor_n_8");
        nor_n_8->A[0](S10);
        nor_n_8->A[1](S9);
        nor_n_8->Y(S0);

    nor_n_9 = new nor_n("nor_n_9");
        nor_n_9->A[0](S7);
        nor_n_9->A[1](S6);
        nor_n_9->Y(S11);

    nor_n_10 = new nor_n("nor_n_10");
        nor_n_10->A[0](S9);
        nor_n_10->A[1](new_counter_reg_1);
        nor_n_10->Y(S12);

    nor_n_11 = new nor_n("nor_n_11");
        nor_n_11->A[0](S12);
        nor_n_11->A[1](S11);
        nor_n_11->Y(S1);

    nand_n_12 = new nand_n("nand_n_12");
        nand_n_12->A[0](S11);
        nand_n_12->A[1](new_counter_reg_2);
        nand_n_12->Y(S13);

    notg_13 = new notg("notg_13");
        notg_13->A(S13);
        notg_13->Y(S14);

    nor_n_14 = new nor_n("nor_n_14");
        nor_n_14->A[0](S11);
        nor_n_14->A[1](new_counter_reg_2);
        nor_n_14->Y(S15);

    nor_n_15 = new nor_n("nor_n_15");
        nor_n_15->A[0](S15);
        nor_n_15->A[1](S14);
        nor_n_15->Y(S2);

    nor_n_16 = new nor_n("nor_n_16");
        nor_n_16->A[0](S14);
        nor_n_16->A[1](new_counter_reg_3);
        nor_n_16->Y(S16);

    nor_n_17 = new nor_n("nor_n_17");
        nor_n_17->A[0](S13);
        nor_n_17->A[1](S5);
        nor_n_17->Y(S17);

    nor_n_18 = new nor_n("nor_n_18");
        nor_n_18->A[0](S17);
        nor_n_18->A[1](S16);
        nor_n_18->Y(S3);

    dff_19 = new dff("dff_19");
        dff_19->C(S18);
        dff_19->CE(sc_logic_1_signal);
        dff_19->D(S0);
        dff_19->NbarT(sc_logic_0_signal);
        dff_19->PRE(sc_logic_0_signal);
        dff_19->Q(new_counter_reg_0);
        dff_19->R(S21);
        dff_19->Si(S22);
        dff_19->global_reset(sc_logic_0_signal);

    dff_20 = new dff("dff_20");
        dff_20->C(S18);
        dff_20->CE(sc_logic_1_signal);
        dff_20->D(S1);
        dff_20->NbarT(sc_logic_0_signal);
        dff_20->PRE(sc_logic_0_signal);
        dff_20->Q(new_counter_reg_1);
        dff_20->R(S21);
        dff_20->Si(S23);
        dff_20->global_reset(sc_logic_0_signal);

    dff_21 = new dff("dff_21");
        dff_21->C(S18);
        dff_21->CE(sc_logic_1_signal);
        dff_21->D(S2);
        dff_21->NbarT(sc_logic_0_signal);
        dff_21->PRE(sc_logic_0_signal);
        dff_21->Q(new_counter_reg_2);
        dff_21->R(S21);
        dff_21->Si(S24);
        dff_21->global_reset(sc_logic_0_signal);

    dff_22 = new dff("dff_22");
        dff_22->C(S18);
        dff_22->CE(sc_logic_1_signal);
        dff_22->D(S3);
        dff_22->NbarT(sc_logic_0_signal);
        dff_22->PRE(sc_logic_0_signal);
        dff_22->Q(new_counter_reg_3);
        dff_22->R(S21);
        dff_22->Si(S25);
        dff_22->global_reset(sc_logic_0_signal);

    pin_23 = new pin("pin_23");
        pin_23->I(clk);
        pin_23->O(S18);

    pout_24 = new pout("pout_24");
        pout_24->I(S19);
        pout_24->O(co);

    pout_25 = new pout("pout_25");
        pout_25->I(new_counter_reg_0);
        pout_25->O(counter[0]);

    pout_26 = new pout("pout_26");
        pout_26->I(new_counter_reg_1);
        pout_26->O(counter[1]);

    pout_27 = new pout("pout_27");
        pout_27->I(new_counter_reg_2);
        pout_27->O(counter[2]);

    pout_28 = new pout("pout_28");
        pout_28->I(new_counter_reg_3);
        pout_28->O(counter[3]);

    pin_29 = new pin("pin_29");
        pin_29->I(en);
        pin_29->O(S20);

    pin_30 = new pin("pin_30");
        pin_30->I(rst);
        pin_30->O(S21);


    SC_METHOD(sc_logic_signal_assignment);

    }

    void sc_logic_signal_assignment(void){ 
        sc_logic_1_signal.write(SC_LOGIC_1);
        sc_logic_0_signal.write(SC_LOGIC_0);
    }
};
