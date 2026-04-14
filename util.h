#ifndef __UTIL_H__
#define __UTIL_H__
#include "types.h"

TT1 fib_rec  (T1 n);
TT1 fib_iter (T1 n);
TT1 fact_rec (T1 n);
TT1 fact_iter(T1 n);

template <typename T>
bool Mayor(T a, T b){
    return a > b;
}

template <typename T>
bool Menor(T a, T b){
    return a < b;
}

template <typename T, typename ran>
bool Ascendencia(T arr[],  ran n){
    return arr[0] < arr[n];
}

void DemoUtil();

#endif // __UTIL_H__
