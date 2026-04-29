#include "sorting.h"
#include "cvector.h"
#include "util.h"

void DemoCVector(){
    CVector<TP> v1;
    CVector<TP> v2(v1);
    size_t n;
    cout << "Ingrese nro de elementos: ";
    cin  >> n;

    v1.CreateVector(n);
    v1.ReadVector(cin);
    v1.Sort( Mayor<TP>);
    v1.PrintVector(cout);
    
    v1.Sort(&Menor<TP>);
    v1.PrintVector(cout);
    
    //Puntero a un objeto CVector:
    CVector<TP> *pV4 = nullptr;
    //Apuntando al objeto v1.
    pV4 = &v1;
    pV4->Sort(&Mayor<TP>);
    pV4->PrintVector(cout);

    //Puntero apuntando a un nuevo objeto creado en la 
    //memoria dinamica, reservando espacio en el heap:
    CVector<TP> *pV3 = new CVector<TP>();
    pV3->CreateVector(5);
    pV3->ReadVector(cin);
    pV3->Sort(&Mayor<TP>);
    pV3->PrintVector(cout);
    delete pV3;
    
}