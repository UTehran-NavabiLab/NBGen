/* Generated by Yosys 0.10+12 (open-tool-forge build) (git sha1 356ec7bb, clang 11.0.3 ) */

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
  wire _27_;
  wire _28_;
  wire _29_;
  wire _30_;
  wire [3:0] _31_;
  wire _32_;
  wire _33_;
  wire _34_;
  wire _35_;
  wire _36_;
  wire _37_;
  input clk;
  input clkEn;
  output co;
  output [3:0] count;
  input en;
  input rst;
  notg #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _38_ (
    .A(_31_[0]),
    .Y(_04_)
  );
  notg #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _39_ (
    .A(_31_[3]),
    .Y(_05_)
  );
  notg #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _40_ (
    .A(_31_[2]),
    .Y(_06_)
  );
  notg #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _41_ (
    .A(_31_[1]),
    .Y(_07_)
  );
  notg #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _42_ (
    .A(_33_),
    .Y(_08_)
  );
  nand_n #(
    .n(32'sd2),
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _43_ (
    .A({ _04_, _31_[3] }),
    .Y(_09_)
  );
  nand_n #(
    .n(32'sd2),
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _44_ (
    .A({ _06_, _31_[1] }),
    .Y(_10_)
  );
  nor_n #(
    .n(32'sd2),
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _45_ (
    .A({ _09_, _10_ }),
    .Y(_30_)
  );
  nand_n #(
    .n(32'sd2),
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _46_ (
    .A({ _29_, _32_ }),
    .Y(_11_)
  );
  nor_n #(
    .n(32'sd2),
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _47_ (
    .A({ _04_, _11_ }),
    .Y(_12_)
  );
  notg #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _48_ (
    .A(_12_),
    .Y(_13_)
  );
  nand_n #(
    .n(32'sd2),
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _49_ (
    .A({ _04_, _11_ }),
    .Y(_14_)
  );
  nand_n #(
    .n(32'sd2),
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _50_ (
    .A({ _08_, _14_ }),
    .Y(_15_)
  );
  nor_n #(
    .n(32'sd2),
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _51_ (
    .A({ _12_, _15_ }),
    .Y(_00_)
  );
  nor_n #(
    .n(32'sd2),
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _52_ (
    .A({ _07_, _13_ }),
    .Y(_16_)
  );
  nand_n #(
    .n(32'sd2),
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _53_ (
    .A({ _31_[1], _12_ }),
    .Y(_17_)
  );
  nor_n #(
    .n(32'sd2),
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _54_ (
    .A({ _31_[1], _12_ }),
    .Y(_18_)
  );
  nor_n #(
    .n(32'sd2),
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _55_ (
    .A({ _33_, _18_ }),
    .Y(_19_)
  );
  nand_n #(
    .n(32'sd2),
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _56_ (
    .A({ _17_, _19_ }),
    .Y(_20_)
  );
  notg #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _57_ (
    .A(_20_),
    .Y(_01_)
  );
  nand_n #(
    .n(32'sd2),
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _58_ (
    .A({ _31_[2], _16_ }),
    .Y(_21_)
  );
  nor_n #(
    .n(32'sd2),
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _59_ (
    .A({ _31_[2], _16_ }),
    .Y(_22_)
  );
  nor_n #(
    .n(32'sd2),
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _60_ (
    .A({ _33_, _22_ }),
    .Y(_23_)
  );
  nand_n #(
    .n(32'sd2),
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _61_ (
    .A({ _21_, _23_ }),
    .Y(_24_)
  );
  notg #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _62_ (
    .A(_24_),
    .Y(_02_)
  );
  nor_n #(
    .n(32'sd2),
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _63_ (
    .A({ _05_, _21_ }),
    .Y(_25_)
  );
  nand_n #(
    .n(32'sd2),
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _64_ (
    .A({ _05_, _21_ }),
    .Y(_26_)
  );
  nand_n #(
    .n(32'sd2),
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _65_ (
    .A({ _08_, _26_ }),
    .Y(_27_)
  );
  nor_n #(
    .n(32'sd2),
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _66_ (
    .A({ _25_, _27_ }),
    .Y(_03_)
  );
  dff #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _67_ (
    .C(_28_),
    .CE(1'h1),
    .D(_00_),
    .NbarT(1'h0),
    .PRE(1'h0),
    .Q(_31_[0]),
    .R(1'h0),
    .Si(_34_),
    .global_reset(1'h0)
  );
  dff #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _68_ (
    .C(_28_),
    .CE(1'h1),
    .D(_01_),
    .NbarT(1'h0),
    .PRE(1'h0),
    .Q(_31_[1]),
    .R(1'h0),
    .Si(_35_),
    .global_reset(1'h0)
  );
  dff #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _69_ (
    .C(_28_),
    .CE(1'h1),
    .D(_02_),
    .NbarT(1'h0),
    .PRE(1'h0),
    .Q(_31_[2]),
    .R(1'h0),
    .Si(_36_),
    .global_reset(1'h0)
  );
  dff #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _70_ (
    .C(_28_),
    .CE(1'h1),
    .D(_03_),
    .NbarT(1'h0),
    .PRE(1'h0),
    .Q(_31_[3]),
    .R(1'h0),
    .Si(_37_),
    .global_reset(1'h0)
  );
  bufg #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _71_ (
    .A(clk),
    .Y(_28_)
  );
  bufg #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _72_ (
    .A(clkEn),
    .Y(_29_)
  );
  bufg #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _73_ (
    .A(_30_),
    .Y(co)
  );
  bufg #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _74_ (
    .A(_31_[0]),
    .Y(count[0])
  );
  bufg #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _75_ (
    .A(_31_[1]),
    .Y(count[1])
  );
  bufg #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _76_ (
    .A(_31_[2]),
    .Y(count[2])
  );
  bufg #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _77_ (
    .A(_31_[3]),
    .Y(count[3])
  );
  bufg #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _78_ (
    .A(en),
    .Y(_32_)
  );
  bufg #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _79_ (
    .A(rst),
    .Y(_33_)
  );
endmodule
