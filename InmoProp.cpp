#include "InmoProp.h"
#include "Aviso.h"

InmoProp::InmoProp(Inmobiliaria* inmobiliaria) {
    this->inmobiliaria = inmobiliaria;
}

void InmoProp::setInmobiliaria(Inmobiliaria* inmobiliaria) {
    this->inmobiliaria = inmobiliaria;
}

void InmoProp::setAvisos(ICollection* avisos) {
    this->avisos = avisos;
}

Inmobiliaria* InmoProp::getInmobiliaria() {
    return this->inmobiliaria;
}

ICollection* InmoProp::getAvisos() {
    return this->avisos;
}

InmoProp::~InmoProp() {
    delete this->avisos;
    delete this->inmobiliaria;
}

ICollection* InmoProp::getMensajes(int) {
}

void InmoProp::ingresarMensaje(string texto, string aov, Usuario* interesado) {
    IIterator* iterator = this->avisos->iterator();

    while (iterator->hasNext()) {
        Aviso* aviso = dynamic_cast<Aviso*> (iterator->getCurrent());
        string tipo = aviso->getTipo();

        if (aov == tipo)
            aviso->ingresarMensaje(texto, interesado);

        iterator->next();
    }
}

void InmoProp::setAlquiler(float) {
}

void InmoProp::setVenta(float) {
}

void InmoProp::borrarLinkInmoProp() {
}