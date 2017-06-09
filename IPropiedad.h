#ifndef IPROPIEDAD_H
#define IPROPIEDAD_H

#include <string>
#include <iostream>

#include "IDictionary.h"
#include "ICollection.h"
#include "DtApartamento.h"
#include "DtCasa.h"
using namespace std;

class IPropiedad {
public:
    virtual IDictionary* listarPropiedad(int) = 0;
    virtual ICollection* listarMensajes(int) = 0;
    virtual void ingresarMensaje(string, string) = 0;
    virtual IDictionary* listarDepartamentos() = 0;
    virtual IDictionary* listarZonas(string) = 0;
    virtual void selectZona(int) = 0;
    virtual void selectEdificio(string) = 0;
    virtual bool fijarAlquiler(float) = 0;
    virtual bool fijarVenta(float) = 0;
    virtual int altaApto(DtApartamento*) = 0;
    virtual int altaCasa(DtCasa*) = 0;
    virtual void eliminarPropiedad(int) = 0;
};

#endif