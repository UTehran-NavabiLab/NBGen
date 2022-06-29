#include <systemc.h>
#include "component_library.h"

using namespace sc_core;

SC_MODULE( counter ) {

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

SC_CTOR( counter ) {
    notg_0 = new notg("notg_0_inst");
        notg_0->in(new_counter_reg_0);
        notg_0->out(S4);

    notg_1 = new notg("notg_1_inst");
        notg_1->in(new_counter_reg_3);
        notg_1->out(S5);

    notg_2 = new notg("notg_2_inst");
        notg_2->in(S20);
        notg_2->out(S6);

    nand_n_3 = new nand_n("nand_n_3_inst");
        nand_n_3->in[0](new_counter_reg_1);
        nand_n_3->in[1](new_counter_reg_0);
        nand_n_3->out(S7);

    nand_n_4 = new nand_n("nand_n_4_inst");
        nand_n_4->in[0](new_counter_reg_2);
        nand_n_4->in[1](new_counter_reg_3);
        nand_n_4->out(S8);

    nor_n_5 = new nor_n("nor_n_5_inst");
        nor_n_5->in[0](S8);
        nor_n_5->in[1](S7);
        nor_n_5->out(S19);

    nor_n_6 = new nor_n("nor_n_6_inst");
        nor_n_6->in[0](S6);
        nor_n_6->in[1](S4);
        nor_n_6->out(S9);

    nor_n_7 = new nor_n("nor_n_7_inst");
        nor_n_7->in[0](S20);
        nor_n_7->in[1](new_counter_reg_0);
        nor_n_7->out(S10);

    nor_n_8 = new nor_n("nor_n_8_inst");
        nor_n_8->in[0](S10);
        nor_n_8->in[1](S9);
        nor_n_8->out(S0);

    nor_n_9 = new nor_n("nor_n_9_inst");
        nor_n_9->in[0](S7);
        nor_n_9->in[1](S6);
        nor_n_9->out(S11);

    nor_n_10 = new nor_n("nor_n_10_inst");
        nor_n_10->in[0](S9);
        nor_n_10->in[1](new_counter_reg_1);
        nor_n_10->out(S12);

    nor_n_11 = new nor_n("nor_n_11_inst");
        nor_n_11->in[0](S12);
        nor_n_11->in[1](S11);
        nor_n_11->out(S1);

    nand_n_12 = new nand_n("nand_n_12_inst");
        nand_n_12->in[0](S11);
        nand_n_12->in[1](new_counter_reg_2);
        nand_n_12->out(S13);

    notg_13 = new notg("notg_13_inst");
        notg_13->in(S13);
        notg_13->out(S14);

    nor_n_14 = new nor_n("nor_n_14_inst");
        nor_n_14->in[0](S11);
        nor_n_14->in[1](new_counter_reg_2);
        nor_n_14->out(S15);

    nor_n_15 = new nor_n("nor_n_15_inst");
        nor_n_15->in[0](S15);
        nor_n_15->in[1](S14);
        nor_n_15->out(S2);

    nor_n_16 = new nor_n("nor_n_16_inst");
        nor_n_16->in[0](S14);
        nor_n_16->in[1](new_counter_reg_3);
        nor_n_16->out(S16);

    nor_n_17 = new nor_n("nor_n_17_inst");
        nor_n_17->in[0](S13);
        nor_n_17->in[1](S5);
        nor_n_17->out(S17);

    nor_n_18 = new nor_n("nor_n_18_inst");
        nor_n_18->in[0](S17);
        nor_n_18->in[1](S16);
        nor_n_18->out(S3);

    dff_19 = new dff("dff_19_inst");
        dff_19->C(S18);
        dff_19->CE(sc_logic_1_signal);
        dff_19->CLR(S21);
        dff_19->D(S0);
        dff_19->NbarT(sc_logic_0_signal);
        dff_19->PRE(sc_logic_0_signal);
        dff_19->Q(new_counter_reg_0);
        dff_19->Si(S22);
        dff_19->global_reset(sc_logic_0_signal);

    dff_20 = new dff("dff_20_inst");
        dff_20->C(S18);
        dff_20->CE(sc_logic_1_signal);
        dff_20->CLR(S21);
        dff_20->D(S1);
        dff_20->NbarT(sc_logic_0_signal);
        dff_20->PRE(sc_logic_0_signal);
        dff_20->Q(new_counter_reg_1);
        dff_20->Si(S23);
        dff_20->global_reset(sc_logic_0_signal);

    dff_21 = new dff("dff_21_inst");
        dff_21->C(S18);
        dff_21->CE(sc_logic_1_signal);
        dff_21->CLR(S21);
        dff_21->D(S2);
        dff_21->NbarT(sc_logic_0_signal);
        dff_21->PRE(sc_logic_0_signal);
        dff_21->Q(new_counter_reg_2);
        dff_21->Si(S24);
        dff_21->global_reset(sc_logic_0_signal);

    dff_22 = new dff("dff_22_inst");
        dff_22->C(S18);
        dff_22->CE(sc_logic_1_signal);
        dff_22->CLR(S21);
        dff_22->D(S3);
        dff_22->NbarT(sc_logic_0_signal);
        dff_22->PRE(sc_logic_0_signal);
        dff_22->Q(new_counter_reg_3);
        dff_22->Si(S25);
        dff_22->global_reset(sc_logic_0_signal);

    pin_23 = new pin("pin_23_inst");
        pin_23->in(clk);
        pin_23->out(S18);

    pout_24 = new pout("pout_24_inst");
        pout_24->in(S19);
        pout_24->out(co);

    pout_25 = new pout("pout_25_inst");
        pout_25->in(new_counter_reg_0);
        pout_25->out(counter[0]);

    pout_26 = new pout("pout_26_inst");
        pout_26->in(new_counter_reg_1);
        pout_26->out(counter[1]);

    pout_27 = new pout("pout_27_inst");
        pout_27->in(new_counter_reg_2);
        pout_27->out(counter[2]);

    pout_28 = new pout("pout_28_inst");
        pout_28->in(new_counter_reg_3);
        pout_28->out(counter[3]);

    pin_29 = new pin("pin_29_inst");
        pin_29->in(en);
        pin_29->out(S20);

    pin_30 = new pin("pin_30_inst");
        pin_30->in(rst);
        pin_30->out(S21);


    SC_METHOD(sc_logic_signal_assignment);

}

    void sc_logic_signal_assignment(void){ 
        sc_logic_1_signal.write(SC_LOGIC_1);
        sc_logic_0_signal.write(SC_LOGIC_0);
    }
};
