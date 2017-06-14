#include "ControladorPropiedad.h"
#include "IDictionary.h"
#include "ICollection.h"
#include "IIterator.h"
#include "ListDiccIterator.h"
#include "ListDiccIteratorObj.h"
#include "ICollectible.h"
#include "ListDicc.h"
#include "IKey.h"
#include "Departamento.h"
#include "Lista.h"
#include "Edificio.h"
#include "KeyString.h"
#include "KeyInt.h"
#include "Zona.h"

ControladorPropiedad::ControladorPropiedad(IUsuario* iUsuario) {
    this->iUsuario = iUsuario;

    departamentos = new ListDicc();
    edificios = new ListDicc();
}

void ControladorPropiedad::ingresarEdificio(string nombre, int pisos, float gastos) {
    KeyString* key = new KeyString(nombre);

    if (this->edificios->member(key))
        throw std::invalid_argument("El edificio ya existe");
    else
        this->edificios->add(new Edificio(nombre, pisos, gastos), key);
}

ICollection* ControladorPropiedad::listarDepartamentos() {
    IIterator* iter = departamentos->getIteratorObj();
    ICollection* res = new Lista();
    while (iter->hasNext()) {
        Departamento* dep = dynamic_cast<Departamento*> (iter->getCurrent());
        ICollectible* dtdep = dep->getDatos();
        res->add(dtdep);
        iter->next();
    }

    delete iter;
    return res;
}

IDictionary* ControladorPropiedad::listarZonas(string nombreDep) {

}

void ControladorPropiedad::selectZona(int codigo) {
    KeyInt* k = new KeyInt(codigo);

    if (this->zonasRecordadas->member(k))
        this->zonaRecordada = this->zonasRecordadas->find(k);
    else
        throw std::invalid_argument("La zona no existe");
}

IDictionary* ControladorPropiedad::listarEdificios() {
    ICollection* resultado = new Lista();

    IIterator* iterator = this->edificios->getIteratorObj();
    while (iterator->hasNext()) {
        Edificio* e = dynamic_cast<Edificio*> (iterator->getCurrent());
        resultado->add(e->getDatos());
        iterator->next();
    }
    delete iterator;

    return resultado;
}

void ControladorPropiedad::selectEdificio(string nombreEdificio) {
    KeyString* k = new KeyString(nombreEdificio);

    if (this->edificios->member(k))
        this->edificioRecordado = this->edificios->find(k);
    else
        throw std::invalid_argument("El edificio no existe");
}

bool ControladorPropiedad::fijarAlquiler(float precioAlquiler) {
    precioA = precioAlquiler;
}

bool ControladorPropiedad::fijarVenta(float precioVenta) {
    precioV = precioVenta;
}

int ControladorPropiedad::altaApto(DtApartamento* dtApto) {
    KeyInt* k = new KeyInt(dtApto->getCodigo());

    if (this->propiedades->member(k))
        throw std::invalid_argument("El apartamento ya existe");
    else {
        Apartamento* apto = new Apartamento(dtApto);
        this->propiedades->add(apto, k);

        zonaRecordada->agregar(apto);

        Inmobiliaria* inmo = iUsuario->getUsuarioActual();

        apto->setInmoProp(inmo);

        if (precioA != 0)
            apto->setAlquiler(precioA);

        if (precioV != 0)
            apto->setVenta(precioV);

        int codigo = apto->getCodigo();

        edificioRecordado->agregarApto(apto);

        return codigo;
    }
}

int ControladorPropiedad::altaCasa(DtCasa* dtCasa) {
    KeyInt* k = new KeyInt(dtCasa->getCodigo());

    if (this->propiedades->member(k))
        throw std::invalid_argument("La casa ya existe");
    else {
        Casa* casa = new Casa(dtCasa);
        this->propiedades->add(casa, k);

        zonaRecordada->agregar(casa);

        Inmobiliaria* inmo = iUsuario->getUsuarioActual();

        casa->setInmoProp(inmo);

        if (precioA != 0)
            casa->setAlquiler(precioA);

        if (precioV != 0)
            casa->setVenta(precioV);

        int codigo = casa->getCodigo();

        return codigo;
    }
}

IDictionary* ControladorPropiedad::listarPropiedades(int codigo) {

}

ICollection* ControladorPropiedad::listarMensajes(int codigo) {

}

void ControladorPropiedad::ingresarMensaje(string texto, string aov) {

}

int ControladorPropiedad::altaApto(DtApartamento* dtApto) {

}

int ControladorPropiedad::altaCasa(DtCasa* dtCasa) {

}

void ControladorPropiedad::eliminarPropiedad(int codigo) {

}

DtInmoProp* ControladorPropiedad::selectPropiedad(int codigo) {

}

void ControladorPropiedad::seleccionarPropiedad(int codigo) {

}

void ControladorPropiedad::modificarApart(DtApartamento* dtApto) {
}

void ControladorPropiedad::modificarCasa(DtCasa* dtCasa) {
}

ControladorPropiedad::~ControladorPropiedad() {

}
