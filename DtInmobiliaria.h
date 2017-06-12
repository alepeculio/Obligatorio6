#ifndef DTINMOBILIARIA_H
#define DTINMOBILIARIA_H

#include "DtDireccion.h"
#include <string>
#include <iostream>
using namespace std;

class DtInmobiliaria {
private:
    string correo;
    string nombre;
    DtDireccion* direccion;

public:
    DtInmobiliaria(string, string, DtDireccion*);

    string getCorreo();
    string getNombre();
    DtDireccion* getDireccion();

    ~DtInmobiliaria();
};

#endif 