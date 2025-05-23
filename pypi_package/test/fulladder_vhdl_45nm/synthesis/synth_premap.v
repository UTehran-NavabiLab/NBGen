/* Generated by Yosys 0.10+12 (open-tool-forge build) (git sha1 356ec7bb, clang 11.0.3 ) */

module fulladder(i0, i1, ci, s, co);
  wire _00_;
  wire _01_;
  wire _02_;
  wire _03_;
  wire _04_;
  wire _05_;
  wire _06_;
  wire _07_;
  input ci;
  output co;
  input i0;
  input i1;
  output s;
  OAI21_X1 _08_ (
    .A(_05_),
    .B1(_03_),
    .B2(_06_),
    .ZN(_02_)
  );
  NAND2_X1 _09_ (
    .A1(_00_),
    .A2(_02_),
    .ZN(_04_)
  );
  NAND2_X1 _10_ (
    .A1(_06_),
    .A2(_03_),
    .ZN(_00_)
  );
  XNOR2_X1 _11_ (
    .A(_06_),
    .B(_03_),
    .ZN(_01_)
  );
  XNOR2_X1 _12_ (
    .A(_05_),
    .B(_01_),
    .ZN(_07_)
  );
  BUF_X1 _13_ (
    .A(ci),
    .Z(_03_)
  );
  BUF_X1 _14_ (
    .A(_04_),
    .Z(co)
  );
  BUF_X1 _15_ (
    .A(i0),
    .Z(_05_)
  );
  BUF_X1 _16_ (
    .A(i1),
    .Z(_06_)
  );
  BUF_X1 _17_ (
    .A(_07_),
    .Z(s)
  );
endmodule
