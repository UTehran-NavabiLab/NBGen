module fulladder(i0, i1, ci, s, co);

wire new__0_;
wire new__10_;
wire new__1_;
wire new__2_;
wire new__3_;
wire new__4_;
wire new__5_;
wire new__6_;
wire new__7_;
wire new__8_;
wire new__9_;
input i0;
input i1;
input ci;
output s;
output co;

INV_X1 #
) INV_X1_0_ (
  .A({ i0 }),
  .ZN({ new__8_ })
);
NAND2_X1 #
) NAND2_X1_1_ (
  .A1({ i1 }),
  .A2({ ci }),
  .ZN({ new__0_ })
);
INV_X1 #
) INV_X1_2_ (
  .A({ i1 }),
  .ZN({ new__1_ })
);
INV_X1 #
) INV_X1_3_ (
  .A({ ci }),
  .ZN({ new__2_ })
);
NAND2_X1 #
) NAND2_X1_4_ (
  .A1({ new__1_ }),
  .A2({ new__2_ }),
  .ZN({ new__3_ })
);
NAND3_X1 #
) NAND3_X1_5_ (
  .A1({ new__3_ }),
  .A2({ new__8_ }),
  .A3({ new__0_ }),
  .ZN({ new__4_ })
);
NAND2_X1 #
) NAND2_X1_6_ (
  .A1({ new__7_ }),
  .A2({ new__4_ }),
  .ZN({ new__10_ })
);
OAI21_X1 #
) OAI21_X1_7_ (
  .A({ new__0_ }),
  .B1({ new__6_ }),
  .B2({ new__8_ }),
  .ZN({ new__9_ })
);
AND2_X1 #
) AND2_X1_8_ (
  .A1({ ci }),
  .A2({ i1 }),
  .ZN({ new__5_ })
);
NOR2_X1 #
) NOR2_X1_9_ (
  .A1({ i1 }),
  .A2({ ci }),
  .ZN({ new__6_ })
);
OAI21_X1 #
) OAI21_X1_10_ (
  .A({ i0 }),
  .B1({ new__5_ }),
  .B2({ new__6_ }),
  .ZN({ new__7_ })
);
BUF_X1 #
) BUF_X1_11_ (
  .A({ new__9_ }),
  .Z({ co })
);
BUF_X1 #
) BUF_X1_12_ (
  .A({ new__10_ }),
  .Z({ s })
);

endmodule