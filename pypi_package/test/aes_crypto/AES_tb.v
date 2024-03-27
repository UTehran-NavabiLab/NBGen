module AES_tb();

	wire e128;
	wire d128;
	wire[127:0] encrypted128, decrypted128;
	reg enable;
	reg[127:0] in = 128'h_00112233445566778899aabbccddeeff;
	reg[127:0] key128 = 128'h_000102030405060708090a0b0c0d0e0f;
	reg[127:0] expected128 = 128'h_69c4e0d86a7b0430d8cdb78070b4c55a;

	AES aes(enable, in, key128, expected128, decrypted128, encrypted128, e128, d128);

	initial begin
	$monitor("Encrypt128 = %b, Decrypt128 = %b",
		e128, d128);
	enable = 1;
	#10;
	enable = 0;
	#10;
	enable = 1;
	#10;
	end

endmodule
