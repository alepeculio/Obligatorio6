#ifndef LISTDICCITERATORKEY_H_
#define LISTDICCITERATORKEY_H_


#include "ListDiccIterator.h"
#include "NodoDicc.h"
#include "ICollectible.h"

class ListDiccIteratorKey : public ListDiccIterator {
public:
    ListDiccIteratorKey(NodoDicc* nodo);
    virtual~ListDiccIteratorKey();
    ICollectible* getCurrent();
};

#endif