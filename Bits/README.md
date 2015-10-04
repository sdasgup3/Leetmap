When shifting left, there is no difference between arithmetic and logical shift. When shifting right, the type of shift depends on the type of the value being shifted.

(As background for those readers unfamiliar with the difference, a "logical" right shift by 1 bit shifts all the bits to the right and fills in the leftmost bit with a 0. An "arithmetic" shift leaves the original value in the leftmost bit. The difference becomes important when dealing with negative numbers.)

When shifting an unsigned value, the >> operator in C is a logical shift. When shifting a signed value, the >> operator is an arithmetic shift.
