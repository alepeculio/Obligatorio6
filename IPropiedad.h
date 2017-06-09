#ifndef IPROPIEDAD_H
#define IPROPIEDAD_H

#include <string>
#include <iostream>
using namespace std;

class IPropiedad {
public:
    /*Set (DtPropiedad)*/ virtual void listarPropiedad(int) = 0;
    /*Set (DtMensaje)*/ virtual void listarMensajes(int) = 0;
    virtual void ingresarMensaje(string, string) = 0;
    /*Set (DtDepartamento)*/ virtual void listarDepartamentos() = 0;
    /*Set (DtZona)*/ virtual void listarZonas(string) = 0;
    virtual void selectZona(int) = 0;
    virtual void selectEdificio(string) = 0;
    virtual bool fijarAlquiler(float) = 0;
    virtual bool fijarVenta(float) = 0;
    virtual int altaApto(/*DtApartamento*/) = 0;
    virtual int altaCasa(/*DtCasa*/) = 0;
    virtual void eliminarPropiedad(int) = 0;
};

#endif