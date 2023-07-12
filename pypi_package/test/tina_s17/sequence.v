module sequence (
    input clk,
    input rst,
    input x,
    output out
);

    reg [2:0] ps, ns;

    always @(posedge clk,posedge rst) begin
        if(rst)
            ps <= 3'b000;
        else
            ps <= ns;
    end

    always @(x, ps) begin
        ns=3'b000;
        case(ps)
            3'b000: ns = (x == 1'b1) ? 3'b001 : 3'b000;
            3'b001: ns = (x == 1'b1) ? 3'b001 : 3'b010;
            3'b010: ns = (x == 1'b1) ? 3'b011 : 3'b000;
            3'b011: ns = (x == 1'b1) ? 3'b001 : 3'b010;
            default: ns = 3'b000;
        endcase
    end

    assign out = (ps== 3'b011)?1'b1:1'b0;

endmodule
