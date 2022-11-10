module fulladder(i0, i1, ci, s, co);

wire _0_;
wire _1_;
wire _2_;
wire _3_;
wire _4_;
wire _5_;
wire _6_;
wire _7_;
wire _8_;
input i0;
input i1;
input ci;
output s;
output co;

NAND2_X1 #() 
NAND2_X1_1_ (
  .A1({ i1 }),
  .A2({ ci }),
  .ZN({ _0_ })
);
INV_X1 #() 
INV_X1_1_ (
  .A({ i1 }),
  .ZN({ _1_ })
);
INV_X1 #() 
INV_X1_2_ (
  .A({ ci }),
  .ZN({ _2_ })
);
NAND2_X1 #() 
NAND2_X1_2_ (
  .A1({ _1_ }),
  .A2({ _2_ }),
  .ZN({ _3_ })
);
NAND3_X1 #() 
NAND3_X1_1_ (
  .A1({ _3_ }),
  .A2({ _8_ }),
  .A3({ _0_ }),
  .ZN({ _4_ })
);
NAND2_X1 #() 
NAND2_X1_3_ (
  .A1({ _7_ }),
  .A2({ _4_ }),
  .ZN({ s })
);
OAI21_X1 #() 
OAI21_X1_1_ (
  .A({ _0_ }),
  .B1({ _6_ }),
  .B2({ _8_ }),
  .ZN({ co })
);
AND2_X1 #() 
AND2_X1_1_ (
  .A1({ ci }),
  .A2({ i1 }),
  .ZN({ _5_ })
);
NOR2_X1 #() 
NOR2_X1_1_ (
  .A1({ i1 }),
  .A2({ ci }),
  .ZN({ _6_ })
);
OAI21_X1 #() 
OAI21_X1_2_ (
  .A({ i0 }),
  .B1({ _5_ }),
  .B2({ _6_ }),
  .ZN({ _7_ })
);
INV_X1 #() 
INV_X1_3_ (
  .A({ i0 }),
  .ZN({ _8_ })
);

endmodule