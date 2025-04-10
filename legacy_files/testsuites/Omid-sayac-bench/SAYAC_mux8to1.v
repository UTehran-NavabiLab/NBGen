/******************************************************************************/
//	Filename:		SAYAC_mux8to1.v
//	Project:		SAYAC : Simple Architecture Yet Ample Circuitry
//  Version:		0.900
//	History:
//	Date:			19 April 2021
//	Last Author: 	Helia
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

module mux8to1(d1, d2 ,d3, d4, d5, d6, d7, d8, sel, dout);
  input [15:0] d1, d2 ,d3, d4, d5, d6, d7, d8;
  input [7:0] sel;
 
  output reg [15:0] dout;
 
  always @(*)begin
    case(sel)
      8'b10000000 : dout <= d1;
      8'b01000000 : dout <= d2;
      8'b00100000 : dout <= d3;
      8'b00010000 : dout <= d4;
      8'b00001000 : dout <= d5;
      8'b00000100 : dout <= d6;
      8'b00000010 : dout <= d7;
      8'b00000001 : dout <= d8;
      default : dout <= 16'b0; 
    endcase

  end
endmodule
