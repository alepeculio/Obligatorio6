#ifndef DTCASA_H
#define DTCASA_H

#include "DtDireccion.h"
#include "DtPropiedad.h"

class DtCasa : public DtPropiedad {
private:
    float m2EspVerde;

public:
    DtCasa(int, int, int, int, bool, DtDireccion*, float, float, float);

    float getM2EspVerde();

    ~DtCasa();
};

#endif