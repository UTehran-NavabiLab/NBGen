/******************************************************************************/
//	Filename:		SAYAC_MDU.v
//	Project:		SAYAC : Simple Architecture Yet Ample Circuitry
//  Version:		0.900
//	History:
//	Date:			8 June 2021
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
module MDU(clk, rst, arithMUL, arithDIV, ldMDU1, ldMDU2, in1, in2, 
		   outMDU1, outMDU2, readyMDU, doneMDU, startMDU);
		   
  input         clk, rst, arithMUL, arithDIV, ldMDU1, ldMDU2, startMDU;
  input  [15:0] in1, in2;
  output [15:0] outMDU1, outMDU2;
  output        readyMDU, doneMDU;
  
  //internal wires
  wire   [15:0] MDU1, MDU2;
  wire   [16:0] Devidend, Divisor, M, Q, Remainder, Quotient;
  wire   [33:0] P;
  wire          readyDIV, readyMUL, doneMUL, doneDIV;
  
  assign Devidend = {1'b0,in1};
  assign Divisor = {1'b0, in2};
  assign M = {1'b0,in1};
  assign Q = {1'b0, in2};
  
  assign MDU1 = (arithDIV) ? Quotient[15:0]:
                   (arithMUL) ? P[15:0]:
                   16'd0;
  assign MDU2 = (arithDIV) ? Remainder[15:0]:
                   (arithMUL) ? P[31:16]:
                   16'd0;           
  assign readyMDU = (arithDIV) ? readyDIV:
                    (arithMUL) ? readyMUL:
                    16'd0;     

  assign doneMDU = (arithDIV) ? doneDIV:
                   (arithMUL) ? doneMUL:
                    16'd0;     					
  divider div(Devidend, Divisor, startMDU, clk, rst, Quotient, Remainder, readyDIV, doneDIV);
  booth #(17) mult(M, Q, P, clk, rst, startMDU, doneMUL, readyMUL);
  REG #(16) reg1(MDU1, outMDU1, ldMDU1, clk, rst);
  REG #(16) reg2(MDU2, outMDU2, ldMDU2, clk, rst); 
  
endmodule  

module booth #( parameter size = 17)(M, Q, P, clk, rst, start, done, Ready);
  input		[size-1:0]   M, Q;
  input				     clk, rst;
  input 			 	 start; 
  output 			 	 done;
  output				 Ready;
  output 	[2*size-1:0] P;
  wire 		[1:0] 		 op;
  wire 					 shrQ;
  wire 					 ldQ;
  wire 					 ldM;
  wire                   ldP;
  wire                   clrP;
  wire                   sel;
  wire                   subsel;

  booth_datapath   #(size) DP (M, Q, P, clk, rst, op, shrQ, ldQ, ldM, ldP, clrP, sel, subsel); 
  booth_controller #(size) CU (start, Ready, done, clk, rst, op, shrQ, ldQ, ldM, ldP, clrP, sel, subsel);
  
endmodule


module booth_controller #( parameter size = 17)(start, Ready, done, clk, rst, op, 
                            shrQ, ldQ, ldM, ldP, clrP, sel, subsel); 
  input       start; 
  output reg  done; 
  input 	  clk;
  input       rst; 
  input [1:0] op;
  output reg  shrQ;
  output reg  ldQ;
  output reg  ldM; 
  output reg  ldP;
  output reg  clrP;
  output reg  sel;
  output reg  subsel;
  output reg  Ready;

 reg [2:0] present_state, next_state; 
 reg [5:0] count; 
 
 wire co;
 reg  cnt_en, cnt_rst; 
 
 /*
 parameter  [1:0] ADD		= 2'b01;
 parameter  [1:0] SUB		= 2'b10;
 parameter  [2:0] IDLE		= 3'b000;
 parameter  [2:0] INIT		= 3'b001;
 parameter  [2:0] COUNT		= 3'b010;
 parameter  [2:0] SHIFT		= 3'b011;
 parameter  [2:0] DONE		= 3'b100;
 */

 always @(posedge clk, posedge cnt_rst) begin
     if (cnt_rst)
         count <= {5'b0}; 
     else if (cnt_en)
         count <= count + 1;
 end
assign co = (count == 5'd17) ? 1'b1: 1'b0;

 always @(posedge clk, posedge rst) begin
    if (rst)
        present_state <= 3'b000;
    else 
        present_state <= next_state;
 end
 

 always @(*) begin
    {ldM, ldQ, ldP, clrP, shrQ, sel, subsel, done, cnt_rst, cnt_en} = 10'b0;    
    case(present_state)
        3'b000: begin  Ready =1'b1; ldQ = 1'b1; clrP = 1'b1; ldM = 1'b1; cnt_rst = 1'b1; end
        3'b001: begin  cnt_rst = 1'b1; end
        3'b010: cnt_en = 1'b1; 
        3'b011: begin
            shrQ = 1'b1; 
            ldP  = 1'b1; 
            if (op == 2'b10) begin
                subsel = 1'b1; 
                sel    = 1'b1; 
            end else if (op == 2'b01)
                sel    = 1'b1; 
            end
		3'b100:  done = 1'b1; 
    endcase
 end
 
 always @(*) begin
    case(present_state)
        3'b000:
            if (start)
                next_state = 3'b001;
            else 
                next_state = 3'b000;      
        3'b001:            
                next_state = 3'b010; 

        3'b010: 
            next_state = 3'b011;  
        3'b011:
            if (~co)              
                next_state = 3'b010; 
            else                    
                next_state = 3'b100;   
		3'b100:	next_state = 3'b000;             
    endcase
 end
 
endmodule

module booth_datapath #( parameter size = 17)(M, Q, P, clk, rst, 
                      op, shrQ, ldQ, ldM, ldP, clrP, sel, subsel); 
  input  [size-1:0]   M;
  input  [size-1:0]   Q;
  output [2*size-1:0] P;
  input 			  clk;
  input 			  rst;
  output [1:0] 		  op;
  input  			  shrQ;
  input  			  ldQ;
  input  			  ldM;
  input  			  ldP;
  input  			  clrP;
  input  			  sel;
  input  			  subsel;
                         

// Register M 
wire [size-1:0] Mout; 
REG #(size) M_REG (M, Mout, ldM, clk, rst);

// Shift Register Q
wire [size:0] Qout; 
wire seiQ, seoQ;
shift_register #(size+1) Q_REG (
    .in({Q , 1'b0}),
    .out(Qout),
    .clk(clk),
    .rst(rst),
    .shrR(shrQ),
    .seiR(seiQ),
    .seoR(seoQ),
    .ldR(ldQ)
    ); 
    
 // Register P
 wire [size-1:0] Pout; 
 wire [size-1:0] Pin; 
 REG #(size) P_REG (Pin,Pout, ldP, clk, clrP);
    
 // Adder_Subtractor 
 wire [size-1:0] result; 
 wire cout; 
 adder_subtractor #(size) ADD_OR_SUB (
    .a(Pout),
    .b(Mout),
    .subsel(subsel),
    .cout(cout),
    .out(result)
    ); 
 
 // Arithmetic Right Shift on Pout 
 assign Pin = (sel) ? {result[size - 1] , result[size - 1:1]} : {Pout[size - 1] , Pout[size - 1:1]}; 
 assign seiQ = (sel) ? result[0] : Pout[0];  
 assign op = Qout[1:0];
 
 // Output 
 assign P = {Pout , Qout[size:1]};  
endmodule

module divider(Devidend, Divisor, start, clk, rst, Quotient, Remainder, ready, done);
  input         start, clk, rst;
  input  [16:0] Divisor, Devidend;
  output [16:0] Quotient, Remainder;
  output        ready, done;
  
  wire          sign, load_R, shift_R;
  wire          shift_Q, load_Q, load_M, setQ0, setR, Q0, clr_R;
  
  divider_CU CU(start, sign, clk, rst, load_R, shift_R, shift_Q, load_Q, 
				load_M, setQ0, setR, Q0, clr_R, ready, done);
  
  divider_DP DP(Divisor, Devidend, load_R, shift_R, shift_Q, load_Q, load_M, 
				setQ0, setR, Q0, clr_R, clk, rst, Remainder, Quotient, sign);

endmodule

module divider_CU(start, sign, clk, rst, load_R, shift_R, shift_Q, load_Q,
				  load_M, setQ0, setR, Q0, clr_R, ready, done); 
				  
  input      start, sign, clk, rst;
  output     load_R, shift_R, shift_Q, load_Q;
  output     load_M, setQ0, setR, Q0, clr_R, ready, done;
  reg        load_R, shift_R, shift_Q, load_Q;
  reg        load_M, setQ0, setR, Q0, clr_R, ready, done;
  reg  [2:0] ps,ns;
  wire [4:0] cnt;
  wire       co;
  reg        incCnt, iniCnt;
  
  
  Counter #(5) counter(cnt, 5'd15, co, incCnt, iniCnt, clk, rst);
  
  always @(posedge clk, posedge rst) begin
    if(rst)
      ps <= 3'b000;
    else
      ps <= ns;
  end
  
  always @(*) begin
    {load_R, shift_R, shift_Q, load_Q, load_M, setQ0, setR, Q0, clr_R, ready, done, incCnt, iniCnt}=13'd0;
    case(ps)
      3'b000: ready = 1;
      3'b001: {load_Q, load_M, iniCnt, clr_R} = 4'b1111;
      3'b010: {shift_R, shift_Q} = 2'b11;
      3'b011: begin
           if(sign)
             {setR,Q0,setQ0,load_R, load_Q, incCnt} = 6'b001111;
           else
             {setR,Q0,setQ0,load_R, load_Q, incCnt} = 6'b111111;
         end
       3'b100: done = 1'b1;
    endcase
  end
  
    always @(*) begin
    case(ps)
      3'b000: ns = (start) ? 3'b001 : 3'b000;
      3'b001: ns = 3'b010;
      3'b010: ns = 3'b011;
      3'b011: ns = (co) ? 3'b100 : 3'b010;
      3'b100: ns = 3'b000;
    endcase
  end
  
endmodule     


module divider_DP(Divisor, Devident, load_R, shift_R, shift_Q, load_Q,
				  load_M, setQ0, setR, Q0, clr_R, clk, rst, Remainder, 
				  Quotient, sign);
				  
  input	 [16:0] Divisor, Devident;
  input         load_R, shift_R, shift_Q, load_Q, load_M;
  input         setQ0, setR, Q0, clr_R, clk, rst;
  output [16:0] Remainder, Quotient;
  output        sign;
  
  wire          serOutQ, serOutR;
  wire   [16:0] mux1Out, Rprev, mux2Out, Qprev, M, sub;
  wire          mux1Sel1, mux1Sel2, mux2Sel1, mux2Sel2;
  
  assign mux1Sel1 = setR;
  assign mux1Sel2 = ~setR;
  assign mux2Sel1 = setQ0;
  assign mux2Sel2 = ~setQ0;
  
  
  shiftReg_17b shReg_R(serOutQ, shift_R, mux1Out, Rprev, load_R, clk, rst, clr_R, serOutR);
  
  shiftReg_17b shReg_Q(1'b0, shift_Q, mux2Out, Qprev, load_Q, clk, rst, 1'b0, serOutQ);
  
  REG #(17) Reg_M(Divisor, M, load_M, clk, rst); 
  
  assign sub = Rprev - M;
  
  mux2to1 #(17) Mux1(Rprev, sub, mux1Sel2, mux1Sel1, mux1Out);
  
  mux2to1 #(17) Mux2(Devident, {Qprev[16:1], Q0}, mux2Sel2, mux2Sel1, mux2Out);
  
  assign sign = sub[16];
  
  assign Remainder = Rprev;
  assign Quotient  = Qprev;
  
  
endmodule





   








