module Tristate (
    input oe,
    input [15:0] in,
    output [15:0] out
);

    assign out = oe ? in : 16'bz;

endmodule