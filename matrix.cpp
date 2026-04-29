#include <iostream>
#include <fstream> // ofstream
#include "matrix.h"
#include "cmatrix.h"

using namespace std;

void DemoMatrix1(){
    size_t rows, cols;
    TP **pMat = nullptr;

    cout << "Demostracion de matrizes" << endl;
    cout << "Ingrese nro de filas: ";
    cin >> rows;
    cout << "Ingrese nro de columnas: ";
    cin >> cols;
    
    CreateMatrix(pMat, rows, cols);
    ReadMatrix(pMat, rows, cols, cout, cin);

    ofstream ofs("matriz1.txt");
    // PrintMatrix(pMat, rows, cols, cout);
    PrintMatrix(pMat, rows, cols, ofs);
    ofs.close();

    DeleteMatrix(pMat, rows);

    // Ejercicio: Leer la matriz,
    //          luego aumentar 1 a cada elemento
    //          finalmente guardar en un archivo de texto   
    ifstream ifs("matriz1.txt");
    
    TP **pMat2 = nullptr;
    ifs >> rows >> cols;
    CreateMatrix(pMat2, rows, cols);
    ReadMatrix(pMat2, rows, cols, cerr, ifs);
    ifs.close();
    TransformarMatriz(pMat2, rows, cols);
    ofstream ofs2("matriz2.txt");
    PrintMatrix(pMat2, rows, cols, ofs2);
    ofs2.close();
    DeleteMatrix(pMat2, rows);

    // cout << "\nEjercicio con textos" << endl;
    // string **pMat3 = nullptr;
    // cout << "Ingrese nro de filas: ";
    // cin >> rows;
    // cout << "Ingrese nro de columnas: ";
    // cin >> cols;

    // CreateMatrix(pMat3, rows, cols);
    // ReadMatrix(pMat3, rows, cols, cout, cin);
    // PrintMatrix(pMat3, rows, cols, cout);
    // ofstream ofs3("matriz3.txt");
    // PrintMatrix(pMat3, rows, cols, ofs3);
    // ofs3.close();
    // DeleteMatrix(pMat3, rows);    
}

//Correspondiente a 14-MatrixTemplate:
/*
void Sumar1(TP &element){
    element += 1;
}

void DemoCMatrix1(){
    size_t rows, cols;
    cout << "Demostracion de matrizes" << endl;
    cout << "Ingrese nro de filas: ";
    cin >> rows;
    cout << "Ingrese nro de columnas: ";
    cin >> cols;
    
    CMatrix<TP> m1(rows, cols);
    m1.ReadMatrix(cin);
    m1.PrintMatrix(cout);
    m1.TransformarMatriz(&Sumar1);

    m1.PrintMatrix(cout);
    // Ahora con funciones lambda
    m1.TransformarMatriz([](TP &x){ x *= 2; });
    m1.PrintMatrix(cout);

    ofstream ofs("matriz1.txt");
    m1.PrintMatrix(ofs);
    ofs.close();
}*/
