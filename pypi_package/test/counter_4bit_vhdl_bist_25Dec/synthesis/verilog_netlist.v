module counter_4bit(clk, rst, en, co, counter);

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
wire counter_reg_0;
wire counter_reg_1;
wire counter_reg_2;
wire counter_reg_3;
input clk;
input rst;
input en;
output co;
output [3:0] counter;
AND2_X1 #() 
AND2_X1_1_ (
  .A1({ S21[2] }),
  .A2({ S21[1] }),
  .ZN({ S5 })
);
AND3_X1 #() 
AND3_X1_1_ (
  .A1({ S5 }),
  .A2({ S21[3] }),
  .A3({ S21[0] }),
  .ZN({ S20 })
);
INV_X1 #() 
INV_X1_1_ (
  .A({ S23 }),
  .ZN({ S0 })
);
MUX2_X1 #() 
MUX2_X1_1_ (
  .A({ S21[0] }),
  .B({ S15 }),
  .S({ S22 }),
  .Z({ S1 })
);
NAND2_X1 #() 
NAND2_X1_1_ (
  .A1({ S21[0] }),
  .A2({ S22 }),
  .ZN({ S6 })
);
XNOR2_X1 #() 
XNOR2_X1_1_ (
  .A({ S6 }),
  .B({ S21[1] }),
  .ZN({ S2 })
);
INV_X1 #() 
INV_X1_2_ (
  .A({ S21[2] }),
  .ZN({ S7 })
);
NAND3_X1 #() 
NAND3_X1_1_ (
  .A1({ S21[1] }),
  .A2({ S21[0] }),
  .A3({ S22 }),
  .ZN({ S8 })
);
NAND2_X1 #() 
NAND2_X1_2_ (
  .A1({ S8 }),
  .A2({ S7 }),
  .ZN({ S9 })
);
NAND4_X1 #() 
NAND4_X1_1_ (
  .A1({ S21[2] }),
  .A2({ S22 }),
  .A3({ S21[1] }),
  .A4({ S21[0] }),
  .ZN({ S10 })
);
AND2_X1 #() 
AND2_X1_2_ (
  .A1({ S9 }),
  .A2({ S10 }),
  .ZN({ S3 })
);
NAND2_X1 #() 
NAND2_X1_3_ (
  .A1({ S10 }),
  .A2({ S21[3] }),
  .ZN({ S11 })
);
INV_X1 #() 
INV_X1_3_ (
  .A({ S21[3] }),
  .ZN({ S12 })
);
AND2_X1 #() 
AND2_X1_3_ (
  .A1({ S22 }),
  .A2({ S21[0] }),
  .ZN({ S13 })
);
NAND3_X1 #() 
NAND3_X1_2_ (
  .A1({ S5 }),
  .A2({ S13 }),
  .A3({ S12 }),
  .ZN({ S14 })
);
NAND2_X1 #() 
NAND2_X1_4_ (
  .A1({ S14 }),
  .A2({ S11 }),
  .ZN({ S4 })
);
DFFR_X1 #() 
DFFR_X1_1_ (
  .CK({ S19 }),
  .D({ S1 }),
  .Q({ S21[0] }),
  .QN({ S15 }),
  .RN({ S0 })
);
DFFR_X1 #() 
DFFR_X1_2_ (
  .CK({ S19 }),
  .D({ S2 }),
  .Q({ S21[1] }),
  .QN({ S18 }),
  .RN({ S0 })
);
DFFR_X1 #() 
DFFR_X1_3_ (
  .CK({ S19 }),
  .D({ S3 }),
  .Q({ S21[2] }),
  .QN({ S17 }),
  .RN({ S0 })
);
DFFR_X1 #() 
DFFR_X1_4_ (
  .CK({ S19 }),
  .D({ S4 }),
  .Q({ S21[3] }),
  .QN({ S16 }),
  .RN({ S0 })
);
BUF_X1 #() 
BUF_X1_1_ (
  .A({ clk }),
  .Z({ S19 })
);
BUF_X1 #() 
BUF_X1_2_ (
  .A({ S20 }),
  .Z({ co })
);
BUF_X1 #() 
BUF_X1_3_ (
  .A({ S21[0] }),
  .Z({ counter[0] })
);
BUF_X1 #() 
BUF_X1_4_ (
  .A({ S21[1] }),
  .Z({ counter[1] })
);
BUF_X1 #() 
BUF_X1_5_ (
  .A({ S21[2] }),
  .Z({ counter[2] })
);
BUF_X1 #() 
BUF_X1_6_ (
  .A({ S21[3] }),
  .Z({ counter[3] })
);
BUF_X1 #() 
BUF_X1_7_ (
  .A({ en }),
  .Z({ S22 })
);
BUF_X1 #() 
BUF_X1_8_ (
  .A({ rst }),
  .Z({ S23 })
);

endmodule