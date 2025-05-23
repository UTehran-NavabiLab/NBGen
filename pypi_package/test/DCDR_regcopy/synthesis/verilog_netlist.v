module register(clk, rst, A, B, C, Q1, Q2, Q3);

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
wire CK;
wire R;
wire cnt_0;
wire cnt_1;
wire cnt_2;
wire cnt_3;
input clk;
input rst;
input [3:0] A;input [3:0] B;input [3:0] C;output [3:0] Q1;output [3:0] Q2;output [3:0] Q3;
notg #( 
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
notg_1_ (
  .A({ cnt_0 }),
  .Y({ S11 })
);
notg #( 
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
notg_2_ (
  .A({ CK }),
  .Y({ S0 })
);
notg #( 
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
notg_3_ (
  .A({ cnt_1 }),
  .Y({ S1 })
);
notg #( 
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
notg_4_ (
  .A({ cnt_2 }),
  .Y({ S2 })
);
notg #( 
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
notg_5_ (
  .A({ cnt_3 }),
  .Y({ S3 })
);
nor_n #( 
  .n(32'b00000000000000000000000000000010),
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
nor_n_1_ (
  .A({ S1, S11 }),
  .Y({ S4 })
);
nand_n #( 
  .n(32'b00000000000000000000000000000010),
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
nand_n_1_ (
  .A({ cnt_1, cnt_0 }),
  .Y({ S5 })
);
nor_n #( 
  .n(32'b00000000000000000000000000000010),
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
nor_n_2_ (
  .A({ cnt_1, cnt_0 }),
  .Y({ S6 })
);
nor_n #( 
  .n(32'b00000000000000000000000000000010),
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
nor_n_3_ (
  .A({ S6, S4 }),
  .Y({ S12 })
);
nor_n #( 
  .n(32'b00000000000000000000000000000010),
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
nor_n_4_ (
  .A({ S5, S2 }),
  .Y({ S7 })
);
nand_n #( 
  .n(32'b00000000000000000000000000000010),
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
nand_n_2_ (
  .A({ S4, cnt_2 }),
  .Y({ S8 })
);
nor_n #( 
  .n(32'b00000000000000000000000000000010),
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
nor_n_5_ (
  .A({ S4, cnt_2 }),
  .Y({ S9 })
);
nor_n #( 
  .n(32'b00000000000000000000000000000010),
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
nor_n_6_ (
  .A({ S9, S7 }),
  .Y({ S13 })
);
nor_n #( 
  .n(32'b00000000000000000000000000000010),
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
nor_n_7_ (
  .A({ S8, S3 }),
  .Y({ R })
);
nor_n #( 
  .n(32'b00000000000000000000000000000010),
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
nor_n_8_ (
  .A({ S7, cnt_3 }),
  .Y({ S10 })
);
nor_n #( 
  .n(32'b00000000000000000000000000000010),
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
nor_n_9_ (
  .A({ S10, R }),
  .Y({ S14 })
);
dff #( 
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
dff_1_ (
  .C({ CK }),
  .CE({ 1'b1 }),
  .D({ S17[0] }),
  .NbarT({ 1'b0 }),
  .PRE({ 1'b0 }),
  .Q({ S20[0] }),
  .R({ R }),
  .Si({ S25 }),
  .global_reset({ 1'b0 })
);
dff #( 
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
dff_2_ (
  .C({ CK }),
  .CE({ 1'b1 }),
  .D({ S17[1] }),
  .NbarT({ 1'b0 }),
  .PRE({ 1'b0 }),
  .Q({ S20[1] }),
  .R({ R }),
  .Si({ S29 }),
  .global_reset({ 1'b0 })
);
dff #( 
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
dff_3_ (
  .C({ CK }),
  .CE({ 1'b1 }),
  .D({ S17[2] }),
  .NbarT({ 1'b0 }),
  .PRE({ 1'b0 }),
  .Q({ S20[2] }),
  .R({ R }),
  .Si({ S30 }),
  .global_reset({ 1'b0 })
);
dff #( 
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
dff_4_ (
  .C({ CK }),
  .CE({ 1'b1 }),
  .D({ S17[3] }),
  .NbarT({ 1'b0 }),
  .PRE({ 1'b0 }),
  .Q({ S20[3] }),
  .R({ R }),
  .Si({ S24 }),
  .global_reset({ 1'b0 })
);
dff #( 
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
dff_5_ (
  .C({ S21 }),
  .CE({ 1'b1 }),
  .D({ S16[0] }),
  .NbarT({ 1'b0 }),
  .PRE({ 1'b0 }),
  .Q({ S19[0] }),
  .R({ R }),
  .Si({ S26 }),
  .global_reset({ 1'b0 })
);
dff #( 
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
dff_6_ (
  .C({ S21 }),
  .CE({ 1'b1 }),
  .D({ S16[1] }),
  .NbarT({ 1'b0 }),
  .PRE({ 1'b0 }),
  .Q({ S19[1] }),
  .R({ R }),
  .Si({ S31 }),
  .global_reset({ 1'b0 })
);
dff #( 
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
dff_7_ (
  .C({ S21 }),
  .CE({ 1'b1 }),
  .D({ S16[2] }),
  .NbarT({ 1'b0 }),
  .PRE({ 1'b0 }),
  .Q({ S19[2] }),
  .R({ R }),
  .Si({ S32 }),
  .global_reset({ 1'b0 })
);
dff #( 
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
dff_8_ (
  .C({ S21 }),
  .CE({ 1'b1 }),
  .D({ S16[3] }),
  .NbarT({ 1'b0 }),
  .PRE({ 1'b0 }),
  .Q({ S19[3] }),
  .R({ R }),
  .Si({ S33 }),
  .global_reset({ 1'b0 })
);
dff #( 
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
dff_9_ (
  .C({ S21 }),
  .CE({ 1'b1 }),
  .D({ S11 }),
  .NbarT({ 1'b0 }),
  .PRE({ 1'b0 }),
  .Q({ cnt_0 }),
  .R({ S22 }),
  .Si({ S27 }),
  .global_reset({ 1'b0 })
);
dff #( 
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
dff_10_ (
  .C({ S21 }),
  .CE({ 1'b1 }),
  .D({ S12 }),
  .NbarT({ 1'b0 }),
  .PRE({ 1'b0 }),
  .Q({ cnt_1 }),
  .R({ S22 }),
  .Si({ S34 }),
  .global_reset({ 1'b0 })
);
dff #( 
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
dff_11_ (
  .C({ S21 }),
  .CE({ 1'b1 }),
  .D({ S13 }),
  .NbarT({ 1'b0 }),
  .PRE({ 1'b0 }),
  .Q({ cnt_2 }),
  .R({ S22 }),
  .Si({ S35 }),
  .global_reset({ 1'b0 })
);
dff #( 
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
dff_12_ (
  .C({ S21 }),
  .CE({ 1'b1 }),
  .D({ S14 }),
  .NbarT({ 1'b0 }),
  .PRE({ 1'b0 }),
  .Q({ cnt_3 }),
  .R({ S22 }),
  .Si({ S36 }),
  .global_reset({ 1'b0 })
);
dff #( 
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
dff_13_ (
  .C({ CK }),
  .CE({ 1'b1 }),
  .D({ S15[0] }),
  .NbarT({ 1'b0 }),
  .PRE({ 1'b0 }),
  .Q({ S18[0] }),
  .R({ S22 }),
  .Si({ S28 }),
  .global_reset({ 1'b0 })
);
dff #( 
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
dff_14_ (
  .C({ CK }),
  .CE({ 1'b1 }),
  .D({ S15[1] }),
  .NbarT({ 1'b0 }),
  .PRE({ 1'b0 }),
  .Q({ S18[1] }),
  .R({ S22 }),
  .Si({ S37 }),
  .global_reset({ 1'b0 })
);
dff #( 
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
dff_15_ (
  .C({ CK }),
  .CE({ 1'b1 }),
  .D({ S15[2] }),
  .NbarT({ 1'b0 }),
  .PRE({ 1'b0 }),
  .Q({ S18[2] }),
  .R({ S22 }),
  .Si({ S38 }),
  .global_reset({ 1'b0 })
);
dff #( 
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
dff_16_ (
  .C({ CK }),
  .CE({ 1'b1 }),
  .D({ S15[3] }),
  .NbarT({ 1'b0 }),
  .PRE({ 1'b0 }),
  .Q({ S18[3] }),
  .R({ S22 }),
  .Si({ S39 }),
  .global_reset({ 1'b0 })
);
dff #( 
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
dff_17_ (
  .C({ S21 }),
  .CE({ 1'b1 }),
  .D({ S0 }),
  .NbarT({ 1'b0 }),
  .PRE({ 1'b0 }),
  .Q({ CK }),
  .R({ S22 }),
  .Si({ S23 }),
  .global_reset({ 1'b0 })
);
bufg #( 
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
bufg_1_ (
  .A({ A[0] }),
  .Y({ S15[0] })
);
bufg #( 
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
bufg_2_ (
  .A({ A[1] }),
  .Y({ S15[1] })
);
bufg #( 
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
bufg_3_ (
  .A({ A[2] }),
  .Y({ S15[2] })
);
bufg #( 
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
bufg_4_ (
  .A({ A[3] }),
  .Y({ S15[3] })
);
bufg #( 
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
bufg_5_ (
  .A({ B[0] }),
  .Y({ S16[0] })
);
bufg #( 
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
bufg_6_ (
  .A({ B[1] }),
  .Y({ S16[1] })
);
bufg #( 
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
bufg_7_ (
  .A({ B[2] }),
  .Y({ S16[2] })
);
bufg #( 
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
bufg_8_ (
  .A({ B[3] }),
  .Y({ S16[3] })
);
bufg #( 
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
bufg_9_ (
  .A({ C[0] }),
  .Y({ S17[0] })
);
bufg #( 
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
bufg_10_ (
  .A({ C[1] }),
  .Y({ S17[1] })
);
bufg #( 
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
bufg_11_ (
  .A({ C[2] }),
  .Y({ S17[2] })
);
bufg #( 
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
bufg_12_ (
  .A({ C[3] }),
  .Y({ S17[3] })
);
bufg #( 
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
bufg_13_ (
  .A({ S18[0] }),
  .Y({ Q1[0] })
);
bufg #( 
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
bufg_14_ (
  .A({ S18[1] }),
  .Y({ Q1[1] })
);
bufg #( 
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
bufg_15_ (
  .A({ S18[2] }),
  .Y({ Q1[2] })
);
bufg #( 
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
bufg_16_ (
  .A({ S18[3] }),
  .Y({ Q1[3] })
);
bufg #( 
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
bufg_17_ (
  .A({ S19[0] }),
  .Y({ Q2[0] })
);
bufg #( 
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
bufg_18_ (
  .A({ S19[1] }),
  .Y({ Q2[1] })
);
bufg #( 
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
bufg_19_ (
  .A({ S19[2] }),
  .Y({ Q2[2] })
);
bufg #( 
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
bufg_20_ (
  .A({ S19[3] }),
  .Y({ Q2[3] })
);
bufg #( 
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
bufg_21_ (
  .A({ S20[0] }),
  .Y({ Q3[0] })
);
bufg #( 
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
bufg_22_ (
  .A({ S20[1] }),
  .Y({ Q3[1] })
);
bufg #( 
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
bufg_23_ (
  .A({ S20[2] }),
  .Y({ Q3[2] })
);
bufg #( 
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
bufg_24_ (
  .A({ S20[3] }),
  .Y({ Q3[3] })
);
bufg #( 
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
bufg_25_ (
  .A({ clk }),
  .Y({ S21 })
);
bufg #( 
  .tphl(32'b00000000000000000000000000000000),
  .tplh(32'b00000000000000000000000000000000)) 
bufg_26_ (
  .A({ rst }),
  .Y({ S22 })
);

endmodule