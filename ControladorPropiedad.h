#ifndef CONTROLADORPROPIEDAD_H
#define CONTROLADORPROPIEDAD_H

#include "IPropiedad.h"
#include <string>
#include <iostream>
using namespace std;

class ControladorPropiedad : public IPropiedad {
public:
    /*Set (DtPropiedad)*/ void listarPropiedad(int);
    /*Set (DtMensaje)*/ void listarMensajes(int);
    void ingresarMensaje(string, string);
    /*Set (DtDepartamento)*/ void listarDepartamentos();
    /*Set (DtZona)*/ void listarZonas(string);
    void selectZona(int);
    void selectEdificio(string);
    bool fijarAlquiler(float);
    bool fijarVenta(float);
    int altaApto(/*DtApartamento*/);
    int altaCasa(/*DtCasa*/);
    void eliminarPropiedad(int);

    ~ControladorPropiedad();
};

#endif