#include "InmoProp.h"
#include "Aviso.h"
#include "Alquiler.h"
#include "Venta.h"
#include "IIterator.h"
#include "Lista.h"

InmoProp::InmoProp(Inmobiliaria* inmobiliaria) {
    this->inmobiliaria = inmobiliaria;
    this->avisos = new Lista();
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

ICollection* InmoProp::getMensajes(int codigo) {

    IIterator* iterator = this->avisos->iterator();
    ICollection* ms = new Lista();
    while (iterator->hasNext()) {
        Aviso* aviso = dynamic_cast<Aviso*> (iterator->getCurrent());
        ms = aviso->getMensajes(codigo);
        iterator->next();
    }
    delete iterator;
    return ms;

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

void InmoProp::setAlquiler(float precioA) {
    Alquiler* a = new Alquiler(precioA);
    avisos ->add(a);
}

void InmoProp::setVenta(float precioV) {
    Venta* v = new Venta(precioV);
    avisos ->add(v);
}

void InmoProp::borrarLinkInmoProp() {
    IIterator* it = this->avisos->iterator();
    while (it->hasNext()) {
        Aviso* a = dynamic_cast<Aviso*> (it->getCurrent());
        a->borrarLinkAviso();
        avisos->remove(it->getCurrent());
        delete a;
        it->next();
    }
    delete it;
}

DtInmobiliaria* InmoProp::selectPropiedad() {
    return (this->inmobiliaria->getDatos());
}