/* Generated by Yosys 0.10+12 (open-tool-forge build) (git sha1 356ec7bb, clang 11.0.3 ) */

module seqDetector(NBART, Grst, clk, rst, serIn, serOutValid);
  input NBART;
	input Grst;
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
  input clk;
  wire [3:0] ps;
  input rst;
  input serIn;
  output serOutValid;
  INVX1 _11_ (
    .A(rst),
    .Y(_4_)
  );
  NOR2X1 _12_ (
    .A(ps[0]),
    .B(ps[1]),
    .Y(_5_)
  );
  OAI21X1 _13_ (
    .A(_5_),
    .B(serIn),
    .C(_4_),
    .Y(_3_)
  );
  NAND2X1 _14_ (
    .A(serIn),
    .B(_4_),
    .Y(_6_)
  );
  NOR3X1 _15_ (
    .A(ps[0]),
    .B(serOutValid),
    .C(ps[2]),
    .Y(_7_)
  );
  NOR2X1 _16_ (
    .A(_7_),
    .B(_6_),
    .Y(_1_)
  );
  OR2X2 _17_ (
    .A(serIn),
    .B(rst),
    .Y(_8_)
  );
  NOR2X1 _18_ (
    .A(serOutValid),
    .B(ps[2]),
    .Y(_9_)
  );
  NOR2X1 _19_ (
    .A(_9_),
    .B(_8_),
    .Y(_0_)
  );
  INVX1 _20_ (
    .A(ps[1]),
    .Y(_10_)
  );
  NOR2X1 _21_ (
    .A(_10_),
    .B(_6_),
    .Y(_2_)
  );
  DFFPOSX1 _22_ (
    .CLK(clk),
    .D(_3_),
    .Q(ps[0])
  );
  DFFPOSX1 _23_ (
    .CLK(clk),
    .D(_0_),
    .Q(ps[1])
  );
  DFFPOSX1 _24_ (
    .CLK(clk),
    .D(_1_),
    .Q(ps[2])
  );
  DFFPOSX1 _25_ (
    .CLK(clk),
    .D(_2_),
    .Q(serOutValid)
  );
  assign ps[3] = serOutValid;
endmodule