#include "Zona.h"
#include "Lista.h"
#include "ListDicc.h"
#include "KeyInt.h"

Zona::Zona(int codigo, string nombre) {
    this->codigo = codigo;
    this->nombre = nombre;
    this->propiedades = new ListDicc();
}

void Zona::setCodigo(int codigo) {
    this->codigo = codigo;
}

void Zona::setNombre(string nombre) {
    this->nombre = nombre;
}

void Zona::setPropiedades(IDictionary* propiedades) {
    this->propiedades = propiedades;
}

int Zona::getCodigo() {
    return this->codigo;
}

string Zona::getNombre() {
    return this->nombre;
}

IDictionary* Zona::getPropiedades() {
    return this->propiedades;
}

Zona::~Zona() {
    delete this->propiedades;
}

ICollection* Zona::listarPropiedad() {
    
    ICollection* resultado = new Lista();
    IIterator* iterator = this->propiedades->getIteratorObj();
      while (iterator->hasNext()) {
        Propiedad* prop = dynamic_cast<Propiedad*>(iterator->getCurrent());
        ICollection dtProp = prop->getDatos();
        resultado->add(dtProp)
        iterator->next();
    }
    delete iterator;

    return resultado;
}

DtZona* Zona::getDatos() {
    return new DtZona(this->codigo, this->nombre);
}

void Zona::agregar(Propiedad* propiedad) {
    this->propiedades->add(propiedad, new KeyInt(propiedad->getCodigo()));
}

void Zona::eliminar(Propiedad* propiedad) {
    this->propiedades->removeKey(new KeyInt(propiedad->getCodigo()));
}