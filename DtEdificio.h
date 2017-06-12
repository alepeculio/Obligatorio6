#ifndef DTEDIFICIO_H
#define DTEDIFICIO_H

#include "ICollectible.h"
#include <iostream>
#include <string>
using namespace std;

class DtEdificio : public ICollectible {
private:
    string nomEdificio;
    int cantPisos;
    float gastosComunes;

public:
    DtEdificio(string, int, float);

    string getNomEdificio();
    int getCantPisos();
    float getGastosComunes();

    ~DtEdificio();
};

#endif