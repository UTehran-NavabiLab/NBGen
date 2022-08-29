module fulladder(i0, i1, ci, s, co);

wire S0;
wire S1;
wire S2;
wire S3;
wire S4;
wire S5;
wire S6;
wire S7;
input i0;
input i1;
input ci;
output s;
output co;

OAI21_X1 #
) OAI21_X1_0_ (
  .A({ S5 }),
  .B1({ S3 }),
  .B2({ S6 }),
  .ZN({ S2 })
);
NAND2_X1 #
) NAND2_X1_1_ (
  .A1({ S0 }),
  .A2({ S2 }),
  .ZN({ S4 })
);
NAND2_X1 #
) NAND2_X1_2_ (
  .A1({ S6 }),
  .A2({ S3 }),
  .ZN({ S0 })
);
XNOR2_X1 #
) XNOR2_X1_3_ (
  .A({ S6 }),
  .B({ S3 }),
  .ZN({ S1 })
);
XNOR2_X1 #
) XNOR2_X1_4_ (
  .A({ S5 }),
  .B({ S1 }),
  .ZN({ S7 })
);
BUF_X1 #
) BUF_X1_5_ (
  .A({ ci }),
  .Z({ S3 })
);
BUF_X1 #
) BUF_X1_6_ (
  .A({ S4 }),
  .Z({ co })
);
BUF_X1 #
) BUF_X1_7_ (
  .A({ i0 }),
  .Z({ S5 })
);
BUF_X1 #
) BUF_X1_8_ (
  .A({ i1 }),
  .Z({ S6 })
);
BUF_X1 #
) BUF_X1_9_ (
  .A({ S7 }),
  .Z({ s })
);

endmodule