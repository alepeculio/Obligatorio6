#ifndef DTPROPIEDAD_H
#define DTPROPIEDAD_H

#include "DtDireccion.h"
#include "ICollectible.h"

class DtPropiedad : public ICollectible {
private:
    int codigo;
    int cantAmb;
    int cantDorm;
    int cantBanios;
    bool garage;
    DtDireccion* direccion;
    float m2Edificados;
    float m2Tot;

public:
    DtPropiedad(int, int, int, int, bool, DtDireccion*, float, float);

    int getCodigo();
    int getCantAmb();
    int getCantDorm();
    int getCantBanios();
    bool getGarage();
    DtDireccion* getDireccion();
    float getM2Edificados();
    float getM2Tot();

    ~DtPropiedad();
};

#endif