module seqDetector (
    input clk,
    input rst,
    input serIn,
    output serOutValid
);

    reg [2:0] ps, ns;
    reg serEn;

    always @(posedge clk) begin
        if(rst)
            ps <= 3'b000;
        else
            ps <= ns;
    end

    always @(serIn, ps) begin
        case(ps)
            3'b000: ns = (serIn == 1'b1) ? 3'b001 : 3'b000;
            3'b001: ns = (serIn == 1'b1) ? 3'b001 : 3'b010;
            3'b010: ns = (serIn == 1'b1) ? 3'b011 : 3'b000;
            3'b011: ns = (serIn == 1'b1) ? 3'b001 : 3'b010;
            default: ns = 3'b000;
        endcase
    end

    assign serOutValid = (ps == 3'b011)? 1'b1 : 1'b0;

endmodule