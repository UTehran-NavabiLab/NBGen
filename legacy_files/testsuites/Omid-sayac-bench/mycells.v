 //Verilog Library for Test Applications
 /////////////////////////////////////////////////////////////////////////////////////
 //    Buf
 /////////////////////////////////////////////////////////////////////////////////////
 
 `timescale 1 ns / 1ns
 
 module bufg #(parameter tphl = 1, tplh = 1)
     (out,in);               
 input in;
 output out;
  
	bufif1 #(tplh, tphl) inst(out, in, 1'b1);
    
 endmodule

 /////////////////////////////////////////////////////////////////////////////////////
 //    Not
 /////////////////////////////////////////////////////////////////////////////////////
 
 `timescale 1 ns / 1ns
 
 module notg #(parameter tphl = 1, tplh = 1)
     (out,in);             
 input in;
 output out;
  
	not #(tplh, tphl) inst (out, in);
    
 endmodule

 /////////////////////////////////////////////////////////////////////////////////////
 //    And: Parametrized on the number of inputs      
 /////////////////////////////////////////////////////////////////////////////////////
 
 `timescale 1 ns / 1ns
 
module and_n
    #(parameter n = 2, tphl = 1, tplh = 1)
    (out,in);           
input [n-1:0] in;
output out;
wire [n-2:0] mwire;

genvar i;

	and and_0 (mwire [0], in [0], in [1]);

  generate
    for (i=1; i <= n-2; i=i+1) begin : AND_N
       and inst (mwire [i], mwire [i-1], in [i+1]);
    end
  endgenerate
	bufif1 #(tplh, tphl) inst(out, mwire [n-2], 1'b1);	
	
endmodule

/////////////////////////////////////////////////////////////////////////////////////
//    Or: Parametrized on the number of inputs       
/////////////////////////////////////////////////////////////////////////////////////

`timescale 1 ns / 1ns
 
module or_n
    #(parameter n = 2, tphl = 1, tplh = 1)
    (out,in);             
input [n-1:0] in;
output out;
wire [n-2:0] mwire;

genvar i;

	or or_0 (mwire [0], in [0], in [1]);

  generate
    for (i=1; i <= n-2; i=i+1) begin : OR_N
       or inst (mwire [i], mwire [i-1], in [i+1]);
    end
  endgenerate
	bufif1 #(tplh, tphl) inst(out, mwire [n-2], 1'b1);	
   
endmodule

/////////////////////////////////////////////////////////////////////////////////////
//    Nand: Parametrized on the number of inputs       
/////////////////////////////////////////////////////////////////////////////////////

`timescale 1 ns / 1ns
 
module nand_n
    #(parameter n = 2, tphl = 1, tplh = 1)
    (out,in);               
input [n-1:0] in;
output out;
wire [n-2:0] mwire;

genvar i;

	and and_0 (mwire [0], in [0], in [1]);

  generate
    for (i=1; i <= n-2; i=i+1) begin : NAND_N
       and inst (mwire [i], mwire [i-1], in [i+1]);
    end
  endgenerate
	not #(tplh, tphl) inst(out, mwire [n-2]);	

endmodule

/////////////////////////////////////////////////////////////////////////////////////
//    Nor: Parametrized on the number of inputs       
/////////////////////////////////////////////////////////////////////////////////////

`timescale 1 ns / 1ns
 
module nor_n
    #(parameter n = 2, tphl = 1, tplh = 1)
    (out,in);              
input [n-1:0] in;
output out;
wire [n-2:0] mwire;

genvar i;

	or nor_0 (mwire [0], in [0], in [1]);

  generate
    for (i=1; i <= n-2; i=i+1) begin : NOR_N
       or inst (mwire [i], mwire [i-1], in [i+1]);
    end
  endgenerate
	not #(tplh, tphl) inst(out, mwire [n-2]);	
      
endmodule

/////////////////////////////////////////////////////////////////////////////////////
//    Xor: Parametrized on the number of inputs       
/////////////////////////////////////////////////////////////////////////////////////

`timescale 1 ns / 1ns
 
module xor_n
    #(parameter n = 2, tphl = 1, tplh = 1)
    (out,in);              
input [n-1:0] in;
output out;
wire [n-2:0] mwire;

genvar i;

	xor xor_0 (mwire [0], in [0], in [1]);

  generate
    for (i=1; i <= n-2; i=i+1) begin : XOR_N
       xor inst (mwire [i], mwire [i-1], in [i+1]);
    end
  endgenerate
	bufif1 #(tplh, tphl) inst(out, mwire [n-2], 1'b1);	
   
endmodule

/////////////////////////////////////////////////////////////////////////////////////
//    Xnor: Parametrized on the number of inputs       
/////////////////////////////////////////////////////////////////////////////////////

`timescale 1 ns / 1ns
 
module xnor_n
    #(parameter n = 2, tphl = 1, tplh = 1)
    (out,in);              
input [n-1:0] in;
output out;
wire [n-2:0] mwire;

genvar i;

	xor xnor_0 (mwire [0], in [0], in [1]);

  generate
    for (i=1; i <= n-2; i=i+1) begin : XNOR_N
       xor inst (mwire [i], mwire [i-1], in [i+1]);
    end
  endgenerate
	not #(tplh, tphl) inst(out, mwire [n-2]);	
    
endmodule

/////////////////////////////////////////////////////////////////////////////////////
//    Fan_Out: Parametrized on the number of inputs       
/////////////////////////////////////////////////////////////////////////////////////

`timescale 1 ns / 1ns
 
module fanout_n
    #(parameter n = 2,tphl = 3, tplh = 5)
    (in, out);
input in;
output [n-1 :0] out;
genvar i;

  generate
    for (i=0; i < n; i=i+1) begin : fanout
       bufif1 #(tplh, tphl) inst (out [i], in, 1'b1);
    end
  endgenerate		
   
endmodule

/////////////////////////////////////////////////////////////////////////////////////
//    Primary Input      
/////////////////////////////////////////////////////////////////////////////////////

`timescale 1 ns / 1ns
 
module pin #(parameter n = 1)
    (in, out);
input [n-1:0] in;
output [n-1:0] out;

genvar i;

  generate
    for (i=0; i < n; i=i+1) begin : PI
       bufif1 inst (out [i], in[i], 1'b1);
    end
  endgenerate

endmodule

/////////////////////////////////////////////////////////////////////////////////////
//    Primary Output      
/////////////////////////////////////////////////////////////////////////////////////

`timescale 1 ns / 1ns
 
module pout #(parameter n = 1)
    (in, out);
input [n-1:0] in;
output [n-1:0] out;

genvar i;

  generate
    for (i=0; i < n; i=i+1) begin : PO
       bufif1 inst (out [i], in[i], 1'b1);
    end
  endgenerate
   
endmodule

/////////////////////////////////////////////////////////////////////////////////////
//    D Flip Flop 
/////////////////////////////////////////////////////////////////////////////////////
module dff 
#(parameter tphl = 0, tplh = 0)
(Q, D, C, CLR, PRE, CE, NbarT, Si, global_reset); 

input D, C, CLR, PRE, CE, NbarT, Si, global_reset; 
output reg Q; 
reg val; 


always @(posedge C or posedge PRE or posedge CLR or posedge global_reset) begin
	if(CLR || global_reset)
		val = 1'b0;
	else	if(PRE)
		val = 1'b1;
	else	if(NbarT)
		val = Si; 
	else	if(CE)	val = D; 
end
   
always@(posedge val) #tplh Q =  val;
always@(negedge val) #tphl Q =  val;    
endmodule



module DFF (C, D, Q);
  
  input C, D;
  output Q;
  wire CE, NbarT, Si, global_reset;
  dff #(.tphl (0),.tplh (0)) _TECHMAP_REPLACE_ (
    .Q(Q), 
    .D(D), 
    .C(C), 
    .CLR(1'b0), 
    .PRE(1'b0), 
    .CE(1'b1), 
    .NbarT(1'b0), 
    .Si(Si), 
    .global_reset(1'b0)
  ); 
endmodule

module DFF_N (C, D, Q);
  
  input C, D;
  output Q;
  wire CE, NbarT, Si, global_reset;
  wire Cbar;

  assign Cbar = ~C;

  dff #(.tphl (0),.tplh (0)) _TECHMAP_REPLACE_ (
    .Q(Q), 
    .D(D), 
    .C(Cbar), 
    .CLR(1'b0), 
    .PRE(1'b0), 
    .CE(1'b1), 
    .NbarT(1'b0), 
    .Si(Si), 
    .global_reset(1'b0)
  ); 
endmodule


module DFF_PP0 (D, C, R, Q);
input D, C, R;
output  Q;
wire CE, NbarT, Si, global_reset;
  dff #(.tphl (0),.tplh (0)) _TECHMAP_REPLACE_ (
    .Q(Q), 
    .D(D), 
    .C(C), 
    .CLR(R), 
    .PRE(1'b0), 
    .CE(1'b1), 
    .NbarT(1'b0), 
    .Si(Si), 
    .global_reset(1'b0)
  ); 
endmodule

module DFF_PP1 (D, C, R, Q);
input D, C, R;
output  Q;
wire CE, NbarT, Si, global_reset;
  dff #(.tphl (0),.tplh (0)) _TECHMAP_REPLACE_ (
    .Q(Q), 
    .D(D), 
    .C(C), 
    .CLR(1'b0), 
    .PRE(R), 
    .CE(1'b1), 
    .NbarT(1'b0), 
    .Si(Si), 
    .global_reset(1'b0)
  ); 
endmodule


module DFF_PN0 (D, C, R, Q);
input D, C, R;
output  Q;
wire CE, NbarT, Si, global_reset;
wire Rbar;

assign Rbar = ~R;

  dff #(.tphl (0),.tplh (0)) _TECHMAP_REPLACE_ (
    .Q(Q), 
    .D(D), 
    .C(C), 
    .CLR(Rbar), 
    .PRE(1'b0), 
    .CE(1'b1), 
    .NbarT(1'b0), 
    .Si(Si), 
    .global_reset(1'b0)
  ); 
endmodule

module DFF_PN1 (D, C, R, Q);
input D, C, R;
output  Q;
wire CE, NbarT, Si, global_reset;
wire Rbar;

assign Rbar = ~R;

  dff #(.tphl (0),.tplh (0)) _TECHMAP_REPLACE_ (
    .Q(Q), 
    .D(D), 
    .C(C), 
    .CLR(1'b0), 
    .PRE(Rbar), 
    .CE(1'b1), 
    .NbarT(1'b0), 
    .Si(Si), 
    .global_reset(1'b0)
  ); 
endmodule

module DFF_NN0 (D, C, R, Q);
input D, C, R;
output  Q;
wire CE, NbarT, Si, global_reset;
wire Cbar, Rbar;

assign Cbar = ~C;
assign Rbar = ~R;

  dff #(.tphl (0),.tplh (0)) _TECHMAP_REPLACE_ (
    .Q(Q), 
    .D(D), 
    .C(Cbar), 
    .CLR(Rbar), 
    .PRE(1'b0), 
    .CE(1'b1), 
    .NbarT(1'b0), 
    .Si(Si), 
    .global_reset(1'b0)
  ); 
endmodule

module DFF_NN1 (D, C, R, Q);
input D, C, R;
output  Q;
wire CE, NbarT, Si, global_reset;
wire Cbar, Rbar;

assign Cbar = ~C;
assign Rbar = ~R;

  dff #(.tphl (0),.tplh (0)) _TECHMAP_REPLACE_ (
    .Q(Q), 
    .D(D), 
    .C(Cbar), 
    .CLR(1'b0), 
    .PRE(Rbar), 
    .CE(1'b1), 
    .NbarT(1'b0), 
    .Si(Si), 
    .global_reset(1'b0)
  ); 
endmodule

module DFF_NP0 (D, C, R, Q);
input D, C, R;
output  Q;
wire CE, NbarT, Si, global_reset;
wire Cbar;

assign Cbar = ~C;

  dff #(.tphl (0),.tplh (0)) _TECHMAP_REPLACE_ (
    .Q(Q), 
    .D(D), 
    .C(Cbar), 
    .CLR(R), 
    .PRE(1'b0), 
    .CE(1'b1), 
    .NbarT(1'b0), 
    .Si(Si), 
    .global_reset(1'b0)
  ); 
endmodule

module DFF_NP1 (D, C, R, Q);
input D, C, R;
output  Q;
wire CE, NbarT, Si, global_reset;
wire Cbar;

assign Cbar = ~C;

  dff #(.tphl (0),.tplh (0)) _TECHMAP_REPLACE_ (
    .Q(Q), 
    .D(D), 
    .C(Cbar), 
    .CLR(1'b0), 
    .PRE(R), 
    .CE(1'b1), 
    .NbarT(1'b0), 
    .Si(Si), 
    .global_reset(1'b0)
  ); 
endmodule

module DFF_E (C, R, E, Q);
input E, C, R;
output  Q;
wire CE, NbarT, Si, global_reset;

  dff #(.tphl (0),.tplh (0)) _TECHMAP_REPLACE_ (
    .Q(Q), 
    .D(Q), 
    .C(C), 
    .CLR(R), 
    .PRE(1'b0), 
    .CE(E), 
    .NbarT(1'b0), 
    .Si(Si), 
    .global_reset(1'b0)
  ); 
endmodule


/////////////////////////////////////////////////////////////////////////////////////
//    latch
/////////////////////////////////////////////////////////////////////////////////////


module \$_DLATCH_P_ (E, D, Q);

parameter WIDTH = 1;
parameter E_POLARITY = 1'b1;

input E;
input [WIDTH-1:0] D;
output reg [WIDTH-1:0] Q;

always @* begin
        if (E == E_POLARITY)
                Q = D;
end

endmodule
