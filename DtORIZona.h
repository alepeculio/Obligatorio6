#ifndef DTORIZONA_H
#define DTORIZONA_H

#include "ICollectible.h"
#include <string.h>
#include <iostream>
using namespace std;

class DtORIZona : public ICollectible {
private:
    string nombre;
    int cantCasas;
    int cantAptos;

public:
    DtORIZona(string, int, int);

    string getNombre();
    int getCantCasas();
    int getCantAptos();

    ~DtORIZona();
};

#endif