#ifndef CONTROLADORPROPIEDAD_H
#define CONTROLADORPROPIEDAD_H

#include "IPropiedad.h"
#include "IDictionary.h"
#include "ICollection.h"
#include "DtApartamento.h"
#include "DtCasa.h"
#include "IUsuario.h"
#include "Propiedad.h"
#include "Zona.h"
#include "Edificio.h"
#include <string>
#include <iostream>
using namespace std;

class ControladorPropiedad : public IPropiedad {
private:
    IUsuario* iUsuario;

    IDictionary* departamentos;
    IDictionary* edificios;
    IDictionary* propiedades;

    IDictionary* zonasRecordadas;
    Zona* zonaRecordada;
    IDictionary* propiedadesRecordadas;
    Propiedad* propiedadRecordada;
    Edificio* edificioRecordado;
    float precioA;
    float precioV;

public:
    ControladorPropiedad(IUsuario*);

    void ingresarEdificio(string, int, float);

    ICollection* listarDepartamentos();
    ICollection* listarZonas(string);
    void selectZona(int);
    ICollection* listarEdificios();
    void selectEdificio(string);
    bool fijarAlquiler(float);
    bool fijarVenta(float);
    int altaApto(DtApartamento*);
    int altaCasa(DtCasa*);

    ICollection* listarPropiedades(int);
    DtInmoProp* selectPropiedad(int);

    void seleccionarPropiedad(int);
    void modificarApart(DtApartamento*);
    void modificarCasa(DtCasa*);

    void eliminarPropiedad(int);

    ICollection* listarMensajes(int);
    void ingresarMensaje(string, string);

    IDictionary* listarConversaciones();
    ICollection* listarMensajesConversacion(int);
    void ingresarMensajeConversacion(string, string);
    
    ICollection* obtenerReporteInmobiliaria(string);


    ~ControladorPropiedad();
};

#endif