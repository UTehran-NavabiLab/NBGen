
module PriorityA ( E, A, PA, X1 );
  input [8:0] E;
  input [8:0] A;
  output [8:0] X1;
  output PA;
  wire   n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15;

  OAI21_X1 U1 ( .B1(A[8]), .B2(n1), .A(PA), .ZN(X1[8]) );
  OAI21_X1 U2 ( .B1(A[7]), .B2(n2), .A(PA), .ZN(X1[7]) );
  OAI21_X1 U3 ( .B1(A[6]), .B2(n3), .A(PA), .ZN(X1[6]) );
  OAI21_X1 U4 ( .B1(A[5]), .B2(n4), .A(PA), .ZN(X1[5]) );
  OAI21_X1 U5 ( .B1(A[4]), .B2(n5), .A(PA), .ZN(X1[4]) );
  OAI21_X1 U6 ( .B1(A[3]), .B2(n6), .A(PA), .ZN(X1[3]) );
  OAI21_X1 U7 ( .B1(A[2]), .B2(n7), .A(PA), .ZN(X1[2]) );
  OAI21_X1 U8 ( .B1(A[1]), .B2(n8), .A(PA), .ZN(X1[1]) );
  OAI21_X1 U9 ( .B1(A[0]), .B2(n9), .A(PA), .ZN(X1[0]) );
  OR2_X1 U10 ( .A1(n10), .A2(n11), .ZN(PA) );
  OAI221_X1 U11 ( .B1(n6), .B2(A[3]), .C1(n5), .C2(A[4]), .A(n12), .ZN(n11) );
  INV_X1 U12 ( .A(n13), .ZN(n12) );
  OAI222_X1 U13 ( .A1(A[1]), .A2(n8), .B1(A[0]), .B2(n9), .C1(A[2]), .C2(n7), 
        .ZN(n13) );
  INV_X1 U14 ( .A(E[2]), .ZN(n7) );
  INV_X1 U15 ( .A(E[0]), .ZN(n9) );
  INV_X1 U16 ( .A(E[1]), .ZN(n8) );
  INV_X1 U17 ( .A(E[4]), .ZN(n5) );
  INV_X1 U18 ( .A(E[3]), .ZN(n6) );
  OAI221_X1 U19 ( .B1(n2), .B2(A[7]), .C1(n1), .C2(A[8]), .A(n14), .ZN(n10) );
  INV_X1 U20 ( .A(n15), .ZN(n14) );
  OAI22_X1 U21 ( .A1(A[6]), .A2(n3), .B1(A[5]), .B2(n4), .ZN(n15) );
  INV_X1 U22 ( .A(E[5]), .ZN(n4) );
  INV_X1 U23 ( .A(E[6]), .ZN(n3) );
  INV_X1 U24 ( .A(E[8]), .ZN(n1) );
  INV_X1 U25 ( .A(E[7]), .ZN(n2) );
endmodule


module PriorityB ( E, X1, B, PB, X2 );
  input [8:0] E;
  input [8:0] X1;
  input [8:0] B;
  output [8:0] X2;
  output PB;
  wire   n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15, n16,
         n17, n18, n19, n20;

  NAND2_X1 U1 ( .A1(PB), .A2(n1), .ZN(X2[8]) );
  NAND2_X1 U2 ( .A1(PB), .A2(n2), .ZN(X2[7]) );
  NAND2_X1 U3 ( .A1(PB), .A2(n3), .ZN(X2[6]) );
  NAND2_X1 U4 ( .A1(PB), .A2(n4), .ZN(X2[5]) );
  NAND2_X1 U5 ( .A1(PB), .A2(n5), .ZN(X2[4]) );
  NAND2_X1 U6 ( .A1(PB), .A2(n6), .ZN(X2[3]) );
  NAND2_X1 U7 ( .A1(PB), .A2(n7), .ZN(X2[2]) );
  NAND2_X1 U8 ( .A1(PB), .A2(n8), .ZN(X2[1]) );
  NAND2_X1 U9 ( .A1(PB), .A2(n9), .ZN(X2[0]) );
  NAND4_X1 U10 ( .A1(n5), .A2(n4), .A3(n10), .A4(n11), .ZN(PB) );
  AND4_X1 U11 ( .A1(n6), .A2(n7), .A3(n8), .A4(n9), .ZN(n11) );
  NAND3_X1 U12 ( .A1(E[0]), .A2(n12), .A3(X1[0]), .ZN(n9) );
  INV_X1 U13 ( .A(B[0]), .ZN(n12) );
  NAND3_X1 U14 ( .A1(E[1]), .A2(n13), .A3(X1[1]), .ZN(n8) );
  INV_X1 U15 ( .A(B[1]), .ZN(n13) );
  NAND3_X1 U16 ( .A1(E[2]), .A2(n14), .A3(X1[2]), .ZN(n7) );
  INV_X1 U17 ( .A(B[2]), .ZN(n14) );
  NAND3_X1 U18 ( .A1(E[3]), .A2(n15), .A3(X1[3]), .ZN(n6) );
  INV_X1 U19 ( .A(B[3]), .ZN(n15) );
  AND3_X1 U20 ( .A1(n3), .A2(n1), .A3(n2), .ZN(n10) );
  NAND3_X1 U21 ( .A1(E[7]), .A2(n16), .A3(X1[7]), .ZN(n2) );
  INV_X1 U22 ( .A(B[7]), .ZN(n16) );
  NAND3_X1 U23 ( .A1(E[8]), .A2(n17), .A3(X1[8]), .ZN(n1) );
  INV_X1 U24 ( .A(B[8]), .ZN(n17) );
  NAND3_X1 U25 ( .A1(E[6]), .A2(n18), .A3(X1[6]), .ZN(n3) );
  INV_X1 U26 ( .A(B[6]), .ZN(n18) );
  NAND3_X1 U27 ( .A1(E[5]), .A2(n19), .A3(X1[5]), .ZN(n4) );
  INV_X1 U28 ( .A(B[5]), .ZN(n19) );
  NAND3_X1 U29 ( .A1(E[4]), .A2(n20), .A3(X1[4]), .ZN(n5) );
  INV_X1 U30 ( .A(B[4]), .ZN(n20) );
endmodule


module PriorityC ( E, X1, X2, C, PC );
  input [8:0] E;
  input [8:0] X1;
  input [8:0] X2;
  input [8:0] C;
  output PC;
  wire   n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15, n16,
         n17, n18, n19, n20;

  NAND4_X1 U1 ( .A1(n1), .A2(n2), .A3(n3), .A4(n4), .ZN(PC) );
  AND4_X1 U2 ( .A1(n5), .A2(n6), .A3(n7), .A4(n8), .ZN(n4) );
  NAND4_X1 U3 ( .A1(X2[5]), .A2(X1[5]), .A3(E[5]), .A4(n9), .ZN(n8) );
  INV_X1 U4 ( .A(C[5]), .ZN(n9) );
  NAND4_X1 U5 ( .A1(X2[6]), .A2(X1[6]), .A3(E[6]), .A4(n10), .ZN(n7) );
  INV_X1 U6 ( .A(C[6]), .ZN(n10) );
  NAND4_X1 U7 ( .A1(X2[7]), .A2(X1[7]), .A3(E[7]), .A4(n11), .ZN(n6) );
  INV_X1 U8 ( .A(C[7]), .ZN(n11) );
  NAND4_X1 U9 ( .A1(X2[8]), .A2(X1[8]), .A3(E[8]), .A4(n12), .ZN(n5) );
  INV_X1 U10 ( .A(C[8]), .ZN(n12) );
  AND3_X1 U11 ( .A1(n13), .A2(n14), .A3(n15), .ZN(n3) );
  NAND4_X1 U12 ( .A1(X2[2]), .A2(X1[2]), .A3(E[2]), .A4(n16), .ZN(n15) );
  INV_X1 U13 ( .A(C[2]), .ZN(n16) );
  NAND4_X1 U14 ( .A1(X2[0]), .A2(X1[0]), .A3(E[0]), .A4(n17), .ZN(n14) );
  INV_X1 U15 ( .A(C[0]), .ZN(n17) );
  NAND4_X1 U16 ( .A1(X2[1]), .A2(X1[1]), .A3(E[1]), .A4(n18), .ZN(n13) );
  INV_X1 U17 ( .A(C[1]), .ZN(n18) );
  NAND4_X1 U18 ( .A1(X2[3]), .A2(X1[3]), .A3(E[3]), .A4(n19), .ZN(n2) );
  INV_X1 U19 ( .A(C[3]), .ZN(n19) );
  NAND4_X1 U20 ( .A1(X2[4]), .A2(X1[4]), .A3(E[4]), .A4(n20), .ZN(n1) );
  INV_X1 U21 ( .A(C[4]), .ZN(n20) );
endmodule


module EncodeChan ( E, A, B, C, PA, PB, PC, I );
  input [8:0] E;
  input [8:0] A;
  input [8:0] B;
  input [8:0] C;
  output [8:0] I;
  input PA, PB, PC;
  wire   n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15, n16,
         n17, n18;

  NAND3_X1 U1 ( .A1(E[8]), .A2(n1), .A3(n2), .ZN(I[8]) );
  AOI22_X1 U2 ( .A1(PA), .A2(A[8]), .B1(PB), .B2(B[8]), .ZN(n2) );
  NAND2_X1 U3 ( .A1(PC), .A2(C[8]), .ZN(n1) );
  NAND3_X1 U4 ( .A1(E[7]), .A2(n3), .A3(n4), .ZN(I[7]) );
  AOI22_X1 U5 ( .A1(A[7]), .A2(PA), .B1(B[7]), .B2(PB), .ZN(n4) );
  NAND2_X1 U6 ( .A1(C[7]), .A2(PC), .ZN(n3) );
  NAND3_X1 U7 ( .A1(E[6]), .A2(n5), .A3(n6), .ZN(I[6]) );
  AOI22_X1 U8 ( .A1(A[6]), .A2(PA), .B1(B[6]), .B2(PB), .ZN(n6) );
  NAND2_X1 U9 ( .A1(C[6]), .A2(PC), .ZN(n5) );
  NAND3_X1 U10 ( .A1(E[5]), .A2(n7), .A3(n8), .ZN(I[5]) );
  AOI22_X1 U11 ( .A1(A[5]), .A2(PA), .B1(B[5]), .B2(PB), .ZN(n8) );
  NAND2_X1 U12 ( .A1(C[5]), .A2(PC), .ZN(n7) );
  NAND3_X1 U13 ( .A1(E[4]), .A2(n9), .A3(n10), .ZN(I[4]) );
  AOI22_X1 U14 ( .A1(A[4]), .A2(PA), .B1(B[4]), .B2(PB), .ZN(n10) );
  NAND2_X1 U15 ( .A1(C[4]), .A2(PC), .ZN(n9) );
  NAND3_X1 U16 ( .A1(E[3]), .A2(n11), .A3(n12), .ZN(I[3]) );
  AOI22_X1 U17 ( .A1(A[3]), .A2(PA), .B1(B[3]), .B2(PB), .ZN(n12) );
  NAND2_X1 U18 ( .A1(C[3]), .A2(PC), .ZN(n11) );
  NAND3_X1 U19 ( .A1(E[2]), .A2(n13), .A3(n14), .ZN(I[2]) );
  AOI22_X1 U20 ( .A1(A[2]), .A2(PA), .B1(B[2]), .B2(PB), .ZN(n14) );
  NAND2_X1 U21 ( .A1(C[2]), .A2(PC), .ZN(n13) );
  NAND3_X1 U22 ( .A1(E[1]), .A2(n15), .A3(n16), .ZN(I[1]) );
  AOI22_X1 U23 ( .A1(A[1]), .A2(PA), .B1(B[1]), .B2(PB), .ZN(n16) );
  NAND2_X1 U24 ( .A1(C[1]), .A2(PC), .ZN(n15) );
  NAND3_X1 U25 ( .A1(E[0]), .A2(n17), .A3(n18), .ZN(I[0]) );
  AOI22_X1 U26 ( .A1(A[0]), .A2(PA), .B1(B[0]), .B2(PB), .ZN(n18) );
  NAND2_X1 U27 ( .A1(C[0]), .A2(PC), .ZN(n17) );
endmodule


module DecodeChan ( I, Chan );
  input [8:0] I;
  output [3:0] Chan;
  wire   n1, n2, n3, n4, n5, n6, n7, n8, n9;

  AND2_X1 U1 ( .A1(I[8]), .A2(n1), .ZN(Chan[3]) );
  OR4_X1 U2 ( .A1(n2), .A2(n3), .A3(n4), .A4(Chan[2]), .ZN(n1) );
  INV_X1 U3 ( .A(I[0]), .ZN(n3) );
  NAND4_X1 U4 ( .A1(I[7]), .A2(I[6]), .A3(I[5]), .A4(I[4]), .ZN(Chan[2]) );
  NAND3_X1 U5 ( .A1(I[6]), .A2(n5), .A3(I[7]), .ZN(Chan[1]) );
  NAND3_X1 U6 ( .A1(I[4]), .A2(n4), .A3(I[5]), .ZN(n5) );
  NAND2_X1 U7 ( .A1(I[3]), .A2(I[2]), .ZN(n4) );
  OAI21_X1 U8 ( .B1(n6), .B2(n7), .A(I[7]), .ZN(Chan[0]) );
  INV_X1 U9 ( .A(I[6]), .ZN(n7) );
  AOI221_X1 U10 ( .B1(I[2]), .B2(n2), .C1(I[4]), .C2(n8), .A(n9), .ZN(n6) );
  INV_X1 U11 ( .A(I[5]), .ZN(n9) );
  INV_X1 U12 ( .A(I[3]), .ZN(n8) );
  INV_X1 U13 ( .A(I[1]), .ZN(n2) );
endmodule


module TopLevel432b ( E, A, B, C, PA, PB, PC, Chan );
  input [8:0] E;
  input [8:0] A;
  input [8:0] B;
  input [8:0] C;
  output [3:0] Chan;
  output PA, PB, PC;

  wire   [8:0] X1;
  wire   [8:0] X2;
  wire   [8:0] I;

  PriorityA M1 ( .E(E), .A(A), .PA(PA), .X1(X1) );
  PriorityB M2 ( .E(E), .X1(X1), .B(B), .PB(PB), .X2(X2) );
  PriorityC M3 ( .E(E), .X1(X1), .X2(X2), .C(C), .PC(PC) );
  EncodeChan M4 ( .E(E), .A(A), .B(B), .C(C), .PA(PA), .PB(PB), .PC(PC), .I(I)
         );
  DecodeChan M5 ( .I(I), .Chan(Chan) );
endmodule


module Circuit432 ( in4, in17, in30, in43, in56, in69, in82, in95, 
        in108, in1, in11, in24, in37, in50, in63, in76, in89, in102, in8, in21, 
        in34, in47, in60, in73, in86, in99, in112, in14, in27, in40, in53, 
        in66, in79, in92, in105, in115, out223, out329, out370, out421, out430, 
        out431, out432 );
  input  in4, in17, in30, in43, in56, in69, in82, in95, in108, in1,
         in11, in24, in37, in50, in63, in76, in89, in102, in8, in21, in34,
         in47, in60, in73, in86, in99, in112, in14, in27, in40, in53, in66,
         in79, in92, in105, in115;
  output out223, out329, out370, out421, out430, out431, out432;


  TopLevel432b Ckt432 ( .E({in4, in17, in30, in43, in56, in69, in82, in95, 
        in108}), .A({in1, in11, in24, in37, in50, in63, in76, in89, in102}), 
        .B({in8, in21, in34, in47, in60, in73, in86, in99, in112}), .C({in14, 
        in27, in40, in53, in66, in79, in92, in105, in115}), .PA(out223), .PB(
        out329), .PC(out370), .Chan({out421, out430, out431, out432}) );
endmodule

