// Benchmark "abc_bench" written by ABC on Tue Aug 30 13:47:13 2022

module abc_bench ( 
    \counter_reg[0] , \counter_reg[1] , \counter_reg[2] , \counter_reg[3] ,
    clk, en, rst,
    co, \counter[0] , \counter[1] , \counter[2] , \counter[3] , _00_, _21_,
    _01_, _02_, _03_  );
  input  \counter_reg[0] , \counter_reg[1] , \counter_reg[2] ,
    \counter_reg[3] , clk, en, rst;
  output co, \counter[0] , \counter[1] , \counter[2] , \counter[3] , _00_,
    _21_, _01_, _02_, _03_;
  wire new__04__, new__05__, new__06__, new__07__, new__08__, new__19__,
    new__09__, new__10__, new__11__, new__12__, new__13__, new__14__,
    new__15__, new__16__, new__17__, new__20__;
  assign new__04__ = ~\counter_reg[0] ;
  assign new__05__ = ~\counter_reg[3] ;
  assign new__06__ = ~new__20__;
  assign new__07__ = ~\counter_reg[0]  | ~\counter_reg[1] ;
  assign new__08__ = ~\counter_reg[3]  | ~\counter_reg[2] ;
  assign new__19__ = ~new__07__ & ~new__08__;
  assign new__09__ = ~new__04__ & ~new__06__;
  assign new__10__ = ~\counter_reg[0]  & ~new__20__;
  assign _00_ = ~new__09__ & ~new__10__;
  assign new__11__ = ~new__06__ & ~new__07__;
  assign new__12__ = ~\counter_reg[1]  & ~new__09__;
  assign _01_ = ~new__11__ & ~new__12__;
  assign new__13__ = ~\counter_reg[2]  | ~new__11__;
  assign new__14__ = ~new__13__;
  assign new__15__ = ~\counter_reg[2]  & ~new__11__;
  assign _02_ = ~new__14__ & ~new__15__;
  assign new__16__ = ~\counter_reg[3]  & ~new__14__;
  assign new__17__ = ~new__05__ & ~new__13__;
  assign _03_ = ~new__16__ & ~new__17__;
  assign co = new__19__;
  assign \counter[0]  = \counter_reg[0] ;
  assign \counter[1]  = \counter_reg[1] ;
  assign \counter[2]  = \counter_reg[2] ;
  assign \counter[3]  = \counter_reg[3] ;
  assign new__20__ = en;
  assign _21_ = rst;
endmodule


