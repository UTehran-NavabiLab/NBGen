/******************************************************************************/
//	Filename:		SAYAC_adder_subtractor.v
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

module adder_subtractor #( parameter size = 4) (a, b, subsel, cout, out);

    input	  [size-1:0] a;
    input	  [size-1:0] b; 
    input                subsel;
    output               cout; 
    output    [size-1:0] out ; 
    wire 	  [size-1:0] b_sel;
	
    assign b_sel = (subsel) ? {~b} : {b};
    adder #(size) adder_1 (a, b_sel, subsel, cout, out);
	
endmodule
