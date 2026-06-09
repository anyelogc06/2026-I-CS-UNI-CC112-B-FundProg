#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <iostream>
#include "types.h"

using namespace std;

template <typename T>
void Print(T n) { cout << "valor: " << n << endl; }

template <typename T>
void Print2(T &n) { cout << "valor: " << n << endl; }

template <typename T>
void AddX(T &n, T val1, T val2) { n += val1 + val2; }

template <typename T>
void Square(T &n) { n *= n; }

void CreateVector(TP *&pv, const size_t n);
void ReadVector  (TP *pv, const size_t n);
void PrintVector (TP *pv, const size_t n);
void DeleteVector(TP *&pv);

void DemoPunteros2Vector();

void DemoPointersVector2();
void DemoPointersVector3();
void DemoPointersVector4();
void DemoPointersVector5();

#endif // __VECTOR_H__