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
  wire _31_;
  wire _32_;
  wire _33_;
  wire _34_;
  wire _35_;
  wire _36_;
  wire _37_;
  wire _38_;
  wire _39_;
  wire _40_;
  input clk;
  input clkEn;
  output co;
  output [3:0] count;
  input en;
  input rst;
  notg #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _41_ (
    .in1(_31_),
    .out1(_04_)
  );
  notg #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _42_ (
    .in1(_34_),
    .out1(_05_)
  );
  notg #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _43_ (
    .in1(_33_),
    .out1(_06_)
  );
  notg #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _44_ (
    .in1(_32_),
    .out1(_07_)
  );
  notg #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _45_ (
    .in1(_36_),
    .out1(_08_)
  );
  nand_n #(
    .n(32'sd2),
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _46_ (
    .in1({ _04_, _34_ }),
    .out1(_09_)
  );
  nand_n #(
    .n(32'sd2),
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _47_ (
    .in1({ _06_, _32_ }),
    .out1(_10_)
  );
  nor_n #(
    .n(32'sd2),
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _48_ (
    .in1({ _09_, _10_ }),
    .out1(_30_)
  );
  nand_n #(
    .n(32'sd2),
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _49_ (
    .in1({ _29_, _35_ }),
    .out1(_11_)
  );
  nor_n #(
    .n(32'sd2),
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _50_ (
    .in1({ _04_, _11_ }),
    .out1(_12_)
  );
  notg #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _51_ (
    .in1(_12_),
    .out1(_13_)
  );
  nand_n #(
    .n(32'sd2),
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _52_ (
    .in1({ _04_, _11_ }),
    .out1(_14_)
  );
  nand_n #(
    .n(32'sd2),
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _53_ (
    .in1({ _08_, _14_ }),
    .out1(_15_)
  );
  nor_n #(
    .n(32'sd2),
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _54_ (
    .in1({ _12_, _15_ }),
    .out1(_00_)
  );
  nor_n #(
    .n(32'sd2),
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _55_ (
    .in1({ _07_, _13_ }),
    .out1(_16_)
  );
  nand_n #(
    .n(32'sd2),
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _56_ (
    .in1({ _32_, _12_ }),
    .out1(_17_)
  );
  nor_n #(
    .n(32'sd2),
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _57_ (
    .in1({ _32_, _12_ }),
    .out1(_18_)
  );
  nor_n #(
    .n(32'sd2),
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _58_ (
    .in1({ _36_, _18_ }),
    .out1(_19_)
  );
  nand_n #(
    .n(32'sd2),
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _59_ (
    .in1({ _17_, _19_ }),
    .out1(_20_)
  );
  notg #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _60_ (
    .in1(_20_),
    .out1(_01_)
  );
  nand_n #(
    .n(32'sd2),
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _61_ (
    .in1({ _33_, _16_ }),
    .out1(_21_)
  );
  nor_n #(
    .n(32'sd2),
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _62_ (
    .in1({ _33_, _16_ }),
    .out1(_22_)
  );
  nor_n #(
    .n(32'sd2),
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _63_ (
    .in1({ _36_, _22_ }),
    .out1(_23_)
  );
  nand_n #(
    .n(32'sd2),
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _64_ (
    .in1({ _21_, _23_ }),
    .out1(_24_)
  );
  notg #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _65_ (
    .in1(_24_),
    .out1(_02_)
  );
  nor_n #(
    .n(32'sd2),
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _66_ (
    .in1({ _05_, _21_ }),
    .out1(_25_)
  );
  nand_n #(
    .n(32'sd2),
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _67_ (
    .in1({ _05_, _21_ }),
    .out1(_26_)
  );
  nand_n #(
    .n(32'sd2),
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _68_ (
    .in1({ _08_, _26_ }),
    .out1(_27_)
  );
  nor_n #(
    .n(32'sd2),
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _69_ (
    .in1({ _25_, _27_ }),
    .out1(_03_)
  );
  dff #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _70_ (
    .C(_28_),
    .CE(1'h1),
    .CLR(1'h0),
    .D(_00_),
    .NbarT(1'h0),
    .PRE(1'h0),
    .Q(_31_),
    .Si(_37_),
    .global_reset(1'h0)
  );
  dff #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _71_ (
    .C(_28_),
    .CE(1'h1),
    .CLR(1'h0),
    .D(_01_),
    .NbarT(1'h0),
    .PRE(1'h0),
    .Q(_32_),
    .Si(_38_),
    .global_reset(1'h0)
  );
  dff #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _72_ (
    .C(_28_),
    .CE(1'h1),
    .CLR(1'h0),
    .D(_02_),
    .NbarT(1'h0),
    .PRE(1'h0),
    .Q(_33_),
    .Si(_39_),
    .global_reset(1'h0)
  );
  dff #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _73_ (
    .C(_28_),
    .CE(1'h1),
    .CLR(1'h0),
    .D(_03_),
    .NbarT(1'h0),
    .PRE(1'h0),
    .Q(_34_),
    .Si(_40_),
    .global_reset(1'h0)
  );
  bufg #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _74_ (
    .in1(clk),
    .out1(_28_)
  );
  bufg #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _75_ (
    .in1(clkEn),
    .out1(_29_)
  );
  bufg #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _76_ (
    .in1(_30_),
    .out1(co)
  );
  bufg #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _77_ (
    .in1(_31_),
    .out1(count[0])
  );
  bufg #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _78_ (
    .in1(_32_),
    .out1(count[1])
  );
  bufg #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _79_ (
    .in1(_33_),
    .out1(count[2])
  );
  bufg #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _80_ (
    .in1(_34_),
    .out1(count[3])
  );
  bufg #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _81_ (
    .in1(en),
    .out1(_35_)
  );
  bufg #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _82_ (
    .in1(rst),
    .out1(_36_)
  );
endmodule