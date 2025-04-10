/******************************************************************************/
//	Filename:		SAYAC_TRF.v
//	Project:		SAYAC : Simple Architecture Yet Ample Circuitry
//  Version:		0.920
//	History:
//	Date:			31 May 2021
//	Last Author: 	Helia
//  Copyright (C) 2021 University of Teheran
//  This source file may be used and distributed without
//  restriction provided that this copyright statement is not
//  removed from the file and that any derivative work contains
//  the original copyright notice and the associated disclaimer.
//

/******************************************************************************/
//	File content description:
//	The Register File (TRF) of the SAYAC core                                 
/******************************************************************************/

module 	TRF (clk, rst, writeRegFile, write_data, rs1, rs2, rd, p1, 
			p2, enFlag, inFlag, outFlag);

		input 			clk, rst, writeRegFile, enFlag;
		input [15:0] 	write_data;
		input [3:0] 	rs1, rs2, rd;
		input [7:0]		inFlag;
		output[15:0] 	p1, p2;
		output[7:0]     outFlag;
  
		reg   [15:0]    register_file [0:31];
		integer i;
		wire EN1, EN2;
	//	mux2to1 #(16) muxp1(register_file[rs1], 16'd0, !(rs1 == 4'b0), ((rs1 == 4'b0)), p1);
	//	mux2to1 #(16) muxp2(register_file[rs2], 16'd0, !(rs2 == 4'b0), ((rs2 == 4'b0)), p2);
		assign p1 = (rs1 == 4'b0) ? 16'd0 : register_file[rs1];
		assign p2 = (rs2 == 4'b0) ? 16'd0 : register_file[rs2];
		
		//assign EN1 = |rs1 ; 
		//assign EN2 = |rs2 ;
  
		always @(posedge clk) begin
			if (rst == 1'b1) begin 
				for (i=0; i<16 ; i=i+1 )
					register_file[i] <= 16'd0;
			end
			else if (writeRegFile == 1'b1) begin
				 if (rd != 4'd0)
					register_file[rd] <= write_data;
			end
		end
	////////////FLAGS//////////////////
	/*	genvar j;
		generate
			for(j = 0; j<8; j = j+1)
			begin 
				DFF ins(clk, rst, enFlag, inFlag[j], outFlag[j], 
				selFlag[j]);
			end
		endgenerate*/

		DFF_E ins0(clk, rst, enFlag, inFlag[0], outFlag[0]);
		DFF_E ins1(clk, rst, enFlag, inFlag[1], outFlag[1]);
		DFF_E ins2(clk, rst, enFlag, inFlag[2], outFlag[2]);
		DFF_E ins3(clk, rst, enFlag, inFlag[3], outFlag[3]);
		DFF_E ins4(clk, rst, enFlag, inFlag[4], outFlag[4]);
		DFF_E ins5(clk, rst, enFlag, inFlag[5], outFlag[5]);
		DFF_E ins6(clk, rst, enFlag, inFlag[6], outFlag[6]);
		DFF_E ins7(clk, rst, enFlag, inFlag[7], outFlag[7]);


endmodule

module DFF_E(clk, rst, en, in, out);
	input      clk, rst;
	input      en, in;
	output reg out;
	
	always@(posedge clk, posedge rst)begin
		if(rst == 1)
			out <= 0;
		else begin
		if(en == 1)
			out <= in;
		end
	end
endmodule

/*module mux2to1 #(parameter N = 16)(in1, in2, sel1, sel2, outMUX);
input	[N-1:0] in1, in2;
input 			sel1, sel2; 
output	[N-1:0] outMUX;

assign outMUX = (sel1)? in1:
				(sel2)? in2:
				{(N){1'b0}};
endmodule*/
