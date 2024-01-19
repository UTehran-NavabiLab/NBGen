// **************************************************************************************
// Filename: aftab_adder_subtractor.v
// Project: AFTAB
// Version: 1.0
// Date:
//
// Module Name: aftab_adder_subtractor
// Description:
//
// Dependencies:
//
// File content description:
// adder_subtractor for AFTAB datapath
//
// **************************************************************************************
`timescale 1ns/1ns

module aftab_adder_subtractor #(parameter size = 32) (
    input [size-1:0] a,
    input [size-1:0] b,
    input subsel,
    input pass,
    output cout,
    output [size-1:0] result
);

    wire [size-1:0] bsel;
    wire [size-1:0] addSubRes;

    assign bsel = (subsel == 1'b1) ? ~b : b;

    aftab_adder #(size) adder_sub (
        .a(a),
        .b(bsel),
        .cin(subsel),
        .cout(cout),
        .sum(addSubRes)
    );

    assign result = (pass == 1'b0) ? addSubRes : b;

endmodule
