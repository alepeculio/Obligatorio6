#ifndef CONTROLADORPROPIEDAD_H
#define CONTROLADORPROPIEDAD_H

#include "IPropiedad.h"
#include "IDictionary.h"
#include "ICollection.h"
#include "DtApartamento.h"
#include "DtCasa.h"
#include <string>
#include <iostream>
using namespace std;

class ControladorPropiedad : public IPropiedad {
private:
    IDictionary* departamentos;
    IDictionary* edificios;
public:
    ControladorPropiedad(IDictionary*, IDictionary*);

    void setDepartamentos(IDictionary*);
    void setEdificios(IDictionary*);

    IDictionary* getDepartamentos();
    IDictionary* getEdificios();


    IDictionary* listarPropiedad(int);
    ICollection* listarMensajes(int);
    void ingresarMensaje(string, string);
    ICollection* listarDepartamentos();
    ICollection* listarZonas(string);
    void selectZona(int);
    void selectEdificio(string);
    bool fijarAlquiler(float);
    bool fijarVenta(float);
    int altaApto(DtApartamento*);
    int altaCasa(DtCasa*);
    void eliminarPropiedad(int);

    ~ControladorPropiedad();
};

#endif