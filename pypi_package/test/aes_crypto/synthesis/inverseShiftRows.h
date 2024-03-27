#include <systemc.h>
#include "Complex_NAgate_45.h"



#ifndef __INVERSESHIFTROWS_H__
#define __INVERSESHIFTROWS_H__
using namespace sc_core;

SC_MODULE( inverseShiftRows ) {

    sc_in<sc_logic> in[128];
    sc_out<sc_logic> shifted[128];

    sc_signal<sc_logic> sc_logic_1_signal;
    sc_signal<sc_logic> sc_logic_0_signal;

    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S0[128];

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

SC_CTOR( inverseShiftRows ) {
    BUF_X1_1 = new BUF_X1("BUF_X1_1");
        BUF_X1_1->A(in[0]);
        BUF_X1_1->Z(S0[0]);

    BUF_X1_2 = new BUF_X1("BUF_X1_2");
        BUF_X1_2->A(in[1]);
        BUF_X1_2->Z(S0[1]);

    BUF_X1_3 = new BUF_X1("BUF_X1_3");
        BUF_X1_3->A(in[10]);
        BUF_X1_3->Z(S0[10]);

    BUF_X1_4 = new BUF_X1("BUF_X1_4");
        BUF_X1_4->A(in[100]);
        BUF_X1_4->Z(S0[100]);

    BUF_X1_5 = new BUF_X1("BUF_X1_5");
        BUF_X1_5->A(in[101]);
        BUF_X1_5->Z(S0[101]);

    BUF_X1_6 = new BUF_X1("BUF_X1_6");
        BUF_X1_6->A(in[102]);
        BUF_X1_6->Z(S0[102]);

    BUF_X1_7 = new BUF_X1("BUF_X1_7");
        BUF_X1_7->A(in[103]);
        BUF_X1_7->Z(S0[103]);

    BUF_X1_8 = new BUF_X1("BUF_X1_8");
        BUF_X1_8->A(in[104]);
        BUF_X1_8->Z(S0[104]);

    BUF_X1_9 = new BUF_X1("BUF_X1_9");
        BUF_X1_9->A(in[105]);
        BUF_X1_9->Z(S0[105]);

    BUF_X1_10 = new BUF_X1("BUF_X1_10");
        BUF_X1_10->A(in[106]);
        BUF_X1_10->Z(S0[106]);

    BUF_X1_11 = new BUF_X1("BUF_X1_11");
        BUF_X1_11->A(in[107]);
        BUF_X1_11->Z(S0[107]);

    BUF_X1_12 = new BUF_X1("BUF_X1_12");
        BUF_X1_12->A(in[108]);
        BUF_X1_12->Z(S0[108]);

    BUF_X1_13 = new BUF_X1("BUF_X1_13");
        BUF_X1_13->A(in[109]);
        BUF_X1_13->Z(S0[109]);

    BUF_X1_14 = new BUF_X1("BUF_X1_14");
        BUF_X1_14->A(in[11]);
        BUF_X1_14->Z(S0[11]);

    BUF_X1_15 = new BUF_X1("BUF_X1_15");
        BUF_X1_15->A(in[110]);
        BUF_X1_15->Z(S0[110]);

    BUF_X1_16 = new BUF_X1("BUF_X1_16");
        BUF_X1_16->A(in[111]);
        BUF_X1_16->Z(S0[111]);

    BUF_X1_17 = new BUF_X1("BUF_X1_17");
        BUF_X1_17->A(in[112]);
        BUF_X1_17->Z(S0[112]);

    BUF_X1_18 = new BUF_X1("BUF_X1_18");
        BUF_X1_18->A(in[113]);
        BUF_X1_18->Z(S0[113]);

    BUF_X1_19 = new BUF_X1("BUF_X1_19");
        BUF_X1_19->A(in[114]);
        BUF_X1_19->Z(S0[114]);

    BUF_X1_20 = new BUF_X1("BUF_X1_20");
        BUF_X1_20->A(in[115]);
        BUF_X1_20->Z(S0[115]);

    BUF_X1_21 = new BUF_X1("BUF_X1_21");
        BUF_X1_21->A(in[116]);
        BUF_X1_21->Z(S0[116]);

    BUF_X1_22 = new BUF_X1("BUF_X1_22");
        BUF_X1_22->A(in[117]);
        BUF_X1_22->Z(S0[117]);

    BUF_X1_23 = new BUF_X1("BUF_X1_23");
        BUF_X1_23->A(in[118]);
        BUF_X1_23->Z(S0[118]);

    BUF_X1_24 = new BUF_X1("BUF_X1_24");
        BUF_X1_24->A(in[119]);
        BUF_X1_24->Z(S0[119]);

    BUF_X1_25 = new BUF_X1("BUF_X1_25");
        BUF_X1_25->A(in[12]);
        BUF_X1_25->Z(S0[12]);

    BUF_X1_26 = new BUF_X1("BUF_X1_26");
        BUF_X1_26->A(in[120]);
        BUF_X1_26->Z(S0[120]);

    BUF_X1_27 = new BUF_X1("BUF_X1_27");
        BUF_X1_27->A(in[121]);
        BUF_X1_27->Z(S0[121]);

    BUF_X1_28 = new BUF_X1("BUF_X1_28");
        BUF_X1_28->A(in[122]);
        BUF_X1_28->Z(S0[122]);

    BUF_X1_29 = new BUF_X1("BUF_X1_29");
        BUF_X1_29->A(in[123]);
        BUF_X1_29->Z(S0[123]);

    BUF_X1_30 = new BUF_X1("BUF_X1_30");
        BUF_X1_30->A(in[124]);
        BUF_X1_30->Z(S0[124]);

    BUF_X1_31 = new BUF_X1("BUF_X1_31");
        BUF_X1_31->A(in[125]);
        BUF_X1_31->Z(S0[125]);

    BUF_X1_32 = new BUF_X1("BUF_X1_32");
        BUF_X1_32->A(in[126]);
        BUF_X1_32->Z(S0[126]);

    BUF_X1_33 = new BUF_X1("BUF_X1_33");
        BUF_X1_33->A(in[127]);
        BUF_X1_33->Z(S0[127]);

    BUF_X1_34 = new BUF_X1("BUF_X1_34");
        BUF_X1_34->A(in[13]);
        BUF_X1_34->Z(S0[13]);

    BUF_X1_35 = new BUF_X1("BUF_X1_35");
        BUF_X1_35->A(in[14]);
        BUF_X1_35->Z(S0[14]);

    BUF_X1_36 = new BUF_X1("BUF_X1_36");
        BUF_X1_36->A(in[15]);
        BUF_X1_36->Z(S0[15]);

    BUF_X1_37 = new BUF_X1("BUF_X1_37");
        BUF_X1_37->A(in[16]);
        BUF_X1_37->Z(S0[16]);

    BUF_X1_38 = new BUF_X1("BUF_X1_38");
        BUF_X1_38->A(in[17]);
        BUF_X1_38->Z(S0[17]);

    BUF_X1_39 = new BUF_X1("BUF_X1_39");
        BUF_X1_39->A(in[18]);
        BUF_X1_39->Z(S0[18]);

    BUF_X1_40 = new BUF_X1("BUF_X1_40");
        BUF_X1_40->A(in[19]);
        BUF_X1_40->Z(S0[19]);

    BUF_X1_41 = new BUF_X1("BUF_X1_41");
        BUF_X1_41->A(in[2]);
        BUF_X1_41->Z(S0[2]);

    BUF_X1_42 = new BUF_X1("BUF_X1_42");
        BUF_X1_42->A(in[20]);
        BUF_X1_42->Z(S0[20]);

    BUF_X1_43 = new BUF_X1("BUF_X1_43");
        BUF_X1_43->A(in[21]);
        BUF_X1_43->Z(S0[21]);

    BUF_X1_44 = new BUF_X1("BUF_X1_44");
        BUF_X1_44->A(in[22]);
        BUF_X1_44->Z(S0[22]);

    BUF_X1_45 = new BUF_X1("BUF_X1_45");
        BUF_X1_45->A(in[23]);
        BUF_X1_45->Z(S0[23]);

    BUF_X1_46 = new BUF_X1("BUF_X1_46");
        BUF_X1_46->A(in[24]);
        BUF_X1_46->Z(S0[24]);

    BUF_X1_47 = new BUF_X1("BUF_X1_47");
        BUF_X1_47->A(in[25]);
        BUF_X1_47->Z(S0[25]);

    BUF_X1_48 = new BUF_X1("BUF_X1_48");
        BUF_X1_48->A(in[26]);
        BUF_X1_48->Z(S0[26]);

    BUF_X1_49 = new BUF_X1("BUF_X1_49");
        BUF_X1_49->A(in[27]);
        BUF_X1_49->Z(S0[27]);

    BUF_X1_50 = new BUF_X1("BUF_X1_50");
        BUF_X1_50->A(in[28]);
        BUF_X1_50->Z(S0[28]);

    BUF_X1_51 = new BUF_X1("BUF_X1_51");
        BUF_X1_51->A(in[29]);
        BUF_X1_51->Z(S0[29]);

    BUF_X1_52 = new BUF_X1("BUF_X1_52");
        BUF_X1_52->A(in[3]);
        BUF_X1_52->Z(S0[3]);

    BUF_X1_53 = new BUF_X1("BUF_X1_53");
        BUF_X1_53->A(in[30]);
        BUF_X1_53->Z(S0[30]);

    BUF_X1_54 = new BUF_X1("BUF_X1_54");
        BUF_X1_54->A(in[31]);
        BUF_X1_54->Z(S0[31]);

    BUF_X1_55 = new BUF_X1("BUF_X1_55");
        BUF_X1_55->A(in[32]);
        BUF_X1_55->Z(S0[32]);

    BUF_X1_56 = new BUF_X1("BUF_X1_56");
        BUF_X1_56->A(in[33]);
        BUF_X1_56->Z(S0[33]);

    BUF_X1_57 = new BUF_X1("BUF_X1_57");
        BUF_X1_57->A(in[34]);
        BUF_X1_57->Z(S0[34]);

    BUF_X1_58 = new BUF_X1("BUF_X1_58");
        BUF_X1_58->A(in[35]);
        BUF_X1_58->Z(S0[35]);

    BUF_X1_59 = new BUF_X1("BUF_X1_59");
        BUF_X1_59->A(in[36]);
        BUF_X1_59->Z(S0[36]);

    BUF_X1_60 = new BUF_X1("BUF_X1_60");
        BUF_X1_60->A(in[37]);
        BUF_X1_60->Z(S0[37]);

    BUF_X1_61 = new BUF_X1("BUF_X1_61");
        BUF_X1_61->A(in[38]);
        BUF_X1_61->Z(S0[38]);

    BUF_X1_62 = new BUF_X1("BUF_X1_62");
        BUF_X1_62->A(in[39]);
        BUF_X1_62->Z(S0[39]);

    BUF_X1_63 = new BUF_X1("BUF_X1_63");
        BUF_X1_63->A(in[4]);
        BUF_X1_63->Z(S0[4]);

    BUF_X1_64 = new BUF_X1("BUF_X1_64");
        BUF_X1_64->A(in[40]);
        BUF_X1_64->Z(S0[40]);

    BUF_X1_65 = new BUF_X1("BUF_X1_65");
        BUF_X1_65->A(in[41]);
        BUF_X1_65->Z(S0[41]);

    BUF_X1_66 = new BUF_X1("BUF_X1_66");
        BUF_X1_66->A(in[42]);
        BUF_X1_66->Z(S0[42]);

    BUF_X1_67 = new BUF_X1("BUF_X1_67");
        BUF_X1_67->A(in[43]);
        BUF_X1_67->Z(S0[43]);

    BUF_X1_68 = new BUF_X1("BUF_X1_68");
        BUF_X1_68->A(in[44]);
        BUF_X1_68->Z(S0[44]);

    BUF_X1_69 = new BUF_X1("BUF_X1_69");
        BUF_X1_69->A(in[45]);
        BUF_X1_69->Z(S0[45]);

    BUF_X1_70 = new BUF_X1("BUF_X1_70");
        BUF_X1_70->A(in[46]);
        BUF_X1_70->Z(S0[46]);

    BUF_X1_71 = new BUF_X1("BUF_X1_71");
        BUF_X1_71->A(in[47]);
        BUF_X1_71->Z(S0[47]);

    BUF_X1_72 = new BUF_X1("BUF_X1_72");
        BUF_X1_72->A(in[48]);
        BUF_X1_72->Z(S0[48]);

    BUF_X1_73 = new BUF_X1("BUF_X1_73");
        BUF_X1_73->A(in[49]);
        BUF_X1_73->Z(S0[49]);

    BUF_X1_74 = new BUF_X1("BUF_X1_74");
        BUF_X1_74->A(in[5]);
        BUF_X1_74->Z(S0[5]);

    BUF_X1_75 = new BUF_X1("BUF_X1_75");
        BUF_X1_75->A(in[50]);
        BUF_X1_75->Z(S0[50]);

    BUF_X1_76 = new BUF_X1("BUF_X1_76");
        BUF_X1_76->A(in[51]);
        BUF_X1_76->Z(S0[51]);

    BUF_X1_77 = new BUF_X1("BUF_X1_77");
        BUF_X1_77->A(in[52]);
        BUF_X1_77->Z(S0[52]);

    BUF_X1_78 = new BUF_X1("BUF_X1_78");
        BUF_X1_78->A(in[53]);
        BUF_X1_78->Z(S0[53]);

    BUF_X1_79 = new BUF_X1("BUF_X1_79");
        BUF_X1_79->A(in[54]);
        BUF_X1_79->Z(S0[54]);

    BUF_X1_80 = new BUF_X1("BUF_X1_80");
        BUF_X1_80->A(in[55]);
        BUF_X1_80->Z(S0[55]);

    BUF_X1_81 = new BUF_X1("BUF_X1_81");
        BUF_X1_81->A(in[56]);
        BUF_X1_81->Z(S0[56]);

    BUF_X1_82 = new BUF_X1("BUF_X1_82");
        BUF_X1_82->A(in[57]);
        BUF_X1_82->Z(S0[57]);

    BUF_X1_83 = new BUF_X1("BUF_X1_83");
        BUF_X1_83->A(in[58]);
        BUF_X1_83->Z(S0[58]);

    BUF_X1_84 = new BUF_X1("BUF_X1_84");
        BUF_X1_84->A(in[59]);
        BUF_X1_84->Z(S0[59]);

    BUF_X1_85 = new BUF_X1("BUF_X1_85");
        BUF_X1_85->A(in[6]);
        BUF_X1_85->Z(S0[6]);

    BUF_X1_86 = new BUF_X1("BUF_X1_86");
        BUF_X1_86->A(in[60]);
        BUF_X1_86->Z(S0[60]);

    BUF_X1_87 = new BUF_X1("BUF_X1_87");
        BUF_X1_87->A(in[61]);
        BUF_X1_87->Z(S0[61]);

    BUF_X1_88 = new BUF_X1("BUF_X1_88");
        BUF_X1_88->A(in[62]);
        BUF_X1_88->Z(S0[62]);

    BUF_X1_89 = new BUF_X1("BUF_X1_89");
        BUF_X1_89->A(in[63]);
        BUF_X1_89->Z(S0[63]);

    BUF_X1_90 = new BUF_X1("BUF_X1_90");
        BUF_X1_90->A(in[64]);
        BUF_X1_90->Z(S0[64]);

    BUF_X1_91 = new BUF_X1("BUF_X1_91");
        BUF_X1_91->A(in[65]);
        BUF_X1_91->Z(S0[65]);

    BUF_X1_92 = new BUF_X1("BUF_X1_92");
        BUF_X1_92->A(in[66]);
        BUF_X1_92->Z(S0[66]);

    BUF_X1_93 = new BUF_X1("BUF_X1_93");
        BUF_X1_93->A(in[67]);
        BUF_X1_93->Z(S0[67]);

    BUF_X1_94 = new BUF_X1("BUF_X1_94");
        BUF_X1_94->A(in[68]);
        BUF_X1_94->Z(S0[68]);

    BUF_X1_95 = new BUF_X1("BUF_X1_95");
        BUF_X1_95->A(in[69]);
        BUF_X1_95->Z(S0[69]);

    BUF_X1_96 = new BUF_X1("BUF_X1_96");
        BUF_X1_96->A(in[7]);
        BUF_X1_96->Z(S0[7]);

    BUF_X1_97 = new BUF_X1("BUF_X1_97");
        BUF_X1_97->A(in[70]);
        BUF_X1_97->Z(S0[70]);

    BUF_X1_98 = new BUF_X1("BUF_X1_98");
        BUF_X1_98->A(in[71]);
        BUF_X1_98->Z(S0[71]);

    BUF_X1_99 = new BUF_X1("BUF_X1_99");
        BUF_X1_99->A(in[72]);
        BUF_X1_99->Z(S0[72]);

    BUF_X1_100 = new BUF_X1("BUF_X1_100");
        BUF_X1_100->A(in[73]);
        BUF_X1_100->Z(S0[73]);

    BUF_X1_101 = new BUF_X1("BUF_X1_101");
        BUF_X1_101->A(in[74]);
        BUF_X1_101->Z(S0[74]);

    BUF_X1_102 = new BUF_X1("BUF_X1_102");
        BUF_X1_102->A(in[75]);
        BUF_X1_102->Z(S0[75]);

    BUF_X1_103 = new BUF_X1("BUF_X1_103");
        BUF_X1_103->A(in[76]);
        BUF_X1_103->Z(S0[76]);

    BUF_X1_104 = new BUF_X1("BUF_X1_104");
        BUF_X1_104->A(in[77]);
        BUF_X1_104->Z(S0[77]);

    BUF_X1_105 = new BUF_X1("BUF_X1_105");
        BUF_X1_105->A(in[78]);
        BUF_X1_105->Z(S0[78]);

    BUF_X1_106 = new BUF_X1("BUF_X1_106");
        BUF_X1_106->A(in[79]);
        BUF_X1_106->Z(S0[79]);

    BUF_X1_107 = new BUF_X1("BUF_X1_107");
        BUF_X1_107->A(in[8]);
        BUF_X1_107->Z(S0[8]);

    BUF_X1_108 = new BUF_X1("BUF_X1_108");
        BUF_X1_108->A(in[80]);
        BUF_X1_108->Z(S0[80]);

    BUF_X1_109 = new BUF_X1("BUF_X1_109");
        BUF_X1_109->A(in[81]);
        BUF_X1_109->Z(S0[81]);

    BUF_X1_110 = new BUF_X1("BUF_X1_110");
        BUF_X1_110->A(in[82]);
        BUF_X1_110->Z(S0[82]);

    BUF_X1_111 = new BUF_X1("BUF_X1_111");
        BUF_X1_111->A(in[83]);
        BUF_X1_111->Z(S0[83]);

    BUF_X1_112 = new BUF_X1("BUF_X1_112");
        BUF_X1_112->A(in[84]);
        BUF_X1_112->Z(S0[84]);

    BUF_X1_113 = new BUF_X1("BUF_X1_113");
        BUF_X1_113->A(in[85]);
        BUF_X1_113->Z(S0[85]);

    BUF_X1_114 = new BUF_X1("BUF_X1_114");
        BUF_X1_114->A(in[86]);
        BUF_X1_114->Z(S0[86]);

    BUF_X1_115 = new BUF_X1("BUF_X1_115");
        BUF_X1_115->A(in[87]);
        BUF_X1_115->Z(S0[87]);

    BUF_X1_116 = new BUF_X1("BUF_X1_116");
        BUF_X1_116->A(in[88]);
        BUF_X1_116->Z(S0[88]);

    BUF_X1_117 = new BUF_X1("BUF_X1_117");
        BUF_X1_117->A(in[89]);
        BUF_X1_117->Z(S0[89]);

    BUF_X1_118 = new BUF_X1("BUF_X1_118");
        BUF_X1_118->A(in[9]);
        BUF_X1_118->Z(S0[9]);

    BUF_X1_119 = new BUF_X1("BUF_X1_119");
        BUF_X1_119->A(in[90]);
        BUF_X1_119->Z(S0[90]);

    BUF_X1_120 = new BUF_X1("BUF_X1_120");
        BUF_X1_120->A(in[91]);
        BUF_X1_120->Z(S0[91]);

    BUF_X1_121 = new BUF_X1("BUF_X1_121");
        BUF_X1_121->A(in[92]);
        BUF_X1_121->Z(S0[92]);

    BUF_X1_122 = new BUF_X1("BUF_X1_122");
        BUF_X1_122->A(in[93]);
        BUF_X1_122->Z(S0[93]);

    BUF_X1_123 = new BUF_X1("BUF_X1_123");
        BUF_X1_123->A(in[94]);
        BUF_X1_123->Z(S0[94]);

    BUF_X1_124 = new BUF_X1("BUF_X1_124");
        BUF_X1_124->A(in[95]);
        BUF_X1_124->Z(S0[95]);

    BUF_X1_125 = new BUF_X1("BUF_X1_125");
        BUF_X1_125->A(in[96]);
        BUF_X1_125->Z(S0[96]);

    BUF_X1_126 = new BUF_X1("BUF_X1_126");
        BUF_X1_126->A(in[97]);
        BUF_X1_126->Z(S0[97]);

    BUF_X1_127 = new BUF_X1("BUF_X1_127");
        BUF_X1_127->A(in[98]);
        BUF_X1_127->Z(S0[98]);

    BUF_X1_128 = new BUF_X1("BUF_X1_128");
        BUF_X1_128->A(in[99]);
        BUF_X1_128->Z(S0[99]);


    SC_METHOD(sc_logic_signal_assignment);

    }

    void sc_logic_signal_assignment(void){ 
        sc_logic_1_signal.write(SC_LOGIC_1);
        sc_logic_0_signal.write(SC_LOGIC_0);
    }
};
#endif /* __INVERSESHIFTROWS_H__ */

