/******************************************************************************/
//	Filename:		SAYAC_TDP.v
//	Project:		SAYAC : Simple Architecture Yet Ample Circuitry
//  Version:		0.940
//	History:
//	Date:			3 June 2021
//	Last Author: 	Helia
//  Copyright (C) 2021 University of Teheran
//  This source file may be used and distributed without
//  restriction provided that this copyright statement is not
//  removed from the file and that any derivative work contains
//  the original copyright notice and the associated disclaimer.
//

/******************************************************************************/
//	File content description:
//	Total DataPath (TDP) of the SAYAC core                               
/******************************************************************************/
`timescale 1ns/1ns
	
module Datapath (clk, rst, selIMM_TRF, selMDU1_TRF, selMDU2_TRF, 
				selASU_TRF, selLLU_TRF, selSHU_TRF, seldatabus_TRF,
				selPC1_TRF, selrs1_TRF, selrd_1_TRF, 
				selrs2_TRF, selrd_2_TRF, selrd0_TRF, selrd1_TRF, 
				writeTRF, selp2_ASU, selimm_ASU, arithMUL, arithDIV,
				ldMDU1,	ldMDU2, startMDU, readyMDU, doneMDU, lt, gt, eq, logicAND, 
				onesComp, twosComp, SE5bits, SE6bits, USE8bits, SE8bits, 
				p1lowbits, selp1_PCP, selimm_PCP, selp2_SHU	, selshim_SHU, 
				selp1_PC, selPCadd_PC, selPC1_PC, selADR_MEM, selPC_MEM, 
				ldIR, ldADR, ldPC, logicSH, arithSH, addrBus
				, dataBusIn, dataBusOut, outFlag, enFlag, instr,
				arithADD, arithSUB); // , driveDataBus, TRFindata, TRFrs1, TRFrs2, TRFrd, TRFP1, TRFP2, Immediate
                
	input         clk, rst;
	input  [15:0] dataBusIn;
	output [15:0] dataBusOut;
	output [15:0] addrBus;
	//output [15:0] TRFP1, TRFP2, TRFindata;
	//output [3:0] TRFrs1, TRFrs2, TRFrd;
	//output [15:0] Immediate;
	
	input         ldIR, ldADR, ldPC, SE5bits, SE6bits, USE8bits, SE8bits, 
				  p1lowbits, selp1_PCP, selimm_PCP, selp2_SHU, selshim_SHU,
				  selp1_PC, selPCadd_PC, selPC1_PC, selADR_MEM, selPC_MEM, 
				  logicSH, arithSH;//, driveDataBus;


	input         selIMM_TRF, selMDU1_TRF, selMDU2_TRF, selASU_TRF, selLLU_TRF,
				        selSHU_TRF, seldatabus_TRF, selPC1_TRF;
	input         arithMUL, arithDIV, ldMDU1, ldMDU2, startMDU, arithADD, arithSUB;
	output        readyMDU, doneMDU;
	output        lt, gt, eq;
	input         logicAND, onesComp, twosComp;
	
	input         selrs1_TRF, selrd_1_TRF, selrs2_TRF, selrd_2_TRF, selrd0_TRF, 
				  selrd1_TRF;
	input         selp2_ASU, selimm_ASU;
	input         writeTRF;
	input 		  enFlag;
	output [7:0]  outFlag;
	output [15:0] instr;
	
	wire   [7:0] inFlag;
	wire   [15:0] outIMM, outMDU1, outMDU2, outASU, outLLU, outSHU, outPC1, 
				  inDataTRF;
	wire   [7:0]  selMUX1;
 	wire   [15:0] outIR;
	wire   [15:0] outMuxPCP;
	wire   [4:0]  outMuxSHU;
	wire   [15:0] outPCP;
	wire   [15:0] outMuxPC;
	wire   [15:0] outADR;
	wire   [15:0] outPC;
	wire   [3:0]  rs1_TRF, rs2_TRF, rd_TRF; 
	wire   [3:0]  rd1_TRF;
	wire   [15:0] p1, p2;
	wire   [15:0] outMuxASU;
	wire   [3:0]  rs1, rs2, rd;
	wire cout0, cout1;
	
	assign rs1 = instr[7:4];
	assign rs2 = instr[11:8];
	assign rd  = instr[3:0];
	//assign TRFP1  = p1;
	//assign TRFP2  = p2;
	//assign Immediate=outIMM;
	//assign TRFindata=inDataTRF;
	//assign TRFrs1=rs1_TRF;
	//assign TRFrs2=rs2_TRF;
	//assign TRFrd=rd_TRF;
//mux 8 to 1(mux1) has outIMM from part IMM
  
	assign selMUX1 = {selIMM_TRF, selMDU1_TRF, selMDU2_TRF, selASU_TRF, selLLU_TRF, 
					  selSHU_TRF, seldatabus_TRF, selPC1_TRF};
	mux8to1 mux1(outIMM, outMDU1, outMDU2, outASU, outLLU, outSHU, dataBusIn, outPC1, 
				selMUX1, inDataTRF);

// mux2, mux3, mux4
  
	assign rd1_TRF = rd + 4'd1;
	mux2to1 #(4) mux2(rs1, rd, selrs1_TRF, selrd_1_TRF, rs1_TRF);
	mux2to1 #(4) mux3(rs2, rd, selrs2_TRF, selrd_2_TRF, rs2_TRF);
	mux2to1 #(4) mux4(rd, rd1_TRF, selrd0_TRF, selrd1_TRF, rd_TRF);
	mux2to1 #(16) mux5(p2, outIMM, selp2_ASU, selimm_ASU, outMuxASU);
	mux2to1 #(5)  MUX6 (p2[4:0], outIR[8:4], selp2_SHU, selshim_SHU, outMuxSHU);//outIR has been changed
//TRF  
			
	TRF TRFU(clk, rst, writeTRF, inDataTRF, rs1_TRF, rs2_TRF, rd_TRF, p1, 
			p2, enFlag, inFlag, outFlag);

//mux5
	
	

//MDU
	
	MDU mdu(clk, rst, arithMUL, arithDIV, ldMDU1, ldMDU2, p1, p2, 
			outMDU1, outMDU2, readyMDU, doneMDU, startMDU);
//CMP
	
	CMP cmp(p1, outMuxASU, lt, gt, eq);
//ASU

	ASU asu(p1, outMuxASU, arithADD, arithSUB, outASU);

//LLU 
	
	LLU llu(p1, outMuxASU, logicAND, onesComp, twosComp, outLLU);
//SHU
	SHU SHiftUnit (p1, outMuxSHU, logicSH, arithSH, outSHU);
	
	REG #(16) IR (dataBusIn, outIR, ldIR, clk, rst);

	REG #(16) ADR (outMuxPCP, outADR, ldADR, clk, rst);

	REG #(16) PC (outMuxPC, outPC, ldPC, clk, rst);
  
	IMM ImmediateUnit (outIR[11:4], p1[7:0], SE5bits, SE6bits, USE8bits, SE8bits, p1lowbits, outIMM); 

	mux2to1 #(16) MUX7 (p1, outIMM, selp1_PCP, selimm_PCP, outMuxPCP);

	mux3to1 #(16) MUX8 (p1, outPCP, outPC1, selp1_PC, selPCadd_PC, selPC1_PC, outMuxPC);
  
	mux2to1 #(16) MUX9 (outADR, outPC, selADR_MEM, selPC_MEM, addrBus);


	adder #(16) PCP (outMuxPCP, outPC, 1'b0, cout0, outPCP);

	adder #(16) PC1 (outPC, 16'd1,1'b0, cout1, outPC1);
	
	/*always @(*) begin
		if(driveDataBus) dataBus <= p1;
		else dataBus <= 16'bZ;
	end*/
	//assign dataBus = (driveDataBus)? p1 : 16'bZ;
	assign dataBusOut = p1;
	assign instr = outIR;
	assign inFlag = {1'b0, 1'b0, gt, eq, 1'b0, 1'b0, 1'b0, 1'b0};
  
endmodule



 

