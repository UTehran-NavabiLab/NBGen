module PUNEH_Top (clk, rst, writeMEM, readMEM, dataBus_in, dataBus_out, addrBus);

	input clk, rst;
    input [15:0] dataBus_in;
    output [15:0] dataBus_out;
	output writeMEM, readMEM;
	output [15:0] addrBus;

	wire [15:0] inst;
	wire [3:0]  ldSR;
	wire [1:0]  SHF;
	wire enSKP, ldIR, ldOF, ldPC, ldIN, ldAC, zeroAC, seldataBus, selPC_OF,
	     selIMM_OF, selMEM_IN, selIMM_LGU, selMEM_LGU, sel1_ARU, selMO_ARU, 
	     selINC_PC, selMEM_PC, selIMM_PC, selIN_MEM, selIR_MEM, selPC_MEM,
	     selAC_MEM, selIN_ADR, selIR_ADR,selPC_ADR,selIMM_AC, selMEM_AC, selARU_AC, selLGU_AC, conOF,
	     SE12bits, SE4bits,LSB0E, AND, NOT, ADD, MUL,selSET_SR, selINC_IN,
	     INC1, INC2, selARU_SR, selLGU_SR;

	Datapath DP (clk, rst,dataBus_in, dataBus_out, AND, NOT, SHF, ADD, MUL, sel1_ARU,
		 selIMM_LGU, selMEM_LGU, ldAC, zeroAC, selIMM_AC, selMEM_AC,
		 selARU_AC, selLGU_AC, ldPC, selINC_PC, selMEM_PC, selIMM_PC,
		 ldIN, selINC_IN, selMEM_IN, conOF, SE12bits, SE4bits,LSB0E, ldIR,
		 ldOF, selPC_OF, selIMM_OF, selIN_MEM, selPC_MEM, selAC_MEM,
		 selIR_MEM,selIN_ADR, selIR_ADR,selPC_ADR, seldataBus, INC1, INC2, ldSR, selSET_SR, selLGU_SR,
		 selARU_SR, enSKP, addrBus, inst, selMO_ARU);

	Controller CU (clk, rst, inst, enSKP, ldSR, ldIR, ldOF, ldPC, 
     			   ldIN, ldAC, zeroAC, seldataBus, selPC_OF, selIMM_OF, 
     			   selMEM_IN, selIMM_LGU, selMEM_LGU, sel1_ARU, selMO_ARU, 
     			   selINC_PC, selMEM_PC, selIMM_PC, selIN_MEM, selIR_MEM, 
     			   selPC_MEM, selAC_MEM,selIN_ADR, selIR_ADR,
				   selPC_ADR, selIMM_AC, selMEM_AC, selARU_AC,
     			   selLGU_AC, conOF, SE12bits, SE4bits, LSB0E,AND, NOT, SHF, ADD,
     			   MUL, readMEM, writeMEM, selSET_SR, selINC_IN,
     			   INC1, INC2, selARU_SR, selLGU_SR);

endmodule
module Datapath (clk, rst,dataBus_in, dataBus_out, AND, NOT, SHF, ADD, MUL, sel1_ARU,
		 selIMM_LGU, selMEM_LGU, ldAC, zeroAC, selIMM_AC, selMEM_AC,
		 selARU_AC, selLGU_AC, ldPC, selINC_PC, selMEM_PC, selIMM_PC,
		 ldIN, selINC_IN, selMEM_IN, conOF, SE12bits, SE4bits,LSB0E, ldIR,
		 ldOF, selPC_OF, selIMM_OF, selIN_MEM, selPC_MEM, selAC_MEM,
		 selIR_MEM,selIN_ADR, selIR_ADR,selPC_ADR, seldataBus, INC1, INC2, ldSR, selSET_SR, selLGU_SR,
		 selARU_SR, enSKP, addrBus, IRout, selMO_ARU);
	
	input clk, rst, AND, NOT, ADD, MUL, sel1_ARU, selMO_ARU, selIMM_LGU,
	      selMEM_LGU, ldAC, zeroAC, selIMM_AC, selMEM_AC,  selARU_AC,
	      selLGU_AC, ldPC, selINC_PC, selMEM_PC, selIMM_PC, ldIN,
	      selINC_IN, selMEM_IN, conOF, SE12bits, SE4bits,LSB0E, ldIR, ldOF,
	      selPC_OF, selIMM_OF, selIN_MEM, selPC_MEM, selAC_MEM, selIR_MEM,selIN_ADR, selIR_ADR,selPC_ADR,
	      seldataBus, INC1, INC2, selSET_SR, selLGU_SR, selARU_SR;
	input  [15:0] dataBus_in;
	output  [15:0] dataBus_out;
	input  [1:0]  SHF;
	input  [3:0]  ldSR;
	output [15:0] addrBus, IRout;
	output enSKP;
		
	wire [15:0] ARU_AC, LGU_AC, MEM_AC, IMM_AC, AC_MEM, MO, MO_ARU, toAC,
		    PC_MEM, toPC, toIN, IN_MEM, INC_PC, INC2_out, inBuff;
	wire [11:0] wire_SR;
	wire [3:0]  toOF, OFout, toSR, exp, obs;
	wire [1:0]  toINC;
	wire Z1, Z2, N1, N2, C, V;

	// Flags assign

	assign exp = IRout[3:0];

	assign wire_SR[4]  = wire_SR[0] ~^ exp[0];
	assign wire_SR[5]  = wire_SR[1] ~^ exp[1];
	assign wire_SR[6]  = wire_SR[2] ~^ exp[2];
	assign wire_SR[7]  = wire_SR[3] ~^ exp[3];

	assign obs = IRout[7:4];

	assign wire_SR[8]  = wire_SR[4] & obs[0];
	assign wire_SR[9]  = wire_SR[5] & obs[1];
	assign wire_SR[10] = wire_SR[6] & obs[2];
	assign wire_SR[11] = wire_SR[7] & obs[3];

	assign MEM_AC = dataBus_in;
	assign enSKP = wire_SR[8] | wire_SR[9] | wire_SR[10] | wire_SR[11];

	// Multiplexer 4x1

	Multiplexer_4_to_1 #(16) mux1  (IMM_AC, MEM_AC, ARU_AC, LGU_AC, selIMM_AC,
			     selMEM_AC, selARU_AC, selLGU_AC, toAC);

	Multiplexer_4_to_1 #(16) mux2  (INC_PC, MEM_AC, IMM_AC, 16'bz, selINC_PC,
			     selMEM_PC, selIMM_PC, 1'b0, toPC);

	Multiplexer_4_to_1 #(16) mux3  (IN_MEM, INC_PC, AC_MEM, 16'bz, selIN_MEM,
			     selPC_MEM, selAC_MEM, 1'b0, inBuff);

	Multiplexer_4_to_1 #(16) mux4  (IN_MEM, IMM_AC, PC_MEM, 16'bz, selIN_ADR,
			     selIR_ADR, selPC_ADR, 1'b0, addrBus);		

	Multiplexer_4_to_1 #(4)  mux5 (IRout[3:0], {Z1, N1, 2'b0}, {Z2, N2, C, V}, 4'b0, selSET_SR,
			     selLGU_SR, selARU_SR, 1'b0, toSR);

	// Multiplexer 2x1
	
	Multiplexer_2_to_1 #(16) mux6  (INC2_out, MEM_AC, selINC_IN, selMEM_IN, toIN);

	Multiplexer_2_to_1 #(16) mux7  (IMM_AC, MEM_AC, selIMM_LGU, selMEM_LGU, MO);

	Multiplexer_2_to_1 #(16) mux8  (16'd1, MO, sel1_ARU, selMO_ARU, MO_ARU);
	
	Multiplexer_2_to_1 #(4)  mux9  (PC_MEM[15:12], IMM_AC[3:0], selPC_OF, selIMM_OF, toOF);

	Multiplexer_2_to_1 #(2)  mux10  (2'd2, 2'd1, INC2, INC1, toINC);

	//Incrementors
	INC INC_1 (PC_MEM, toINC, INC_PC);

	INC INC_2 (MEM_AC, 2'd1, INC2_out);
    
	// Registers
	register #(4)  OF (clk, rst, toOF, ldOF, 1'b0, OFout);

	register #(1)  SR_Z (clk, rst, toSR[3], ldSR[3], 1'b0, wire_SR[3]);
	register #(1)  SR_N (clk, rst, toSR[2], ldSR[2], 1'b0, wire_SR[2]);
	register #(1)  SR_C (clk, rst, toSR[1], ldSR[1], 1'b0, wire_SR[1]);
	register #(1)  SR_V (clk, rst, toSR[0], ldSR[0], 1'b0, wire_SR[0]);

	register #(16) AC (clk, rst, toAC, ldAC, zeroAC, AC_MEM);

	register #(16) IR (clk, rst, MEM_AC, ldIR, 1'b0, IRout);

	register #(16) PC (clk, rst, toPC, ldPC, 1'b0, PC_MEM);

	register #(16) IN (clk, rst, toIN, ldIN, 1'b0, IN_MEM);

	// IMM module
	IMM IMM1 (IRout[11:0], OFout, conOF, SE12bits, SE4bits,LSB0E,IMM_AC);

	// LGU module
	LGU LGU1 (AC_MEM, MO, AND, NOT, SHF, LGU_AC, Z1, N1);

	// ARU module
	ARU ARU1 (AC_MEM, MO_ARU, ADD, MUL, ARU_AC, Z2, N2, C, V);	

	//Tristate

	Tristate TriBuff (inBuff, 1'b1, dataBus_out);
	
endmodule
module Controller(clk, rst, inst, enSKP, ldSR, ldIR, ldOF, ldPC, 
                  ldIN, ldAC, zeroAC, seldataBus, selPC_OF, selIMM_OF, 
                  selMEM_IN, selIMM_LGU, selMEM_LGU, sel1_ARU, selMO_ARU, 
                  selINC_PC, selMEM_PC, selIMM_PC, selIN_MEM, selIR_MEM, 
                  selPC_MEM, selAC_MEM, selIN_ADR, selIR_ADR,
		            selPC_ADR,selIMM_AC, selMEM_AC, selARU_AC,
                  selLGU_AC, conOF, SE12bits, SE4bits,LSB0E, AND, NOT, SHF, ADD,
                  MUL, readMEM, writeMEM, selSET_SR, selINC_IN,
                  INC1, INC2, selARU_SR, selLGU_SR);
	
	input clk;
	input rst;
	input	enSKP;
	
	input [15:0] 	inst; 
	output reg  ldIR, ldOF, ldPC, ldIN, ldAC, zeroAC, seldataBus, selPC_OF,
	            selIMM_OF, selINC_IN, selMEM_IN, selIMM_LGU, selMEM_LGU, sel1_ARU,
	            selMO_ARU, selINC_PC, selMEM_PC, selIMM_PC, selIN_MEM, selIR_MEM,
	            selPC_MEM, selAC_MEM, selIN_ADR, selIR_ADR,
				selPC_ADR, selIMM_AC, selMEM_AC, selARU_AC, selLGU_AC,
	            conOF, SE12bits, SE4bits,LSB0E ,AND, NOT, ADD, MUL, readMEM, writeMEM,
	            selSET_SR, INC1, INC2, selARU_SR, selLGU_SR;

	output reg [1:0]  SHF;
	output reg [3:0]  ldSR;           

	reg  [1:0] pstate;
	reg  [1:0] nstate;

	//parameter definetion
	parameter  [3:0] LDm		 = 4'b0000;
	parameter  [3:0] LDa		 = 4'b0001;
	parameter  [3:0] LDn		 = 4'b0010;
	parameter  [3:0] STa		 = 4'b0011;
	parameter  [3:0] STn		 = 4'b0100;
	parameter  [3:0] INa		 = 4'b0101;
	parameter  [3:0] ANm		 = 4'b0110;
	parameter  [3:0] ANa		 = 4'b0111;
	parameter  [3:0] ADm		 = 4'b1000;
	parameter  [3:0] ADa		 = 4'b1001;
	parameter  [3:0] ADn		 = 4'b1010;
	parameter  [3:0] MLa		 = 4'b1011;
	parameter  [3:0] JMa		 = 4'b1100;
	parameter  [3:0] JMn		 = 4'b1101;
	parameter  [3:0] JSR		 = 4'b1110;

	parameter  [3:0] Fulll15 = 4'b1111;
	parameter  [3:0] Type2   = 4'b0001;

	parameter  [3:0] LOm		 = 4'b0000;
	parameter  [2:0] LPO		 = 3'b000;
	parameter  [2:0] LOP		 = 3'b001;
	parameter  [2:0] ACZ		 = 3'b010;
	parameter  [2:0] ACN		 = 3'b011;
	parameter  [2:0] ACI		 = 3'b100;
	parameter  [3:0] SRA		 = 4'b0010;
	parameter  [3:0] SLL		 = 4'b0011;
	parameter  [3:0] SRL		 = 4'b0100;
	parameter  [3:0] SKP		 = 4'b1001;
	parameter  [3:0] SET		 = 4'b0110;

	parameter  [1:0] fetch      = 2'b00;
	parameter  [1:0] exec1      = 2'b01;
	parameter  [1:0] exec2      = 2'b10;
	
	always @(posedge clk, posedge rst) begin
		if (rst) 
			pstate <= 2'b00;
		else 
			pstate <= nstate;
	end
			
	always @(pstate, inst)
	begin
		 ldSR = 0;       ldIR = 0;        ldOF = 0;       ldPC = 0; 
		 ldIN = 0;       ldAC = 0;        zeroAC = 0;     seldataBus = 0;
		 selPC_OF = 0;   selIMM_OF = 0;   selINC_IN = 0;  selMEM_IN = 0;
		 selIMM_LGU = 0; selMEM_LGU = 0;  sel1_ARU = 0;   selMO_ARU = 0;
	    selINC_PC = 0;  selMEM_PC = 0;   selIMM_PC = 0;  selIN_MEM = 0; 
	    selIR_MEM = 0;  selPC_MEM = 0;   selAC_MEM = 0;  selIMM_AC = 0; 
  		 selIN_ADR=0;    selIR_ADR=0;	 selPC_ADR=0;	 conOF = 0;
	    selMEM_AC = 0;  selARU_AC = 0;   selLGU_AC = 0;  AND = 0; 
	    SE12bits = 0;   SE4bits = 0;     LSB0E=0;        NOT = 0;       
	    SHF = 0;        ADD = 0;         MUL = 0;        readMEM = 0;
	    writeMEM = 0;   INC1 = 0;        INC2 = 0;       
	    selSET_SR = 0;  selARU_SR = 0;   selLGU_SR = 0;

		case (pstate)
			fetch :
			begin
				selPC_ADR = 1;	ldIR = 1;  readMEM = 1;
				nstate = exec1;
			end	
			exec1 :
			begin 
				case (inst[15:12]) 
					LDm :
					begin
						SE4bits = 1;    selIMM_AC = 1;  	ldAC = 1;
						INC1 = 1;       selINC_PC = 1;  	ldPC = 1;	
						nstate = fetch;
					end
					LDa :
					begin
						
						conOF = 1;		selIR_ADR = 1;  	
						selMEM_AC = 1;  ldAC = 1;       	readMEM = 1;
						INC1 = 1;       selINC_PC = 1;   	ldPC = 1;
						nstate = fetch;	
					end	
					LDn : 
					begin

						conOF = 1;		 selIR_ADR = 1;   	 readMEM = 1;
						selMEM_IN = 1;   ldIN = 1;     
						 nstate = exec2; 
								
					end		
				    STa :
					begin
						conOF = 1;      selIR_ADR = 1;    	selAC_MEM = 1;
						seldataBus = 1; writeMEM = 1;
						INC1 = 1;  		selINC_PC = 1; 	  	ldPC = 1;
						nstate = fetch;					
					end														
					STn :
					begin
						conOF = 1;		selIR_ADR = 1;   	readMEM = 1;  
						selMEM_IN = 1;	ldIN = 1;
						nstate = exec2;	
					end
					INa :
					begin
						conOF = 1;      selIR_ADR = 1;  	readMEM = 1; 
						selINC_IN = 1;  ldIN = 1;	
						nstate = exec2;
					end																							
					ANm :
					begin
						SE4bits= 1;		   selIMM_LGU= 1;		AND	= 1;
						selLGU_SR = 1;	   ldSR = 4'b1100;      selLGU_AC= 1;               
						ldAC= 1;
						INC1 = 1;          selINC_PC = 1;       ldPC = 1;
						nstate = fetch;
					end	
					ANa :
					begin
						conOF = 1; 	       selIR_ADR = 1;          readMEM = 1;
						selMEM_LGU = 1;    AND = 1;  			   selLGU_SR = 1; 		                
						ldSR = 4'b1100;	   selLGU_AC = 1; 		   ldAC = 1;			        							
						INC1 = 1;          selINC_PC = 1;    	   ldPC = 1;
						nstate = fetch;
						
					end	
					ADm :
					begin
						SE4bits= 1;		    selIMM_LGU	= 1;		selARU_AC= 1;
						selMO_ARU = 1;	    ADD= 1;          		ldAC= 1;	
						ldSR = 4'b1111;     selARU_SR = 1;
						INC1 = 1;           selINC_PC = 1;           ldPC = 1;
						nstate = fetch;
					end	
					ADa :
					begin
						conOF = 1;		    selIR_ADR	= 1;		readMEM = 1;
						selMEM_LGU	= 1;	selMO_ARU	= 1;		ADD	= 1;  
						selARU_SR = 1;		ldSR = 4'b1111;	    	selARU_AC = 1;		        
						ldAC= 1;
						INC1 = 1;  			selINC_PC = 1; 			ldPC = 1;
						nstate = fetch;			
					end	
					ADn :
					begin
						conOF = 1;		     selIR_ADR= 1;			readMEM = 1;
						selMEM_IN	= 1;  	 ldIN= 1;
						 nstate = exec2;				
					end	
					MLa :
					begin
						conOF = 1;  		 selIR_ADR = 1; 		readMEM = 1;
						selMEM_LGU = 1; 	 selMO_ARU = 1;		    MUL = 1;
					    selARU_SR = 1;		 ldSR = 4'b1000;        selARU_AC = 1; 		
						ldAC = 1; 
						INC1 = 1;            selINC_PC = 1; 		ldPC = 1;
						nstate = fetch;
					end
					JMa :
					begin
						conOF = 1;			 selIMM_PC= 1;			ldPC= 1;
						nstate = fetch;	

					end	
					JMn :
					begin
						conOF = 1;	       	 selIR_ADR=1;		    readMEM = 1; 
						selMEM_PC=1;         ldPC=1;
						nstate = fetch;
							
					end	
					JSR :
					begin
						conOF = 1;			 selIR_ADR	= 1;		INC1= 1;
						selIMM_PC	= 1;	 seldataBus= 1;			writeMEM = 1;		    	  
						selPC_MEM = 1;		 ldPC		= 1;
						nstate = exec2;	
					end	
					Fulll15 :
					begin
						case (inst[11:8])
							LOm :
							begin
								SE12bits= 1;		selIMM_OF	= 1;		ldOF= 1;
								INC1 = 1;           selINC_PC = 1;          ldPC = 1;
								nstate = fetch;		
							end	
							Type2:
							begin
							  case (inst[7:5])
						      LPO :
						      begin
						        selPC_OF = 1;   ldOF  = 1;  
						        INC1 = 1;       selINC_PC = 1;  ldPC = 1;
								nstate = fetch;
						      end
						      LOP :
						      begin
										LSB0E = 1;    selIMM_PC = 1;   ldPC = 1;  
										nstate = fetch;          
										
									end
									ACZ :
									begin
										zeroAC = 1;   selLGU_SR = 1;    ldSR = 4'b1100;
										INC1 = 1;     selINC_PC = 1;    ldPC = 1;
										nstate = fetch;
										
									end
									ACN :
									begin
										NOT = 1;         ldSR = 4'b1100;  selLGU_SR = 1;   
										selLGU_AC = 1;   ldAC = 1;
										INC1 = 1;        selINC_PC = 1;   ldPC = 1;
										nstate = fetch;
									end
									ACI : 
									begin
										sel1_ARU = 1;     ADD = 1;        selARU_AC = 1;	
										ldAC = 1;
										INC1 = 1;  selINC_PC = 1; ldPC = 1;
										nstate = fetch;
												
									end
									default :
									begin
										 INC1 = 1;  selINC_PC = 1; ldPC = 1;
										 nstate = fetch;
									end
							  endcase
							end
							SRA :
							begin
							    SE12bits = 1;		selIMM_LGU = 1;	 SHF = 2'b00;
								selLGU_AC = 1;      ldAC = 1;
								INC1 = 1;           selINC_PC = 1;   ldPC = 1; 
								nstate = fetch;
							end
							SLL :
							begin
						        SE12bits = 1;		selIMM_LGU = 1;	  SHF = 2'b10;
								selLGU_AC = 1;      ldAC = 1;
								INC1 = 1;           selINC_PC = 1;    ldPC = 1;
								nstate = fetch;
							end
							SRL :
							begin
								SE12bits = 1;		selIMM_LGU = 1;	  SHF = 2'b01;
								selLGU_AC = 1; 	    ldAC = 1;
								INC1 = 1;           selINC_PC = 1;    ldPC = 1;
								nstate = fetch;
							end
							SKP :
							begin
								if (enSKP == 1)
								begin 
								  INC2 = 1;   		selINC_PC = 1;    ldPC = 1;
								  nstate = fetch;
								end
								else
								begin
								  INC1 = 1;   		 selINC_PC = 1;   ldPC = 1;
								  nstate = fetch;
								end
							end
							SET :
							begin
								selSET_SR = 1;  	ldSR = inst[7:4];
								INC1 = 1;     	    selINC_PC = 1;    ldPC = 1;
								nstate = fetch;
							end
							default :
							begin
								INC1 = 1;  selINC_PC = 1; ldPC = 1;
								nstate = fetch;
							end
						endcase
					end
					default :
						begin
							 INC1 = 1;  selINC_PC = 1; ldPC = 1;
							 nstate = fetch;
						end	
				endcase
			end			
			exec2 :
			begin
				case (inst[15:12])
					LDn :
					begin
						selIN_ADR = 1;  readMEM = 1;  selMEM_AC = 1;
						ldAC = 1;
						INC1 = 1;  selINC_PC = 1; ldPC = 1;
						nstate = fetch;
					end
					STn : 		
					begin					
						selIN_ADR = 1;  selAC_MEM = 1;    seldataBus = 1;
						writeMEM = 1;   selINC_PC = 1;     ldPC = 1;
						INC1 = 1;
						nstate = fetch;
					end	
					INa :
					begin
					    selIR_ADR = 1;	    selIN_MEM = 1;  writeMEM = 1;  
						seldataBus = 1;      conOF = 1;	
						INC1 = 1;            selINC_PC = 1;  ldPC = 1;
						nstate = fetch;		
					end
					ADn :
					begin
						selIN_MEM = 1;    readMEM = 1;    selMEM_LGU = 1;
						selMO_ARU = 1;    ADD = 1;	      selARU_SR = 1;  
						ldSR = 4'b1111;	  selARU_AC = 1;  ldAC = 1; 
						INC1 = 1;         selINC_PC = 1;  ldPC = 1;
						nstate = fetch;
						
					end
					JSR :
					begin
						selINC_PC = 1; INC1 = 1; ldPC = 1;	
						nstate = fetch;		
					end
					default :
						begin
							 INC1 = 1;  selINC_PC = 1; ldPC = 1;
							 nstate = fetch;
						end	
				endcase
			end
			default :
			nstate = fetch;
		endcase
	end
	
endmodule
module register #(parameter N = 16) (clk,rst,d,ld,clr,q);

	input clk;
	input clr;
	input rst;
	input ld;
	input [N-1:0]d;
	
	output reg [N-1:0]q;
	
	always @(posedge clk, posedge rst)
	begin
	
		if (rst == 1'b1)
			q <= 'b0;
		else if(clr)
			q <= 'b0;
		else if(ld)
			q <= d;
	
	end

endmodule
module Multiplexer_4_to_1 #(parameter N = 16) (in0,in1,in2,in3,sel0,sel1,sel2,sel3,out);

	input [N-1:0]in0;
	input [N-1:0]in1;
	input [N-1:0]in2;
	input [N-1:0]in3;
	
	input sel0;
	input sel1;
	input sel2;
	input sel3;

	output [N-1:0] out;
	
	assign out = sel0 ? in0 :
					 sel1 ? in1 :
					 sel2 ? in2 :
					 sel3 ? in3 :
					 'bz;

endmodule
module Multiplexer_2_to_1 #(parameter N = 16) (in0,in1,sel0,sel1,out);

	input [N-1:0] in0;
	input [N-1:0] in1;
	
	input sel0;
	input sel1;

	output [N-1:0] out;
	
	assign out = sel0 ? in0 :
					 sel1 ? in1 :
					 'bz;

endmodule
module INC # (parameter N = 16)(in, increament_val, out);

	input  [N-1:0] in;
	input  [1:0] increament_val;
	output [N-1:0] out;
	
	assign out = in + increament_val;

endmodule
module IMM(in0,in1,conOF,SE12bits,SE4bits,LSB0E,out);

	input [11:0] in0;
	input [3:0] in1;
	
	input conOF;
	input SE12bits;
	input SE4bits;
	input LSB0E;
	
	output [15:0] out;
	
	assign out = conOF?{in1,in0}:
					 SE12bits?{{12{in0[3]}},in0[3:0]}:
					 SE4bits?{{4{in0[11]}},in0[11:0]}:
					 LSB0E?{in1,12'b0}:
					 16'bz;


endmodule
module LGU #(parameter NN = 16)(in0,in1,AND,NOT,SHF,out,Z,N);

	input signed [NN-1:0] in0;
	input signed [NN-1:0] in1;
	
	input [1:0]SHF;
	
	input AND;
	input NOT;
	
	output Z;
	output N;

	output signed [NN-1:0] out;
	
	assign out = AND            ? (in0&in1):
					 NOT            ? ~in0:
					 (SHF == 2'b00) ? (in0 >>> in1[3:0]):
					 (SHF == 2'b01) ? (in0 >> in1[3:0]):
					 (SHF == 2'b10) ? (in0 >>> in1[3:0]):
					 (SHF == 2'b00) ? (in0 << in1[3:0]):
					 'bz;
					 
endmodule
module ARU #(parameter NN = 16) (in0, in1, ADD, MUL, out, Z, N, C, V);

	input signed [NN-1:0] in0;
	input signed [NN-1:0] in1;
	
	input ADD;
	input MUL;
	
	output Z;
	output N;
	output C;
	output V;

	output signed [NN-1:0] out;
	
	assign {C,out} = ADD?(in0+in1):
						  MUL?(in0[7:0]*in1[7:0]):
						  'bz;

	assign Z = ~|out;
	assign N = out[NN-1];
	assign V = (out[NN-1]&~in0[NN-1]&~in1[NN-1]) || (~out[NN-1]&in0[NN-1]&in1[NN-1]);
	
endmodule
module Tristate #(parameter N = 16) (in,oe,out);

	input [N-1:0] in;
	input oe;
	
	output [N-1:0] out;
	
	assign out = oe?in:'bz;

endmodule
