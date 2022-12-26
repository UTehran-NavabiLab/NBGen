module MAC(clk, rst, a, b, d);
  
  input clk, rst;
  input [3:0] a,b;
  
  output reg [3:0] d;
  
  reg [3:0] R1, R2;
  reg CK;
  
  always@(posedge clk, posedge rst) begin
    if(rst) CK <= 0;
    else CK <= ~CK;
  end
  
  always@(posedge CK, posedge rst) begin
    if (rst) R1 <= 4'd0;
    else R1 <= a;
  end
  
  always@(posedge CK, posedge rst) begin
    if (rst) R2 <= 4'd0;
    else R2 <= b;
  end
  
  always@(posedge CK, posedge rst) begin
    if(rst) d<=4'd0;
    else d<=R1+R2;
  end
  
endmodule