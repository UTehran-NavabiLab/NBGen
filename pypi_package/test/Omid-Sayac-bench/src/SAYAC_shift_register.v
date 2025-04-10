/******************************************************************************/
//	Filename:		SAYAC_shift_register.v
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

module shift_register #( parameter size = 4)
                       ( input  [size-1:0] in, 
                         input             ldR,  //Load Enable 
                         input             shrR, //Shift right enable 
                         input             seiR, //Serial in 
                         input             clk, 
                         input             rst,  //Sync reset 
                         output reg        seoR, //Serial out 
                         output [size-1:0] out); 

    reg [size-1:0] Rreg;
    assign out = Rreg;
    
    always @ (posedge clk, posedge rst) begin: RREG
        if(rst)
            Rreg = {(size){1'b0}};
        else begin if(ldR)
            Rreg = in;
        if(shrR)
            {Rreg, seoR} = {seiR, Rreg[size-1:0]};
        end
    end
    
endmodule