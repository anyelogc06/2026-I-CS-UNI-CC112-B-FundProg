#include <iostream>     // cout 
#include "arit.h"       // suma, resta
#include "util.h"       // fact, fib, Mayor, Menor
#include "sorting.h"    // bubble, Merge, Quick, Binary
#include "punteros.h"   //
#include "vector.h"     // create, read, print, delete
#include "matrix.h"     // create, read, transf, print, delete
#include "cmatrix.h"
#include "cvector.h"    // class Cvector

// Antes: g++ -std=c++2b main.cpp arit.cpp -o main
// Ahora                : make
// Limpia los temporales: make clean
// Compile todo.        : make -B
// Luego: ./main

// El main() debe ser muy pero muy pequeñito
int main() {
    std::cout << "HelloX FundProg-UNI!" << std::endl;
    // DemoAritmetica();
    // DemoUtil();
    // DemoSorting();
    // DemoSearch();
    // DemoPunteros1();
    // DemoPunteros2Vector();
    // DemoMatrix1(); 
    DemoCVector();
    return 0;
}