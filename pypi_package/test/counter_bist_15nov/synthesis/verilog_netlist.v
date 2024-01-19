module counter(clk, rst, en, clkEn, count, co);

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
input clk;
input rst;
input en;
input clkEn;
output [3:0] count;output co;

INV_X1 #() 
INV_X1_1_ (
  .A({ S27[2] }),
  .ZN({ S4 })
);
AND4_X1 #() 
AND4_X1_1_ (
  .A1({ S4 }),
  .A2({ S27[3] }),
  .A3({ S27[1] }),
  .A4({ S20 }),
  .ZN({ S26 })
);
INV_X1 #() 
INV_X1_2_ (
  .A({ S27[0] }),
  .ZN({ S5 })
);
NAND2_X1 #() 
NAND2_X1_1_ (
  .A1({ S25 }),
  .A2({ S28 }),
  .ZN({ S6 })
);
INV_X1 #() 
INV_X1_3_ (
  .A({ S29 }),
  .ZN({ S7 })
);
OAI21_X1 #() 
OAI21_X1_1_ (
  .A({ S7 }),
  .B1({ S6 }),
  .B2({ S20 }),
  .ZN({ S8 })
);
AOI21_X1 #() 
AOI21_X1_1_ (
  .A({ S8 }),
  .B1({ S6 }),
  .B2({ S5 }),
  .ZN({ S0 })
);
INV_X1 #() 
INV_X1_4_ (
  .A({ S27[1] }),
  .ZN({ S9 })
);
NAND3_X1 #() 
NAND3_X1_1_ (
  .A1({ S25 }),
  .A2({ S28 }),
  .A3({ S27[0] }),
  .ZN({ S10 })
);
NAND4_X1 #() 
NAND4_X1_1_ (
  .A1({ S27[1] }),
  .A2({ S27[0] }),
  .A3({ S25 }),
  .A4({ S28 }),
  .ZN({ S11 })
);
NAND2_X1 #() 
NAND2_X1_2_ (
  .A1({ S11 }),
  .A2({ S7 }),
  .ZN({ S12 })
);
AOI21_X1 #() 
AOI21_X1_2_ (
  .A({ S12 }),
  .B1({ S10 }),
  .B2({ S9 }),
  .ZN({ S1 })
);
NAND2_X1 #() 
NAND2_X1_3_ (
  .A1({ S27[2] }),
  .A2({ S27[1] }),
  .ZN({ S13 })
);
OAI21_X1 #() 
OAI21_X1_2_ (
  .A({ S7 }),
  .B1({ S10 }),
  .B2({ S13 }),
  .ZN({ S14 })
);
AOI21_X1 #() 
AOI21_X1_3_ (
  .A({ S14 }),
  .B1({ S11 }),
  .B2({ S4 }),
  .ZN({ S2 })
);
OAI21_X1 #() 
OAI21_X1_3_ (
  .A({ S27[3] }),
  .B1({ S10 }),
  .B2({ S13 }),
  .ZN({ S15 })
);
INV_X1 #() 
INV_X1_5_ (
  .A({ S27[3] }),
  .ZN({ S16 })
);
AND3_X1 #() 
AND3_X1_1_ (
  .A1({ S27[0] }),
  .A2({ S28 }),
  .A3({ S25 }),
  .ZN({ S17 })
);
AND2_X1 #() 
AND2_X1_1_ (
  .A1({ S27[1] }),
  .A2({ S27[2] }),
  .ZN({ S18 })
);
NAND3_X1 #() 
NAND3_X1_2_ (
  .A1({ S17 }),
  .A2({ S16 }),
  .A3({ S18 }),
  .ZN({ S19 })
);
AOI21_X1 #() 
AOI21_X1_4_ (
  .A({ S29 }),
  .B1({ S19 }),
  .B2({ S15 }),
  .ZN({ S3 })
);
DFF_X1 #() 
DFF_X1_1_ (
  .CK({ S24 }),
  .D({ S0 }),
  .Q({ S27[0] }),
  .QN({ S20 })
);
DFF_X1 #() 
DFF_X1_2_ (
  .CK({ S24 }),
  .D({ S1 }),
  .Q({ S27[1] }),
  .QN({ S23 })
);
DFF_X1 #() 
DFF_X1_3_ (
  .CK({ S24 }),
  .D({ S2 }),
  .Q({ S27[2] }),
  .QN({ S22 })
);
DFF_X1 #() 
DFF_X1_4_ (
  .CK({ S24 }),
  .D({ S3 }),
  .Q({ S27[3] }),
  .QN({ S21 })
);
BUF_X1 #() 
BUF_X1_1_ (
  .A({ clk }),
  .Z({ S24 })
);
BUF_X1 #() 
BUF_X1_2_ (
  .A({ clkEn }),
  .Z({ S25 })
);
BUF_X1 #() 
BUF_X1_3_ (
  .A({ S26 }),
  .Z({ co })
);
BUF_X1 #() 
BUF_X1_4_ (
  .A({ S27[0] }),
  .Z({ count[0] })
);
BUF_X1 #() 
BUF_X1_5_ (
  .A({ S27[1] }),
  .Z({ count[1] })
);
BUF_X1 #() 
BUF_X1_6_ (
  .A({ S27[2] }),
  .Z({ count[2] })
);
BUF_X1 #() 
BUF_X1_7_ (
  .A({ S27[3] }),
  .Z({ count[3] })
);
BUF_X1 #() 
BUF_X1_8_ (
  .A({ en }),
  .Z({ S28 })
);
BUF_X1 #() 
BUF_X1_9_ (
  .A({ rst }),
  .Z({ S29 })
);

endmodule