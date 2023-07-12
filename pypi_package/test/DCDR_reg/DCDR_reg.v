module register( input clk, rst, input [3:0] A, B,C, output reg[3:0] Q1, Q2, Q3);
  
  reg CK;
  wire R;
  reg [3:0] cnt; 
  always@(posedge clk, posedge rst) begin
    if(rst) 
      CK <=0;
    else
      CK <= ~CK;
  end
  
  always@(posedge CK , posedge rst) begin
    if(rst)
      Q1 <= 0;
    else
      Q1 <= A;
  end
  
  always@(posedge clk , posedge rst) begin
    if(rst)
      cnt <= 0;
    else
      cnt <= cnt + 1;
  end
  
  assign R = &(cnt);
  
  always@(posedge clk , posedge R) begin
    if(R)
      Q2 <= 0;
    else
      Q2 <= B;
  end
  
  always@(posedge CK , posedge R) begin
    if(R)
      Q3 <= 0;
    else
      Q3 <= C;
  end
  
endmodule

