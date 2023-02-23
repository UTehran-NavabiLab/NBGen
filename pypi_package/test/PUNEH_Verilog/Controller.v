/*******************************************************************************/
//	Filename:		Controller.v
//	Project:		PUNEH : Processor that is Useful and New for Education of Hardware
//  Version:		1.0
//	Created by: 	Omid Mohammadi
//	Approved by:	Nooshin Nosrati
//	Date:			6 June 2021
//  Copyright (C) 2021 University of Teheran
//  This source file may be used and distributed without
//  restriction provided that this copyright statement is not
//  removed from the file and that any derivative work contains
//  the original copyright notice and the associated disclaimer.

//******************************************************************************/
//	File content description:
//	Controller of the PUNEH processor, considering Huffman style coding                                 
/*******************************************************************************/

module Controller(clk, rst, inst, enSKP, ldSR, ldIR, ldOF, ldPC, 
                  ldIN, ldAC, zeroAC, seldataBus, selPC_OF, selIMM_OF, 
                  selMEM_IN, selIMM_LGU, selMEM_LGU, sel1_ARU, selMO_ARU, 
                  selINC_PC, selMEM_PC, selIMM_PC, selIN_ADR, selIR_ADR, 
                  selPC_ADR, selAC_MEM, selIMM_AC, selMEM_AC, selARU_AC,
                  selLGU_AC, conOF, SE12bits, SE4bits, AND, NOT, SHF, ADD,
                  MUL, readMEM, writeMEM, selSET_SR, selINC_IN,
                  INC1, INC2, selARU_SR, selLGU_SR,selIN_MEM, selPC_MEM, LSB0E);
				  
	input 		clk, rst, enSKP;
	input [15:0] 	inst; 
	output reg 	ldIR, ldOF, ldPC, ldIN, ldAC, zeroAC, seldataBus, selPC_OF,
	            selIMM_OF, selINC_IN, selMEM_IN, selIMM_LGU, selMEM_LGU, sel1_ARU,
	            selMO_ARU, selINC_PC, selMEM_PC, selIMM_PC, selIN_ADR, selIR_ADR,
	            selPC_ADR, selAC_MEM, selIMM_AC, selMEM_AC, selARU_AC, selLGU_AC,
	            conOF, SE12bits, SE4bits, AND, NOT, ADD, MUL, readMEM, writeMEM,
	            selSET_SR, INC1, INC2, selARU_SR, selLGU_SR,selIN_MEM, selPC_MEM, LSB0E;
	output reg [1:0]  SHF;
	output reg [3:0]  ldSR;           
	reg  [1:0] pstate;
	reg  [1:0] nstate;
	
	parameter  [3:0] LDm		= 4'b0000;
	parameter  [3:0] LDa		= 4'b0001;
	parameter  [3:0] LDn		= 4'b0010;
	parameter  [3:0] STa		= 4'b0011;
	parameter  [3:0] STn		= 4'b0100;
	parameter  [3:0] INa		= 4'b0101;
	parameter  [3:0] ANm		= 4'b0110;
	parameter  [3:0] ANa		= 4'b0111;
	parameter  [3:0] ADm		= 4'b1000;
	parameter  [3:0] ADa		= 4'b1001;
	parameter  [3:0] ADn		= 4'b1010;
	parameter  [3:0] MLa		= 4'b1011;
	parameter  [3:0] JMa		= 4'b1100;
	parameter  [3:0] JMn		= 4'b1101;
	parameter  [3:0] JSR		= 4'b1110;
	parameter  [3:0] INST15 	= 4'b1111;
	parameter  [3:0] TYPE1		= 4'b0000;
	parameter  [3:0] LOm 		= 4'b0001;
	parameter  [3:0] SRA		= 4'b0010;
	parameter  [3:0] SRL		= 4'b0011;
	parameter  [3:0] SLL		= 4'b0100;
	parameter  [3:0] SKP		= 4'b0101; 
	parameter  [3:0] SET		= 4'b0110;
	parameter  [7:0] LPO		= 8'b00000000;
	parameter  [7:0] LOP		= 8'b00000001;
	parameter  [7:0] ACZ		= 8'b00000010;
	parameter  [7:0] ACN		= 8'b00000011;
	parameter  [7:0] ACI		= 8'b00000100;
	
	parameter  [1:0] fetch 		= 2'b00;
	parameter  [1:0] exec1 		= 2'b01;
	parameter  [1:0] exec2 		= 2'b10;
	
	always @(posedge clk, posedge rst) begin
		if (rst) 
			pstate <= 2'b00;
		else 
			pstate <= nstate;
	end		
	
	always @(pstate, inst) begin
		ldSR = 0; ldIR = 0; ldOF = 0; ldPC = 0; 
		ldIN = 0; ldAC = 0; zeroAC = 0; seldataBus = 0;
		selPC_OF = 0; selIMM_OF = 0;  selINC_IN = 0; selMEM_IN = 0;
		selIMM_LGU = 0; selMEM_LGU = 0; sel1_ARU = 0; selMO_ARU = 0;
		selINC_PC = 0; selMEM_PC = 0; selIMM_PC = 0; selIN_ADR = 0; 
		selIR_ADR = 0; selPC_ADR = 0;  selAC_MEM = 0;  selIMM_AC = 0; 
		selMEM_AC = 0; selARU_AC = 0;  selLGU_AC = 0; conOF = 0; 
		SE12bits = 0;  SE4bits = 0;  AND = 0;  NOT = 0;  
		SHF = 0; ADD = 0;  MUL = 0;  readMEM = 0;
		writeMEM = 0; INC1 = 0;  INC2 = 0; 
		selSET_SR = 0; selARU_SR = 0; selLGU_SR = 0;
		selIN_MEM=0; selPC_MEM=0; LSB0E = 0;
		
		case (pstate) 
			fetch : begin
				selPC_ADR = 1;	ldIR = 1;  readMEM = 1;
			end	
			exec1 : begin case (inst[15:12]) 
				LDm : begin
					SE4bits = 1;  selIMM_AC = 1;  ldAC = 1; 
					INC1 = 1;  selINC_PC = 1;  ldPC = 1;	
				end
				LDa : begin
					conOF = 1;  selIR_ADR = 1;  readMEM = 1;
					selMEM_AC = 1;  ldAC = 1; 
					INC1 = 1;  selINC_PC = 1;  ldPC = 1;	
				end	
				LDn : begin
					conOF = 1;  selIR_ADR = 1;  readMEM = 1;
					selMEM_IN = 1;  ldIN = 1; 			
				end		
				STa : begin
					conOF = 1;  selIR_ADR = 1;  selAC_MEM = 1;
					seldataBus = 1;  writeMEM = 1; 
					INC1 = 1;  selINC_PC = 1;  ldPC = 1;				
				end														
				STn : begin
					conOF = 1;  selIR_ADR = 1;  readMEM = 1;
					selMEM_IN = 1;  ldIN = 1;	
				end
				INa : begin
					conOF = 1;  selIR_ADR = 1;  readMEM = 1; 
					selINC_IN = 1;  ldIN = 1;	
				end																							
				ANm : begin
					SE4bits	= 1;  selIMM_LGU = 1;  AND = 1;
					selLGU_AC = 1;  ldAC = 1;  
					selLGU_SR = 1;  ldSR = 4'b1100;
					INC1 = 1;  selINC_PC = 1;  ldPC = 1;
				end	
				ANa : begin
					conOF = 1;  selIR_ADR = 1;  readMEM = 1; 
					selMEM_LGU = 1;  AND = 1;  selLGU_AC = 1; ldAC = 1;  
					selLGU_SR = 1;  ldSR = 4'b1100;	
					INC1 = 1;  selINC_PC = 1;  ldPC = 1;
				end	
				ADm : begin
					SE4bits	= 1;  selIMM_LGU = 1;  selMO_ARU = 1;
					ADD	= 1;  selARU_AC = 1;  ldAC = 1;	
					selARU_SR = 1;  ldSR = 4'b1111; 
					INC1 = 1;  selINC_PC = 1;  ldPC = 1;
				end	
				ADa : begin
					conOF = 1;  selIR_ADR = 1;  readMEM = 1; 
					selMEM_LGU = 1;  selMO_ARU	= 1;  ADD = 1;  
					selARU_AC = 1;  ldAC = 1;  
					selARU_SR = 1;  ldSR = 4'b1111;
					INC1 = 1;  selINC_PC = 1;  ldPC = 1;			
				end	
				ADn : begin
					conOF = 1;  selIR_ADR = 1;  readMEM = 1;
					selMEM_IN = 1;  ldIN = 1;				
				end	
				MLa : begin
					conOF = 1;  selIR_ADR = 1;  readMEM = 1;
					selMEM_LGU = 1;  selMO_ARU = 1;  MUL = 1;
					selARU_AC = 1;  ldAC = 1;
					selARU_SR = 1;  ldSR = 4'b1000; 
					INC1 = 1;  selINC_PC = 1;  ldPC = 1;
				end
				JMa : begin
					conOF = 1;  selIMM_PC = 1;  ldPC = 1;			
				end	
				JMn : begin
					conOF = 1;  selIR_ADR = 1;  readMEM = 1;
					selMEM_PC = 1;  ldPC = 1; 
				end	
				JSR : begin
					conOF = 1;  selIR_ADR = 1;  INC1 = 1;
					selPC_MEM = 1;  seldataBus = 1;      
					writeMEM = 1;  selIMM_PC = 1;  ldPC = 1;  
				end	
				INST15 : begin case (inst[11:8])
					TYPE1 : begin case (inst[7:0])
						LPO : begin
							selPC_OF = 1;  ldOF  = 1;  
							INC1 = 1;  selINC_PC = 1;  ldPC = 1;
						end
						LOP : begin
							LSB0E = 1;  selIMM_PC = 1;  ldPC = 1; 
						end
						ACZ : begin
							zeroAC = 1;  
							selLGU_SR = 1;  ldSR = 4'b1100;
							INC1 = 1;  selINC_PC = 1;  ldPC = 1;
						end
						ACN : begin
							NOT = 1;  selLGU_AC = 1;  ldAC = 1; 
							selLGU_SR = 1;  ldSR = 4'b1100; 
							INC1 = 1;  selINC_PC = 1;  ldPC = 1;
						end
						ACI : begin
							sel1_ARU = 1;  ADD = 1;
							selARU_AC = 1;  ldAC = 1; 
							INC1 = 1;  selINC_PC = 1;  ldPC = 1; 	
						end
						default : begin
							INC1 = 1;  selINC_PC = 1;  ldPC = 1;
						end
					endcase
					end
					LOm : begin
						SE12bits = 1;  selIMM_OF = 1;  ldOF	= 1;
						INC1 = 1;  selINC_PC = 1;  ldPC = 1;		
					end	
					SRA : begin
						SE12bits = 1;  selIMM_LGU = 1;	SHF = 2'b00;
						selLGU_AC = 1;  ldAC = 1;
						INC1 = 1;  selINC_PC = 1;  ldPC = 1; 
					end
					SRL : begin
						SE12bits = 1;  selIMM_LGU = 1;  SHF = 2'b01;
						selLGU_AC = 1;  ldAC = 1;
						INC1 = 1;  selINC_PC = 1;  ldPC = 1;
					end
					SLL : begin
						SE12bits = 1;  selIMM_LGU = 1;  SHF = 2'b10;
						selLGU_AC = 1;  ldAC = 1;
						INC1 = 1;  selINC_PC = 1;  ldPC = 1;
					end
					SKP : begin
						if (enSKP) INC2 = 1; 
						else INC1 = 1;
						selINC_PC = 1;  ldPC = 1;
					end
					SET : begin
						selSET_SR = 1;  ldSR = inst[7:4];
						INC1 = 1;  selINC_PC = 1;  ldPC = 1;
					end
					default : begin
						INC1 = 1;  selINC_PC = 1;  ldPC = 1;
					end
				endcase
				end
					default : begin
						INC1 = 1;  selINC_PC = 1;  ldPC = 1;
					end	
			endcase
			end			
			exec2 : begin case (inst[15:12])
				LDn : begin
					selIN_ADR = 1;  readMEM = 1;  
					selMEM_AC = 1; ldAC = 1;
					INC1 = 1;  selINC_PC = 1;  ldPC = 1;
				end
				STn : begin					
					selIN_ADR = 1;  selAC_MEM = 1; 
					seldataBus = 1;  writeMEM = 1;  
					INC1 = 1;  selINC_PC = 1;  ldPC = 1; 
				end	
				INa : begin
					conOF = 1;  selIR_ADR = 1;  selIN_MEM = 1;
					seldataBus = 1;  writeMEM = 1;	
					INC1 = 1;  selINC_PC = 1;  ldPC = 1;		
				end
				ADn : begin
					selIN_ADR = 1;  readMEM = 1;  selMEM_LGU = 1;
					selMO_ARU = 1;  ADD = 1;  selARU_AC = 1;  ldAC = 1;
					selARU_SR = 1;  ldSR = 4'b1111;
					INC1 = 1;  selINC_PC = 1;  ldPC = 1;
				end
				JSR : begin
					INC1 = 1;  selINC_PC = 1;  ldPC = 1;			
				end
			endcase
			end
		endcase
	end
	
	always @(pstate, inst) begin
		case (pstate) 
			fetch :
				if (rst == 1)
					nstate = fetch;
				else
					nstate = exec1;
			exec1 : begin case (inst[15:12]) 
				LDm :	 nstate = fetch;
				LDa :	 nstate = fetch;
				LDn :	 nstate = exec2;	
				STa :	 nstate = fetch;													
				STn :	 nstate = exec2;
				INa :	 nstate = exec2;																					
				ANm :	 nstate = fetch;
				ANa : 	 nstate = fetch;
				ADm : 	 nstate = fetch;
				ADa : 	 nstate = fetch;
				ADn : 	 nstate = exec2;
				MLa : 	 nstate = fetch;
				JMa : 	 nstate = fetch;
				JMn : 	 nstate = fetch;
				JSR : 	 nstate = exec2;
				INST15 : nstate = fetch;
				default: nstate = fetch;	
			endcase
		end
			exec2 : begin 
				nstate = fetch ;	
			end						
		endcase
	end	
endmodule