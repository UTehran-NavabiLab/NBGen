module register #(
    parameter N = 16
) (
    input clk,
    input rst,
    input ld,
    input clr,
    input [N-1:0] in,
    output reg [N-1:0] out
);

    always @(posedge clk, posedge rst) begin
        if (rst)
            out <= 'b0;
        else if (clr)
            out <= 1'b0;
        else if (ld)
            out <= in;
    end

endmodule