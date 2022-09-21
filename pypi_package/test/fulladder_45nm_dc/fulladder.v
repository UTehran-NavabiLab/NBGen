/* 
 *--------------------------------------------------------------
 * This module converts a counter value N into a reset value
 * for an 8-bit LFSR.  The count is initialized by "reset" high
 * or "start" transition high.  When the count is valid, it is
 * latched into "dp" and the signal "done" is raised to indicate
 * a valid new value of "dp".
 *--------------------------------------------------------------
 */

module fulladder(i0, i1, ci, s, co);

input         i0;
input         i1;
input         ci;
output  	  s;
output  	  co;

xor x1(s, i0, i1, ci);
assign co = (i0 & i1) | (i0 & ci) | (i1 & ci);

endmodule