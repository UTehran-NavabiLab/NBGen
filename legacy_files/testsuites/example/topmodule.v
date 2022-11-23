// combination of 8bit shift register and ISCAS benchmark (c17)
module shiftReg_c17 (shiftout,N22,N23,N24,
		N1,N2,N3,N6,N7, sin,clk, reset);

output [7:0] shiftout;
output N22,N23,N24;

input N1,N2,N3,N6,N7;
input sin,clk, reset;


reg [7:0] inter;
wire N10,N11,N16,N19;

nand NAND2_1 (N10, N1, N3);
nand NAND2_2 (N11, N3, N6);
nand NAND2_3 (N16, N2, N11);
nand NAND2_4 (N19, N11, N7);
nand NAND2_5 (N22, N10, N16);
nand NAND2_6 (N23, N16, N19);
nand NAND2_6 (N24, N10, N16);


always @(posedge clk, posedge reset) begin
	if (reset)
		inter <= 0;
	else
		inter <= {inter[6:0], sin};
	end

assign shiftout = inter;

endmodule