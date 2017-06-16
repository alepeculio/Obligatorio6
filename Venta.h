#ifndef VENTA_H
#define VENTA_H

#include "Aviso.h"
#include <string>
#include <iostream>
using namespace std;

class Venta : public Aviso {
private:
    float precioV;

public:
    Venta(float);

    void setPrecioV(int);

    int getPrecioV();

    string getTipo();

    ~Venta();
};

#endif