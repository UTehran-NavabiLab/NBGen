module three_level_gate(i0, i1, i2, o);

wire _0_;
wire _1_;
input i0;
input i1;
input i2;
output o;

INV_X1 #() 
INV_X1_1_ (
  .A({ i2 }),
  .ZN({ _0_ })
);
NAND2_X1 #() 
NAND2_X1_1_ (
  .A1({ i1 }),
  .A2({ i0 }),
  .ZN({ _1_ })
);
NAND2_X1 #() 
NAND2_X1_2_ (
  .A1({ _1_ }),
  .A2({ _0_ }),
  .ZN({ o })
);

endmodule