module fulladder(i0, i1, ci, s, co);

wire _0_;
wire _10_;
wire _1_;
wire _2_;
wire _3_;
wire _4_;
wire _5_;
wire _6_;
wire _7_;
wire _8_;
wire _9_;
input i0;
input i1;
input ci;
output s;
output co;

INVX1 INVX1_1_ (
  .A({ i0 }),
  .Y({ _8_ })
);
NAND2X1 NAND2X1_1_ (
  .A({ i1 }),
  .B({ ci }),
  .Y({ _0_ })
);
INVX1 INVX1_2_ (
  .A({ i1 }),
  .Y({ _1_ })
);
INVX1 INVX1_3_ (
  .A({ ci }),
  .Y({ _2_ })
);
NAND2X1 NAND2X1_2_ (
  .A({ _1_ }),
  .B({ _2_ }),
  .Y({ _3_ })
);
NAND3X1 NAND3X1_1_ (
  .A({ _3_ }),
  .B({ _8_ }),
  .C({ _0_ }),
  .Y({ _4_ })
);
NAND2X1 NAND2X1_3_ (
  .A({ _7_ }),
  .B({ _4_ }),
  .Y({ _10_ })
);
OAI21XL OAI21X1_1_ (
  .A0({ _0_ }),
  .A1({ _6_ }),
  .B0({ _8_ }),
  .Y({ _9_ })
);
AND2X1 AND2X1_1_ (
  .A({ ci }),
  .B({ i1 }),
  .Y({ _5_ })
);
NOR2X1 NOR2X1_1_ (
  .A({ i1 }),
  .B({ ci }),
  .Y({ _6_ })
);
OAI21XL OAI21X1_2_ (
  .A0({ i0 }),
  .A1({ _5_ }),
  .B0({ _6_ }),
  .Y({ _7_ })
);
BUFX3 BUFX1_1_ (
  .A({ _9_ }),
  .Y({ co })
);
BUFX3 BUFX1_2_ (
  .A({ _10_ }),
  .Y({ s })
);

endmodule