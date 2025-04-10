/*******************************************************************************/
//	Filename:		SAYAC_controller.v
//	Project:		SAYAC : Simple Architecture Yet Ample Circuitry
//  Version:		0.990
//	History:
//	Date:			3 June 2021
//	Last Author: 	MOHAMMAD
//  Copyright (C) 2021 University of Teheran
//  This source file may be used and distributed without
//  restriction provided that this copyright statement is not
//  removed from the file and that any derivative work contains
//  the original copyright notice and the associated disclaimer.
//

//******************************************************************************/
//	File content description:
//	Controller (CTRL) of the SAYAC core                                 
/*******************************************************************************/

module Controller (clk, rst, opcode, outFlag, FIB, seldatabus_TRF, selPC1_TRF,
             		selLLU_TRF, selSHU_TRF, selASU_TRF, selMDU1_TRF, selMDU2_TRF, 
			selIMM_TRF, selrs1_TRF, selrd_1_TRF, selrd0_TRF, selrd1_TRF, writeTRF,
			selp1_PCP, selimm_PCP, selp1_PC, selPCadd_PC, selPC1_PC,
			selPC_MEM, selADR_MEM, SE5bits, SE6bits, USE8bits, SE8bits,
			p1lowbits, selp2_ASU, selimm_ASU, arithADD, arithSUB, logicAND,
			onesComp, twosComp, selp2_SHU, selshim_SHU, logicSH, arithSH,
			ldMDU1, ldMDU2, arithMUL, arithDIV, startMDU, ldIR, ldADR, ldPC,
			readMEM, writeMEM, readIO, writeIO, selrd_2_TRF, selrs2_TRF,
			readyMDU, doneMDU, readyMEM, enFlag);//, driveDataBus

	input 		clk, rst, readyMDU, readyMEM, doneMDU;
	input [7:0] 	opcode;
	input [7:0]		outFlag;
	input [4:0] 	FIB;
	output reg 	seldatabus_TRF, selPC1_TRF, selLLU_TRF, selSHU_TRF, selASU_TRF, 
			selMDU1_TRF, selMDU2_TRF, selIMM_TRF, selrs1_TRF, selrd_1_TRF, 
			selrd0_TRF, selrd1_TRF, writeTRF, selp1_PCP, selimm_PCP,
			selp1_PC, selPCadd_PC, selPC1_PC, selPC_MEM, selADR_MEM, SE5bits,
			SE6bits, USE8bits, SE8bits, p1lowbits, selp2_ASU, selimm_ASU,
			arithADD, arithSUB, logicAND, onesComp, twosComp, selp2_SHU,
			selshim_SHU, logicSH, arithSH, ldMDU1, ldMDU2, arithMUL, arithDIV,
			startMDU, ldIR, ldADR, ldPC, readMEM, writeMEM, readIO, writeIO,
			selrd_2_TRF, selrs2_TRF, enFlag;//, driveDataBus

	reg  [1:0] pstate;
	reg  [1:0] nstate;

	/*
	parameter  [3:0] RSV1		= 4'b0000;
	parameter  [3:0] RSV2		= 4'b0001;
	parameter  [3:0] INST2		= 4'b0010;
	parameter  [1:0] LDR		= 2'b00;
	parameter  [1:0] STR		= 2'b01;
	parameter  [1:0] JMR		= 2'b10;
	parameter  [1:0] JMI		= 2'b11;
	parameter  [3:0] ANR		= 4'b0011;
	parameter  [3:0] ANI		= 4'b0100;
	parameter  [3:0] MSI		= 4'b0101;
	parameter  [3:0] MHI		= 4'b0110;
	parameter  [3:0] SLR		= 4'b0111;
	parameter  [3:0] SAR		= 4'b1000;
	parameter  [3:0] ADR		= 4'b1001;
	parameter  [3:0] SUR		= 4'b1010;
	parameter  [3:0] ADI		= 4'b1011;
	parameter  [3:0] SUI		= 4'b1100;
	parameter  [3:0] MUL		= 4'b1101;
	parameter  [3:0] DIV		= 4'b1110;
	parameter  [3:0] INST15 	= 4'b1111;
	parameter  [2:0] CMR		= 3'b000;
	parameter  [2:0] CMI		= 3'b001;
	parameter  [2:0] BRC		= 3'b010;
	parameter  [2:0] BRR		= 3'b011;
	parameter  [5:0] SHI		= 6'b111110;
	parameter  [2:0] NTR		= 3'b110;
	parameter  [2:0] NTD		= 3'b111;
	parameter  [1:0] fetch		= 2'b00;
	parameter  [1:0] exec1		= 2'b01;
	parameter  [1:0] exec2		= 2'b10;
	parameter  [1:0] exec3		= 2'b11;
	*/
	always @(posedge clk, posedge rst)
		if (rst) 
			pstate <= 2'b00;
		else 
			pstate <= nstate;
			
	always @(*)
	begin
		seldatabus_TRF	= 0;		selPC1_TRF	= 0;		selLLU_TRF		= 0; 
		selSHU_TRF     	= 0;		selASU_TRF	= 0;		selMDU1_TRF		= 0; 
		selMDU2_TRF		= 0;		selIMM_TRF	= 0;		selrs1_TRF		= 0;	    
		selrd_1_TRF		= 0;		selrd0_TRF	= 0;		selrd1_TRF		= 0;	    
		writeTRF		= 0;		selp1_PCP	= 0;		selimm_PCP		= 0;	
		selp1_PC		= 0;		selPCadd_PC	= 0;		selPC1_PC		= 0;       
		selPC_MEM		= 0;		selADR_MEM	= 0;		SE5bits			= 0;			
		SE6bits			= 0;		USE8bits	= 0;		SE8bits			= 0;			
		p1lowbits		= 0;		selp2_ASU	= 0;		selimm_ASU		= 0;		
		arithADD		= 0;		arithSUB	= 0;		logicAND		= 0;		
		onesComp		= 0;		twosComp	= 0;		selp2_SHU		= 0;		
		selshim_SHU		= 0;		logicSH		= 0;		arithSH			= 0;
		ldMDU1			= 0;		ldMDU2		= 0;		arithMUL		= 0;
		arithDIV		= 0;		startMDU	= 0;		ldIR			= 0;
		ldADR			= 0;		ldPC		= 0;		readMEM			= 0;
		writeMEM		= 0;		readIO		= 0;		writeIO			= 0;		
		selrd_2_TRF		= 0;		selrs2_TRF	= 0;		enFlag  = 0;
		case (pstate)
			2'b00 :
			begin
				selPC_MEM = 1;	ldIR = 1;  readMEM	= 1;
			end	
			2'b01 :
			begin 
				case (opcode[7:4]) 
					4'b0000 : 
					begin
						ldPC = 1;		selPC1_PC = 1;  
					end			
					4'b0001 :
					begin
						ldPC = 1;		selPC1_PC = 1; 
					end
					4'b0010 :
					begin
						case (opcode[3:2])
							2'b00 :
							begin
								selrs1_TRF	= 1;		selrd0_TRF = 1;		selp1_PCP = 1;
								ldADR		= 1;		
							end
							2'b01 :
							begin
								selrd_1_TRF = 1;		selp1_PCP = 1;		ldADR = 1;		
							end	
							2'b10 : 
							begin
								selrs1_TRF	= 1;		selp1_PCP = 1;		selPCadd_PC = 1;	
								ldPC		= 1;			
								if (opcode[1] == 1)
								begin
									selrd0_TRF		= 1;		selPC1_TRF = 1;		
									writeTRF	= 1;
								end
							end		
							2'b11 :
							begin
								SE6bits			= 1;		selimm_PCP	= 1;		selPCadd_PC	= 1;
								ldPC			= 1;		selrd0_TRF	= 1;		selPC1_TRF	= 1;	
								writeTRF 	= 1;					
							end													
						endcase
					end
					4'b0011 :
					begin
						selrs1_TRF		= 1;		selrs2_TRF	= 1;		selp2_ASU	= 1;	
						logicAND		= 1;		selrd0_TRF	= 1;		selLLU_TRF	= 1;	
						writeTRF		= 1;		selPC1_PC	= 1;		ldPC		= 1;			
					end
					4'b0100 :
					begin
						selrd_1_TRF		= 1;		USE8bits   = 1;		selimm_ASU	= 1;	
						logicAND		= 1;		selrd0_TRF = 1;		selLLU_TRF	= 1;	
						writeTRF		= 1;		selPC1_PC  = 1;		ldPC		= 1;
					end																							
					4'b0101 :
					begin
						SE8bits			= 1;		selrd0_TRF	= 1;		selIMM_TRF	= 1;
						writeTRF		= 1;		selPC1_PC	= 1;		ldPC		= 1;
					end	
					4'b0110 :
					begin
						selrd_1_TRF	= 1;		p1lowbits		= 1;		selrd0_TRF	= 1;
						selIMM_TRF	= 1;		writeTRF		= 1;		selPC1_PC	= 1;
						ldPC		= 1;		
					end	
					4'b0111 :
					begin
						selrs1_TRF		= 1;		selrs2_TRF	= 1;		selp2_SHU	= 1;
						logicSH			= 1;		selrd0_TRF	= 1;		selSHU_TRF	= 1;	
						writeTRF		= 1;		selPC1_PC	= 1;		ldPC		= 1;			
					end	
					4'b1000 :
					begin
						selrs1_TRF		= 1;		selrs2_TRF	= 1;		selp2_SHU	= 1;
						arithSH			= 1;		selrd0_TRF	= 1;		selSHU_TRF	= 1;	
						writeTRF		= 1;		selPC1_PC	= 1;		ldPC		= 1;			
					end	
					4'b1001 :
					begin
						selrs1_TRF		= 1;		selrs2_TRF	= 1;		selp2_ASU	= 1;
						arithADD		= 1;		selrd0_TRF	= 1;		selASU_TRF	= 1;	
						writeTRF		= 1;		selPC1_PC	= 1;		ldPC		= 1;			
					end	
					4'b1010 :
					begin
						selrs1_TRF		= 1;		selrs2_TRF	= 1;		selp2_ASU	= 1;
						arithSUB		= 1;  		selrd0_TRF	= 1;		selASU_TRF	= 1;	
						writeTRF		= 1;		selPC1_PC	= 1;		ldPC		= 1;			
					end	
					4'b1011 :
					begin
						selrd_1_TRF		= 1;		SE8bits		= 1;		selimm_ASU	= 1;
						arithADD		= 1;		selrd0_TRF	= 1;		selASU_TRF	= 1;	
						writeTRF		= 1;		selPC1_PC	= 1;		ldPC		= 1;			
					end	
					4'b1100 :
					begin
						selrd_1_TRF		= 1;		SE8bits		= 1;		 selimm_ASU	= 1;
						arithSUB		= 1;		selrd0_TRF	= 1;		 selASU_TRF	= 1;	
						writeTRF		= 1;		selPC1_PC	= 1;		 ldPC		= 1;			
					end	
					4'b1101 :
					begin
						selrs1_TRF		= 1;		selrs2_TRF	= 1;	arithMUL	= 1;	
						if (readyMDU == 1)
						begin
							startMDU = 1;	
						end
						
						if (doneMDU == 1)
						begin
							ldMDU2 = 1; 
						end
					end	
					4'b1110 :
					begin
						selrs1_TRF		= 1;		selrs2_TRF	= 1;		arithDIV	= 1;	
						if (readyMDU == 1)
						begin
							startMDU = 1;
						end
						if (doneMDU == 1)
						begin
							ldMDU1 = 1; 
						end
					end	
					4'b1111 :
					begin
						case (opcode[3:1])
							3'b000 :
							begin
								selrs1_TRF	= 1;		selrd_2_TRF	= 1;		selp2_ASU	= 1;		
								selPC1_PC	= 1;		ldPC		= 1;		enFlag		= 1;
							end		
							3'b001 :
							begin
								selrd_1_TRF	= 1;		SE5bits	= 1;		selimm_ASU = 1;	
								selPC1_PC	= 1;		ldPC 	= 1;		enFlag	   = 1;
							end		
							3'b010 :
							  case (FIB[2:0])
							3'b000 :
						      begin
						        ldPC  = 1;
						        if (outFlag[4] == 1)
						        begin
						          selrd_1_TRF = 1;		selp1_PC = 1;
						        end
						        else
						          selPC1_PC = 1;	
						      end
						      3'b001 :
						      begin
										ldPC = 1;
										if (outFlag[5] == 0)
										begin
											selrd_1_TRF = 1;		selp1_PC = 1;	
										end
										else
											selPC1_PC = 1;
									end
									3'b010 :
									begin
										ldPC = 1;
										if (outFlag[5] == 1)
										begin
											selrd_1_TRF = 1;		selp1_PC = 1;	
										end
										else
											selPC1_PC = 1;
									end
									3'b011 :
									begin
										ldPC = 1;
										if (outFlag[5] == 1 || outFlag[4] == 1)	
										begin
											selrd_1_TRF = 1;		selp1_PC = 1;
										end	
										else
											selPC1_PC = 1;
									end
									3'b100 : 
									begin
										ldPC = 1;
										if (outFlag[5] == 0 || outFlag[4] == 1)
										begin
										  selrd_1_TRF = 1;		selp1_PC = 1;
										end
										else
											selPC1_PC = 1;		
									end
									3'b101 :
									begin
										ldPC = 1;
										if (outFlag[4] == 0)
										begin
											selrd_1_TRF = 1;		selp1_PC = 1;	
										end
										else
											selPC1_PC = 1;
									end
							  endcase
							3'b011 :
							  case (FIB[2:0])
						      3'b000 :
						      begin
						        ldPC  = 1;
						        if (outFlag[4] == 1)
						        begin
						          selrd_1_TRF = 1;		selp1_PCP = 1;  selPCadd_PC = 1;
						        end
						        else
						          selPC1_PC = 1;	
						      end
						      3'b001 :
						      begin
										ldPC = 1;
										if (outFlag[5] == 0)
										begin
											selrd_1_TRF = 1;		selp1_PCP = 1;  selPCadd_PC = 1;	
										end
										else
											selPC1_PC = 1;
									end
									3'b010 :
									begin
										ldPC = 1;
										if (outFlag[5] == 1)
										begin
											selrd_1_TRF = 1;		selp1_PCP = 1;  selPCadd_PC = 1;	
										end
										else
											selPC1_PC = 1;
									end
									3'b011 :
									begin
										ldPC = 1;
										if (outFlag[5] == 1 || outFlag[4] == 1)	
										begin
											selrd_1_TRF = 1;		selp1_PCP = 1;  selPCadd_PC = 1;
										end	
										else
											selPC1_PC = 1;
									end
									3'b100 : 
									begin
										ldPC = 1;
										if (outFlag[5] == 0 || outFlag[4] == 1)
										begin
										  selrd_1_TRF = 1;		selp1_PCP = 1;  selPCadd_PC = 1;
										end
										else
											selPC1_PC = 1;		
									end
									3'b101 :
									begin
										ldPC = 1;
										if (outFlag[4] == 0)
										begin
											selrd_1_TRF = 1;		selp1_PCP = 1;  selPCadd_PC = 1;	
										end
										else
											selPC1_PC = 1;
									end
							  endcase
							3'b110 :
							begin
						    selrs1_TRF = 1;		selrd0_TRF = 1;		selLLU_TRF = 1;	
								writeTRF = 1;		selPC1_PC = 1;		ldPC = 1;
								if (opcode[0] == 0)
									onesComp = 1;
								else
									twosComp = 1;
							end
							3'b111 :
							begin
								selrd_1_TRF		= 1;		selrd0_TRF	= 1; 	selLLU_TRF	= 1;	
								writeTRF	= 1;		selPC1_PC	= 1;		ldPC		= 1;			
								
								if (opcode[0] == 0)
									onesComp = 1; 
								else
									twosComp = 1; 
							end
						endcase
					end	
				endcase			
				if (opcode[7:2] == 6'b111110) 
				begin
					selrd_1_TRF	= 1;		selshim_SHU		= 1;		selrd0_TRF	= 1;
					selSHU_TRF	= 1;		writeTRF		= 1;		selPC1_PC	= 1;	
					ldPC		= 1;	
			
					if (opcode[1] == 0)
						logicSH = 1; 
					else
						arithSH = 1; 
				end
			end
			2'b10 :
			begin
				case (opcode[7:4])
					4'b0010 :
					begin
						case (opcode[3:2]) 
							2'b00 :	
							begin																			
								selADR_MEM	= 1;		seldatabus_TRF	= 1;		selPC1_PC	= 1;  selrd0_TRF = 1;
								if (opcode[1] == 1) 
								begin			
									readIO	= 1;		writeTRF	= 1; 		ldPC		= 1;	
								end
								else
								begin						
									readMEM = 1;	 
									if (readyMEM == 1) 
									begin
										writeTRF = 1;	 ldPC = 1;	
									end
								end	
							end	
							2'b01 :	
							begin						
								selADR_MEM	= 1;		selrs1_TRF	= 1;		selrd0_TRF = 1;
								selPC1_PC 	= 1;		
								if (opcode[1] == 1)
								begin
									writeIO  = 1;		ldPC		= 1;
								end
								else
								begin
									writeMEM = 1;
									if (readyMEM == 1) 
										ldPC = 1;	
								end	
						end
						endcase
					end
					4'b1101 : 		
					begin					
						selrd1_TRF	= 1;		selMDU2_TRF	= 1;		writeTRF	= 1;
						ldMDU1		= 1;		arithMUL	= 1;
					end	
					4'b1110 :
					begin
						selrd0_TRF	= 1;		selMDU1_TRF	= 1;		writeTRF	= 1;
						ldMDU2		= 1;		arithDIV	= 1;	
					end
				endcase
			end
			2'b11 :
			begin
				case (opcode[7:4])
					4'b1101 :			
					begin						
						selrd0_TRF	= 1;		selMDU1_TRF	= 1;		writeTRF	= 1;
						selPC1_PC	= 1;		ldPC		= 1;	
					end			
					4'b1110 :
					begin
						selrd1_TRF	= 1;		selMDU2_TRF	= 1;		writeTRF	= 1;
						selPC1_PC	= 1;		ldPC		= 1;		
					end
				endcase
			end
		endcase
	end
	
		always @(*)
		begin
			case (pstate) 
			2'b00 :
				if (rst == 1)
					nstate = 2'b00;
				else
					nstate = 2'b01;
			2'b01 :
			begin
				case (opcode[7:4])
					4'b0000 :
						nstate = 2'b00;
					4'b0001 :
						nstate = 2'b00;
					4'b0010 :
					begin
						case (opcode[3:2])
							2'b00 :
								nstate = 2'b10;
							2'b01 :	
								nstate = 2'b10;
							2'b10 : 
								nstate = 2'b00;
							2'b11 :
								nstate = 2'b00;	
						endcase
					end
					4'b0011 :			
						nstate = 2'b00;
					4'b0100 :
						nstate = 2'b00;
					4'b0101 :
						nstate = 2'b00;
					4'b0110 :
						nstate = 2'b00;
					4'b0111 :			
						nstate = 2'b00;
					4'b1000 :		
						nstate = 2'b00;
					4'b1001 :			
						nstate = 2'b00;
					4'b1010 :			
						nstate = 2'b00;
					4'b1011 :			
						nstate = 2'b00;
					4'b1100 :			
						nstate = 2'b00;
					4'b1101 :
						if (doneMDU == 1)
							nstate = 2'b10;
						else
							nstate = 2'b01;
					4'b1110 :
						if (doneMDU == 1)
							nstate = 2'b10;
						else
							nstate = 2'b01;
					4'b1111 :
					begin
						case (opcode[3:1]) 
							3'b000 :
								nstate = 2'b00;
							3'b001 :
								nstate = 2'b00;
							3'b010 :
								nstate = 2'b00;
							3'b011 :
								nstate = 2'b00;
							3'b110 :
								nstate = 2'b00;
							3'b111 :
								nstate = 2'b00;
						endcase
					end
				endcase
				if (opcode[7:2] == 6'b111110)
					nstate = 2'b00;
			end
			2'b10 :
			begin
				case (opcode[7:4]) 
					4'b0010 :
					begin
						case (opcode[3:2])
							 2'b00 :	
								if (opcode[1] == 1)
									nstate = 2'b00;
								else	
									if (readyMEM == 1)
										nstate = 2'b00;
									else
										nstate = 2'b10;
							2'b01 :
								if (opcode[1] == 1)
									nstate = 2'b00; 	
								else
									if (readyMEM == 1)
										nstate = 2'b00;
									else
										nstate = 2'b10;
						endcase
					end
					4'b1101 : 
						nstate = 2'b11; 		
					4'b1110 :
						nstate = 2'b11; 
				endcase
			end
			2'b11 :
			begin
				case (opcode[7:4])
					4'b1101 : 
						nstate = 2'b00;
					4'b1110 :
						nstate = 2'b00;
				endcase
			end
		endcase
	end	
endmodule