module IMM (
    input conOF,
    input SE12bits,
    input SE4bits,
    input selLOP,
    input [11:0] inIR,
    input [3:0] inOF,

    output [15:0] Imm
);

    assign Imm = (conOF == 1'b1) ? {inOF, inIR} :
                 (selLOP == 1'b1) ? {inOF, 12'b0} :
                 (SE12bits == 1'b1) ? {{12{inIR[3]}}, inIR[3:0]} :
                 (SE4bits == 1'b1) ? {{4{inIR[11]}}, inIR} :
                 16'b0;

endmodule