#ifndef COLLECTION_H
#define COLLECTION_H


#include <string>
#include "IIterator.h"
#include "ICollectible.h"
using namespace std;

class ICollection {
public:
    virtual void add(ICollectible *o) = 0;
    virtual void remove(ICollectible *o) = 0;
    virtual bool member(ICollectible *o) = 0;
    virtual IIterator *iterator() = 0;
    virtual bool isEmpty() = 0;
};

#endif