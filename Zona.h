#ifndef ZONA_H
#define ZONA_H

#include "DtZona.h"
#include "ICollectible.h"
#include "ICollection.h"
#include "IDictionary.h"

#include "Propiedad.h"
#include "Ikey.h"
#include "DtORIZona.h"
#include <string>
#include <iostream>
using namespace std;

class Propiedad;

class Zona : public ICollectible {
private:
    int codigo;
    string nombre;
    IDictionary* propiedades;

public:
    Zona(int, string);

    void setCodigo(int);
    void setNombre(string);
    void setPropiedades(IDictionary*);

    int getCodigo();
    string getNombre();
    IDictionary* getPropiedades();

    ~Zona();

    ICollection* listarPropiedad();
    DtZona* getDatos();
    void agregar(Propiedad*);
    void eliminar(IKey*);

    DtORIZona* obtenerReporteInmobiliaria(string);

};

#endif