/******************************************************************************/
//	Filename:		SAYAC_LLU.v
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

module LLU(in1, in2, logicAND, onescomp, twoscomp, outLLU);
  
  input  [15:0] in1, in2;
  output [15:0] outLLU;
  input         logicAND, onescomp, twoscomp;
/*
	always @(*) begin
		if(logicAND) outLLU <= in1 & in2;
		else if(onescomp) outLLU <= ~(in1);
		else if(twoscomp) outLLU <= ~(in1) + 16'd1;
		else outLLU <= 16'b0;
	end
  */
  assign outLLU = (logicAND) ? in1 & in2      :
                  (onescomp) ? ~(in1)         :
                  (twoscomp) ? ~(in1) + 16'd1 : 16'b0;
                           
endmodule
