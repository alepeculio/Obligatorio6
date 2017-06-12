#ifndef DTINMOPROP_H
#define DTINMOPROP_H

#include "DtDireccion.h"
#include "DtPropiedad.h"
#include "DtInmobiliaria.h"
#include <string>
#include <iostream>
using namespace std;

class DtInmoProp {
private:
    DtPropiedad* dtPropiedad;
    DtInmobiliaria* dtInmobiliaria;

public:
    DtInmoProp(DtPropiedad*, DtInmobiliaria*);

    DtPropiedad* getDtPropiedad();
    DtInmobiliaria* getDtInmobiliaria();

    ~DtInmoProp();
};

#endif