#ifndef __SORTING_H__
#define __SORTING_H__
#include <iostream>
#include "types.h"
// #include "compareFunc.h"
using namespace std;
using ContainerRange    = int;

template <typename Q, typename R> 
void Test(Q q, R r, string s, Q *pQ, R *pR){
    cout << q << " " << r << endl;
    cout << s << endl;
    cout << *pQ << " " << *pR << endl;
}

template <typename Q, typename R> 
auto suma(Q q, R r){
    return q + r;
}

template <typename T> 
void intercambiar(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

template <typename T> 
void PrintArray(T arr[], ContainerRange n){
    for (auto i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

// Búsqueda Binaria recursiva
template <typename T, typename Func> 
ContainerRange BinarySearch(T arr[], ContainerRange first, ContainerRange last, 
                            T elem, Func func){
    if (first > last)
        return -1;
    auto mid = first + (last - first) / 2;
    if (arr[mid] == elem)
        return mid;
    if ( func(elem, arr[mid]) )
        return BinarySearch(arr, mid + 1, last, elem, func);
    return BinarySearch(arr, first, mid - 1, elem, func);
}

// Videos: https://www.youtube.com/watch?v=ZZuD6iUe3Pc
// Bubble 
template <typename T, typename Func> 
void BurbujaClasico(T arr[], ContainerRange n, Func func) {
    if (n <= 1)
        return;
    for (auto i = 0; i < n - 1; ++i)
        for (auto j = i+1; j < n; ++j)
            if( func(arr[i], arr[j]) )
                intercambiar(arr[i], arr[j]);
}

// Bubble
template <typename T, typename Func> 
void BurbujaRecursivo(T arr[], ContainerRange n, Func func) {
    if (n <= 1)
        return;
    for (auto j = 1; j < n; ++j)
        if ( func(arr[j], arr[0]) )
            intercambiar(arr[0], arr[j]);
    BurbujaRecursivo(arr+1, n-1, func);
}

//
template <typename T, typename Func, typename Ord>
ContainerRange AutoBinarySearch(T arr[], ContainerRange first, ContainerRange last, T elem, Ord ord, Func func){
    if (ord){
        return BinarySearch(arr, first, last, elem, func);
    }
    return BinarySearch(arr, first, last, elem, func);
}
void DemoBinarySearch();
//

void DemoBurbuja();

void DemoSorting();
void DemoSearch();

#endif // __SORTING_H__