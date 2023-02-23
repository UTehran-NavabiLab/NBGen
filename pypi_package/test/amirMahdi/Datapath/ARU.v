module ARU (
    input ADD,
    input MUL,
    input signed [15:0] in0,
    input signed [15:0] in1,

    output Z,
    output N,
    output C,
    output V,
    output signed [15:0] res
);

    wire [15:0] resADD;
    wire [15:0] resMult;

    assign {C, resADD} = in0 + in1;
    assign resMult = in0[7:0] * in1[7:0];

    assign res = (ADD == 1'b1) ? resADD :
                 (MUL == 1'b1) ? resMult :
                 16'b0;

    assign Z = ~(|res);
    assign N = res[15];
    assign V = (in0[15] & in1[15] & ~res[15]) || (~in0[15] & ~in1[15] & res[15]);

endmodule