#ifndef __ITERATOR_H__
#define __ITERATOR_H__
#include <algorithm>
#include <utility>
using namespace std;

template <typename Container, class IteratorBase> // 
class general_iterator
{public:
    //typename Informa al compilador que Container es un tipo de dato (struct o class)
    using Node   = typename Container::Node; 
    using Myself = general_iterator<Container, IteratorBase>;
    
protected:
    Container *m_pContainer;
    Node      *m_pNode;
public:
    //Constructor Parametrizado
    general_iterator(Container *pContainer, Node *pNode)
        : m_pContainer(pContainer), m_pNode(pNode) {}
    //Constructor de copia
    general_iterator(Myself &other) 
          : m_pContainer(other.m_pContainer), m_pNode(other.m_pNode){}
    //Constructor de movimiento
    general_iterator(Myself &&other) // Move constructor
          {   m_pContainer = move(other.m_pContainer);
              m_pNode      = move(other.m_pNode);
          }
    IteratorBase operator=(IteratorBase &iter)
          {   m_pContainer = move(iter.m_pContainer);
              m_pNode      = move(iter.m_pNode);
              //Se aplica herencia → general_iterator hereda de IteratorBase
              return *(IteratorBase *)this; // Pending static_cast? - C-Style  Cast (mala practica)
              //Sintaxis oficial, segura y moderna:
              // Hace exactamente lo mismo, pero el compilador verifica en tiempo de 
              // compilación que la herencia entre las clases sea real y segura.
              //    return *static_cast<IteratorBase*>(this);
          }
    Node *getNode() const { return m_pNode; }
    //Compara direcciones (m_pNode)de dos objetos: a.operator==(b)
    friend bool operator==(const IteratorBase &a, const IteratorBase &b) { return a.getNode() == b.getNode(); }
    //Podemos interpretar → *m_pNode (caja fisica)
    Node &operator*(){ return *m_pNode; }
    //Podemos interpretar → m_pNode (direccion a la caja fisica)
    Node* operator->() const { return m_pNode; }
};

#endif
 