#ifndef NodoDicc_H_
#define NodoDicc_H_

#include "ICollectible.h"
#include "Par.h"

class NodoDicc : public ICollectible {
private:
    NodoDicc *next;
    Par *par;

public:
    NodoDicc();
    NodoDicc(NodoDicc *, Par *);
    virtual ~NodoDicc();

    void setNext(NodoDicc *);
    NodoDicc *getNext();
    bool hasNext();

    Par* getPar();
    void setPar(Par* par);
};

#endif