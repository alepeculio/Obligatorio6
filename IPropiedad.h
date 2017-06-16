#ifndef IPROPIEDAD_H
#define IPROPIEDAD_H

#include "IDictionary.h"
#include "ICollection.h"
#include "DtApartamento.h"
#include "DtCasa.h"
#include "DtInmoProp.h"

#include <string>
#include <iostream>
using namespace std;

class IPropiedad {
public:
    virtual void ingresarEdificio(string, int, float) = 0;

    virtual ICollection* listarDepartamentos() = 0;
    virtual ICollection* listarZonas(string) = 0;
    virtual void selectZona(int) = 0;
    virtual ICollection* listarEdificios() = 0;
    virtual void selectEdificio(string) = 0;
    virtual bool fijarAlquiler(float) = 0;
    virtual bool fijarVenta(float) = 0;
    virtual int altaApto(DtApartamento*) = 0;
    virtual int altaCasa(DtCasa*) = 0;

    virtual ICollection* listarPropiedades(int) = 0;
    virtual DtInmoProp* selectPropiedad(int) = 0;

    virtual void seleccionarPropiedad(int) = 0;
    virtual void modificarApart(DtApartamento*) = 0;
    virtual void modificarCasa(DtCasa*) = 0;

    virtual void eliminarPropiedad(int) = 0;

    virtual ICollection* listarMensajes(int) = 0;
    virtual void ingresarMensaje(string, string) = 0;

    virtual IDictionary* listarConversaciones() = 0;
    virtual ICollection* listarMensajesConversacion(int) = 0;
    virtual void ingresarMensajeConversacion(string, string) = 0;

    virtual ICollection* obtenerReporteInmobiliaria(string) = 0;


};

#endif