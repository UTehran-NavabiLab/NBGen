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
