#ifndef _ListaIterator_H_
#define _ListaIterator_H_

#include "IIterator.h"
#include "Nodo.h"

class ListaIterator : public IIterator {
private:
    Nodo *actual;

public:
    ListaIterator(Nodo *);

    bool hasNext();
    ICollectible *next();
    ICollectible *getCurrent();
    void remove();
};

#endif