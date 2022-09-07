#include <systemc.h>
#include "component_library.h"

using namespace sc_core;

SC_MODULE( map9v3 ) {

    sc_in<sc_logic> clock;
    sc_in<sc_logic> reset;
    sc_in<sc_logic> start;
    sc_in<sc_logic> N[9];
    sc_out<sc_logic> dp[9];
    sc_out<sc_logic> done;
    sc_out<sc_logic> counter[8];
    sc_out<sc_logic> sr[8];

    sc_signal<sc_logic> sc_logic_1_signal;
    sc_signal<sc_logic> sc_logic_0_signal;

    sc_signal<sc_logic> new__0_;
    sc_signal<sc_logic> new__100_;
    sc_signal<sc_logic> new__101_;
    sc_signal<sc_logic> new__102_;
    sc_signal<sc_logic> new__103_;
    sc_signal<sc_logic> new__104_;
    sc_signal<sc_logic> new__105_;
    sc_signal<sc_logic> new__106_;
    sc_signal<sc_logic> new__107_;
    sc_signal<sc_logic> new__108_;
    sc_signal<sc_logic> new__109_;
    sc_signal<sc_logic> new__10_;
    sc_signal<sc_logic> new__110_;
    sc_signal<sc_logic> new__111_;
    sc_signal<sc_logic> new__112_;
    sc_signal<sc_logic> new__113_;
    sc_signal<sc_logic> new__114_;
    sc_signal<sc_logic> new__115_;
    sc_signal<sc_logic> new__116_;
    sc_signal<sc_logic> new__117_;
    sc_signal<sc_logic> new__118_;
    sc_signal<sc_logic> new__119_;
    sc_signal<sc_logic> new__11_;
    sc_signal<sc_logic> new__120_;
    sc_signal<sc_logic> new__121_;
    sc_signal<sc_logic> new__122_;
    sc_signal<sc_logic> new__123_;
    sc_signal<sc_logic> new__124_;
    sc_signal<sc_logic> new__125_;
    sc_signal<sc_logic> new__126_;
    sc_signal<sc_logic> new__127_;
    sc_signal<sc_logic> new__128_;
    sc_signal<sc_logic> new__129_;
    sc_signal<sc_logic> new__12_;
    sc_signal<sc_logic> new__130_;
    sc_signal<sc_logic> new__131_;
    sc_signal<sc_logic> new__132_;
    sc_signal<sc_logic> new__133_;
    sc_signal<sc_logic> new__134_;
    sc_signal<sc_logic> new__135_;
    sc_signal<sc_logic> new__136_;
    sc_signal<sc_logic> new__137_;
    sc_signal<sc_logic> new__138_;
    sc_signal<sc_logic> new__139_;
    sc_signal<sc_logic> new__13_;
    sc_signal<sc_logic> new__140_;
    sc_signal<sc_logic> new__141_;
    sc_signal<sc_logic> new__142_;
    sc_signal<sc_logic> new__143_;
    sc_signal<sc_logic> new__144_;
    sc_signal<sc_logic> new__145_;
    sc_signal<sc_logic> new__146_;
    sc_signal<sc_logic> new__147_;
    sc_signal<sc_logic> new__148_;
    sc_signal<sc_logic> new__149_;
    sc_signal<sc_logic> new__14_;
    sc_signal<sc_logic> new__150_;
    sc_signal<sc_logic> new__151_;
    sc_signal<sc_logic> new__152_;
    sc_signal<sc_logic> new__153_;
    sc_signal<sc_logic> new__154_;
    sc_signal<sc_logic> new__155_;
    sc_signal<sc_logic> new__156_;
    sc_signal<sc_logic> new__157_;
    sc_signal<sc_logic> new__158_;
    sc_signal<sc_logic> new__159_;
    sc_signal<sc_logic> new__15_;
    sc_signal<sc_logic> new__160_;
    sc_signal<sc_logic> new__161_;
    sc_signal<sc_logic> new__162_;
    sc_signal<sc_logic> new__163_;
    sc_signal<sc_logic> new__164_;
    sc_signal<sc_logic> new__165_;
    sc_signal<sc_logic> new__166_;
    sc_signal<sc_logic> new__167_;
    sc_signal<sc_logic> new__168_;
    sc_signal<sc_logic> new__169_;
    sc_signal<sc_logic> new__16_;
    sc_signal<sc_logic> new__170_;
    sc_signal<sc_logic> new__171_;
    sc_signal<sc_logic> new__172_;
    sc_signal<sc_logic> new__173_;
    sc_signal<sc_logic> new__174_;
    sc_signal<sc_logic> new__175_;
    sc_signal<sc_logic> new__176_;
    sc_signal<sc_logic> new__177_;
    sc_signal<sc_logic> new__178_;
    sc_signal<sc_logic> new__179_;
    sc_signal<sc_logic> new__17_;
    sc_signal<sc_logic> new__180_;
    sc_signal<sc_logic> new__181_;
    sc_signal<sc_logic> new__182_;
    sc_signal<sc_logic> new__183_;
    sc_signal<sc_logic> new__184_;
    sc_signal<sc_logic> new__185_;
    sc_signal<sc_logic> new__186_;
    sc_signal<sc_logic> new__187_;
    sc_signal<sc_logic> new__188_;
    sc_signal<sc_logic> new__18_;
    sc_signal<sc_logic> new__19_;
    sc_signal<sc_logic> new__1_;
    sc_signal<sc_logic> new__20_;
    sc_signal<sc_logic> new__21_;
    sc_signal<sc_logic> new__22_;
    sc_signal<sc_logic> new__23_;
    sc_signal<sc_logic> new__24_;
    sc_signal<sc_logic> new__25_;
    sc_signal<sc_logic> new__26_;
    sc_signal<sc_logic> new__27_;
    sc_signal<sc_logic> new__28_;
    sc_signal<sc_logic> new__29_;
    sc_signal<sc_logic> new__2_;
    sc_signal<sc_logic> new__30_;
    sc_signal<sc_logic> new__31_;
    sc_signal<sc_logic> new__32_;
    sc_signal<sc_logic> new__33_;
    sc_signal<sc_logic> new__34_;
    sc_signal<sc_logic> new__35_;
    sc_signal<sc_logic> new__36_;
    sc_signal<sc_logic> new__37_;
    sc_signal<sc_logic> new__38_;
    sc_signal<sc_logic> new__39_;
    sc_signal<sc_logic> new__3_;
    sc_signal<sc_logic> new__40_;
    sc_signal<sc_logic> new__41_;
    sc_signal<sc_logic> new__42_;
    sc_signal<sc_logic> new__43_;
    sc_signal<sc_logic> new__44_;
    sc_signal<sc_logic> new__45_;
    sc_signal<sc_logic> new__46_;
    sc_signal<sc_logic> new__47_;
    sc_signal<sc_logic> new__48_;
    sc_signal<sc_logic> new__49_;
    sc_signal<sc_logic> new__4_;
    sc_signal<sc_logic> new__50_;
    sc_signal<sc_logic> new__51_;
    sc_signal<sc_logic> new__52_;
    sc_signal<sc_logic> new__53_;
    sc_signal<sc_logic> new__54_;
    sc_signal<sc_logic> new__55_;
    sc_signal<sc_logic> new__56_;
    sc_signal<sc_logic> new__57_;
    sc_signal<sc_logic> new__58_;
    sc_signal<sc_logic> new__59_;
    sc_signal<sc_logic> new__5_;
    sc_signal<sc_logic> new__60_;
    sc_signal<sc_logic> new__61_;
    sc_signal<sc_logic> new__62_;
    sc_signal<sc_logic> new__63_;
    sc_signal<sc_logic> new__64_;
    sc_signal<sc_logic> new__65_;
    sc_signal<sc_logic> new__66_;
    sc_signal<sc_logic> new__67_;
    sc_signal<sc_logic> new__68_;
    sc_signal<sc_logic> new__69_;
    sc_signal<sc_logic> new__6_;
    sc_signal<sc_logic> new__70_;
    sc_signal<sc_logic> new__71_;
    sc_signal<sc_logic> new__72_;
    sc_signal<sc_logic> new__73_;
    sc_signal<sc_logic> new__74_;
    sc_signal<sc_logic> new__75_;
    sc_signal<sc_logic> new__76_;
    sc_signal<sc_logic> new__77_;
    sc_signal<sc_logic> new__78_;
    sc_signal<sc_logic> new__79_;
    sc_signal<sc_logic> new__7_;
    sc_signal<sc_logic> new__80_;
    sc_signal<sc_logic> new__81_;
    sc_signal<sc_logic> new__82_;
    sc_signal<sc_logic> new__83_;
    sc_signal<sc_logic> new__84_;
    sc_signal<sc_logic> new__85_;
    sc_signal<sc_logic> new__86_;
    sc_signal<sc_logic> new__87_;
    sc_signal<sc_logic> new__88_;
    sc_signal<sc_logic> new__89_;
    sc_signal<sc_logic> new__8_;
    sc_signal<sc_logic> new__90_;
    sc_signal<sc_logic> new__91_;
    sc_signal<sc_logic> new__92_;
    sc_signal<sc_logic> new__93_;
    sc_signal<sc_logic> new__94_;
    sc_signal<sc_logic> new__95_;
    sc_signal<sc_logic> new__96_;
    sc_signal<sc_logic> new__97_;
    sc_signal<sc_logic> new__98_;
    sc_signal<sc_logic> new__99_;
    sc_signal<sc_logic> new__9_;
    sc_signal<sc_logic> new_startbuf_0;
    sc_signal<sc_logic> new_startbuf_1;
    sc_signal<sc_logic> new_state_0;
    sc_signal<sc_logic> new_state_1;
    sc_signal<sc_logic> new_state_2;
    sc_signal<sc_logic> new_state_3;
    sc_signal<sc_logic> new_state_4;

    INV_X1* INV_X1_0;
    INV_X1* INV_X1_1;
    INV_X1* INV_X1_2;
    INV_X1* INV_X1_3;
    INV_X1* INV_X1_4;
    NOR2_X1* NOR2_X1_5;
    NOR2_X1* NOR2_X1_6;
    AND3_X1* AND3_X1_7;
    NAND4_X1* NAND4_X1_8;
    NAND2_X1* NAND2_X1_9;
    NAND2_X1* NAND2_X1_10;
    INV_X1* INV_X1_11;
    INV_X1* INV_X1_12;
    OAI21_X1* OAI21_X1_13;
    NAND2_X1* NAND2_X1_14;
    INV_X1* INV_X1_15;
    NOR3_X1* NOR3_X1_16;
    INV_X1* INV_X1_17;
    NOR2_X1* NOR2_X1_18;
    INV_X1* INV_X1_19;
    NOR2_X1* NOR2_X1_20;
    INV_X1* INV_X1_21;
    NOR2_X1* NOR2_X1_22;
    AOI22_X1* AOI22_X1_23;
    OAI21_X1* OAI21_X1_24;
    INV_X1* INV_X1_25;
    NAND2_X1* NAND2_X1_26;
    INV_X1* INV_X1_27;
    NOR2_X1* NOR2_X1_28;
    OAI21_X1* OAI21_X1_29;
    NAND2_X1* NAND2_X1_30;
    XOR2_X1* XOR2_X1_31;
    OAI211_X1* OAI211_X1_32;
    NAND2_X1* NAND2_X1_33;
    INV_X1* INV_X1_34;
    NAND2_X1* NAND2_X1_35;
    NAND3_X1* NAND3_X1_36;
    INV_X1* INV_X1_37;
    OAI211_X1* OAI211_X1_38;
    NOR2_X1* NOR2_X1_39;
    NAND3_X1* NAND3_X1_40;
    NAND3_X1* NAND3_X1_41;
    INV_X1* INV_X1_42;
    AOI21_X1* AOI21_X1_43;
    AND3_X1* AND3_X1_44;
    OR3_X1* OR3_X1_45;
    NAND2_X1* NAND2_X1_46;
    XNOR2_X1* XNOR2_X1_47;
    OAI211_X1* OAI211_X1_48;
    INV_X1* INV_X1_49;
    NOR2_X1* NOR2_X1_50;
    NOR2_X1* NOR2_X1_51;
    NAND3_X1* NAND3_X1_52;
    NAND2_X1* NAND2_X1_53;
    AOI21_X1* AOI21_X1_54;
    OAI21_X1* OAI21_X1_55;
    OAI221_X1* OAI221_X1_56;
    NAND3_X1* NAND3_X1_57;
    NAND4_X1* NAND4_X1_58;
    NAND2_X1* NAND2_X1_59;
    AOI21_X1* AOI21_X1_60;
    NOR2_X1* NOR2_X1_61;
    NAND2_X1* NAND2_X1_62;
    NOR2_X1* NOR2_X1_63;
    NAND3_X1* NAND3_X1_64;
    AOI21_X1* AOI21_X1_65;
    NOR3_X1* NOR3_X1_66;
    INV_X1* INV_X1_67;
    OAI21_X1* OAI21_X1_68;
    AOI21_X1* AOI21_X1_69;
    NAND2_X1* NAND2_X1_70;
    NAND3_X1* NAND3_X1_71;
    INV_X1* INV_X1_72;
    NAND2_X1* NAND2_X1_73;
    NAND3_X1* NAND3_X1_74;
    NAND2_X1* NAND2_X1_75;
    NOR2_X1* NOR2_X1_76;
    OAI21_X1* OAI21_X1_77;
    NAND4_X1* NAND4_X1_78;
    AOI21_X1* AOI21_X1_79;
    NAND2_X1* NAND2_X1_80;
    NAND4_X1* NAND4_X1_81;
    INV_X1* INV_X1_82;
    NAND4_X1* NAND4_X1_83;
    NAND2_X1* NAND2_X1_84;
    NAND3_X1* NAND3_X1_85;
    NAND2_X1* NAND2_X1_86;
    NOR2_X1* NOR2_X1_87;
    INV_X1* INV_X1_88;
    NOR2_X1* NOR2_X1_89;
    MUX2_X1* MUX2_X1_90;
    INV_X1* INV_X1_91;
    NOR2_X1* NOR2_X1_92;
    AOI21_X1* AOI21_X1_93;
    MUX2_X1* MUX2_X1_94;
    MUX2_X1* MUX2_X1_95;
    MUX2_X1* MUX2_X1_96;
    MUX2_X1* MUX2_X1_97;
    MUX2_X1* MUX2_X1_98;
    MUX2_X1* MUX2_X1_99;
    INV_X1* INV_X1_100;
    NOR2_X1* NOR2_X1_101;
    AOI21_X1* AOI21_X1_102;
    NAND3_X1* NAND3_X1_103;
    NAND2_X1* NAND2_X1_104;
    MUX2_X1* MUX2_X1_105;
    NAND2_X1* NAND2_X1_106;
    INV_X1* INV_X1_107;
    INV_X1* INV_X1_108;
    NAND2_X1* NAND2_X1_109;
    NAND2_X1* NAND2_X1_110;
    NAND3_X1* NAND3_X1_111;
    INV_X1* INV_X1_112;
    NAND2_X1* NAND2_X1_113;
    NAND2_X1* NAND2_X1_114;
    AOI21_X1* AOI21_X1_115;
    NAND3_X1* NAND3_X1_116;
    NAND3_X1* NAND3_X1_117;
    OAI21_X1* OAI21_X1_118;
    INV_X1* INV_X1_119;
    OAI22_X1* OAI22_X1_120;
    INV_X1* INV_X1_121;
    OAI22_X1* OAI22_X1_122;
    OAI22_X1* OAI22_X1_123;
    OAI22_X1* OAI22_X1_124;
    OAI22_X1* OAI22_X1_125;
    INV_X1* INV_X1_126;
    OAI22_X1* OAI22_X1_127;
    OAI22_X1* OAI22_X1_128;
    INV_X1* INV_X1_129;
    DFFR_X1* DFFR_X1_130;
    DFFR_X1* DFFR_X1_131;
    DFFR_X1* DFFR_X1_132;
    DFFR_X1* DFFR_X1_133;
    DFFR_X1* DFFR_X1_134;
    DFFR_X1* DFFR_X1_135;
    DFFR_X1* DFFR_X1_136;
    DFFR_X1* DFFR_X1_137;
    DFFR_X1* DFFR_X1_138;
    DFFR_X1* DFFR_X1_139;
    DFFR_X1* DFFR_X1_140;
    DFFR_X1* DFFR_X1_141;
    DFFR_X1* DFFR_X1_142;
    DFFR_X1* DFFR_X1_143;
    DFFR_X1* DFFR_X1_144;
    DFFR_X1* DFFR_X1_145;
    DFFR_X1* DFFR_X1_146;
    DFFR_X1* DFFR_X1_147;
    DFFS_X1* DFFS_X1_148;
    DFFR_X1* DFFR_X1_149;
    DFFR_X1* DFFR_X1_150;
    DFFR_X1* DFFR_X1_151;
    DFFR_X1* DFFR_X1_152;
    DFFR_X1* DFFR_X1_153;
    DFFR_X1* DFFR_X1_154;
    DFFR_X1* DFFR_X1_155;
    DFFR_X1* DFFR_X1_156;
    DFFR_X1* DFFR_X1_157;
    DFFR_X1* DFFR_X1_158;
    DFFR_X1* DFFR_X1_159;
    DFFR_X1* DFFR_X1_160;
    DFFR_X1* DFFR_X1_161;
    DFFR_X1* DFFR_X1_162;
    BUF_X1* BUF_X1_163;
    BUF_X1* BUF_X1_164;
    BUF_X1* BUF_X1_165;
    BUF_X1* BUF_X1_166;
    BUF_X1* BUF_X1_167;
    BUF_X1* BUF_X1_168;
    BUF_X1* BUF_X1_169;
    BUF_X1* BUF_X1_170;
    BUF_X1* BUF_X1_171;
    BUF_X1* BUF_X1_172;
    BUF_X1* BUF_X1_173;
    BUF_X1* BUF_X1_174;
    BUF_X1* BUF_X1_175;
    BUF_X1* BUF_X1_176;
    BUF_X1* BUF_X1_177;
    BUF_X1* BUF_X1_178;
    BUF_X1* BUF_X1_179;
    BUF_X1* BUF_X1_180;
    BUF_X1* BUF_X1_181;
    BUF_X1* BUF_X1_182;
    BUF_X1* BUF_X1_183;
    BUF_X1* BUF_X1_184;
    BUF_X1* BUF_X1_185;
    BUF_X1* BUF_X1_186;
    BUF_X1* BUF_X1_187;
    BUF_X1* BUF_X1_188;

SC_CTOR( map9v3 ) {
    INV_X1_0 = new INV_X1("INV_X1_0");
        INV_X1_0->A(new_state_0);
        INV_X1_0->ZN(new__115_);

    INV_X1_1 = new INV_X1("INV_X1_1");
        INV_X1_1->A(new__168_);
        INV_X1_1->ZN(new__116_);

    INV_X1_2 = new INV_X1("INV_X1_2");
        INV_X1_2->A(new__169_);
        INV_X1_2->ZN(new__117_);

    INV_X1_3 = new INV_X1("INV_X1_3");
        INV_X1_3->A(new__170_);
        INV_X1_3->ZN(new__118_);

    INV_X1_4 = new INV_X1("INV_X1_4");
        INV_X1_4->A(new__167_);
        INV_X1_4->ZN(new__119_);

    NOR2_X1_5 = new NOR2_X1("NOR2_X1_5");
        NOR2_X1_5->A1(new__164_);
        NOR2_X1_5->A2(new__163_);
        NOR2_X1_5->ZN(new__120_);

    NOR2_X1_6 = new NOR2_X1("NOR2_X1_6");
        NOR2_X1_6->A1(new__166_);
        NOR2_X1_6->A2(new__165_);
        NOR2_X1_6->ZN(new__121_);

    AND3_X1_7 = new AND3_X1("AND3_X1_7");
        AND3_X1_7->A1(new__121_);
        AND3_X1_7->A2(new__120_);
        AND3_X1_7->A3(new__119_);
        AND3_X1_7->ZN(new__122_);

    NAND4_X1_8 = new NAND4_X1("NAND4_X1_8");
        NAND4_X1_8->A1(new__122_);
        NAND4_X1_8->A2(new__118_);
        NAND4_X1_8->A3(new__117_);
        NAND4_X1_8->A4(new__116_);
        NAND4_X1_8->ZN(new__123_);

    NAND2_X1_9 = new NAND2_X1("NAND2_X1_9");
        NAND2_X1_9->A1(new__123_);
        NAND2_X1_9->A2(new_state_3);
        NAND2_X1_9->ZN(new__124_);

    NAND2_X1_10 = new NAND2_X1("NAND2_X1_10");
        NAND2_X1_10->A1(new__124_);
        NAND2_X1_10->A2(new__115_);
        NAND2_X1_10->ZN(new__4_);

    INV_X1_11 = new INV_X1("INV_X1_11");
        INV_X1_11->A(new_state_4);
        INV_X1_11->ZN(new__125_);

    INV_X1_12 = new INV_X1("INV_X1_12");
        INV_X1_12->A(new_startbuf_0);
        INV_X1_12->ZN(new__126_);

    OAI21_X1_13 = new OAI21_X1("OAI21_X1_13");
        OAI21_X1_13->A(new_state_1);
        OAI21_X1_13->B1(new__126_);
        OAI21_X1_13->B2(new_startbuf_1);
        OAI21_X1_13->ZN(new__127_);

    NAND2_X1_14 = new NAND2_X1("NAND2_X1_14");
        NAND2_X1_14->A1(new__127_);
        NAND2_X1_14->A2(new__125_);
        NAND2_X1_14->ZN(new__3_);

    INV_X1_15 = new INV_X1("INV_X1_15");
        INV_X1_15->A(new_state_1);
        INV_X1_15->ZN(new__128_);

    NOR3_X1_16 = new NOR3_X1("NOR3_X1_16");
        NOR3_X1_16->A1(new__128_);
        NOR3_X1_16->A2(new__126_);
        NOR3_X1_16->A3(new_startbuf_1);
        NOR3_X1_16->ZN(new__1_);

    INV_X1_17 = new INV_X1("INV_X1_17");
        INV_X1_17->A(new_state_3);
        INV_X1_17->ZN(new__129_);

    NOR2_X1_18 = new NOR2_X1("NOR2_X1_18");
        NOR2_X1_18->A1(new__123_);
        NOR2_X1_18->A2(new__129_);
        NOR2_X1_18->ZN(new__2_);

    INV_X1_19 = new INV_X1("INV_X1_19");
        INV_X1_19->A(new__163_);
        INV_X1_19->ZN(new__130_);

    NOR2_X1_20 = new NOR2_X1("NOR2_X1_20");
        NOR2_X1_20->A1(new_state_3);
        NOR2_X1_20->A2(new_state_0);
        NOR2_X1_20->ZN(new__131_);

    INV_X1_21 = new INV_X1("INV_X1_21");
        INV_X1_21->A(new__131_);
        INV_X1_21->ZN(new__132_);

    NOR2_X1_22 = new NOR2_X1("NOR2_X1_22");
        NOR2_X1_22->A1(new__129_);
        NOR2_X1_22->A2(new_state_0);
        NOR2_X1_22->ZN(new__34_);

    AOI22_X1_23 = new AOI22_X1("AOI22_X1_23");
        AOI22_X1_23->A1(new__34_);
        AOI22_X1_23->A2(new__6_);
        AOI22_X1_23->B1(new_state_0);
        AOI22_X1_23->B2(N[1]);
        AOI22_X1_23->ZN(new__35_);

    OAI21_X1_24 = new OAI21_X1("OAI21_X1_24");
        OAI21_X1_24->A(new__35_);
        OAI21_X1_24->B1(new__130_);
        OAI21_X1_24->B2(new__132_);
        OAI21_X1_24->ZN(new__8_);

    INV_X1_25 = new INV_X1("INV_X1_25");
        INV_X1_25->A(new__34_);
        INV_X1_25->ZN(new__36_);

    NAND2_X1_26 = new NAND2_X1("NAND2_X1_26");
        NAND2_X1_26->A1(N[1]);
        NAND2_X1_26->A2(N[2]);
        NAND2_X1_26->ZN(new__37_);

    INV_X1_27 = new INV_X1("INV_X1_27");
        INV_X1_27->A(new__37_);
        INV_X1_27->ZN(new__38_);

    NOR2_X1_28 = new NOR2_X1("NOR2_X1_28");
        NOR2_X1_28->A1(N[1]);
        NOR2_X1_28->A2(N[2]);
        NOR2_X1_28->ZN(new__39_);

    OAI21_X1_29 = new OAI21_X1("OAI21_X1_29");
        OAI21_X1_29->A(new_state_0);
        OAI21_X1_29->B1(new__38_);
        OAI21_X1_29->B2(new__39_);
        OAI21_X1_29->ZN(new__40_);

    NAND2_X1_30 = new NAND2_X1("NAND2_X1_30");
        NAND2_X1_30->A1(new__131_);
        NAND2_X1_30->A2(new__164_);
        NAND2_X1_30->ZN(new__41_);

    XOR2_X1_31 = new XOR2_X1("XOR2_X1_31");
        XOR2_X1_31->A(new__164_);
        XOR2_X1_31->B(new__163_);
        XOR2_X1_31->Z(new__42_);

    OAI211_X1_32 = new OAI211_X1("OAI211_X1_32");
        OAI211_X1_32->A(new__40_);
        OAI211_X1_32->B(new__41_);
        OAI211_X1_32->C1(new__42_);
        OAI211_X1_32->C2(new__36_);
        OAI211_X1_32->ZN(new__9_);

    NAND2_X1_33 = new NAND2_X1("NAND2_X1_33");
        NAND2_X1_33->A1(new__38_);
        NAND2_X1_33->A2(N[3]);
        NAND2_X1_33->ZN(new__43_);

    INV_X1_34 = new INV_X1("INV_X1_34");
        INV_X1_34->A(N[3]);
        INV_X1_34->ZN(new__44_);

    NAND2_X1_35 = new NAND2_X1("NAND2_X1_35");
        NAND2_X1_35->A1(new__37_);
        NAND2_X1_35->A2(new__44_);
        NAND2_X1_35->ZN(new__45_);

    NAND3_X1_36 = new NAND3_X1("NAND3_X1_36");
        NAND3_X1_36->A1(new__43_);
        NAND3_X1_36->A2(new_state_0);
        NAND3_X1_36->A3(new__45_);
        NAND3_X1_36->ZN(new__46_);

    INV_X1_37 = new INV_X1("INV_X1_37");
        INV_X1_37->A(new__120_);
        INV_X1_37->ZN(new__47_);

    OAI211_X1_38 = new OAI211_X1("OAI211_X1_38");
        OAI211_X1_38->A(new__165_);
        OAI211_X1_38->B(new__115_);
        OAI211_X1_38->C1(new__47_);
        OAI211_X1_38->C2(new__129_);
        OAI211_X1_38->ZN(new__48_);

    NOR2_X1_39 = new NOR2_X1("NOR2_X1_39");
        NOR2_X1_39->A1(new__47_);
        NOR2_X1_39->A2(new__165_);
        NOR2_X1_39->ZN(new__49_);

    NAND3_X1_40 = new NAND3_X1("NAND3_X1_40");
        NAND3_X1_40->A1(new__49_);
        NAND3_X1_40->A2(new_state_3);
        NAND3_X1_40->A3(new__115_);
        NAND3_X1_40->ZN(new__50_);

    NAND3_X1_41 = new NAND3_X1("NAND3_X1_41");
        NAND3_X1_41->A1(new__50_);
        NAND3_X1_41->A2(new__46_);
        NAND3_X1_41->A3(new__48_);
        NAND3_X1_41->ZN(new__10_);

    INV_X1_42 = new INV_X1("INV_X1_42");
        INV_X1_42->A(N[4]);
        INV_X1_42->ZN(new__51_);

    AOI21_X1_43 = new AOI21_X1("AOI21_X1_43");
        AOI21_X1_43->A(new__51_);
        AOI21_X1_43->B1(new__37_);
        AOI21_X1_43->B2(new__44_);
        AOI21_X1_43->ZN(new__52_);

    AND3_X1_44 = new AND3_X1("AND3_X1_44");
        AND3_X1_44->A1(new__37_);
        AND3_X1_44->A2(new__51_);
        AND3_X1_44->A3(new__44_);
        AND3_X1_44->ZN(new__53_);

    OR3_X1_45 = new OR3_X1("OR3_X1_45");
        OR3_X1_45->A1(new__53_);
        OR3_X1_45->A2(new__52_);
        OR3_X1_45->A3(new__115_);
        OR3_X1_45->ZN(new__54_);

    NAND2_X1_46 = new NAND2_X1("NAND2_X1_46");
        NAND2_X1_46->A1(new__131_);
        NAND2_X1_46->A2(new__166_);
        NAND2_X1_46->ZN(new__55_);

    XNOR2_X1_47 = new XNOR2_X1("XNOR2_X1_47");
        XNOR2_X1_47->A(new__49_);
        XNOR2_X1_47->B(new__166_);
        XNOR2_X1_47->ZN(new__56_);

    OAI211_X1_48 = new OAI211_X1("OAI211_X1_48");
        OAI211_X1_48->A(new__54_);
        OAI211_X1_48->B(new__55_);
        OAI211_X1_48->C1(new__56_);
        OAI211_X1_48->C2(new__36_);
        OAI211_X1_48->ZN(new__11_);

    INV_X1_49 = new INV_X1("INV_X1_49");
        INV_X1_49->A(N[5]);
        INV_X1_49->ZN(new__57_);

    NOR2_X1_50 = new NOR2_X1("NOR2_X1_50");
        NOR2_X1_50->A1(new__53_);
        NOR2_X1_50->A2(new__57_);
        NOR2_X1_50->ZN(new__58_);

    NOR2_X1_51 = new NOR2_X1("NOR2_X1_51");
        NOR2_X1_51->A1(N[3]);
        NOR2_X1_51->A2(N[4]);
        NOR2_X1_51->ZN(new__59_);

    NAND3_X1_52 = new NAND3_X1("NAND3_X1_52");
        NAND3_X1_52->A1(new__59_);
        NAND3_X1_52->A2(new__57_);
        NAND3_X1_52->A3(new__37_);
        NAND3_X1_52->ZN(new__60_);

    NAND2_X1_53 = new NAND2_X1("NAND2_X1_53");
        NAND2_X1_53->A1(new__60_);
        NAND2_X1_53->A2(new_state_0);
        NAND2_X1_53->ZN(new__61_);

    AOI21_X1_54 = new AOI21_X1("AOI21_X1_54");
        AOI21_X1_54->A(new__119_);
        AOI21_X1_54->B1(new__120_);
        AOI21_X1_54->B2(new__121_);
        AOI21_X1_54->ZN(new__62_);

    OAI21_X1_55 = new OAI21_X1("OAI21_X1_55");
        OAI21_X1_55->A(new__34_);
        OAI21_X1_55->B1(new__122_);
        OAI21_X1_55->B2(new__62_);
        OAI21_X1_55->ZN(new__63_);

    OAI221_X1_56 = new OAI221_X1("OAI221_X1_56");
        OAI221_X1_56->A(new__63_);
        OAI221_X1_56->B1(new__58_);
        OAI221_X1_56->B2(new__61_);
        OAI221_X1_56->C1(new__132_);
        OAI221_X1_56->C2(new__119_);
        OAI221_X1_56->ZN(new__12_);

    NAND3_X1_57 = new NAND3_X1("NAND3_X1_57");
        NAND3_X1_57->A1(new__120_);
        NAND3_X1_57->A2(new__121_);
        NAND3_X1_57->A3(new__119_);
        NAND3_X1_57->ZN(new__64_);

    NAND4_X1_58 = new NAND4_X1("NAND4_X1_58");
        NAND4_X1_58->A1(new__120_);
        NAND4_X1_58->A2(new__121_);
        NAND4_X1_58->A3(new__116_);
        NAND4_X1_58->A4(new__119_);
        NAND4_X1_58->ZN(new__65_);

    NAND2_X1_59 = new NAND2_X1("NAND2_X1_59");
        NAND2_X1_59->A1(new__65_);
        NAND2_X1_59->A2(new__34_);
        NAND2_X1_59->ZN(new__66_);

    AOI21_X1_60 = new AOI21_X1("AOI21_X1_60");
        AOI21_X1_60->A(new__66_);
        AOI21_X1_60->B1(new__64_);
        AOI21_X1_60->B2(new__168_);
        AOI21_X1_60->ZN(new__67_);

    NOR2_X1_61 = new NOR2_X1("NOR2_X1_61");
        NOR2_X1_61->A1(new__132_);
        NOR2_X1_61->A2(new__168_);
        NOR2_X1_61->ZN(new__68_);

    NAND2_X1_62 = new NAND2_X1("NAND2_X1_62");
        NAND2_X1_62->A1(new__60_);
        NAND2_X1_62->A2(N[6]);
        NAND2_X1_62->ZN(new__69_);

    NOR2_X1_63 = new NOR2_X1("NOR2_X1_63");
        NOR2_X1_63->A1(N[5]);
        NOR2_X1_63->A2(N[6]);
        NOR2_X1_63->ZN(new__70_);

    NAND3_X1_64 = new NAND3_X1("NAND3_X1_64");
        NAND3_X1_64->A1(new__59_);
        NAND3_X1_64->A2(new__70_);
        NAND3_X1_64->A3(new__37_);
        NAND3_X1_64->ZN(new__71_);

    AOI21_X1_65 = new AOI21_X1("AOI21_X1_65");
        AOI21_X1_65->A(new__115_);
        AOI21_X1_65->B1(new__69_);
        AOI21_X1_65->B2(new__71_);
        AOI21_X1_65->ZN(new__72_);

    NOR3_X1_66 = new NOR3_X1("NOR3_X1_66");
        NOR3_X1_66->A1(new__67_);
        NOR3_X1_66->A2(new__72_);
        NOR3_X1_66->A3(new__68_);
        NOR3_X1_66->ZN(new__13_);

    INV_X1_67 = new INV_X1("INV_X1_67");
        INV_X1_67->A(new__5_);
        INV_X1_67->ZN(new__73_);

    OAI21_X1_68 = new OAI21_X1("OAI21_X1_68");
        OAI21_X1_68->A(new__34_);
        OAI21_X1_68->B1(new__65_);
        OAI21_X1_68->B2(new__73_);
        OAI21_X1_68->ZN(new__74_);

    AOI21_X1_69 = new AOI21_X1("AOI21_X1_69");
        AOI21_X1_69->A(new__74_);
        AOI21_X1_69->B1(new__65_);
        AOI21_X1_69->B2(new__73_);
        AOI21_X1_69->ZN(new__75_);

    NAND2_X1_70 = new NAND2_X1("NAND2_X1_70");
        NAND2_X1_70->A1(new__131_);
        NAND2_X1_70->A2(new__117_);
        NAND2_X1_70->ZN(new__76_);

    NAND3_X1_71 = new NAND3_X1("NAND3_X1_71");
        NAND3_X1_71->A1(new__53_);
        NAND3_X1_71->A2(N[7]);
        NAND3_X1_71->A3(new__70_);
        NAND3_X1_71->ZN(new__77_);

    INV_X1_72 = new INV_X1("INV_X1_72");
        INV_X1_72->A(N[7]);
        INV_X1_72->ZN(new__78_);

    NAND2_X1_73 = new NAND2_X1("NAND2_X1_73");
        NAND2_X1_73->A1(new__71_);
        NAND2_X1_73->A2(new__78_);
        NAND2_X1_73->ZN(new__79_);

    NAND3_X1_74 = new NAND3_X1("NAND3_X1_74");
        NAND3_X1_74->A1(new__77_);
        NAND3_X1_74->A2(new_state_0);
        NAND3_X1_74->A3(new__79_);
        NAND3_X1_74->ZN(new__80_);

    NAND2_X1_75 = new NAND2_X1("NAND2_X1_75");
        NAND2_X1_75->A1(new__80_);
        NAND2_X1_75->A2(new__76_);
        NAND2_X1_75->ZN(new__81_);

    NOR2_X1_76 = new NOR2_X1("NOR2_X1_76");
        NOR2_X1_76->A1(new__81_);
        NOR2_X1_76->A2(new__75_);
        NOR2_X1_76->ZN(new__14_);

    OAI21_X1_77 = new OAI21_X1("OAI21_X1_77");
        OAI21_X1_77->A(new__118_);
        OAI21_X1_77->B1(new__65_);
        OAI21_X1_77->B2(new__73_);
        OAI21_X1_77->ZN(new__82_);

    NAND4_X1_78 = new NAND4_X1("NAND4_X1_78");
        NAND4_X1_78->A1(new__122_);
        NAND4_X1_78->A2(new__5_);
        NAND4_X1_78->A3(new__170_);
        NAND4_X1_78->A4(new__116_);
        NAND4_X1_78->ZN(new__83_);

    AOI21_X1_79 = new AOI21_X1("AOI21_X1_79");
        AOI21_X1_79->A(new__36_);
        AOI21_X1_79->B1(new__83_);
        AOI21_X1_79->B2(new__82_);
        AOI21_X1_79->ZN(new__84_);

    NAND2_X1_80 = new NAND2_X1("NAND2_X1_80");
        NAND2_X1_80->A1(new__131_);
        NAND2_X1_80->A2(new__118_);
        NAND2_X1_80->ZN(new__85_);

    NAND4_X1_81 = new NAND4_X1("NAND4_X1_81");
        NAND4_X1_81->A1(new__53_);
        NAND4_X1_81->A2(new__70_);
        NAND4_X1_81->A3(new__78_);
        NAND4_X1_81->A4(N[8]);
        NAND4_X1_81->ZN(new__86_);

    INV_X1_82 = new INV_X1("INV_X1_82");
        INV_X1_82->A(N[8]);
        INV_X1_82->ZN(new__87_);

    NAND4_X1_83 = new NAND4_X1("NAND4_X1_83");
        NAND4_X1_83->A1(new__59_);
        NAND4_X1_83->A2(new__70_);
        NAND4_X1_83->A3(new__78_);
        NAND4_X1_83->A4(new__37_);
        NAND4_X1_83->ZN(new__88_);

    NAND2_X1_84 = new NAND2_X1("NAND2_X1_84");
        NAND2_X1_84->A1(new__88_);
        NAND2_X1_84->A2(new__87_);
        NAND2_X1_84->ZN(new__89_);

    NAND3_X1_85 = new NAND3_X1("NAND3_X1_85");
        NAND3_X1_85->A1(new__86_);
        NAND3_X1_85->A2(new_state_0);
        NAND3_X1_85->A3(new__89_);
        NAND3_X1_85->ZN(new__90_);

    NAND2_X1_86 = new NAND2_X1("NAND2_X1_86");
        NAND2_X1_86->A1(new__90_);
        NAND2_X1_86->A2(new__85_);
        NAND2_X1_86->ZN(new__91_);

    NOR2_X1_87 = new NOR2_X1("NOR2_X1_87");
        NOR2_X1_87->A1(new__91_);
        NOR2_X1_87->A2(new__84_);
        NOR2_X1_87->ZN(new__15_);

    INV_X1_88 = new INV_X1("INV_X1_88");
        INV_X1_88->A(new_state_2);
        INV_X1_88->ZN(new__92_);

    NOR2_X1_89 = new NOR2_X1("NOR2_X1_89");
        NOR2_X1_89->A1(new__132_);
        NOR2_X1_89->A2(new__92_);
        NOR2_X1_89->ZN(new__93_);

    MUX2_X1_90 = new MUX2_X1("MUX2_X1_90");
        MUX2_X1_90->A(new__172_);
        MUX2_X1_90->B(N[0]);
        MUX2_X1_90->S(new__93_);
        MUX2_X1_90->Z(new__16_);

    INV_X1_91 = new INV_X1("INV_X1_91");
        INV_X1_91->A(new__181_);
        INV_X1_91->ZN(new__94_);

    NOR2_X1_92 = new NOR2_X1("NOR2_X1_92");
        NOR2_X1_92->A1(new__93_);
        NOR2_X1_92->A2(new__173_);
        NOR2_X1_92->ZN(new__95_);

    AOI21_X1_93 = new AOI21_X1("AOI21_X1_93");
        AOI21_X1_93->A(new__95_);
        AOI21_X1_93->B1(new__93_);
        AOI21_X1_93->B2(new__94_);
        AOI21_X1_93->ZN(new__17_);

    MUX2_X1_94 = new MUX2_X1("MUX2_X1_94");
        MUX2_X1_94->A(new__174_);
        MUX2_X1_94->B(new__182_);
        MUX2_X1_94->S(new__93_);
        MUX2_X1_94->Z(new__18_);

    MUX2_X1_95 = new MUX2_X1("MUX2_X1_95");
        MUX2_X1_95->A(new__175_);
        MUX2_X1_95->B(new__183_);
        MUX2_X1_95->S(new__93_);
        MUX2_X1_95->Z(new__19_);

    MUX2_X1_96 = new MUX2_X1("MUX2_X1_96");
        MUX2_X1_96->A(new__176_);
        MUX2_X1_96->B(new__184_);
        MUX2_X1_96->S(new__93_);
        MUX2_X1_96->Z(new__20_);

    MUX2_X1_97 = new MUX2_X1("MUX2_X1_97");
        MUX2_X1_97->A(new__177_);
        MUX2_X1_97->B(new__185_);
        MUX2_X1_97->S(new__93_);
        MUX2_X1_97->Z(new__21_);

    MUX2_X1_98 = new MUX2_X1("MUX2_X1_98");
        MUX2_X1_98->A(new__178_);
        MUX2_X1_98->B(new__186_);
        MUX2_X1_98->S(new__93_);
        MUX2_X1_98->Z(new__22_);

    MUX2_X1_99 = new MUX2_X1("MUX2_X1_99");
        MUX2_X1_99->A(new__179_);
        MUX2_X1_99->B(new__187_);
        MUX2_X1_99->S(new__93_);
        MUX2_X1_99->Z(new__23_);

    INV_X1_100 = new INV_X1("INV_X1_100");
        INV_X1_100->A(new__188_);
        INV_X1_100->ZN(new__96_);

    NOR2_X1_101 = new NOR2_X1("NOR2_X1_101");
        NOR2_X1_101->A1(new__93_);
        NOR2_X1_101->A2(new__180_);
        NOR2_X1_101->ZN(new__97_);

    AOI21_X1_102 = new AOI21_X1("AOI21_X1_102");
        AOI21_X1_102->A(new__97_);
        AOI21_X1_102->B1(new__93_);
        AOI21_X1_102->B2(new__96_);
        AOI21_X1_102->ZN(new__24_);

    NAND3_X1_103 = new NAND3_X1("NAND3_X1_103");
        NAND3_X1_103->A1(new__129_);
        NAND3_X1_103->A2(new__92_);
        NAND3_X1_103->A3(new_state_4);
        NAND3_X1_103->ZN(new__98_);

    NAND2_X1_104 = new NAND2_X1("NAND2_X1_104");
        NAND2_X1_104->A1(new__98_);
        NAND2_X1_104->A2(new__115_);
        NAND2_X1_104->ZN(new__99_);

    MUX2_X1_105 = new MUX2_X1("MUX2_X1_105");
        MUX2_X1_105->A(new__171_);
        MUX2_X1_105->B(new__0_);
        MUX2_X1_105->S(new__99_);
        MUX2_X1_105->Z(new__25_);

    NAND2_X1_106 = new NAND2_X1("NAND2_X1_106");
        NAND2_X1_106->A1(new__131_);
        NAND2_X1_106->A2(new__181_);
        NAND2_X1_106->ZN(new__100_);

    INV_X1_107 = new INV_X1("INV_X1_107");
        INV_X1_107->A(new__184_);
        INV_X1_107->ZN(new__101_);

    INV_X1_108 = new INV_X1("INV_X1_108");
        INV_X1_108->A(new__185_);
        INV_X1_108->ZN(new__102_);

    NAND2_X1_109 = new NAND2_X1("NAND2_X1_109");
        NAND2_X1_109->A1(new__96_);
        NAND2_X1_109->A2(new__102_);
        NAND2_X1_109->ZN(new__103_);

    NAND2_X1_110 = new NAND2_X1("NAND2_X1_110");
        NAND2_X1_110->A1(new__188_);
        NAND2_X1_110->A2(new__185_);
        NAND2_X1_110->ZN(new__104_);

    NAND3_X1_111 = new NAND3_X1("NAND3_X1_111");
        NAND3_X1_111->A1(new__103_);
        NAND3_X1_111->A2(new__186_);
        NAND3_X1_111->A3(new__104_);
        NAND3_X1_111->ZN(new__105_);

    INV_X1_112 = new INV_X1("INV_X1_112");
        INV_X1_112->A(new__186_);
        INV_X1_112->ZN(new__106_);

    NAND2_X1_113 = new NAND2_X1("NAND2_X1_113");
        NAND2_X1_113->A1(new__103_);
        NAND2_X1_113->A2(new__104_);
        NAND2_X1_113->ZN(new__107_);

    NAND2_X1_114 = new NAND2_X1("NAND2_X1_114");
        NAND2_X1_114->A1(new__107_);
        NAND2_X1_114->A2(new__106_);
        NAND2_X1_114->ZN(new__108_);

    AOI21_X1_115 = new AOI21_X1("AOI21_X1_115");
        AOI21_X1_115->A(new__101_);
        AOI21_X1_115->B1(new__108_);
        AOI21_X1_115->B2(new__105_);
        AOI21_X1_115->ZN(new__109_);

    NAND3_X1_116 = new NAND3_X1("NAND3_X1_116");
        NAND3_X1_116->A1(new__108_);
        NAND3_X1_116->A2(new__101_);
        NAND3_X1_116->A3(new__105_);
        NAND3_X1_116->ZN(new__110_);

    NAND3_X1_117 = new NAND3_X1("NAND3_X1_117");
        NAND3_X1_117->A1(new__110_);
        NAND3_X1_117->A2(new__0_);
        NAND3_X1_117->A3(new__132_);
        NAND3_X1_117->ZN(new__111_);

    OAI21_X1_118 = new OAI21_X1("OAI21_X1_118");
        OAI21_X1_118->A(new__100_);
        OAI21_X1_118->B1(new__111_);
        OAI21_X1_118->B2(new__109_);
        OAI21_X1_118->ZN(new__26_);

    INV_X1_119 = new INV_X1("INV_X1_119");
        INV_X1_119->A(new__182_);
        INV_X1_119->ZN(new__112_);

    OAI22_X1_120 = new OAI22_X1("OAI22_X1_120");
        OAI22_X1_120->A1(new__36_);
        OAI22_X1_120->A2(new__94_);
        OAI22_X1_120->B1(new__132_);
        OAI22_X1_120->B2(new__112_);
        OAI22_X1_120->ZN(new__27_);

    INV_X1_121 = new INV_X1("INV_X1_121");
        INV_X1_121->A(new__183_);
        INV_X1_121->ZN(new__113_);

    OAI22_X1_122 = new OAI22_X1("OAI22_X1_122");
        OAI22_X1_122->A1(new__36_);
        OAI22_X1_122->A2(new__112_);
        OAI22_X1_122->B1(new__113_);
        OAI22_X1_122->B2(new__132_);
        OAI22_X1_122->ZN(new__28_);

    OAI22_X1_123 = new OAI22_X1("OAI22_X1_123");
        OAI22_X1_123->A1(new__36_);
        OAI22_X1_123->A2(new__113_);
        OAI22_X1_123->B1(new__132_);
        OAI22_X1_123->B2(new__101_);
        OAI22_X1_123->ZN(new__29_);

    OAI22_X1_124 = new OAI22_X1("OAI22_X1_124");
        OAI22_X1_124->A1(new__36_);
        OAI22_X1_124->A2(new__101_);
        OAI22_X1_124->B1(new__132_);
        OAI22_X1_124->B2(new__102_);
        OAI22_X1_124->ZN(new__30_);

    OAI22_X1_125 = new OAI22_X1("OAI22_X1_125");
        OAI22_X1_125->A1(new__36_);
        OAI22_X1_125->A2(new__102_);
        OAI22_X1_125->B1(new__132_);
        OAI22_X1_125->B2(new__106_);
        OAI22_X1_125->ZN(new__31_);

    INV_X1_126 = new INV_X1("INV_X1_126");
        INV_X1_126->A(new__187_);
        INV_X1_126->ZN(new__114_);

    OAI22_X1_127 = new OAI22_X1("OAI22_X1_127");
        OAI22_X1_127->A1(new__36_);
        OAI22_X1_127->A2(new__106_);
        OAI22_X1_127->B1(new__114_);
        OAI22_X1_127->B2(new__132_);
        OAI22_X1_127->ZN(new__32_);

    OAI22_X1_128 = new OAI22_X1("OAI22_X1_128");
        OAI22_X1_128->A1(new__36_);
        OAI22_X1_128->A2(new__114_);
        OAI22_X1_128->B1(new__132_);
        OAI22_X1_128->B2(new__96_);
        OAI22_X1_128->ZN(new__33_);

    INV_X1_129 = new INV_X1("INV_X1_129");
        INV_X1_129->A(reset);
        INV_X1_129->ZN(new__7_);

    DFFR_X1_130 = new DFFR_X1("DFFR_X1_130");
        DFFR_X1_130->CK(clock);
        DFFR_X1_130->D(new__8_);
        DFFR_X1_130->Q(new__163_);
        DFFR_X1_130->QN(new__6_);
        DFFR_X1_130->RN(new__7_);

    DFFR_X1_131 = new DFFR_X1("DFFR_X1_131");
        DFFR_X1_131->CK(clock);
        DFFR_X1_131->D(new__9_);
        DFFR_X1_131->Q(new__164_);
        DFFR_X1_131->QN(new__133_);
        DFFR_X1_131->RN(new__7_);

    DFFR_X1_132 = new DFFR_X1("DFFR_X1_132");
        DFFR_X1_132->CK(clock);
        DFFR_X1_132->D(new__10_);
        DFFR_X1_132->Q(new__165_);
        DFFR_X1_132->QN(new__134_);
        DFFR_X1_132->RN(new__7_);

    DFFR_X1_133 = new DFFR_X1("DFFR_X1_133");
        DFFR_X1_133->CK(clock);
        DFFR_X1_133->D(new__11_);
        DFFR_X1_133->Q(new__166_);
        DFFR_X1_133->QN(new__135_);
        DFFR_X1_133->RN(new__7_);

    DFFR_X1_134 = new DFFR_X1("DFFR_X1_134");
        DFFR_X1_134->CK(clock);
        DFFR_X1_134->D(new__12_);
        DFFR_X1_134->Q(new__167_);
        DFFR_X1_134->QN(new__136_);
        DFFR_X1_134->RN(new__7_);

    DFFR_X1_135 = new DFFR_X1("DFFR_X1_135");
        DFFR_X1_135->CK(clock);
        DFFR_X1_135->D(new__13_);
        DFFR_X1_135->Q(new__168_);
        DFFR_X1_135->QN(new__137_);
        DFFR_X1_135->RN(new__7_);

    DFFR_X1_136 = new DFFR_X1("DFFR_X1_136");
        DFFR_X1_136->CK(clock);
        DFFR_X1_136->D(new__14_);
        DFFR_X1_136->Q(new__169_);
        DFFR_X1_136->QN(new__5_);
        DFFR_X1_136->RN(new__7_);

    DFFR_X1_137 = new DFFR_X1("DFFR_X1_137");
        DFFR_X1_137->CK(clock);
        DFFR_X1_137->D(new__15_);
        DFFR_X1_137->Q(new__170_);
        DFFR_X1_137->QN(new__138_);
        DFFR_X1_137->RN(new__7_);

    DFFR_X1_138 = new DFFR_X1("DFFR_X1_138");
        DFFR_X1_138->CK(clock);
        DFFR_X1_138->D(new__16_);
        DFFR_X1_138->Q(new__172_);
        DFFR_X1_138->QN(new__139_);
        DFFR_X1_138->RN(new__7_);

    DFFR_X1_139 = new DFFR_X1("DFFR_X1_139");
        DFFR_X1_139->CK(clock);
        DFFR_X1_139->D(new__17_);
        DFFR_X1_139->Q(new__173_);
        DFFR_X1_139->QN(new__140_);
        DFFR_X1_139->RN(new__7_);

    DFFR_X1_140 = new DFFR_X1("DFFR_X1_140");
        DFFR_X1_140->CK(clock);
        DFFR_X1_140->D(new__18_);
        DFFR_X1_140->Q(new__174_);
        DFFR_X1_140->QN(new__141_);
        DFFR_X1_140->RN(new__7_);

    DFFR_X1_141 = new DFFR_X1("DFFR_X1_141");
        DFFR_X1_141->CK(clock);
        DFFR_X1_141->D(new__19_);
        DFFR_X1_141->Q(new__175_);
        DFFR_X1_141->QN(new__142_);
        DFFR_X1_141->RN(new__7_);

    DFFR_X1_142 = new DFFR_X1("DFFR_X1_142");
        DFFR_X1_142->CK(clock);
        DFFR_X1_142->D(new__20_);
        DFFR_X1_142->Q(new__176_);
        DFFR_X1_142->QN(new__143_);
        DFFR_X1_142->RN(new__7_);

    DFFR_X1_143 = new DFFR_X1("DFFR_X1_143");
        DFFR_X1_143->CK(clock);
        DFFR_X1_143->D(new__21_);
        DFFR_X1_143->Q(new__177_);
        DFFR_X1_143->QN(new__144_);
        DFFR_X1_143->RN(new__7_);

    DFFR_X1_144 = new DFFR_X1("DFFR_X1_144");
        DFFR_X1_144->CK(clock);
        DFFR_X1_144->D(new__22_);
        DFFR_X1_144->Q(new__178_);
        DFFR_X1_144->QN(new__145_);
        DFFR_X1_144->RN(new__7_);

    DFFR_X1_145 = new DFFR_X1("DFFR_X1_145");
        DFFR_X1_145->CK(clock);
        DFFR_X1_145->D(new__23_);
        DFFR_X1_145->Q(new__179_);
        DFFR_X1_145->QN(new__146_);
        DFFR_X1_145->RN(new__7_);

    DFFR_X1_146 = new DFFR_X1("DFFR_X1_146");
        DFFR_X1_146->CK(clock);
        DFFR_X1_146->D(new__24_);
        DFFR_X1_146->Q(new__180_);
        DFFR_X1_146->QN(new__147_);
        DFFR_X1_146->RN(new__7_);

    DFFR_X1_147 = new DFFR_X1("DFFR_X1_147");
        DFFR_X1_147->CK(clock);
        DFFR_X1_147->D(new__25_);
        DFFR_X1_147->Q(new__171_);
        DFFR_X1_147->QN(new__148_);
        DFFR_X1_147->RN(new__7_);

    DFFS_X1_148 = new DFFS_X1("DFFS_X1_148");
        DFFS_X1_148->CK(clock);
        DFFS_X1_148->D(new__1_);
        DFFS_X1_148->Q(new_state_0);
        DFFS_X1_148->QN(new__0_);
        DFFS_X1_148->SN(new__7_);

    DFFR_X1_149 = new DFFR_X1("DFFR_X1_149");
        DFFR_X1_149->CK(clock);
        DFFR_X1_149->D(new__3_);
        DFFR_X1_149->Q(new_state_1);
        DFFR_X1_149->QN(new__149_);
        DFFR_X1_149->RN(new__7_);

    DFFR_X1_150 = new DFFR_X1("DFFR_X1_150");
        DFFR_X1_150->CK(clock);
        DFFR_X1_150->D(new__2_);
        DFFR_X1_150->Q(new_state_2);
        DFFR_X1_150->QN(new__150_);
        DFFR_X1_150->RN(new__7_);

    DFFR_X1_151 = new DFFR_X1("DFFR_X1_151");
        DFFR_X1_151->CK(clock);
        DFFR_X1_151->D(new__4_);
        DFFR_X1_151->Q(new_state_3);
        DFFR_X1_151->QN(new__151_);
        DFFR_X1_151->RN(new__7_);

    DFFR_X1_152 = new DFFR_X1("DFFR_X1_152");
        DFFR_X1_152->CK(clock);
        DFFR_X1_152->D(new_state_2);
        DFFR_X1_152->Q(new_state_4);
        DFFR_X1_152->QN(new__152_);
        DFFR_X1_152->RN(new__7_);

    DFFR_X1_153 = new DFFR_X1("DFFR_X1_153");
        DFFR_X1_153->CK(clock);
        DFFR_X1_153->D(new__26_);
        DFFR_X1_153->Q(new__181_);
        DFFR_X1_153->QN(new__153_);
        DFFR_X1_153->RN(new__7_);

    DFFR_X1_154 = new DFFR_X1("DFFR_X1_154");
        DFFR_X1_154->CK(clock);
        DFFR_X1_154->D(new__27_);
        DFFR_X1_154->Q(new__182_);
        DFFR_X1_154->QN(new__154_);
        DFFR_X1_154->RN(new__7_);

    DFFR_X1_155 = new DFFR_X1("DFFR_X1_155");
        DFFR_X1_155->CK(clock);
        DFFR_X1_155->D(new__28_);
        DFFR_X1_155->Q(new__183_);
        DFFR_X1_155->QN(new__155_);
        DFFR_X1_155->RN(new__7_);

    DFFR_X1_156 = new DFFR_X1("DFFR_X1_156");
        DFFR_X1_156->CK(clock);
        DFFR_X1_156->D(new__29_);
        DFFR_X1_156->Q(new__184_);
        DFFR_X1_156->QN(new__156_);
        DFFR_X1_156->RN(new__7_);

    DFFR_X1_157 = new DFFR_X1("DFFR_X1_157");
        DFFR_X1_157->CK(clock);
        DFFR_X1_157->D(new__30_);
        DFFR_X1_157->Q(new__185_);
        DFFR_X1_157->QN(new__157_);
        DFFR_X1_157->RN(new__7_);

    DFFR_X1_158 = new DFFR_X1("DFFR_X1_158");
        DFFR_X1_158->CK(clock);
        DFFR_X1_158->D(new__31_);
        DFFR_X1_158->Q(new__186_);
        DFFR_X1_158->QN(new__158_);
        DFFR_X1_158->RN(new__7_);

    DFFR_X1_159 = new DFFR_X1("DFFR_X1_159");
        DFFR_X1_159->CK(clock);
        DFFR_X1_159->D(new__32_);
        DFFR_X1_159->Q(new__187_);
        DFFR_X1_159->QN(new__159_);
        DFFR_X1_159->RN(new__7_);

    DFFR_X1_160 = new DFFR_X1("DFFR_X1_160");
        DFFR_X1_160->CK(clock);
        DFFR_X1_160->D(new__33_);
        DFFR_X1_160->Q(new__188_);
        DFFR_X1_160->QN(new__160_);
        DFFR_X1_160->RN(new__7_);

    DFFR_X1_161 = new DFFR_X1("DFFR_X1_161");
        DFFR_X1_161->CK(clock);
        DFFR_X1_161->D(start);
        DFFR_X1_161->Q(new_startbuf_0);
        DFFR_X1_161->QN(new__161_);
        DFFR_X1_161->RN(new__7_);

    DFFR_X1_162 = new DFFR_X1("DFFR_X1_162");
        DFFR_X1_162->CK(clock);
        DFFR_X1_162->D(new_startbuf_0);
        DFFR_X1_162->Q(new_startbuf_1);
        DFFR_X1_162->QN(new__162_);
        DFFR_X1_162->RN(new__7_);

    BUF_X1_163 = new BUF_X1("BUF_X1_163");
        BUF_X1_163->A(new__163_);
        BUF_X1_163->Z(counter[0]);

    BUF_X1_164 = new BUF_X1("BUF_X1_164");
        BUF_X1_164->A(new__164_);
        BUF_X1_164->Z(counter[1]);

    BUF_X1_165 = new BUF_X1("BUF_X1_165");
        BUF_X1_165->A(new__165_);
        BUF_X1_165->Z(counter[2]);

    BUF_X1_166 = new BUF_X1("BUF_X1_166");
        BUF_X1_166->A(new__166_);
        BUF_X1_166->Z(counter[3]);

    BUF_X1_167 = new BUF_X1("BUF_X1_167");
        BUF_X1_167->A(new__167_);
        BUF_X1_167->Z(counter[4]);

    BUF_X1_168 = new BUF_X1("BUF_X1_168");
        BUF_X1_168->A(new__168_);
        BUF_X1_168->Z(counter[5]);

    BUF_X1_169 = new BUF_X1("BUF_X1_169");
        BUF_X1_169->A(new__169_);
        BUF_X1_169->Z(counter[6]);

    BUF_X1_170 = new BUF_X1("BUF_X1_170");
        BUF_X1_170->A(new__170_);
        BUF_X1_170->Z(counter[7]);

    BUF_X1_171 = new BUF_X1("BUF_X1_171");
        BUF_X1_171->A(new__171_);
        BUF_X1_171->Z(done);

    BUF_X1_172 = new BUF_X1("BUF_X1_172");
        BUF_X1_172->A(new__172_);
        BUF_X1_172->Z(dp[0]);

    BUF_X1_173 = new BUF_X1("BUF_X1_173");
        BUF_X1_173->A(new__173_);
        BUF_X1_173->Z(dp[1]);

    BUF_X1_174 = new BUF_X1("BUF_X1_174");
        BUF_X1_174->A(new__174_);
        BUF_X1_174->Z(dp[2]);

    BUF_X1_175 = new BUF_X1("BUF_X1_175");
        BUF_X1_175->A(new__175_);
        BUF_X1_175->Z(dp[3]);

    BUF_X1_176 = new BUF_X1("BUF_X1_176");
        BUF_X1_176->A(new__176_);
        BUF_X1_176->Z(dp[4]);

    BUF_X1_177 = new BUF_X1("BUF_X1_177");
        BUF_X1_177->A(new__177_);
        BUF_X1_177->Z(dp[5]);

    BUF_X1_178 = new BUF_X1("BUF_X1_178");
        BUF_X1_178->A(new__178_);
        BUF_X1_178->Z(dp[6]);

    BUF_X1_179 = new BUF_X1("BUF_X1_179");
        BUF_X1_179->A(new__179_);
        BUF_X1_179->Z(dp[7]);

    BUF_X1_180 = new BUF_X1("BUF_X1_180");
        BUF_X1_180->A(new__180_);
        BUF_X1_180->Z(dp[8]);

    BUF_X1_181 = new BUF_X1("BUF_X1_181");
        BUF_X1_181->A(new__181_);
        BUF_X1_181->Z(sr[0]);

    BUF_X1_182 = new BUF_X1("BUF_X1_182");
        BUF_X1_182->A(new__182_);
        BUF_X1_182->Z(sr[1]);

    BUF_X1_183 = new BUF_X1("BUF_X1_183");
        BUF_X1_183->A(new__183_);
        BUF_X1_183->Z(sr[2]);

    BUF_X1_184 = new BUF_X1("BUF_X1_184");
        BUF_X1_184->A(new__184_);
        BUF_X1_184->Z(sr[3]);

    BUF_X1_185 = new BUF_X1("BUF_X1_185");
        BUF_X1_185->A(new__185_);
        BUF_X1_185->Z(sr[4]);

    BUF_X1_186 = new BUF_X1("BUF_X1_186");
        BUF_X1_186->A(new__186_);
        BUF_X1_186->Z(sr[5]);

    BUF_X1_187 = new BUF_X1("BUF_X1_187");
        BUF_X1_187->A(new__187_);
        BUF_X1_187->Z(sr[6]);

    BUF_X1_188 = new BUF_X1("BUF_X1_188");
        BUF_X1_188->A(new__188_);
        BUF_X1_188->Z(sr[7]);


    SC_METHOD(sc_logic_signal_assignment);

    }

    void sc_logic_signal_assignment(void){ 
        sc_logic_1_signal.write(SC_LOGIC_1);
        sc_logic_0_signal.write(SC_LOGIC_0);
    }
};
