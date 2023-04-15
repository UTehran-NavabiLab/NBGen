module counter (clk, rst, en, clkEn, count, co);

   input clk, rst, en, clkEn;
   output co;
   output reg [3:0] count;
   
   always @(posedge clk)
      if (rst)
         count <= 4'd0;
      else if (clkEn) begin
         if (en)
            count <= count + 4'd1;
      end

   assign co = (count[3] & (~count[2]) & count[1] & (~count[0]));

endmodule