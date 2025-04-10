/******************************************************************************/
//	Filename:		SAYAC_shiftReg_17b.v
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

module shiftReg_17b(serIn, sh_L_en, dataIn, dataOut, Ld, clk, rst,
					init, serOut);
  input 	    sh_L_en,init;
  input         serIn;
  input  [16:0] dataIn;
  input 	    clk,rst,Ld;
  output [16:0] dataOut;
  output 		serOut;
  wire 			serOut;
  reg 	 [16:0] 	dataOut;
  
  always @(posedge clk,posedge rst) begin
    if(rst)
      {dataOut} <= 17'd0;
    else if(init)
      dataOut   <= 17'd0;
    else if(Ld)
      dataOut   <= dataIn;
    else if(sh_L_en) begin
      {dataOut} <= {dataOut,serIn};
    end
    else
      dataOut   <= dataOut;
  end
  
  assign serOut  =  dataOut[16];
  
endmodule