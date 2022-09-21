module and3(i0, i1, i2, o);

wire _0_;
input i0;
input i1;
input i2;
output o;

AND3_X1 #() 
AND3_X1_1_ (
  .A1({ i2 }),
  .A2({ i0 }),
  .A3({ i1 }),
  .ZN({ _0_ })
);
BUF_X1 #() 
BUF_X1_1_ (
  .A({ _0_ }),
  .Z({ o })
);

endmodule