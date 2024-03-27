module LGC(clk, rst, readyMEM, dataBusIn, p1TRF, p2TRF, readMM, writeMM, dataBusOut, addrBus, outMuxrs1, outMuxrs2, outMuxrd, inDataTRF, writeTRF, readInst);

wire S0;
wire S1;
wire S2;
wire S3;
wire S4;
wire S5;
wire S6;
wire S7;
wire S8;
wire S9;
wire S10;
wire S11;
wire S12;
wire S13;
wire S14;
wire S15;
wire S16;
wire S17;
wire S18;
wire S19;
wire arithadd;
wire arithdiv;
wire arithmul;
wire arithsh;
wire arithsub;
wire drivedatabus;
wire enflag;
wire fib_0;
wire fib_1;
wire fib_2;
wire fib_3;
wire fib_4;
wire ldadr;
wire ldir;
wire ldmdu1;
wire ldmdu2;
wire ldpc;
wire logicand;
wire logicsh;
wire onescomp;
wire opcode_0;
wire opcode_1;
wire opcode_2;
wire opcode_3;
wire opcode_4;
wire opcode_5;
wire opcode_6;
wire opcode_7;
wire outflag_0;
wire outflag_1;
wire outflag_2;
wire outflag_3;
wire outflag_4;
wire outflag_5;
wire outflag_6;
wire outflag_7;
wire p1lowbits;
wire readio;
wire readmem;
wire readymdu;
wire se5bits;
wire se6bits;
wire se8bits;
wire seladr_mem;
wire selasu_trf;
wire seldatabus_trf;
wire selflag_0;
wire selflag_1;
wire selflag_2;
wire selflag_3;
wire selflag_4;
wire selflag_5;
wire selflag_6;
wire selflag_7;
wire selimm_asu;
wire selimm_pcp;
wire selimm_trf;
wire selllu_trf;
wire selmdu1_trf;
wire selmdu2_trf;
wire selp1_pc;
wire selp1_pcp;
wire selp2_asu;
wire selp2_shu;
wire selpc1_pc;
wire selpc1_trf;
wire selpcadd_pc;
wire selrd0_trf;
wire selrd1_trf;
wire selrd_1_trf;
wire selrd_2_trf;
wire selrs1_trf;
wire selrs2_trf;
wire selshim_shu;
wire selshu_trf;
wire setflags;
wire startmdu;
wire twoscomp;
wire use8bits;
wire writeio;
wire writemem;
input clk;
input rst;
input readyMEM;
input [15:0] dataBusIn;input [15:0] p1TRF;input [15:0] p2TRF;output readMM;
output writeMM;
output [15:0] dataBusOut;output [15:0] addrBus;output [3:0] outMuxrs1;output [3:0] outMuxrs2;output [3:0] outMuxrd;output [15:0] inDataTRF;output writeTRF;
output readInst;

INV_X1 #() 
INV_X1_1_ (
  .A({ readio }),
  .ZN({ S2 })
);
INV_X1 #() 
INV_X1_2_ (
  .A({ readmem }),
  .ZN({ S3 })
);
NAND2_X1 #() 
NAND2_X1_1_ (
  .A1({ S2 }),
  .A2({ S3 }),
  .ZN({ S15 })
);
INV_X1 #() 
INV_X1_3_ (
  .A({ writeio }),
  .ZN({ S0 })
);
INV_X1 #() 
INV_X1_4_ (
  .A({ writemem }),
  .ZN({ S1 })
);
NAND2_X1 #() 
NAND2_X1_2_ (
  .A1({ S0 }),
  .A2({ S1 }),
  .ZN({ S18 })
);
BUF_X1 #() 
BUF_X1_1_ (
  .A({ S4[0] }),
  .Z({ addrBus[0] })
);
BUF_X1 #() 
BUF_X1_2_ (
  .A({ S4[1] }),
  .Z({ addrBus[1] })
);
BUF_X1 #() 
BUF_X1_3_ (
  .A({ S4[10] }),
  .Z({ addrBus[10] })
);
BUF_X1 #() 
BUF_X1_4_ (
  .A({ S4[11] }),
  .Z({ addrBus[11] })
);
BUF_X1 #() 
BUF_X1_5_ (
  .A({ S4[12] }),
  .Z({ addrBus[12] })
);
BUF_X1 #() 
BUF_X1_6_ (
  .A({ S4[13] }),
  .Z({ addrBus[13] })
);
BUF_X1 #() 
BUF_X1_7_ (
  .A({ S4[14] }),
  .Z({ addrBus[14] })
);
BUF_X1 #() 
BUF_X1_8_ (
  .A({ S4[15] }),
  .Z({ addrBus[15] })
);
BUF_X1 #() 
BUF_X1_9_ (
  .A({ S4[2] }),
  .Z({ addrBus[2] })
);
BUF_X1 #() 
BUF_X1_10_ (
  .A({ S4[3] }),
  .Z({ addrBus[3] })
);
BUF_X1 #() 
BUF_X1_11_ (
  .A({ S4[4] }),
  .Z({ addrBus[4] })
);
BUF_X1 #() 
BUF_X1_12_ (
  .A({ S4[5] }),
  .Z({ addrBus[5] })
);
BUF_X1 #() 
BUF_X1_13_ (
  .A({ S4[6] }),
  .Z({ addrBus[6] })
);
BUF_X1 #() 
BUF_X1_14_ (
  .A({ S4[7] }),
  .Z({ addrBus[7] })
);
BUF_X1 #() 
BUF_X1_15_ (
  .A({ S4[8] }),
  .Z({ addrBus[8] })
);
BUF_X1 #() 
BUF_X1_16_ (
  .A({ S4[9] }),
  .Z({ addrBus[9] })
);
BUF_X1 #() 
BUF_X1_17_ (
  .A({ clk }),
  .Z({ S5 })
);
BUF_X1 #() 
BUF_X1_18_ (
  .A({ dataBusIn[0] }),
  .Z({ S6[0] })
);
BUF_X1 #() 
BUF_X1_19_ (
  .A({ dataBusIn[1] }),
  .Z({ S6[1] })
);
BUF_X1 #() 
BUF_X1_20_ (
  .A({ dataBusIn[10] }),
  .Z({ S6[10] })
);
BUF_X1 #() 
BUF_X1_21_ (
  .A({ dataBusIn[11] }),
  .Z({ S6[11] })
);
BUF_X1 #() 
BUF_X1_22_ (
  .A({ dataBusIn[12] }),
  .Z({ S6[12] })
);
BUF_X1 #() 
BUF_X1_23_ (
  .A({ dataBusIn[13] }),
  .Z({ S6[13] })
);
BUF_X1 #() 
BUF_X1_24_ (
  .A({ dataBusIn[14] }),
  .Z({ S6[14] })
);
BUF_X1 #() 
BUF_X1_25_ (
  .A({ dataBusIn[15] }),
  .Z({ S6[15] })
);
BUF_X1 #() 
BUF_X1_26_ (
  .A({ dataBusIn[2] }),
  .Z({ S6[2] })
);
BUF_X1 #() 
BUF_X1_27_ (
  .A({ dataBusIn[3] }),
  .Z({ S6[3] })
);
BUF_X1 #() 
BUF_X1_28_ (
  .A({ dataBusIn[4] }),
  .Z({ S6[4] })
);
BUF_X1 #() 
BUF_X1_29_ (
  .A({ dataBusIn[5] }),
  .Z({ S6[5] })
);
BUF_X1 #() 
BUF_X1_30_ (
  .A({ dataBusIn[6] }),
  .Z({ S6[6] })
);
BUF_X1 #() 
BUF_X1_31_ (
  .A({ dataBusIn[7] }),
  .Z({ S6[7] })
);
BUF_X1 #() 
BUF_X1_32_ (
  .A({ dataBusIn[8] }),
  .Z({ S6[8] })
);
BUF_X1 #() 
BUF_X1_33_ (
  .A({ dataBusIn[9] }),
  .Z({ S6[9] })
);
BUF_X1 #() 
BUF_X1_34_ (
  .A({ S7[0] }),
  .Z({ dataBusOut[0] })
);
BUF_X1 #() 
BUF_X1_35_ (
  .A({ S7[1] }),
  .Z({ dataBusOut[1] })
);
BUF_X1 #() 
BUF_X1_36_ (
  .A({ S7[2] }),
  .Z({ dataBusOut[2] })
);
BUF_X1 #() 
BUF_X1_37_ (
  .A({ S7[3] }),
  .Z({ dataBusOut[3] })
);
BUF_X1 #() 
BUF_X1_38_ (
  .A({ S7[4] }),
  .Z({ dataBusOut[4] })
);
BUF_X1 #() 
BUF_X1_39_ (
  .A({ S7[5] }),
  .Z({ dataBusOut[5] })
);
BUF_X1 #() 
BUF_X1_40_ (
  .A({ S7[6] }),
  .Z({ dataBusOut[6] })
);
BUF_X1 #() 
BUF_X1_41_ (
  .A({ S7[7] }),
  .Z({ dataBusOut[7] })
);
BUF_X1 #() 
BUF_X1_42_ (
  .A({ S8[0] }),
  .Z({ inDataTRF[0] })
);
BUF_X1 #() 
BUF_X1_43_ (
  .A({ S8[1] }),
  .Z({ inDataTRF[1] })
);
BUF_X1 #() 
BUF_X1_44_ (
  .A({ S8[10] }),
  .Z({ inDataTRF[10] })
);
BUF_X1 #() 
BUF_X1_45_ (
  .A({ S8[11] }),
  .Z({ inDataTRF[11] })
);
BUF_X1 #() 
BUF_X1_46_ (
  .A({ S8[12] }),
  .Z({ inDataTRF[12] })
);
BUF_X1 #() 
BUF_X1_47_ (
  .A({ S8[13] }),
  .Z({ inDataTRF[13] })
);
BUF_X1 #() 
BUF_X1_48_ (
  .A({ S8[14] }),
  .Z({ inDataTRF[14] })
);
BUF_X1 #() 
BUF_X1_49_ (
  .A({ S8[15] }),
  .Z({ inDataTRF[15] })
);
BUF_X1 #() 
BUF_X1_50_ (
  .A({ S8[2] }),
  .Z({ inDataTRF[2] })
);
BUF_X1 #() 
BUF_X1_51_ (
  .A({ S8[3] }),
  .Z({ inDataTRF[3] })
);
BUF_X1 #() 
BUF_X1_52_ (
  .A({ S8[4] }),
  .Z({ inDataTRF[4] })
);
BUF_X1 #() 
BUF_X1_53_ (
  .A({ S8[5] }),
  .Z({ inDataTRF[5] })
);
BUF_X1 #() 
BUF_X1_54_ (
  .A({ S8[6] }),
  .Z({ inDataTRF[6] })
);
BUF_X1 #() 
BUF_X1_55_ (
  .A({ S8[7] }),
  .Z({ inDataTRF[7] })
);
BUF_X1 #() 
BUF_X1_56_ (
  .A({ S8[8] }),
  .Z({ inDataTRF[8] })
);
BUF_X1 #() 
BUF_X1_57_ (
  .A({ S8[9] }),
  .Z({ inDataTRF[9] })
);
BUF_X1 #() 
BUF_X1_58_ (
  .A({ S9[0] }),
  .Z({ outMuxrd[0] })
);
BUF_X1 #() 
BUF_X1_59_ (
  .A({ S9[1] }),
  .Z({ outMuxrd[1] })
);
BUF_X1 #() 
BUF_X1_60_ (
  .A({ S9[2] }),
  .Z({ outMuxrd[2] })
);
BUF_X1 #() 
BUF_X1_61_ (
  .A({ S9[3] }),
  .Z({ outMuxrd[3] })
);
BUF_X1 #() 
BUF_X1_62_ (
  .A({ S10[0] }),
  .Z({ outMuxrs1[0] })
);
BUF_X1 #() 
BUF_X1_63_ (
  .A({ S10[1] }),
  .Z({ outMuxrs1[1] })
);
BUF_X1 #() 
BUF_X1_64_ (
  .A({ S10[2] }),
  .Z({ outMuxrs1[2] })
);
BUF_X1 #() 
BUF_X1_65_ (
  .A({ S10[3] }),
  .Z({ outMuxrs1[3] })
);
BUF_X1 #() 
BUF_X1_66_ (
  .A({ S11[0] }),
  .Z({ outMuxrs2[0] })
);
BUF_X1 #() 
BUF_X1_67_ (
  .A({ S11[1] }),
  .Z({ outMuxrs2[1] })
);
BUF_X1 #() 
BUF_X1_68_ (
  .A({ S11[2] }),
  .Z({ outMuxrs2[2] })
);
BUF_X1 #() 
BUF_X1_69_ (
  .A({ S11[3] }),
  .Z({ outMuxrs2[3] })
);
BUF_X1 #() 
BUF_X1_70_ (
  .A({ p1TRF[0] }),
  .Z({ S12[0] })
);
BUF_X1 #() 
BUF_X1_71_ (
  .A({ p1TRF[1] }),
  .Z({ S12[1] })
);
BUF_X1 #() 
BUF_X1_72_ (
  .A({ p1TRF[10] }),
  .Z({ S12[10] })
);
BUF_X1 #() 
BUF_X1_73_ (
  .A({ p1TRF[11] }),
  .Z({ S12[11] })
);
BUF_X1 #() 
BUF_X1_74_ (
  .A({ p1TRF[12] }),
  .Z({ S12[12] })
);
BUF_X1 #() 
BUF_X1_75_ (
  .A({ p1TRF[13] }),
  .Z({ S12[13] })
);
BUF_X1 #() 
BUF_X1_76_ (
  .A({ p1TRF[14] }),
  .Z({ S12[14] })
);
BUF_X1 #() 
BUF_X1_77_ (
  .A({ p1TRF[15] }),
  .Z({ S12[15] })
);
BUF_X1 #() 
BUF_X1_78_ (
  .A({ p1TRF[2] }),
  .Z({ S12[2] })
);
BUF_X1 #() 
BUF_X1_79_ (
  .A({ p1TRF[3] }),
  .Z({ S12[3] })
);
BUF_X1 #() 
BUF_X1_80_ (
  .A({ p1TRF[4] }),
  .Z({ S12[4] })
);
BUF_X1 #() 
BUF_X1_81_ (
  .A({ p1TRF[5] }),
  .Z({ S12[5] })
);
BUF_X1 #() 
BUF_X1_82_ (
  .A({ p1TRF[6] }),
  .Z({ S12[6] })
);
BUF_X1 #() 
BUF_X1_83_ (
  .A({ p1TRF[7] }),
  .Z({ S12[7] })
);
BUF_X1 #() 
BUF_X1_84_ (
  .A({ p1TRF[8] }),
  .Z({ S12[8] })
);
BUF_X1 #() 
BUF_X1_85_ (
  .A({ p1TRF[9] }),
  .Z({ S12[9] })
);
BUF_X1 #() 
BUF_X1_86_ (
  .A({ p2TRF[0] }),
  .Z({ S13[0] })
);
BUF_X1 #() 
BUF_X1_87_ (
  .A({ p2TRF[1] }),
  .Z({ S13[1] })
);
BUF_X1 #() 
BUF_X1_88_ (
  .A({ p2TRF[10] }),
  .Z({ S13[10] })
);
BUF_X1 #() 
BUF_X1_89_ (
  .A({ p2TRF[11] }),
  .Z({ S13[11] })
);
BUF_X1 #() 
BUF_X1_90_ (
  .A({ p2TRF[12] }),
  .Z({ S13[12] })
);
BUF_X1 #() 
BUF_X1_91_ (
  .A({ p2TRF[13] }),
  .Z({ S13[13] })
);
BUF_X1 #() 
BUF_X1_92_ (
  .A({ p2TRF[14] }),
  .Z({ S13[14] })
);
BUF_X1 #() 
BUF_X1_93_ (
  .A({ p2TRF[15] }),
  .Z({ S13[15] })
);
BUF_X1 #() 
BUF_X1_94_ (
  .A({ p2TRF[2] }),
  .Z({ S13[2] })
);
BUF_X1 #() 
BUF_X1_95_ (
  .A({ p2TRF[3] }),
  .Z({ S13[3] })
);
BUF_X1 #() 
BUF_X1_96_ (
  .A({ p2TRF[4] }),
  .Z({ S13[4] })
);
BUF_X1 #() 
BUF_X1_97_ (
  .A({ p2TRF[5] }),
  .Z({ S13[5] })
);
BUF_X1 #() 
BUF_X1_98_ (
  .A({ p2TRF[6] }),
  .Z({ S13[6] })
);
BUF_X1 #() 
BUF_X1_99_ (
  .A({ p2TRF[7] }),
  .Z({ S13[7] })
);
BUF_X1 #() 
BUF_X1_100_ (
  .A({ p2TRF[8] }),
  .Z({ S13[8] })
);
BUF_X1 #() 
BUF_X1_101_ (
  .A({ p2TRF[9] }),
  .Z({ S13[9] })
);
BUF_X1 #() 
BUF_X1_102_ (
  .A({ S14 }),
  .Z({ readInst })
);
BUF_X1 #() 
BUF_X1_103_ (
  .A({ S15 }),
  .Z({ readMM })
);
BUF_X1 #() 
BUF_X1_104_ (
  .A({ readyMEM }),
  .Z({ S16 })
);
BUF_X1 #() 
BUF_X1_105_ (
  .A({ rst }),
  .Z({ S17 })
);
BUF_X1 #() 
BUF_X1_106_ (
  .A({ S18 }),
  .Z({ writeMM })
);
BUF_X1 #() 
BUF_X1_107_ (
  .A({ S19 }),
  .Z({ writeTRF })
);
ccu #() 
ccu_1_ (
  .arithadd({ arithadd }),
  .arithdiv({ arithdiv }),
  .arithmul({ arithmul }),
  .arithsh({ arithsh }),
  .arithsub({ arithsub }),
  .clk({ S5 }),
  .drivedatabus({ drivedatabus }),
  .enflag({ enflag }),
  .fib({ fib_0, fib_1, fib_2, fib_3, fib_4 }),
  .ldadr({ ldadr }),
  .ldir({ ldir }),
  .ldmdu1({ ldmdu1 }),
  .ldmdu2({ ldmdu2 }),
  .ldpc({ ldpc }),
  .logicand({ logicand }),
  .logicsh({ logicsh }),
  .onescomp({ onescomp }),
  .opcode({ opcode_0, opcode_1, opcode_2, opcode_3, opcode_4, opcode_5, opcode_6, opcode_7 }),
  .outflag({ outflag_0, outflag_1, outflag_2, outflag_3, outflag_4, outflag_5, outflag_6, outflag_7 }),
  .p1lowbits({ p1lowbits }),
  .readio({ readio }),
  .readmem({ readmem }),
  .readymdu({ readymdu }),
  .readymem({ S16 }),
  .rst({ S17 }),
  .se5bits({ se5bits }),
  .se6bits({ se6bits }),
  .se8bits({ se8bits }),
  .seladr_mem({ seladr_mem }),
  .selasu_trf({ selasu_trf }),
  .seldatabus_trf({ seldatabus_trf }),
  .selflag({ selflag_0, selflag_1, selflag_2, selflag_3, selflag_4, selflag_5, selflag_6, selflag_7 }),
  .selimm_asu({ selimm_asu }),
  .selimm_pcp({ selimm_pcp }),
  .selimm_trf({ selimm_trf }),
  .selllu_trf({ selllu_trf }),
  .selmdu1_trf({ selmdu1_trf }),
  .selmdu2_trf({ selmdu2_trf }),
  .selp1_pc({ selp1_pc }),
  .selp1_pcp({ selp1_pcp }),
  .selp2_asu({ selp2_asu }),
  .selp2_shu({ selp2_shu }),
  .selpc1_pc({ selpc1_pc }),
  .selpc1_trf({ selpc1_trf }),
  .selpc_mem({ S14 }),
  .selpcadd_pc({ selpcadd_pc }),
  .selrd0_trf({ selrd0_trf }),
  .selrd1_trf({ selrd1_trf }),
  .selrd_1_trf({ selrd_1_trf }),
  .selrd_2_trf({ selrd_2_trf }),
  .selrs1_trf({ selrs1_trf }),
  .selrs2_trf({ selrs2_trf }),
  .selshim_shu({ selshim_shu }),
  .selshu_trf({ selshu_trf }),
  .setflags({ setflags }),
  .startmdu({ startmdu }),
  .twoscomp({ twoscomp }),
  .use8bits({ use8bits }),
  .writeio({ writeio }),
  .writemem({ writemem }),
  .writetrf({ S19 })
);
dpu #() 
dpu_1_ (
  .addrbus({ S4[0], S4[1], S4[2], S4[3], S4[4], S4[5], S4[6], S4[7], S4[8], S4[9], S4[10], S4[11], S4[12], S4[13], S4[14], S4[15] }),
  .arithadd({ arithadd }),
  .arithdiv({ arithdiv }),
  .arithmul({ arithmul }),
  .arithsh({ arithsh }),
  .arithsub({ arithsub }),
  .clk({ S5 }),
  .databusin({ S6[0], S6[1], S6[2], S6[3], S6[4], S6[5], S6[6], S6[7], S6[8], S6[9], S6[10], S6[11], S6[12], S6[13], S6[14], S6[15] }),
  .databusout({ S7[0], S7[1], S7[2], S7[3], S7[4], S7[5], S7[6], S7[7], S7[8], S7[9], S7[10], S7[11], S7[12], S7[13], S7[14], S7[15] }),
  .drivedatabus({ drivedatabus }),
  .enflag({ enflag }),
  .fib({ fib_0, fib_1, fib_2, fib_3, fib_4 }),
  .indatatrf({ S8[0], S8[1], S8[2], S8[3], S8[4], S8[5], S8[6], S8[7], S8[8], S8[9], S8[10], S8[11], S8[12], S8[13], S8[14], S8[15] }),
  .ldadr({ ldadr }),
  .ldir({ ldir }),
  .ldmdu1({ ldmdu1 }),
  .ldmdu2({ ldmdu2 }),
  .ldpc({ ldpc }),
  .logicand({ logicand }),
  .logicsh({ logicsh }),
  .onescomp({ onescomp }),
  .opcode({ opcode_0, opcode_1, opcode_2, opcode_3, opcode_4, opcode_5, opcode_6, opcode_7 }),
  .outflag({ outflag_0, outflag_1, outflag_2, outflag_3, outflag_4, outflag_5, outflag_6, outflag_7 }),
  .outmuxrd({ S9[0], S9[1], S9[2], S9[3] }),
  .outmuxrs1({ S10[0], S10[1], S10[2], S10[3] }),
  .outmuxrs2({ S11[0], S11[1], S11[2], S11[3] }),
  .p1lowbits({ p1lowbits }),
  .p1trf({ S12[0], S12[1], S12[2], S12[3], S12[4], S12[5], S12[6], S12[7], S12[8], S12[9], S12[10], S12[11], S12[12], S12[13], S12[14], S12[15] }),
  .p2trf({ S13[0], S13[1], S13[2], S13[3], S13[4], S13[5], S13[6], S13[7], S13[8], S13[9], S13[10], S13[11], S13[12], S13[13], S13[14], S13[15] }),
  .readymdu({ readymdu }),
  .rst({ S17 }),
  .se5bits({ se5bits }),
  .se6bits({ se6bits }),
  .se8bits({ se8bits }),
  .seladr_mem({ seladr_mem }),
  .selasu_trf({ selasu_trf }),
  .seldatabus_trf({ seldatabus_trf }),
  .selflag({ selflag_0, selflag_1, selflag_2, selflag_3, selflag_4, selflag_5, selflag_6, selflag_7 }),
  .selimm_asu({ selimm_asu }),
  .selimm_pcp({ selimm_pcp }),
  .selimm_trf({ selimm_trf }),
  .selllu_trf({ selllu_trf }),
  .selmdu1_trf({ selmdu1_trf }),
  .selmdu2_trf({ selmdu2_trf }),
  .selp1_pc({ selp1_pc }),
  .selp1_pcp({ selp1_pcp }),
  .selp2_asu({ selp2_asu }),
  .selp2_shu({ selp2_shu }),
  .selpc1_pc({ selpc1_pc }),
  .selpc1_trf({ selpc1_trf }),
  .selpc_mem({ S14 }),
  .selpcadd_pc({ selpcadd_pc }),
  .selrd0_trf({ selrd0_trf }),
  .selrd1_trf({ selrd1_trf }),
  .selrd_1_trf({ selrd_1_trf }),
  .selrd_2_trf({ selrd_2_trf }),
  .selrs1_trf({ selrs1_trf }),
  .selrs2_trf({ selrs2_trf }),
  .selshim_shu({ selshim_shu }),
  .selshu_trf({ selshu_trf }),
  .setflags({ setflags }),
  .startmdu({ startmdu }),
  .twoscomp({ twoscomp }),
  .use8bits({ use8bits })
);

endmodule