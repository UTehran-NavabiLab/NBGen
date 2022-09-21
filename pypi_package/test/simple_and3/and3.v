/* 
 *--------------------------------------------------------------
 * This module converts a counter value N into a reset value
 * for an 8-bit LFSR.  The count is initialized by "reset" high
 * or "start" transition high.  When the count is valid, it is
 * latched into "dp" and the signal "done" is raised to indicate
 * a valid new value of "dp".
 *--------------------------------------------------------------
 */

module and3(i0, i1, i2, o);

input         i0;
input         i1;
input         i2;
output  	  o;

and x1(o, i0, i1, i2);

endmodule