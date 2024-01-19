//------------------------------------------------------------------------------
// Title:   Homework 1: Logic design, Verilog modeling and testbenches
// Author:  Nooshin Nosrati
// Date:    01-03-2021
//------------------------------------------------------------------------------

module Counter_4bit (clk, rst, en, co, counter);
	input clk;
	input rst;
	input en;
	output co;
	output [3:0] counter;
	
	reg [3:0] counter;

	always @(posedge clk, posedge rst ) 
	begin
		if(rst)
			counter <= 4'b0000;
		else if (en)
			counter <= counter + 1;
	end
	
	assign co = (counter == 4'b1111) ? 1'b1 : 1'b0;
endmodule
