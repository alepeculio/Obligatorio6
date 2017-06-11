#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H

#include "DtDireccion.h"
#include "Usuario.h"
#include <string>
#include <iostream>

using namespace std;

class Inmobiliaria : public Usuario {
private:
    string nombre;
    DtDireccion* direccion;

public:
    Inmobiliaria(string, string, DtDireccion*);

    void setNombre(string); //Setters
    void setUbicacion(DtDireccion*);

    string getNombre(); //Getters
    DtDireccion* getUbicacion();

    ~Inmobiliaria();
};

#endif