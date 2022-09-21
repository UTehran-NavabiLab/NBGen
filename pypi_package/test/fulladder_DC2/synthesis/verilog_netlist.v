module fulladder(i0, i1, ci, s, co);

wire n4;
wire n5;
input i0;
input i1;
input ci;
output s;
output co;

XOR2_X1 #() 
XOR2_X1_1_ (
  .A({ i1 }),
  .B({ n4 }),
  .Z({ s })
);
INV_X1 #() 
INV_X1_1_ (
  .A({ n5 }),
  .ZN({ co })
);
AOI22_X1 #() 
AOI22_X1_1_ (
  .A1({ i0 }),
  .A2({ ci }),
  .B1({ n4 }),
  .B2({ i1 }),
  .ZN({ n5 })
);
XOR2_X1 #() 
XOR2_X1_2_ (
  .A({ ci }),
  .B({ i0 }),
  .Z({ n4 })
);

endmodule