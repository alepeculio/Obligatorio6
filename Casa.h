#ifndef CASA_H
#define CASA_H

#include <string>
#include <iostream>
using namespace std;

class Casa : public Propiedad {
private:
    float m2EspVerde;

public:
    Casa(float, int, int, int, int, bool, DtDireccion*, float, float, InmoProp*);

    void setM2EspVerde(float);

    float getM2EspVerde();

    ~Casa();
};

#endif