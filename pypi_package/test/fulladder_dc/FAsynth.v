
module fulladder ( i0, i1, ci, s, co );
  input i0, i1, ci;
  output s, co;
  wire   n4, n5;

  XOR2_X1 U5 ( .A(i1), .B(n4), .Z(s) );
  INV_X1 U6 ( .A(n5), .ZN(co) );
  AOI22_X1 U7 ( .A1(i0), .A2(ci), .B1(n4), .B2(i1), .ZN(n5) );
  XOR2_X1 U8 ( .A(ci), .B(i0), .Z(n4) );
endmodule

