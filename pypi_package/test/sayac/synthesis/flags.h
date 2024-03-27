#include <systemc.h>
#include "Complex_NAgate_45.h"

#include "iff.h"
#include "iff.h"
#include "iff.h"
#include "iff.h"
#include "iff.h"
#include "iff.h"
#include "iff.h"
#include "iff.h"


#ifndef __FLAGS_H__
#define __FLAGS_H__
using namespace sc_core;

SC_MODULE( flags ) {

    sc_in<sc_logic> clk;
    sc_in<sc_logic> rst;
    sc_in<sc_logic> setflags;
    sc_in<sc_logic> enflag;
    sc_in<sc_logic> selflag[8];
    sc_in<sc_logic> inflag[8];
    sc_out<sc_logic> outflag[8];

    sc_signal<sc_logic> sc_logic_1_signal;
    sc_signal<sc_logic> sc_logic_0_signal;

    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S0 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S0");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S1 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S1");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S2[8];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S3[8];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S4 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S4");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S5[8];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S6 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S6");

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
    BUF_X1* BUF_X1_15;
    BUF_X1* BUF_X1_16;
    BUF_X1* BUF_X1_17;
    BUF_X1* BUF_X1_18;
    BUF_X1* BUF_X1_19;
    BUF_X1* BUF_X1_20;
    BUF_X1* BUF_X1_21;
    BUF_X1* BUF_X1_22;
    BUF_X1* BUF_X1_23;
    BUF_X1* BUF_X1_24;
    BUF_X1* BUF_X1_25;
    BUF_X1* BUF_X1_26;
    BUF_X1* BUF_X1_27;
    BUF_X1* BUF_X1_28;
    iff* flagsff_1_ff_biti;
    iff* flagsff_2_ff_biti;
    iff* flagsff_3_ff_biti;
    iff* flagsff_4_ff_biti;
    iff* flagsff_5_ff_biti;
    iff* flagsff_6_ff_biti;
    iff* flagsff_7_ff_biti;
    iff* flagsff_8_ff_biti;

SC_CTOR( flags ) {
    BUF_X1_1 = new BUF_X1("BUF_X1_1");
        BUF_X1_1->A(clk);
        BUF_X1_1->Z(S0);

    BUF_X1_2 = new BUF_X1("BUF_X1_2");
        BUF_X1_2->A(enflag);
        BUF_X1_2->Z(S1);

    BUF_X1_3 = new BUF_X1("BUF_X1_3");
        BUF_X1_3->A(inflag[0]);
        BUF_X1_3->Z(S2[0]);

    BUF_X1_4 = new BUF_X1("BUF_X1_4");
        BUF_X1_4->A(inflag[1]);
        BUF_X1_4->Z(S2[1]);

    BUF_X1_5 = new BUF_X1("BUF_X1_5");
        BUF_X1_5->A(inflag[2]);
        BUF_X1_5->Z(S2[2]);

    BUF_X1_6 = new BUF_X1("BUF_X1_6");
        BUF_X1_6->A(inflag[3]);
        BUF_X1_6->Z(S2[3]);

    BUF_X1_7 = new BUF_X1("BUF_X1_7");
        BUF_X1_7->A(inflag[4]);
        BUF_X1_7->Z(S2[4]);

    BUF_X1_8 = new BUF_X1("BUF_X1_8");
        BUF_X1_8->A(inflag[5]);
        BUF_X1_8->Z(S2[5]);

    BUF_X1_9 = new BUF_X1("BUF_X1_9");
        BUF_X1_9->A(inflag[6]);
        BUF_X1_9->Z(S2[6]);

    BUF_X1_10 = new BUF_X1("BUF_X1_10");
        BUF_X1_10->A(inflag[7]);
        BUF_X1_10->Z(S2[7]);

    BUF_X1_11 = new BUF_X1("BUF_X1_11");
        BUF_X1_11->A(S3[0]);
        BUF_X1_11->Z(outflag[0]);

    BUF_X1_12 = new BUF_X1("BUF_X1_12");
        BUF_X1_12->A(S3[1]);
        BUF_X1_12->Z(outflag[1]);

    BUF_X1_13 = new BUF_X1("BUF_X1_13");
        BUF_X1_13->A(S3[2]);
        BUF_X1_13->Z(outflag[2]);

    BUF_X1_14 = new BUF_X1("BUF_X1_14");
        BUF_X1_14->A(S3[3]);
        BUF_X1_14->Z(outflag[3]);

    BUF_X1_15 = new BUF_X1("BUF_X1_15");
        BUF_X1_15->A(S3[4]);
        BUF_X1_15->Z(outflag[4]);

    BUF_X1_16 = new BUF_X1("BUF_X1_16");
        BUF_X1_16->A(S3[5]);
        BUF_X1_16->Z(outflag[5]);

    BUF_X1_17 = new BUF_X1("BUF_X1_17");
        BUF_X1_17->A(S3[6]);
        BUF_X1_17->Z(outflag[6]);

    BUF_X1_18 = new BUF_X1("BUF_X1_18");
        BUF_X1_18->A(S3[7]);
        BUF_X1_18->Z(outflag[7]);

    BUF_X1_19 = new BUF_X1("BUF_X1_19");
        BUF_X1_19->A(rst);
        BUF_X1_19->Z(S4);

    BUF_X1_20 = new BUF_X1("BUF_X1_20");
        BUF_X1_20->A(selflag[0]);
        BUF_X1_20->Z(S5[0]);

    BUF_X1_21 = new BUF_X1("BUF_X1_21");
        BUF_X1_21->A(selflag[1]);
        BUF_X1_21->Z(S5[1]);

    BUF_X1_22 = new BUF_X1("BUF_X1_22");
        BUF_X1_22->A(selflag[2]);
        BUF_X1_22->Z(S5[2]);

    BUF_X1_23 = new BUF_X1("BUF_X1_23");
        BUF_X1_23->A(selflag[3]);
        BUF_X1_23->Z(S5[3]);

    BUF_X1_24 = new BUF_X1("BUF_X1_24");
        BUF_X1_24->A(selflag[4]);
        BUF_X1_24->Z(S5[4]);

    BUF_X1_25 = new BUF_X1("BUF_X1_25");
        BUF_X1_25->A(selflag[5]);
        BUF_X1_25->Z(S5[5]);

    BUF_X1_26 = new BUF_X1("BUF_X1_26");
        BUF_X1_26->A(selflag[6]);
        BUF_X1_26->Z(S5[6]);

    BUF_X1_27 = new BUF_X1("BUF_X1_27");
        BUF_X1_27->A(selflag[7]);
        BUF_X1_27->Z(S5[7]);

    BUF_X1_28 = new BUF_X1("BUF_X1_28");
        BUF_X1_28->A(setflags);
        BUF_X1_28->Z(S6);

    flagsff_1_ff_biti = new iff("flagsff_1_ff_biti");
        flagsff_1_ff_biti->clk(S0);
        flagsff_1_ff_biti->enflag(S1);
        flagsff_1_ff_biti->inflag(S2[0]);
        flagsff_1_ff_biti->outflag(S3[0]);
        flagsff_1_ff_biti->rst(S4);
        flagsff_1_ff_biti->selflag(S5[0]);
        flagsff_1_ff_biti->setflags(S6);

    flagsff_2_ff_biti = new iff("flagsff_2_ff_biti");
        flagsff_2_ff_biti->clk(S0);
        flagsff_2_ff_biti->enflag(S1);
        flagsff_2_ff_biti->inflag(S2[1]);
        flagsff_2_ff_biti->outflag(S3[1]);
        flagsff_2_ff_biti->rst(S4);
        flagsff_2_ff_biti->selflag(S5[1]);
        flagsff_2_ff_biti->setflags(S6);

    flagsff_3_ff_biti = new iff("flagsff_3_ff_biti");
        flagsff_3_ff_biti->clk(S0);
        flagsff_3_ff_biti->enflag(S1);
        flagsff_3_ff_biti->inflag(S2[2]);
        flagsff_3_ff_biti->outflag(S3[2]);
        flagsff_3_ff_biti->rst(S4);
        flagsff_3_ff_biti->selflag(S5[2]);
        flagsff_3_ff_biti->setflags(S6);

    flagsff_4_ff_biti = new iff("flagsff_4_ff_biti");
        flagsff_4_ff_biti->clk(S0);
        flagsff_4_ff_biti->enflag(S1);
        flagsff_4_ff_biti->inflag(S2[3]);
        flagsff_4_ff_biti->outflag(S3[3]);
        flagsff_4_ff_biti->rst(S4);
        flagsff_4_ff_biti->selflag(S5[3]);
        flagsff_4_ff_biti->setflags(S6);

    flagsff_5_ff_biti = new iff("flagsff_5_ff_biti");
        flagsff_5_ff_biti->clk(S0);
        flagsff_5_ff_biti->enflag(S1);
        flagsff_5_ff_biti->inflag(S2[4]);
        flagsff_5_ff_biti->outflag(S3[4]);
        flagsff_5_ff_biti->rst(S4);
        flagsff_5_ff_biti->selflag(S5[4]);
        flagsff_5_ff_biti->setflags(S6);

    flagsff_6_ff_biti = new iff("flagsff_6_ff_biti");
        flagsff_6_ff_biti->clk(S0);
        flagsff_6_ff_biti->enflag(S1);
        flagsff_6_ff_biti->inflag(S2[5]);
        flagsff_6_ff_biti->outflag(S3[5]);
        flagsff_6_ff_biti->rst(S4);
        flagsff_6_ff_biti->selflag(S5[5]);
        flagsff_6_ff_biti->setflags(S6);

    flagsff_7_ff_biti = new iff("flagsff_7_ff_biti");
        flagsff_7_ff_biti->clk(S0);
        flagsff_7_ff_biti->enflag(S1);
        flagsff_7_ff_biti->inflag(S2[6]);
        flagsff_7_ff_biti->outflag(S3[6]);
        flagsff_7_ff_biti->rst(S4);
        flagsff_7_ff_biti->selflag(S5[6]);
        flagsff_7_ff_biti->setflags(S6);

    flagsff_8_ff_biti = new iff("flagsff_8_ff_biti");
        flagsff_8_ff_biti->clk(S0);
        flagsff_8_ff_biti->enflag(S1);
        flagsff_8_ff_biti->inflag(S2[7]);
        flagsff_8_ff_biti->outflag(S3[7]);
        flagsff_8_ff_biti->rst(S4);
        flagsff_8_ff_biti->selflag(S5[7]);
        flagsff_8_ff_biti->setflags(S6);


    SC_METHOD(sc_logic_signal_assignment);

    }

    void sc_logic_signal_assignment(void){ 
        sc_logic_1_signal.write(SC_LOGIC_1);
        sc_logic_0_signal.write(SC_LOGIC_0);
    }
};
#endif /* __FLAGS_H__ */

