module AES_Encrypt_tb();
	reg [127:0] in1;
	wire [127:0] out1;
	reg [127:0] key1;

	AES_Encrypt a(in1,key1,out1);


	initial begin
	$monitor("in128= %h, key128= %h ,out128= %h",in1,key1,out1);
	in1=128'h_3243f6a8_885a308d_313198a2_e0370734;
	key1=128'h_2b7e1516_28aed2a6_abf71588_09cf4f3c; #10;
	end

endmodule