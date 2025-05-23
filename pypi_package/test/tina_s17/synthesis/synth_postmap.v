/* Generated by Yosys 0.10+12 (open-tool-forge build) (git sha1 356ec7bb, clang 11.0.3 ) */

module \sequence (clk, rst, x, out);
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
  input clk;
  wire \ns[0] ;
  wire \ns[1] ;
  output out;
  wire \ps[0] ;
  wire \ps[1] ;
  input rst;
  input x;
  notg #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _12_ (
    .A(\ps[1] ),
    .Y(_03_)
  );
  notg #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _13_ (
    .A(_09_),
    .Y(_04_)
  );
  nand_n #(
    .n(32'sd2),
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _14_ (
    .A({ \ps[1] , \ps[0]  }),
    .Y(_05_)
  );
  notg #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _15_ (
    .A(_05_),
    .Y(_07_)
  );
  nor_n #(
    .n(32'sd2),
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _16_ (
    .A({ _03_, \ps[0]  }),
    .Y(_00_)
  );
  nand_n #(
    .n(32'sd2),
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _17_ (
    .A({ _09_, _00_ }),
    .Y(_01_)
  );
  nand_n #(
    .n(32'sd2),
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _18_ (
    .A({ \ps[0] , _04_ }),
    .Y(_02_)
  );
  nand_n #(
    .n(32'sd2),
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _19_ (
    .A({ _01_, _02_ }),
    .Y(\ns[1] )
  );
  bufg #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _20_ (
    .A(_09_),
    .Y(\ns[0] )
  );
  dff #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _21_ (
    .C(_06_),
    .CE(1'h1),
    .D(\ns[0] ),
    .NbarT(1'h0),
    .PRE(1'h0),
    .Q(\ps[0] ),
    .R(_08_),
    .Si(_10_),
    .global_reset(1'h0)
  );
  dff #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _22_ (
    .C(_06_),
    .CE(1'h1),
    .D(\ns[1] ),
    .NbarT(1'h0),
    .PRE(1'h0),
    .Q(\ps[1] ),
    .R(_08_),
    .Si(_11_),
    .global_reset(1'h0)
  );
  bufg #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _23_ (
    .A(clk),
    .Y(_06_)
  );
  bufg #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _24_ (
    .A(_07_),
    .Y(out)
  );
  bufg #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _25_ (
    .A(rst),
    .Y(_08_)
  );
  bufg #(
    .tphl(32'sd0),
    .tplh(32'sd0)
  ) _26_ (
    .A(x),
    .Y(_09_)
  );
endmodule
