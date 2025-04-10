/******************************************************************************/
//	Filename:		SAYAC_register_file.v
//	Project:		SAYAC : Simple Architecture Yet Ample Circuitry
//  Version:		0.900
//	History:
//	Date:			15 April 2021
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
module REG #(parameter N = 16)(inREG, outREG, ld, clk, rst);

  input 	 [N-1:0] inREG;
  input 			 clk, rst, ld;
  output reg [N-1:0] outREG;
  
  always @(posedge clk, posedge rst) begin
    if(rst)
      outREG <= 0;
    else if(ld)
      outREG <= inREG;
  end
  
endmodule


