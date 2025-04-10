/******************************************************************************/
//	Filename:		SAYAC_IMM.v
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

module IMM(in1, in2, SE5bits, SE6bits, USE8bits, SE8bits, p1lowbits, outIMM);
  
  input  [7:0]  in1, in2;
  output [15:0] outIMM;
  input         SE6bits, USE8bits, SE8bits, SE5bits, p1lowbits;
/*
  always @(*) begin
	if(SE5bits) outIMM <= {{11{in1[4]}}, in1[4:0]};
	else if(SE6bits) outIMM <= {{10{in1[5]}}, in1[5:0]};
	else if(SE8bits) outIMM <= {{8{in1[7]}}, in1[7:0]};
	else if(USE8bits) outIMM <= {{8'b0}, in1[7:0]};
	else if(p1lowbits) outIMM <= {in1, in2};
	else outIMM <= 16'b0;
  end*/
  assign outIMM = (SE5bits)  ? {{11{in1[4]}}, in1[4:0]} :
                  (SE6bits)  ? {{10{in1[5]}}, in1[5:0]} :
                  (SE8bits)  ? {{8{in1[7]}}, in1[7:0]}  :
                  (USE8bits) ? {{8'b0}, in1[7:0]}       : 
                  (p1lowbits)? {in1, in2}               : 16'b0;
                          
endmodule
