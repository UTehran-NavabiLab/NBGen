module mux4to1 #(
    parameter N = 16
) (
    input [N-1:0] in0,
    input [N-1:0] in1,
    input [N-1:0] in2,
    input [N-1:0] in3,
    input sel0,
    input sel1,
    input sel2,
    input sel3,
    output [N-1:0] out
);

    assign out = (sel0 == 1'b1) ? in0 :
                 (sel1 == 1'b1) ? in1 :
                 (sel2 == 1'b1) ? in2 :
                 (sel3 == 1'b1) ? in3 :
                 {({N-1}){1'b0}};

endmodule