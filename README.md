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


# FACTORIAL and FIBONACCI functionality

Fibonnacci 

Added a new recursive function **r_fib()** which can be called by the **fib()** to compute the n^th Fibonnaci number.

**it supports bigints**
the key is adding an additional argument to **r_fib()**, a memoization table implemented as an **unordered_map.**

Computing Fibonacci numbers recursively can be **really** computationally expensive, but by taking advantage of memoization, it can be quite fast.

Factorial

Added recursive function **factorial()**
This function works for any numeric type that supports multiplication: `int`, `double`, `bigint`, etc. 

It returns the same type given as its argument: `int` for `int`, `bigint` for `bigint`, and so on. 
