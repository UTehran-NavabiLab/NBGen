

module CMP(in1, in2, lt, gt, eq);

  input [15:0] in1, in2;
  output       lt, gt, eq;
  
  assign lt = (in1 <  in2) ? 1:0;
  assign eq = (in1 == in2) ? 1:0;
  assign gt = (in1 >  in2) ? 1:0;
  
endmodule

 
