#ifndef INMOPROP_H
#define INMOPROP_H

#include "ICollection.h"
#include "Inmobiliaria.h"
#include "DtInmobiliaria.h"
#include <string>
#include <iostream>
using namespace std;

class InmoProp {
private:
    Inmobiliaria* inmobiliaria;
    ICollection* avisos;

public:
    InmoProp(Inmobiliaria*);

    void setInmobiliaria(Inmobiliaria*);
    void setAvisos(ICollection*);

    Inmobiliaria* getInmobiliaria();
    ICollection* getAvisos();

    ~InmoProp();

    ICollection* getMensajes(int);
    void ingresarMensaje(string, string, Usuario*);
    void setAlquiler(float);
    void setVenta(float);
    void borrarLinkInmoProp();
    DtInmobiliaria* selectPropiedad();
};

#endif