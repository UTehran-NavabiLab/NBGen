// **************************************************************************************
// Filename: aftab_adder.v
// Project: AFTAB
// Version: 1.0
// Date: 06/05/2019 04:41:33 PM
//
// Module Name: aftab_adder
// Description:
//
// Dependencies:
//
// File content description:
// adder for AFTAB datapath
//
// **************************************************************************************
`timescale 1ns/1ns

module aftab_adder #(parameter size = 4) (
    input [size-1:0] a,
    input [size-1:0] b,
    input cin,
    output cout,
    output [size-1:0] sum
);

    assign {cout, sum} = a + b + cin;

endmodule
