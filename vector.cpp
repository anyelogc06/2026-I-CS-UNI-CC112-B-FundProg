#include "vector.h"
#include "sorting.h"

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