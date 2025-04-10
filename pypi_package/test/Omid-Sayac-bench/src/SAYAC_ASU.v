/******************************************************************************/
//	Filename:		SAYAC_ASU.v
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

module ASU(in1, in2, arithADD, arithSUB, outASU);
  input		[15:0] in1,in2;
  output	[15:0] outASU;
  input 	       arithADD, arithSUB;
  wire 		[15:0] addout, subout;
  wire 				coutA, coutS;
  assign outASU = (arithADD)? addout:((arithSUB)? subout:16'b0);
  adder1 #(16) ASUADDER (in1, in2, 1'b0, coutA, addout);
  adder1 #(16) ASUSUBTR (in1, -in2, 1'b0, coutS, subout);
endmodule


module adder1 #( parameter size = 16)( a, b, cin, cout, sum); 
                
	  input  [size-1:0] a;
	  input  [size-1:0] b; 
      input             cin; 
      output            cout;
      output [size-1:0] sum;
       wire    Co_0,Co_1 ,Co_2,Co_3,Co_4,Co_5,Co_6,Co_7,Co_8,Co_9,Co_10,Co_11,Co_12,Co_13,Co_14,Co_15; 
      FA FA0 (a[0], b[0], cin, Co_0, sum[0]) ;
      FA FA1 (a[1], b[1], Co_0, Co_1, sum[1]) ;
      FA FA2 (a[2], b[2], Co_1, Co_2, sum[2]) ;
      FA FA3 (a[3], b[3], Co_2, Co_3, sum[3]) ;
      FA FA4 (a[4], b[4], Co_3, Co_4, sum[4]) ;
      FA FA5 (a[5], b[5], Co_4, Co_5, sum[5]) ;
      FA FA6 (a[6], b[6], Co_5, Co_6, sum[6]) ;
      FA FA7 (a[7], b[7], Co_6, Co_7, sum[7]) ;
      FA FA8 (a[8], b[8], Co_7, Co_8, sum[8]) ;
      FA FA9 (a[9], b[9], Co_8, Co_9, sum[9]) ;
      FA FA10 (a[10], b[10], Co_9, Co_10, sum[10]) ;
      FA FA11 (a[11], b[11], Co_10, Co_11, sum[11]) ;
      FA FA12 (a[12], b[12], Co_11, Co_12, sum[12]) ;
      FA FA13 (a[13], b[13], Co_12, Co_13, sum[13]) ;
      FA FA14 (a[14], b[14], Co_13, Co_14, sum[14]) ;
      FA FA15 (a[15], b[15], Co_14, cout, sum[15]) ;
	  

endmodule

module FA(input A, B, Cin, output  Co, S);

	assign S= (A ^ B) ^ Cin;
	assign Co= ((A ^ B) & Cin) | (A & B);
endmodule


/*module ASUtb();
  reg	[15:0] in1,in2;
  wire	[15:0] outASU;
  reg 		   arithADD;
  reg		   arithSUB;
  
  ASU MUT(in1, in2, arithADD, arithSUB, outASU);
  
  initial begin
    arithADD = 1;
    arithSUB = 0;
    #10;
    in1 = 16'd5;
    in2 = 16'd9;
    #50;
    in1 = 16'd10;
    in2 = 16'd7;
    arithADD = 0;
    arithSUB = 1;
    #100 $stop;
  end
  
endmodule*/
    
            
            
