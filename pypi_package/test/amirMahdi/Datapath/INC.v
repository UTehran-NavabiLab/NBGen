module INC (
    input [15:0] in,
    input [1:0] inc_val,

    output [15:0] out
);

    assign out = in + inc_val;

endmodule