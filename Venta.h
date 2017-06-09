#ifndef VENTA_H
#define VENTA_H

#include <string>
#include <iostream>
using namespace std;

class Venta : public Aviso {
private:
    float precioV;

public:
    Venta(float, ICollection*);

    void setPrecioV(int);

    int getPrecioV();

    ~Venta();

};

#endif