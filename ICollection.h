#ifndef ICOLLECTION_H
#define ICOLLECTION_H

#include "ICollectible.h"
#include "IIterator.h"

class ICollection{
   public:
    virtual void add(ICollectible*) = 0;
    virtual void remove(ICollectible*)= 0;
    virtual void member(ICollectible*)= 0;
    virtual bool isEmpty()= 0;
    virtual int size()= 0;
    virtual IIterator iterator()= 0;
};



#endif /* ICOLLECTION_H */

