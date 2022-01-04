#include <unordered_map>
#include "bigint/bigint.h"

typedef std::unordered_map<int, bigint> memo;

bigint r_fib(int n, memo& mem ){
    //created an iteration and set it equals to the number we will be looking for
   memo::iterator i = mem.find(n);
   //if i is not found return the second element of the pair
   if(i!=mem.end()) return i->second;
   //summons the previous two values–except if n is equals to 0 or 1 these values are set to n
   return n<2 ? n : mem[n] = r_fib(n-1, mem) + r_fib(n-2, mem);
}

bigint fib(int n) {
	std::unordered_map<int, bigint> memo;
	return r_fib(n, memo);
}


