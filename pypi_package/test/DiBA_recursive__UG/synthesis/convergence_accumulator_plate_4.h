#include <systemc.h>
#include "Complex_NAgate_45.h"

#include "add.h"
#include "cap_controller.h"
#include "mux_cascading.h"


#ifndef __CONVERGENCE_ACCUMULATOR_PLATE_4_H__
#define __CONVERGENCE_ACCUMULATOR_PLATE_4_H__
using namespace sc_core;

SC_MODULE( convergence_accumulator_plate_4 ) {

    sc_in<sc_logic> clk;
    sc_in<sc_logic> rst;
    sc_in<sc_logic> run;
    sc_in<sc_logic> din[128];
    sc_out<sc_logic> reg_out;
    sc_out<sc_logic> dout[32];

    sc_signal<sc_logic> sc_logic_1_signal;
    sc_signal<sc_logic> sc_logic_0_signal;

    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S0 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S0");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S1[128];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S2[32];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S3 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S3");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S4 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S4");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S5 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S5");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> add_reg = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("add_reg");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> c_add_ctrl_128_0_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("c_add_ctrl_128_0_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> c_add_ctrl_128_1_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("c_add_ctrl_128_1_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> c_add_ctrl_128_2_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("c_add_ctrl_128_2_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> c_add_ctrl_128_3_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("c_add_ctrl_128_3_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> c_add_ctrl_129 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("c_add_ctrl_129");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> doutm_0_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("doutm_0_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> doutm_10_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("doutm_10_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> doutm_11_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("doutm_11_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> doutm_12_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("doutm_12_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> doutm_13_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("doutm_13_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> doutm_14_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("doutm_14_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> doutm_15_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("doutm_15_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> doutm_16_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("doutm_16_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> doutm_17_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("doutm_17_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> doutm_18_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("doutm_18_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> doutm_19_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("doutm_19_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> doutm_1_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("doutm_1_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> doutm_20_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("doutm_20_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> doutm_21_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("doutm_21_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> doutm_22_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("doutm_22_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> doutm_23_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("doutm_23_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> doutm_24_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("doutm_24_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> doutm_25_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("doutm_25_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> doutm_26_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("doutm_26_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> doutm_27_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("doutm_27_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> doutm_28_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("doutm_28_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> doutm_29_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("doutm_29_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> doutm_2_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("doutm_2_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> doutm_30_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("doutm_30_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> doutm_31_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("doutm_31_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> doutm_3_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("doutm_3_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> doutm_4_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("doutm_4_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> doutm_5_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("doutm_5_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> doutm_6_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("doutm_6_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> doutm_7_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("doutm_7_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> doutm_8_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("doutm_8_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> doutm_9_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("doutm_9_");

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
    BUF_X1* BUF_X1_29;
    BUF_X1* BUF_X1_30;
    BUF_X1* BUF_X1_31;
    BUF_X1* BUF_X1_32;
    BUF_X1* BUF_X1_33;
    BUF_X1* BUF_X1_34;
    BUF_X1* BUF_X1_35;
    BUF_X1* BUF_X1_36;
    BUF_X1* BUF_X1_37;
    BUF_X1* BUF_X1_38;
    BUF_X1* BUF_X1_39;
    BUF_X1* BUF_X1_40;
    BUF_X1* BUF_X1_41;
    BUF_X1* BUF_X1_42;
    BUF_X1* BUF_X1_43;
    BUF_X1* BUF_X1_44;
    BUF_X1* BUF_X1_45;
    BUF_X1* BUF_X1_46;
    BUF_X1* BUF_X1_47;
    BUF_X1* BUF_X1_48;
    BUF_X1* BUF_X1_49;
    BUF_X1* BUF_X1_50;
    BUF_X1* BUF_X1_51;
    BUF_X1* BUF_X1_52;
    BUF_X1* BUF_X1_53;
    BUF_X1* BUF_X1_54;
    BUF_X1* BUF_X1_55;
    BUF_X1* BUF_X1_56;
    BUF_X1* BUF_X1_57;
    BUF_X1* BUF_X1_58;
    BUF_X1* BUF_X1_59;
    BUF_X1* BUF_X1_60;
    BUF_X1* BUF_X1_61;
    BUF_X1* BUF_X1_62;
    BUF_X1* BUF_X1_63;
    BUF_X1* BUF_X1_64;
    BUF_X1* BUF_X1_65;
    BUF_X1* BUF_X1_66;
    BUF_X1* BUF_X1_67;
    BUF_X1* BUF_X1_68;
    BUF_X1* BUF_X1_69;
    BUF_X1* BUF_X1_70;
    BUF_X1* BUF_X1_71;
    BUF_X1* BUF_X1_72;
    BUF_X1* BUF_X1_73;
    BUF_X1* BUF_X1_74;
    BUF_X1* BUF_X1_75;
    BUF_X1* BUF_X1_76;
    BUF_X1* BUF_X1_77;
    BUF_X1* BUF_X1_78;
    BUF_X1* BUF_X1_79;
    BUF_X1* BUF_X1_80;
    BUF_X1* BUF_X1_81;
    BUF_X1* BUF_X1_82;
    BUF_X1* BUF_X1_83;
    BUF_X1* BUF_X1_84;
    BUF_X1* BUF_X1_85;
    BUF_X1* BUF_X1_86;
    BUF_X1* BUF_X1_87;
    BUF_X1* BUF_X1_88;
    BUF_X1* BUF_X1_89;
    BUF_X1* BUF_X1_90;
    BUF_X1* BUF_X1_91;
    BUF_X1* BUF_X1_92;
    BUF_X1* BUF_X1_93;
    BUF_X1* BUF_X1_94;
    BUF_X1* BUF_X1_95;
    BUF_X1* BUF_X1_96;
    BUF_X1* BUF_X1_97;
    BUF_X1* BUF_X1_98;
    BUF_X1* BUF_X1_99;
    BUF_X1* BUF_X1_100;
    BUF_X1* BUF_X1_101;
    BUF_X1* BUF_X1_102;
    BUF_X1* BUF_X1_103;
    BUF_X1* BUF_X1_104;
    BUF_X1* BUF_X1_105;
    BUF_X1* BUF_X1_106;
    BUF_X1* BUF_X1_107;
    BUF_X1* BUF_X1_108;
    BUF_X1* BUF_X1_109;
    BUF_X1* BUF_X1_110;
    BUF_X1* BUF_X1_111;
    BUF_X1* BUF_X1_112;
    BUF_X1* BUF_X1_113;
    BUF_X1* BUF_X1_114;
    BUF_X1* BUF_X1_115;
    BUF_X1* BUF_X1_116;
    BUF_X1* BUF_X1_117;
    BUF_X1* BUF_X1_118;
    BUF_X1* BUF_X1_119;
    BUF_X1* BUF_X1_120;
    BUF_X1* BUF_X1_121;
    BUF_X1* BUF_X1_122;
    BUF_X1* BUF_X1_123;
    BUF_X1* BUF_X1_124;
    BUF_X1* BUF_X1_125;
    BUF_X1* BUF_X1_126;
    BUF_X1* BUF_X1_127;
    BUF_X1* BUF_X1_128;
    BUF_X1* BUF_X1_129;
    BUF_X1* BUF_X1_130;
    BUF_X1* BUF_X1_131;
    BUF_X1* BUF_X1_132;
    BUF_X1* BUF_X1_133;
    BUF_X1* BUF_X1_134;
    BUF_X1* BUF_X1_135;
    BUF_X1* BUF_X1_136;
    BUF_X1* BUF_X1_137;
    BUF_X1* BUF_X1_138;
    BUF_X1* BUF_X1_139;
    BUF_X1* BUF_X1_140;
    BUF_X1* BUF_X1_141;
    BUF_X1* BUF_X1_142;
    BUF_X1* BUF_X1_143;
    BUF_X1* BUF_X1_144;
    BUF_X1* BUF_X1_145;
    BUF_X1* BUF_X1_146;
    BUF_X1* BUF_X1_147;
    BUF_X1* BUF_X1_148;
    BUF_X1* BUF_X1_149;
    BUF_X1* BUF_X1_150;
    BUF_X1* BUF_X1_151;
    BUF_X1* BUF_X1_152;
    BUF_X1* BUF_X1_153;
    BUF_X1* BUF_X1_154;
    BUF_X1* BUF_X1_155;
    BUF_X1* BUF_X1_156;
    BUF_X1* BUF_X1_157;
    BUF_X1* BUF_X1_158;
    BUF_X1* BUF_X1_159;
    BUF_X1* BUF_X1_160;
    BUF_X1* BUF_X1_161;
    BUF_X1* BUF_X1_162;
    BUF_X1* BUF_X1_163;
    BUF_X1* BUF_X1_164;
    add* c_add;
    cap_controller* c_add_ctrl;
    mux_cascading* mux;

SC_CTOR( convergence_accumulator_plate_4 ) {
    BUF_X1_1 = new BUF_X1("BUF_X1_1");
        BUF_X1_1->A(clk);
        BUF_X1_1->Z(S0);

    BUF_X1_2 = new BUF_X1("BUF_X1_2");
        BUF_X1_2->A(din[0]);
        BUF_X1_2->Z(S1[0]);

    BUF_X1_3 = new BUF_X1("BUF_X1_3");
        BUF_X1_3->A(din[1]);
        BUF_X1_3->Z(S1[1]);

    BUF_X1_4 = new BUF_X1("BUF_X1_4");
        BUF_X1_4->A(din[10]);
        BUF_X1_4->Z(S1[10]);

    BUF_X1_5 = new BUF_X1("BUF_X1_5");
        BUF_X1_5->A(din[100]);
        BUF_X1_5->Z(S1[100]);

    BUF_X1_6 = new BUF_X1("BUF_X1_6");
        BUF_X1_6->A(din[101]);
        BUF_X1_6->Z(S1[101]);

    BUF_X1_7 = new BUF_X1("BUF_X1_7");
        BUF_X1_7->A(din[102]);
        BUF_X1_7->Z(S1[102]);

    BUF_X1_8 = new BUF_X1("BUF_X1_8");
        BUF_X1_8->A(din[103]);
        BUF_X1_8->Z(S1[103]);

    BUF_X1_9 = new BUF_X1("BUF_X1_9");
        BUF_X1_9->A(din[104]);
        BUF_X1_9->Z(S1[104]);

    BUF_X1_10 = new BUF_X1("BUF_X1_10");
        BUF_X1_10->A(din[105]);
        BUF_X1_10->Z(S1[105]);

    BUF_X1_11 = new BUF_X1("BUF_X1_11");
        BUF_X1_11->A(din[106]);
        BUF_X1_11->Z(S1[106]);

    BUF_X1_12 = new BUF_X1("BUF_X1_12");
        BUF_X1_12->A(din[107]);
        BUF_X1_12->Z(S1[107]);

    BUF_X1_13 = new BUF_X1("BUF_X1_13");
        BUF_X1_13->A(din[108]);
        BUF_X1_13->Z(S1[108]);

    BUF_X1_14 = new BUF_X1("BUF_X1_14");
        BUF_X1_14->A(din[109]);
        BUF_X1_14->Z(S1[109]);

    BUF_X1_15 = new BUF_X1("BUF_X1_15");
        BUF_X1_15->A(din[11]);
        BUF_X1_15->Z(S1[11]);

    BUF_X1_16 = new BUF_X1("BUF_X1_16");
        BUF_X1_16->A(din[110]);
        BUF_X1_16->Z(S1[110]);

    BUF_X1_17 = new BUF_X1("BUF_X1_17");
        BUF_X1_17->A(din[111]);
        BUF_X1_17->Z(S1[111]);

    BUF_X1_18 = new BUF_X1("BUF_X1_18");
        BUF_X1_18->A(din[112]);
        BUF_X1_18->Z(S1[112]);

    BUF_X1_19 = new BUF_X1("BUF_X1_19");
        BUF_X1_19->A(din[113]);
        BUF_X1_19->Z(S1[113]);

    BUF_X1_20 = new BUF_X1("BUF_X1_20");
        BUF_X1_20->A(din[114]);
        BUF_X1_20->Z(S1[114]);

    BUF_X1_21 = new BUF_X1("BUF_X1_21");
        BUF_X1_21->A(din[115]);
        BUF_X1_21->Z(S1[115]);

    BUF_X1_22 = new BUF_X1("BUF_X1_22");
        BUF_X1_22->A(din[116]);
        BUF_X1_22->Z(S1[116]);

    BUF_X1_23 = new BUF_X1("BUF_X1_23");
        BUF_X1_23->A(din[117]);
        BUF_X1_23->Z(S1[117]);

    BUF_X1_24 = new BUF_X1("BUF_X1_24");
        BUF_X1_24->A(din[118]);
        BUF_X1_24->Z(S1[118]);

    BUF_X1_25 = new BUF_X1("BUF_X1_25");
        BUF_X1_25->A(din[119]);
        BUF_X1_25->Z(S1[119]);

    BUF_X1_26 = new BUF_X1("BUF_X1_26");
        BUF_X1_26->A(din[12]);
        BUF_X1_26->Z(S1[12]);

    BUF_X1_27 = new BUF_X1("BUF_X1_27");
        BUF_X1_27->A(din[120]);
        BUF_X1_27->Z(S1[120]);

    BUF_X1_28 = new BUF_X1("BUF_X1_28");
        BUF_X1_28->A(din[121]);
        BUF_X1_28->Z(S1[121]);

    BUF_X1_29 = new BUF_X1("BUF_X1_29");
        BUF_X1_29->A(din[122]);
        BUF_X1_29->Z(S1[122]);

    BUF_X1_30 = new BUF_X1("BUF_X1_30");
        BUF_X1_30->A(din[123]);
        BUF_X1_30->Z(S1[123]);

    BUF_X1_31 = new BUF_X1("BUF_X1_31");
        BUF_X1_31->A(din[124]);
        BUF_X1_31->Z(S1[124]);

    BUF_X1_32 = new BUF_X1("BUF_X1_32");
        BUF_X1_32->A(din[125]);
        BUF_X1_32->Z(S1[125]);

    BUF_X1_33 = new BUF_X1("BUF_X1_33");
        BUF_X1_33->A(din[126]);
        BUF_X1_33->Z(S1[126]);

    BUF_X1_34 = new BUF_X1("BUF_X1_34");
        BUF_X1_34->A(din[127]);
        BUF_X1_34->Z(S1[127]);

    BUF_X1_35 = new BUF_X1("BUF_X1_35");
        BUF_X1_35->A(din[13]);
        BUF_X1_35->Z(S1[13]);

    BUF_X1_36 = new BUF_X1("BUF_X1_36");
        BUF_X1_36->A(din[14]);
        BUF_X1_36->Z(S1[14]);

    BUF_X1_37 = new BUF_X1("BUF_X1_37");
        BUF_X1_37->A(din[15]);
        BUF_X1_37->Z(S1[15]);

    BUF_X1_38 = new BUF_X1("BUF_X1_38");
        BUF_X1_38->A(din[16]);
        BUF_X1_38->Z(S1[16]);

    BUF_X1_39 = new BUF_X1("BUF_X1_39");
        BUF_X1_39->A(din[17]);
        BUF_X1_39->Z(S1[17]);

    BUF_X1_40 = new BUF_X1("BUF_X1_40");
        BUF_X1_40->A(din[18]);
        BUF_X1_40->Z(S1[18]);

    BUF_X1_41 = new BUF_X1("BUF_X1_41");
        BUF_X1_41->A(din[19]);
        BUF_X1_41->Z(S1[19]);

    BUF_X1_42 = new BUF_X1("BUF_X1_42");
        BUF_X1_42->A(din[2]);
        BUF_X1_42->Z(S1[2]);

    BUF_X1_43 = new BUF_X1("BUF_X1_43");
        BUF_X1_43->A(din[20]);
        BUF_X1_43->Z(S1[20]);

    BUF_X1_44 = new BUF_X1("BUF_X1_44");
        BUF_X1_44->A(din[21]);
        BUF_X1_44->Z(S1[21]);

    BUF_X1_45 = new BUF_X1("BUF_X1_45");
        BUF_X1_45->A(din[22]);
        BUF_X1_45->Z(S1[22]);

    BUF_X1_46 = new BUF_X1("BUF_X1_46");
        BUF_X1_46->A(din[23]);
        BUF_X1_46->Z(S1[23]);

    BUF_X1_47 = new BUF_X1("BUF_X1_47");
        BUF_X1_47->A(din[24]);
        BUF_X1_47->Z(S1[24]);

    BUF_X1_48 = new BUF_X1("BUF_X1_48");
        BUF_X1_48->A(din[25]);
        BUF_X1_48->Z(S1[25]);

    BUF_X1_49 = new BUF_X1("BUF_X1_49");
        BUF_X1_49->A(din[26]);
        BUF_X1_49->Z(S1[26]);

    BUF_X1_50 = new BUF_X1("BUF_X1_50");
        BUF_X1_50->A(din[27]);
        BUF_X1_50->Z(S1[27]);

    BUF_X1_51 = new BUF_X1("BUF_X1_51");
        BUF_X1_51->A(din[28]);
        BUF_X1_51->Z(S1[28]);

    BUF_X1_52 = new BUF_X1("BUF_X1_52");
        BUF_X1_52->A(din[29]);
        BUF_X1_52->Z(S1[29]);

    BUF_X1_53 = new BUF_X1("BUF_X1_53");
        BUF_X1_53->A(din[3]);
        BUF_X1_53->Z(S1[3]);

    BUF_X1_54 = new BUF_X1("BUF_X1_54");
        BUF_X1_54->A(din[30]);
        BUF_X1_54->Z(S1[30]);

    BUF_X1_55 = new BUF_X1("BUF_X1_55");
        BUF_X1_55->A(din[31]);
        BUF_X1_55->Z(S1[31]);

    BUF_X1_56 = new BUF_X1("BUF_X1_56");
        BUF_X1_56->A(din[32]);
        BUF_X1_56->Z(S1[32]);

    BUF_X1_57 = new BUF_X1("BUF_X1_57");
        BUF_X1_57->A(din[33]);
        BUF_X1_57->Z(S1[33]);

    BUF_X1_58 = new BUF_X1("BUF_X1_58");
        BUF_X1_58->A(din[34]);
        BUF_X1_58->Z(S1[34]);

    BUF_X1_59 = new BUF_X1("BUF_X1_59");
        BUF_X1_59->A(din[35]);
        BUF_X1_59->Z(S1[35]);

    BUF_X1_60 = new BUF_X1("BUF_X1_60");
        BUF_X1_60->A(din[36]);
        BUF_X1_60->Z(S1[36]);

    BUF_X1_61 = new BUF_X1("BUF_X1_61");
        BUF_X1_61->A(din[37]);
        BUF_X1_61->Z(S1[37]);

    BUF_X1_62 = new BUF_X1("BUF_X1_62");
        BUF_X1_62->A(din[38]);
        BUF_X1_62->Z(S1[38]);

    BUF_X1_63 = new BUF_X1("BUF_X1_63");
        BUF_X1_63->A(din[39]);
        BUF_X1_63->Z(S1[39]);

    BUF_X1_64 = new BUF_X1("BUF_X1_64");
        BUF_X1_64->A(din[4]);
        BUF_X1_64->Z(S1[4]);

    BUF_X1_65 = new BUF_X1("BUF_X1_65");
        BUF_X1_65->A(din[40]);
        BUF_X1_65->Z(S1[40]);

    BUF_X1_66 = new BUF_X1("BUF_X1_66");
        BUF_X1_66->A(din[41]);
        BUF_X1_66->Z(S1[41]);

    BUF_X1_67 = new BUF_X1("BUF_X1_67");
        BUF_X1_67->A(din[42]);
        BUF_X1_67->Z(S1[42]);

    BUF_X1_68 = new BUF_X1("BUF_X1_68");
        BUF_X1_68->A(din[43]);
        BUF_X1_68->Z(S1[43]);

    BUF_X1_69 = new BUF_X1("BUF_X1_69");
        BUF_X1_69->A(din[44]);
        BUF_X1_69->Z(S1[44]);

    BUF_X1_70 = new BUF_X1("BUF_X1_70");
        BUF_X1_70->A(din[45]);
        BUF_X1_70->Z(S1[45]);

    BUF_X1_71 = new BUF_X1("BUF_X1_71");
        BUF_X1_71->A(din[46]);
        BUF_X1_71->Z(S1[46]);

    BUF_X1_72 = new BUF_X1("BUF_X1_72");
        BUF_X1_72->A(din[47]);
        BUF_X1_72->Z(S1[47]);

    BUF_X1_73 = new BUF_X1("BUF_X1_73");
        BUF_X1_73->A(din[48]);
        BUF_X1_73->Z(S1[48]);

    BUF_X1_74 = new BUF_X1("BUF_X1_74");
        BUF_X1_74->A(din[49]);
        BUF_X1_74->Z(S1[49]);

    BUF_X1_75 = new BUF_X1("BUF_X1_75");
        BUF_X1_75->A(din[5]);
        BUF_X1_75->Z(S1[5]);

    BUF_X1_76 = new BUF_X1("BUF_X1_76");
        BUF_X1_76->A(din[50]);
        BUF_X1_76->Z(S1[50]);

    BUF_X1_77 = new BUF_X1("BUF_X1_77");
        BUF_X1_77->A(din[51]);
        BUF_X1_77->Z(S1[51]);

    BUF_X1_78 = new BUF_X1("BUF_X1_78");
        BUF_X1_78->A(din[52]);
        BUF_X1_78->Z(S1[52]);

    BUF_X1_79 = new BUF_X1("BUF_X1_79");
        BUF_X1_79->A(din[53]);
        BUF_X1_79->Z(S1[53]);

    BUF_X1_80 = new BUF_X1("BUF_X1_80");
        BUF_X1_80->A(din[54]);
        BUF_X1_80->Z(S1[54]);

    BUF_X1_81 = new BUF_X1("BUF_X1_81");
        BUF_X1_81->A(din[55]);
        BUF_X1_81->Z(S1[55]);

    BUF_X1_82 = new BUF_X1("BUF_X1_82");
        BUF_X1_82->A(din[56]);
        BUF_X1_82->Z(S1[56]);

    BUF_X1_83 = new BUF_X1("BUF_X1_83");
        BUF_X1_83->A(din[57]);
        BUF_X1_83->Z(S1[57]);

    BUF_X1_84 = new BUF_X1("BUF_X1_84");
        BUF_X1_84->A(din[58]);
        BUF_X1_84->Z(S1[58]);

    BUF_X1_85 = new BUF_X1("BUF_X1_85");
        BUF_X1_85->A(din[59]);
        BUF_X1_85->Z(S1[59]);

    BUF_X1_86 = new BUF_X1("BUF_X1_86");
        BUF_X1_86->A(din[6]);
        BUF_X1_86->Z(S1[6]);

    BUF_X1_87 = new BUF_X1("BUF_X1_87");
        BUF_X1_87->A(din[60]);
        BUF_X1_87->Z(S1[60]);

    BUF_X1_88 = new BUF_X1("BUF_X1_88");
        BUF_X1_88->A(din[61]);
        BUF_X1_88->Z(S1[61]);

    BUF_X1_89 = new BUF_X1("BUF_X1_89");
        BUF_X1_89->A(din[62]);
        BUF_X1_89->Z(S1[62]);

    BUF_X1_90 = new BUF_X1("BUF_X1_90");
        BUF_X1_90->A(din[63]);
        BUF_X1_90->Z(S1[63]);

    BUF_X1_91 = new BUF_X1("BUF_X1_91");
        BUF_X1_91->A(din[64]);
        BUF_X1_91->Z(S1[64]);

    BUF_X1_92 = new BUF_X1("BUF_X1_92");
        BUF_X1_92->A(din[65]);
        BUF_X1_92->Z(S1[65]);

    BUF_X1_93 = new BUF_X1("BUF_X1_93");
        BUF_X1_93->A(din[66]);
        BUF_X1_93->Z(S1[66]);

    BUF_X1_94 = new BUF_X1("BUF_X1_94");
        BUF_X1_94->A(din[67]);
        BUF_X1_94->Z(S1[67]);

    BUF_X1_95 = new BUF_X1("BUF_X1_95");
        BUF_X1_95->A(din[68]);
        BUF_X1_95->Z(S1[68]);

    BUF_X1_96 = new BUF_X1("BUF_X1_96");
        BUF_X1_96->A(din[69]);
        BUF_X1_96->Z(S1[69]);

    BUF_X1_97 = new BUF_X1("BUF_X1_97");
        BUF_X1_97->A(din[7]);
        BUF_X1_97->Z(S1[7]);

    BUF_X1_98 = new BUF_X1("BUF_X1_98");
        BUF_X1_98->A(din[70]);
        BUF_X1_98->Z(S1[70]);

    BUF_X1_99 = new BUF_X1("BUF_X1_99");
        BUF_X1_99->A(din[71]);
        BUF_X1_99->Z(S1[71]);

    BUF_X1_100 = new BUF_X1("BUF_X1_100");
        BUF_X1_100->A(din[72]);
        BUF_X1_100->Z(S1[72]);

    BUF_X1_101 = new BUF_X1("BUF_X1_101");
        BUF_X1_101->A(din[73]);
        BUF_X1_101->Z(S1[73]);

    BUF_X1_102 = new BUF_X1("BUF_X1_102");
        BUF_X1_102->A(din[74]);
        BUF_X1_102->Z(S1[74]);

    BUF_X1_103 = new BUF_X1("BUF_X1_103");
        BUF_X1_103->A(din[75]);
        BUF_X1_103->Z(S1[75]);

    BUF_X1_104 = new BUF_X1("BUF_X1_104");
        BUF_X1_104->A(din[76]);
        BUF_X1_104->Z(S1[76]);

    BUF_X1_105 = new BUF_X1("BUF_X1_105");
        BUF_X1_105->A(din[77]);
        BUF_X1_105->Z(S1[77]);

    BUF_X1_106 = new BUF_X1("BUF_X1_106");
        BUF_X1_106->A(din[78]);
        BUF_X1_106->Z(S1[78]);

    BUF_X1_107 = new BUF_X1("BUF_X1_107");
        BUF_X1_107->A(din[79]);
        BUF_X1_107->Z(S1[79]);

    BUF_X1_108 = new BUF_X1("BUF_X1_108");
        BUF_X1_108->A(din[8]);
        BUF_X1_108->Z(S1[8]);

    BUF_X1_109 = new BUF_X1("BUF_X1_109");
        BUF_X1_109->A(din[80]);
        BUF_X1_109->Z(S1[80]);

    BUF_X1_110 = new BUF_X1("BUF_X1_110");
        BUF_X1_110->A(din[81]);
        BUF_X1_110->Z(S1[81]);

    BUF_X1_111 = new BUF_X1("BUF_X1_111");
        BUF_X1_111->A(din[82]);
        BUF_X1_111->Z(S1[82]);

    BUF_X1_112 = new BUF_X1("BUF_X1_112");
        BUF_X1_112->A(din[83]);
        BUF_X1_112->Z(S1[83]);

    BUF_X1_113 = new BUF_X1("BUF_X1_113");
        BUF_X1_113->A(din[84]);
        BUF_X1_113->Z(S1[84]);

    BUF_X1_114 = new BUF_X1("BUF_X1_114");
        BUF_X1_114->A(din[85]);
        BUF_X1_114->Z(S1[85]);

    BUF_X1_115 = new BUF_X1("BUF_X1_115");
        BUF_X1_115->A(din[86]);
        BUF_X1_115->Z(S1[86]);

    BUF_X1_116 = new BUF_X1("BUF_X1_116");
        BUF_X1_116->A(din[87]);
        BUF_X1_116->Z(S1[87]);

    BUF_X1_117 = new BUF_X1("BUF_X1_117");
        BUF_X1_117->A(din[88]);
        BUF_X1_117->Z(S1[88]);

    BUF_X1_118 = new BUF_X1("BUF_X1_118");
        BUF_X1_118->A(din[89]);
        BUF_X1_118->Z(S1[89]);

    BUF_X1_119 = new BUF_X1("BUF_X1_119");
        BUF_X1_119->A(din[9]);
        BUF_X1_119->Z(S1[9]);

    BUF_X1_120 = new BUF_X1("BUF_X1_120");
        BUF_X1_120->A(din[90]);
        BUF_X1_120->Z(S1[90]);

    BUF_X1_121 = new BUF_X1("BUF_X1_121");
        BUF_X1_121->A(din[91]);
        BUF_X1_121->Z(S1[91]);

    BUF_X1_122 = new BUF_X1("BUF_X1_122");
        BUF_X1_122->A(din[92]);
        BUF_X1_122->Z(S1[92]);

    BUF_X1_123 = new BUF_X1("BUF_X1_123");
        BUF_X1_123->A(din[93]);
        BUF_X1_123->Z(S1[93]);

    BUF_X1_124 = new BUF_X1("BUF_X1_124");
        BUF_X1_124->A(din[94]);
        BUF_X1_124->Z(S1[94]);

    BUF_X1_125 = new BUF_X1("BUF_X1_125");
        BUF_X1_125->A(din[95]);
        BUF_X1_125->Z(S1[95]);

    BUF_X1_126 = new BUF_X1("BUF_X1_126");
        BUF_X1_126->A(din[96]);
        BUF_X1_126->Z(S1[96]);

    BUF_X1_127 = new BUF_X1("BUF_X1_127");
        BUF_X1_127->A(din[97]);
        BUF_X1_127->Z(S1[97]);

    BUF_X1_128 = new BUF_X1("BUF_X1_128");
        BUF_X1_128->A(din[98]);
        BUF_X1_128->Z(S1[98]);

    BUF_X1_129 = new BUF_X1("BUF_X1_129");
        BUF_X1_129->A(din[99]);
        BUF_X1_129->Z(S1[99]);

    BUF_X1_130 = new BUF_X1("BUF_X1_130");
        BUF_X1_130->A(S2[0]);
        BUF_X1_130->Z(dout[0]);

    BUF_X1_131 = new BUF_X1("BUF_X1_131");
        BUF_X1_131->A(S2[1]);
        BUF_X1_131->Z(dout[1]);

    BUF_X1_132 = new BUF_X1("BUF_X1_132");
        BUF_X1_132->A(S2[10]);
        BUF_X1_132->Z(dout[10]);

    BUF_X1_133 = new BUF_X1("BUF_X1_133");
        BUF_X1_133->A(S2[11]);
        BUF_X1_133->Z(dout[11]);

    BUF_X1_134 = new BUF_X1("BUF_X1_134");
        BUF_X1_134->A(S2[12]);
        BUF_X1_134->Z(dout[12]);

    BUF_X1_135 = new BUF_X1("BUF_X1_135");
        BUF_X1_135->A(S2[13]);
        BUF_X1_135->Z(dout[13]);

    BUF_X1_136 = new BUF_X1("BUF_X1_136");
        BUF_X1_136->A(S2[14]);
        BUF_X1_136->Z(dout[14]);

    BUF_X1_137 = new BUF_X1("BUF_X1_137");
        BUF_X1_137->A(S2[15]);
        BUF_X1_137->Z(dout[15]);

    BUF_X1_138 = new BUF_X1("BUF_X1_138");
        BUF_X1_138->A(S2[16]);
        BUF_X1_138->Z(dout[16]);

    BUF_X1_139 = new BUF_X1("BUF_X1_139");
        BUF_X1_139->A(S2[17]);
        BUF_X1_139->Z(dout[17]);

    BUF_X1_140 = new BUF_X1("BUF_X1_140");
        BUF_X1_140->A(S2[18]);
        BUF_X1_140->Z(dout[18]);

    BUF_X1_141 = new BUF_X1("BUF_X1_141");
        BUF_X1_141->A(S2[19]);
        BUF_X1_141->Z(dout[19]);

    BUF_X1_142 = new BUF_X1("BUF_X1_142");
        BUF_X1_142->A(S2[2]);
        BUF_X1_142->Z(dout[2]);

    BUF_X1_143 = new BUF_X1("BUF_X1_143");
        BUF_X1_143->A(S2[20]);
        BUF_X1_143->Z(dout[20]);

    BUF_X1_144 = new BUF_X1("BUF_X1_144");
        BUF_X1_144->A(S2[21]);
        BUF_X1_144->Z(dout[21]);

    BUF_X1_145 = new BUF_X1("BUF_X1_145");
        BUF_X1_145->A(S2[22]);
        BUF_X1_145->Z(dout[22]);

    BUF_X1_146 = new BUF_X1("BUF_X1_146");
        BUF_X1_146->A(S2[23]);
        BUF_X1_146->Z(dout[23]);

    BUF_X1_147 = new BUF_X1("BUF_X1_147");
        BUF_X1_147->A(S2[24]);
        BUF_X1_147->Z(dout[24]);

    BUF_X1_148 = new BUF_X1("BUF_X1_148");
        BUF_X1_148->A(S2[25]);
        BUF_X1_148->Z(dout[25]);

    BUF_X1_149 = new BUF_X1("BUF_X1_149");
        BUF_X1_149->A(S2[26]);
        BUF_X1_149->Z(dout[26]);

    BUF_X1_150 = new BUF_X1("BUF_X1_150");
        BUF_X1_150->A(S2[27]);
        BUF_X1_150->Z(dout[27]);

    BUF_X1_151 = new BUF_X1("BUF_X1_151");
        BUF_X1_151->A(S2[28]);
        BUF_X1_151->Z(dout[28]);

    BUF_X1_152 = new BUF_X1("BUF_X1_152");
        BUF_X1_152->A(S2[29]);
        BUF_X1_152->Z(dout[29]);

    BUF_X1_153 = new BUF_X1("BUF_X1_153");
        BUF_X1_153->A(S2[3]);
        BUF_X1_153->Z(dout[3]);

    BUF_X1_154 = new BUF_X1("BUF_X1_154");
        BUF_X1_154->A(S2[30]);
        BUF_X1_154->Z(dout[30]);

    BUF_X1_155 = new BUF_X1("BUF_X1_155");
        BUF_X1_155->A(S2[31]);
        BUF_X1_155->Z(dout[31]);

    BUF_X1_156 = new BUF_X1("BUF_X1_156");
        BUF_X1_156->A(S2[4]);
        BUF_X1_156->Z(dout[4]);

    BUF_X1_157 = new BUF_X1("BUF_X1_157");
        BUF_X1_157->A(S2[5]);
        BUF_X1_157->Z(dout[5]);

    BUF_X1_158 = new BUF_X1("BUF_X1_158");
        BUF_X1_158->A(S2[6]);
        BUF_X1_158->Z(dout[6]);

    BUF_X1_159 = new BUF_X1("BUF_X1_159");
        BUF_X1_159->A(S2[7]);
        BUF_X1_159->Z(dout[7]);

    BUF_X1_160 = new BUF_X1("BUF_X1_160");
        BUF_X1_160->A(S2[8]);
        BUF_X1_160->Z(dout[8]);

    BUF_X1_161 = new BUF_X1("BUF_X1_161");
        BUF_X1_161->A(S2[9]);
        BUF_X1_161->Z(dout[9]);

    BUF_X1_162 = new BUF_X1("BUF_X1_162");
        BUF_X1_162->A(S3);
        BUF_X1_162->Z(reg_out);

    BUF_X1_163 = new BUF_X1("BUF_X1_163");
        BUF_X1_163->A(rst);
        BUF_X1_163->Z(S4);

    BUF_X1_164 = new BUF_X1("BUF_X1_164");
        BUF_X1_164->A(run);
        BUF_X1_164->Z(S5);

    c_add = new add("c_add");
        c_add->add_reg(add_reg);
        c_add->clk(S0);
        c_add->din[0](doutm_0_);
        c_add->din[1](doutm_1_);
        c_add->din[2](doutm_2_);
        c_add->din[3](doutm_3_);
        c_add->din[4](doutm_4_);
        c_add->din[5](doutm_5_);
        c_add->din[6](doutm_6_);
        c_add->din[7](doutm_7_);
        c_add->din[8](doutm_8_);
        c_add->din[9](doutm_9_);
        c_add->din[10](doutm_10_);
        c_add->din[11](doutm_11_);
        c_add->din[12](doutm_12_);
        c_add->din[13](doutm_13_);
        c_add->din[14](doutm_14_);
        c_add->din[15](doutm_15_);
        c_add->din[16](doutm_16_);
        c_add->din[17](doutm_17_);
        c_add->din[18](doutm_18_);
        c_add->din[19](doutm_19_);
        c_add->din[20](doutm_20_);
        c_add->din[21](doutm_21_);
        c_add->din[22](doutm_22_);
        c_add->din[23](doutm_23_);
        c_add->din[24](doutm_24_);
        c_add->din[25](doutm_25_);
        c_add->din[26](doutm_26_);
        c_add->din[27](doutm_27_);
        c_add->din[28](doutm_28_);
        c_add->din[29](doutm_29_);
        c_add->din[30](doutm_30_);
        c_add->din[31](doutm_31_);
        c_add->dout[0](S2[0]);
        c_add->dout[1](S2[1]);
        c_add->dout[2](S2[2]);
        c_add->dout[3](S2[3]);
        c_add->dout[4](S2[4]);
        c_add->dout[5](S2[5]);
        c_add->dout[6](S2[6]);
        c_add->dout[7](S2[7]);
        c_add->dout[8](S2[8]);
        c_add->dout[9](S2[9]);
        c_add->dout[10](S2[10]);
        c_add->dout[11](S2[11]);
        c_add->dout[12](S2[12]);
        c_add->dout[13](S2[13]);
        c_add->dout[14](S2[14]);
        c_add->dout[15](S2[15]);
        c_add->dout[16](S2[16]);
        c_add->dout[17](S2[17]);
        c_add->dout[18](S2[18]);
        c_add->dout[19](S2[19]);
        c_add->dout[20](S2[20]);
        c_add->dout[21](S2[21]);
        c_add->dout[22](S2[22]);
        c_add->dout[23](S2[23]);
        c_add->dout[24](S2[24]);
        c_add->dout[25](S2[25]);
        c_add->dout[26](S2[26]);
        c_add->dout[27](S2[27]);
        c_add->dout[28](S2[28]);
        c_add->dout[29](S2[29]);
        c_add->dout[30](S2[30]);
        c_add->dout[31](S2[31]);
        c_add->in_reg(c_add_ctrl_129);
        c_add->reg_out(S3);

    c_add_ctrl = new cap_controller("c_add_ctrl");
        c_add_ctrl->add_reg(add_reg);
        c_add_ctrl->clk(S0);
        c_add_ctrl->count[0](sc_logic_0_signal);
        c_add_ctrl->count[1](sc_logic_0_signal);
        c_add_ctrl->count[2](sc_logic_1_signal);
        c_add_ctrl->count[3](sc_logic_0_signal);
        c_add_ctrl->in_reg(c_add_ctrl_129);
        c_add_ctrl->out_reg(S3);
        c_add_ctrl->rst(S4);
        c_add_ctrl->run(S5);
        c_add_ctrl->sel[0](c_add_ctrl_128_0_);
        c_add_ctrl->sel[1](c_add_ctrl_128_1_);
        c_add_ctrl->sel[2](c_add_ctrl_128_2_);
        c_add_ctrl->sel[3](c_add_ctrl_128_3_);

    mux = new mux_cascading("mux");
        mux->din[0](S1[0]);
        mux->din[1](S1[1]);
        mux->din[2](S1[2]);
        mux->din[3](S1[3]);
        mux->din[4](S1[4]);
        mux->din[5](S1[5]);
        mux->din[6](S1[6]);
        mux->din[7](S1[7]);
        mux->din[8](S1[8]);
        mux->din[9](S1[9]);
        mux->din[10](S1[10]);
        mux->din[11](S1[11]);
        mux->din[12](S1[12]);
        mux->din[13](S1[13]);
        mux->din[14](S1[14]);
        mux->din[15](S1[15]);
        mux->din[16](S1[16]);
        mux->din[17](S1[17]);
        mux->din[18](S1[18]);
        mux->din[19](S1[19]);
        mux->din[20](S1[20]);
        mux->din[21](S1[21]);
        mux->din[22](S1[22]);
        mux->din[23](S1[23]);
        mux->din[24](S1[24]);
        mux->din[25](S1[25]);
        mux->din[26](S1[26]);
        mux->din[27](S1[27]);
        mux->din[28](S1[28]);
        mux->din[29](S1[29]);
        mux->din[30](S1[30]);
        mux->din[31](S1[31]);
        mux->din[32](S1[32]);
        mux->din[33](S1[33]);
        mux->din[34](S1[34]);
        mux->din[35](S1[35]);
        mux->din[36](S1[36]);
        mux->din[37](S1[37]);
        mux->din[38](S1[38]);
        mux->din[39](S1[39]);
        mux->din[40](S1[40]);
        mux->din[41](S1[41]);
        mux->din[42](S1[42]);
        mux->din[43](S1[43]);
        mux->din[44](S1[44]);
        mux->din[45](S1[45]);
        mux->din[46](S1[46]);
        mux->din[47](S1[47]);
        mux->din[48](S1[48]);
        mux->din[49](S1[49]);
        mux->din[50](S1[50]);
        mux->din[51](S1[51]);
        mux->din[52](S1[52]);
        mux->din[53](S1[53]);
        mux->din[54](S1[54]);
        mux->din[55](S1[55]);
        mux->din[56](S1[56]);
        mux->din[57](S1[57]);
        mux->din[58](S1[58]);
        mux->din[59](S1[59]);
        mux->din[60](S1[60]);
        mux->din[61](S1[61]);
        mux->din[62](S1[62]);
        mux->din[63](S1[63]);
        mux->din[64](S1[64]);
        mux->din[65](S1[65]);
        mux->din[66](S1[66]);
        mux->din[67](S1[67]);
        mux->din[68](S1[68]);
        mux->din[69](S1[69]);
        mux->din[70](S1[70]);
        mux->din[71](S1[71]);
        mux->din[72](S1[72]);
        mux->din[73](S1[73]);
        mux->din[74](S1[74]);
        mux->din[75](S1[75]);
        mux->din[76](S1[76]);
        mux->din[77](S1[77]);
        mux->din[78](S1[78]);
        mux->din[79](S1[79]);
        mux->din[80](S1[80]);
        mux->din[81](S1[81]);
        mux->din[82](S1[82]);
        mux->din[83](S1[83]);
        mux->din[84](S1[84]);
        mux->din[85](S1[85]);
        mux->din[86](S1[86]);
        mux->din[87](S1[87]);
        mux->din[88](S1[88]);
        mux->din[89](S1[89]);
        mux->din[90](S1[90]);
        mux->din[91](S1[91]);
        mux->din[92](S1[92]);
        mux->din[93](S1[93]);
        mux->din[94](S1[94]);
        mux->din[95](S1[95]);
        mux->din[96](S1[96]);
        mux->din[97](S1[97]);
        mux->din[98](S1[98]);
        mux->din[99](S1[99]);
        mux->din[100](S1[100]);
        mux->din[101](S1[101]);
        mux->din[102](S1[102]);
        mux->din[103](S1[103]);
        mux->din[104](S1[104]);
        mux->din[105](S1[105]);
        mux->din[106](S1[106]);
        mux->din[107](S1[107]);
        mux->din[108](S1[108]);
        mux->din[109](S1[109]);
        mux->din[110](S1[110]);
        mux->din[111](S1[111]);
        mux->din[112](S1[112]);
        mux->din[113](S1[113]);
        mux->din[114](S1[114]);
        mux->din[115](S1[115]);
        mux->din[116](S1[116]);
        mux->din[117](S1[117]);
        mux->din[118](S1[118]);
        mux->din[119](S1[119]);
        mux->din[120](S1[120]);
        mux->din[121](S1[121]);
        mux->din[122](S1[122]);
        mux->din[123](S1[123]);
        mux->din[124](S1[124]);
        mux->din[125](S1[125]);
        mux->din[126](S1[126]);
        mux->din[127](S1[127]);
        mux->din[128](sc_logic_0_signal);
        mux->din[129](sc_logic_0_signal);
        mux->din[130](sc_logic_0_signal);
        mux->din[131](sc_logic_0_signal);
        mux->din[132](sc_logic_0_signal);
        mux->din[133](sc_logic_0_signal);
        mux->din[134](sc_logic_0_signal);
        mux->din[135](sc_logic_0_signal);
        mux->din[136](sc_logic_0_signal);
        mux->din[137](sc_logic_0_signal);
        mux->din[138](sc_logic_0_signal);
        mux->din[139](sc_logic_0_signal);
        mux->din[140](sc_logic_0_signal);
        mux->din[141](sc_logic_0_signal);
        mux->din[142](sc_logic_0_signal);
        mux->din[143](sc_logic_0_signal);
        mux->din[144](sc_logic_0_signal);
        mux->din[145](sc_logic_0_signal);
        mux->din[146](sc_logic_0_signal);
        mux->din[147](sc_logic_0_signal);
        mux->din[148](sc_logic_0_signal);
        mux->din[149](sc_logic_0_signal);
        mux->din[150](sc_logic_0_signal);
        mux->din[151](sc_logic_0_signal);
        mux->din[152](sc_logic_0_signal);
        mux->din[153](sc_logic_0_signal);
        mux->din[154](sc_logic_0_signal);
        mux->din[155](sc_logic_0_signal);
        mux->din[156](sc_logic_0_signal);
        mux->din[157](sc_logic_0_signal);
        mux->din[158](sc_logic_0_signal);
        mux->din[159](sc_logic_0_signal);
        mux->din[160](sc_logic_0_signal);
        mux->din[161](sc_logic_0_signal);
        mux->din[162](sc_logic_0_signal);
        mux->din[163](sc_logic_0_signal);
        mux->din[164](sc_logic_0_signal);
        mux->din[165](sc_logic_0_signal);
        mux->din[166](sc_logic_0_signal);
        mux->din[167](sc_logic_0_signal);
        mux->din[168](sc_logic_0_signal);
        mux->din[169](sc_logic_0_signal);
        mux->din[170](sc_logic_0_signal);
        mux->din[171](sc_logic_0_signal);
        mux->din[172](sc_logic_0_signal);
        mux->din[173](sc_logic_0_signal);
        mux->din[174](sc_logic_0_signal);
        mux->din[175](sc_logic_0_signal);
        mux->din[176](sc_logic_0_signal);
        mux->din[177](sc_logic_0_signal);
        mux->din[178](sc_logic_0_signal);
        mux->din[179](sc_logic_0_signal);
        mux->din[180](sc_logic_0_signal);
        mux->din[181](sc_logic_0_signal);
        mux->din[182](sc_logic_0_signal);
        mux->din[183](sc_logic_0_signal);
        mux->din[184](sc_logic_0_signal);
        mux->din[185](sc_logic_0_signal);
        mux->din[186](sc_logic_0_signal);
        mux->din[187](sc_logic_0_signal);
        mux->din[188](sc_logic_0_signal);
        mux->din[189](sc_logic_0_signal);
        mux->din[190](sc_logic_0_signal);
        mux->din[191](sc_logic_0_signal);
        mux->din[192](sc_logic_0_signal);
        mux->din[193](sc_logic_0_signal);
        mux->din[194](sc_logic_0_signal);
        mux->din[195](sc_logic_0_signal);
        mux->din[196](sc_logic_0_signal);
        mux->din[197](sc_logic_0_signal);
        mux->din[198](sc_logic_0_signal);
        mux->din[199](sc_logic_0_signal);
        mux->din[200](sc_logic_0_signal);
        mux->din[201](sc_logic_0_signal);
        mux->din[202](sc_logic_0_signal);
        mux->din[203](sc_logic_0_signal);
        mux->din[204](sc_logic_0_signal);
        mux->din[205](sc_logic_0_signal);
        mux->din[206](sc_logic_0_signal);
        mux->din[207](sc_logic_0_signal);
        mux->din[208](sc_logic_0_signal);
        mux->din[209](sc_logic_0_signal);
        mux->din[210](sc_logic_0_signal);
        mux->din[211](sc_logic_0_signal);
        mux->din[212](sc_logic_0_signal);
        mux->din[213](sc_logic_0_signal);
        mux->din[214](sc_logic_0_signal);
        mux->din[215](sc_logic_0_signal);
        mux->din[216](sc_logic_0_signal);
        mux->din[217](sc_logic_0_signal);
        mux->din[218](sc_logic_0_signal);
        mux->din[219](sc_logic_0_signal);
        mux->din[220](sc_logic_0_signal);
        mux->din[221](sc_logic_0_signal);
        mux->din[222](sc_logic_0_signal);
        mux->din[223](sc_logic_0_signal);
        mux->din[224](sc_logic_0_signal);
        mux->din[225](sc_logic_0_signal);
        mux->din[226](sc_logic_0_signal);
        mux->din[227](sc_logic_0_signal);
        mux->din[228](sc_logic_0_signal);
        mux->din[229](sc_logic_0_signal);
        mux->din[230](sc_logic_0_signal);
        mux->din[231](sc_logic_0_signal);
        mux->din[232](sc_logic_0_signal);
        mux->din[233](sc_logic_0_signal);
        mux->din[234](sc_logic_0_signal);
        mux->din[235](sc_logic_0_signal);
        mux->din[236](sc_logic_0_signal);
        mux->din[237](sc_logic_0_signal);
        mux->din[238](sc_logic_0_signal);
        mux->din[239](sc_logic_0_signal);
        mux->din[240](sc_logic_0_signal);
        mux->din[241](sc_logic_0_signal);
        mux->din[242](sc_logic_0_signal);
        mux->din[243](sc_logic_0_signal);
        mux->din[244](sc_logic_0_signal);
        mux->din[245](sc_logic_0_signal);
        mux->din[246](sc_logic_0_signal);
        mux->din[247](sc_logic_0_signal);
        mux->din[248](sc_logic_0_signal);
        mux->din[249](sc_logic_0_signal);
        mux->din[250](sc_logic_0_signal);
        mux->din[251](sc_logic_0_signal);
        mux->din[252](sc_logic_0_signal);
        mux->din[253](sc_logic_0_signal);
        mux->din[254](sc_logic_0_signal);
        mux->din[255](sc_logic_0_signal);
        mux->din[256](sc_logic_0_signal);
        mux->din[257](sc_logic_0_signal);
        mux->din[258](sc_logic_0_signal);
        mux->din[259](sc_logic_0_signal);
        mux->din[260](sc_logic_0_signal);
        mux->din[261](sc_logic_0_signal);
        mux->din[262](sc_logic_0_signal);
        mux->din[263](sc_logic_0_signal);
        mux->din[264](sc_logic_0_signal);
        mux->din[265](sc_logic_0_signal);
        mux->din[266](sc_logic_0_signal);
        mux->din[267](sc_logic_0_signal);
        mux->din[268](sc_logic_0_signal);
        mux->din[269](sc_logic_0_signal);
        mux->din[270](sc_logic_0_signal);
        mux->din[271](sc_logic_0_signal);
        mux->din[272](sc_logic_0_signal);
        mux->din[273](sc_logic_0_signal);
        mux->din[274](sc_logic_0_signal);
        mux->din[275](sc_logic_0_signal);
        mux->din[276](sc_logic_0_signal);
        mux->din[277](sc_logic_0_signal);
        mux->din[278](sc_logic_0_signal);
        mux->din[279](sc_logic_0_signal);
        mux->din[280](sc_logic_0_signal);
        mux->din[281](sc_logic_0_signal);
        mux->din[282](sc_logic_0_signal);
        mux->din[283](sc_logic_0_signal);
        mux->din[284](sc_logic_0_signal);
        mux->din[285](sc_logic_0_signal);
        mux->din[286](sc_logic_0_signal);
        mux->din[287](sc_logic_0_signal);
        mux->din[288](sc_logic_0_signal);
        mux->din[289](sc_logic_0_signal);
        mux->din[290](sc_logic_0_signal);
        mux->din[291](sc_logic_0_signal);
        mux->din[292](sc_logic_0_signal);
        mux->din[293](sc_logic_0_signal);
        mux->din[294](sc_logic_0_signal);
        mux->din[295](sc_logic_0_signal);
        mux->din[296](sc_logic_0_signal);
        mux->din[297](sc_logic_0_signal);
        mux->din[298](sc_logic_0_signal);
        mux->din[299](sc_logic_0_signal);
        mux->din[300](sc_logic_0_signal);
        mux->din[301](sc_logic_0_signal);
        mux->din[302](sc_logic_0_signal);
        mux->din[303](sc_logic_0_signal);
        mux->din[304](sc_logic_0_signal);
        mux->din[305](sc_logic_0_signal);
        mux->din[306](sc_logic_0_signal);
        mux->din[307](sc_logic_0_signal);
        mux->din[308](sc_logic_0_signal);
        mux->din[309](sc_logic_0_signal);
        mux->din[310](sc_logic_0_signal);
        mux->din[311](sc_logic_0_signal);
        mux->din[312](sc_logic_0_signal);
        mux->din[313](sc_logic_0_signal);
        mux->din[314](sc_logic_0_signal);
        mux->din[315](sc_logic_0_signal);
        mux->din[316](sc_logic_0_signal);
        mux->din[317](sc_logic_0_signal);
        mux->din[318](sc_logic_0_signal);
        mux->din[319](sc_logic_0_signal);
        mux->din[320](sc_logic_0_signal);
        mux->din[321](sc_logic_0_signal);
        mux->din[322](sc_logic_0_signal);
        mux->din[323](sc_logic_0_signal);
        mux->din[324](sc_logic_0_signal);
        mux->din[325](sc_logic_0_signal);
        mux->din[326](sc_logic_0_signal);
        mux->din[327](sc_logic_0_signal);
        mux->din[328](sc_logic_0_signal);
        mux->din[329](sc_logic_0_signal);
        mux->din[330](sc_logic_0_signal);
        mux->din[331](sc_logic_0_signal);
        mux->din[332](sc_logic_0_signal);
        mux->din[333](sc_logic_0_signal);
        mux->din[334](sc_logic_0_signal);
        mux->din[335](sc_logic_0_signal);
        mux->din[336](sc_logic_0_signal);
        mux->din[337](sc_logic_0_signal);
        mux->din[338](sc_logic_0_signal);
        mux->din[339](sc_logic_0_signal);
        mux->din[340](sc_logic_0_signal);
        mux->din[341](sc_logic_0_signal);
        mux->din[342](sc_logic_0_signal);
        mux->din[343](sc_logic_0_signal);
        mux->din[344](sc_logic_0_signal);
        mux->din[345](sc_logic_0_signal);
        mux->din[346](sc_logic_0_signal);
        mux->din[347](sc_logic_0_signal);
        mux->din[348](sc_logic_0_signal);
        mux->din[349](sc_logic_0_signal);
        mux->din[350](sc_logic_0_signal);
        mux->din[351](sc_logic_0_signal);
        mux->din[352](sc_logic_0_signal);
        mux->din[353](sc_logic_0_signal);
        mux->din[354](sc_logic_0_signal);
        mux->din[355](sc_logic_0_signal);
        mux->din[356](sc_logic_0_signal);
        mux->din[357](sc_logic_0_signal);
        mux->din[358](sc_logic_0_signal);
        mux->din[359](sc_logic_0_signal);
        mux->din[360](sc_logic_0_signal);
        mux->din[361](sc_logic_0_signal);
        mux->din[362](sc_logic_0_signal);
        mux->din[363](sc_logic_0_signal);
        mux->din[364](sc_logic_0_signal);
        mux->din[365](sc_logic_0_signal);
        mux->din[366](sc_logic_0_signal);
        mux->din[367](sc_logic_0_signal);
        mux->din[368](sc_logic_0_signal);
        mux->din[369](sc_logic_0_signal);
        mux->din[370](sc_logic_0_signal);
        mux->din[371](sc_logic_0_signal);
        mux->din[372](sc_logic_0_signal);
        mux->din[373](sc_logic_0_signal);
        mux->din[374](sc_logic_0_signal);
        mux->din[375](sc_logic_0_signal);
        mux->din[376](sc_logic_0_signal);
        mux->din[377](sc_logic_0_signal);
        mux->din[378](sc_logic_0_signal);
        mux->din[379](sc_logic_0_signal);
        mux->din[380](sc_logic_0_signal);
        mux->din[381](sc_logic_0_signal);
        mux->din[382](sc_logic_0_signal);
        mux->din[383](sc_logic_0_signal);
        mux->din[384](sc_logic_0_signal);
        mux->din[385](sc_logic_0_signal);
        mux->din[386](sc_logic_0_signal);
        mux->din[387](sc_logic_0_signal);
        mux->din[388](sc_logic_0_signal);
        mux->din[389](sc_logic_0_signal);
        mux->din[390](sc_logic_0_signal);
        mux->din[391](sc_logic_0_signal);
        mux->din[392](sc_logic_0_signal);
        mux->din[393](sc_logic_0_signal);
        mux->din[394](sc_logic_0_signal);
        mux->din[395](sc_logic_0_signal);
        mux->din[396](sc_logic_0_signal);
        mux->din[397](sc_logic_0_signal);
        mux->din[398](sc_logic_0_signal);
        mux->din[399](sc_logic_0_signal);
        mux->din[400](sc_logic_0_signal);
        mux->din[401](sc_logic_0_signal);
        mux->din[402](sc_logic_0_signal);
        mux->din[403](sc_logic_0_signal);
        mux->din[404](sc_logic_0_signal);
        mux->din[405](sc_logic_0_signal);
        mux->din[406](sc_logic_0_signal);
        mux->din[407](sc_logic_0_signal);
        mux->din[408](sc_logic_0_signal);
        mux->din[409](sc_logic_0_signal);
        mux->din[410](sc_logic_0_signal);
        mux->din[411](sc_logic_0_signal);
        mux->din[412](sc_logic_0_signal);
        mux->din[413](sc_logic_0_signal);
        mux->din[414](sc_logic_0_signal);
        mux->din[415](sc_logic_0_signal);
        mux->din[416](sc_logic_0_signal);
        mux->din[417](sc_logic_0_signal);
        mux->din[418](sc_logic_0_signal);
        mux->din[419](sc_logic_0_signal);
        mux->din[420](sc_logic_0_signal);
        mux->din[421](sc_logic_0_signal);
        mux->din[422](sc_logic_0_signal);
        mux->din[423](sc_logic_0_signal);
        mux->din[424](sc_logic_0_signal);
        mux->din[425](sc_logic_0_signal);
        mux->din[426](sc_logic_0_signal);
        mux->din[427](sc_logic_0_signal);
        mux->din[428](sc_logic_0_signal);
        mux->din[429](sc_logic_0_signal);
        mux->din[430](sc_logic_0_signal);
        mux->din[431](sc_logic_0_signal);
        mux->din[432](sc_logic_0_signal);
        mux->din[433](sc_logic_0_signal);
        mux->din[434](sc_logic_0_signal);
        mux->din[435](sc_logic_0_signal);
        mux->din[436](sc_logic_0_signal);
        mux->din[437](sc_logic_0_signal);
        mux->din[438](sc_logic_0_signal);
        mux->din[439](sc_logic_0_signal);
        mux->din[440](sc_logic_0_signal);
        mux->din[441](sc_logic_0_signal);
        mux->din[442](sc_logic_0_signal);
        mux->din[443](sc_logic_0_signal);
        mux->din[444](sc_logic_0_signal);
        mux->din[445](sc_logic_0_signal);
        mux->din[446](sc_logic_0_signal);
        mux->din[447](sc_logic_0_signal);
        mux->din[448](sc_logic_0_signal);
        mux->din[449](sc_logic_0_signal);
        mux->din[450](sc_logic_0_signal);
        mux->din[451](sc_logic_0_signal);
        mux->din[452](sc_logic_0_signal);
        mux->din[453](sc_logic_0_signal);
        mux->din[454](sc_logic_0_signal);
        mux->din[455](sc_logic_0_signal);
        mux->din[456](sc_logic_0_signal);
        mux->din[457](sc_logic_0_signal);
        mux->din[458](sc_logic_0_signal);
        mux->din[459](sc_logic_0_signal);
        mux->din[460](sc_logic_0_signal);
        mux->din[461](sc_logic_0_signal);
        mux->din[462](sc_logic_0_signal);
        mux->din[463](sc_logic_0_signal);
        mux->din[464](sc_logic_0_signal);
        mux->din[465](sc_logic_0_signal);
        mux->din[466](sc_logic_0_signal);
        mux->din[467](sc_logic_0_signal);
        mux->din[468](sc_logic_0_signal);
        mux->din[469](sc_logic_0_signal);
        mux->din[470](sc_logic_0_signal);
        mux->din[471](sc_logic_0_signal);
        mux->din[472](sc_logic_0_signal);
        mux->din[473](sc_logic_0_signal);
        mux->din[474](sc_logic_0_signal);
        mux->din[475](sc_logic_0_signal);
        mux->din[476](sc_logic_0_signal);
        mux->din[477](sc_logic_0_signal);
        mux->din[478](sc_logic_0_signal);
        mux->din[479](sc_logic_0_signal);
        mux->din[480](sc_logic_0_signal);
        mux->din[481](sc_logic_0_signal);
        mux->din[482](sc_logic_0_signal);
        mux->din[483](sc_logic_0_signal);
        mux->din[484](sc_logic_0_signal);
        mux->din[485](sc_logic_0_signal);
        mux->din[486](sc_logic_0_signal);
        mux->din[487](sc_logic_0_signal);
        mux->din[488](sc_logic_0_signal);
        mux->din[489](sc_logic_0_signal);
        mux->din[490](sc_logic_0_signal);
        mux->din[491](sc_logic_0_signal);
        mux->din[492](sc_logic_0_signal);
        mux->din[493](sc_logic_0_signal);
        mux->din[494](sc_logic_0_signal);
        mux->din[495](sc_logic_0_signal);
        mux->din[496](sc_logic_0_signal);
        mux->din[497](sc_logic_0_signal);
        mux->din[498](sc_logic_0_signal);
        mux->din[499](sc_logic_0_signal);
        mux->din[500](sc_logic_0_signal);
        mux->din[501](sc_logic_0_signal);
        mux->din[502](sc_logic_0_signal);
        mux->din[503](sc_logic_0_signal);
        mux->din[504](sc_logic_0_signal);
        mux->din[505](sc_logic_0_signal);
        mux->din[506](sc_logic_0_signal);
        mux->din[507](sc_logic_0_signal);
        mux->din[508](sc_logic_0_signal);
        mux->din[509](sc_logic_0_signal);
        mux->din[510](sc_logic_0_signal);
        mux->din[511](sc_logic_0_signal);
        mux->dout[0](doutm_0_);
        mux->dout[1](doutm_1_);
        mux->dout[2](doutm_2_);
        mux->dout[3](doutm_3_);
        mux->dout[4](doutm_4_);
        mux->dout[5](doutm_5_);
        mux->dout[6](doutm_6_);
        mux->dout[7](doutm_7_);
        mux->dout[8](doutm_8_);
        mux->dout[9](doutm_9_);
        mux->dout[10](doutm_10_);
        mux->dout[11](doutm_11_);
        mux->dout[12](doutm_12_);
        mux->dout[13](doutm_13_);
        mux->dout[14](doutm_14_);
        mux->dout[15](doutm_15_);
        mux->dout[16](doutm_16_);
        mux->dout[17](doutm_17_);
        mux->dout[18](doutm_18_);
        mux->dout[19](doutm_19_);
        mux->dout[20](doutm_20_);
        mux->dout[21](doutm_21_);
        mux->dout[22](doutm_22_);
        mux->dout[23](doutm_23_);
        mux->dout[24](doutm_24_);
        mux->dout[25](doutm_25_);
        mux->dout[26](doutm_26_);
        mux->dout[27](doutm_27_);
        mux->dout[28](doutm_28_);
        mux->dout[29](doutm_29_);
        mux->dout[30](doutm_30_);
        mux->dout[31](doutm_31_);
        mux->sel[0](c_add_ctrl_128_0_);
        mux->sel[1](c_add_ctrl_128_1_);
        mux->sel[2](c_add_ctrl_128_2_);
        mux->sel[3](c_add_ctrl_128_3_);


    SC_METHOD(sc_logic_signal_assignment);

    }

    void sc_logic_signal_assignment(void){ 
        sc_logic_1_signal.write(SC_LOGIC_1);
        sc_logic_0_signal.write(SC_LOGIC_0);
    }
};
#endif /* __CONVERGENCE_ACCUMULATOR_PLATE_4_H__ */

