/* 
 *--------------------------------------------------------------
 * This module converts a counter value N into a reset value
 * for an 8-bit LFSR.  The count is initialized by "reset" high
 * or "start" transition high.  When the count is valid, it is
 * latched into "dp" and the signal "done" is raised to indicate
 * a valid new value of "dp".
 *--------------------------------------------------------------
 */

module three_level_gate(i0, i1, i2, o);

input         i0;
input         i1;
input         i2;
output  	  o;

wire S1;
wire S2;
wire S3;

and x1(S1, i0, i1);
nor x4(S2, i0, i2);
or x2(S3, S1, i2);
or x3(o, S1, S3);

endmodule