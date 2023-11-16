#include <systemc.h>
#include "Complex_NAgate_45.h"

#include "ccu.h"
#include "dpu.h"


#ifndef __SAYAC_TOP_H__
#define __SAYAC_TOP_H__
using namespace sc_core;

SC_MODULE( SAYAC_TOP ) {

    sc_in<sc_logic> clk;
    sc_in<sc_logic> rst;
    sc_in<sc_logic> readyMEM;
    sc_in<sc_logic> dataBusIn[16];
    sc_out<sc_logic> readMEM;
    sc_out<sc_logic> writeMEM;
    sc_out<sc_logic> readIO;
    sc_out<sc_logic> writeIO;
    sc_out<sc_logic> dataBusOut[16];
    sc_out<sc_logic> addrBus[16];
    sc_out<sc_logic> readInst;
    sc_out<sc_logic> PCout[16];

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
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> selpc_mem = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("selpc_mem");
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
    sc_signal<sc_logic, sc_core::SC_MANY_WRITERS> writetrf = sc_signal<sc_logic, sc_core::SC_MANY_WRITERS>("writetrf");

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
    ccu* controller;
    dpu* datapath;

SC_CTOR( SAYAC_TOP ) {
    BUF_X1_1 = new BUF_X1("BUF_X1_1");
        BUF_X1_1->A(S0);
        BUF_X1_1->Z(PCout[0]);

    BUF_X1_2 = new BUF_X1("BUF_X1_2");
        BUF_X1_2->A(S7);
        BUF_X1_2->Z(PCout[1]);

    BUF_X1_3 = new BUF_X1("BUF_X1_3");
        BUF_X1_3->A(S1);
        BUF_X1_3->Z(PCout[10]);

    BUF_X1_4 = new BUF_X1("BUF_X1_4");
        BUF_X1_4->A(S2);
        BUF_X1_4->Z(PCout[11]);

    BUF_X1_5 = new BUF_X1("BUF_X1_5");
        BUF_X1_5->A(S3);
        BUF_X1_5->Z(PCout[12]);

    BUF_X1_6 = new BUF_X1("BUF_X1_6");
        BUF_X1_6->A(S4);
        BUF_X1_6->Z(PCout[13]);

    BUF_X1_7 = new BUF_X1("BUF_X1_7");
        BUF_X1_7->A(S5);
        BUF_X1_7->Z(PCout[14]);

    BUF_X1_8 = new BUF_X1("BUF_X1_8");
        BUF_X1_8->A(S6);
        BUF_X1_8->Z(PCout[15]);

    BUF_X1_9 = new BUF_X1("BUF_X1_9");
        BUF_X1_9->A(S8);
        BUF_X1_9->Z(PCout[2]);

    BUF_X1_10 = new BUF_X1("BUF_X1_10");
        BUF_X1_10->A(S9);
        BUF_X1_10->Z(PCout[3]);

    BUF_X1_11 = new BUF_X1("BUF_X1_11");
        BUF_X1_11->A(S10);
        BUF_X1_11->Z(PCout[4]);

    BUF_X1_12 = new BUF_X1("BUF_X1_12");
        BUF_X1_12->A(S11);
        BUF_X1_12->Z(PCout[5]);

    BUF_X1_13 = new BUF_X1("BUF_X1_13");
        BUF_X1_13->A(S12);
        BUF_X1_13->Z(PCout[6]);

    BUF_X1_14 = new BUF_X1("BUF_X1_14");
        BUF_X1_14->A(S13);
        BUF_X1_14->Z(PCout[7]);

    BUF_X1_15 = new BUF_X1("BUF_X1_15");
        BUF_X1_15->A(S14);
        BUF_X1_15->Z(PCout[8]);

    BUF_X1_16 = new BUF_X1("BUF_X1_16");
        BUF_X1_16->A(S15);
        BUF_X1_16->Z(PCout[9]);

    BUF_X1_17 = new BUF_X1("BUF_X1_17");
        BUF_X1_17->A(S16);
        BUF_X1_17->Z(addrBus[0]);

    BUF_X1_18 = new BUF_X1("BUF_X1_18");
        BUF_X1_18->A(S23);
        BUF_X1_18->Z(addrBus[1]);

    BUF_X1_19 = new BUF_X1("BUF_X1_19");
        BUF_X1_19->A(S17);
        BUF_X1_19->Z(addrBus[10]);

    BUF_X1_20 = new BUF_X1("BUF_X1_20");
        BUF_X1_20->A(S18);
        BUF_X1_20->Z(addrBus[11]);

    BUF_X1_21 = new BUF_X1("BUF_X1_21");
        BUF_X1_21->A(S19);
        BUF_X1_21->Z(addrBus[12]);

    BUF_X1_22 = new BUF_X1("BUF_X1_22");
        BUF_X1_22->A(S20);
        BUF_X1_22->Z(addrBus[13]);

    BUF_X1_23 = new BUF_X1("BUF_X1_23");
        BUF_X1_23->A(S21);
        BUF_X1_23->Z(addrBus[14]);

    BUF_X1_24 = new BUF_X1("BUF_X1_24");
        BUF_X1_24->A(S22);
        BUF_X1_24->Z(addrBus[15]);

    BUF_X1_25 = new BUF_X1("BUF_X1_25");
        BUF_X1_25->A(S24);
        BUF_X1_25->Z(addrBus[2]);

    BUF_X1_26 = new BUF_X1("BUF_X1_26");
        BUF_X1_26->A(S25);
        BUF_X1_26->Z(addrBus[3]);

    BUF_X1_27 = new BUF_X1("BUF_X1_27");
        BUF_X1_27->A(S26);
        BUF_X1_27->Z(addrBus[4]);

    BUF_X1_28 = new BUF_X1("BUF_X1_28");
        BUF_X1_28->A(S27);
        BUF_X1_28->Z(addrBus[5]);

    BUF_X1_29 = new BUF_X1("BUF_X1_29");
        BUF_X1_29->A(S28);
        BUF_X1_29->Z(addrBus[6]);

    BUF_X1_30 = new BUF_X1("BUF_X1_30");
        BUF_X1_30->A(S29);
        BUF_X1_30->Z(addrBus[7]);

    BUF_X1_31 = new BUF_X1("BUF_X1_31");
        BUF_X1_31->A(S30);
        BUF_X1_31->Z(addrBus[8]);

    BUF_X1_32 = new BUF_X1("BUF_X1_32");
        BUF_X1_32->A(S31);
        BUF_X1_32->Z(addrBus[9]);

    BUF_X1_33 = new BUF_X1("BUF_X1_33");
        BUF_X1_33->A(clk);
        BUF_X1_33->Z(S32);

    BUF_X1_34 = new BUF_X1("BUF_X1_34");
        BUF_X1_34->A(dataBusIn[0]);
        BUF_X1_34->Z(S33);

    BUF_X1_35 = new BUF_X1("BUF_X1_35");
        BUF_X1_35->A(dataBusIn[1]);
        BUF_X1_35->Z(S40);

    BUF_X1_36 = new BUF_X1("BUF_X1_36");
        BUF_X1_36->A(dataBusIn[10]);
        BUF_X1_36->Z(S34);

    BUF_X1_37 = new BUF_X1("BUF_X1_37");
        BUF_X1_37->A(dataBusIn[11]);
        BUF_X1_37->Z(S35);

    BUF_X1_38 = new BUF_X1("BUF_X1_38");
        BUF_X1_38->A(dataBusIn[12]);
        BUF_X1_38->Z(S36);

    BUF_X1_39 = new BUF_X1("BUF_X1_39");
        BUF_X1_39->A(dataBusIn[13]);
        BUF_X1_39->Z(S37);

    BUF_X1_40 = new BUF_X1("BUF_X1_40");
        BUF_X1_40->A(dataBusIn[14]);
        BUF_X1_40->Z(S38);

    BUF_X1_41 = new BUF_X1("BUF_X1_41");
        BUF_X1_41->A(dataBusIn[15]);
        BUF_X1_41->Z(S39);

    BUF_X1_42 = new BUF_X1("BUF_X1_42");
        BUF_X1_42->A(dataBusIn[2]);
        BUF_X1_42->Z(S41);

    BUF_X1_43 = new BUF_X1("BUF_X1_43");
        BUF_X1_43->A(dataBusIn[3]);
        BUF_X1_43->Z(S42);

    BUF_X1_44 = new BUF_X1("BUF_X1_44");
        BUF_X1_44->A(dataBusIn[4]);
        BUF_X1_44->Z(S43);

    BUF_X1_45 = new BUF_X1("BUF_X1_45");
        BUF_X1_45->A(dataBusIn[5]);
        BUF_X1_45->Z(S44);

    BUF_X1_46 = new BUF_X1("BUF_X1_46");
        BUF_X1_46->A(dataBusIn[6]);
        BUF_X1_46->Z(S45);

    BUF_X1_47 = new BUF_X1("BUF_X1_47");
        BUF_X1_47->A(dataBusIn[7]);
        BUF_X1_47->Z(S46);

    BUF_X1_48 = new BUF_X1("BUF_X1_48");
        BUF_X1_48->A(dataBusIn[8]);
        BUF_X1_48->Z(S47);

    BUF_X1_49 = new BUF_X1("BUF_X1_49");
        BUF_X1_49->A(dataBusIn[9]);
        BUF_X1_49->Z(S48);

    BUF_X1_50 = new BUF_X1("BUF_X1_50");
        BUF_X1_50->A(S49);
        BUF_X1_50->Z(dataBusOut[0]);

    BUF_X1_51 = new BUF_X1("BUF_X1_51");
        BUF_X1_51->A(S56);
        BUF_X1_51->Z(dataBusOut[1]);

    BUF_X1_52 = new BUF_X1("BUF_X1_52");
        BUF_X1_52->A(S50);
        BUF_X1_52->Z(dataBusOut[10]);

    BUF_X1_53 = new BUF_X1("BUF_X1_53");
        BUF_X1_53->A(S51);
        BUF_X1_53->Z(dataBusOut[11]);

    BUF_X1_54 = new BUF_X1("BUF_X1_54");
        BUF_X1_54->A(S52);
        BUF_X1_54->Z(dataBusOut[12]);

    BUF_X1_55 = new BUF_X1("BUF_X1_55");
        BUF_X1_55->A(S53);
        BUF_X1_55->Z(dataBusOut[13]);

    BUF_X1_56 = new BUF_X1("BUF_X1_56");
        BUF_X1_56->A(S54);
        BUF_X1_56->Z(dataBusOut[14]);

    BUF_X1_57 = new BUF_X1("BUF_X1_57");
        BUF_X1_57->A(S55);
        BUF_X1_57->Z(dataBusOut[15]);

    BUF_X1_58 = new BUF_X1("BUF_X1_58");
        BUF_X1_58->A(S57);
        BUF_X1_58->Z(dataBusOut[2]);

    BUF_X1_59 = new BUF_X1("BUF_X1_59");
        BUF_X1_59->A(S58);
        BUF_X1_59->Z(dataBusOut[3]);

    BUF_X1_60 = new BUF_X1("BUF_X1_60");
        BUF_X1_60->A(S59);
        BUF_X1_60->Z(dataBusOut[4]);

    BUF_X1_61 = new BUF_X1("BUF_X1_61");
        BUF_X1_61->A(S60);
        BUF_X1_61->Z(dataBusOut[5]);

    BUF_X1_62 = new BUF_X1("BUF_X1_62");
        BUF_X1_62->A(S61);
        BUF_X1_62->Z(dataBusOut[6]);

    BUF_X1_63 = new BUF_X1("BUF_X1_63");
        BUF_X1_63->A(S62);
        BUF_X1_63->Z(dataBusOut[7]);

    BUF_X1_64 = new BUF_X1("BUF_X1_64");
        BUF_X1_64->A(S63);
        BUF_X1_64->Z(dataBusOut[8]);

    BUF_X1_65 = new BUF_X1("BUF_X1_65");
        BUF_X1_65->A(S64);
        BUF_X1_65->Z(dataBusOut[9]);

    BUF_X1_66 = new BUF_X1("BUF_X1_66");
        BUF_X1_66->A(S65);
        BUF_X1_66->Z(readIO);

    BUF_X1_67 = new BUF_X1("BUF_X1_67");
        BUF_X1_67->A(selpc_mem);
        BUF_X1_67->Z(readInst);

    BUF_X1_68 = new BUF_X1("BUF_X1_68");
        BUF_X1_68->A(S66);
        BUF_X1_68->Z(readMEM);

    BUF_X1_69 = new BUF_X1("BUF_X1_69");
        BUF_X1_69->A(readyMEM);
        BUF_X1_69->Z(S67);

    BUF_X1_70 = new BUF_X1("BUF_X1_70");
        BUF_X1_70->A(rst);
        BUF_X1_70->Z(S68);

    BUF_X1_71 = new BUF_X1("BUF_X1_71");
        BUF_X1_71->A(S69);
        BUF_X1_71->Z(writeIO);

    BUF_X1_72 = new BUF_X1("BUF_X1_72");
        BUF_X1_72->A(S70);
        BUF_X1_72->Z(writeMEM);

    controller = new ccu("controller");
        controller->arithadd(arithadd);
        controller->arithdiv(arithdiv);
        controller->arithmul(arithmul);
        controller->arithsh(arithsh);
        controller->arithsub(arithsub);
        controller->clk(S32);
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
        controller->readio(S65);
        controller->readmem(S66);
        controller->readymdu(readymdu);
        controller->readymem(S67);
        controller->rst(S68);
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
        controller->selpc_mem(selpc_mem);
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
        controller->writeio(S69);
        controller->writemem(S70);
        controller->writetrf(writetrf);

    datapath = new dpu("datapath");
        datapath->addrbus[0](S16);
        datapath->addrbus[1](S23);
        datapath->addrbus[2](S24);
        datapath->addrbus[3](S25);
        datapath->addrbus[4](S26);
        datapath->addrbus[5](S27);
        datapath->addrbus[6](S28);
        datapath->addrbus[7](S29);
        datapath->addrbus[8](S30);
        datapath->addrbus[9](S31);
        datapath->addrbus[10](S17);
        datapath->addrbus[11](S18);
        datapath->addrbus[12](S19);
        datapath->addrbus[13](S20);
        datapath->addrbus[14](S21);
        datapath->addrbus[15](S22);
        datapath->arithadd(arithadd);
        datapath->arithdiv(arithdiv);
        datapath->arithmul(arithmul);
        datapath->arithsh(arithsh);
        datapath->arithsub(arithsub);
        datapath->clk(S32);
        datapath->databusin[0](S33);
        datapath->databusin[1](S40);
        datapath->databusin[2](S41);
        datapath->databusin[3](S42);
        datapath->databusin[4](S43);
        datapath->databusin[5](S44);
        datapath->databusin[6](S45);
        datapath->databusin[7](S46);
        datapath->databusin[8](S47);
        datapath->databusin[9](S48);
        datapath->databusin[10](S34);
        datapath->databusin[11](S35);
        datapath->databusin[12](S36);
        datapath->databusin[13](S37);
        datapath->databusin[14](S38);
        datapath->databusin[15](S39);
        datapath->databusout[0](S49);
        datapath->databusout[1](S56);
        datapath->databusout[2](S57);
        datapath->databusout[3](S58);
        datapath->databusout[4](S59);
        datapath->databusout[5](S60);
        datapath->databusout[6](S61);
        datapath->databusout[7](S62);
        datapath->databusout[8](S63);
        datapath->databusout[9](S64);
        datapath->databusout[10](S50);
        datapath->databusout[11](S51);
        datapath->databusout[12](S52);
        datapath->databusout[13](S53);
        datapath->databusout[14](S54);
        datapath->databusout[15](S55);
        datapath->drivedatabus(drivedatabus);
        datapath->enflag(enflag);
        datapath->fib[0](fib_0_);
        datapath->fib[1](fib_1_);
        datapath->fib[2](fib_2_);
        datapath->fib[3](fib_3_);
        datapath->fib[4](fib_4_);
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
        datapath->p1lowbits(p1lowbits);
        datapath->pcout[0](S0);
        datapath->pcout[1](S7);
        datapath->pcout[2](S8);
        datapath->pcout[3](S9);
        datapath->pcout[4](S10);
        datapath->pcout[5](S11);
        datapath->pcout[6](S12);
        datapath->pcout[7](S13);
        datapath->pcout[8](S14);
        datapath->pcout[9](S15);
        datapath->pcout[10](S1);
        datapath->pcout[11](S2);
        datapath->pcout[12](S3);
        datapath->pcout[13](S4);
        datapath->pcout[14](S5);
        datapath->pcout[15](S6);
        datapath->readymdu(readymdu);
        datapath->rst(S68);
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
        datapath->selpc_mem(selpc_mem);
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
        datapath->writetrf(writetrf);


    SC_METHOD(sc_logic_signal_assignment);

    }

    void sc_logic_signal_assignment(void){ 
        sc_logic_1_signal.write(SC_LOGIC_1);
        sc_logic_0_signal.write(SC_LOGIC_0);
    }
};
#endif /* __SAYAC_TOP_H__ */

