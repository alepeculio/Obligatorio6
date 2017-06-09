#ifndef LISTDICCITERATOR_H_
#define LISTDICCITERATOR_H_

#include "NodoDicc.h"
#include "ICollectible.h"
#include "IIterator.h"

class ListDiccIterator : public IIterator {
private:
    NodoDicc* current;
public:
    //constructores
    ListDiccIterator();
    ListDiccIterator(NodoDicc* current);

    //operaciones
    ICollectible *getCurrent();
    bool hasNext();
    ICollectible *next();
    void remove();

    //destructor
    virtual ~ListDiccIterator();
};

#endif