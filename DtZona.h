#ifndef DTZONA_H
#define DTZONA_H

#include "ICollectible.h"
#include <string>
#include <iostream>
using namespace std;

class DtZona : public ICollectible {
private:
    int codigo;
    string nombre;

public:
    DtZona(int, string);

    int getCodigo();
    string getNombre();

    ~DtZona();
};

#endif