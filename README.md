# BigInt

A class for storing very large numbers.


Big integers refer to numbers that are too large to be held in a computers memory.
Integers can range from 0 to 4,294,967,295 on 32 bit systems; and 0 to
18,446,744,073,709,551,615 on 64 bit systems. Though this number may be large,
there are occasions in computation where even larger numbers are needed.


bigints is represented as the following type:
std::vector<vec_bin> number;

Which you can read as “a number is a vector of vec_bins” while a vec_bin is
an integer type that will represent a single digit of a number.
