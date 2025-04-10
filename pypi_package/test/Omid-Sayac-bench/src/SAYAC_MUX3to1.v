/******************************************************************************/
//	Filename:		SAYAC_MUX2to1.v
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
module mux3to1 #(parameter N = 16)(in1, in2, in3, sel1, sel2, sel3, outMUX);

input  [N-1:0] in1, in2, in3;
input          sel1, sel2, sel3; 

output [N-1:0] outMUX;

assign outMUX = (sel1)? in1:
                (sel2)? in2:
                (sel3)? in3:
                {(N){1'b0}};
endmodule
