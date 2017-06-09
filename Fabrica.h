#ifndef FABRICA_H
#define FABRICA_H

#include "IUsuario.h"
#include "IPropiedad.h"

class Fabrica {
public:
    IUsuario* getIUsuario();
    IPropiedad* getIPropiedad();

    ~Fabrica();
};

#endif