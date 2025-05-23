/* Generated by Yosys 0.36 (git sha1 8f07a0d8404, clang 15.0.0 -fPIC -Os) */

module b01(line1, line2, reset, clock, outp, overflw);
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
  wire _41_;
  wire _42_;
  wire _43_;
  wire _44_;
  wire _45_;
  wire _46_;
  wire _47_;
  wire \2.stato[0] ;
  wire \2.stato[1] ;
  wire \2.stato[2] ;
  wire \79.Y[0] ;
  wire \79.Y[1] ;
  wire \79.Y[2] ;
  input clock;
  wire clock;
  input line1;
  wire line1;
  input line2;
  wire line2;
  output outp;
  wire outp;
  output overflw;
  wire overflw;
  input reset;
  wire reset;
  INV_X1 _48_ (
    .A(_02_),
    .ZN(_04_)
  );
  INV_X1 _49_ (
    .A(\2.stato[0] ),
    .ZN(_05_)
  );
  NAND3_X1 _50_ (
    .A1(_05_),
    .A2(\2.stato[1] ),
    .A3(\2.stato[2] ),
    .ZN(_06_)
  );
  NAND2_X1 _51_ (
    .A1(_06_),
    .A2(_04_),
    .ZN(_07_)
  );
  NAND2_X1 _52_ (
    .A1(_44_),
    .A2(_43_),
    .ZN(_08_)
  );
  INV_X1 _53_ (
    .A(_08_),
    .ZN(_09_)
  );
  NOR2_X1 _54_ (
    .A1(_44_),
    .A2(_43_),
    .ZN(_10_)
  );
  NOR2_X1 _55_ (
    .A1(_09_),
    .A2(_10_),
    .ZN(_11_)
  );
  XNOR2_X1 _56_ (
    .A(_11_),
    .B(_07_),
    .ZN(_00_)
  );
  INV_X1 _57_ (
    .A(_10_),
    .ZN(_12_)
  );
  INV_X1 _58_ (
    .A(\2.stato[1] ),
    .ZN(_13_)
  );
  NAND3_X1 _59_ (
    .A1(_13_),
    .A2(\2.stato[0] ),
    .A3(\2.stato[2] ),
    .ZN(_14_)
  );
  AOI21_X1 _60_ (
    .A(_02_),
    .B1(_05_),
    .B2(_13_),
    .ZN(_15_)
  );
  NAND4_X1 _61_ (
    .A1(_15_),
    .A2(_12_),
    .A3(_14_),
    .A4(_06_),
    .ZN(_16_)
  );
  NOR3_X1 _62_ (
    .A1(_04_),
    .A2(_13_),
    .A3(\2.stato[0] ),
    .ZN(_17_)
  );
  NOR3_X1 _63_ (
    .A1(\2.stato[1] ),
    .A2(\2.stato[0] ),
    .A3(_02_),
    .ZN(_18_)
  );
  AOI22_X1 _64_ (
    .A1(_17_),
    .A2(_09_),
    .B1(_18_),
    .B2(_12_),
    .ZN(_19_)
  );
  NAND3_X1 _65_ (
    .A1(_13_),
    .A2(\2.stato[0] ),
    .A3(_02_),
    .ZN(_20_)
  );
  NOR2_X1 _66_ (
    .A1(_20_),
    .A2(_08_),
    .ZN(_21_)
  );
  NAND3_X1 _67_ (
    .A1(\2.stato[1] ),
    .A2(\2.stato[0] ),
    .A3(_02_),
    .ZN(_22_)
  );
  NAND3_X1 _68_ (
    .A1(_13_),
    .A2(_05_),
    .A3(_02_),
    .ZN(_23_)
  );
  AOI21_X1 _69_ (
    .A(_09_),
    .B1(_23_),
    .B2(_22_),
    .ZN(_24_)
  );
  NOR2_X1 _70_ (
    .A1(_24_),
    .A2(_21_),
    .ZN(_25_)
  );
  NOR2_X1 _71_ (
    .A1(_14_),
    .A2(_10_),
    .ZN(_26_)
  );
  NOR2_X1 _72_ (
    .A1(_06_),
    .A2(_08_),
    .ZN(_27_)
  );
  NOR2_X1 _73_ (
    .A1(_26_),
    .A2(_27_),
    .ZN(_28_)
  );
  NAND4_X1 _74_ (
    .A1(_25_),
    .A2(_28_),
    .A3(_16_),
    .A4(_19_),
    .ZN(\79.Y[0] )
  );
  NOR2_X1 _75_ (
    .A1(_20_),
    .A2(_09_),
    .ZN(_29_)
  );
  NOR2_X1 _76_ (
    .A1(_29_),
    .A2(_27_),
    .ZN(_30_)
  );
  NOR2_X1 _77_ (
    .A1(_05_),
    .A2(\2.stato[1] ),
    .ZN(_31_)
  );
  AOI21_X1 _78_ (
    .A(_17_),
    .B1(_31_),
    .B2(\2.stato[2] ),
    .ZN(_32_)
  );
  NAND2_X1 _79_ (
    .A1(_18_),
    .A2(_10_),
    .ZN(_33_)
  );
  NAND4_X1 _80_ (
    .A1(_30_),
    .A2(_32_),
    .A3(_16_),
    .A4(_33_),
    .ZN(\79.Y[1] )
  );
  AOI21_X1 _81_ (
    .A(_21_),
    .B1(_18_),
    .B2(_12_),
    .ZN(_34_)
  );
  NAND2_X1 _82_ (
    .A1(_23_),
    .A2(_22_),
    .ZN(_35_)
  );
  NAND2_X1 _83_ (
    .A1(_35_),
    .A2(_09_),
    .ZN(_36_)
  );
  NAND3_X1 _84_ (
    .A1(_34_),
    .A2(_32_),
    .A3(_36_),
    .ZN(\79.Y[2] )
  );
  AOI21_X1 _85_ (
    .A(_15_),
    .B1(\2.stato[0] ),
    .B2(\2.stato[1] ),
    .ZN(_37_)
  );
  NOR2_X1 _86_ (
    .A1(_37_),
    .A2(\2.stato[2] ),
    .ZN(_01_)
  );
  INV_X1 _87_ (
    .A(_47_),
    .ZN(_03_)
  );
  DFFR_X1 _88_ (
    .CK(_42_),
    .D(\79.Y[0] ),
    .Q(\2.stato[0] ),
    .QN(_41_),
    .RN(_03_)
  );
  DFFR_X1 _89_ (
    .CK(_42_),
    .D(\79.Y[1] ),
    .Q(\2.stato[1] ),
    .QN(_40_),
    .RN(_03_)
  );
  DFFR_X1 _90_ (
    .CK(_42_),
    .D(\79.Y[2] ),
    .Q(\2.stato[2] ),
    .QN(_02_),
    .RN(_03_)
  );
  DFFR_X1 _91_ (
    .CK(_42_),
    .D(_00_),
    .Q(_45_),
    .QN(_39_),
    .RN(_03_)
  );
  DFFR_X1 _92_ (
    .CK(_42_),
    .D(_01_),
    .Q(_46_),
    .QN(_38_),
    .RN(_03_)
  );
  BUF_X1 _93_ (
    .A(clock),
    .Z(_42_)
  );
  BUF_X1 _94_ (
    .A(line1),
    .Z(_43_)
  );
  BUF_X1 _95_ (
    .A(line2),
    .Z(_44_)
  );
  BUF_X1 _96_ (
    .A(_45_),
    .Z(outp)
  );
  BUF_X1 _97_ (
    .A(_46_),
    .Z(overflw)
  );
  BUF_X1 _98_ (
    .A(reset),
    .Z(_47_)
  );
endmodule
