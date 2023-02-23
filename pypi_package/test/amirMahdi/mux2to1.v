module mux2to1 #(
    parameter N = 16
) (
    input sel0,
    input sel1,
    input [N-1:0] in0,
    input [N-1:0] in1,

    output [N-1:0] out
);

    assign out = (sel0 == 1'b1) ? in0 :
                 (sel1 == 1'b1) ? in1 :
                 {({N-1}){1'b0}};

endmodule