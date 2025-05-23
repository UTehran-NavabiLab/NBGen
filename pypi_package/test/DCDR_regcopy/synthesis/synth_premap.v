/* Generated by Yosys 0.10+12 (open-tool-forge build) (git sha1 356ec7bb, clang 11.0.3 ) */

module register(clk, rst, A, B, C, Q1, Q2, Q3);
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
  wire [3:0] _15_;
  wire [3:0] _16_;
  wire [3:0] _17_;
  wire [3:0] _18_;
  wire [3:0] _19_;
  wire [3:0] _20_;
  wire _21_;
  wire _22_;
  input [3:0] A;
  input [3:0] B;
  input [3:0] C;
  wire CK;
  output [3:0] Q1;
  output [3:0] Q2;
  output [3:0] Q3;
  wire R;
  input clk;
  wire \cnt[0] ;
  wire \cnt[1] ;
  wire \cnt[2] ;
  wire \cnt[3] ;
  input rst;
  NOT _23_ (
    .A(\cnt[0] ),
    .Y(_11_)
  );
  NOT _24_ (
    .A(CK),
    .Y(_00_)
  );
  NOT _25_ (
    .A(\cnt[1] ),
    .Y(_01_)
  );
  NOT _26_ (
    .A(\cnt[2] ),
    .Y(_02_)
  );
  NOT _27_ (
    .A(\cnt[3] ),
    .Y(_03_)
  );
  NOR _28_ (
    .A(_11_),
    .B(_01_),
    .Y(_04_)
  );
  NAND _29_ (
    .A(\cnt[0] ),
    .B(\cnt[1] ),
    .Y(_05_)
  );
  NOR _30_ (
    .A(\cnt[0] ),
    .B(\cnt[1] ),
    .Y(_06_)
  );
  NOR _31_ (
    .A(_04_),
    .B(_06_),
    .Y(_12_)
  );
  NOR _32_ (
    .A(_02_),
    .B(_05_),
    .Y(_07_)
  );
  NAND _33_ (
    .A(\cnt[2] ),
    .B(_04_),
    .Y(_08_)
  );
  NOR _34_ (
    .A(\cnt[2] ),
    .B(_04_),
    .Y(_09_)
  );
  NOR _35_ (
    .A(_07_),
    .B(_09_),
    .Y(_13_)
  );
  NOR _36_ (
    .A(_03_),
    .B(_08_),
    .Y(R)
  );
  NOR _37_ (
    .A(\cnt[3] ),
    .B(_07_),
    .Y(_10_)
  );
  NOR _38_ (
    .A(R),
    .B(_10_),
    .Y(_14_)
  );
  DFF_PP0 _39_ (
    .C(CK),
    .D(_17_[0]),
    .Q(_20_[0]),
    .R(R)
  );
  DFF_PP0 _40_ (
    .C(CK),
    .D(_17_[1]),
    .Q(_20_[1]),
    .R(R)
  );
  DFF_PP0 _41_ (
    .C(CK),
    .D(_17_[2]),
    .Q(_20_[2]),
    .R(R)
  );
  DFF_PP0 _42_ (
    .C(CK),
    .D(_17_[3]),
    .Q(_20_[3]),
    .R(R)
  );
  DFF_PP0 _43_ (
    .C(_21_),
    .D(_16_[0]),
    .Q(_19_[0]),
    .R(R)
  );
  DFF_PP0 _44_ (
    .C(_21_),
    .D(_16_[1]),
    .Q(_19_[1]),
    .R(R)
  );
  DFF_PP0 _45_ (
    .C(_21_),
    .D(_16_[2]),
    .Q(_19_[2]),
    .R(R)
  );
  DFF_PP0 _46_ (
    .C(_21_),
    .D(_16_[3]),
    .Q(_19_[3]),
    .R(R)
  );
  DFF_PP0 _47_ (
    .C(_21_),
    .D(_11_),
    .Q(\cnt[0] ),
    .R(_22_)
  );
  DFF_PP0 _48_ (
    .C(_21_),
    .D(_12_),
    .Q(\cnt[1] ),
    .R(_22_)
  );
  DFF_PP0 _49_ (
    .C(_21_),
    .D(_13_),
    .Q(\cnt[2] ),
    .R(_22_)
  );
  DFF_PP0 _50_ (
    .C(_21_),
    .D(_14_),
    .Q(\cnt[3] ),
    .R(_22_)
  );
  DFF_PP0 _51_ (
    .C(CK),
    .D(_15_[0]),
    .Q(_18_[0]),
    .R(_22_)
  );
  DFF_PP0 _52_ (
    .C(CK),
    .D(_15_[1]),
    .Q(_18_[1]),
    .R(_22_)
  );
  DFF_PP0 _53_ (
    .C(CK),
    .D(_15_[2]),
    .Q(_18_[2]),
    .R(_22_)
  );
  DFF_PP0 _54_ (
    .C(CK),
    .D(_15_[3]),
    .Q(_18_[3]),
    .R(_22_)
  );
  DFF_PP0 _55_ (
    .C(_21_),
    .D(_00_),
    .Q(CK),
    .R(_22_)
  );
  BUF _56_ (
    .A(A[0]),
    .Y(_15_[0])
  );
  BUF _57_ (
    .A(A[1]),
    .Y(_15_[1])
  );
  BUF _58_ (
    .A(A[2]),
    .Y(_15_[2])
  );
  BUF _59_ (
    .A(A[3]),
    .Y(_15_[3])
  );
  BUF _60_ (
    .A(B[0]),
    .Y(_16_[0])
  );
  BUF _61_ (
    .A(B[1]),
    .Y(_16_[1])
  );
  BUF _62_ (
    .A(B[2]),
    .Y(_16_[2])
  );
  BUF _63_ (
    .A(B[3]),
    .Y(_16_[3])
  );
  BUF _64_ (
    .A(C[0]),
    .Y(_17_[0])
  );
  BUF _65_ (
    .A(C[1]),
    .Y(_17_[1])
  );
  BUF _66_ (
    .A(C[2]),
    .Y(_17_[2])
  );
  BUF _67_ (
    .A(C[3]),
    .Y(_17_[3])
  );
  BUF _68_ (
    .A(_18_[0]),
    .Y(Q1[0])
  );
  BUF _69_ (
    .A(_18_[1]),
    .Y(Q1[1])
  );
  BUF _70_ (
    .A(_18_[2]),
    .Y(Q1[2])
  );
  BUF _71_ (
    .A(_18_[3]),
    .Y(Q1[3])
  );
  BUF _72_ (
    .A(_19_[0]),
    .Y(Q2[0])
  );
  BUF _73_ (
    .A(_19_[1]),
    .Y(Q2[1])
  );
  BUF _74_ (
    .A(_19_[2]),
    .Y(Q2[2])
  );
  BUF _75_ (
    .A(_19_[3]),
    .Y(Q2[3])
  );
  BUF _76_ (
    .A(_20_[0]),
    .Y(Q3[0])
  );
  BUF _77_ (
    .A(_20_[1]),
    .Y(Q3[1])
  );
  BUF _78_ (
    .A(_20_[2]),
    .Y(Q3[2])
  );
  BUF _79_ (
    .A(_20_[3]),
    .Y(Q3[3])
  );
  BUF _80_ (
    .A(clk),
    .Y(_21_)
  );
  BUF _81_ (
    .A(rst),
    .Y(_22_)
  );
endmodule
