/* Generated by Yosys 0.36 (git sha1 8f07a0d8404, clang 15.0.0 -fPIC -Os) */

module counter(clk, rst, en, clkEn, count, co);
  wire _00_;
  wire _01_;
  wire _02_;
  wire _03_;
  wire _04_;
  wire _05_;
  wire _06_;
  wire _07_;
  wire _08_;
  wire _09_;
  wire _10_;
  wire _11_;
  wire _12_;
  wire _13_;
  wire _14_;
  wire _15_;
  wire _16_;
  wire _17_;
  wire _18_;
  wire _19_;
  wire _20_;
  wire _21_;
  wire _22_;
  wire _23_;
  wire _24_;
  wire _25_;
  wire _26_;
  wire [3:0] _27_;
  wire _28_;
  wire _29_;
  input clk;
  wire clk;
  input clkEn;
  wire clkEn;
  output co;
  wire co;
  output [3:0] count;
  wire [3:0] count;
  input en;
  wire en;
  input rst;
  wire rst;
  INV_X1 _30_ (
    .A(_27_[2]),
    .ZN(_04_)
  );
  AND4_X1 _31_ (
    .A1(_04_),
    .A2(_27_[3]),
    .A3(_27_[1]),
    .A4(_20_),
    .ZN(_26_)
  );
  INV_X1 _32_ (
    .A(_27_[0]),
    .ZN(_05_)
  );
  NAND2_X1 _33_ (
    .A1(_25_),
    .A2(_28_),
    .ZN(_06_)
  );
  INV_X1 _34_ (
    .A(_29_),
    .ZN(_07_)
  );
  OAI21_X1 _35_ (
    .A(_07_),
    .B1(_06_),
    .B2(_20_),
    .ZN(_08_)
  );
  AOI21_X1 _36_ (
    .A(_08_),
    .B1(_06_),
    .B2(_05_),
    .ZN(_00_)
  );
  INV_X1 _37_ (
    .A(_27_[1]),
    .ZN(_09_)
  );
  NAND3_X1 _38_ (
    .A1(_25_),
    .A2(_28_),
    .A3(_27_[0]),
    .ZN(_10_)
  );
  NAND4_X1 _39_ (
    .A1(_27_[1]),
    .A2(_27_[0]),
    .A3(_25_),
    .A4(_28_),
    .ZN(_11_)
  );
  NAND2_X1 _40_ (
    .A1(_11_),
    .A2(_07_),
    .ZN(_12_)
  );
  AOI21_X1 _41_ (
    .A(_12_),
    .B1(_10_),
    .B2(_09_),
    .ZN(_01_)
  );
  NAND2_X1 _42_ (
    .A1(_27_[2]),
    .A2(_27_[1]),
    .ZN(_13_)
  );
  OAI21_X1 _43_ (
    .A(_07_),
    .B1(_10_),
    .B2(_13_),
    .ZN(_14_)
  );
  AOI21_X1 _44_ (
    .A(_14_),
    .B1(_11_),
    .B2(_04_),
    .ZN(_02_)
  );
  OAI21_X1 _45_ (
    .A(_27_[3]),
    .B1(_10_),
    .B2(_13_),
    .ZN(_15_)
  );
  INV_X1 _46_ (
    .A(_27_[3]),
    .ZN(_16_)
  );
  AND3_X1 _47_ (
    .A1(_27_[0]),
    .A2(_28_),
    .A3(_25_),
    .ZN(_17_)
  );
  AND2_X1 _48_ (
    .A1(_27_[1]),
    .A2(_27_[2]),
    .ZN(_18_)
  );
  NAND3_X1 _49_ (
    .A1(_17_),
    .A2(_16_),
    .A3(_18_),
    .ZN(_19_)
  );
  AOI21_X1 _50_ (
    .A(_29_),
    .B1(_19_),
    .B2(_15_),
    .ZN(_03_)
  );
  DFF_X1 _51_ (
    .CK(_24_),
    .D(_00_),
    .Q(_27_[0]),
    .QN(_20_)
  );
  DFF_X1 _52_ (
    .CK(_24_),
    .D(_01_),
    .Q(_27_[1]),
    .QN(_23_)
  );
  DFF_X1 _53_ (
    .CK(_24_),
    .D(_02_),
    .Q(_27_[2]),
    .QN(_22_)
  );
  DFF_X1 _54_ (
    .CK(_24_),
    .D(_03_),
    .Q(_27_[3]),
    .QN(_21_)
  );
  BUF_X1 _55_ (
    .A(clk),
    .Z(_24_)
  );
  BUF_X1 _56_ (
    .A(clkEn),
    .Z(_25_)
  );
  BUF_X1 _57_ (
    .A(_26_),
    .Z(co)
  );
  BUF_X1 _58_ (
    .A(_27_[0]),
    .Z(count[0])
  );
  BUF_X1 _59_ (
    .A(_27_[1]),
    .Z(count[1])
  );
  BUF_X1 _60_ (
    .A(_27_[2]),
    .Z(count[2])
  );
  BUF_X1 _61_ (
    .A(_27_[3]),
    .Z(count[3])
  );
  BUF_X1 _62_ (
    .A(en),
    .Z(_28_)
  );
  BUF_X1 _63_ (
    .A(rst),
    .Z(_29_)
  );
endmodule
