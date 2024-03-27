module AES(enable, in, key128, expected128, decrypted128, encrypted128, e128, d128);
	input enable;
	input[127:0] in;
	input[127:0] key128;
	input[127:0] expected128;
	output[127:0] decrypted128, encrypted128;
	output wire e128;
	output wire d128;
	
	//wire[127:0] encrypted128;

	assign e128 = (encrypted128 == expected128 && enable) ? 1'b1 : 1'b0;

	//wire[127:0] decrypted128;

	AES_Encrypt a(in,key128,encrypted128);

	AES_Decrypt a2(encrypted128,key128,decrypted128);

	assign d128 = (decrypted128 == in && enable) ? 1'b1 : 1'b0;

endmodule