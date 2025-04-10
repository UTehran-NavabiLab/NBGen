 			  /******************************************************************************/
//	Filename:		SAYAC_Counter.v
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

module Counter #(parameter N = 16)(dataOut, initValue, co, incCnt, iniCnt, clk, rst);
  input          clk, rst, incCnt, iniCnt;
  input  [N-1:0] initValue;
  output [N-1:0] dataOut;
  output         co;
  reg    [N-1:0] dataOut;
  always @(posedge clk, posedge rst) begin
    if(rst == 1)
      dataOut <=  {(N){1'b0}};
    else if(iniCnt)
      dataOut <=  initValue;
    else if(incCnt)
      dataOut <=  dataOut + 1;
    else
      dataOut <=  dataOut;
  end
  
  assign co = &{dataOut};
endmodule
