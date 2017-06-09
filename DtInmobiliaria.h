#ifndef DTINMOBILIARIA_H
#define DTINMOBILIARIA_H

#include <string>
#include <iostream>
using namespace std;

class DtInmobiliaria {
private:
    string correo;
    string nombre;
    string ubicacion;

public:
    DtInmobiliaria(string, string, string);

    string getCorreo();
    string getNombre();
    string getUbicacion();

    ~DtInmobiliaria();
};

#endif 