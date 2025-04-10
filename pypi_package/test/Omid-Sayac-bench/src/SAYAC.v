module SAYAC(clk, rst, dataBusIn, dataBusOut, addrBus, readMEM, writeMEM, readyMEM); // , instruction, TRFindata, TRFrs1, TRFrs2, TRFrd, TRFP1, TRFP2, Immediate
  input clk, rst, readyMEM;
  input  [15:0]  dataBusIn;
  output [15:0]  dataBusOut;
  output readMEM, writeMEM;
  output [15:0]  addrBus; 
  //output [15:0] TRFP1, TRFP2, TRFindata;
  //output [3:0] TRFrs1, TRFrs2, TRFrd;
  //output [15:0] Immediate;
  wire [15:0] instruction;
  
  wire 	seldatabus_TRF, selPC1_TRF, selLLU_TRF, selSHU_TRF, selASU_TRF, 
				selMDU1_TRF, selMDU2_TRF, selIMM_TRF, selrs1_TRF, selrd_1_TRF, 
				selrd0_TRF, selrd1_TRF, writeTRF, selp1_PCP, selimm_PCP,
				selp1_PC, selPCadd_PC, selPC1_PC, selPC_MEM, selADR_MEM, SE5bits,
				SE6bits, USE8bits, SE8bits, p1lowbits, selp2_ASU, selimm_ASU,
				arithADD, arithSUB, logicAND, onesComp, twosComp, selp2_SHU,
				selshim_SHU, logicSH, arithSH, ldMDU1, ldMDU2, arithMUL, arithDIV,
				startMDU, readyMDU, doneMDU, lt, gt, eq, ldIR, ldADR, ldPC, readIO, writeIO,
				selrd_2_TRF, selrs2_TRF, enFlag;//, driveDataBus
  wire [7:0] outFlag;
 
  Datapath DP (clk, rst, selIMM_TRF, selMDU1_TRF, selMDU2_TRF, 
				selASU_TRF, selLLU_TRF, selSHU_TRF, seldatabus_TRF,
				selPC1_TRF, selrs1_TRF, selrd_1_TRF, 
				selrs2_TRF, selrd_2_TRF, selrd0_TRF, selrd1_TRF, 
				writeTRF, selp2_ASU, selimm_ASU, arithMUL, arithDIV,
				ldMDU1,	ldMDU2, startMDU, readyMDU, doneMDU, lt, gt, eq, logicAND, 
				onesComp, twosComp, SE5bits, SE6bits, USE8bits, SE8bits, 
				p1lowbits, selp1_PCP, selimm_PCP, selp2_SHU	, selshim_SHU, 
				selp1_PC, selPCadd_PC, selPC1_PC, selADR_MEM, selPC_MEM, 
				ldIR, ldADR, ldPC, logicSH, arithSH, addrBus
				, dataBusIn, dataBusOut, outFlag, enFlag, instruction,
				arithADD, arithSUB); // , driveDataBus, TRFindata, TRFrs1, TRFrs2, TRFrd, TRFP1, TRFP2, Immediate
                 
  Controller CU (clk, rst, instruction[15:8], outFlag, instruction[8:4], seldatabus_TRF, selPC1_TRF,
        			selLLU_TRF, selSHU_TRF, selASU_TRF, selMDU1_TRF, selMDU2_TRF, 
				selIMM_TRF, selrs1_TRF, selrd_1_TRF, selrd0_TRF, selrd1_TRF, writeTRF,
				selp1_PCP, selimm_PCP, selp1_PC, selPCadd_PC, selPC1_PC,
				selPC_MEM, selADR_MEM, SE5bits, SE6bits, USE8bits, SE8bits,
				p1lowbits, selp2_ASU, selimm_ASU, arithADD, arithSUB, logicAND,
				onesComp, twosComp, selp2_SHU, selshim_SHU, logicSH, arithSH,
				ldMDU1, ldMDU2, arithMUL, arithDIV, startMDU, ldIR, ldADR, ldPC,
				readMEM, writeMEM, readIO, writeIO, selrd_2_TRF, selrs2_TRF,
				readyMDU, doneMDU, readyMEM, enFlag);//, driveDataBus

endmodule
