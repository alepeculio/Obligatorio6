#include "Zona.h"
#include "Lista.h"
#include "ListDicc.h"
#include "IKey.h"
#include "KeyInt.h"
#include "Casa.h"
//#include "Propiedad.h"

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
        resultado->add(iterator->getCurrent());
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

void Zona::eliminar(IKey* p) {
    this->propiedades->removeKey(p);
}

DtORIZona* Zona::obtenerReporteInmobiliaria(string correo) {
    int cantCasas = 0;
    int cantAptos = 0;

    IIterator* props = this->propiedades->getIteratorObj();
    while (props->hasNext()) {
        Propiedad* p = dynamic_cast<Propiedad*> (props->getCurrent());
        if (p->perteneceA(correo)) {
            Casa* casa = dynamic_cast<Casa*> (p);
            if (casa != NULL)
                cantCasas++;
            else
                cantAptos++;
        }
        props->next();
    }
    delete props;

    return new DtORIZona(this->nombre, cantCasas, cantAptos);
}