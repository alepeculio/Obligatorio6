#ifndef IKEY_H_
#define IKEY_H_

#include "ICollectible.h"

class IKey : public ICollectible {
public:
    virtual bool equals(IKey* key) = 0;
    virtual ~IKey();
};

#endif