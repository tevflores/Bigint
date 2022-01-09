#ifndef _fact_h
#define _fact_h

#include "bigint/bigint.h"
template <typename T>
T factorial(T t){
    if (t>1) return t*factorial(t-1);
    return 1;
}



#endif