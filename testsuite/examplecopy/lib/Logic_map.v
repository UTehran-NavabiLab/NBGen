module BUF (A, Y);
  
  input A;
  output Y;
  bufg #(.tphl (0), .tplh (0)) _TECHMAP_REPLACE_ (
    .in(A),
    .out(Y),
  );
endmodule

module TIELOM (Y);
  
  output Y;
  bufg #(.tphl (0), .tplh (0)) _TECHMAP_REPLACE_ (
    .in(1'b0),
    .out(Y),
  );
endmodule

module TIEHIM (Y);
  
  output Y;
  bufg #(.tphl (0), .tplh (0)) _TECHMAP_REPLACE_ (
    .in(1'b1),
    .out(Y),
  );
endmodule

module IBUF (I, O);
  
  input I;
  output O;
  pin #(.n (1)) _TECHMAP_REPLACE_ (
    .in(I),
    .out(O),
  );
endmodule

module OBUF (I, O);
  
  input I;
  output O;
  pout #(.n (1)) _TECHMAP_REPLACE_ (
    .in(I),
    .out(O),
  );
endmodule

module NOT (A, Y);
  
  input A;
  output Y;
  notg #(.tphl (0),.tplh (0)) _TECHMAP_REPLACE_ (
    .in(A),
    .out(Y),
  );
endmodule

module AND (A, B, Y);
  
  input A, B;
  output Y;
  and_n #(.n(2),.tphl (0),.tplh (0)) _TECHMAP_REPLACE_ (
    .in({A,B}),
    .out(Y),
  );
endmodule

module NAND (A, B, Y);
  
  input A, B;
  output Y;
  nand_n #(.n(2),.tphl (0),.tplh (0)) _TECHMAP_REPLACE_ (
    .in({A,B}),
    .out(Y),
  );
endmodule

module OR (A, B, Y);
  
  input A, B;
  output Y;
  or_n #(.n(2),.tphl (0),.tplh (0)) _TECHMAP_REPLACE_ (
    .in({A,B}),
    .out(Y),
  );
endmodule

module NOR (A, B, Y);
  
  input A, B;
  output Y;
  nor_n #(.n(2),.tphl (0),.tplh (0)) _TECHMAP_REPLACE_ (
    .in({A,B}),
    .out(Y),
  );
endmodule

module XOR (A, B, Y);
  
  input A, B;
  output Y;
  xor_n #(.n(2),.tphl (0),.tplh (0)) _TECHMAP_REPLACE_ (
    .in({A,B}),
    .out(Y),
  );
endmodule

module XNOR (A, B, Y);
  
  input A, B;
  output Y;
  xnor_n #(.n(2),.tphl (0),.tplh (0)) _TECHMAP_REPLACE_ (
    .in({A,B}),
    .out(Y),
  );
endmodule
