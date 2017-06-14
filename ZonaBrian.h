#ifndef ZONA_H
#define ZONA_H

#include "DtZona.h"
#include "ICollectible.h"
#include "ICollection.h"
#include "Propiedad.h"
#include "IDictionary.h"
#include <string>
#include <iostream>
using namespace std;

class Zona: public ICollectible {
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

    ICollection* listarPropiedad(); //cambio.
    DtZona* getDatos();
    void agregar(Propiedad*);
    void eliminar(Propiedad*);
};

#endif