#ifndef CONTROLADORPROPIEDAD_H
#define CONTROLADORPROPIEDAD_H

#include "IPropiedad.h"
#include "IDictionary.h"
#include "ICollection.h"
#include "DtApartamento.h"
#include "DtCasa.h"
#include "IUsuario.h"
#include "Propiedad.h"
#include <string>
#include <iostream>
using namespace std;

class ControladorPropiedad : public IPropiedad {
private:
    IDictionary* departamentos;
    IDictionary* edificios;
    IDictionary* propiedades;
    IDictionary* zonas;
    IUsuario* iUsuario;

    Propiedad* propiedad;

public:
    ControladorPropiedad(IUsuario*);

    void setDepartamentos(IDictionary*);
    void setEdificios(IDictionary*);

    IDictionary* getDepartamentos();
    IDictionary* getEdificios();
    IDictionary* getPropiedades();
    IDictionary* getZonas();
    
    ICollection* listarPropiedades(int);
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
    void ingresarEdificio(string, int, float);
    DtInmoProp* selectPropiedad(int);
    void seleccionarPropiedad(int);
    void modificarApart(DtApartamento*);
    void modificarCasa(DtCasa*);

    ~ControladorPropiedad();
};

#endif