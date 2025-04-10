/******************************************************************************/
//	Filename:		SAYAC_SHU.v
//	Project:		SAYAC : Simple Architecture Yet Ample Circuitry
//  Version:		0.900
//	History:
//	Date:			20 April 2021
//	Last Author: 	Milad Azimi Fashi
//  Copyright (C) 2021 University of Teheran
//  This source file may be used and distributed without
//  restriction provided that this copyright statement is not
//  removed from the file and that any derivative work contains
//  the original copyright notice and the associated disclaimer.
//

/******************************************************************************/
//	File content description:
//	                              
/******************************************************************************/
`timescale 1ns/1ns

module SHU(in1, in2, logicSH, arithSH, outSHU);
  
	input  [15:0] in1;
	input  [4:0]  in2;
	output [15:0] outSHU;
	input         logicSH, arithSH;
  /*
	always @(*) begin
		if({in2[4], logicSH, arithSH} == 3'b001) outSHU <= in1 >>> in2;
		else if({in2[4], logicSH, arithSH} == 3'b010) outSHU <= in1 >>  in2;
		else if({in2[4], logicSH, arithSH} == 3'b101) outSHU <= in1 <<< (~(in2) + 5'b1);
		else if({in2[4], logicSH, arithSH} == 3'b110) outSHU <= (~(in2) + 5'b1);
		else outSHU <= 16'b0;
	end
  */
  assign outSHU = ({in2[4], logicSH, arithSH} == 3'b001) ? in1 >>> in2 :                      // arithmetic right shift
                  ({in2[4], logicSH, arithSH} == 3'b010) ? in1 >>  in2 :                      // logical right shift
                  ({in2[4], logicSH, arithSH} == 3'b101) ? in1 <<< (~(in2) + 5'd1) :          // arithmetic left shift
                  ({in2[4], logicSH, arithSH} == 3'b110) ? in1 <<  (~(in2) + 5'd1) : 16'b0;   // logical left shift
                          
endmodule
