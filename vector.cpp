#include <fstream>
#include "vector.h"
#include "sorting.h"
#include "array2.h"
#include "array3.h"
#include "array4.h"
#include "types.h"

void CreateVector(TP *&pv, const size_t n){
    pv = new TP [n];
}

void ReadVector(TP *pv, const size_t n){
    cout << "Ingrese " << n << " valores: ";
    for (size_t i = 0; i < n; ++i)
        cin >> pv[i];
}

void PrintVector(TP *pv, const size_t n){
    for (size_t i = 0; i < n; ++i)
        cout << pv[i] << " ";
    cout << endl;
}

void DeleteVector(TP *&pv){
    delete[] pv;
    pv = nullptr;
}

// Vectores
void DemoPunteros2Vector(){
    cout << "Nivel #1: cachimbo ingeniero\n";
    TP *pVect = nullptr;
    const size_t n = 10;

    // Crear un vector de tamano n
    CreateVector(pVect, n);
    
    // Leer el vector con valores
    ReadVector(pVect, n);
    
    BurbujaClasico(pVect, n, Mayor<TP>);
    PrintVector(pVect, n);
    cout << endl;
    
    BurbujaClasico(pVect, n, Menor<TP>);
    PrintVector(pVect, n);
    cout << endl;
    
    // Eliminar el vector
    DeleteVector(pVect);
}

template <typename T>
void Print(T n) { cout << "valor: " << n << endl; }

template <typename T>
void Print2(T &n) { cout << "valor: " << n << endl; }

template <typename T>
void AddX(T &n, T val1, T val2) { n += val1 + val2; }

template <typename T>
void Square(T &n) { n *= n; }

void DemoPointersVector2(){
    TI *pArray2 = nullptr;
    cout << "Nivel #2 (cachimbo mejor informado (templates))\n";
    cout << "Problemas:\n";
    cout << "* No se puede crear el arreglo en cualquier lugar (solo en el heap)\n";
    cout << "* No tengo una clase para encapsular los datos\n";
    size_t n2;
    cout << "Ingrese el tamaño del vector: ";
    cin >> n2;
    
    CreateArray2(pArray2, n2);
    ReadArray2(pArray2, n2, cin);
    cout << "Vector original: ";
    PrintArray2(pArray2, n2, cout);
    
    cout << "Funcion #1 aplicada:\n";
    ApplyFunctionToAll2(pArray2, n2, Print2<TI>);
    PrintArray2(pArray2, n2, cout);
    
    cout << "Funcion #2 aplicada: ";
    ApplyFunctionToAll2(pArray2, n2, Square<TI>);
    cout << "Vector transformado #3: ";
    PrintArray2(pArray2, n2, cout);

    ofstream ofs("output2.txt");
    PrintArray2(pArray2, n2, ofs);
    ofs.close();

    DeleteArray2(pArray2);
}

void DemoPointersVector3(){
    cout << "Nivel #3 (cachimbo con clase)\n";
    cout << "Ingrese el tamaño del vector: ";
    Array3<TI> array3;
    array3.Read(cin);
    array3.Print(cout);
    array3.ApplyFunctionToAll(Print2<TI>);
    array3.ApplyFunctionToAll(Square<TI>);
    array3.Print(cout);
    ofstream ofs("output3.txt");
    array3.Print(ofs);
    ofs.close();
}

void DemoPointersVector4(){
    cout << "Nivel #4 (cachimbo respetable)\n";
    Array4<TI> array4;
    ifstream ifs("output3.txt");
    array4.Read(ifs);
    cout << "Aplicando Square\n";
    array4.ApplyFunctionToAll(Square<TI>);

    cout << "Imprimiendo en el cout\n";
    array4.ApplyFunctionToAll(Print4<TI>, cout);
    cout << endl;

    cout << "Sumándole 2 valores extras\n";
    array4.ApplyFunctionToAll(AddX<TI>, 5, 10);

    array4.ApplyFunctionToAll(Print4<TI>, cout);
    cout << endl;
}

void DemoPointersVector5(){
    cout << "Nivel #5 (cachimbo CS)\n";
    Array4<TI> array5;
    ifstream ifs("output3.txt");
    ifs >> array5;
    cout << "Aplicando Square\n";
    array5.ApplyFunctionToAll(Square<TI>);

    cout << "Imprimiendo en el cout\n";
    // array5.ApplyFunctionToAll(Print4<T>, cout);
    cout << array5;
    cout << endl;

    cout << "Sumándole 2 valores extras\n";
    array5.ApplyFunctionToAll(AddX<TI>, 5, 10);

    cout << array5 << endl;
    ofstream ofs("output5.txt");
    ofs << array5 ;
}