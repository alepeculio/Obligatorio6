#ifndef PAR_H_
#define PAR_H_

#include "ICollectible.h"
#include "IKey.h"

class Par : public ICollectible {
private:
    IKey* key;
    ICollectible* object;
public:
    Par();
    Par(ICollectible* object, IKey* key);
    IKey* getKey();
    ICollectible* getObject();
    virtual ~Par();
};

#endif