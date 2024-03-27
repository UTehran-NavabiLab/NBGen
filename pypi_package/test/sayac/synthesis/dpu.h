#include <systemc.h>
#include "Complex_NAgate_45.h"

#include "asu.h"
#include "reg.h"
#include "cmp.h"
#include "flags.h"
#include "imm.h"
#include "reg.h"
#include "llu.h"
#include "mdu.h"
#include "mux2ofnbits_16.h"
#include "mux8of16bits.h"
#include "mux2ofnbits_16.h"
#include "mux3of16bits.h"
#include "mux2ofnbits_16.h"
#include "mux2ofnbits_4.h"
#include "mux2ofnbits_4.h"
#include "mux2ofnbits_4.h"
#include "mux2ofnbits_5.h"
#include "reg.h"
#include "inc_16.h"
#include "add_16.h"
#include "inc_4.h"
#include "shu.h"


#ifndef __DPU_H__
#define __DPU_H__
using namespace sc_core;

SC_MODULE( dpu ) {

    sc_in<sc_logic> clk;
    sc_in<sc_logic> rst;
    sc_in<sc_logic> seldatabus_trf;
    sc_in<sc_logic> selpc1_trf;
    sc_in<sc_logic> selllu_trf;
    sc_in<sc_logic> selshu_trf;
    sc_in<sc_logic> selasu_trf;
    sc_in<sc_logic> selmdu1_trf;
    sc_in<sc_logic> selmdu2_trf;
    sc_in<sc_logic> selimm_trf;
    sc_in<sc_logic> selrs1_trf;
    sc_in<sc_logic> selrd_1_trf;
    sc_in<sc_logic> selrs2_trf;
    sc_in<sc_logic> selrd_2_trf;
    sc_in<sc_logic> selrd0_trf;
    sc_in<sc_logic> selrd1_trf;
    sc_in<sc_logic> selp1_pcp;
    sc_in<sc_logic> selimm_pcp;
    sc_in<sc_logic> selp1_pc;
    sc_in<sc_logic> selpcadd_pc;
    sc_in<sc_logic> selpc1_pc;
    sc_in<sc_logic> selpc_mem;
    sc_in<sc_logic> seladr_mem;
    sc_in<sc_logic> drivedatabus;
    sc_in<sc_logic> se5bits;
    sc_in<sc_logic> se6bits;
    sc_in<sc_logic> use8bits;
    sc_in<sc_logic> se8bits;
    sc_in<sc_logic> p1lowbits;
    sc_in<sc_logic> selp2_asu;
    sc_in<sc_logic> selimm_asu;
    sc_in<sc_logic> arithadd;
    sc_in<sc_logic> arithsub;
    sc_in<sc_logic> logicand;
    sc_in<sc_logic> onescomp;
    sc_in<sc_logic> twoscomp;
    sc_in<sc_logic> selp2_shu;
    sc_in<sc_logic> selshim_shu;
    sc_in<sc_logic> logicsh;
    sc_in<sc_logic> arithsh;
    sc_in<sc_logic> ldmdu1;
    sc_in<sc_logic> ldmdu2;
    sc_in<sc_logic> arithmul;
    sc_in<sc_logic> arithdiv;
    sc_in<sc_logic> startmdu;
    sc_in<sc_logic> ldir;
    sc_in<sc_logic> ldadr;
    sc_in<sc_logic> ldpc;
    sc_in<sc_logic> setflags;
    sc_in<sc_logic> enflag;
    sc_in<sc_logic> selflag[8];
    sc_in<sc_logic> databusin[16];
    sc_in<sc_logic> p1trf[16];
    sc_in<sc_logic> p2trf[16];
    sc_out<sc_logic> readymdu;
    sc_out<sc_logic> opcode[8];
    sc_out<sc_logic> fib[5];
    sc_out<sc_logic> outflag[8];
    sc_out<sc_logic> addrbus[16];
    sc_out<sc_logic> databusout[16];
    sc_out<sc_logic> outmuxrs1[4];
    sc_out<sc_logic> outmuxrs2[4];
    sc_out<sc_logic> outmuxrd[4];
    sc_out<sc_logic> indatatrf[16];

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
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S23 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S23");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S24 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S24");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S25 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S25");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S26 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S26");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S27 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S27");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S28 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S28");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S29 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S29");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S30 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S30");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S31 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S31");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S32 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S32");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S33 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S33");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S34 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S34");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S35 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S35");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S36 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S36");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S37 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S37");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S38[16];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S39 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S39");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S40 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S40");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S41 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S41");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S42 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S42");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S43 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S43");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S44 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S44");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S45[16];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S46[16];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S47 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S47");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S48 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S48");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S49[5];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S50[16];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S51 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S51");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S52 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S52");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S53 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S53");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S54 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S54");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S55 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S55");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S56 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S56");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S57 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S57");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S58 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S58");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S59[8];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S60[8];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S61[4];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S62[4];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S63[4];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S64 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S64");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S65[16];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S66[16];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S67 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S67");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S68 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S68");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S69 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S69");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S70 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S70");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S71 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S71");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S72 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S72");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S73 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S73");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S74 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S74");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S75[8];
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S76 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S76");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S77 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S77");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S78 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S78");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S79 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S79");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S80 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S80");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S81 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S81");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S82 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S82");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S83 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S83");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S84 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S84");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S85 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S85");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S86 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S86");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S87 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S87");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S88 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S88");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S89 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S89");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S90 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S90");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S91 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S91");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S92 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S92");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S93 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S93");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S94 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S94");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S95 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S95");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S96 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S96");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S97 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S97");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S98 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S98");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S99 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S99");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S100 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S100");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S101 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S101");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> eq = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("eq");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> gt = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("gt");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> instruction_0_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("instruction_0_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> instruction_1_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("instruction_1_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> instruction_2_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("instruction_2_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> instruction_3_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("instruction_3_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outadr_0_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outadr_0_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outadr_10_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outadr_10_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outadr_11_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outadr_11_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outadr_12_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outadr_12_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outadr_13_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outadr_13_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outadr_14_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outadr_14_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outadr_15_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outadr_15_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outadr_1_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outadr_1_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outadr_2_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outadr_2_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outadr_3_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outadr_3_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outadr_4_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outadr_4_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outadr_5_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outadr_5_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outadr_6_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outadr_6_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outadr_7_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outadr_7_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outadr_8_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outadr_8_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outadr_9_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outadr_9_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outasu_0_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outasu_0_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outasu_10_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outasu_10_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outasu_11_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outasu_11_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outasu_12_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outasu_12_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outasu_13_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outasu_13_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outasu_14_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outasu_14_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outasu_15_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outasu_15_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outasu_1_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outasu_1_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outasu_2_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outasu_2_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outasu_3_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outasu_3_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outasu_4_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outasu_4_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outasu_5_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outasu_5_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outasu_6_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outasu_6_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outasu_7_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outasu_7_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outasu_8_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outasu_8_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outasu_9_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outasu_9_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outimm_0_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outimm_0_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outimm_10_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outimm_10_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outimm_11_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outimm_11_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outimm_12_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outimm_12_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outimm_13_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outimm_13_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outimm_14_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outimm_14_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outimm_15_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outimm_15_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outimm_1_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outimm_1_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outimm_2_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outimm_2_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outimm_3_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outimm_3_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outimm_4_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outimm_4_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outimm_5_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outimm_5_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outimm_6_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outimm_6_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outimm_7_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outimm_7_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outimm_8_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outimm_8_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outimm_9_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outimm_9_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outllu_0_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outllu_0_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outllu_10_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outllu_10_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outllu_11_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outllu_11_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outllu_12_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outllu_12_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outllu_13_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outllu_13_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outllu_14_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outllu_14_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outllu_15_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outllu_15_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outllu_1_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outllu_1_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outllu_2_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outllu_2_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outllu_3_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outllu_3_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outllu_4_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outllu_4_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outllu_5_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outllu_5_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outllu_6_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outllu_6_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outllu_7_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outllu_7_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outllu_8_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outllu_8_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outllu_9_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outllu_9_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmdu1_0_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmdu1_0_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmdu1_10_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmdu1_10_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmdu1_11_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmdu1_11_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmdu1_12_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmdu1_12_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmdu1_13_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmdu1_13_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmdu1_14_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmdu1_14_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmdu1_15_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmdu1_15_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmdu1_1_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmdu1_1_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmdu1_2_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmdu1_2_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmdu1_3_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmdu1_3_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmdu1_4_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmdu1_4_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmdu1_5_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmdu1_5_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmdu1_6_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmdu1_6_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmdu1_7_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmdu1_7_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmdu1_8_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmdu1_8_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmdu1_9_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmdu1_9_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmdu2_0_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmdu2_0_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmdu2_10_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmdu2_10_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmdu2_11_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmdu2_11_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmdu2_12_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmdu2_12_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmdu2_13_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmdu2_13_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmdu2_14_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmdu2_14_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmdu2_15_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmdu2_15_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmdu2_1_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmdu2_1_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmdu2_2_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmdu2_2_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmdu2_3_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmdu2_3_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmdu2_4_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmdu2_4_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmdu2_5_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmdu2_5_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmdu2_6_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmdu2_6_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmdu2_7_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmdu2_7_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmdu2_8_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmdu2_8_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmdu2_9_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmdu2_9_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxasu_0_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxasu_0_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxasu_10_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxasu_10_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxasu_11_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxasu_11_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxasu_12_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxasu_12_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxasu_13_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxasu_13_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxasu_14_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxasu_14_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxasu_15_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxasu_15_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxasu_1_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxasu_1_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxasu_2_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxasu_2_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxasu_3_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxasu_3_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxasu_4_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxasu_4_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxasu_5_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxasu_5_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxasu_6_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxasu_6_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxasu_7_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxasu_7_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxasu_8_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxasu_8_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxasu_9_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxasu_9_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxpc_0_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxpc_0_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxpc_10_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxpc_10_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxpc_11_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxpc_11_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxpc_12_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxpc_12_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxpc_13_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxpc_13_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxpc_14_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxpc_14_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxpc_15_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxpc_15_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxpc_1_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxpc_1_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxpc_2_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxpc_2_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxpc_3_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxpc_3_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxpc_4_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxpc_4_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxpc_5_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxpc_5_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxpc_6_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxpc_6_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxpc_7_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxpc_7_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxpc_8_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxpc_8_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxpc_9_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxpc_9_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxpcp_0_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxpcp_0_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxpcp_10_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxpcp_10_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxpcp_11_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxpcp_11_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxpcp_12_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxpcp_12_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxpcp_13_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxpcp_13_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxpcp_14_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxpcp_14_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxpcp_15_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxpcp_15_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxpcp_1_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxpcp_1_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxpcp_2_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxpcp_2_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxpcp_3_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxpcp_3_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxpcp_4_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxpcp_4_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxpcp_5_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxpcp_5_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxpcp_6_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxpcp_6_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxpcp_7_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxpcp_7_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxpcp_8_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxpcp_8_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxpcp_9_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxpcp_9_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxshu_0_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxshu_0_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxshu_1_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxshu_1_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxshu_2_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxshu_2_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxshu_3_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxshu_3_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outmuxshu_4_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outmuxshu_4_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outpc1_0_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outpc1_0_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outpc1_10_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outpc1_10_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outpc1_11_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outpc1_11_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outpc1_12_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outpc1_12_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outpc1_13_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outpc1_13_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outpc1_14_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outpc1_14_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outpc1_15_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outpc1_15_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outpc1_1_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outpc1_1_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outpc1_2_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outpc1_2_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outpc1_3_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outpc1_3_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outpc1_4_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outpc1_4_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outpc1_5_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outpc1_5_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outpc1_6_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outpc1_6_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outpc1_7_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outpc1_7_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outpc1_8_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outpc1_8_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outpc1_9_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outpc1_9_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outpc_0_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outpc_0_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outpc_10_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outpc_10_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outpc_11_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outpc_11_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outpc_12_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outpc_12_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outpc_13_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outpc_13_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outpc_14_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outpc_14_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outpc_15_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outpc_15_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outpc_1_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outpc_1_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outpc_2_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outpc_2_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outpc_3_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outpc_3_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outpc_4_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outpc_4_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outpc_5_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outpc_5_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outpc_6_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outpc_6_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outpc_7_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outpc_7_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outpc_8_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outpc_8_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outpc_9_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outpc_9_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outpcp_0_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outpcp_0_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outpcp_10_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outpcp_10_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outpcp_11_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outpcp_11_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outpcp_12_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outpcp_12_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outpcp_13_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outpcp_13_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outpcp_14_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outpcp_14_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outpcp_15_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outpcp_15_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outpcp_1_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outpcp_1_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outpcp_2_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outpcp_2_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outpcp_3_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outpcp_3_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outpcp_4_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outpcp_4_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outpcp_5_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outpcp_5_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outpcp_6_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outpcp_6_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outpcp_7_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outpcp_7_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outpcp_8_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outpcp_8_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outpcp_9_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outpcp_9_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outrd1_0_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outrd1_0_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outrd1_1_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outrd1_1_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outrd1_2_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outrd1_2_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outrd1_3_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outrd1_3_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outshu_0_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outshu_0_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outshu_10_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outshu_10_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outshu_11_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outshu_11_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outshu_12_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outshu_12_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outshu_13_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outshu_13_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outshu_14_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outshu_14_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outshu_15_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outshu_15_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outshu_1_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outshu_1_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outshu_2_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outshu_2_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outshu_3_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outshu_3_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outshu_4_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outshu_4_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outshu_5_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outshu_5_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outshu_6_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outshu_6_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outshu_7_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outshu_7_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outshu_8_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outshu_8_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> outshu_9_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("outshu_9_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> p1_0_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("p1_0_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> p1_1_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("p1_1_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> p1_2_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("p1_2_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> p1_3_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("p1_3_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> p1_4_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("p1_4_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> p1_5_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("p1_5_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> p1_6_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("p1_6_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> p1_7_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("p1_7_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> p2_0_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("p2_0_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> p2_1_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("p2_1_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> p2_2_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("p2_2_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> p2_3_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("p2_3_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> p2_4_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("p2_4_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> p2_5_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("p2_5_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> p2_6_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("p2_6_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> p2_7_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("p2_7_");

    NAND4_X1* NAND4_X1_1;
    NAND2_X1* NAND2_X1_1;
    AND2_X1* AND2_X1_1;
    AND2_X1* AND2_X1_2;
    NAND3_X1* NAND3_X1_1;
    NAND2_X1* NAND2_X1_2;
    NAND2_X1* NAND2_X1_3;
    NAND3_X1* NAND3_X1_2;
    NAND2_X1* NAND2_X1_4;
    NAND2_X1* NAND2_X1_5;
    NAND3_X1* NAND3_X1_3;
    NAND2_X1* NAND2_X1_6;
    NAND2_X1* NAND2_X1_7;
    NAND3_X1* NAND3_X1_4;
    NAND2_X1* NAND2_X1_8;
    NAND2_X1* NAND2_X1_9;
    NAND3_X1* NAND3_X1_5;
    NAND2_X1* NAND2_X1_10;
    NAND2_X1* NAND2_X1_11;
    NAND3_X1* NAND3_X1_6;
    NAND2_X1* NAND2_X1_12;
    NAND2_X1* NAND2_X1_13;
    NAND3_X1* NAND3_X1_7;
    NAND2_X1* NAND2_X1_14;
    NAND2_X1* NAND2_X1_15;
    NAND3_X1* NAND3_X1_8;
    NAND2_X1* NAND2_X1_16;
    NAND4_X1* NAND4_X1_2;
    NAND2_X1* NAND2_X1_17;
    AND2_X1* AND2_X1_3;
    AND2_X1* AND2_X1_4;
    NAND3_X1* NAND3_X1_9;
    NAND2_X1* NAND2_X1_18;
    NAND2_X1* NAND2_X1_19;
    NAND3_X1* NAND3_X1_10;
    NAND2_X1* NAND2_X1_20;
    NAND2_X1* NAND2_X1_21;
    NAND3_X1* NAND3_X1_11;
    NAND2_X1* NAND2_X1_22;
    NAND2_X1* NAND2_X1_23;
    NAND3_X1* NAND3_X1_12;
    NAND2_X1* NAND2_X1_24;
    NAND2_X1* NAND2_X1_25;
    NAND3_X1* NAND3_X1_13;
    NAND2_X1* NAND2_X1_26;
    NAND2_X1* NAND2_X1_27;
    NAND3_X1* NAND3_X1_14;
    NAND2_X1* NAND2_X1_28;
    NAND2_X1* NAND2_X1_29;
    NAND3_X1* NAND3_X1_15;
    NAND2_X1* NAND2_X1_30;
    NAND2_X1* NAND2_X1_31;
    NAND3_X1* NAND3_X1_16;
    NAND2_X1* NAND2_X1_32;
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
    asu* addsubunit;
    reg* adr;
    cmp* comparatorunit;
    flags* flags_dffs;
    imm* immediateunit;
    reg* ir;
    llu* logiclogicunit;
    mdu* multdivunit;
    mux2ofnbits_16* muxasu;
    mux8of16bits* muxindatatrf;
    mux2ofnbits_16* muxmem;
    mux3of16bits* muxpc;
    mux2ofnbits_16* muxpcp;
    mux2ofnbits_4* muxrd;
    mux2ofnbits_4* muxrs1;
    mux2ofnbits_4* muxrs2;
    mux2ofnbits_5* muxshu;
    reg* pc;
    inc_16* pc1;
    add_16* pcp;
    inc_4* rd1;
    shu* shiftunit;

SC_CTOR( dpu ) {
    NAND4_X1_1 = new NAND4_X1("NAND4_X1_1");
        NAND4_X1_1->A1(S62[3]);
        NAND4_X1_1->A2(S62[2]);
        NAND4_X1_1->A3(S62[1]);
        NAND4_X1_1->A4(S62[0]);
        NAND4_X1_1->ZN(S2);

    NAND2_X1_1 = new NAND2_X1("NAND2_X1_1");
        NAND2_X1_1->A1(S2);
        NAND2_X1_1->A2(S65[0]);
        NAND2_X1_1->ZN(S3);

    AND2_X1_1 = new AND2_X1("AND2_X1_1");
        AND2_X1_1->A1(S62[0]);
        AND2_X1_1->A2(S62[1]);
        AND2_X1_1->ZN(S4);

    AND2_X1_2 = new AND2_X1("AND2_X1_2");
        AND2_X1_2->A1(S62[2]);
        AND2_X1_2->A2(S62[3]);
        AND2_X1_2->ZN(S5);

    NAND3_X1_1 = new NAND3_X1("NAND3_X1_1");
        NAND3_X1_1->A1(S4);
        NAND3_X1_1->A2(S5);
        NAND3_X1_1->A3(S60[0]);
        NAND3_X1_1->ZN(S6);

    NAND2_X1_2 = new NAND2_X1("NAND2_X1_2");
        NAND2_X1_2->A1(S6);
        NAND2_X1_2->A2(S3);
        NAND2_X1_2->ZN(S46[0]);

    NAND2_X1_3 = new NAND2_X1("NAND2_X1_3");
        NAND2_X1_3->A1(S2);
        NAND2_X1_3->A2(S65[1]);
        NAND2_X1_3->ZN(S7);

    NAND3_X1_2 = new NAND3_X1("NAND3_X1_2");
        NAND3_X1_2->A1(S4);
        NAND3_X1_2->A2(S5);
        NAND3_X1_2->A3(S60[1]);
        NAND3_X1_2->ZN(S8);

    NAND2_X1_4 = new NAND2_X1("NAND2_X1_4");
        NAND2_X1_4->A1(S8);
        NAND2_X1_4->A2(S7);
        NAND2_X1_4->ZN(S46[1]);

    NAND2_X1_5 = new NAND2_X1("NAND2_X1_5");
        NAND2_X1_5->A1(S2);
        NAND2_X1_5->A2(S65[2]);
        NAND2_X1_5->ZN(S9);

    NAND3_X1_3 = new NAND3_X1("NAND3_X1_3");
        NAND3_X1_3->A1(S4);
        NAND3_X1_3->A2(S5);
        NAND3_X1_3->A3(S60[2]);
        NAND3_X1_3->ZN(S10);

    NAND2_X1_6 = new NAND2_X1("NAND2_X1_6");
        NAND2_X1_6->A1(S10);
        NAND2_X1_6->A2(S9);
        NAND2_X1_6->ZN(S46[2]);

    NAND2_X1_7 = new NAND2_X1("NAND2_X1_7");
        NAND2_X1_7->A1(S2);
        NAND2_X1_7->A2(S65[3]);
        NAND2_X1_7->ZN(S11);

    NAND3_X1_4 = new NAND3_X1("NAND3_X1_4");
        NAND3_X1_4->A1(S4);
        NAND3_X1_4->A2(S5);
        NAND3_X1_4->A3(S60[3]);
        NAND3_X1_4->ZN(S12);

    NAND2_X1_8 = new NAND2_X1("NAND2_X1_8");
        NAND2_X1_8->A1(S12);
        NAND2_X1_8->A2(S11);
        NAND2_X1_8->ZN(S46[3]);

    NAND2_X1_9 = new NAND2_X1("NAND2_X1_9");
        NAND2_X1_9->A1(S2);
        NAND2_X1_9->A2(S65[4]);
        NAND2_X1_9->ZN(S13);

    NAND3_X1_5 = new NAND3_X1("NAND3_X1_5");
        NAND3_X1_5->A1(S4);
        NAND3_X1_5->A2(S5);
        NAND3_X1_5->A3(S60[4]);
        NAND3_X1_5->ZN(S14);

    NAND2_X1_10 = new NAND2_X1("NAND2_X1_10");
        NAND2_X1_10->A1(S14);
        NAND2_X1_10->A2(S13);
        NAND2_X1_10->ZN(S46[4]);

    NAND2_X1_11 = new NAND2_X1("NAND2_X1_11");
        NAND2_X1_11->A1(S2);
        NAND2_X1_11->A2(S65[5]);
        NAND2_X1_11->ZN(S15);

    NAND3_X1_6 = new NAND3_X1("NAND3_X1_6");
        NAND3_X1_6->A1(S4);
        NAND3_X1_6->A2(S5);
        NAND3_X1_6->A3(S60[5]);
        NAND3_X1_6->ZN(S16);

    NAND2_X1_12 = new NAND2_X1("NAND2_X1_12");
        NAND2_X1_12->A1(S16);
        NAND2_X1_12->A2(S15);
        NAND2_X1_12->ZN(S46[5]);

    NAND2_X1_13 = new NAND2_X1("NAND2_X1_13");
        NAND2_X1_13->A1(S2);
        NAND2_X1_13->A2(S65[6]);
        NAND2_X1_13->ZN(S17);

    NAND3_X1_7 = new NAND3_X1("NAND3_X1_7");
        NAND3_X1_7->A1(S4);
        NAND3_X1_7->A2(S5);
        NAND3_X1_7->A3(S60[6]);
        NAND3_X1_7->ZN(S18);

    NAND2_X1_14 = new NAND2_X1("NAND2_X1_14");
        NAND2_X1_14->A1(S18);
        NAND2_X1_14->A2(S17);
        NAND2_X1_14->ZN(S46[6]);

    NAND2_X1_15 = new NAND2_X1("NAND2_X1_15");
        NAND2_X1_15->A1(S2);
        NAND2_X1_15->A2(S65[7]);
        NAND2_X1_15->ZN(S19);

    NAND3_X1_8 = new NAND3_X1("NAND3_X1_8");
        NAND3_X1_8->A1(S4);
        NAND3_X1_8->A2(S5);
        NAND3_X1_8->A3(S60[7]);
        NAND3_X1_8->ZN(S20);

    NAND2_X1_16 = new NAND2_X1("NAND2_X1_16");
        NAND2_X1_16->A1(S20);
        NAND2_X1_16->A2(S19);
        NAND2_X1_16->ZN(S46[7]);

    NAND4_X1_2 = new NAND4_X1("NAND4_X1_2");
        NAND4_X1_2->A1(S63[3]);
        NAND4_X1_2->A2(S63[2]);
        NAND4_X1_2->A3(S63[1]);
        NAND4_X1_2->A4(S63[0]);
        NAND4_X1_2->ZN(S21);

    NAND2_X1_17 = new NAND2_X1("NAND2_X1_17");
        NAND2_X1_17->A1(S21);
        NAND2_X1_17->A2(S66[0]);
        NAND2_X1_17->ZN(S22);

    AND2_X1_3 = new AND2_X1("AND2_X1_3");
        AND2_X1_3->A1(S63[0]);
        AND2_X1_3->A2(S63[1]);
        AND2_X1_3->ZN(S23);

    AND2_X1_4 = new AND2_X1("AND2_X1_4");
        AND2_X1_4->A1(S63[2]);
        AND2_X1_4->A2(S63[3]);
        AND2_X1_4->ZN(S24);

    NAND3_X1_9 = new NAND3_X1("NAND3_X1_9");
        NAND3_X1_9->A1(S23);
        NAND3_X1_9->A2(S24);
        NAND3_X1_9->A3(S60[0]);
        NAND3_X1_9->ZN(S25);

    NAND2_X1_18 = new NAND2_X1("NAND2_X1_18");
        NAND2_X1_18->A1(S25);
        NAND2_X1_18->A2(S22);
        NAND2_X1_18->ZN(p2_0_);

    NAND2_X1_19 = new NAND2_X1("NAND2_X1_19");
        NAND2_X1_19->A1(S21);
        NAND2_X1_19->A2(S66[1]);
        NAND2_X1_19->ZN(S26);

    NAND3_X1_10 = new NAND3_X1("NAND3_X1_10");
        NAND3_X1_10->A1(S23);
        NAND3_X1_10->A2(S24);
        NAND3_X1_10->A3(S60[1]);
        NAND3_X1_10->ZN(S27);

    NAND2_X1_20 = new NAND2_X1("NAND2_X1_20");
        NAND2_X1_20->A1(S27);
        NAND2_X1_20->A2(S26);
        NAND2_X1_20->ZN(p2_1_);

    NAND2_X1_21 = new NAND2_X1("NAND2_X1_21");
        NAND2_X1_21->A1(S21);
        NAND2_X1_21->A2(S66[2]);
        NAND2_X1_21->ZN(S28);

    NAND3_X1_11 = new NAND3_X1("NAND3_X1_11");
        NAND3_X1_11->A1(S23);
        NAND3_X1_11->A2(S24);
        NAND3_X1_11->A3(S60[2]);
        NAND3_X1_11->ZN(S29);

    NAND2_X1_22 = new NAND2_X1("NAND2_X1_22");
        NAND2_X1_22->A1(S29);
        NAND2_X1_22->A2(S28);
        NAND2_X1_22->ZN(p2_2_);

    NAND2_X1_23 = new NAND2_X1("NAND2_X1_23");
        NAND2_X1_23->A1(S21);
        NAND2_X1_23->A2(S66[3]);
        NAND2_X1_23->ZN(S30);

    NAND3_X1_12 = new NAND3_X1("NAND3_X1_12");
        NAND3_X1_12->A1(S23);
        NAND3_X1_12->A2(S24);
        NAND3_X1_12->A3(S60[3]);
        NAND3_X1_12->ZN(S31);

    NAND2_X1_24 = new NAND2_X1("NAND2_X1_24");
        NAND2_X1_24->A1(S31);
        NAND2_X1_24->A2(S30);
        NAND2_X1_24->ZN(p2_3_);

    NAND2_X1_25 = new NAND2_X1("NAND2_X1_25");
        NAND2_X1_25->A1(S21);
        NAND2_X1_25->A2(S66[4]);
        NAND2_X1_25->ZN(S32);

    NAND3_X1_13 = new NAND3_X1("NAND3_X1_13");
        NAND3_X1_13->A1(S23);
        NAND3_X1_13->A2(S24);
        NAND3_X1_13->A3(S60[4]);
        NAND3_X1_13->ZN(S33);

    NAND2_X1_26 = new NAND2_X1("NAND2_X1_26");
        NAND2_X1_26->A1(S33);
        NAND2_X1_26->A2(S32);
        NAND2_X1_26->ZN(p2_4_);

    NAND2_X1_27 = new NAND2_X1("NAND2_X1_27");
        NAND2_X1_27->A1(S21);
        NAND2_X1_27->A2(S66[5]);
        NAND2_X1_27->ZN(S34);

    NAND3_X1_14 = new NAND3_X1("NAND3_X1_14");
        NAND3_X1_14->A1(S23);
        NAND3_X1_14->A2(S24);
        NAND3_X1_14->A3(S60[5]);
        NAND3_X1_14->ZN(S35);

    NAND2_X1_28 = new NAND2_X1("NAND2_X1_28");
        NAND2_X1_28->A1(S35);
        NAND2_X1_28->A2(S34);
        NAND2_X1_28->ZN(p2_5_);

    NAND2_X1_29 = new NAND2_X1("NAND2_X1_29");
        NAND2_X1_29->A1(S21);
        NAND2_X1_29->A2(S66[6]);
        NAND2_X1_29->ZN(S36);

    NAND3_X1_15 = new NAND3_X1("NAND3_X1_15");
        NAND3_X1_15->A1(S23);
        NAND3_X1_15->A2(S24);
        NAND3_X1_15->A3(S60[6]);
        NAND3_X1_15->ZN(S37);

    NAND2_X1_30 = new NAND2_X1("NAND2_X1_30");
        NAND2_X1_30->A1(S37);
        NAND2_X1_30->A2(S36);
        NAND2_X1_30->ZN(p2_6_);

    NAND2_X1_31 = new NAND2_X1("NAND2_X1_31");
        NAND2_X1_31->A1(S21);
        NAND2_X1_31->A2(S66[7]);
        NAND2_X1_31->ZN(S0);

    NAND3_X1_16 = new NAND3_X1("NAND3_X1_16");
        NAND3_X1_16->A1(S23);
        NAND3_X1_16->A2(S24);
        NAND3_X1_16->A3(S60[7]);
        NAND3_X1_16->ZN(S1);

    NAND2_X1_32 = new NAND2_X1("NAND2_X1_32");
        NAND2_X1_32->A1(S1);
        NAND2_X1_32->A2(S0);
        NAND2_X1_32->ZN(p2_7_);

    BUF_X1_1 = new BUF_X1("BUF_X1_1");
        BUF_X1_1->A(S38[0]);
        BUF_X1_1->Z(addrbus[0]);

    BUF_X1_2 = new BUF_X1("BUF_X1_2");
        BUF_X1_2->A(S38[1]);
        BUF_X1_2->Z(addrbus[1]);

    BUF_X1_3 = new BUF_X1("BUF_X1_3");
        BUF_X1_3->A(S38[10]);
        BUF_X1_3->Z(addrbus[10]);

    BUF_X1_4 = new BUF_X1("BUF_X1_4");
        BUF_X1_4->A(S38[11]);
        BUF_X1_4->Z(addrbus[11]);

    BUF_X1_5 = new BUF_X1("BUF_X1_5");
        BUF_X1_5->A(S38[12]);
        BUF_X1_5->Z(addrbus[12]);

    BUF_X1_6 = new BUF_X1("BUF_X1_6");
        BUF_X1_6->A(S38[13]);
        BUF_X1_6->Z(addrbus[13]);

    BUF_X1_7 = new BUF_X1("BUF_X1_7");
        BUF_X1_7->A(S38[14]);
        BUF_X1_7->Z(addrbus[14]);

    BUF_X1_8 = new BUF_X1("BUF_X1_8");
        BUF_X1_8->A(S38[15]);
        BUF_X1_8->Z(addrbus[15]);

    BUF_X1_9 = new BUF_X1("BUF_X1_9");
        BUF_X1_9->A(S38[2]);
        BUF_X1_9->Z(addrbus[2]);

    BUF_X1_10 = new BUF_X1("BUF_X1_10");
        BUF_X1_10->A(S38[3]);
        BUF_X1_10->Z(addrbus[3]);

    BUF_X1_11 = new BUF_X1("BUF_X1_11");
        BUF_X1_11->A(S38[4]);
        BUF_X1_11->Z(addrbus[4]);

    BUF_X1_12 = new BUF_X1("BUF_X1_12");
        BUF_X1_12->A(S38[5]);
        BUF_X1_12->Z(addrbus[5]);

    BUF_X1_13 = new BUF_X1("BUF_X1_13");
        BUF_X1_13->A(S38[6]);
        BUF_X1_13->Z(addrbus[6]);

    BUF_X1_14 = new BUF_X1("BUF_X1_14");
        BUF_X1_14->A(S38[7]);
        BUF_X1_14->Z(addrbus[7]);

    BUF_X1_15 = new BUF_X1("BUF_X1_15");
        BUF_X1_15->A(S38[8]);
        BUF_X1_15->Z(addrbus[8]);

    BUF_X1_16 = new BUF_X1("BUF_X1_16");
        BUF_X1_16->A(S38[9]);
        BUF_X1_16->Z(addrbus[9]);

    BUF_X1_17 = new BUF_X1("BUF_X1_17");
        BUF_X1_17->A(arithadd);
        BUF_X1_17->Z(S39);

    BUF_X1_18 = new BUF_X1("BUF_X1_18");
        BUF_X1_18->A(arithdiv);
        BUF_X1_18->Z(S40);

    BUF_X1_19 = new BUF_X1("BUF_X1_19");
        BUF_X1_19->A(arithmul);
        BUF_X1_19->Z(S41);

    BUF_X1_20 = new BUF_X1("BUF_X1_20");
        BUF_X1_20->A(arithsh);
        BUF_X1_20->Z(S42);

    BUF_X1_21 = new BUF_X1("BUF_X1_21");
        BUF_X1_21->A(arithsub);
        BUF_X1_21->Z(S43);

    BUF_X1_22 = new BUF_X1("BUF_X1_22");
        BUF_X1_22->A(clk);
        BUF_X1_22->Z(S44);

    BUF_X1_23 = new BUF_X1("BUF_X1_23");
        BUF_X1_23->A(databusin[0]);
        BUF_X1_23->Z(S45[0]);

    BUF_X1_24 = new BUF_X1("BUF_X1_24");
        BUF_X1_24->A(databusin[1]);
        BUF_X1_24->Z(S45[1]);

    BUF_X1_25 = new BUF_X1("BUF_X1_25");
        BUF_X1_25->A(databusin[10]);
        BUF_X1_25->Z(S45[10]);

    BUF_X1_26 = new BUF_X1("BUF_X1_26");
        BUF_X1_26->A(databusin[11]);
        BUF_X1_26->Z(S45[11]);

    BUF_X1_27 = new BUF_X1("BUF_X1_27");
        BUF_X1_27->A(databusin[12]);
        BUF_X1_27->Z(S45[12]);

    BUF_X1_28 = new BUF_X1("BUF_X1_28");
        BUF_X1_28->A(databusin[13]);
        BUF_X1_28->Z(S45[13]);

    BUF_X1_29 = new BUF_X1("BUF_X1_29");
        BUF_X1_29->A(databusin[14]);
        BUF_X1_29->Z(S45[14]);

    BUF_X1_30 = new BUF_X1("BUF_X1_30");
        BUF_X1_30->A(databusin[15]);
        BUF_X1_30->Z(S45[15]);

    BUF_X1_31 = new BUF_X1("BUF_X1_31");
        BUF_X1_31->A(databusin[2]);
        BUF_X1_31->Z(S45[2]);

    BUF_X1_32 = new BUF_X1("BUF_X1_32");
        BUF_X1_32->A(databusin[3]);
        BUF_X1_32->Z(S45[3]);

    BUF_X1_33 = new BUF_X1("BUF_X1_33");
        BUF_X1_33->A(databusin[4]);
        BUF_X1_33->Z(S45[4]);

    BUF_X1_34 = new BUF_X1("BUF_X1_34");
        BUF_X1_34->A(databusin[5]);
        BUF_X1_34->Z(S45[5]);

    BUF_X1_35 = new BUF_X1("BUF_X1_35");
        BUF_X1_35->A(databusin[6]);
        BUF_X1_35->Z(S45[6]);

    BUF_X1_36 = new BUF_X1("BUF_X1_36");
        BUF_X1_36->A(databusin[7]);
        BUF_X1_36->Z(S45[7]);

    BUF_X1_37 = new BUF_X1("BUF_X1_37");
        BUF_X1_37->A(databusin[8]);
        BUF_X1_37->Z(S45[8]);

    BUF_X1_38 = new BUF_X1("BUF_X1_38");
        BUF_X1_38->A(databusin[9]);
        BUF_X1_38->Z(S45[9]);

    BUF_X1_39 = new BUF_X1("BUF_X1_39");
        BUF_X1_39->A(S46[0]);
        BUF_X1_39->Z(databusout[0]);

    BUF_X1_40 = new BUF_X1("BUF_X1_40");
        BUF_X1_40->A(S46[1]);
        BUF_X1_40->Z(databusout[1]);

    BUF_X1_41 = new BUF_X1("BUF_X1_41");
        BUF_X1_41->A(S46[2]);
        BUF_X1_41->Z(databusout[2]);

    BUF_X1_42 = new BUF_X1("BUF_X1_42");
        BUF_X1_42->A(S46[3]);
        BUF_X1_42->Z(databusout[3]);

    BUF_X1_43 = new BUF_X1("BUF_X1_43");
        BUF_X1_43->A(S46[4]);
        BUF_X1_43->Z(databusout[4]);

    BUF_X1_44 = new BUF_X1("BUF_X1_44");
        BUF_X1_44->A(S46[5]);
        BUF_X1_44->Z(databusout[5]);

    BUF_X1_45 = new BUF_X1("BUF_X1_45");
        BUF_X1_45->A(S46[6]);
        BUF_X1_45->Z(databusout[6]);

    BUF_X1_46 = new BUF_X1("BUF_X1_46");
        BUF_X1_46->A(S46[7]);
        BUF_X1_46->Z(databusout[7]);

    BUF_X1_47 = new BUF_X1("BUF_X1_47");
        BUF_X1_47->A(drivedatabus);
        BUF_X1_47->Z(S47);

    BUF_X1_48 = new BUF_X1("BUF_X1_48");
        BUF_X1_48->A(enflag);
        BUF_X1_48->Z(S48);

    BUF_X1_49 = new BUF_X1("BUF_X1_49");
        BUF_X1_49->A(S49[0]);
        BUF_X1_49->Z(fib[0]);

    BUF_X1_50 = new BUF_X1("BUF_X1_50");
        BUF_X1_50->A(S49[1]);
        BUF_X1_50->Z(fib[1]);

    BUF_X1_51 = new BUF_X1("BUF_X1_51");
        BUF_X1_51->A(S49[2]);
        BUF_X1_51->Z(fib[2]);

    BUF_X1_52 = new BUF_X1("BUF_X1_52");
        BUF_X1_52->A(S49[3]);
        BUF_X1_52->Z(fib[3]);

    BUF_X1_53 = new BUF_X1("BUF_X1_53");
        BUF_X1_53->A(S49[4]);
        BUF_X1_53->Z(fib[4]);

    BUF_X1_54 = new BUF_X1("BUF_X1_54");
        BUF_X1_54->A(S50[0]);
        BUF_X1_54->Z(indatatrf[0]);

    BUF_X1_55 = new BUF_X1("BUF_X1_55");
        BUF_X1_55->A(S50[1]);
        BUF_X1_55->Z(indatatrf[1]);

    BUF_X1_56 = new BUF_X1("BUF_X1_56");
        BUF_X1_56->A(S50[10]);
        BUF_X1_56->Z(indatatrf[10]);

    BUF_X1_57 = new BUF_X1("BUF_X1_57");
        BUF_X1_57->A(S50[11]);
        BUF_X1_57->Z(indatatrf[11]);

    BUF_X1_58 = new BUF_X1("BUF_X1_58");
        BUF_X1_58->A(S50[12]);
        BUF_X1_58->Z(indatatrf[12]);

    BUF_X1_59 = new BUF_X1("BUF_X1_59");
        BUF_X1_59->A(S50[13]);
        BUF_X1_59->Z(indatatrf[13]);

    BUF_X1_60 = new BUF_X1("BUF_X1_60");
        BUF_X1_60->A(S50[14]);
        BUF_X1_60->Z(indatatrf[14]);

    BUF_X1_61 = new BUF_X1("BUF_X1_61");
        BUF_X1_61->A(S50[15]);
        BUF_X1_61->Z(indatatrf[15]);

    BUF_X1_62 = new BUF_X1("BUF_X1_62");
        BUF_X1_62->A(S50[2]);
        BUF_X1_62->Z(indatatrf[2]);

    BUF_X1_63 = new BUF_X1("BUF_X1_63");
        BUF_X1_63->A(S50[3]);
        BUF_X1_63->Z(indatatrf[3]);

    BUF_X1_64 = new BUF_X1("BUF_X1_64");
        BUF_X1_64->A(S50[4]);
        BUF_X1_64->Z(indatatrf[4]);

    BUF_X1_65 = new BUF_X1("BUF_X1_65");
        BUF_X1_65->A(S50[5]);
        BUF_X1_65->Z(indatatrf[5]);

    BUF_X1_66 = new BUF_X1("BUF_X1_66");
        BUF_X1_66->A(S50[6]);
        BUF_X1_66->Z(indatatrf[6]);

    BUF_X1_67 = new BUF_X1("BUF_X1_67");
        BUF_X1_67->A(S50[7]);
        BUF_X1_67->Z(indatatrf[7]);

    BUF_X1_68 = new BUF_X1("BUF_X1_68");
        BUF_X1_68->A(S50[8]);
        BUF_X1_68->Z(indatatrf[8]);

    BUF_X1_69 = new BUF_X1("BUF_X1_69");
        BUF_X1_69->A(S50[9]);
        BUF_X1_69->Z(indatatrf[9]);

    BUF_X1_70 = new BUF_X1("BUF_X1_70");
        BUF_X1_70->A(ldadr);
        BUF_X1_70->Z(S51);

    BUF_X1_71 = new BUF_X1("BUF_X1_71");
        BUF_X1_71->A(ldir);
        BUF_X1_71->Z(S52);

    BUF_X1_72 = new BUF_X1("BUF_X1_72");
        BUF_X1_72->A(ldmdu1);
        BUF_X1_72->Z(S53);

    BUF_X1_73 = new BUF_X1("BUF_X1_73");
        BUF_X1_73->A(ldmdu2);
        BUF_X1_73->Z(S54);

    BUF_X1_74 = new BUF_X1("BUF_X1_74");
        BUF_X1_74->A(ldpc);
        BUF_X1_74->Z(S55);

    BUF_X1_75 = new BUF_X1("BUF_X1_75");
        BUF_X1_75->A(logicand);
        BUF_X1_75->Z(S56);

    BUF_X1_76 = new BUF_X1("BUF_X1_76");
        BUF_X1_76->A(logicsh);
        BUF_X1_76->Z(S57);

    BUF_X1_77 = new BUF_X1("BUF_X1_77");
        BUF_X1_77->A(onescomp);
        BUF_X1_77->Z(S58);

    BUF_X1_78 = new BUF_X1("BUF_X1_78");
        BUF_X1_78->A(S49[4]);
        BUF_X1_78->Z(opcode[0]);

    BUF_X1_79 = new BUF_X1("BUF_X1_79");
        BUF_X1_79->A(S59[1]);
        BUF_X1_79->Z(opcode[1]);

    BUF_X1_80 = new BUF_X1("BUF_X1_80");
        BUF_X1_80->A(S59[2]);
        BUF_X1_80->Z(opcode[2]);

    BUF_X1_81 = new BUF_X1("BUF_X1_81");
        BUF_X1_81->A(S59[3]);
        BUF_X1_81->Z(opcode[3]);

    BUF_X1_82 = new BUF_X1("BUF_X1_82");
        BUF_X1_82->A(S59[4]);
        BUF_X1_82->Z(opcode[4]);

    BUF_X1_83 = new BUF_X1("BUF_X1_83");
        BUF_X1_83->A(S59[5]);
        BUF_X1_83->Z(opcode[5]);

    BUF_X1_84 = new BUF_X1("BUF_X1_84");
        BUF_X1_84->A(S59[6]);
        BUF_X1_84->Z(opcode[6]);

    BUF_X1_85 = new BUF_X1("BUF_X1_85");
        BUF_X1_85->A(S59[7]);
        BUF_X1_85->Z(opcode[7]);

    BUF_X1_86 = new BUF_X1("BUF_X1_86");
        BUF_X1_86->A(S60[0]);
        BUF_X1_86->Z(outflag[0]);

    BUF_X1_87 = new BUF_X1("BUF_X1_87");
        BUF_X1_87->A(S60[1]);
        BUF_X1_87->Z(outflag[1]);

    BUF_X1_88 = new BUF_X1("BUF_X1_88");
        BUF_X1_88->A(S60[2]);
        BUF_X1_88->Z(outflag[2]);

    BUF_X1_89 = new BUF_X1("BUF_X1_89");
        BUF_X1_89->A(S60[3]);
        BUF_X1_89->Z(outflag[3]);

    BUF_X1_90 = new BUF_X1("BUF_X1_90");
        BUF_X1_90->A(S60[4]);
        BUF_X1_90->Z(outflag[4]);

    BUF_X1_91 = new BUF_X1("BUF_X1_91");
        BUF_X1_91->A(S60[5]);
        BUF_X1_91->Z(outflag[5]);

    BUF_X1_92 = new BUF_X1("BUF_X1_92");
        BUF_X1_92->A(S60[6]);
        BUF_X1_92->Z(outflag[6]);

    BUF_X1_93 = new BUF_X1("BUF_X1_93");
        BUF_X1_93->A(S60[7]);
        BUF_X1_93->Z(outflag[7]);

    BUF_X1_94 = new BUF_X1("BUF_X1_94");
        BUF_X1_94->A(S61[0]);
        BUF_X1_94->Z(outmuxrd[0]);

    BUF_X1_95 = new BUF_X1("BUF_X1_95");
        BUF_X1_95->A(S61[1]);
        BUF_X1_95->Z(outmuxrd[1]);

    BUF_X1_96 = new BUF_X1("BUF_X1_96");
        BUF_X1_96->A(S61[2]);
        BUF_X1_96->Z(outmuxrd[2]);

    BUF_X1_97 = new BUF_X1("BUF_X1_97");
        BUF_X1_97->A(S61[3]);
        BUF_X1_97->Z(outmuxrd[3]);

    BUF_X1_98 = new BUF_X1("BUF_X1_98");
        BUF_X1_98->A(S62[0]);
        BUF_X1_98->Z(outmuxrs1[0]);

    BUF_X1_99 = new BUF_X1("BUF_X1_99");
        BUF_X1_99->A(S62[1]);
        BUF_X1_99->Z(outmuxrs1[1]);

    BUF_X1_100 = new BUF_X1("BUF_X1_100");
        BUF_X1_100->A(S62[2]);
        BUF_X1_100->Z(outmuxrs1[2]);

    BUF_X1_101 = new BUF_X1("BUF_X1_101");
        BUF_X1_101->A(S62[3]);
        BUF_X1_101->Z(outmuxrs1[3]);

    BUF_X1_102 = new BUF_X1("BUF_X1_102");
        BUF_X1_102->A(S63[0]);
        BUF_X1_102->Z(outmuxrs2[0]);

    BUF_X1_103 = new BUF_X1("BUF_X1_103");
        BUF_X1_103->A(S63[1]);
        BUF_X1_103->Z(outmuxrs2[1]);

    BUF_X1_104 = new BUF_X1("BUF_X1_104");
        BUF_X1_104->A(S63[2]);
        BUF_X1_104->Z(outmuxrs2[2]);

    BUF_X1_105 = new BUF_X1("BUF_X1_105");
        BUF_X1_105->A(S63[3]);
        BUF_X1_105->Z(outmuxrs2[3]);

    BUF_X1_106 = new BUF_X1("BUF_X1_106");
        BUF_X1_106->A(p1lowbits);
        BUF_X1_106->Z(S64);

    BUF_X1_107 = new BUF_X1("BUF_X1_107");
        BUF_X1_107->A(p1trf[0]);
        BUF_X1_107->Z(S65[0]);

    BUF_X1_108 = new BUF_X1("BUF_X1_108");
        BUF_X1_108->A(p1trf[1]);
        BUF_X1_108->Z(S65[1]);

    BUF_X1_109 = new BUF_X1("BUF_X1_109");
        BUF_X1_109->A(p1trf[10]);
        BUF_X1_109->Z(S46[10]);

    BUF_X1_110 = new BUF_X1("BUF_X1_110");
        BUF_X1_110->A(p1trf[11]);
        BUF_X1_110->Z(S46[11]);

    BUF_X1_111 = new BUF_X1("BUF_X1_111");
        BUF_X1_111->A(p1trf[12]);
        BUF_X1_111->Z(S46[12]);

    BUF_X1_112 = new BUF_X1("BUF_X1_112");
        BUF_X1_112->A(p1trf[13]);
        BUF_X1_112->Z(S46[13]);

    BUF_X1_113 = new BUF_X1("BUF_X1_113");
        BUF_X1_113->A(p1trf[14]);
        BUF_X1_113->Z(S46[14]);

    BUF_X1_114 = new BUF_X1("BUF_X1_114");
        BUF_X1_114->A(p1trf[15]);
        BUF_X1_114->Z(S46[15]);

    BUF_X1_115 = new BUF_X1("BUF_X1_115");
        BUF_X1_115->A(p1trf[2]);
        BUF_X1_115->Z(S65[2]);

    BUF_X1_116 = new BUF_X1("BUF_X1_116");
        BUF_X1_116->A(p1trf[3]);
        BUF_X1_116->Z(S65[3]);

    BUF_X1_117 = new BUF_X1("BUF_X1_117");
        BUF_X1_117->A(p1trf[4]);
        BUF_X1_117->Z(S65[4]);

    BUF_X1_118 = new BUF_X1("BUF_X1_118");
        BUF_X1_118->A(p1trf[5]);
        BUF_X1_118->Z(S65[5]);

    BUF_X1_119 = new BUF_X1("BUF_X1_119");
        BUF_X1_119->A(p1trf[6]);
        BUF_X1_119->Z(S65[6]);

    BUF_X1_120 = new BUF_X1("BUF_X1_120");
        BUF_X1_120->A(p1trf[7]);
        BUF_X1_120->Z(S65[7]);

    BUF_X1_121 = new BUF_X1("BUF_X1_121");
        BUF_X1_121->A(p1trf[8]);
        BUF_X1_121->Z(S46[8]);

    BUF_X1_122 = new BUF_X1("BUF_X1_122");
        BUF_X1_122->A(p1trf[9]);
        BUF_X1_122->Z(S46[9]);

    BUF_X1_123 = new BUF_X1("BUF_X1_123");
        BUF_X1_123->A(p2trf[0]);
        BUF_X1_123->Z(S66[0]);

    BUF_X1_124 = new BUF_X1("BUF_X1_124");
        BUF_X1_124->A(p2trf[1]);
        BUF_X1_124->Z(S66[1]);

    BUF_X1_125 = new BUF_X1("BUF_X1_125");
        BUF_X1_125->A(p2trf[10]);
        BUF_X1_125->Z(S66[10]);

    BUF_X1_126 = new BUF_X1("BUF_X1_126");
        BUF_X1_126->A(p2trf[11]);
        BUF_X1_126->Z(S66[11]);

    BUF_X1_127 = new BUF_X1("BUF_X1_127");
        BUF_X1_127->A(p2trf[12]);
        BUF_X1_127->Z(S66[12]);

    BUF_X1_128 = new BUF_X1("BUF_X1_128");
        BUF_X1_128->A(p2trf[13]);
        BUF_X1_128->Z(S66[13]);

    BUF_X1_129 = new BUF_X1("BUF_X1_129");
        BUF_X1_129->A(p2trf[14]);
        BUF_X1_129->Z(S66[14]);

    BUF_X1_130 = new BUF_X1("BUF_X1_130");
        BUF_X1_130->A(p2trf[15]);
        BUF_X1_130->Z(S66[15]);

    BUF_X1_131 = new BUF_X1("BUF_X1_131");
        BUF_X1_131->A(p2trf[2]);
        BUF_X1_131->Z(S66[2]);

    BUF_X1_132 = new BUF_X1("BUF_X1_132");
        BUF_X1_132->A(p2trf[3]);
        BUF_X1_132->Z(S66[3]);

    BUF_X1_133 = new BUF_X1("BUF_X1_133");
        BUF_X1_133->A(p2trf[4]);
        BUF_X1_133->Z(S66[4]);

    BUF_X1_134 = new BUF_X1("BUF_X1_134");
        BUF_X1_134->A(p2trf[5]);
        BUF_X1_134->Z(S66[5]);

    BUF_X1_135 = new BUF_X1("BUF_X1_135");
        BUF_X1_135->A(p2trf[6]);
        BUF_X1_135->Z(S66[6]);

    BUF_X1_136 = new BUF_X1("BUF_X1_136");
        BUF_X1_136->A(p2trf[7]);
        BUF_X1_136->Z(S66[7]);

    BUF_X1_137 = new BUF_X1("BUF_X1_137");
        BUF_X1_137->A(p2trf[8]);
        BUF_X1_137->Z(S66[8]);

    BUF_X1_138 = new BUF_X1("BUF_X1_138");
        BUF_X1_138->A(p2trf[9]);
        BUF_X1_138->Z(S66[9]);

    BUF_X1_139 = new BUF_X1("BUF_X1_139");
        BUF_X1_139->A(S67);
        BUF_X1_139->Z(readymdu);

    BUF_X1_140 = new BUF_X1("BUF_X1_140");
        BUF_X1_140->A(rst);
        BUF_X1_140->Z(S68);

    BUF_X1_141 = new BUF_X1("BUF_X1_141");
        BUF_X1_141->A(se5bits);
        BUF_X1_141->Z(S69);

    BUF_X1_142 = new BUF_X1("BUF_X1_142");
        BUF_X1_142->A(se6bits);
        BUF_X1_142->Z(S70);

    BUF_X1_143 = new BUF_X1("BUF_X1_143");
        BUF_X1_143->A(se8bits);
        BUF_X1_143->Z(S71);

    BUF_X1_144 = new BUF_X1("BUF_X1_144");
        BUF_X1_144->A(seladr_mem);
        BUF_X1_144->Z(S72);

    BUF_X1_145 = new BUF_X1("BUF_X1_145");
        BUF_X1_145->A(selasu_trf);
        BUF_X1_145->Z(S73);

    BUF_X1_146 = new BUF_X1("BUF_X1_146");
        BUF_X1_146->A(seldatabus_trf);
        BUF_X1_146->Z(S74);

    BUF_X1_147 = new BUF_X1("BUF_X1_147");
        BUF_X1_147->A(selflag[0]);
        BUF_X1_147->Z(S75[0]);

    BUF_X1_148 = new BUF_X1("BUF_X1_148");
        BUF_X1_148->A(selflag[1]);
        BUF_X1_148->Z(S75[1]);

    BUF_X1_149 = new BUF_X1("BUF_X1_149");
        BUF_X1_149->A(selflag[2]);
        BUF_X1_149->Z(S75[2]);

    BUF_X1_150 = new BUF_X1("BUF_X1_150");
        BUF_X1_150->A(selflag[3]);
        BUF_X1_150->Z(S75[3]);

    BUF_X1_151 = new BUF_X1("BUF_X1_151");
        BUF_X1_151->A(selflag[4]);
        BUF_X1_151->Z(S75[4]);

    BUF_X1_152 = new BUF_X1("BUF_X1_152");
        BUF_X1_152->A(selflag[5]);
        BUF_X1_152->Z(S75[5]);

    BUF_X1_153 = new BUF_X1("BUF_X1_153");
        BUF_X1_153->A(selflag[6]);
        BUF_X1_153->Z(S75[6]);

    BUF_X1_154 = new BUF_X1("BUF_X1_154");
        BUF_X1_154->A(selflag[7]);
        BUF_X1_154->Z(S75[7]);

    BUF_X1_155 = new BUF_X1("BUF_X1_155");
        BUF_X1_155->A(selimm_asu);
        BUF_X1_155->Z(S76);

    BUF_X1_156 = new BUF_X1("BUF_X1_156");
        BUF_X1_156->A(selimm_pcp);
        BUF_X1_156->Z(S77);

    BUF_X1_157 = new BUF_X1("BUF_X1_157");
        BUF_X1_157->A(selimm_trf);
        BUF_X1_157->Z(S78);

    BUF_X1_158 = new BUF_X1("BUF_X1_158");
        BUF_X1_158->A(selllu_trf);
        BUF_X1_158->Z(S79);

    BUF_X1_159 = new BUF_X1("BUF_X1_159");
        BUF_X1_159->A(selmdu1_trf);
        BUF_X1_159->Z(S80);

    BUF_X1_160 = new BUF_X1("BUF_X1_160");
        BUF_X1_160->A(selmdu2_trf);
        BUF_X1_160->Z(S81);

    BUF_X1_161 = new BUF_X1("BUF_X1_161");
        BUF_X1_161->A(selp1_pc);
        BUF_X1_161->Z(S82);

    BUF_X1_162 = new BUF_X1("BUF_X1_162");
        BUF_X1_162->A(selp1_pcp);
        BUF_X1_162->Z(S83);

    BUF_X1_163 = new BUF_X1("BUF_X1_163");
        BUF_X1_163->A(selp2_asu);
        BUF_X1_163->Z(S84);

    BUF_X1_164 = new BUF_X1("BUF_X1_164");
        BUF_X1_164->A(selp2_shu);
        BUF_X1_164->Z(S85);

    BUF_X1_165 = new BUF_X1("BUF_X1_165");
        BUF_X1_165->A(selpc1_pc);
        BUF_X1_165->Z(S86);

    BUF_X1_166 = new BUF_X1("BUF_X1_166");
        BUF_X1_166->A(selpc1_trf);
        BUF_X1_166->Z(S87);

    BUF_X1_167 = new BUF_X1("BUF_X1_167");
        BUF_X1_167->A(selpc_mem);
        BUF_X1_167->Z(S88);

    BUF_X1_168 = new BUF_X1("BUF_X1_168");
        BUF_X1_168->A(selpcadd_pc);
        BUF_X1_168->Z(S89);

    BUF_X1_169 = new BUF_X1("BUF_X1_169");
        BUF_X1_169->A(selrd0_trf);
        BUF_X1_169->Z(S90);

    BUF_X1_170 = new BUF_X1("BUF_X1_170");
        BUF_X1_170->A(selrd1_trf);
        BUF_X1_170->Z(S91);

    BUF_X1_171 = new BUF_X1("BUF_X1_171");
        BUF_X1_171->A(selrd_1_trf);
        BUF_X1_171->Z(S92);

    BUF_X1_172 = new BUF_X1("BUF_X1_172");
        BUF_X1_172->A(selrd_2_trf);
        BUF_X1_172->Z(S93);

    BUF_X1_173 = new BUF_X1("BUF_X1_173");
        BUF_X1_173->A(selrs1_trf);
        BUF_X1_173->Z(S94);

    BUF_X1_174 = new BUF_X1("BUF_X1_174");
        BUF_X1_174->A(selrs2_trf);
        BUF_X1_174->Z(S95);

    BUF_X1_175 = new BUF_X1("BUF_X1_175");
        BUF_X1_175->A(selshim_shu);
        BUF_X1_175->Z(S96);

    BUF_X1_176 = new BUF_X1("BUF_X1_176");
        BUF_X1_176->A(selshu_trf);
        BUF_X1_176->Z(S97);

    BUF_X1_177 = new BUF_X1("BUF_X1_177");
        BUF_X1_177->A(setflags);
        BUF_X1_177->Z(S98);

    BUF_X1_178 = new BUF_X1("BUF_X1_178");
        BUF_X1_178->A(startmdu);
        BUF_X1_178->Z(S99);

    BUF_X1_179 = new BUF_X1("BUF_X1_179");
        BUF_X1_179->A(twoscomp);
        BUF_X1_179->Z(S100);

    BUF_X1_180 = new BUF_X1("BUF_X1_180");
        BUF_X1_180->A(use8bits);
        BUF_X1_180->Z(S101);

    addsubunit = new asu("addsubunit");
        addsubunit->arithadd(S39);
        addsubunit->arithsub(S43);
        addsubunit->in1[0](S46[0]);
        addsubunit->in1[1](S46[1]);
        addsubunit->in1[2](S46[2]);
        addsubunit->in1[3](S46[3]);
        addsubunit->in1[4](S46[4]);
        addsubunit->in1[5](S46[5]);
        addsubunit->in1[6](S46[6]);
        addsubunit->in1[7](S46[7]);
        addsubunit->in1[8](S46[8]);
        addsubunit->in1[9](S46[9]);
        addsubunit->in1[10](S46[10]);
        addsubunit->in1[11](S46[11]);
        addsubunit->in1[12](S46[12]);
        addsubunit->in1[13](S46[13]);
        addsubunit->in1[14](S46[14]);
        addsubunit->in1[15](S46[15]);
        addsubunit->in2[0](outmuxasu_0_);
        addsubunit->in2[1](outmuxasu_1_);
        addsubunit->in2[2](outmuxasu_2_);
        addsubunit->in2[3](outmuxasu_3_);
        addsubunit->in2[4](outmuxasu_4_);
        addsubunit->in2[5](outmuxasu_5_);
        addsubunit->in2[6](outmuxasu_6_);
        addsubunit->in2[7](outmuxasu_7_);
        addsubunit->in2[8](outmuxasu_8_);
        addsubunit->in2[9](outmuxasu_9_);
        addsubunit->in2[10](outmuxasu_10_);
        addsubunit->in2[11](outmuxasu_11_);
        addsubunit->in2[12](outmuxasu_12_);
        addsubunit->in2[13](outmuxasu_13_);
        addsubunit->in2[14](outmuxasu_14_);
        addsubunit->in2[15](outmuxasu_15_);
        addsubunit->outasu[0](outasu_0_);
        addsubunit->outasu[1](outasu_1_);
        addsubunit->outasu[2](outasu_2_);
        addsubunit->outasu[3](outasu_3_);
        addsubunit->outasu[4](outasu_4_);
        addsubunit->outasu[5](outasu_5_);
        addsubunit->outasu[6](outasu_6_);
        addsubunit->outasu[7](outasu_7_);
        addsubunit->outasu[8](outasu_8_);
        addsubunit->outasu[9](outasu_9_);
        addsubunit->outasu[10](outasu_10_);
        addsubunit->outasu[11](outasu_11_);
        addsubunit->outasu[12](outasu_12_);
        addsubunit->outasu[13](outasu_13_);
        addsubunit->outasu[14](outasu_14_);
        addsubunit->outasu[15](outasu_15_);

    adr = new reg("adr");
        adr->clk(S44);
        adr->inreg[0](outmuxpcp_0_);
        adr->inreg[1](outmuxpcp_1_);
        adr->inreg[2](outmuxpcp_2_);
        adr->inreg[3](outmuxpcp_3_);
        adr->inreg[4](outmuxpcp_4_);
        adr->inreg[5](outmuxpcp_5_);
        adr->inreg[6](outmuxpcp_6_);
        adr->inreg[7](outmuxpcp_7_);
        adr->inreg[8](outmuxpcp_8_);
        adr->inreg[9](outmuxpcp_9_);
        adr->inreg[10](outmuxpcp_10_);
        adr->inreg[11](outmuxpcp_11_);
        adr->inreg[12](outmuxpcp_12_);
        adr->inreg[13](outmuxpcp_13_);
        adr->inreg[14](outmuxpcp_14_);
        adr->inreg[15](outmuxpcp_15_);
        adr->ld(S51);
        adr->outreg[0](outadr_0_);
        adr->outreg[1](outadr_1_);
        adr->outreg[2](outadr_2_);
        adr->outreg[3](outadr_3_);
        adr->outreg[4](outadr_4_);
        adr->outreg[5](outadr_5_);
        adr->outreg[6](outadr_6_);
        adr->outreg[7](outadr_7_);
        adr->outreg[8](outadr_8_);
        adr->outreg[9](outadr_9_);
        adr->outreg[10](outadr_10_);
        adr->outreg[11](outadr_11_);
        adr->outreg[12](outadr_12_);
        adr->outreg[13](outadr_13_);
        adr->outreg[14](outadr_14_);
        adr->outreg[15](outadr_15_);
        adr->rst(S68);

    comparatorunit = new cmp("comparatorunit");
        comparatorunit->eq(eq);
        comparatorunit->gt(gt);
        comparatorunit->in1[0](S46[0]);
        comparatorunit->in1[1](S46[1]);
        comparatorunit->in1[2](S46[2]);
        comparatorunit->in1[3](S46[3]);
        comparatorunit->in1[4](S46[4]);
        comparatorunit->in1[5](S46[5]);
        comparatorunit->in1[6](S46[6]);
        comparatorunit->in1[7](S46[7]);
        comparatorunit->in1[8](S46[8]);
        comparatorunit->in1[9](S46[9]);
        comparatorunit->in1[10](S46[10]);
        comparatorunit->in1[11](S46[11]);
        comparatorunit->in1[12](S46[12]);
        comparatorunit->in1[13](S46[13]);
        comparatorunit->in1[14](S46[14]);
        comparatorunit->in1[15](S46[15]);
        comparatorunit->in2[0](outmuxasu_0_);
        comparatorunit->in2[1](outmuxasu_1_);
        comparatorunit->in2[2](outmuxasu_2_);
        comparatorunit->in2[3](outmuxasu_3_);
        comparatorunit->in2[4](outmuxasu_4_);
        comparatorunit->in2[5](outmuxasu_5_);
        comparatorunit->in2[6](outmuxasu_6_);
        comparatorunit->in2[7](outmuxasu_7_);
        comparatorunit->in2[8](outmuxasu_8_);
        comparatorunit->in2[9](outmuxasu_9_);
        comparatorunit->in2[10](outmuxasu_10_);
        comparatorunit->in2[11](outmuxasu_11_);
        comparatorunit->in2[12](outmuxasu_12_);
        comparatorunit->in2[13](outmuxasu_13_);
        comparatorunit->in2[14](outmuxasu_14_);
        comparatorunit->in2[15](outmuxasu_15_);

    flags_dffs = new flags("flags_dffs");
        flags_dffs->clk(S44);
        flags_dffs->enflag(S48);
        flags_dffs->inflag[0](sc_logic_0_signal);
        flags_dffs->inflag[1](sc_logic_0_signal);
        flags_dffs->inflag[2](sc_logic_0_signal);
        flags_dffs->inflag[3](sc_logic_0_signal);
        flags_dffs->inflag[4](eq);
        flags_dffs->inflag[5](gt);
        flags_dffs->inflag[6](sc_logic_0_signal);
        flags_dffs->inflag[7](sc_logic_0_signal);
        flags_dffs->outflag[0](S60[0]);
        flags_dffs->outflag[1](S60[1]);
        flags_dffs->outflag[2](S60[2]);
        flags_dffs->outflag[3](S60[3]);
        flags_dffs->outflag[4](S60[4]);
        flags_dffs->outflag[5](S60[5]);
        flags_dffs->outflag[6](S60[6]);
        flags_dffs->outflag[7](S60[7]);
        flags_dffs->rst(S68);
        flags_dffs->selflag[0](S75[0]);
        flags_dffs->selflag[1](S75[1]);
        flags_dffs->selflag[2](S75[2]);
        flags_dffs->selflag[3](S75[3]);
        flags_dffs->selflag[4](S75[4]);
        flags_dffs->selflag[5](S75[5]);
        flags_dffs->selflag[6](S75[6]);
        flags_dffs->selflag[7](S75[7]);
        flags_dffs->setflags(S98);

    immediateunit = new imm("immediateunit");
        immediateunit->in1[0](S49[0]);
        immediateunit->in1[1](S49[1]);
        immediateunit->in1[2](S49[2]);
        immediateunit->in1[3](S49[3]);
        immediateunit->in1[4](S49[4]);
        immediateunit->in1[5](S59[1]);
        immediateunit->in1[6](S59[2]);
        immediateunit->in1[7](S59[3]);
        immediateunit->in2[0](S46[0]);
        immediateunit->in2[1](S46[1]);
        immediateunit->in2[2](S46[2]);
        immediateunit->in2[3](S46[3]);
        immediateunit->in2[4](S46[4]);
        immediateunit->in2[5](S46[5]);
        immediateunit->in2[6](S46[6]);
        immediateunit->in2[7](S46[7]);
        immediateunit->outimm[0](outimm_0_);
        immediateunit->outimm[1](outimm_1_);
        immediateunit->outimm[2](outimm_2_);
        immediateunit->outimm[3](outimm_3_);
        immediateunit->outimm[4](outimm_4_);
        immediateunit->outimm[5](outimm_5_);
        immediateunit->outimm[6](outimm_6_);
        immediateunit->outimm[7](outimm_7_);
        immediateunit->outimm[8](outimm_8_);
        immediateunit->outimm[9](outimm_9_);
        immediateunit->outimm[10](outimm_10_);
        immediateunit->outimm[11](outimm_11_);
        immediateunit->outimm[12](outimm_12_);
        immediateunit->outimm[13](outimm_13_);
        immediateunit->outimm[14](outimm_14_);
        immediateunit->outimm[15](outimm_15_);
        immediateunit->p1lowbits(S64);
        immediateunit->se5bits(S69);
        immediateunit->se6bits(S70);
        immediateunit->se8bits(S71);
        immediateunit->use8bits(S101);

    ir = new reg("ir");
        ir->clk(S44);
        ir->inreg[0](S45[0]);
        ir->inreg[1](S45[1]);
        ir->inreg[2](S45[2]);
        ir->inreg[3](S45[3]);
        ir->inreg[4](S45[4]);
        ir->inreg[5](S45[5]);
        ir->inreg[6](S45[6]);
        ir->inreg[7](S45[7]);
        ir->inreg[8](S45[8]);
        ir->inreg[9](S45[9]);
        ir->inreg[10](S45[10]);
        ir->inreg[11](S45[11]);
        ir->inreg[12](S45[12]);
        ir->inreg[13](S45[13]);
        ir->inreg[14](S45[14]);
        ir->inreg[15](S45[15]);
        ir->ld(S52);
        ir->outreg[0](instruction_0_);
        ir->outreg[1](instruction_1_);
        ir->outreg[2](instruction_2_);
        ir->outreg[3](instruction_3_);
        ir->outreg[4](S49[0]);
        ir->outreg[5](S49[1]);
        ir->outreg[6](S49[2]);
        ir->outreg[7](S49[3]);
        ir->outreg[8](S49[4]);
        ir->outreg[9](S59[1]);
        ir->outreg[10](S59[2]);
        ir->outreg[11](S59[3]);
        ir->outreg[12](S59[4]);
        ir->outreg[13](S59[5]);
        ir->outreg[14](S59[6]);
        ir->outreg[15](S59[7]);
        ir->rst(S68);

    logiclogicunit = new llu("logiclogicunit");
        logiclogicunit->in1[0](S46[0]);
        logiclogicunit->in1[1](S46[1]);
        logiclogicunit->in1[2](S46[2]);
        logiclogicunit->in1[3](S46[3]);
        logiclogicunit->in1[4](S46[4]);
        logiclogicunit->in1[5](S46[5]);
        logiclogicunit->in1[6](S46[6]);
        logiclogicunit->in1[7](S46[7]);
        logiclogicunit->in1[8](S46[8]);
        logiclogicunit->in1[9](S46[9]);
        logiclogicunit->in1[10](S46[10]);
        logiclogicunit->in1[11](S46[11]);
        logiclogicunit->in1[12](S46[12]);
        logiclogicunit->in1[13](S46[13]);
        logiclogicunit->in1[14](S46[14]);
        logiclogicunit->in1[15](S46[15]);
        logiclogicunit->in2[0](outmuxasu_0_);
        logiclogicunit->in2[1](outmuxasu_1_);
        logiclogicunit->in2[2](outmuxasu_2_);
        logiclogicunit->in2[3](outmuxasu_3_);
        logiclogicunit->in2[4](outmuxasu_4_);
        logiclogicunit->in2[5](outmuxasu_5_);
        logiclogicunit->in2[6](outmuxasu_6_);
        logiclogicunit->in2[7](outmuxasu_7_);
        logiclogicunit->in2[8](outmuxasu_8_);
        logiclogicunit->in2[9](outmuxasu_9_);
        logiclogicunit->in2[10](outmuxasu_10_);
        logiclogicunit->in2[11](outmuxasu_11_);
        logiclogicunit->in2[12](outmuxasu_12_);
        logiclogicunit->in2[13](outmuxasu_13_);
        logiclogicunit->in2[14](outmuxasu_14_);
        logiclogicunit->in2[15](outmuxasu_15_);
        logiclogicunit->logicand(S56);
        logiclogicunit->onescomp(S58);
        logiclogicunit->outllu[0](outllu_0_);
        logiclogicunit->outllu[1](outllu_1_);
        logiclogicunit->outllu[2](outllu_2_);
        logiclogicunit->outllu[3](outllu_3_);
        logiclogicunit->outllu[4](outllu_4_);
        logiclogicunit->outllu[5](outllu_5_);
        logiclogicunit->outllu[6](outllu_6_);
        logiclogicunit->outllu[7](outllu_7_);
        logiclogicunit->outllu[8](outllu_8_);
        logiclogicunit->outllu[9](outllu_9_);
        logiclogicunit->outllu[10](outllu_10_);
        logiclogicunit->outllu[11](outllu_11_);
        logiclogicunit->outllu[12](outllu_12_);
        logiclogicunit->outllu[13](outllu_13_);
        logiclogicunit->outllu[14](outllu_14_);
        logiclogicunit->outllu[15](outllu_15_);
        logiclogicunit->twoscomp(S100);

    multdivunit = new mdu("multdivunit");
        multdivunit->arithdiv(S40);
        multdivunit->arithmul(S41);
        multdivunit->clk(S44);
        multdivunit->in1[0](S46[0]);
        multdivunit->in1[1](S46[1]);
        multdivunit->in1[2](S46[2]);
        multdivunit->in1[3](S46[3]);
        multdivunit->in1[4](S46[4]);
        multdivunit->in1[5](S46[5]);
        multdivunit->in1[6](S46[6]);
        multdivunit->in1[7](S46[7]);
        multdivunit->in1[8](S46[8]);
        multdivunit->in1[9](S46[9]);
        multdivunit->in1[10](S46[10]);
        multdivunit->in1[11](S46[11]);
        multdivunit->in1[12](S46[12]);
        multdivunit->in1[13](S46[13]);
        multdivunit->in1[14](S46[14]);
        multdivunit->in1[15](S46[15]);
        multdivunit->in2[0](p2_0_);
        multdivunit->in2[1](p2_1_);
        multdivunit->in2[2](p2_2_);
        multdivunit->in2[3](p2_3_);
        multdivunit->in2[4](p2_4_);
        multdivunit->in2[5](p2_5_);
        multdivunit->in2[6](p2_6_);
        multdivunit->in2[7](p2_7_);
        multdivunit->in2[8](S66[8]);
        multdivunit->in2[9](S66[9]);
        multdivunit->in2[10](S66[10]);
        multdivunit->in2[11](S66[11]);
        multdivunit->in2[12](S66[12]);
        multdivunit->in2[13](S66[13]);
        multdivunit->in2[14](S66[14]);
        multdivunit->in2[15](S66[15]);
        multdivunit->ldmdu1(S53);
        multdivunit->ldmdu2(S54);
        multdivunit->outmdu1[0](outmdu1_0_);
        multdivunit->outmdu1[1](outmdu1_1_);
        multdivunit->outmdu1[2](outmdu1_2_);
        multdivunit->outmdu1[3](outmdu1_3_);
        multdivunit->outmdu1[4](outmdu1_4_);
        multdivunit->outmdu1[5](outmdu1_5_);
        multdivunit->outmdu1[6](outmdu1_6_);
        multdivunit->outmdu1[7](outmdu1_7_);
        multdivunit->outmdu1[8](outmdu1_8_);
        multdivunit->outmdu1[9](outmdu1_9_);
        multdivunit->outmdu1[10](outmdu1_10_);
        multdivunit->outmdu1[11](outmdu1_11_);
        multdivunit->outmdu1[12](outmdu1_12_);
        multdivunit->outmdu1[13](outmdu1_13_);
        multdivunit->outmdu1[14](outmdu1_14_);
        multdivunit->outmdu1[15](outmdu1_15_);
        multdivunit->outmdu2[0](outmdu2_0_);
        multdivunit->outmdu2[1](outmdu2_1_);
        multdivunit->outmdu2[2](outmdu2_2_);
        multdivunit->outmdu2[3](outmdu2_3_);
        multdivunit->outmdu2[4](outmdu2_4_);
        multdivunit->outmdu2[5](outmdu2_5_);
        multdivunit->outmdu2[6](outmdu2_6_);
        multdivunit->outmdu2[7](outmdu2_7_);
        multdivunit->outmdu2[8](outmdu2_8_);
        multdivunit->outmdu2[9](outmdu2_9_);
        multdivunit->outmdu2[10](outmdu2_10_);
        multdivunit->outmdu2[11](outmdu2_11_);
        multdivunit->outmdu2[12](outmdu2_12_);
        multdivunit->outmdu2[13](outmdu2_13_);
        multdivunit->outmdu2[14](outmdu2_14_);
        multdivunit->outmdu2[15](outmdu2_15_);
        multdivunit->readymdu(S67);
        multdivunit->rst(S68);
        multdivunit->startmdu(S99);

    muxasu = new mux2ofnbits_16("muxasu");
        muxasu->in1[0](p2_0_);
        muxasu->in1[1](p2_1_);
        muxasu->in1[2](p2_2_);
        muxasu->in1[3](p2_3_);
        muxasu->in1[4](p2_4_);
        muxasu->in1[5](p2_5_);
        muxasu->in1[6](p2_6_);
        muxasu->in1[7](p2_7_);
        muxasu->in1[8](S66[8]);
        muxasu->in1[9](S66[9]);
        muxasu->in1[10](S66[10]);
        muxasu->in1[11](S66[11]);
        muxasu->in1[12](S66[12]);
        muxasu->in1[13](S66[13]);
        muxasu->in1[14](S66[14]);
        muxasu->in1[15](S66[15]);
        muxasu->in2[0](outimm_0_);
        muxasu->in2[1](outimm_1_);
        muxasu->in2[2](outimm_2_);
        muxasu->in2[3](outimm_3_);
        muxasu->in2[4](outimm_4_);
        muxasu->in2[5](outimm_5_);
        muxasu->in2[6](outimm_6_);
        muxasu->in2[7](outimm_7_);
        muxasu->in2[8](outimm_8_);
        muxasu->in2[9](outimm_9_);
        muxasu->in2[10](outimm_10_);
        muxasu->in2[11](outimm_11_);
        muxasu->in2[12](outimm_12_);
        muxasu->in2[13](outimm_13_);
        muxasu->in2[14](outimm_14_);
        muxasu->in2[15](outimm_15_);
        muxasu->outmux[0](outmuxasu_0_);
        muxasu->outmux[1](outmuxasu_1_);
        muxasu->outmux[2](outmuxasu_2_);
        muxasu->outmux[3](outmuxasu_3_);
        muxasu->outmux[4](outmuxasu_4_);
        muxasu->outmux[5](outmuxasu_5_);
        muxasu->outmux[6](outmuxasu_6_);
        muxasu->outmux[7](outmuxasu_7_);
        muxasu->outmux[8](outmuxasu_8_);
        muxasu->outmux[9](outmuxasu_9_);
        muxasu->outmux[10](outmuxasu_10_);
        muxasu->outmux[11](outmuxasu_11_);
        muxasu->outmux[12](outmuxasu_12_);
        muxasu->outmux[13](outmuxasu_13_);
        muxasu->outmux[14](outmuxasu_14_);
        muxasu->outmux[15](outmuxasu_15_);
        muxasu->sel1(S84);
        muxasu->sel2(S76);

    muxindatatrf = new mux8of16bits("muxindatatrf");
        muxindatatrf->in1[0](outimm_0_);
        muxindatatrf->in1[1](outimm_1_);
        muxindatatrf->in1[2](outimm_2_);
        muxindatatrf->in1[3](outimm_3_);
        muxindatatrf->in1[4](outimm_4_);
        muxindatatrf->in1[5](outimm_5_);
        muxindatatrf->in1[6](outimm_6_);
        muxindatatrf->in1[7](outimm_7_);
        muxindatatrf->in1[8](outimm_8_);
        muxindatatrf->in1[9](outimm_9_);
        muxindatatrf->in1[10](outimm_10_);
        muxindatatrf->in1[11](outimm_11_);
        muxindatatrf->in1[12](outimm_12_);
        muxindatatrf->in1[13](outimm_13_);
        muxindatatrf->in1[14](outimm_14_);
        muxindatatrf->in1[15](outimm_15_);
        muxindatatrf->in2[0](outmdu1_0_);
        muxindatatrf->in2[1](outmdu1_1_);
        muxindatatrf->in2[2](outmdu1_2_);
        muxindatatrf->in2[3](outmdu1_3_);
        muxindatatrf->in2[4](outmdu1_4_);
        muxindatatrf->in2[5](outmdu1_5_);
        muxindatatrf->in2[6](outmdu1_6_);
        muxindatatrf->in2[7](outmdu1_7_);
        muxindatatrf->in2[8](outmdu1_8_);
        muxindatatrf->in2[9](outmdu1_9_);
        muxindatatrf->in2[10](outmdu1_10_);
        muxindatatrf->in2[11](outmdu1_11_);
        muxindatatrf->in2[12](outmdu1_12_);
        muxindatatrf->in2[13](outmdu1_13_);
        muxindatatrf->in2[14](outmdu1_14_);
        muxindatatrf->in2[15](outmdu1_15_);
        muxindatatrf->in3[0](outmdu2_0_);
        muxindatatrf->in3[1](outmdu2_1_);
        muxindatatrf->in3[2](outmdu2_2_);
        muxindatatrf->in3[3](outmdu2_3_);
        muxindatatrf->in3[4](outmdu2_4_);
        muxindatatrf->in3[5](outmdu2_5_);
        muxindatatrf->in3[6](outmdu2_6_);
        muxindatatrf->in3[7](outmdu2_7_);
        muxindatatrf->in3[8](outmdu2_8_);
        muxindatatrf->in3[9](outmdu2_9_);
        muxindatatrf->in3[10](outmdu2_10_);
        muxindatatrf->in3[11](outmdu2_11_);
        muxindatatrf->in3[12](outmdu2_12_);
        muxindatatrf->in3[13](outmdu2_13_);
        muxindatatrf->in3[14](outmdu2_14_);
        muxindatatrf->in3[15](outmdu2_15_);
        muxindatatrf->in4[0](outasu_0_);
        muxindatatrf->in4[1](outasu_1_);
        muxindatatrf->in4[2](outasu_2_);
        muxindatatrf->in4[3](outasu_3_);
        muxindatatrf->in4[4](outasu_4_);
        muxindatatrf->in4[5](outasu_5_);
        muxindatatrf->in4[6](outasu_6_);
        muxindatatrf->in4[7](outasu_7_);
        muxindatatrf->in4[8](outasu_8_);
        muxindatatrf->in4[9](outasu_9_);
        muxindatatrf->in4[10](outasu_10_);
        muxindatatrf->in4[11](outasu_11_);
        muxindatatrf->in4[12](outasu_12_);
        muxindatatrf->in4[13](outasu_13_);
        muxindatatrf->in4[14](outasu_14_);
        muxindatatrf->in4[15](outasu_15_);
        muxindatatrf->in5[0](outllu_0_);
        muxindatatrf->in5[1](outllu_1_);
        muxindatatrf->in5[2](outllu_2_);
        muxindatatrf->in5[3](outllu_3_);
        muxindatatrf->in5[4](outllu_4_);
        muxindatatrf->in5[5](outllu_5_);
        muxindatatrf->in5[6](outllu_6_);
        muxindatatrf->in5[7](outllu_7_);
        muxindatatrf->in5[8](outllu_8_);
        muxindatatrf->in5[9](outllu_9_);
        muxindatatrf->in5[10](outllu_10_);
        muxindatatrf->in5[11](outllu_11_);
        muxindatatrf->in5[12](outllu_12_);
        muxindatatrf->in5[13](outllu_13_);
        muxindatatrf->in5[14](outllu_14_);
        muxindatatrf->in5[15](outllu_15_);
        muxindatatrf->in6[0](outshu_0_);
        muxindatatrf->in6[1](outshu_1_);
        muxindatatrf->in6[2](outshu_2_);
        muxindatatrf->in6[3](outshu_3_);
        muxindatatrf->in6[4](outshu_4_);
        muxindatatrf->in6[5](outshu_5_);
        muxindatatrf->in6[6](outshu_6_);
        muxindatatrf->in6[7](outshu_7_);
        muxindatatrf->in6[8](outshu_8_);
        muxindatatrf->in6[9](outshu_9_);
        muxindatatrf->in6[10](outshu_10_);
        muxindatatrf->in6[11](outshu_11_);
        muxindatatrf->in6[12](outshu_12_);
        muxindatatrf->in6[13](outshu_13_);
        muxindatatrf->in6[14](outshu_14_);
        muxindatatrf->in6[15](outshu_15_);
        muxindatatrf->in7[0](S45[0]);
        muxindatatrf->in7[1](S45[1]);
        muxindatatrf->in7[2](S45[2]);
        muxindatatrf->in7[3](S45[3]);
        muxindatatrf->in7[4](S45[4]);
        muxindatatrf->in7[5](S45[5]);
        muxindatatrf->in7[6](S45[6]);
        muxindatatrf->in7[7](S45[7]);
        muxindatatrf->in7[8](S45[8]);
        muxindatatrf->in7[9](S45[9]);
        muxindatatrf->in7[10](S45[10]);
        muxindatatrf->in7[11](S45[11]);
        muxindatatrf->in7[12](S45[12]);
        muxindatatrf->in7[13](S45[13]);
        muxindatatrf->in7[14](S45[14]);
        muxindatatrf->in7[15](S45[15]);
        muxindatatrf->in8[0](outpc1_0_);
        muxindatatrf->in8[1](outpc1_1_);
        muxindatatrf->in8[2](outpc1_2_);
        muxindatatrf->in8[3](outpc1_3_);
        muxindatatrf->in8[4](outpc1_4_);
        muxindatatrf->in8[5](outpc1_5_);
        muxindatatrf->in8[6](outpc1_6_);
        muxindatatrf->in8[7](outpc1_7_);
        muxindatatrf->in8[8](outpc1_8_);
        muxindatatrf->in8[9](outpc1_9_);
        muxindatatrf->in8[10](outpc1_10_);
        muxindatatrf->in8[11](outpc1_11_);
        muxindatatrf->in8[12](outpc1_12_);
        muxindatatrf->in8[13](outpc1_13_);
        muxindatatrf->in8[14](outpc1_14_);
        muxindatatrf->in8[15](outpc1_15_);
        muxindatatrf->outmux[0](S50[0]);
        muxindatatrf->outmux[1](S50[1]);
        muxindatatrf->outmux[2](S50[2]);
        muxindatatrf->outmux[3](S50[3]);
        muxindatatrf->outmux[4](S50[4]);
        muxindatatrf->outmux[5](S50[5]);
        muxindatatrf->outmux[6](S50[6]);
        muxindatatrf->outmux[7](S50[7]);
        muxindatatrf->outmux[8](S50[8]);
        muxindatatrf->outmux[9](S50[9]);
        muxindatatrf->outmux[10](S50[10]);
        muxindatatrf->outmux[11](S50[11]);
        muxindatatrf->outmux[12](S50[12]);
        muxindatatrf->outmux[13](S50[13]);
        muxindatatrf->outmux[14](S50[14]);
        muxindatatrf->outmux[15](S50[15]);
        muxindatatrf->sel1(S78);
        muxindatatrf->sel2(S80);
        muxindatatrf->sel3(S81);
        muxindatatrf->sel4(S73);
        muxindatatrf->sel5(S79);
        muxindatatrf->sel6(S97);
        muxindatatrf->sel7(S74);
        muxindatatrf->sel8(S87);

    muxmem = new mux2ofnbits_16("muxmem");
        muxmem->in1[0](outadr_0_);
        muxmem->in1[1](outadr_1_);
        muxmem->in1[2](outadr_2_);
        muxmem->in1[3](outadr_3_);
        muxmem->in1[4](outadr_4_);
        muxmem->in1[5](outadr_5_);
        muxmem->in1[6](outadr_6_);
        muxmem->in1[7](outadr_7_);
        muxmem->in1[8](outadr_8_);
        muxmem->in1[9](outadr_9_);
        muxmem->in1[10](outadr_10_);
        muxmem->in1[11](outadr_11_);
        muxmem->in1[12](outadr_12_);
        muxmem->in1[13](outadr_13_);
        muxmem->in1[14](outadr_14_);
        muxmem->in1[15](outadr_15_);
        muxmem->in2[0](outpc_0_);
        muxmem->in2[1](outpc_1_);
        muxmem->in2[2](outpc_2_);
        muxmem->in2[3](outpc_3_);
        muxmem->in2[4](outpc_4_);
        muxmem->in2[5](outpc_5_);
        muxmem->in2[6](outpc_6_);
        muxmem->in2[7](outpc_7_);
        muxmem->in2[8](outpc_8_);
        muxmem->in2[9](outpc_9_);
        muxmem->in2[10](outpc_10_);
        muxmem->in2[11](outpc_11_);
        muxmem->in2[12](outpc_12_);
        muxmem->in2[13](outpc_13_);
        muxmem->in2[14](outpc_14_);
        muxmem->in2[15](outpc_15_);
        muxmem->outmux[0](S38[0]);
        muxmem->outmux[1](S38[1]);
        muxmem->outmux[2](S38[2]);
        muxmem->outmux[3](S38[3]);
        muxmem->outmux[4](S38[4]);
        muxmem->outmux[5](S38[5]);
        muxmem->outmux[6](S38[6]);
        muxmem->outmux[7](S38[7]);
        muxmem->outmux[8](S38[8]);
        muxmem->outmux[9](S38[9]);
        muxmem->outmux[10](S38[10]);
        muxmem->outmux[11](S38[11]);
        muxmem->outmux[12](S38[12]);
        muxmem->outmux[13](S38[13]);
        muxmem->outmux[14](S38[14]);
        muxmem->outmux[15](S38[15]);
        muxmem->sel1(S72);
        muxmem->sel2(S88);

    muxpc = new mux3of16bits("muxpc");
        muxpc->in1[0](S46[0]);
        muxpc->in1[1](S46[1]);
        muxpc->in1[2](S46[2]);
        muxpc->in1[3](S46[3]);
        muxpc->in1[4](S46[4]);
        muxpc->in1[5](S46[5]);
        muxpc->in1[6](S46[6]);
        muxpc->in1[7](S46[7]);
        muxpc->in1[8](S46[8]);
        muxpc->in1[9](S46[9]);
        muxpc->in1[10](S46[10]);
        muxpc->in1[11](S46[11]);
        muxpc->in1[12](S46[12]);
        muxpc->in1[13](S46[13]);
        muxpc->in1[14](S46[14]);
        muxpc->in1[15](S46[15]);
        muxpc->in2[0](outpcp_0_);
        muxpc->in2[1](outpcp_1_);
        muxpc->in2[2](outpcp_2_);
        muxpc->in2[3](outpcp_3_);
        muxpc->in2[4](outpcp_4_);
        muxpc->in2[5](outpcp_5_);
        muxpc->in2[6](outpcp_6_);
        muxpc->in2[7](outpcp_7_);
        muxpc->in2[8](outpcp_8_);
        muxpc->in2[9](outpcp_9_);
        muxpc->in2[10](outpcp_10_);
        muxpc->in2[11](outpcp_11_);
        muxpc->in2[12](outpcp_12_);
        muxpc->in2[13](outpcp_13_);
        muxpc->in2[14](outpcp_14_);
        muxpc->in2[15](outpcp_15_);
        muxpc->in3[0](outpc1_0_);
        muxpc->in3[1](outpc1_1_);
        muxpc->in3[2](outpc1_2_);
        muxpc->in3[3](outpc1_3_);
        muxpc->in3[4](outpc1_4_);
        muxpc->in3[5](outpc1_5_);
        muxpc->in3[6](outpc1_6_);
        muxpc->in3[7](outpc1_7_);
        muxpc->in3[8](outpc1_8_);
        muxpc->in3[9](outpc1_9_);
        muxpc->in3[10](outpc1_10_);
        muxpc->in3[11](outpc1_11_);
        muxpc->in3[12](outpc1_12_);
        muxpc->in3[13](outpc1_13_);
        muxpc->in3[14](outpc1_14_);
        muxpc->in3[15](outpc1_15_);
        muxpc->outmux[0](outmuxpc_0_);
        muxpc->outmux[1](outmuxpc_1_);
        muxpc->outmux[2](outmuxpc_2_);
        muxpc->outmux[3](outmuxpc_3_);
        muxpc->outmux[4](outmuxpc_4_);
        muxpc->outmux[5](outmuxpc_5_);
        muxpc->outmux[6](outmuxpc_6_);
        muxpc->outmux[7](outmuxpc_7_);
        muxpc->outmux[8](outmuxpc_8_);
        muxpc->outmux[9](outmuxpc_9_);
        muxpc->outmux[10](outmuxpc_10_);
        muxpc->outmux[11](outmuxpc_11_);
        muxpc->outmux[12](outmuxpc_12_);
        muxpc->outmux[13](outmuxpc_13_);
        muxpc->outmux[14](outmuxpc_14_);
        muxpc->outmux[15](outmuxpc_15_);
        muxpc->sel1(S82);
        muxpc->sel2(S89);
        muxpc->sel3(S86);

    muxpcp = new mux2ofnbits_16("muxpcp");
        muxpcp->in1[0](S46[0]);
        muxpcp->in1[1](S46[1]);
        muxpcp->in1[2](S46[2]);
        muxpcp->in1[3](S46[3]);
        muxpcp->in1[4](S46[4]);
        muxpcp->in1[5](S46[5]);
        muxpcp->in1[6](S46[6]);
        muxpcp->in1[7](S46[7]);
        muxpcp->in1[8](S46[8]);
        muxpcp->in1[9](S46[9]);
        muxpcp->in1[10](S46[10]);
        muxpcp->in1[11](S46[11]);
        muxpcp->in1[12](S46[12]);
        muxpcp->in1[13](S46[13]);
        muxpcp->in1[14](S46[14]);
        muxpcp->in1[15](S46[15]);
        muxpcp->in2[0](outimm_0_);
        muxpcp->in2[1](outimm_1_);
        muxpcp->in2[2](outimm_2_);
        muxpcp->in2[3](outimm_3_);
        muxpcp->in2[4](outimm_4_);
        muxpcp->in2[5](outimm_5_);
        muxpcp->in2[6](outimm_6_);
        muxpcp->in2[7](outimm_7_);
        muxpcp->in2[8](outimm_8_);
        muxpcp->in2[9](outimm_9_);
        muxpcp->in2[10](outimm_10_);
        muxpcp->in2[11](outimm_11_);
        muxpcp->in2[12](outimm_12_);
        muxpcp->in2[13](outimm_13_);
        muxpcp->in2[14](outimm_14_);
        muxpcp->in2[15](outimm_15_);
        muxpcp->outmux[0](outmuxpcp_0_);
        muxpcp->outmux[1](outmuxpcp_1_);
        muxpcp->outmux[2](outmuxpcp_2_);
        muxpcp->outmux[3](outmuxpcp_3_);
        muxpcp->outmux[4](outmuxpcp_4_);
        muxpcp->outmux[5](outmuxpcp_5_);
        muxpcp->outmux[6](outmuxpcp_6_);
        muxpcp->outmux[7](outmuxpcp_7_);
        muxpcp->outmux[8](outmuxpcp_8_);
        muxpcp->outmux[9](outmuxpcp_9_);
        muxpcp->outmux[10](outmuxpcp_10_);
        muxpcp->outmux[11](outmuxpcp_11_);
        muxpcp->outmux[12](outmuxpcp_12_);
        muxpcp->outmux[13](outmuxpcp_13_);
        muxpcp->outmux[14](outmuxpcp_14_);
        muxpcp->outmux[15](outmuxpcp_15_);
        muxpcp->sel1(S83);
        muxpcp->sel2(S77);

    muxrd = new mux2ofnbits_4("muxrd");
        muxrd->in1[0](instruction_0_);
        muxrd->in1[1](instruction_1_);
        muxrd->in1[2](instruction_2_);
        muxrd->in1[3](instruction_3_);
        muxrd->in2[0](outrd1_0_);
        muxrd->in2[1](outrd1_1_);
        muxrd->in2[2](outrd1_2_);
        muxrd->in2[3](outrd1_3_);
        muxrd->outmux[0](S61[0]);
        muxrd->outmux[1](S61[1]);
        muxrd->outmux[2](S61[2]);
        muxrd->outmux[3](S61[3]);
        muxrd->sel1(S90);
        muxrd->sel2(S91);

    muxrs1 = new mux2ofnbits_4("muxrs1");
        muxrs1->in1[0](S49[0]);
        muxrs1->in1[1](S49[1]);
        muxrs1->in1[2](S49[2]);
        muxrs1->in1[3](S49[3]);
        muxrs1->in2[0](instruction_0_);
        muxrs1->in2[1](instruction_1_);
        muxrs1->in2[2](instruction_2_);
        muxrs1->in2[3](instruction_3_);
        muxrs1->outmux[0](S62[0]);
        muxrs1->outmux[1](S62[1]);
        muxrs1->outmux[2](S62[2]);
        muxrs1->outmux[3](S62[3]);
        muxrs1->sel1(S94);
        muxrs1->sel2(S92);

    muxrs2 = new mux2ofnbits_4("muxrs2");
        muxrs2->in1[0](S49[4]);
        muxrs2->in1[1](S59[1]);
        muxrs2->in1[2](S59[2]);
        muxrs2->in1[3](S59[3]);
        muxrs2->in2[0](instruction_0_);
        muxrs2->in2[1](instruction_1_);
        muxrs2->in2[2](instruction_2_);
        muxrs2->in2[3](instruction_3_);
        muxrs2->outmux[0](S63[0]);
        muxrs2->outmux[1](S63[1]);
        muxrs2->outmux[2](S63[2]);
        muxrs2->outmux[3](S63[3]);
        muxrs2->sel1(S95);
        muxrs2->sel2(S93);

    muxshu = new mux2ofnbits_5("muxshu");
        muxshu->in1[0](p2_0_);
        muxshu->in1[1](p2_1_);
        muxshu->in1[2](p2_2_);
        muxshu->in1[3](p2_3_);
        muxshu->in1[4](p2_4_);
        muxshu->in2[0](S49[0]);
        muxshu->in2[1](S49[1]);
        muxshu->in2[2](S49[2]);
        muxshu->in2[3](S49[3]);
        muxshu->in2[4](S49[4]);
        muxshu->outmux[0](outmuxshu_0_);
        muxshu->outmux[1](outmuxshu_1_);
        muxshu->outmux[2](outmuxshu_2_);
        muxshu->outmux[3](outmuxshu_3_);
        muxshu->outmux[4](outmuxshu_4_);
        muxshu->sel1(S85);
        muxshu->sel2(S96);

    pc = new reg("pc");
        pc->clk(S44);
        pc->inreg[0](outmuxpc_0_);
        pc->inreg[1](outmuxpc_1_);
        pc->inreg[2](outmuxpc_2_);
        pc->inreg[3](outmuxpc_3_);
        pc->inreg[4](outmuxpc_4_);
        pc->inreg[5](outmuxpc_5_);
        pc->inreg[6](outmuxpc_6_);
        pc->inreg[7](outmuxpc_7_);
        pc->inreg[8](outmuxpc_8_);
        pc->inreg[9](outmuxpc_9_);
        pc->inreg[10](outmuxpc_10_);
        pc->inreg[11](outmuxpc_11_);
        pc->inreg[12](outmuxpc_12_);
        pc->inreg[13](outmuxpc_13_);
        pc->inreg[14](outmuxpc_14_);
        pc->inreg[15](outmuxpc_15_);
        pc->ld(S55);
        pc->outreg[0](outpc_0_);
        pc->outreg[1](outpc_1_);
        pc->outreg[2](outpc_2_);
        pc->outreg[3](outpc_3_);
        pc->outreg[4](outpc_4_);
        pc->outreg[5](outpc_5_);
        pc->outreg[6](outpc_6_);
        pc->outreg[7](outpc_7_);
        pc->outreg[8](outpc_8_);
        pc->outreg[9](outpc_9_);
        pc->outreg[10](outpc_10_);
        pc->outreg[11](outpc_11_);
        pc->outreg[12](outpc_12_);
        pc->outreg[13](outpc_13_);
        pc->outreg[14](outpc_14_);
        pc->outreg[15](outpc_15_);
        pc->rst(S68);

    pc1 = new inc_16("pc1");
        pc1->ininc[0](outpc_0_);
        pc1->ininc[1](outpc_1_);
        pc1->ininc[2](outpc_2_);
        pc1->ininc[3](outpc_3_);
        pc1->ininc[4](outpc_4_);
        pc1->ininc[5](outpc_5_);
        pc1->ininc[6](outpc_6_);
        pc1->ininc[7](outpc_7_);
        pc1->ininc[8](outpc_8_);
        pc1->ininc[9](outpc_9_);
        pc1->ininc[10](outpc_10_);
        pc1->ininc[11](outpc_11_);
        pc1->ininc[12](outpc_12_);
        pc1->ininc[13](outpc_13_);
        pc1->ininc[14](outpc_14_);
        pc1->ininc[15](outpc_15_);
        pc1->outinc[0](outpc1_0_);
        pc1->outinc[1](outpc1_1_);
        pc1->outinc[2](outpc1_2_);
        pc1->outinc[3](outpc1_3_);
        pc1->outinc[4](outpc1_4_);
        pc1->outinc[5](outpc1_5_);
        pc1->outinc[6](outpc1_6_);
        pc1->outinc[7](outpc1_7_);
        pc1->outinc[8](outpc1_8_);
        pc1->outinc[9](outpc1_9_);
        pc1->outinc[10](outpc1_10_);
        pc1->outinc[11](outpc1_11_);
        pc1->outinc[12](outpc1_12_);
        pc1->outinc[13](outpc1_13_);
        pc1->outinc[14](outpc1_14_);
        pc1->outinc[15](outpc1_15_);

    pcp = new add_16("pcp");
        pcp->in1[0](outmuxpcp_0_);
        pcp->in1[1](outmuxpcp_1_);
        pcp->in1[2](outmuxpcp_2_);
        pcp->in1[3](outmuxpcp_3_);
        pcp->in1[4](outmuxpcp_4_);
        pcp->in1[5](outmuxpcp_5_);
        pcp->in1[6](outmuxpcp_6_);
        pcp->in1[7](outmuxpcp_7_);
        pcp->in1[8](outmuxpcp_8_);
        pcp->in1[9](outmuxpcp_9_);
        pcp->in1[10](outmuxpcp_10_);
        pcp->in1[11](outmuxpcp_11_);
        pcp->in1[12](outmuxpcp_12_);
        pcp->in1[13](outmuxpcp_13_);
        pcp->in1[14](outmuxpcp_14_);
        pcp->in1[15](outmuxpcp_15_);
        pcp->in2[0](outpc_0_);
        pcp->in2[1](outpc_1_);
        pcp->in2[2](outpc_2_);
        pcp->in2[3](outpc_3_);
        pcp->in2[4](outpc_4_);
        pcp->in2[5](outpc_5_);
        pcp->in2[6](outpc_6_);
        pcp->in2[7](outpc_7_);
        pcp->in2[8](outpc_8_);
        pcp->in2[9](outpc_9_);
        pcp->in2[10](outpc_10_);
        pcp->in2[11](outpc_11_);
        pcp->in2[12](outpc_12_);
        pcp->in2[13](outpc_13_);
        pcp->in2[14](outpc_14_);
        pcp->in2[15](outpc_15_);
        pcp->outadd[0](outpcp_0_);
        pcp->outadd[1](outpcp_1_);
        pcp->outadd[2](outpcp_2_);
        pcp->outadd[3](outpcp_3_);
        pcp->outadd[4](outpcp_4_);
        pcp->outadd[5](outpcp_5_);
        pcp->outadd[6](outpcp_6_);
        pcp->outadd[7](outpcp_7_);
        pcp->outadd[8](outpcp_8_);
        pcp->outadd[9](outpcp_9_);
        pcp->outadd[10](outpcp_10_);
        pcp->outadd[11](outpcp_11_);
        pcp->outadd[12](outpcp_12_);
        pcp->outadd[13](outpcp_13_);
        pcp->outadd[14](outpcp_14_);
        pcp->outadd[15](outpcp_15_);

    rd1 = new inc_4("rd1");
        rd1->ininc[0](instruction_0_);
        rd1->ininc[1](instruction_1_);
        rd1->ininc[2](instruction_2_);
        rd1->ininc[3](instruction_3_);
        rd1->outinc[0](outrd1_0_);
        rd1->outinc[1](outrd1_1_);
        rd1->outinc[2](outrd1_2_);
        rd1->outinc[3](outrd1_3_);

    shiftunit = new shu("shiftunit");
        shiftunit->arithsh(S42);
        shiftunit->in1[0](S46[0]);
        shiftunit->in1[1](S46[1]);
        shiftunit->in1[2](S46[2]);
        shiftunit->in1[3](S46[3]);
        shiftunit->in1[4](S46[4]);
        shiftunit->in1[5](S46[5]);
        shiftunit->in1[6](S46[6]);
        shiftunit->in1[7](S46[7]);
        shiftunit->in1[8](S46[8]);
        shiftunit->in1[9](S46[9]);
        shiftunit->in1[10](S46[10]);
        shiftunit->in1[11](S46[11]);
        shiftunit->in1[12](S46[12]);
        shiftunit->in1[13](S46[13]);
        shiftunit->in1[14](S46[14]);
        shiftunit->in1[15](S46[15]);
        shiftunit->in2[0](outmuxshu_0_);
        shiftunit->in2[1](outmuxshu_1_);
        shiftunit->in2[2](outmuxshu_2_);
        shiftunit->in2[3](outmuxshu_3_);
        shiftunit->in2[4](outmuxshu_4_);
        shiftunit->logicsh(S57);
        shiftunit->outshu[0](outshu_0_);
        shiftunit->outshu[1](outshu_1_);
        shiftunit->outshu[2](outshu_2_);
        shiftunit->outshu[3](outshu_3_);
        shiftunit->outshu[4](outshu_4_);
        shiftunit->outshu[5](outshu_5_);
        shiftunit->outshu[6](outshu_6_);
        shiftunit->outshu[7](outshu_7_);
        shiftunit->outshu[8](outshu_8_);
        shiftunit->outshu[9](outshu_9_);
        shiftunit->outshu[10](outshu_10_);
        shiftunit->outshu[11](outshu_11_);
        shiftunit->outshu[12](outshu_12_);
        shiftunit->outshu[13](outshu_13_);
        shiftunit->outshu[14](outshu_14_);
        shiftunit->outshu[15](outshu_15_);


    SC_METHOD(sc_logic_signal_assignment);

    }

    void sc_logic_signal_assignment(void){ 
        sc_logic_1_signal.write(SC_LOGIC_1);
        sc_logic_0_signal.write(SC_LOGIC_0);
    }
};
#endif /* __DPU_H__ */

