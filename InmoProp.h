#ifndef INMOPROP_H
#define INMOPROP_H

#include "ICollection.h"
#include <string>
#include <iostream>
using namespace std;

class InmoProp {
private:
    Inmobiliaria* inmobiliaria;
    ICollection* aviso;
public:
    InmoProp(Inmobiliaria*);

    void setInmobiliaria(Inmobiliaria*);
    void setAvisos(ICollection);

    Inmobiliaria* getInmobiliaria();
    ICollection* getAvisos();

    ~InmoProp();

    ICollection* getMensajes(int);
    void ingresarMensaje(string, string, int);
    void setAlquiler(float);
    void setVenta(float);
    void borrarLinkInmoProp();

};

#endif