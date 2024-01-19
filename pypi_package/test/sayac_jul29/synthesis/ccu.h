#include <systemc.h>
#include "Complex_NAgate_45.h"



#ifndef __CCU_H__
#define __CCU_H__
using namespace sc_core;

SC_MODULE( ccu ) {

    sc_in<sc_logic> clk;
    sc_in<sc_logic> rst;
    sc_in<sc_logic> readymem;
    sc_in<sc_logic> readymdu;
    sc_in<sc_logic> opcode[8];
    sc_in<sc_logic> fib[5];
    sc_in<sc_logic> outflag[8];
    sc_out<sc_logic> seldatabus_trf;
    sc_out<sc_logic> selpc1_trf;
    sc_out<sc_logic> selllu_trf;
    sc_out<sc_logic> selshu_trf;
    sc_out<sc_logic> selasu_trf;
    sc_out<sc_logic> selmdu1_trf;
    sc_out<sc_logic> selmdu2_trf;
    sc_out<sc_logic> selimm_trf;
    sc_out<sc_logic> selrs1_trf;
    sc_out<sc_logic> selrd_1_trf;
    sc_out<sc_logic> selrs2_trf;
    sc_out<sc_logic> selrd_2_trf;
    sc_out<sc_logic> selrd0_trf;
    sc_out<sc_logic> selrd1_trf;
    sc_out<sc_logic> writetrf;
    sc_out<sc_logic> selp1_pcp;
    sc_out<sc_logic> selimm_pcp;
    sc_out<sc_logic> selp1_pc;
    sc_out<sc_logic> selpcadd_pc;
    sc_out<sc_logic> selpc1_pc;
    sc_out<sc_logic> selpc_mem;
    sc_out<sc_logic> seladr_mem;
    sc_out<sc_logic> drivedatabus;
    sc_out<sc_logic> se5bits;
    sc_out<sc_logic> se6bits;
    sc_out<sc_logic> use8bits;
    sc_out<sc_logic> se8bits;
    sc_out<sc_logic> p1lowbits;
    sc_out<sc_logic> selp2_asu;
    sc_out<sc_logic> selimm_asu;
    sc_out<sc_logic> arithadd;
    sc_out<sc_logic> arithsub;
    sc_out<sc_logic> logicand;
    sc_out<sc_logic> onescomp;
    sc_out<sc_logic> twoscomp;
    sc_out<sc_logic> selp2_shu;
    sc_out<sc_logic> selshim_shu;
    sc_out<sc_logic> logicsh;
    sc_out<sc_logic> arithsh;
    sc_out<sc_logic> ldmdu1;
    sc_out<sc_logic> ldmdu2;
    sc_out<sc_logic> arithmul;
    sc_out<sc_logic> arithdiv;
    sc_out<sc_logic> startmdu;
    sc_out<sc_logic> ldir;
    sc_out<sc_logic> ldadr;
    sc_out<sc_logic> ldpc;
    sc_out<sc_logic> readmem;
    sc_out<sc_logic> writemem;
    sc_out<sc_logic> readio;
    sc_out<sc_logic> writeio;
    sc_out<sc_logic> setflags;
    sc_out<sc_logic> enflag;
    sc_out<sc_logic> selflag[8];

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
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S38 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S38");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S39 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S39");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S40 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S40");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S41 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S41");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S42 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S42");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S43 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S43");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S44 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S44");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S45 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S45");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S46 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S46");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S47 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S47");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S48 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S48");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S49 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S49");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S50 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S50");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S51 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S51");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S52 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S52");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S53 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S53");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S54 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S54");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S55 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S55");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S56 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S56");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S57 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S57");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S58 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S58");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S59 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S59");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S60 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S60");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S61 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S61");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S62 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S62");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S63 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S63");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S64 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S64");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S65 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S65");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S66 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S66");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S67 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S67");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S68 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S68");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S69 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S69");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S70 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S70");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S71 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S71");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S72 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S72");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S73 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S73");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S74 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S74");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S75 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S75");
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
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S102 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S102");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S103 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S103");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S104 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S104");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S105 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S105");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S106 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S106");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S107 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S107");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S108 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S108");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S109 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S109");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S110 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S110");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S111 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S111");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S112 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S112");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S113 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S113");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S114 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S114");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S115 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S115");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S116 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S116");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S117 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S117");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S118 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S118");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S119 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S119");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S120 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S120");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S121 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S121");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S122 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S122");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S123 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S123");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S124 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S124");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S125 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S125");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S126 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S126");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S127 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S127");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S128 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S128");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S129 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S129");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S130 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S130");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S131 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S131");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S132 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S132");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S133 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S133");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S134 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S134");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S135 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S135");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S136 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S136");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S137 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S137");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S138 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S138");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S139 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S139");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S140 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S140");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S141 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S141");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S142 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S142");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S143 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S143");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S144 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S144");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S145 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S145");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S146 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S146");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S147 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S147");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S148 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S148");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S149 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S149");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S150 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S150");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S151 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S151");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S152 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S152");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S153 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S153");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S154 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S154");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S155 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S155");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S156 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S156");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S157 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S157");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S158 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S158");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S159 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S159");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S160 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S160");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S161 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S161");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S162 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S162");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S163 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S163");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S164 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S164");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S165 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S165");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S166 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S166");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S167 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S167");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S168 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S168");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S169 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S169");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S170 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S170");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S171 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S171");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S172 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S172");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S173 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S173");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S174 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S174");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S175 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S175");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S176 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S176");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S177 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S177");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S178 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S178");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S179 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S179");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S180 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S180");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S181 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S181");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S182 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S182");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S183 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S183");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S184 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S184");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S185 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S185");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S186 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S186");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S187 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S187");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S188 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S188");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S189 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S189");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S190 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S190");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> S191 = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("S191");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _1091_Y = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_1091_Y");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _1107_Y = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_1107_Y");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _1115_S_0_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_1115_S_0_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _1115_Y = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_1115_Y");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _1135_Y = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_1135_Y");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _1245_Y = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_1245_Y");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _1360_B_3_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_1360_B_3_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _1405_Y_0_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_1405_Y_0_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _1405_Y_1_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_1405_Y_1_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _216_B_0_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_216_B_0_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _389_B_0_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_389_B_0_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> _389_B_2_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("_389_B_2_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> pstate_0_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("pstate_0_");
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> pstate_1_ = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("pstate_1_");

    NOR2_X1* NOR2_X1_1;
    INV_X1* INV_X1_1;
    INV_X1* INV_X1_2;
    NOR2_X1* NOR2_X1_2;
    INV_X1* INV_X1_3;
    NOR4_X1* NOR4_X1_1;
    NAND3_X1* NAND3_X1_1;
    NOR2_X1* NOR2_X1_3;
    NOR2_X1* NOR2_X1_4;
    NOR2_X1* NOR2_X1_5;
    NAND2_X1* NAND2_X1_1;
    INV_X1* INV_X1_4;
    NOR2_X1* NOR2_X1_6;
    INV_X1* INV_X1_5;
    OAI21_X1* OAI21_X1_1;
    NOR3_X1* NOR3_X1_1;
    AND2_X1* AND2_X1_1;
    AND2_X1* AND2_X1_2;
    AND2_X1* AND2_X1_3;
    NAND2_X1* NAND2_X1_2;
    NOR2_X1* NOR2_X1_7;
    NAND2_X1* NAND2_X1_3;
    INV_X1* INV_X1_6;
    NOR2_X1* NOR2_X1_8;
    NOR2_X1* NOR2_X1_9;
    NAND2_X1* NAND2_X1_4;
    NAND2_X1* NAND2_X1_5;
    AND2_X1* AND2_X1_4;
    OAI21_X1* OAI21_X1_2;
    INV_X1* INV_X1_7;
    NAND4_X1* NAND4_X1_1;
    NAND2_X1* NAND2_X1_6;
    INV_X1* INV_X1_8;
    NOR2_X1* NOR2_X1_10;
    NAND2_X1* NAND2_X1_7;
    AND2_X1* AND2_X1_5;
    AOI21_X1* AOI21_X1_1;
    AND3_X1* AND3_X1_1;
    NAND2_X1* NAND2_X1_8;
    NAND2_X1* NAND2_X1_9;
    AOI21_X1* AOI21_X1_2;
    OR2_X1* OR2_X1_1;
    OAI211_X1* OAI211_X1_1;
    NOR2_X1* NOR2_X1_11;
    NAND2_X1* NAND2_X1_10;
    INV_X1* INV_X1_9;
    NOR2_X1* NOR2_X1_12;
    NAND2_X1* NAND2_X1_11;
    INV_X1* INV_X1_10;
    NAND2_X1* NAND2_X1_12;
    INV_X1* INV_X1_11;
    NOR2_X1* NOR2_X1_13;
    NAND2_X1* NAND2_X1_13;
    AOI21_X1* AOI21_X1_3;
    INV_X1* INV_X1_12;
    INV_X1* INV_X1_13;
    NOR2_X1* NOR2_X1_14;
    NAND3_X1* NAND3_X1_2;
    INV_X1* INV_X1_14;
    INV_X1* INV_X1_15;
    NAND4_X1* NAND4_X1_2;
    INV_X1* INV_X1_16;
    NOR2_X1* NOR2_X1_15;
    AOI21_X1* AOI21_X1_4;
    INV_X1* INV_X1_17;
    NAND2_X1* NAND2_X1_14;
    NOR2_X1* NOR2_X1_16;
    OAI21_X1* OAI21_X1_3;
    NAND2_X1* NAND2_X1_15;
    NAND4_X1* NAND4_X1_3;
    NAND2_X1* NAND2_X1_16;
    INV_X1* INV_X1_18;
    NAND3_X1* NAND3_X1_3;
    AOI22_X1* AOI22_X1_1;
    NAND4_X1* NAND4_X1_4;
    NOR2_X1* NOR2_X1_17;
    NOR2_X1* NOR2_X1_18;
    NAND3_X1* NAND3_X1_4;
    OAI22_X1* OAI22_X1_1;
    OAI21_X1* OAI21_X1_4;
    NAND2_X1* NAND2_X1_17;
    NAND2_X1* NAND2_X1_18;
    NAND4_X1* NAND4_X1_5;
    NAND2_X1* NAND2_X1_19;
    NAND2_X1* NAND2_X1_20;
    NAND3_X1* NAND3_X1_5;
    OAI21_X1* OAI21_X1_5;
    INV_X1* INV_X1_19;
    NAND2_X1* NAND2_X1_21;
    NOR2_X1* NOR2_X1_19;
    INV_X1* INV_X1_20;
    NAND2_X1* NAND2_X1_22;
    NAND3_X1* NAND3_X1_6;
    NOR2_X1* NOR2_X1_20;
    NAND2_X1* NAND2_X1_23;
    AOI21_X1* AOI21_X1_5;
    NOR3_X1* NOR3_X1_2;
    NAND2_X1* NAND2_X1_24;
    INV_X1* INV_X1_21;
    NAND2_X1* NAND2_X1_25;
    AOI21_X1* AOI21_X1_6;
    NOR2_X1* NOR2_X1_21;
    INV_X1* INV_X1_22;
    NAND2_X1* NAND2_X1_26;
    AOI21_X1* AOI21_X1_7;
    INV_X1* INV_X1_23;
    NAND2_X1* NAND2_X1_27;
    INV_X1* INV_X1_24;
    NOR2_X1* NOR2_X1_22;
    NOR2_X1* NOR2_X1_23;
    AOI21_X1* AOI21_X1_8;
    NOR2_X1* NOR2_X1_24;
    AND3_X1* AND3_X1_2;
    OAI22_X1* OAI22_X1_2;
    AND2_X1* AND2_X1_6;
    OAI22_X1* OAI22_X1_3;
    NOR2_X1* NOR2_X1_25;
    NOR2_X1* NOR2_X1_26;
    AND3_X1* AND3_X1_3;
    NOR2_X1* NOR2_X1_27;
    NOR2_X1* NOR2_X1_28;
    INV_X1* INV_X1_25;
    OAI22_X1* OAI22_X1_4;
    OAI22_X1* OAI22_X1_5;
    INV_X1* INV_X1_26;
    NAND2_X1* NAND2_X1_28;
    NAND2_X1* NAND2_X1_29;
    NAND3_X1* NAND3_X1_7;
    NOR3_X1* NOR3_X1_3;
    NOR2_X1* NOR2_X1_29;
    NOR2_X1* NOR2_X1_30;
    NOR3_X1* NOR3_X1_4;
    NOR3_X1* NOR3_X1_5;
    NOR2_X1* NOR2_X1_31;
    INV_X1* INV_X1_27;
    NOR2_X1* NOR2_X1_32;
    NOR2_X1* NOR2_X1_33;
    INV_X1* INV_X1_28;
    NOR3_X1* NOR3_X1_6;
    NOR2_X1* NOR2_X1_34;
    OAI21_X1* OAI21_X1_6;
    NAND3_X1* NAND3_X1_8;
    NOR2_X1* NOR2_X1_35;
    NAND2_X1* NAND2_X1_30;
    OAI21_X1* OAI21_X1_7;
    OAI21_X1* OAI21_X1_8;
    OAI21_X1* OAI21_X1_9;
    NAND3_X1* NAND3_X1_9;
    NAND2_X1* NAND2_X1_31;
    OR2_X1* OR2_X1_2;
    AND4_X1* AND4_X1_1;
    NAND3_X1* NAND3_X1_10;
    NAND3_X1* NAND3_X1_11;
    INV_X1* INV_X1_29;
    INV_X1* INV_X1_30;
    OAI211_X1* OAI211_X1_2;
    NAND2_X1* NAND2_X1_32;
    OAI21_X1* OAI21_X1_10;
    NAND2_X1* NAND2_X1_33;
    NAND3_X1* NAND3_X1_12;
    AOI21_X1* AOI21_X1_9;
    AND2_X1* AND2_X1_7;
    OAI211_X1* OAI211_X1_3;
    NAND2_X1* NAND2_X1_34;
    OAI211_X1* OAI211_X1_4;
    NAND2_X1* NAND2_X1_35;
    OAI21_X1* OAI21_X1_11;
    AOI21_X1* AOI21_X1_10;
    OAI21_X1* OAI21_X1_12;
    NAND4_X1* NAND4_X1_6;
    NAND3_X1* NAND3_X1_13;
    OAI211_X1* OAI211_X1_5;
    NOR2_X1* NOR2_X1_36;
    NOR2_X1* NOR2_X1_37;
    OAI21_X1* OAI21_X1_13;
    OAI211_X1* OAI211_X1_6;
    INV_X1* INV_X1_31;
    DFFR_X1* DFFR_X1_1;
    DFFR_X1* DFFR_X1_2;
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

SC_CTOR( ccu ) {
    NOR2_X1_1 = new NOR2_X1("NOR2_X1_1");
        NOR2_X1_1->A1(pstate_1_);
        NOR2_X1_1->A2(pstate_0_);
        NOR2_X1_1->ZN(_1115_S_0_);

    INV_X1_1 = new INV_X1("INV_X1_1");
        INV_X1_1->A(S151);
        INV_X1_1->ZN(S101);

    INV_X1_2 = new INV_X1("INV_X1_2");
        INV_X1_2->A(pstate_1_);
        INV_X1_2->ZN(S102);

    NOR2_X1_2 = new NOR2_X1("NOR2_X1_2");
        NOR2_X1_2->A1(S102);
        NOR2_X1_2->A2(pstate_0_);
        NOR2_X1_2->ZN(S103);

    INV_X1_3 = new INV_X1("INV_X1_3");
        INV_X1_3->A(S153);
        INV_X1_3->ZN(S104);

    NOR4_X1_1 = new NOR4_X1("NOR4_X1_1");
        NOR4_X1_1->A1(S104);
        NOR4_X1_1->A2(S152);
        NOR4_X1_1->A3(S154);
        NOR4_X1_1->A4(S155);
        NOR4_X1_1->ZN(S105);

    NAND3_X1_1 = new NAND3_X1("NAND3_X1_1");
        NAND3_X1_1->A1(S105);
        NAND3_X1_1->A2(S101);
        NAND3_X1_1->A3(S103);
        NAND3_X1_1->ZN(S106);

    NOR2_X1_3 = new NOR2_X1("NOR2_X1_3");
        NOR2_X1_3->A1(S106);
        NOR2_X1_3->A2(S150);
        NOR2_X1_3->ZN(S172);

    NOR2_X1_4 = new NOR2_X1("NOR2_X1_4");
        NOR2_X1_4->A1(S155);
        NOR2_X1_4->A2(S154);
        NOR2_X1_4->ZN(S107);

    NOR2_X1_5 = new NOR2_X1("NOR2_X1_5");
        NOR2_X1_5->A1(S104);
        NOR2_X1_5->A2(S152);
        NOR2_X1_5->ZN(S108);

    NAND2_X1_1 = new NAND2_X1("NAND2_X1_1");
        NAND2_X1_1->A1(S108);
        NAND2_X1_1->A2(S107);
        NAND2_X1_1->ZN(S109);

    INV_X1_4 = new INV_X1("INV_X1_4");
        INV_X1_4->A(pstate_0_);
        INV_X1_4->ZN(S110);

    NOR2_X1_6 = new NOR2_X1("NOR2_X1_6");
        NOR2_X1_6->A1(S110);
        NOR2_X1_6->A2(pstate_1_);
        NOR2_X1_6->ZN(S111);

    INV_X1_5 = new INV_X1("INV_X1_5");
        INV_X1_5->A(S111);
        INV_X1_5->ZN(S112);

    OAI21_X1_1 = new OAI21_X1("OAI21_X1_1");
        OAI21_X1_1->A(S151);
        OAI21_X1_1->B1(S150);
        OAI21_X1_1->B2(_216_B_0_);
        OAI21_X1_1->ZN(S113);

    NOR3_X1_1 = new NOR3_X1("NOR3_X1_1");
        NOR3_X1_1->A1(S109);
        NOR3_X1_1->A2(S112);
        NOR3_X1_1->A3(S113);
        NOR3_X1_1->ZN(S181);

    AND2_X1_1 = new AND2_X1("AND2_X1_1");
        AND2_X1_1->A1(S150);
        AND2_X1_1->A2(S151);
        AND2_X1_1->ZN(S114);

    AND2_X1_2 = new AND2_X1("AND2_X1_2");
        AND2_X1_2->A1(S152);
        AND2_X1_2->A2(S153);
        AND2_X1_2->ZN(S115);

    AND2_X1_3 = new AND2_X1("AND2_X1_3");
        AND2_X1_3->A1(S154);
        AND2_X1_3->A2(S155);
        AND2_X1_3->ZN(S116);

    NAND2_X1_2 = new NAND2_X1("NAND2_X1_2");
        NAND2_X1_2->A1(S115);
        NAND2_X1_2->A2(S116);
        NAND2_X1_2->ZN(S117);

    NOR2_X1_7 = new NOR2_X1("NOR2_X1_7");
        NOR2_X1_7->A1(S117);
        NOR2_X1_7->A2(S112);
        NOR2_X1_7->ZN(S118);

    NAND2_X1_3 = new NAND2_X1("NAND2_X1_3");
        NAND2_X1_3->A1(S118);
        NAND2_X1_3->A2(S114);
        NAND2_X1_3->ZN(S119);

    INV_X1_6 = new INV_X1("INV_X1_6");
        INV_X1_6->A(S154);
        INV_X1_6->ZN(S120);

    NOR2_X1_8 = new NOR2_X1("NOR2_X1_8");
        NOR2_X1_8->A1(S120);
        NOR2_X1_8->A2(S155);
        NOR2_X1_8->ZN(S121);

    NOR2_X1_9 = new NOR2_X1("NOR2_X1_9");
        NOR2_X1_9->A1(S153);
        NOR2_X1_9->A2(S152);
        NOR2_X1_9->ZN(S122);

    NAND2_X1_4 = new NAND2_X1("NAND2_X1_4");
        NAND2_X1_4->A1(S121);
        NAND2_X1_4->A2(S122);
        NAND2_X1_4->ZN(S123);

    NAND2_X1_5 = new NAND2_X1("NAND2_X1_5");
        NAND2_X1_5->A1(S115);
        NAND2_X1_5->A2(S107);
        NAND2_X1_5->ZN(S124);

    AND2_X1_4 = new AND2_X1("AND2_X1_4");
        AND2_X1_4->A1(S123);
        AND2_X1_4->A2(S124);
        AND2_X1_4->ZN(S125);

    OAI21_X1_2 = new OAI21_X1("OAI21_X1_2");
        OAI21_X1_2->A(S119);
        OAI21_X1_2->B1(S112);
        OAI21_X1_2->B2(S125);
        OAI21_X1_2->ZN(S175);

    INV_X1_7 = new INV_X1("INV_X1_7");
        INV_X1_7->A(S150);
        INV_X1_7->ZN(S126);

    NAND4_X1_1 = new NAND4_X1("NAND4_X1_1");
        NAND4_X1_1->A1(S115);
        NAND4_X1_1->A2(S116);
        NAND4_X1_1->A3(S151);
        NAND4_X1_1->A4(S126);
        NAND4_X1_1->ZN(S127);

    NAND2_X1_6 = new NAND2_X1("NAND2_X1_6");
        NAND2_X1_6->A1(S121);
        NAND2_X1_6->A2(S115);
        NAND2_X1_6->ZN(S1);

    INV_X1_8 = new INV_X1("INV_X1_8");
        INV_X1_8->A(S155);
        INV_X1_8->ZN(S2);

    NOR2_X1_10 = new NOR2_X1("NOR2_X1_10");
        NOR2_X1_10->A1(S2);
        NOR2_X1_10->A2(S154);
        NOR2_X1_10->ZN(S3);

    NAND2_X1_7 = new NAND2_X1("NAND2_X1_7");
        NAND2_X1_7->A1(S3);
        NAND2_X1_7->A2(S122);
        NAND2_X1_7->ZN(S4);

    AND2_X1_5 = new AND2_X1("AND2_X1_5");
        AND2_X1_5->A1(S4);
        AND2_X1_5->A2(S1);
        AND2_X1_5->ZN(S5);

    AOI21_X1_1 = new AOI21_X1("AOI21_X1_1");
        AOI21_X1_1->A(S112);
        AOI21_X1_1->B1(S5);
        AOI21_X1_1->B2(S127);
        AOI21_X1_1->ZN(S187);

    AND3_X1_1 = new AND3_X1("AND3_X1_1");
        AND3_X1_1->A1(S3);
        AND3_X1_1->A2(S111);
        AND3_X1_1->A3(S152);
        AND3_X1_1->ZN(S130);

    NAND2_X1_8 = new NAND2_X1("NAND2_X1_8");
        NAND2_X1_8->A1(S116);
        NAND2_X1_8->A2(S122);
        NAND2_X1_8->ZN(S6);

    NAND2_X1_9 = new NAND2_X1("NAND2_X1_9");
        NAND2_X1_9->A1(S108);
        NAND2_X1_9->A2(S3);
        NAND2_X1_9->ZN(S7);

    AOI21_X1_2 = new AOI21_X1("AOI21_X1_2");
        AOI21_X1_2->A(S112);
        AOI21_X1_2->B1(S7);
        AOI21_X1_2->B2(S6);
        AOI21_X1_2->ZN(S134);

    OR2_X1_1 = new OR2_X1("OR2_X1_1");
        OR2_X1_1->A1(S134);
        OR2_X1_1->A2(S130);
        OR2_X1_1->ZN(S171);

    OAI211_X1_1 = new OAI211_X1("OAI211_X1_1");
        OAI211_X1_1->A(S155);
        OAI211_X1_1->B(S154);
        OAI211_X1_1->C1(S152);
        OAI211_X1_1->C2(S153);
        OAI211_X1_1->ZN(S8);

    NOR2_X1_11 = new NOR2_X1("NOR2_X1_11");
        NOR2_X1_11->A1(S8);
        NOR2_X1_11->A2(S115);
        NOR2_X1_11->ZN(S9);

    NAND2_X1_10 = new NAND2_X1("NAND2_X1_10");
        NAND2_X1_10->A1(S9);
        NAND2_X1_10->A2(S103);
        NAND2_X1_10->ZN(S10);

    INV_X1_9 = new INV_X1("INV_X1_9");
        INV_X1_9->A(S10);
        INV_X1_9->ZN(S145);

    NOR2_X1_12 = new NOR2_X1("NOR2_X1_12");
        NOR2_X1_12->A1(S102);
        NOR2_X1_12->A2(S110);
        NOR2_X1_12->ZN(S11);

    NAND2_X1_11 = new NAND2_X1("NAND2_X1_11");
        NAND2_X1_11->A1(S9);
        NAND2_X1_11->A2(S11);
        NAND2_X1_11->ZN(S12);

    INV_X1_10 = new INV_X1("INV_X1_10");
        INV_X1_10->A(S12);
        INV_X1_10->ZN(S176);

    NAND2_X1_12 = new NAND2_X1("NAND2_X1_12");
        NAND2_X1_12->A1(S108);
        NAND2_X1_12->A2(S121);
        NAND2_X1_12->ZN(S13);

    INV_X1_11 = new INV_X1("INV_X1_11");
        INV_X1_11->A(S152);
        INV_X1_11->ZN(S14);

    NOR2_X1_13 = new NOR2_X1("NOR2_X1_13");
        NOR2_X1_13->A1(S14);
        NOR2_X1_13->A2(S153);
        NOR2_X1_13->ZN(S15);

    NAND2_X1_13 = new NAND2_X1("NAND2_X1_13");
        NAND2_X1_13->A1(S121);
        NAND2_X1_13->A2(S15);
        NAND2_X1_13->ZN(S16);

    AOI21_X1_3 = new AOI21_X1("AOI21_X1_3");
        AOI21_X1_3->A(S112);
        AOI21_X1_3->B1(S13);
        AOI21_X1_3->B2(S16);
        AOI21_X1_3->ZN(S174);

    INV_X1_12 = new INV_X1("INV_X1_12");
        INV_X1_12->A(_389_B_0_);
        INV_X1_12->ZN(S17);

    INV_X1_13 = new INV_X1("INV_X1_13");
        INV_X1_13->A(S138);
        INV_X1_13->ZN(S18);

    NOR2_X1_14 = new NOR2_X1("NOR2_X1_14");
        NOR2_X1_14->A1(S18);
        NOR2_X1_14->A2(S139);
        NOR2_X1_14->ZN(S19);

    NAND3_X1_2 = new NAND3_X1("NAND3_X1_2");
        NAND3_X1_2->A1(S19);
        NAND3_X1_2->A2(S17);
        NAND3_X1_2->A3(S140);
        NAND3_X1_2->ZN(S20);

    INV_X1_14 = new INV_X1("INV_X1_14");
        INV_X1_14->A(S140);
        INV_X1_14->ZN(S21);

    INV_X1_15 = new INV_X1("INV_X1_15");
        INV_X1_15->A(_389_B_2_);
        INV_X1_15->ZN(S22);

    NAND4_X1_2 = new NAND4_X1("NAND4_X1_2");
        NAND4_X1_2->A1(S19);
        NAND4_X1_2->A2(S22);
        NAND4_X1_2->A3(S21);
        NAND4_X1_2->A4(S17);
        NAND4_X1_2->ZN(S23);

    INV_X1_16 = new INV_X1("INV_X1_16");
        INV_X1_16->A(S139);
        INV_X1_16->ZN(S24);

    NOR2_X1_15 = new NOR2_X1("NOR2_X1_15");
        NOR2_X1_15->A1(S24);
        NOR2_X1_15->A2(S140);
        NOR2_X1_15->ZN(S25);

    AOI21_X1_4 = new AOI21_X1("AOI21_X1_4");
        AOI21_X1_4->A(_389_B_2_);
        AOI21_X1_4->B1(S138);
        AOI21_X1_4->B2(_389_B_0_);
        AOI21_X1_4->ZN(S26);

    INV_X1_17 = new INV_X1("INV_X1_17");
        INV_X1_17->A(S26);
        INV_X1_17->ZN(S27);

    NAND2_X1_14 = new NAND2_X1("NAND2_X1_14");
        NAND2_X1_14->A1(S27);
        NAND2_X1_14->A2(S25);
        NAND2_X1_14->ZN(S28);

    NOR2_X1_16 = new NOR2_X1("NOR2_X1_16");
        NOR2_X1_16->A1(S139);
        NOR2_X1_16->A2(S138);
        NOR2_X1_16->ZN(S29);

    OAI21_X1_3 = new OAI21_X1("OAI21_X1_3");
        OAI21_X1_3->A(S17);
        OAI21_X1_3->B1(S21);
        OAI21_X1_3->B2(_389_B_2_);
        OAI21_X1_3->ZN(S30);

    NAND2_X1_15 = new NAND2_X1("NAND2_X1_15");
        NAND2_X1_15->A1(S30);
        NAND2_X1_15->A2(S29);
        NAND2_X1_15->ZN(S31);

    NAND4_X1_3 = new NAND4_X1("NAND4_X1_3");
        NAND4_X1_3->A1(S28);
        NAND4_X1_3->A2(S23);
        NAND4_X1_3->A3(S20);
        NAND4_X1_3->A4(S31);
        NAND4_X1_3->ZN(S32);

    NAND2_X1_16 = new NAND2_X1("NAND2_X1_16");
        NAND2_X1_16->A1(S101);
        NAND2_X1_16->A2(S150);
        NAND2_X1_16->ZN(S33);

    INV_X1_18 = new INV_X1("INV_X1_18");
        INV_X1_18->A(S33);
        INV_X1_18->ZN(S34);

    NAND3_X1_3 = new NAND3_X1("NAND3_X1_3");
        NAND3_X1_3->A1(S32);
        NAND3_X1_3->A2(S118);
        NAND3_X1_3->A3(S34);
        NAND3_X1_3->ZN(S35);

    AOI22_X1_1 = new AOI22_X1("AOI22_X1_1");
        AOI22_X1_1->A1(S3);
        AOI22_X1_1->A2(S115);
        AOI22_X1_1->B1(S116);
        AOI22_X1_1->B2(S122);
        AOI22_X1_1->ZN(S36);

    NAND4_X1_4 = new NAND4_X1("NAND4_X1_4");
        NAND4_X1_4->A1(S36);
        NAND4_X1_4->A2(S13);
        NAND4_X1_4->A3(S123);
        NAND4_X1_4->A4(S127);
        NAND4_X1_4->ZN(S37);

    NOR2_X1_17 = new NOR2_X1("NOR2_X1_17");
        NOR2_X1_17->A1(S151);
        NOR2_X1_17->A2(S150);
        NOR2_X1_17->ZN(S38);

    NOR2_X1_18 = new NOR2_X1("NOR2_X1_18");
        NOR2_X1_18->A1(S114);
        NOR2_X1_18->A2(S38);
        NOR2_X1_18->ZN(S39);

    NAND3_X1_4 = new NAND3_X1("NAND3_X1_4");
        NAND3_X1_4->A1(S115);
        NAND3_X1_4->A2(S116);
        NAND3_X1_4->A3(_216_B_0_);
        NAND3_X1_4->ZN(S40);

    OAI22_X1_1 = new OAI22_X1("OAI22_X1_1");
        OAI22_X1_1->A1(S40);
        OAI22_X1_1->A2(S39);
        OAI22_X1_1->B1(S109);
        OAI22_X1_1->B2(S33);
        OAI22_X1_1->ZN(S41);

    OAI21_X1_4 = new OAI21_X1("OAI21_X1_4");
        OAI21_X1_4->A(S111);
        OAI21_X1_4->B1(S37);
        OAI21_X1_4->B2(S41);
        OAI21_X1_4->ZN(S42);

    NAND2_X1_17 = new NAND2_X1("NAND2_X1_17");
        NAND2_X1_17->A1(S42);
        NAND2_X1_17->A2(S35);
        NAND2_X1_17->ZN(S183);

    NAND2_X1_18 = new NAND2_X1("NAND2_X1_18");
        NAND2_X1_18->A1(S3);
        NAND2_X1_18->A2(S15);
        NAND2_X1_18->ZN(S43);

    NAND4_X1_5 = new NAND4_X1("NAND4_X1_5");
        NAND4_X1_5->A1(S43);
        NAND4_X1_5->A2(S4);
        NAND4_X1_5->A3(S1);
        NAND4_X1_5->A4(S124);
        NAND4_X1_5->ZN(S44);

    NAND2_X1_19 = new NAND2_X1("NAND2_X1_19");
        NAND2_X1_19->A1(S108);
        NAND2_X1_19->A2(S116);
        NAND2_X1_19->ZN(S45);

    NAND2_X1_20 = new NAND2_X1("NAND2_X1_20");
        NAND2_X1_20->A1(S15);
        NAND2_X1_20->A2(S116);
        NAND2_X1_20->ZN(S46);

    NAND3_X1_5 = new NAND3_X1("NAND3_X1_5");
        NAND3_X1_5->A1(S7);
        NAND3_X1_5->A2(S45);
        NAND3_X1_5->A3(S46);
        NAND3_X1_5->ZN(S47);

    OAI21_X1_5 = new OAI21_X1("OAI21_X1_5");
        OAI21_X1_5->A(S111);
        OAI21_X1_5->B1(S44);
        OAI21_X1_5->B2(S47);
        OAI21_X1_5->ZN(S48);

    INV_X1_19 = new INV_X1("INV_X1_19");
        INV_X1_19->A(S48);
        INV_X1_19->ZN(S185);

    NAND2_X1_21 = new NAND2_X1("NAND2_X1_21");
        NAND2_X1_21->A1(S118);
        NAND2_X1_21->A2(S38);
        NAND2_X1_21->ZN(S49);

    NOR2_X1_19 = new NOR2_X1("NOR2_X1_19");
        NOR2_X1_19->A1(S49);
        NOR2_X1_19->A2(_216_B_0_);
        NOR2_X1_19->ZN(S184);

    INV_X1_20 = new INV_X1("INV_X1_20");
        INV_X1_20->A(S114);
        INV_X1_20->ZN(S50);

    NAND2_X1_22 = new NAND2_X1("NAND2_X1_22");
        NAND2_X1_22->A1(S105);
        NAND2_X1_22->A2(S50);
        NAND2_X1_22->ZN(S51);

    NAND3_X1_6 = new NAND3_X1("NAND3_X1_6");
        NAND3_X1_6->A1(S28);
        NAND3_X1_6->A2(S23);
        NAND3_X1_6->A3(S31);
        NAND3_X1_6->ZN(S52);

    NOR2_X1_20 = new NOR2_X1("NOR2_X1_20");
        NOR2_X1_20->A1(S40);
        NOR2_X1_20->A2(S33);
        NOR2_X1_20->ZN(S53);

    NAND2_X1_23 = new NAND2_X1("NAND2_X1_23");
        NAND2_X1_23->A1(S52);
        NAND2_X1_23->A2(S53);
        NAND2_X1_23->ZN(S54);

    AOI21_X1_5 = new AOI21_X1("AOI21_X1_5");
        AOI21_X1_5->A(S112);
        AOI21_X1_5->B1(S54);
        AOI21_X1_5->B2(S51);
        AOI21_X1_5->ZN(S178);

    NOR3_X1_2 = new NOR3_X1("NOR3_X1_2");
        NOR3_X1_2->A1(S109);
        NOR3_X1_2->A2(S112);
        NOR3_X1_2->A3(S50);
        NOR3_X1_2->ZN(S168);

    NAND2_X1_24 = new NAND2_X1("NAND2_X1_24");
        NAND2_X1_24->A1(S118);
        NAND2_X1_24->A2(S34);
        NAND2_X1_24->ZN(S55);

    INV_X1_21 = new INV_X1("INV_X1_21");
        INV_X1_21->A(_216_B_0_);
        INV_X1_21->ZN(S56);

    NAND2_X1_25 = new NAND2_X1("NAND2_X1_25");
        NAND2_X1_25->A1(S52);
        NAND2_X1_25->A2(S56);
        NAND2_X1_25->ZN(S57);

    AOI21_X1_6 = new AOI21_X1("AOI21_X1_6");
        AOI21_X1_6->A(S55);
        AOI21_X1_6->B1(S57);
        AOI21_X1_6->B2(S20);
        AOI21_X1_6->ZN(S177);

    NOR2_X1_21 = new NOR2_X1("NOR2_X1_21");
        NOR2_X1_21->A1(S109);
        NOR2_X1_21->A2(S101);
        NOR2_X1_21->ZN(S58);

    INV_X1_22 = new INV_X1("INV_X1_22");
        INV_X1_22->A(S58);
        INV_X1_22->ZN(S59);

    NAND2_X1_26 = new NAND2_X1("NAND2_X1_26");
        NAND2_X1_26->A1(S32);
        NAND2_X1_26->A2(S53);
        NAND2_X1_26->ZN(S60);

    AOI21_X1_7 = new AOI21_X1("AOI21_X1_7");
        AOI21_X1_7->A(S112);
        AOI21_X1_7->B1(S60);
        AOI21_X1_7->B2(S59);
        AOI21_X1_7->ZN(S182);

    INV_X1_23 = new INV_X1("INV_X1_23");
        INV_X1_23->A(S106);
        INV_X1_23->ZN(S170);

    NAND2_X1_27 = new NAND2_X1("NAND2_X1_27");
        NAND2_X1_27->A1(S170);
        NAND2_X1_27->A2(S150);
        NAND2_X1_27->ZN(S61);

    INV_X1_24 = new INV_X1("INV_X1_24");
        INV_X1_24->A(S61);
        INV_X1_24->ZN(S136);

    NOR2_X1_22 = new NOR2_X1("NOR2_X1_22");
        NOR2_X1_22->A1(S49);
        NOR2_X1_22->A2(S56);
        NOR2_X1_22->ZN(S167);

    NOR2_X1_23 = new NOR2_X1("NOR2_X1_23");
        NOR2_X1_23->A1(S123);
        NOR2_X1_23->A2(S112);
        NOR2_X1_23->ZN(S189);

    AOI21_X1_8 = new AOI21_X1("AOI21_X1_8");
        AOI21_X1_8->A(S112);
        AOI21_X1_8->B1(S36);
        AOI21_X1_8->B2(S16);
        AOI21_X1_8->ZN(S169);

    NOR2_X1_24 = new NOR2_X1("NOR2_X1_24");
        NOR2_X1_24->A1(S13);
        NOR2_X1_24->A2(S112);
        NOR2_X1_24->ZN(S162);

    AND3_X1_2 = new AND3_X1("AND3_X1_2");
        AND3_X1_2->A1(S7);
        AND3_X1_2->A2(S43);
        AND3_X1_2->A3(S124);
        AND3_X1_2->ZN(S62);

    OAI22_X1_2 = new OAI22_X1("OAI22_X1_2");
        OAI22_X1_2->A1(S49);
        OAI22_X1_2->A2(_216_B_0_);
        OAI22_X1_2->B1(S62);
        OAI22_X1_2->B2(S112);
        OAI22_X1_2->ZN(S179);

    AND2_X1_6 = new AND2_X1("AND2_X1_6");
        AND2_X1_6->A1(S36);
        AND2_X1_6->A2(S123);
        AND2_X1_6->ZN(S63);

    OAI22_X1_3 = new OAI22_X1("OAI22_X1_3");
        OAI22_X1_3->A1(S63);
        OAI22_X1_3->A2(S112);
        OAI22_X1_3->B1(S49);
        OAI22_X1_3->B2(S56);
        OAI22_X1_3->ZN(S173);

    NOR2_X1_25 = new NOR2_X1("NOR2_X1_25");
        NOR2_X1_25->A1(S125);
        NOR2_X1_25->A2(S112);
        NOR2_X1_25->ZN(S146);

    NOR2_X1_26 = new NOR2_X1("NOR2_X1_26");
        NOR2_X1_26->A1(S119);
        NOR2_X1_26->A2(S149);
        NOR2_X1_26->ZN(S148);

    AND3_X1_3 = new AND3_X1("AND3_X1_3");
        AND3_X1_3->A1(S118);
        AND3_X1_3->A2(S114);
        AND3_X1_3->A3(S149);
        AND3_X1_3->ZN(S188);

    NOR2_X1_27 = new NOR2_X1("NOR2_X1_27");
        NOR2_X1_27->A1(S5);
        NOR2_X1_27->A2(S112);
        NOR2_X1_27->ZN(S180);

    NOR2_X1_28 = new NOR2_X1("NOR2_X1_28");
        NOR2_X1_28->A1(S127);
        NOR2_X1_28->A2(S112);
        NOR2_X1_28->ZN(S186);

    INV_X1_25 = new INV_X1("INV_X1_25");
        INV_X1_25->A(S186);
        INV_X1_25->ZN(S64);

    OAI22_X1_4 = new OAI22_X1("OAI22_X1_4");
        OAI22_X1_4->A1(S64);
        OAI22_X1_4->A2(_216_B_0_);
        OAI22_X1_4->B1(S112);
        OAI22_X1_4->B2(S1);
        OAI22_X1_4->ZN(S147);

    OAI22_X1_5 = new OAI22_X1("OAI22_X1_5");
        OAI22_X1_5->A1(S64);
        OAI22_X1_5->A2(S56);
        OAI22_X1_5->B1(S112);
        OAI22_X1_5->B2(S4);
        OAI22_X1_5->ZN(S133);

    INV_X1_26 = new INV_X1("INV_X1_26");
        INV_X1_26->A(_1360_B_3_);
        INV_X1_26->ZN(S65);

    NAND2_X1_28 = new NAND2_X1("NAND2_X1_28");
        NAND2_X1_28->A1(S153);
        NAND2_X1_28->A2(S152);
        NAND2_X1_28->ZN(S66);

    NAND2_X1_29 = new NAND2_X1("NAND2_X1_29");
        NAND2_X1_29->A1(S104);
        NAND2_X1_29->A2(S14);
        NAND2_X1_29->ZN(S67);

    NAND3_X1_7 = new NAND3_X1("NAND3_X1_7");
        NAND3_X1_7->A1(S67);
        NAND3_X1_7->A2(S66);
        NAND3_X1_7->A3(S116);
        NAND3_X1_7->ZN(S68);

    NOR3_X1_3 = new NOR3_X1("NOR3_X1_3");
        NOR3_X1_3->A1(S68);
        NOR3_X1_3->A2(S112);
        NOR3_X1_3->A3(S65);
        NOR3_X1_3->ZN(S144);

    NOR2_X1_29 = new NOR2_X1("NOR2_X1_29");
        NOR2_X1_29->A1(S46);
        NOR2_X1_29->A2(S112);
        NOR2_X1_29->ZN(S132);

    NOR2_X1_30 = new NOR2_X1("NOR2_X1_30");
        NOR2_X1_30->A1(S45);
        NOR2_X1_30->A2(S112);
        NOR2_X1_30->ZN(S131);

    NOR3_X1_4 = new NOR3_X1("NOR3_X1_4");
        NOR3_X1_4->A1(S109);
        NOR3_X1_4->A2(S112);
        NOR3_X1_4->A3(S151);
        NOR3_X1_4->ZN(S143);

    NOR3_X1_5 = new NOR3_X1("NOR3_X1_5");
        NOR3_X1_5->A1(S106);
        NOR3_X1_5->A2(_216_B_0_);
        NOR3_X1_5->A3(S150);
        NOR3_X1_5->ZN(S164);

    NOR2_X1_31 = new NOR2_X1("NOR2_X1_31");
        NOR2_X1_31->A1(S61);
        NOR2_X1_31->A2(_216_B_0_);
        NOR2_X1_31->ZN(S191);

    INV_X1_27 = new INV_X1("INV_X1_27");
        INV_X1_27->A(S172);
        INV_X1_27->ZN(S69);

    NOR2_X1_32 = new NOR2_X1("NOR2_X1_32");
        NOR2_X1_32->A1(S69);
        NOR2_X1_32->A2(S56);
        NOR2_X1_32->ZN(S163);

    NOR2_X1_33 = new NOR2_X1("NOR2_X1_33");
        NOR2_X1_33->A1(S61);
        NOR2_X1_33->A2(S56);
        NOR2_X1_33->ZN(S190);

    INV_X1_28 = new INV_X1("INV_X1_28");
        INV_X1_28->A(S49);
        INV_X1_28->ZN(S137);

    NOR3_X1_6 = new NOR3_X1("NOR3_X1_6");
        NOR3_X1_6->A1(S39);
        NOR3_X1_6->A2(S117);
        NOR3_X1_6->A3(_216_B_0_);
        NOR3_X1_6->ZN(S70);

    NOR2_X1_34 = new NOR2_X1("NOR2_X1_34");
        NOR2_X1_34->A1(S109);
        NOR2_X1_34->A2(S150);
        NOR2_X1_34->ZN(S71);

    OAI21_X1_6 = new OAI21_X1("OAI21_X1_6");
        OAI21_X1_6->A(S111);
        OAI21_X1_6->B1(S70);
        OAI21_X1_6->B2(S71);
        OAI21_X1_6->ZN(S72);

    NAND3_X1_8 = new NAND3_X1("NAND3_X1_8");
        NAND3_X1_8->A1(S72);
        NAND3_X1_8->A2(S48);
        NAND3_X1_8->A3(S61);
        NAND3_X1_8->ZN(_1091_Y);

    NOR2_X1_35 = new NOR2_X1("NOR2_X1_35");
        NOR2_X1_35->A1(S109);
        NOR2_X1_35->A2(S113);
        NOR2_X1_35->ZN(S73);

    NAND2_X1_30 = new NAND2_X1("NAND2_X1_30");
        NAND2_X1_30->A1(S2);
        NAND2_X1_30->A2(S120);
        NAND2_X1_30->ZN(S74);

    OAI21_X1_7 = new OAI21_X1("OAI21_X1_7");
        OAI21_X1_7->A(S8);
        OAI21_X1_7->B1(S74);
        OAI21_X1_7->B2(S115);
        OAI21_X1_7->ZN(S75);

    OAI21_X1_8 = new OAI21_X1("OAI21_X1_8");
        OAI21_X1_8->A(S75);
        OAI21_X1_8->B1(S101);
        OAI21_X1_8->B2(S117);
        OAI21_X1_8->ZN(S76);

    OAI21_X1_9 = new OAI21_X1("OAI21_X1_9");
        OAI21_X1_9->A(S111);
        OAI21_X1_9->B1(S76);
        OAI21_X1_9->B2(S73);
        OAI21_X1_9->ZN(S77);

    NAND3_X1_9 = new NAND3_X1("NAND3_X1_9");
        NAND3_X1_9->A1(S69);
        NAND3_X1_9->A2(S77);
        NAND3_X1_9->A3(S10);
        NAND3_X1_9->ZN(_1107_Y);

    NAND2_X1_31 = new NAND2_X1("NAND2_X1_31");
        NAND2_X1_31->A1(S9);
        NAND2_X1_31->A2(pstate_1_);
        NAND2_X1_31->ZN(S78);

    OR2_X1_2 = new OR2_X1("OR2_X1_2");
        OR2_X1_2->A1(_216_B_0_);
        OR2_X1_2->A2(S165);
        OR2_X1_2->ZN(S79);

    AND4_X1_1 = new AND4_X1("AND4_X1_1");
        AND4_X1_1->A1(S101);
        AND4_X1_1->A2(S108);
        AND4_X1_1->A3(S79);
        AND4_X1_1->A4(S107);
        AND4_X1_1->ZN(S80);

    NAND3_X1_10 = new NAND3_X1("NAND3_X1_10");
        NAND3_X1_10->A1(S80);
        NAND3_X1_10->A2(S126);
        NAND3_X1_10->A3(S103);
        NAND3_X1_10->ZN(S81);

    NAND3_X1_11 = new NAND3_X1("NAND3_X1_11");
        NAND3_X1_11->A1(S77);
        NAND3_X1_11->A2(S78);
        NAND3_X1_11->A3(S81);
        NAND3_X1_11->ZN(_1115_Y);

    INV_X1_29 = new INV_X1("INV_X1_29");
        INV_X1_29->A(S118);
        INV_X1_29->ZN(S82);

    INV_X1_30 = new INV_X1("INV_X1_30");
        INV_X1_30->A(S39);
        INV_X1_30->ZN(S83);

    OAI211_X1_2 = new OAI211_X1("OAI211_X1_2");
        OAI211_X1_2->A(S29);
        OAI211_X1_2->B(S17);
        OAI211_X1_2->C1(S21);
        OAI211_X1_2->C2(_389_B_2_);
        OAI211_X1_2->ZN(S84);

    NAND2_X1_32 = new NAND2_X1("NAND2_X1_32");
        NAND2_X1_32->A1(S25);
        NAND2_X1_32->A2(S26);
        NAND2_X1_32->ZN(S85);

    OAI21_X1_10 = new OAI21_X1("OAI21_X1_10");
        OAI21_X1_10->A(S17);
        OAI21_X1_10->B1(S22);
        OAI21_X1_10->B2(S140);
        OAI21_X1_10->ZN(S86);

    NAND2_X1_33 = new NAND2_X1("NAND2_X1_33");
        NAND2_X1_33->A1(S86);
        NAND2_X1_33->A2(S19);
        NAND2_X1_33->ZN(S87);

    NAND3_X1_12 = new NAND3_X1("NAND3_X1_12");
        NAND3_X1_12->A1(S87);
        NAND3_X1_12->A2(S84);
        NAND3_X1_12->A3(S85);
        NAND3_X1_12->ZN(S88);

    AOI21_X1_9 = new AOI21_X1("AOI21_X1_9");
        AOI21_X1_9->A(S83);
        AOI21_X1_9->B1(S88);
        AOI21_X1_9->B2(S101);
        AOI21_X1_9->ZN(S89);

    AND2_X1_7 = new AND2_X1("AND2_X1_7");
        AND2_X1_7->A1(S106);
        AND2_X1_7->A2(S12);
        AND2_X1_7->ZN(S90);

    OAI211_X1_3 = new OAI211_X1("OAI211_X1_3");
        OAI211_X1_3->A(S75);
        OAI211_X1_3->B(S127);
        OAI211_X1_3->C1(S74);
        OAI211_X1_3->C2(S153);
        OAI211_X1_3->ZN(S91);

    NAND2_X1_34 = new NAND2_X1("NAND2_X1_34");
        NAND2_X1_34->A1(S91);
        NAND2_X1_34->A2(S111);
        NAND2_X1_34->ZN(S92);

    OAI211_X1_4 = new OAI211_X1("OAI211_X1_4");
        OAI211_X1_4->A(S90);
        OAI211_X1_4->B(S92);
        OAI211_X1_4->C1(S89);
        OAI211_X1_4->C2(S82);
        OAI211_X1_4->ZN(_1135_Y);

    NAND2_X1_35 = new NAND2_X1("NAND2_X1_35");
        NAND2_X1_35->A1(S80);
        NAND2_X1_35->A2(S103);
        NAND2_X1_35->ZN(S93);

    OAI21_X1_11 = new OAI21_X1("OAI21_X1_11");
        OAI21_X1_11->A(S101);
        OAI21_X1_11->B1(S24);
        OAI21_X1_11->B2(S21);
        OAI21_X1_11->ZN(S94);

    AOI21_X1_10 = new AOI21_X1("AOI21_X1_10");
        AOI21_X1_10->A(S117);
        AOI21_X1_10->B1(S39);
        AOI21_X1_10->B2(S94);
        AOI21_X1_10->ZN(S95);

    OAI21_X1_12 = new OAI21_X1("OAI21_X1_12");
        OAI21_X1_12->A(S111);
        OAI21_X1_12->B1(S95);
        OAI21_X1_12->B2(S58);
        OAI21_X1_12->ZN(S96);

    NAND4_X1_6 = new NAND4_X1("NAND4_X1_6");
        NAND4_X1_6->A1(S92);
        NAND4_X1_6->A2(S96);
        NAND4_X1_6->A3(S12);
        NAND4_X1_6->A4(S93);
        NAND4_X1_6->ZN(_1245_Y);

    NAND3_X1_13 = new NAND3_X1("NAND3_X1_13");
        NAND3_X1_13->A1(S9);
        NAND3_X1_13->A2(S65);
        NAND3_X1_13->A3(S111);
        NAND3_X1_13->ZN(S97);

    OAI211_X1_5 = new OAI211_X1("OAI211_X1_5");
        OAI211_X1_5->A(S97);
        OAI211_X1_5->B(S10);
        OAI211_X1_5->C1(pstate_0_);
        OAI211_X1_5->C2(pstate_1_);
        OAI211_X1_5->ZN(_1405_Y_0_);

    NOR2_X1_36 = new NOR2_X1("NOR2_X1_36");
        NOR2_X1_36->A1(S109);
        NOR2_X1_36->A2(S151);
        NOR2_X1_36->ZN(S98);

    NOR2_X1_37 = new NOR2_X1("NOR2_X1_37");
        NOR2_X1_37->A1(S68);
        NOR2_X1_37->A2(S65);
        NOR2_X1_37->ZN(S99);

    OAI21_X1_13 = new OAI21_X1("OAI21_X1_13");
        OAI21_X1_13->A(S111);
        OAI21_X1_13->B1(S99);
        OAI21_X1_13->B2(S98);
        OAI21_X1_13->ZN(S100);

    OAI211_X1_6 = new OAI211_X1("OAI211_X1_6");
        OAI211_X1_6->A(S100);
        OAI211_X1_6->B(S10);
        OAI211_X1_6->C1(S79);
        OAI211_X1_6->C2(S106);
        OAI211_X1_6->ZN(_1405_Y_1_);

    INV_X1_31 = new INV_X1("INV_X1_31");
        INV_X1_31->A(S166);
        INV_X1_31->ZN(S0);

    DFFR_X1_1 = new DFFR_X1("DFFR_X1_1");
        DFFR_X1_1->CK(S135);
        DFFR_X1_1->D(_1405_Y_0_);
        DFFR_X1_1->Q(pstate_0_);
        DFFR_X1_1->QN(S129);
        DFFR_X1_1->RN(S0);

    DFFR_X1_2 = new DFFR_X1("DFFR_X1_2");
        DFFR_X1_2->CK(S135);
        DFFR_X1_2->D(_1405_Y_1_);
        DFFR_X1_2->Q(pstate_1_);
        DFFR_X1_2->QN(S128);
        DFFR_X1_2->RN(S0);

    BUF_X1_1 = new BUF_X1("BUF_X1_1");
        BUF_X1_1->A(S130);
        BUF_X1_1->Z(arithadd);

    BUF_X1_2 = new BUF_X1("BUF_X1_2");
        BUF_X1_2->A(S131);
        BUF_X1_2->Z(arithdiv);

    BUF_X1_3 = new BUF_X1("BUF_X1_3");
        BUF_X1_3->A(S132);
        BUF_X1_3->Z(arithmul);

    BUF_X1_4 = new BUF_X1("BUF_X1_4");
        BUF_X1_4->A(S133);
        BUF_X1_4->Z(arithsh);

    BUF_X1_5 = new BUF_X1("BUF_X1_5");
        BUF_X1_5->A(S134);
        BUF_X1_5->Z(arithsub);

    BUF_X1_6 = new BUF_X1("BUF_X1_6");
        BUF_X1_6->A(clk);
        BUF_X1_6->Z(S135);

    BUF_X1_7 = new BUF_X1("BUF_X1_7");
        BUF_X1_7->A(S136);
        BUF_X1_7->Z(drivedatabus);

    BUF_X1_8 = new BUF_X1("BUF_X1_8");
        BUF_X1_8->A(S137);
        BUF_X1_8->Z(enflag);

    BUF_X1_9 = new BUF_X1("BUF_X1_9");
        BUF_X1_9->A(fib[0]);
        BUF_X1_9->Z(S138);

    BUF_X1_10 = new BUF_X1("BUF_X1_10");
        BUF_X1_10->A(fib[1]);
        BUF_X1_10->Z(S139);

    BUF_X1_11 = new BUF_X1("BUF_X1_11");
        BUF_X1_11->A(fib[2]);
        BUF_X1_11->Z(S140);

    BUF_X1_12 = new BUF_X1("BUF_X1_12");
        BUF_X1_12->A(fib[3]);
        BUF_X1_12->Z(S141);

    BUF_X1_13 = new BUF_X1("BUF_X1_13");
        BUF_X1_13->A(fib[4]);
        BUF_X1_13->Z(S142);

    BUF_X1_14 = new BUF_X1("BUF_X1_14");
        BUF_X1_14->A(S143);
        BUF_X1_14->Z(ldadr);

    BUF_X1_15 = new BUF_X1("BUF_X1_15");
        BUF_X1_15->A(_1115_S_0_);
        BUF_X1_15->Z(ldir);

    BUF_X1_16 = new BUF_X1("BUF_X1_16");
        BUF_X1_16->A(S144);
        BUF_X1_16->Z(ldmdu1);

    BUF_X1_17 = new BUF_X1("BUF_X1_17");
        BUF_X1_17->A(S145);
        BUF_X1_17->Z(ldmdu2);

    BUF_X1_18 = new BUF_X1("BUF_X1_18");
        BUF_X1_18->A(_1245_Y);
        BUF_X1_18->Z(ldpc);

    BUF_X1_19 = new BUF_X1("BUF_X1_19");
        BUF_X1_19->A(S146);
        BUF_X1_19->Z(logicand);

    BUF_X1_20 = new BUF_X1("BUF_X1_20");
        BUF_X1_20->A(S147);
        BUF_X1_20->Z(logicsh);

    BUF_X1_21 = new BUF_X1("BUF_X1_21");
        BUF_X1_21->A(S148);
        BUF_X1_21->Z(onescomp);

    BUF_X1_22 = new BUF_X1("BUF_X1_22");
        BUF_X1_22->A(opcode[0]);
        BUF_X1_22->Z(S149);

    BUF_X1_23 = new BUF_X1("BUF_X1_23");
        BUF_X1_23->A(opcode[1]);
        BUF_X1_23->Z(_216_B_0_);

    BUF_X1_24 = new BUF_X1("BUF_X1_24");
        BUF_X1_24->A(opcode[2]);
        BUF_X1_24->Z(S150);

    BUF_X1_25 = new BUF_X1("BUF_X1_25");
        BUF_X1_25->A(opcode[3]);
        BUF_X1_25->Z(S151);

    BUF_X1_26 = new BUF_X1("BUF_X1_26");
        BUF_X1_26->A(opcode[4]);
        BUF_X1_26->Z(S152);

    BUF_X1_27 = new BUF_X1("BUF_X1_27");
        BUF_X1_27->A(opcode[5]);
        BUF_X1_27->Z(S153);

    BUF_X1_28 = new BUF_X1("BUF_X1_28");
        BUF_X1_28->A(opcode[6]);
        BUF_X1_28->Z(S154);

    BUF_X1_29 = new BUF_X1("BUF_X1_29");
        BUF_X1_29->A(opcode[7]);
        BUF_X1_29->Z(S155);

    BUF_X1_30 = new BUF_X1("BUF_X1_30");
        BUF_X1_30->A(outflag[0]);
        BUF_X1_30->Z(S156);

    BUF_X1_31 = new BUF_X1("BUF_X1_31");
        BUF_X1_31->A(outflag[1]);
        BUF_X1_31->Z(S157);

    BUF_X1_32 = new BUF_X1("BUF_X1_32");
        BUF_X1_32->A(outflag[2]);
        BUF_X1_32->Z(S158);

    BUF_X1_33 = new BUF_X1("BUF_X1_33");
        BUF_X1_33->A(outflag[3]);
        BUF_X1_33->Z(S159);

    BUF_X1_34 = new BUF_X1("BUF_X1_34");
        BUF_X1_34->A(outflag[4]);
        BUF_X1_34->Z(_389_B_0_);

    BUF_X1_35 = new BUF_X1("BUF_X1_35");
        BUF_X1_35->A(outflag[5]);
        BUF_X1_35->Z(_389_B_2_);

    BUF_X1_36 = new BUF_X1("BUF_X1_36");
        BUF_X1_36->A(outflag[6]);
        BUF_X1_36->Z(S160);

    BUF_X1_37 = new BUF_X1("BUF_X1_37");
        BUF_X1_37->A(outflag[7]);
        BUF_X1_37->Z(S161);

    BUF_X1_38 = new BUF_X1("BUF_X1_38");
        BUF_X1_38->A(S162);
        BUF_X1_38->Z(p1lowbits);

    BUF_X1_39 = new BUF_X1("BUF_X1_39");
        BUF_X1_39->A(S163);
        BUF_X1_39->Z(readio);

    BUF_X1_40 = new BUF_X1("BUF_X1_40");
        BUF_X1_40->A(S164);
        BUF_X1_40->Z(readmem);

    BUF_X1_41 = new BUF_X1("BUF_X1_41");
        BUF_X1_41->A(readymdu);
        BUF_X1_41->Z(_1360_B_3_);

    BUF_X1_42 = new BUF_X1("BUF_X1_42");
        BUF_X1_42->A(readymem);
        BUF_X1_42->Z(S165);

    BUF_X1_43 = new BUF_X1("BUF_X1_43");
        BUF_X1_43->A(rst);
        BUF_X1_43->Z(S166);

    BUF_X1_44 = new BUF_X1("BUF_X1_44");
        BUF_X1_44->A(S167);
        BUF_X1_44->Z(se5bits);

    BUF_X1_45 = new BUF_X1("BUF_X1_45");
        BUF_X1_45->A(S168);
        BUF_X1_45->Z(se6bits);

    BUF_X1_46 = new BUF_X1("BUF_X1_46");
        BUF_X1_46->A(S169);
        BUF_X1_46->Z(se8bits);

    BUF_X1_47 = new BUF_X1("BUF_X1_47");
        BUF_X1_47->A(S170);
        BUF_X1_47->Z(seladr_mem);

    BUF_X1_48 = new BUF_X1("BUF_X1_48");
        BUF_X1_48->A(S171);
        BUF_X1_48->Z(selasu_trf);

    BUF_X1_49 = new BUF_X1("BUF_X1_49");
        BUF_X1_49->A(S172);
        BUF_X1_49->Z(seldatabus_trf);

    BUF_X1_50 = new BUF_X1("BUF_X1_50");
        BUF_X1_50->A(sc_logic_0_signal);
        BUF_X1_50->Z(selflag[0]);

    BUF_X1_51 = new BUF_X1("BUF_X1_51");
        BUF_X1_51->A(sc_logic_0_signal);
        BUF_X1_51->Z(selflag[1]);

    BUF_X1_52 = new BUF_X1("BUF_X1_52");
        BUF_X1_52->A(sc_logic_0_signal);
        BUF_X1_52->Z(selflag[2]);

    BUF_X1_53 = new BUF_X1("BUF_X1_53");
        BUF_X1_53->A(sc_logic_0_signal);
        BUF_X1_53->Z(selflag[3]);

    BUF_X1_54 = new BUF_X1("BUF_X1_54");
        BUF_X1_54->A(S137);
        BUF_X1_54->Z(selflag[4]);

    BUF_X1_55 = new BUF_X1("BUF_X1_55");
        BUF_X1_55->A(S137);
        BUF_X1_55->Z(selflag[5]);

    BUF_X1_56 = new BUF_X1("BUF_X1_56");
        BUF_X1_56->A(sc_logic_0_signal);
        BUF_X1_56->Z(selflag[6]);

    BUF_X1_57 = new BUF_X1("BUF_X1_57");
        BUF_X1_57->A(sc_logic_0_signal);
        BUF_X1_57->Z(selflag[7]);

    BUF_X1_58 = new BUF_X1("BUF_X1_58");
        BUF_X1_58->A(S173);
        BUF_X1_58->Z(selimm_asu);

    BUF_X1_59 = new BUF_X1("BUF_X1_59");
        BUF_X1_59->A(S168);
        BUF_X1_59->Z(selimm_pcp);

    BUF_X1_60 = new BUF_X1("BUF_X1_60");
        BUF_X1_60->A(S174);
        BUF_X1_60->Z(selimm_trf);

    BUF_X1_61 = new BUF_X1("BUF_X1_61");
        BUF_X1_61->A(S175);
        BUF_X1_61->Z(selllu_trf);

    BUF_X1_62 = new BUF_X1("BUF_X1_62");
        BUF_X1_62->A(S145);
        BUF_X1_62->Z(selmdu1_trf);

    BUF_X1_63 = new BUF_X1("BUF_X1_63");
        BUF_X1_63->A(S176);
        BUF_X1_63->Z(selmdu2_trf);

    BUF_X1_64 = new BUF_X1("BUF_X1_64");
        BUF_X1_64->A(S177);
        BUF_X1_64->Z(selp1_pc);

    BUF_X1_65 = new BUF_X1("BUF_X1_65");
        BUF_X1_65->A(S178);
        BUF_X1_65->Z(selp1_pcp);

    BUF_X1_66 = new BUF_X1("BUF_X1_66");
        BUF_X1_66->A(S179);
        BUF_X1_66->Z(selp2_asu);

    BUF_X1_67 = new BUF_X1("BUF_X1_67");
        BUF_X1_67->A(S180);
        BUF_X1_67->Z(selp2_shu);

    BUF_X1_68 = new BUF_X1("BUF_X1_68");
        BUF_X1_68->A(_1135_Y);
        BUF_X1_68->Z(selpc1_pc);

    BUF_X1_69 = new BUF_X1("BUF_X1_69");
        BUF_X1_69->A(S181);
        BUF_X1_69->Z(selpc1_trf);

    BUF_X1_70 = new BUF_X1("BUF_X1_70");
        BUF_X1_70->A(_1115_S_0_);
        BUF_X1_70->Z(selpc_mem);

    BUF_X1_71 = new BUF_X1("BUF_X1_71");
        BUF_X1_71->A(S182);
        BUF_X1_71->Z(selpcadd_pc);

    BUF_X1_72 = new BUF_X1("BUF_X1_72");
        BUF_X1_72->A(_1107_Y);
        BUF_X1_72->Z(selrd0_trf);

    BUF_X1_73 = new BUF_X1("BUF_X1_73");
        BUF_X1_73->A(S176);
        BUF_X1_73->Z(selrd1_trf);

    BUF_X1_74 = new BUF_X1("BUF_X1_74");
        BUF_X1_74->A(S183);
        BUF_X1_74->Z(selrd_1_trf);

    BUF_X1_75 = new BUF_X1("BUF_X1_75");
        BUF_X1_75->A(S184);
        BUF_X1_75->Z(selrd_2_trf);

    BUF_X1_76 = new BUF_X1("BUF_X1_76");
        BUF_X1_76->A(_1091_Y);
        BUF_X1_76->Z(selrs1_trf);

    BUF_X1_77 = new BUF_X1("BUF_X1_77");
        BUF_X1_77->A(S185);
        BUF_X1_77->Z(selrs2_trf);

    BUF_X1_78 = new BUF_X1("BUF_X1_78");
        BUF_X1_78->A(S186);
        BUF_X1_78->Z(selshim_shu);

    BUF_X1_79 = new BUF_X1("BUF_X1_79");
        BUF_X1_79->A(S187);
        BUF_X1_79->Z(selshu_trf);

    BUF_X1_80 = new BUF_X1("BUF_X1_80");
        BUF_X1_80->A(sc_logic_0_signal);
        BUF_X1_80->Z(setflags);

    BUF_X1_81 = new BUF_X1("BUF_X1_81");
        BUF_X1_81->A(S144);
        BUF_X1_81->Z(startmdu);

    BUF_X1_82 = new BUF_X1("BUF_X1_82");
        BUF_X1_82->A(S188);
        BUF_X1_82->Z(twoscomp);

    BUF_X1_83 = new BUF_X1("BUF_X1_83");
        BUF_X1_83->A(S189);
        BUF_X1_83->Z(use8bits);

    BUF_X1_84 = new BUF_X1("BUF_X1_84");
        BUF_X1_84->A(S190);
        BUF_X1_84->Z(writeio);

    BUF_X1_85 = new BUF_X1("BUF_X1_85");
        BUF_X1_85->A(S191);
        BUF_X1_85->Z(writemem);

    BUF_X1_86 = new BUF_X1("BUF_X1_86");
        BUF_X1_86->A(_1115_Y);
        BUF_X1_86->Z(writetrf);


    SC_METHOD(sc_logic_signal_assignment);

    }

    void sc_logic_signal_assignment(void){ 
        sc_logic_1_signal.write(SC_LOGIC_1);
        sc_logic_0_signal.write(SC_LOGIC_0);
    }
};
#endif /* __CCU_H__ */

