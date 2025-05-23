/* Generated by Yosys 0.29+23 (git sha1 cdeef5481, x86_64-w64-mingw32-g++ 9.2.1 -Os) */

module register(Si1, Si2, Si3, Si4, So1, So2, So3, So4, NBART, Grst, clk, rst, A, B, C, Q1, Q2, Q3);
  	input Si1;
	input Si2;
	input Si3;
	input Si4;
	output So1;
	output So2;
	output So3;
	output So4;
	wire _DMY0_;
	wire _DMY1_;
	wire _DMY2_;
	wire _DMY3_;
	wire _DMY4_;
	wire _DMY5_;
	wire _DMY6_;
	wire _DMY7_;
	wire _DMY8_;
	wire _DMY9_;
	wire _DMY10_;
wire _35_;
  wire _36_;
  input [3:0] A;
  wire [3:0] A;
  input [3:0] B;
  wire [3:0] B;
  input [3:0] C;
  wire [3:0] C;
  wire CK;
  input Grst;
  wire Grst;
  input NBART;
  wire NBART;
  output [3:0] Q1;
  wire [3:0] Q1;
  output [3:0] Q2;
  wire [3:0] Q2;
  output [3:0] Q3;
  wire [3:0] Q3;
  wire _0_;
  wire _1_;
  wire _2_;
  wire _3_;
  wire _4_;
  wire _5_;
  wire [3:0] _6_;
  wire [3:0] _7_;
  wire _DRS0_;
  wire _MUX0_;
  input clk;
  wire clk;
  wire [3:0] cnt;
  input rst;
  wire rst;
  INVX1 _37_ (
    .A(CK),
    .Y(_35_)
  );
  NAND2X1 _38_ (
    .A(NBART),
    .B(clk),
    .Y(_36_)
  );
  OAI21X1 _39_ (
    .A(_35_),
    .B(NBART),
    .C(_36_),
    .Y(_MUX0_)
  );
  OR2X2 _40_ (
    .A(NBART),
    .B(_1_),
    .Y(_DRS0_)
  );
  XOR2X1 _10_ (
    .A(cnt[0]),
    .B(_6_[1]),
    .Y(_7_[1])
  );
  NAND3X1 _11_ (
    .A(_6_[1]),
    .B(cnt[0]),
    .C(_6_[2]),
    .Y(_3_)
  );
  INVX1 _12_ (
    .A(_3_),
    .Y(_4_)
  );
  AOI21X1 _13_ (
    .A(_6_[1]),
    .B(cnt[0]),
    .C(_6_[2]),
    .Y(_5_)
  );
  NOR2X1 _14_ (
    .A(_5_),
    .B(_4_),
    .Y(_7_[2])
  );
  XNOR2X1 _15_ (
    .A(_3_),
    .B(_6_[3]),
    .Y(_7_[3])
  );
  NAND2X1 _16_ (
    .A(_6_[3]),
    .B(_4_),
    .Y(_1_)
  );
  INVX1 _17_ (
    .A(rst),
    .Y(_2_)
  );
  	scandff _18_(.Q(Q3[0]), .D(C[0]), .C(_MUX0_), .CLR(( ~_DRS0_)), .PRE(1'h0), .NbarT(NBART), .Si(Si1), .global_reset(Grst));

  	scandff _19_(.Q(Q3[1]), .D(C[1]), .C(_MUX0_), .CLR(( ~_DRS0_)), .PRE(1'h0), .NbarT(NBART), .Si(Q3[0]), .global_reset(Grst));

  	scandff _20_(.Q(Q3[2]), .D(C[2]), .C(_MUX0_), .CLR(( ~_DRS0_)), .PRE(1'h0), .NbarT(NBART), .Si(Si2), .global_reset(Grst));

  	scandff _21_(.Q(Q3[3]), .D(C[3]), .C(_MUX0_), .CLR(( ~_DRS0_)), .PRE(1'h0), .NbarT(NBART), .Si(Q3[2]), .global_reset(Grst));

  	scandff _22_(.Q(Q2[0]), .D(B[0]), .C(clk), .CLR(( ~_DRS0_)), .PRE(1'h0), .NbarT(NBART), .Si(Q3[3]), .global_reset(Grst));

  	scandff _23_(.Q(Q2[1]), .D(B[1]), .C(clk), .CLR(( ~_DRS0_)), .PRE(1'h0), .NbarT(NBART), .Si(Si3), .global_reset(Grst));

  	scandff _24_(.Q(Q2[2]), .D(B[2]), .C(clk), .CLR(( ~_DRS0_)), .PRE(1'h0), .NbarT(NBART), .Si(Q2[1]), .global_reset(Grst));

  	scandff _25_(.Q(Q2[3]), .D(B[3]), .C(clk), .CLR(( ~_DRS0_)), .PRE(1'h0), .NbarT(NBART), .Si(Q2[2]), .global_reset(Grst));

  	scandff _26_(.Q(cnt[0]), .D(_6_[0]), .C(clk), .CLR(( ~_2_)), .PRE(1'h0), .NbarT(NBART), .Si(Q2[3]), .global_reset(Grst));

  	scandff _27_(.Q(_6_[1]), .D(_7_[1]), .C(clk), .CLR(( ~_2_)), .PRE(1'h0), .NbarT(NBART), .Si(cnt[0]), .global_reset(Grst));

  	scandff _28_(.Q(_6_[2]), .D(_7_[2]), .C(clk), .CLR(( ~_2_)), .PRE(1'h0), .NbarT(NBART), .Si(Si4), .global_reset(Grst));

  	scandff _29_(.Q(_6_[3]), .D(_7_[3]), .C(clk), .CLR(( ~_2_)), .PRE(1'h0), .NbarT(NBART), .Si(_6_[2]), .global_reset(Grst));

  	scandff _30_(.Q(Q1[0]), .D(A[0]), .C(_MUX0_), .CLR(( ~_2_)), .PRE(1'h0), .NbarT(NBART), .Si(_6_[3]), .global_reset(Grst));

  	scandff _31_(.Q(Q1[1]), .D(A[1]), .C(_MUX0_), .CLR(( ~_2_)), .PRE(1'h0), .NbarT(NBART), .Si(Q1[0]), .global_reset(Grst));

  	scandff _32_(.Q(Q1[2]), .D(A[2]), .C(_MUX0_), .CLR(( ~_2_)), .PRE(1'h0), .NbarT(NBART), .Si(Q1[1]), .global_reset(Grst));

  	scandff _33_(.Q(Q1[3]), .D(A[3]), .C(_MUX0_), .CLR(( ~_2_)), .PRE(1'h0), .NbarT(NBART), .Si(Q1[2]), .global_reset(Grst));

  	scandff _34_(.Q(CK), .D(_0_), .C(clk), .CLR(( ~_2_)), .PRE(1'h0), .NbarT(NBART), .Si(Q1[3]), .global_reset(Grst));

  INVX1 _8_ (
    .A(cnt[0]),
    .Y(_6_[0])
  );
  INVX1 _9_ (
    .A(CK),
    .Y(_0_)
  );
  assign _7_[0] = _6_[0];
  assign cnt[3:1] = _6_[3:1];
	scandff _dummy0_(.Q(_DMY0_), .D(1'h0), .C(clk), .CLR(1'h0), .PRE(1'h0), .NbarT(NBART), .Si(Q3[1]), .global_reset(Grst));

	scandff _dummy1_(.Q(_DMY1_), .D(1'h0), .C(clk), .CLR(1'h0), .PRE(1'h0), .NbarT(NBART), .Si(_DMY0_), .global_reset(Grst));

	scandff _dummy2_(.Q(_DMY2_), .D(1'h0), .C(clk), .CLR(1'h0), .PRE(1'h0), .NbarT(NBART), .Si(_DMY1_), .global_reset(Grst));

	scandff _dummy3_(.Q(_DMY3_), .D(1'h0), .C(clk), .CLR(1'h0), .PRE(1'h0), .NbarT(NBART), .Si(_DMY2_), .global_reset(Grst));

	scandff _dummy4_(.Q(_DMY4_), .D(1'h0), .C(clk), .CLR(1'h0), .PRE(1'h0), .NbarT(NBART), .Si(_DMY3_), .global_reset(Grst));

	scandff _dummy5_(.Q(_DMY5_), .D(1'h0), .C(clk), .CLR(1'h0), .PRE(1'h0), .NbarT(NBART), .Si(Q2[0]), .global_reset(Grst));

	scandff _dummy6_(.Q(_DMY6_), .D(1'h0), .C(clk), .CLR(1'h0), .PRE(1'h0), .NbarT(NBART), .Si(_DMY5_), .global_reset(Grst));

	scandff _dummy7_(.Q(_DMY7_), .D(1'h0), .C(clk), .CLR(1'h0), .PRE(1'h0), .NbarT(NBART), .Si(_DMY6_), .global_reset(Grst));

	scandff _dummy8_(.Q(_DMY8_), .D(1'h0), .C(clk), .CLR(1'h0), .PRE(1'h0), .NbarT(NBART), .Si(_DMY7_), .global_reset(Grst));

	scandff _dummy9_(.Q(_DMY9_), .D(1'h0), .C(clk), .CLR(1'h0), .PRE(1'h0), .NbarT(NBART), .Si(_6_[1]), .global_reset(Grst));

	scandff _dummy10_(.Q(_DMY10_), .D(1'h0), .C(clk), .CLR(1'h0), .PRE(1'h0), .NbarT(NBART), .Si(_DMY9_), .global_reset(Grst));

	 assign So1 = _DMY4_;
	 assign So2 = _DMY8_;
	 assign So3 = _DMY10_;
	 assign So4 = CK;
endmodule

module scandff (Q, D, C, CLR, PRE, NbarT, Si, global_reset);

	input D, C, CLR, PRE, NbarT, Si, global_reset;
	output reg Q;

	wire rst = CLR || global_reset;

	always @ (posedge C, posedge PRE, posedge rst)begin
		if (rst)
			Q <= 1'b0;
		else if (PRE)
			Q <= 1'b1;
		else if (NbarT)
			 Q <= Si;
		else
			Q <= D;

	end

endmodule
