/******************************************************************************/
//	Filename:		SAYAC_adder.v
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

`timescale 1ns / 1ns
module adder #( parameter size = 4)( a, b, cin, cout, sum); 
                
	  input  [size-1:0] a;
	  input  [size-1:0] b; 
      input             cin; 
      output            cout;
      output [size-1:0] sum;
                
      assign {cout,sum} = a + b + cin;               

endmodule
