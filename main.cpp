#include <iostream> // cout 
#include "arit.h"   // suma, resta
#include "util.h"
#include "sorting.h"

// Antes: g++ -std=c++2b main.cpp arit.cpp -o main
// Ahora                : make
// Limpia los temporales: make clean
// Compile todo.        : make -B
// Luego: ./main

// El main() debe ser muy pero muy pequeñito
int main() {
    std::cout << "HelloX FundProg-UNI!" << std::endl;
    // DemoAritmetica();
    //DemoUtil();
    DemoSorting();
    DemoSearch();
    DemoBinarySearch();
    return 0;
}