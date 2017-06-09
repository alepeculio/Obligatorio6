#ifndef LISTA_H
#define LISTA_H

#include "ICollection.h"
#include "Nodo.h"
#include "ListaIterator.h"

class Lista : public ICollection {
private:
    Nodo *first;

public:
    Lista();
    ~Lista();

    void add(ICollectible *);
    void remove(ICollectible *);
    bool member(ICollectible *);
    IIterator *iterator();

    bool isEmpty();
};

#endif