#ifndef DTORIINMO_H
#define DTORIINMO_H

#include "ICollectible.h"
#include "DtInmobiliaria.h"
#include "ICollection.h"

class DtORIInmo : public ICollectible {
private:
    DtInmobiliaria* dtInmobiliaria;
    ICollection* dtORIDeps;

public:
    DtORIInmo(DtInmobiliaria*, ICollection*);

    DtInmobiliaria* getInmobiliaria();
    ICollection* getDtORIDeps();

    ~DtORIInmo();
};

#endif