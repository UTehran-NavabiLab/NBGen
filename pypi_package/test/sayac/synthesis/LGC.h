#include <systemc.h>
#include "Complex_NAgate_45.h"

#include "ccu.h"
#include "dpu.h"


#ifndef __LGC_H__
#define __LGC_H__
using namespace sc_core;

SC_MODULE( LGC ) {

    sc_in<sc_logic> clk;
    sc_in<sc_logic> rst;
    sc_in<sc_logic> readyMEM;
    sc_in<sc_logic> dataBusIn[16];
    sc_in<sc_logic> p1TRF[16];
    sc_in<sc_logic> p2TRF[16];
    sc_out<sc_logic> readMM;
    sc_out<sc_logic> writeMM;
    sc_out<sc_logic> dataBusOut[16];
    sc_out<sc_logic> addrBus[16];
    sc_out<sc_logic> outMuxrs1[4];
    sc_out<sc_logic> outMuxrs2[4];
    sc_out<sc_logic> outMuxrd[4];
    sc_out<sc_logic> inDataTRF[16];
    sc_out<sc_logic> writeTRF;
    sc_out<sc_logic> readInst;

    sc_signal<sc_logic> sc_logic_1_signal;
    sc_signal<sc_logic> sc_logic_0_signal;

    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S0 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S0");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S1 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S1");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S2 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S2");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S3 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S3");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S4[16];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S5 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S5");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S6[16];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S7[16];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S8[16];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S9[4];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S10[4];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S11[4];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S12[16];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S13[16];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S14 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S14");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S15 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S15");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S16 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S16");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S17 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S17");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S18 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S18");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S19 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S19");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> arithadd = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("arithadd");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> arithdiv = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("arithdiv");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> arithmul = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("arithmul");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> arithsh = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("arithsh");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> arithsub = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("arithsub");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> drivedatabus = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("drivedatabus");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> enflag = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("enflag");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> fib_0_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("fib_0_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> fib_1_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("fib_1_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> fib_2_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("fib_2_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> fib_3_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("fib_3_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> fib_4_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("fib_4_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> ldadr = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("ldadr");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> ldir = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("ldir");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> ldmdu1 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("ldmdu1");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> ldmdu2 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("ldmdu2");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> ldpc = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("ldpc");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> logicand = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("logicand");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> logicsh = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("logicsh");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> onescomp = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("onescomp");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> opcode_0_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("opcode_0_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> opcode_1_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("opcode_1_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> opcode_2_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("opcode_2_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> opcode_3_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("opcode_3_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> opcode_4_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("opcode_4_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> opcode_5_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("opcode_5_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> opcode_6_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("opcode_6_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> opcode_7_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("opcode_7_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outflag_0_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outflag_0_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outflag_1_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outflag_1_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outflag_2_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outflag_2_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outflag_3_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outflag_3_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outflag_4_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outflag_4_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outflag_5_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outflag_5_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outflag_6_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outflag_6_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outflag_7_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outflag_7_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> p1lowbits = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("p1lowbits");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> readio = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("readio");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> readmem = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("readmem");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> readymdu = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("readymdu");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> se5bits = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("se5bits");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> se6bits = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("se6bits");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> se8bits = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("se8bits");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> seladr_mem = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("seladr_mem");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> selasu_trf = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("selasu_trf");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> seldatabus_trf = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("seldatabus_trf");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> selflag_0_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("selflag_0_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> selflag_1_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("selflag_1_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> selflag_2_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("selflag_2_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> selflag_3_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("selflag_3_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> selflag_4_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("selflag_4_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> selflag_5_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("selflag_5_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> selflag_6_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("selflag_6_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> selflag_7_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("selflag_7_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> selimm_asu = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("selimm_asu");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> selimm_pcp = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("selimm_pcp");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> selimm_trf = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("selimm_trf");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> selllu_trf = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("selllu_trf");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> selmdu1_trf = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("selmdu1_trf");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> selmdu2_trf = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("selmdu2_trf");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> selp1_pc = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("selp1_pc");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> selp1_pcp = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("selp1_pcp");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> selp2_asu = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("selp2_asu");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> selp2_shu = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("selp2_shu");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> selpc1_pc = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("selpc1_pc");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> selpc1_trf = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("selpc1_trf");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> selpcadd_pc = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("selpcadd_pc");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> selrd0_trf = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("selrd0_trf");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> selrd1_trf = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("selrd1_trf");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> selrd_1_trf = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("selrd_1_trf");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> selrd_2_trf = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("selrd_2_trf");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> selrs1_trf = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("selrs1_trf");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> selrs2_trf = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("selrs2_trf");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> selshim_shu = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("selshim_shu");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> selshu_trf = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("selshu_trf");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> setflags = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("setflags");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> startmdu = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("startmdu");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> twoscomp = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("twoscomp");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> use8bits = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("use8bits");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> writeio = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("writeio");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> writemem = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("writemem");

    INV_X1* INV_X1_1;
    INV_X1* INV_X1_2;
    NAND2_X1* NAND2_X1_1;
    INV_X1* INV_X1_3;
    INV_X1* INV_X1_4;
    NAND2_X1* NAND2_X1_2;
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
    ccu* controller;
    dpu* datapath;

SC_CTOR( LGC ) {
    INV_X1_1 = new INV_X1("INV_X1_1");
        INV_X1_1->A(readio);
        INV_X1_1->ZN(S2);

    INV_X1_2 = new INV_X1("INV_X1_2");
        INV_X1_2->A(readmem);
        INV_X1_2->ZN(S3);

    NAND2_X1_1 = new NAND2_X1("NAND2_X1_1");
        NAND2_X1_1->A1(S2);
        NAND2_X1_1->A2(S3);
        NAND2_X1_1->ZN(S15);

    INV_X1_3 = new INV_X1("INV_X1_3");
        INV_X1_3->A(writeio);
        INV_X1_3->ZN(S0);

    INV_X1_4 = new INV_X1("INV_X1_4");
        INV_X1_4->A(writemem);
        INV_X1_4->ZN(S1);

    NAND2_X1_2 = new NAND2_X1("NAND2_X1_2");
        NAND2_X1_2->A1(S0);
        NAND2_X1_2->A2(S1);
        NAND2_X1_2->ZN(S18);

    BUF_X1_1 = new BUF_X1("BUF_X1_1");
        BUF_X1_1->A(S4[0]);
        BUF_X1_1->Z(addrBus[0]);

    BUF_X1_2 = new BUF_X1("BUF_X1_2");
        BUF_X1_2->A(S4[1]);
        BUF_X1_2->Z(addrBus[1]);

    BUF_X1_3 = new BUF_X1("BUF_X1_3");
        BUF_X1_3->A(S4[10]);
        BUF_X1_3->Z(addrBus[10]);

    BUF_X1_4 = new BUF_X1("BUF_X1_4");
        BUF_X1_4->A(S4[11]);
        BUF_X1_4->Z(addrBus[11]);

    BUF_X1_5 = new BUF_X1("BUF_X1_5");
        BUF_X1_5->A(S4[12]);
        BUF_X1_5->Z(addrBus[12]);

    BUF_X1_6 = new BUF_X1("BUF_X1_6");
        BUF_X1_6->A(S4[13]);
        BUF_X1_6->Z(addrBus[13]);

    BUF_X1_7 = new BUF_X1("BUF_X1_7");
        BUF_X1_7->A(S4[14]);
        BUF_X1_7->Z(addrBus[14]);

    BUF_X1_8 = new BUF_X1("BUF_X1_8");
        BUF_X1_8->A(S4[15]);
        BUF_X1_8->Z(addrBus[15]);

    BUF_X1_9 = new BUF_X1("BUF_X1_9");
        BUF_X1_9->A(S4[2]);
        BUF_X1_9->Z(addrBus[2]);

    BUF_X1_10 = new BUF_X1("BUF_X1_10");
        BUF_X1_10->A(S4[3]);
        BUF_X1_10->Z(addrBus[3]);

    BUF_X1_11 = new BUF_X1("BUF_X1_11");
        BUF_X1_11->A(S4[4]);
        BUF_X1_11->Z(addrBus[4]);

    BUF_X1_12 = new BUF_X1("BUF_X1_12");
        BUF_X1_12->A(S4[5]);
        BUF_X1_12->Z(addrBus[5]);

    BUF_X1_13 = new BUF_X1("BUF_X1_13");
        BUF_X1_13->A(S4[6]);
        BUF_X1_13->Z(addrBus[6]);

    BUF_X1_14 = new BUF_X1("BUF_X1_14");
        BUF_X1_14->A(S4[7]);
        BUF_X1_14->Z(addrBus[7]);

    BUF_X1_15 = new BUF_X1("BUF_X1_15");
        BUF_X1_15->A(S4[8]);
        BUF_X1_15->Z(addrBus[8]);

    BUF_X1_16 = new BUF_X1("BUF_X1_16");
        BUF_X1_16->A(S4[9]);
        BUF_X1_16->Z(addrBus[9]);

    BUF_X1_17 = new BUF_X1("BUF_X1_17");
        BUF_X1_17->A(clk);
        BUF_X1_17->Z(S5);

    BUF_X1_18 = new BUF_X1("BUF_X1_18");
        BUF_X1_18->A(dataBusIn[0]);
        BUF_X1_18->Z(S6[0]);

    BUF_X1_19 = new BUF_X1("BUF_X1_19");
        BUF_X1_19->A(dataBusIn[1]);
        BUF_X1_19->Z(S6[1]);

    BUF_X1_20 = new BUF_X1("BUF_X1_20");
        BUF_X1_20->A(dataBusIn[10]);
        BUF_X1_20->Z(S6[10]);

    BUF_X1_21 = new BUF_X1("BUF_X1_21");
        BUF_X1_21->A(dataBusIn[11]);
        BUF_X1_21->Z(S6[11]);

    BUF_X1_22 = new BUF_X1("BUF_X1_22");
        BUF_X1_22->A(dataBusIn[12]);
        BUF_X1_22->Z(S6[12]);

    BUF_X1_23 = new BUF_X1("BUF_X1_23");
        BUF_X1_23->A(dataBusIn[13]);
        BUF_X1_23->Z(S6[13]);

    BUF_X1_24 = new BUF_X1("BUF_X1_24");
        BUF_X1_24->A(dataBusIn[14]);
        BUF_X1_24->Z(S6[14]);

    BUF_X1_25 = new BUF_X1("BUF_X1_25");
        BUF_X1_25->A(dataBusIn[15]);
        BUF_X1_25->Z(S6[15]);

    BUF_X1_26 = new BUF_X1("BUF_X1_26");
        BUF_X1_26->A(dataBusIn[2]);
        BUF_X1_26->Z(S6[2]);

    BUF_X1_27 = new BUF_X1("BUF_X1_27");
        BUF_X1_27->A(dataBusIn[3]);
        BUF_X1_27->Z(S6[3]);

    BUF_X1_28 = new BUF_X1("BUF_X1_28");
        BUF_X1_28->A(dataBusIn[4]);
        BUF_X1_28->Z(S6[4]);

    BUF_X1_29 = new BUF_X1("BUF_X1_29");
        BUF_X1_29->A(dataBusIn[5]);
        BUF_X1_29->Z(S6[5]);

    BUF_X1_30 = new BUF_X1("BUF_X1_30");
        BUF_X1_30->A(dataBusIn[6]);
        BUF_X1_30->Z(S6[6]);

    BUF_X1_31 = new BUF_X1("BUF_X1_31");
        BUF_X1_31->A(dataBusIn[7]);
        BUF_X1_31->Z(S6[7]);

    BUF_X1_32 = new BUF_X1("BUF_X1_32");
        BUF_X1_32->A(dataBusIn[8]);
        BUF_X1_32->Z(S6[8]);

    BUF_X1_33 = new BUF_X1("BUF_X1_33");
        BUF_X1_33->A(dataBusIn[9]);
        BUF_X1_33->Z(S6[9]);

    BUF_X1_34 = new BUF_X1("BUF_X1_34");
        BUF_X1_34->A(S7[0]);
        BUF_X1_34->Z(dataBusOut[0]);

    BUF_X1_35 = new BUF_X1("BUF_X1_35");
        BUF_X1_35->A(S7[1]);
        BUF_X1_35->Z(dataBusOut[1]);

    BUF_X1_36 = new BUF_X1("BUF_X1_36");
        BUF_X1_36->A(S7[2]);
        BUF_X1_36->Z(dataBusOut[2]);

    BUF_X1_37 = new BUF_X1("BUF_X1_37");
        BUF_X1_37->A(S7[3]);
        BUF_X1_37->Z(dataBusOut[3]);

    BUF_X1_38 = new BUF_X1("BUF_X1_38");
        BUF_X1_38->A(S7[4]);
        BUF_X1_38->Z(dataBusOut[4]);

    BUF_X1_39 = new BUF_X1("BUF_X1_39");
        BUF_X1_39->A(S7[5]);
        BUF_X1_39->Z(dataBusOut[5]);

    BUF_X1_40 = new BUF_X1("BUF_X1_40");
        BUF_X1_40->A(S7[6]);
        BUF_X1_40->Z(dataBusOut[6]);

    BUF_X1_41 = new BUF_X1("BUF_X1_41");
        BUF_X1_41->A(S7[7]);
        BUF_X1_41->Z(dataBusOut[7]);

    BUF_X1_42 = new BUF_X1("BUF_X1_42");
        BUF_X1_42->A(S8[0]);
        BUF_X1_42->Z(inDataTRF[0]);

    BUF_X1_43 = new BUF_X1("BUF_X1_43");
        BUF_X1_43->A(S8[1]);
        BUF_X1_43->Z(inDataTRF[1]);

    BUF_X1_44 = new BUF_X1("BUF_X1_44");
        BUF_X1_44->A(S8[10]);
        BUF_X1_44->Z(inDataTRF[10]);

    BUF_X1_45 = new BUF_X1("BUF_X1_45");
        BUF_X1_45->A(S8[11]);
        BUF_X1_45->Z(inDataTRF[11]);

    BUF_X1_46 = new BUF_X1("BUF_X1_46");
        BUF_X1_46->A(S8[12]);
        BUF_X1_46->Z(inDataTRF[12]);

    BUF_X1_47 = new BUF_X1("BUF_X1_47");
        BUF_X1_47->A(S8[13]);
        BUF_X1_47->Z(inDataTRF[13]);

    BUF_X1_48 = new BUF_X1("BUF_X1_48");
        BUF_X1_48->A(S8[14]);
        BUF_X1_48->Z(inDataTRF[14]);

    BUF_X1_49 = new BUF_X1("BUF_X1_49");
        BUF_X1_49->A(S8[15]);
        BUF_X1_49->Z(inDataTRF[15]);

    BUF_X1_50 = new BUF_X1("BUF_X1_50");
        BUF_X1_50->A(S8[2]);
        BUF_X1_50->Z(inDataTRF[2]);

    BUF_X1_51 = new BUF_X1("BUF_X1_51");
        BUF_X1_51->A(S8[3]);
        BUF_X1_51->Z(inDataTRF[3]);

    BUF_X1_52 = new BUF_X1("BUF_X1_52");
        BUF_X1_52->A(S8[4]);
        BUF_X1_52->Z(inDataTRF[4]);

    BUF_X1_53 = new BUF_X1("BUF_X1_53");
        BUF_X1_53->A(S8[5]);
        BUF_X1_53->Z(inDataTRF[5]);

    BUF_X1_54 = new BUF_X1("BUF_X1_54");
        BUF_X1_54->A(S8[6]);
        BUF_X1_54->Z(inDataTRF[6]);

    BUF_X1_55 = new BUF_X1("BUF_X1_55");
        BUF_X1_55->A(S8[7]);
        BUF_X1_55->Z(inDataTRF[7]);

    BUF_X1_56 = new BUF_X1("BUF_X1_56");
        BUF_X1_56->A(S8[8]);
        BUF_X1_56->Z(inDataTRF[8]);

    BUF_X1_57 = new BUF_X1("BUF_X1_57");
        BUF_X1_57->A(S8[9]);
        BUF_X1_57->Z(inDataTRF[9]);

    BUF_X1_58 = new BUF_X1("BUF_X1_58");
        BUF_X1_58->A(S9[0]);
        BUF_X1_58->Z(outMuxrd[0]);

    BUF_X1_59 = new BUF_X1("BUF_X1_59");
        BUF_X1_59->A(S9[1]);
        BUF_X1_59->Z(outMuxrd[1]);

    BUF_X1_60 = new BUF_X1("BUF_X1_60");
        BUF_X1_60->A(S9[2]);
        BUF_X1_60->Z(outMuxrd[2]);

    BUF_X1_61 = new BUF_X1("BUF_X1_61");
        BUF_X1_61->A(S9[3]);
        BUF_X1_61->Z(outMuxrd[3]);

    BUF_X1_62 = new BUF_X1("BUF_X1_62");
        BUF_X1_62->A(S10[0]);
        BUF_X1_62->Z(outMuxrs1[0]);

    BUF_X1_63 = new BUF_X1("BUF_X1_63");
        BUF_X1_63->A(S10[1]);
        BUF_X1_63->Z(outMuxrs1[1]);

    BUF_X1_64 = new BUF_X1("BUF_X1_64");
        BUF_X1_64->A(S10[2]);
        BUF_X1_64->Z(outMuxrs1[2]);

    BUF_X1_65 = new BUF_X1("BUF_X1_65");
        BUF_X1_65->A(S10[3]);
        BUF_X1_65->Z(outMuxrs1[3]);

    BUF_X1_66 = new BUF_X1("BUF_X1_66");
        BUF_X1_66->A(S11[0]);
        BUF_X1_66->Z(outMuxrs2[0]);

    BUF_X1_67 = new BUF_X1("BUF_X1_67");
        BUF_X1_67->A(S11[1]);
        BUF_X1_67->Z(outMuxrs2[1]);

    BUF_X1_68 = new BUF_X1("BUF_X1_68");
        BUF_X1_68->A(S11[2]);
        BUF_X1_68->Z(outMuxrs2[2]);

    BUF_X1_69 = new BUF_X1("BUF_X1_69");
        BUF_X1_69->A(S11[3]);
        BUF_X1_69->Z(outMuxrs2[3]);

    BUF_X1_70 = new BUF_X1("BUF_X1_70");
        BUF_X1_70->A(p1TRF[0]);
        BUF_X1_70->Z(S12[0]);

    BUF_X1_71 = new BUF_X1("BUF_X1_71");
        BUF_X1_71->A(p1TRF[1]);
        BUF_X1_71->Z(S12[1]);

    BUF_X1_72 = new BUF_X1("BUF_X1_72");
        BUF_X1_72->A(p1TRF[10]);
        BUF_X1_72->Z(S12[10]);

    BUF_X1_73 = new BUF_X1("BUF_X1_73");
        BUF_X1_73->A(p1TRF[11]);
        BUF_X1_73->Z(S12[11]);

    BUF_X1_74 = new BUF_X1("BUF_X1_74");
        BUF_X1_74->A(p1TRF[12]);
        BUF_X1_74->Z(S12[12]);

    BUF_X1_75 = new BUF_X1("BUF_X1_75");
        BUF_X1_75->A(p1TRF[13]);
        BUF_X1_75->Z(S12[13]);

    BUF_X1_76 = new BUF_X1("BUF_X1_76");
        BUF_X1_76->A(p1TRF[14]);
        BUF_X1_76->Z(S12[14]);

    BUF_X1_77 = new BUF_X1("BUF_X1_77");
        BUF_X1_77->A(p1TRF[15]);
        BUF_X1_77->Z(S12[15]);

    BUF_X1_78 = new BUF_X1("BUF_X1_78");
        BUF_X1_78->A(p1TRF[2]);
        BUF_X1_78->Z(S12[2]);

    BUF_X1_79 = new BUF_X1("BUF_X1_79");
        BUF_X1_79->A(p1TRF[3]);
        BUF_X1_79->Z(S12[3]);

    BUF_X1_80 = new BUF_X1("BUF_X1_80");
        BUF_X1_80->A(p1TRF[4]);
        BUF_X1_80->Z(S12[4]);

    BUF_X1_81 = new BUF_X1("BUF_X1_81");
        BUF_X1_81->A(p1TRF[5]);
        BUF_X1_81->Z(S12[5]);

    BUF_X1_82 = new BUF_X1("BUF_X1_82");
        BUF_X1_82->A(p1TRF[6]);
        BUF_X1_82->Z(S12[6]);

    BUF_X1_83 = new BUF_X1("BUF_X1_83");
        BUF_X1_83->A(p1TRF[7]);
        BUF_X1_83->Z(S12[7]);

    BUF_X1_84 = new BUF_X1("BUF_X1_84");
        BUF_X1_84->A(p1TRF[8]);
        BUF_X1_84->Z(S12[8]);

    BUF_X1_85 = new BUF_X1("BUF_X1_85");
        BUF_X1_85->A(p1TRF[9]);
        BUF_X1_85->Z(S12[9]);

    BUF_X1_86 = new BUF_X1("BUF_X1_86");
        BUF_X1_86->A(p2TRF[0]);
        BUF_X1_86->Z(S13[0]);

    BUF_X1_87 = new BUF_X1("BUF_X1_87");
        BUF_X1_87->A(p2TRF[1]);
        BUF_X1_87->Z(S13[1]);

    BUF_X1_88 = new BUF_X1("BUF_X1_88");
        BUF_X1_88->A(p2TRF[10]);
        BUF_X1_88->Z(S13[10]);

    BUF_X1_89 = new BUF_X1("BUF_X1_89");
        BUF_X1_89->A(p2TRF[11]);
        BUF_X1_89->Z(S13[11]);

    BUF_X1_90 = new BUF_X1("BUF_X1_90");
        BUF_X1_90->A(p2TRF[12]);
        BUF_X1_90->Z(S13[12]);

    BUF_X1_91 = new BUF_X1("BUF_X1_91");
        BUF_X1_91->A(p2TRF[13]);
        BUF_X1_91->Z(S13[13]);

    BUF_X1_92 = new BUF_X1("BUF_X1_92");
        BUF_X1_92->A(p2TRF[14]);
        BUF_X1_92->Z(S13[14]);

    BUF_X1_93 = new BUF_X1("BUF_X1_93");
        BUF_X1_93->A(p2TRF[15]);
        BUF_X1_93->Z(S13[15]);

    BUF_X1_94 = new BUF_X1("BUF_X1_94");
        BUF_X1_94->A(p2TRF[2]);
        BUF_X1_94->Z(S13[2]);

    BUF_X1_95 = new BUF_X1("BUF_X1_95");
        BUF_X1_95->A(p2TRF[3]);
        BUF_X1_95->Z(S13[3]);

    BUF_X1_96 = new BUF_X1("BUF_X1_96");
        BUF_X1_96->A(p2TRF[4]);
        BUF_X1_96->Z(S13[4]);

    BUF_X1_97 = new BUF_X1("BUF_X1_97");
        BUF_X1_97->A(p2TRF[5]);
        BUF_X1_97->Z(S13[5]);

    BUF_X1_98 = new BUF_X1("BUF_X1_98");
        BUF_X1_98->A(p2TRF[6]);
        BUF_X1_98->Z(S13[6]);

    BUF_X1_99 = new BUF_X1("BUF_X1_99");
        BUF_X1_99->A(p2TRF[7]);
        BUF_X1_99->Z(S13[7]);

    BUF_X1_100 = new BUF_X1("BUF_X1_100");
        BUF_X1_100->A(p2TRF[8]);
        BUF_X1_100->Z(S13[8]);

    BUF_X1_101 = new BUF_X1("BUF_X1_101");
        BUF_X1_101->A(p2TRF[9]);
        BUF_X1_101->Z(S13[9]);

    BUF_X1_102 = new BUF_X1("BUF_X1_102");
        BUF_X1_102->A(S14);
        BUF_X1_102->Z(readInst);

    BUF_X1_103 = new BUF_X1("BUF_X1_103");
        BUF_X1_103->A(S15);
        BUF_X1_103->Z(readMM);

    BUF_X1_104 = new BUF_X1("BUF_X1_104");
        BUF_X1_104->A(readyMEM);
        BUF_X1_104->Z(S16);

    BUF_X1_105 = new BUF_X1("BUF_X1_105");
        BUF_X1_105->A(rst);
        BUF_X1_105->Z(S17);

    BUF_X1_106 = new BUF_X1("BUF_X1_106");
        BUF_X1_106->A(S18);
        BUF_X1_106->Z(writeMM);

    BUF_X1_107 = new BUF_X1("BUF_X1_107");
        BUF_X1_107->A(S19);
        BUF_X1_107->Z(writeTRF);

    controller = new ccu("controller");
        controller->arithadd(arithadd);
        controller->arithdiv(arithdiv);
        controller->arithmul(arithmul);
        controller->arithsh(arithsh);
        controller->arithsub(arithsub);
        controller->clk(S5);
        controller->drivedatabus(drivedatabus);
        controller->enflag(enflag);
        controller->fib[0](fib_0_);
        controller->fib[1](fib_1_);
        controller->fib[2](fib_2_);
        controller->fib[3](fib_3_);
        controller->fib[4](fib_4_);
        controller->ldadr(ldadr);
        controller->ldir(ldir);
        controller->ldmdu1(ldmdu1);
        controller->ldmdu2(ldmdu2);
        controller->ldpc(ldpc);
        controller->logicand(logicand);
        controller->logicsh(logicsh);
        controller->onescomp(onescomp);
        controller->opcode[0](opcode_0_);
        controller->opcode[1](opcode_1_);
        controller->opcode[2](opcode_2_);
        controller->opcode[3](opcode_3_);
        controller->opcode[4](opcode_4_);
        controller->opcode[5](opcode_5_);
        controller->opcode[6](opcode_6_);
        controller->opcode[7](opcode_7_);
        controller->outflag[0](outflag_0_);
        controller->outflag[1](outflag_1_);
        controller->outflag[2](outflag_2_);
        controller->outflag[3](outflag_3_);
        controller->outflag[4](outflag_4_);
        controller->outflag[5](outflag_5_);
        controller->outflag[6](outflag_6_);
        controller->outflag[7](outflag_7_);
        controller->p1lowbits(p1lowbits);
        controller->readio(readio);
        controller->readmem(readmem);
        controller->readymdu(readymdu);
        controller->readymem(S16);
        controller->rst(S17);
        controller->se5bits(se5bits);
        controller->se6bits(se6bits);
        controller->se8bits(se8bits);
        controller->seladr_mem(seladr_mem);
        controller->selasu_trf(selasu_trf);
        controller->seldatabus_trf(seldatabus_trf);
        controller->selflag[0](selflag_0_);
        controller->selflag[1](selflag_1_);
        controller->selflag[2](selflag_2_);
        controller->selflag[3](selflag_3_);
        controller->selflag[4](selflag_4_);
        controller->selflag[5](selflag_5_);
        controller->selflag[6](selflag_6_);
        controller->selflag[7](selflag_7_);
        controller->selimm_asu(selimm_asu);
        controller->selimm_pcp(selimm_pcp);
        controller->selimm_trf(selimm_trf);
        controller->selllu_trf(selllu_trf);
        controller->selmdu1_trf(selmdu1_trf);
        controller->selmdu2_trf(selmdu2_trf);
        controller->selp1_pc(selp1_pc);
        controller->selp1_pcp(selp1_pcp);
        controller->selp2_asu(selp2_asu);
        controller->selp2_shu(selp2_shu);
        controller->selpc1_pc(selpc1_pc);
        controller->selpc1_trf(selpc1_trf);
        controller->selpc_mem(S14);
        controller->selpcadd_pc(selpcadd_pc);
        controller->selrd0_trf(selrd0_trf);
        controller->selrd1_trf(selrd1_trf);
        controller->selrd_1_trf(selrd_1_trf);
        controller->selrd_2_trf(selrd_2_trf);
        controller->selrs1_trf(selrs1_trf);
        controller->selrs2_trf(selrs2_trf);
        controller->selshim_shu(selshim_shu);
        controller->selshu_trf(selshu_trf);
        controller->setflags(setflags);
        controller->startmdu(startmdu);
        controller->twoscomp(twoscomp);
        controller->use8bits(use8bits);
        controller->writeio(writeio);
        controller->writemem(writemem);
        controller->writetrf(S19);

    datapath = new dpu("datapath");
        datapath->addrbus[0](S4[0]);
        datapath->addrbus[1](S4[1]);
        datapath->addrbus[2](S4[2]);
        datapath->addrbus[3](S4[3]);
        datapath->addrbus[4](S4[4]);
        datapath->addrbus[5](S4[5]);
        datapath->addrbus[6](S4[6]);
        datapath->addrbus[7](S4[7]);
        datapath->addrbus[8](S4[8]);
        datapath->addrbus[9](S4[9]);
        datapath->addrbus[10](S4[10]);
        datapath->addrbus[11](S4[11]);
        datapath->addrbus[12](S4[12]);
        datapath->addrbus[13](S4[13]);
        datapath->addrbus[14](S4[14]);
        datapath->addrbus[15](S4[15]);
        datapath->arithadd(arithadd);
        datapath->arithdiv(arithdiv);
        datapath->arithmul(arithmul);
        datapath->arithsh(arithsh);
        datapath->arithsub(arithsub);
        datapath->clk(S5);
        datapath->databusin[0](S6[0]);
        datapath->databusin[1](S6[1]);
        datapath->databusin[2](S6[2]);
        datapath->databusin[3](S6[3]);
        datapath->databusin[4](S6[4]);
        datapath->databusin[5](S6[5]);
        datapath->databusin[6](S6[6]);
        datapath->databusin[7](S6[7]);
        datapath->databusin[8](S6[8]);
        datapath->databusin[9](S6[9]);
        datapath->databusin[10](S6[10]);
        datapath->databusin[11](S6[11]);
        datapath->databusin[12](S6[12]);
        datapath->databusin[13](S6[13]);
        datapath->databusin[14](S6[14]);
        datapath->databusin[15](S6[15]);
        datapath->databusout[0](S7[0]);
        datapath->databusout[1](S7[1]);
        datapath->databusout[2](S7[2]);
        datapath->databusout[3](S7[3]);
        datapath->databusout[4](S7[4]);
        datapath->databusout[5](S7[5]);
        datapath->databusout[6](S7[6]);
        datapath->databusout[7](S7[7]);
        datapath->databusout[8](S7[8]);
        datapath->databusout[9](S7[9]);
        datapath->databusout[10](S7[10]);
        datapath->databusout[11](S7[11]);
        datapath->databusout[12](S7[12]);
        datapath->databusout[13](S7[13]);
        datapath->databusout[14](S7[14]);
        datapath->databusout[15](S7[15]);
        datapath->drivedatabus(drivedatabus);
        datapath->enflag(enflag);
        datapath->fib[0](fib_0_);
        datapath->fib[1](fib_1_);
        datapath->fib[2](fib_2_);
        datapath->fib[3](fib_3_);
        datapath->fib[4](fib_4_);
        datapath->indatatrf[0](S8[0]);
        datapath->indatatrf[1](S8[1]);
        datapath->indatatrf[2](S8[2]);
        datapath->indatatrf[3](S8[3]);
        datapath->indatatrf[4](S8[4]);
        datapath->indatatrf[5](S8[5]);
        datapath->indatatrf[6](S8[6]);
        datapath->indatatrf[7](S8[7]);
        datapath->indatatrf[8](S8[8]);
        datapath->indatatrf[9](S8[9]);
        datapath->indatatrf[10](S8[10]);
        datapath->indatatrf[11](S8[11]);
        datapath->indatatrf[12](S8[12]);
        datapath->indatatrf[13](S8[13]);
        datapath->indatatrf[14](S8[14]);
        datapath->indatatrf[15](S8[15]);
        datapath->ldadr(ldadr);
        datapath->ldir(ldir);
        datapath->ldmdu1(ldmdu1);
        datapath->ldmdu2(ldmdu2);
        datapath->ldpc(ldpc);
        datapath->logicand(logicand);
        datapath->logicsh(logicsh);
        datapath->onescomp(onescomp);
        datapath->opcode[0](opcode_0_);
        datapath->opcode[1](opcode_1_);
        datapath->opcode[2](opcode_2_);
        datapath->opcode[3](opcode_3_);
        datapath->opcode[4](opcode_4_);
        datapath->opcode[5](opcode_5_);
        datapath->opcode[6](opcode_6_);
        datapath->opcode[7](opcode_7_);
        datapath->outflag[0](outflag_0_);
        datapath->outflag[1](outflag_1_);
        datapath->outflag[2](outflag_2_);
        datapath->outflag[3](outflag_3_);
        datapath->outflag[4](outflag_4_);
        datapath->outflag[5](outflag_5_);
        datapath->outflag[6](outflag_6_);
        datapath->outflag[7](outflag_7_);
        datapath->outmuxrd[0](S9[0]);
        datapath->outmuxrd[1](S9[1]);
        datapath->outmuxrd[2](S9[2]);
        datapath->outmuxrd[3](S9[3]);
        datapath->outmuxrs1[0](S10[0]);
        datapath->outmuxrs1[1](S10[1]);
        datapath->outmuxrs1[2](S10[2]);
        datapath->outmuxrs1[3](S10[3]);
        datapath->outmuxrs2[0](S11[0]);
        datapath->outmuxrs2[1](S11[1]);
        datapath->outmuxrs2[2](S11[2]);
        datapath->outmuxrs2[3](S11[3]);
        datapath->p1lowbits(p1lowbits);
        datapath->p1trf[0](S12[0]);
        datapath->p1trf[1](S12[1]);
        datapath->p1trf[2](S12[2]);
        datapath->p1trf[3](S12[3]);
        datapath->p1trf[4](S12[4]);
        datapath->p1trf[5](S12[5]);
        datapath->p1trf[6](S12[6]);
        datapath->p1trf[7](S12[7]);
        datapath->p1trf[8](S12[8]);
        datapath->p1trf[9](S12[9]);
        datapath->p1trf[10](S12[10]);
        datapath->p1trf[11](S12[11]);
        datapath->p1trf[12](S12[12]);
        datapath->p1trf[13](S12[13]);
        datapath->p1trf[14](S12[14]);
        datapath->p1trf[15](S12[15]);
        datapath->p2trf[0](S13[0]);
        datapath->p2trf[1](S13[1]);
        datapath->p2trf[2](S13[2]);
        datapath->p2trf[3](S13[3]);
        datapath->p2trf[4](S13[4]);
        datapath->p2trf[5](S13[5]);
        datapath->p2trf[6](S13[6]);
        datapath->p2trf[7](S13[7]);
        datapath->p2trf[8](S13[8]);
        datapath->p2trf[9](S13[9]);
        datapath->p2trf[10](S13[10]);
        datapath->p2trf[11](S13[11]);
        datapath->p2trf[12](S13[12]);
        datapath->p2trf[13](S13[13]);
        datapath->p2trf[14](S13[14]);
        datapath->p2trf[15](S13[15]);
        datapath->readymdu(readymdu);
        datapath->rst(S17);
        datapath->se5bits(se5bits);
        datapath->se6bits(se6bits);
        datapath->se8bits(se8bits);
        datapath->seladr_mem(seladr_mem);
        datapath->selasu_trf(selasu_trf);
        datapath->seldatabus_trf(seldatabus_trf);
        datapath->selflag[0](selflag_0_);
        datapath->selflag[1](selflag_1_);
        datapath->selflag[2](selflag_2_);
        datapath->selflag[3](selflag_3_);
        datapath->selflag[4](selflag_4_);
        datapath->selflag[5](selflag_5_);
        datapath->selflag[6](selflag_6_);
        datapath->selflag[7](selflag_7_);
        datapath->selimm_asu(selimm_asu);
        datapath->selimm_pcp(selimm_pcp);
        datapath->selimm_trf(selimm_trf);
        datapath->selllu_trf(selllu_trf);
        datapath->selmdu1_trf(selmdu1_trf);
        datapath->selmdu2_trf(selmdu2_trf);
        datapath->selp1_pc(selp1_pc);
        datapath->selp1_pcp(selp1_pcp);
        datapath->selp2_asu(selp2_asu);
        datapath->selp2_shu(selp2_shu);
        datapath->selpc1_pc(selpc1_pc);
        datapath->selpc1_trf(selpc1_trf);
        datapath->selpc_mem(S14);
        datapath->selpcadd_pc(selpcadd_pc);
        datapath->selrd0_trf(selrd0_trf);
        datapath->selrd1_trf(selrd1_trf);
        datapath->selrd_1_trf(selrd_1_trf);
        datapath->selrd_2_trf(selrd_2_trf);
        datapath->selrs1_trf(selrs1_trf);
        datapath->selrs2_trf(selrs2_trf);
        datapath->selshim_shu(selshim_shu);
        datapath->selshu_trf(selshu_trf);
        datapath->setflags(setflags);
        datapath->startmdu(startmdu);
        datapath->twoscomp(twoscomp);
        datapath->use8bits(use8bits);


    SC_METHOD(sc_logic_signal_assignment);

    }

    void sc_logic_signal_assignment(void){ 
        sc_logic_1_signal.write(SC_LOGIC_1);
        sc_logic_0_signal.write(SC_LOGIC_0);
    }
};
#endif /* __LGC_H__ */

