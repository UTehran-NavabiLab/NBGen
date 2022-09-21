
module NAND2X1 (A, B, Y);
  input A;
  input B;
  output Y;

  not(Y, i_10);
  and(i_10, A, B);

  specify
    (A => Y) = (0.1, 0.1);
    (B => Y) = (0.1, 0.1);
  endspecify

endmodule


module INVX1 (A, Y);
  input A;
  output Y;

  not(Y, A);

  specify
    (A => Y) = (0.1, 0.1);
  endspecify

endmodule


module NAND3X1 (A, B, C, Y);
  input A;
  input B;
  input C;
  output Y;

  not(Y, i_8);
  and(i_8, i_9, C);
  and(i_9, A, B);

  specify
    (A => Y) = (0.1, 0.1);
    (B => Y) = (0.1, 0.1);
    (C => Y) = (0.1, 0.1);
  endspecify

endmodule


module OAI21XL (A0, A1, B0, Y);
  input A0;
  input A1;
  input B0;
  output Y;

  not(Y, i_8);
  and(i_8, A0, i_9);
  or(i_9, A1, B0);

  specify
    if((A1 == 1'b0) && (B0 == 1'b1)) (A0 => Y) = (0.1, 0.1);
    if((A1 == 1'b1) && (B0 == 1'b0)) (A0 => Y) = (0.1, 0.1);
    if((A1 == 1'b1) && (B0 == 1'b1)) (A0 => Y) = (0.1, 0.1);
    (A1 => Y) = (0.1, 0.1);
    (B0 => Y) = (0.1, 0.1);
  endspecify

endmodule


module AND2X1 (A, B, Y);
  input A;
  input B;
  output Y;

  and(Y, A, B);

  specify
    (A => Y) = (0.1, 0.1);
    (B => Y) = (0.1, 0.1);
  endspecify

endmodule


module NOR2X1 (A, B, Y);
  input A;
  input B;
  output Y;

  not(Y, i_10);
  or(i_10, A, B);

  specify
    (A => Y) = (0.1, 0.1);
    (B => Y) = (0.1, 0.1);
  endspecify

endmodule


module BUFX3 (A, Y);
  input A;
  output Y;

  buf(Y, A);

  specify
    (A => Y) = (0.1, 0.1);
  endspecify

endmodule
