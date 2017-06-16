#ifndef CASA_H
#define CASA_H

#include "DtDireccion.h"
#include "Propiedad.h"
#include "DtCasa.h"

#include <string>
#include <iostream>
using namespace std;

class Casa : public Propiedad {
private:
    float m2EspVerde;

public:
    Casa( int, int, int, int, bool, DtDireccion*, float, float, float);
    Casa(DtCasa*);

    void setM2EspVerde(float);

    float getM2EspVerde();

    ~Casa();
};

#endif