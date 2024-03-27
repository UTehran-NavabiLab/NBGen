module b01(line1, line2, reset, clock, outp, overflw);

wire S0;
wire S1;
wire S2;
wire S3;
wire S4;
wire S5;
wire S6;
wire S7;
wire S8;
wire S9;
wire S10;
wire S11;
wire S12;
wire S13;
wire S14;
wire S15;
wire S16;
wire S17;
wire S18;
wire S19;
wire S20;
wire S21;
wire S22;
wire S23;
wire S24;
wire S25;
wire S26;
wire S27;
wire S28;
wire S29;
wire S30;
wire S31;
wire S32;
wire S33;
wire S34;
wire S35;
wire S36;
wire S37;
wire S38;
wire S39;
wire S40;
wire S41;
wire S42;
wire S43;
wire S44;
wire S45;
wire S46;
wire S47;
wire \2_stato_0;
wire \2_stato_1;
wire \2_stato_2;
wire \79_Y_0;
wire \79_Y_1;
wire \79_Y_2;
input line1;
input line2;
input reset;
input clock;
output outp;
output overflw;

INV_X1 #() 
INV_X1_1_ (
  .A({ S2 }),
  .ZN({ S4 })
);
INV_X1 #() 
INV_X1_2_ (
  .A({ \2_stato_0 }),
  .ZN({ S5 })
);
NAND3_X1 #() 
NAND3_X1_1_ (
  .A1({ S5 }),
  .A2({ \2_stato_1 }),
  .A3({ \2_stato_2 }),
  .ZN({ S6 })
);
NAND2_X1 #() 
NAND2_X1_1_ (
  .A1({ S6 }),
  .A2({ S4 }),
  .ZN({ S7 })
);
NAND2_X1 #() 
NAND2_X1_2_ (
  .A1({ S44 }),
  .A2({ S43 }),
  .ZN({ S8 })
);
INV_X1 #() 
INV_X1_3_ (
  .A({ S8 }),
  .ZN({ S9 })
);
NOR2_X1 #() 
NOR2_X1_1_ (
  .A1({ S44 }),
  .A2({ S43 }),
  .ZN({ S10 })
);
NOR2_X1 #() 
NOR2_X1_2_ (
  .A1({ S9 }),
  .A2({ S10 }),
  .ZN({ S11 })
);
XNOR2_X1 #() 
XNOR2_X1_1_ (
  .A({ S11 }),
  .B({ S7 }),
  .ZN({ S0 })
);
INV_X1 #() 
INV_X1_4_ (
  .A({ S10 }),
  .ZN({ S12 })
);
INV_X1 #() 
INV_X1_5_ (
  .A({ \2_stato_1 }),
  .ZN({ S13 })
);
NAND3_X1 #() 
NAND3_X1_2_ (
  .A1({ S13 }),
  .A2({ \2_stato_0 }),
  .A3({ \2_stato_2 }),
  .ZN({ S14 })
);
AOI21_X1 #() 
AOI21_X1_1_ (
  .A({ S2 }),
  .B1({ S5 }),
  .B2({ S13 }),
  .ZN({ S15 })
);
NAND4_X1 #() 
NAND4_X1_1_ (
  .A1({ S15 }),
  .A2({ S12 }),
  .A3({ S14 }),
  .A4({ S6 }),
  .ZN({ S16 })
);
NOR3_X1 #() 
NOR3_X1_1_ (
  .A1({ S4 }),
  .A2({ S13 }),
  .A3({ \2_stato_0 }),
  .ZN({ S17 })
);
NOR3_X1 #() 
NOR3_X1_2_ (
  .A1({ \2_stato_1 }),
  .A2({ \2_stato_0 }),
  .A3({ S2 }),
  .ZN({ S18 })
);
AOI22_X1 #() 
AOI22_X1_1_ (
  .A1({ S17 }),
  .A2({ S9 }),
  .B1({ S18 }),
  .B2({ S12 }),
  .ZN({ S19 })
);
NAND3_X1 #() 
NAND3_X1_3_ (
  .A1({ S13 }),
  .A2({ \2_stato_0 }),
  .A3({ S2 }),
  .ZN({ S20 })
);
NOR2_X1 #() 
NOR2_X1_3_ (
  .A1({ S20 }),
  .A2({ S8 }),
  .ZN({ S21 })
);
NAND3_X1 #() 
NAND3_X1_4_ (
  .A1({ \2_stato_1 }),
  .A2({ \2_stato_0 }),
  .A3({ S2 }),
  .ZN({ S22 })
);
NAND3_X1 #() 
NAND3_X1_5_ (
  .A1({ S13 }),
  .A2({ S5 }),
  .A3({ S2 }),
  .ZN({ S23 })
);
AOI21_X1 #() 
AOI21_X1_2_ (
  .A({ S9 }),
  .B1({ S23 }),
  .B2({ S22 }),
  .ZN({ S24 })
);
NOR2_X1 #() 
NOR2_X1_4_ (
  .A1({ S24 }),
  .A2({ S21 }),
  .ZN({ S25 })
);
NOR2_X1 #() 
NOR2_X1_5_ (
  .A1({ S14 }),
  .A2({ S10 }),
  .ZN({ S26 })
);
NOR2_X1 #() 
NOR2_X1_6_ (
  .A1({ S6 }),
  .A2({ S8 }),
  .ZN({ S27 })
);
NOR2_X1 #() 
NOR2_X1_7_ (
  .A1({ S26 }),
  .A2({ S27 }),
  .ZN({ S28 })
);
NAND4_X1 #() 
NAND4_X1_2_ (
  .A1({ S25 }),
  .A2({ S28 }),
  .A3({ S16 }),
  .A4({ S19 }),
  .ZN({ \79_Y_0 })
);
NOR2_X1 #() 
NOR2_X1_8_ (
  .A1({ S20 }),
  .A2({ S9 }),
  .ZN({ S29 })
);
NOR2_X1 #() 
NOR2_X1_9_ (
  .A1({ S29 }),
  .A2({ S27 }),
  .ZN({ S30 })
);
NOR2_X1 #() 
NOR2_X1_10_ (
  .A1({ S5 }),
  .A2({ \2_stato_1 }),
  .ZN({ S31 })
);
AOI21_X1 #() 
AOI21_X1_3_ (
  .A({ S17 }),
  .B1({ S31 }),
  .B2({ \2_stato_2 }),
  .ZN({ S32 })
);
NAND2_X1 #() 
NAND2_X1_3_ (
  .A1({ S18 }),
  .A2({ S10 }),
  .ZN({ S33 })
);
NAND4_X1 #() 
NAND4_X1_3_ (
  .A1({ S30 }),
  .A2({ S32 }),
  .A3({ S16 }),
  .A4({ S33 }),
  .ZN({ \79_Y_1 })
);
AOI21_X1 #() 
AOI21_X1_4_ (
  .A({ S21 }),
  .B1({ S18 }),
  .B2({ S12 }),
  .ZN({ S34 })
);
NAND2_X1 #() 
NAND2_X1_4_ (
  .A1({ S23 }),
  .A2({ S22 }),
  .ZN({ S35 })
);
NAND2_X1 #() 
NAND2_X1_5_ (
  .A1({ S35 }),
  .A2({ S9 }),
  .ZN({ S36 })
);
NAND3_X1 #() 
NAND3_X1_6_ (
  .A1({ S34 }),
  .A2({ S32 }),
  .A3({ S36 }),
  .ZN({ \79_Y_2 })
);
AOI21_X1 #() 
AOI21_X1_5_ (
  .A({ S15 }),
  .B1({ \2_stato_0 }),
  .B2({ \2_stato_1 }),
  .ZN({ S37 })
);
NOR2_X1 #() 
NOR2_X1_11_ (
  .A1({ S37 }),
  .A2({ \2_stato_2 }),
  .ZN({ S1 })
);
INV_X1 #() 
INV_X1_6_ (
  .A({ S47 }),
  .ZN({ S3 })
);
DFFR_X1 #() 
DFFR_X1_1_ (
  .CK({ S42 }),
  .D({ \79_Y_0 }),
  .Q({ \2_stato_0 }),
  .QN({ S41 }),
  .RN({ S3 })
);
DFFR_X1 #() 
DFFR_X1_2_ (
  .CK({ S42 }),
  .D({ \79_Y_1 }),
  .Q({ \2_stato_1 }),
  .QN({ S40 }),
  .RN({ S3 })
);
DFFR_X1 #() 
DFFR_X1_3_ (
  .CK({ S42 }),
  .D({ \79_Y_2 }),
  .Q({ \2_stato_2 }),
  .QN({ S2 }),
  .RN({ S3 })
);
DFFR_X1 #() 
DFFR_X1_4_ (
  .CK({ S42 }),
  .D({ S0 }),
  .Q({ S45 }),
  .QN({ S39 }),
  .RN({ S3 })
);
DFFR_X1 #() 
DFFR_X1_5_ (
  .CK({ S42 }),
  .D({ S1 }),
  .Q({ S46 }),
  .QN({ S38 }),
  .RN({ S3 })
);
BUF_X1 #() 
BUF_X1_1_ (
  .A({ clock }),
  .Z({ S42 })
);
BUF_X1 #() 
BUF_X1_2_ (
  .A({ line1 }),
  .Z({ S43 })
);
BUF_X1 #() 
BUF_X1_3_ (
  .A({ line2 }),
  .Z({ S44 })
);
BUF_X1 #() 
BUF_X1_4_ (
  .A({ S45 }),
  .Z({ outp })
);
BUF_X1 #() 
BUF_X1_5_ (
  .A({ S46 }),
  .Z({ overflw })
);
BUF_X1 #() 
BUF_X1_6_ (
  .A({ reset }),
  .Z({ S47 })
);

endmodule