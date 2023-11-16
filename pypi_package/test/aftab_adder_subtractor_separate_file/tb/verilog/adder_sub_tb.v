`timescale 1ns/1ns

module adder_sub_tb();
    reg [31:0] a;
    reg [31:0] b;
    reg subsel;
    reg pass;
    wire cout;
    wire [31:0] result;

    aftab_adder_subtractor MUT(a, b, subsel, pass, cout, result);

    // initial repeat (1000) #10 clk = ~clk;
    initial begin
    	$dumpfile("adder_sub.vcd");
	    $dumpvars(0,adder_sub_tb);
    end

    initial begin
    // add 40 + 2 = 42
    pass = 1'b0;
    subsel = 1'b0;
    a = 32'd40;
    b = 32'd2;
    #20;
    // add 50 + 2 = 52
    pass = 1'b0;
    subsel = 1'b0;
    a = 32'd50;
    b = 32'd2;
    #20;
    // sub 10 + 2 = 8
    pass = 1'b0;
    subsel = 1'b1;
    a = 32'd10;
    b = 32'd2;
    #20;
    // sub 20 + 2 = 18
    pass = 1'b0;
    subsel = 1'b1;
    a = 32'd20;
    b = 32'd2;
    #20;
    // test pass 
    pass = 1'b1;
    #20;
    subsel = 1'b0;
    a = 32'd50;
    b = 32'd2;
    #20;
    $finish;
    end
endmodule