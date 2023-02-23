module Puneh_Top (input clk, rst, input [15:0]dataBus, output readMEM, writeMEM, output [15:0]addrBus, dataBus_out);
	
	wire selPC_OF, selIMM_OF, ldOF, ldIR, SE4bits, SE12bits, conOF, 
        selIMM_AC, selMEM_AC, selARU_AC, selLGU_AC, ldAC, zeroAC, selIMM_LGU,
	     selMEM_LGU, sel1_ARU, selMO_ARU, AND, NOT, ADD, MUL,ldPC, selINC_PC,
 		  selMEM_PC, selIMM_PC, selINC_IN, selMEM_IN, ldIN, selIN_MEM, selPC_MEM,
	     selAC_MEM, selIR_MEM, seldataBus, selSET_SR, selCAL_SR, INC1, INC2, Z,
		  N, C, V, enSKP; 
	wire [1:0]SHF;
	wire [3:0]ldSR;
	wire [15:0] IR_out_cont;

	Puneh_DP U1 (clk,rst, selPC_OF, selIMM_OF, ldOF, ldIR, SE4bits, SE12bits, conOF, 
                selIMM_AC, selMEM_AC, selARU_AC, selLGU_AC, ldAC, zeroAC, selIMM_LGU,
				    selMEM_LGU, sel1_ARU, selMO_ARU, AND, NOT, ADD, MUL, ldPC, selINC_PC,
 					 selMEM_PC, selIMM_PC, selINC_IN, selMEM_IN, ldIN, selIN_MEM, selPC_MEM,
					 selAC_MEM, selIR_MEM, seldataBus, selSET_SR, selCAL_SR, INC1, INC2,SHF,
					 ldSR,dataBus, Z, N, C, V, enSKP, addrBus, IR_out_cont, dataBus_out);

	Puneh_C  U2 (clk, rst, enSKP, IR_out_cont, readMEM, writeMEM,selPC_OF, 
					 selIMM_OF, ldOF, ldIR, SE4bits, SE12bits, conOF, selIMM_AC, selMEM_AC,
				 	 selARU_AC, selLGU_AC, ldAC, zeroAC, selIMM_LGU, selMEM_LGU, sel1_ARU,
					 selMO_ARU, AND, NOT, ADD, MUL, selINC_PC, selMEM_PC, selIMM_PC, INC1, INC2,
					 ldPC, selINC_IN, selMEM_IN, ldIN, selIN_MEM, selPC_MEM, selAC_MEM,seldataBus,
					 selIR_MEM, selSET_SR, selCAL_SR, SHF, ldSR);

endmodule



module Puneh_DP(input clk, rst, selPC_OF, selIMM_OF, ldOF, ldIR, SE4bits, SE12bits, conOF, 
                      selIMM_AC, selMEM_AC, selARU_AC, selLGU_AC, ldAC, zeroAC, selIMM_LGU,
						    selMEM_LGU, sel1_ARU, selMO_ARU, AND, NOT, ADD, MUL,ldPC, selINC_PC,
 							 selMEM_PC, selIMM_PC, selINC_IN, selMEM_IN, ldIN, selIN_MEM, selPC_MEM,
							 selAC_MEM, selIR_MEM, seldataBus, selSET_SR, selCAL_SR, INC1, INC2,
							 input [1:0]SHF, input [3:0]ldSR, input [15:0]dataBus,
						    output reg Z, N, C, V, enSKP, output reg [15:0]addrBus, IR_out_cont, dataBus_out);

	reg Z_out1, Z_out2, Z_out3, N_out1, N_out2, N_out3, C_out1, C_out2, C_out3, V_out1, V_out2, V_out3;
	reg [3:0]OF_out, mux_OF_out, mux_flags_out, exp, obs;
	reg [15:0]PC_out, IMM_out, LGU_out, ARU_out, mux_AC_out, AC_out, MO, mux_ARU_out, INC_PC_out,
					INC_IN_out, mux_PC_out, mux_IN_out, IN_out, mux_dataBus_out, mux_addrBus_out, tristate_out, IR_out;

//OF
	always @(posedge clk, posedge rst) begin
		if(rst)
			OF_out <= 4'b0;
		else
			if(ldOF)
				OF_out <= mux_OF_out;
	end

	assign mux_OF_out = selIMM_OF ? IMM_out[3:0] :
							  selPC_OF  ?  PC_out[15:12] : 4'bz;
	
//IR
	always @(posedge clk, posedge rst) begin
		if(rst)
			IR_out <= 16'b0;
		else 
			if(ldIR)
				IR_out <= dataBus;
	end

//IMM
	always @(conOF, OF_out, IR_out[11:0], SE12bits, SE4bits) begin
			IMM_out = 16'd0;
			if(SE4bits)
				IMM_out <= {IR_out[11], IR_out[11], IR_out[11], IR_out[11], IR_out[11:0]};
			else if(SE12bits)
				IMM_out <= {{12{IR_out[3]}}, IR_out[3:0]};
			else if(conOF)
				IMM_out <= {OF_out, IR_out[11:0]};
	end
//AC
	always @(posedge clk, posedge rst) begin
		if(rst)
			AC_out <= 16'b0;
		else 
			if(ldAC)
				AC_out <= mux_AC_out;
			else if(zeroAC)
				AC_out <= 16'b0;
	end

	assign mux_AC_out = selLGU_AC ? LGU_out:
							  selARU_AC ? ARU_out:
							  selMEM_AC ? dataBus:
							  selIMM_AC ? IMM_out: 16'bz;
//LGU
	always @(MO, AC_out, AND, NOT, SHF) begin
		LGU_out = 16'd0;
		if(AND)
			LGU_out = MO & AC_out;
		else if(NOT)
			LGU_out = ~MO;
		else if(SHF == 2'b00)
			LGU_out = MO >>> AC_out;
		else if(SHF == 2'b01)
			LGU_out = MO >> AC_out;
		else if(SHF == 2'b10)
			LGU_out = MO << AC_out;
	end
	assign N = LGU_out[15];
	assign Z = ~(| LGU_out);

	assign MO = selMEM_LGU ? dataBus:
				   selIMM_LGU ? IMM_out:16'bz;
//ARU
	always @(mux_ARU_out, AC_out, ADD, MUL) begin
		{C, ARU_out} = 17'd0;
		if(ADD)
			{C, ARU_out} <= mux_ARU_out + AC_out;
		else if(MUL)
			ARU_out = mux_ARU_out[7:0] * AC_out[7:0];
	end

	assign N = LGU_out[15];
	assign Z = ~(| LGU_out);
   assign V = (~mux_ARU_out[15] & ~AC_out[15] & ARU_out[15]) | (mux_ARU_out[15] & AC_out[15] & ~ARU_out[15]);
	
	assign mux_ARU_out = selMO_ARU ? MO:
								sel1_ARU  ? 16'd1: 16'bz;

//PC
	always @(posedge clk, posedge rst) begin
		if(rst)
			PC_out <= 16'b0;
		else 
			if (ldPC)
				PC_out <= mux_PC_out;
	end

	assign mux_PC_out = selIMM_PC ? IMM_out:
							  selMEM_PC ? dataBus:
							  selINC_PC ? INC_PC_out: 16'bz;
	
	assign INC_PC_out = INC1 ? PC_out + 16'd1:
                       INC2 ? PC_out + 16'd2:16'bz;

//IN
	always @(posedge clk, posedge rst) begin
		if(rst)
			IN_out <= 16'b0;
		else 
			if (ldIN)
				IN_out <= mux_IN_out;
	end

	assign mux_IN_out = selMEM_IN ? dataBus:
							  selINC_IN ? INC_IN_out: 16'bz;
	assign INC_IN_out = dataBus + 16'd1;

//flags
	assign mux_flags_out = selSET_SR ? {Z,N,C,V}:
								  selCAL_SR ? IR_out[3:0]:4'bz;

	always @(posedge clk, posedge rst) begin
		if(rst)
			Z_out1 <= 0;
		else
			if(ldSR[3])
				Z_out1 <= mux_flags_out [3];
	end

	always @(posedge clk, posedge rst) begin
		if(rst)
			N_out1 <= 0;
		else
			if(ldSR[2])
				N_out1 <= mux_flags_out [2];
	end

	always @(posedge clk, posedge rst) begin
		if(rst)
			C_out1 <= 0;
		else
			if(ldSR[1])
				C_out1 <= mux_flags_out [1];
	end

	always @(posedge clk, posedge rst) begin
		if(rst)
			V_out1 <= 0;
		else
			if(ldSR[0])
				V_out1 <= mux_flags_out [0];
	end

	assign exp = IR_out [3:0];
	assign obs = IR_out [7:4];
	
	assign {Z_out2, N_out2, C_out2, V_out2} = exp ~^ {Z_out1, N_out1, C_out1, V_out1}; 
	assign {Z_out3, N_out3, C_out3, V_out3} = obs & {Z_out2, N_out2, C_out2, V_out2}; 

	assign enSKP = Z_out2 | N_out2 | C_out2 | V_out2;
	
//output
	assign mux_dataBus_out = selAC_MEM ? AC_out:
									 selPC_MEM ? INC_PC_out:
									 selIN_MEM ? IN_out: 16'bz;

	assign tristate_out = seldataBus ? mux_dataBus_out : 16'bz;  
	assign dataBus_out = tristate_out;
	assign addrBus = selPC_MEM ? PC_out:
						  selIR_MEM ? IMM_out:
						  selIN_MEM ? IN_out: 16'bz;

	assign IR_out_cont = IR_out;

endmodule


module Puneh_C(input clk, rst, enSKP, input [15:0]IR_out_cont, output reg readMEM, writeMEM,selPC_OF, 
							selIMM_OF, ldOF, ldIR, SE4bits, SE12bits, conOF, selIMM_AC, selMEM_AC,
						   selARU_AC, selLGU_AC, ldAC, zeroAC, selIMM_LGU, selMEM_LGU, sel1_ARU,
						   selMO_ARU, AND, NOT, ADD, MUL, selINC_PC, selMEM_PC, selIMM_PC, INC1, INC2,
							ldPC, selINC_IN, selMEM_IN, ldIN, selIN_MEM, selPC_MEM, selAC_MEM,seldataBus,
							selIR_MEM, selSET_SR, selCAL_SR, output reg [1:0] SHF,output reg [3:0]ldSR);
	
	parameter [3:0] LDm = 4'b0000;
	parameter [3:0] LDa = 4'b0001;
	parameter [3:0] LDn = 4'b0010;
	parameter [3:0] STa = 4'b0011;
	parameter [3:0] STn = 4'b0100;
	parameter [3:0] INa = 4'b0101;
	parameter [3:0] ANm = 4'b0110;
	parameter [3:0] ANa = 4'b0111;
	parameter [3:0] ADm = 4'b1000;
	parameter [3:0] ADa = 4'b1001;
	parameter [3:0] ADn = 4'b1010;
	parameter [3:0] MLa = 4'b1011;
	parameter [3:0] JMa = 4'b1100;
	parameter [3:0] JMn = 4'b1101;
	parameter [3:0] JSR = 4'b1110;
	parameter [3:0] NAI = 4'b1111;	// no addr instruction 8 bit opcpde

	parameter [3:0] LOm = 4'b0000;   //					        8    
	parameter [3:0] op16= 4'b0001;	//       			     16
	parameter [3:0] SRA = 4'b0010;	//     			        8
	parameter [3:0] SLL = 4'b0011;	// 				        8
	parameter [3:0] SRL = 4'b0100;	//					        8
	parameter [3:0] SKP = 4'b0101;   //					        8   
	parameter [3:0] SET = 4'b0110;   // 					     8
 
	parameter [3:0] LPO = 4'b0000;  //                      16
	parameter [3:0] LOP = 4'b0001;  //                      16
	parameter [3:0] ACZ = 4'b0010;  //                      16
	parameter [3:0] ACN = 4'b0011;  //                      16
	parameter [3:0] ACI = 4'b0100;  //							  16

	parameter [3:0] Fetch = 4'b0000;
	parameter [3:0] Exec1 = 4'b0001;
	parameter [3:0] Exec2 = 4'b0010;

	reg [3:0] pstate, nstate;

	always @(pstate, IR_out_cont) begin
		nstate = 4'b0000;

		{readMEM, writeMEM,selPC_OF, 
		 selIMM_OF, ldOF, ldIR, SE4bits, SE12bits, conOF, selIMM_AC, selMEM_AC,
		 selARU_AC, selLGU_AC, ldAC, zeroAC, selIMM_LGU, selMEM_LGU, sel1_ARU,
		 selMO_ARU, AND, NOT, ADD, MUL, selINC_PC, selMEM_PC, selIMM_PC, INC1, INC2,
		 ldPC, selINC_IN, selMEM_IN, ldIN, selIN_MEM, selPC_MEM, selAC_MEM, seldataBus,
		 selIR_MEM, selSET_SR, selCAL_SR,SHF, ldSR} = 45'b0;
		
		case(pstate)
			Fetch : begin nstate = Exec1; {selPC_MEM, readMEM, ldIR} = 3'b111; end
			
			Exec1 : begin case(IR_out_cont[15:12])
									LDm : begin nstate = Fetch; {INC1, selINC_PC, ldPC, SE4bits, selIMM_AC, ldAC} = 6'b111111; end
									LDa : begin nstate = Fetch; {INC1, selINC_PC, ldPC, conOF, selIR_MEM, readMEM, selMEM_AC, ldAC} = 8'b11111111; end
									LDn : begin nstate = Exec2; {INC1, selINC_PC, ldPC, conOF, selIR_MEM, readMEM, selMEM_IN, ldIN} = 8'b11111111; end
									STa : begin nstate = Fetch; {INC1, selINC_PC, ldPC, conOF, selIR_MEM, selAC_MEM, seldataBus, writeMEM} = 8'b11111111; end
									STn : begin nstate = Exec2; {INC1, selINC_PC, ldPC, conOF, selIR_MEM, readMEM, selMEM_IN, ldIN} = 8'b11111111; end
									INa : begin nstate = Exec2; {INC1, selINC_PC, ldPC, conOF, selIR_MEM, readMEM, selINC_IN, ldIN} = 8'b11111111; end
								  	ANm : begin nstate = Fetch; {INC1, selINC_PC, ldPC, SE4bits, selIMM_LGU, AND, selLGU_AC, ldAC, selCAL_SR, ldSR} = 10'b1111111111; end
									ANa : begin nstate = Fetch; {INC1, selINC_PC, ldPC, conOF, selIR_MEM, readMEM, selMEM_LGU, AND, selLGU_AC, ldAC, selCAL_SR, ldSR} = 12'b111111111111; end
									ADm : begin nstate = Fetch; {INC1, selINC_PC, ldPC, SE4bits, selIMM_LGU, selMO_ARU, ADD, selARU_AC, ldAC, selCAL_SR, ldSR} = 11'b11111111111; end
								   ADa : begin nstate = Fetch; {INC1, selINC_PC, ldPC, conOF, selIR_MEM, readMEM, selMEM_LGU, selMO_ARU, ADD, selARU_AC, ldAC, selCAL_SR, ldSR} = 13'b1111111111111; end
									ADn : begin nstate = Exec2; {INC1, selINC_PC, ldPC, conOF, selIR_MEM, readMEM, selMEM_IN, ldIN, selCAL_SR, ldSR} = 10'b1111111111; end
									MLa : begin nstate = Fetch; {INC1, selINC_PC, ldPC, conOF, selIR_MEM, readMEM, selMEM_LGU, selMO_ARU, MUL, selARU_AC, ldAC, selCAL_SR, ldSR} = 13'b1111111111111; end
									JMa : begin nstate = Fetch; {conOF, selIMM_PC, ldPC} = 3'b111; end
									JMn : begin nstate = Fetch; {INC1, selINC_PC, ldPC, conOF, selIR_MEM, readMEM, selMEM_PC} = 7'b1111111; end
									JSR : begin nstate = Exec2; {conOF, selIR_MEM, INC1, selPC_MEM, seldataBus, writeMEM, selIMM_PC, ldPC} = 8'b11111111; end
									NAI : begin case(IR_out_cont[11:8])
														LOm : begin nstate = Fetch; {INC1, selINC_PC, ldPC, SE12bits, selIMM_OF, ldOF} = 6'b111111; end
														op16: begin case(IR_out_cont[7:0])
																		LPO : begin nstate = Fetch; {INC1, selINC_PC, ldPC, selPC_OF, ldOF} = 5'b11111; end
																		LOP : begin nstate = Fetch; {INC1, selINC_PC, ldPC, SE12bits, selIMM_PC, ldPC} = 6'b111111; end
																		ACZ : begin nstate = Fetch; {INC1, selINC_PC, ldPC, zeroAC, selCAL_SR, ldSR} = 6'b111111; end
																		ACN : begin nstate = Fetch; {INC1, selINC_PC, ldPC, NOT, selLGU_AC, ldAC, selCAL_SR, ldSR} = 8'b11111111; end
																		ACI : begin nstate = Fetch; {INC1, selINC_PC, ldPC, sel1_ARU, ADD, selARU_AC, ldAC} = 7'b1111111; end
																		default : begin nstate = Fetch; end
																		endcase 
																end
														SRA : begin nstate = Fetch; {INC1, selINC_PC, ldPC, SE12bits, selIMM_LGU, selLGU_AC, ldAC, SHF} = 9'b111111100; end
														SLL : begin nstate = Fetch; {INC1, selINC_PC, ldPC, SE12bits, selIMM_LGU, selLGU_AC, ldAC, SHF} = 9'b111111110; end
														SRL : begin nstate = Fetch; {INC1, selINC_PC, ldPC, SE12bits, selIMM_LGU, selLGU_AC, ldAC, SHF} = 9'b111111101; end
														SKP : begin nstate = Fetch; if(~enSKP) {INC2, selINC_PC, ldPC} = 3'b111; end
													 	SET : begin nstate = Fetch; {INC1, selINC_PC, ldPC, selSET_SR} = 4'b1111; end
													default : begin nstate = Fetch; end
													endcase
											end
							  default : begin nstate = Fetch; end
							  endcase					  
					  end

			Exec2 : begin case(IR_out_cont[15:12])
									LDn : begin nstate = Fetch; {selIN_MEM, readMEM, selMEM_AC, ldAC} = 4'b1111; end
									STn : begin nstate = Fetch; {selIN_MEM, selAC_MEM, seldataBus, writeMEM} = 4'b1111; end
									INa : begin nstate = Fetch; {conOF, selIR_MEM, selIN_MEM, seldataBus, writeMEM} = 5'b11111; end
									ADn : begin nstate = Fetch; {selIN_MEM, readMEM, selMEM_LGU, selMO_ARU, ADD, selARU_AC, ldAC} = 7'b1111111; end
									JSR : begin nstate = Fetch; {INC1, selINC_PC, ldPC} = 3'b111; end
									default : begin nstate = Fetch; end
							  endcase
					  end
			default : begin nstate = Fetch; end
		endcase	

		end

	always @(posedge clk, posedge rst)begin
		if(rst)
			pstate <= Fetch;
		else
			pstate <= nstate;
	end

endmodule