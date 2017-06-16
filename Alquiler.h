#ifndef ALQUILER_H
#define ALQUILER_H

#include "Aviso.h"
#include <string>
#include <iostream>
using namespace std;

class Alquiler : public Aviso {
private:
    float precioA;

public:
    Alquiler(float);

    void setPrecioA(int);

    int getPrecioA();

    string getTipo();

    ~Alquiler();
};

#endif