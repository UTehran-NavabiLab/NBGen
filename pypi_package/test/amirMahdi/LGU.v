module LGU (
    input signed [15:0] in0,
    input signed [15:0] in1,
    output signed [15:0] out,
    input AND,
    input NOT,
    input [1:0] SHF,
    output Z,
    output N
);

    assign out = (AND == 1'b1) ? in0 & in1 :
                 (NOT == 1'b1) ? ~in0 :
                 (SHF == 2'b00) ? in0 >>> in1 :
                 (SHF == 2'b01) ? in0 >> in1 :
                 (SHF == 2'b10) ? in0 << in1:
                 16'b0;

    assign Z = ~(|out);
    assign N = out[15];

endmodule
