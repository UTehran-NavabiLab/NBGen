
module fulladder(i0, i1, ci, s, co);

input         i0;
input         i1;
input         ci;
output  	  s;
output  	  co;

xor x1(s, i0, i1, ci);
assign co = (i0 & i1) | (i0 & ci) | (i1 & ci);

endmodule