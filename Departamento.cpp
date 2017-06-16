#include "Departamento.h"
#include "ICollection.h"
#include "DtDepartamento.h"
#include "ListDicc.h"
#include "Lista.h"
#include "Alquiler.h"
#include "Venta.h"
#include "Zona.h"
#include "KeyInt.h"

Departamento::Departamento(string matricula, string nombre) {
    this->matricula = matricula;
    this->nombre = nombre;
    this ->letra = matricula[0];
    this->zonas = new ListDicc();

    zonas->add(new Zona(0, "Zona0"), new KeyInt(0));
    zonas->add(new Zona(1, "Zona1"), new KeyInt(1));
    zonas->add(new Zona(2, "Zona2"), new KeyInt(2));
    zonas->add(new Zona(3, "Zona3"), new KeyInt(3));
    zonas->add(new Zona(4, "Zona4"), new KeyInt(4));
}

char Departamento::getLetra() {
    return this->letra;
}

string Departamento::getMatricula() {
    return this->matricula;
}

string Departamento::getNombre() {
    return this->nombre;
}

IDictionary* Departamento::getZonas() {
    return this->zonas;
}

void Departamento::setMatricula(string matricula) {
    this->matricula = matricula;
}

void Departamento::setNombre(string nombre) {
    this->nombre = nombre;
}

void Departamento::setZonas(IDictionary* zonas) {
    this->zonas = zonas;
}

Departamento::~Departamento() {
    delete this->zonas;
}

DtDepartamento* Departamento::getDatos() {
    DtDepartamento* dep = new DtDepartamento(this->matricula, this->nombre);
    return dep;
}

ICollection* Departamento::listarZonas() {
    IDictionary* zon = this->getZonas();
    IIterator* iter = zon->getIteratorObj();
    ICollection* res = new Lista();
    while (iter->hasNext()) {
        Zona* z = dynamic_cast<Zona*> (iter->getCurrent());
        res->add(z->getDatos());
        iter->next();
    }
    delete iter;
    return res;
}

DtORIDep* Departamento::obtenerReporteInmobiliaria(string correo) {
    ICollection* dtORIZonas = new Lista();

    IIterator* iterator = zonas->getIteratorObj();
    while (iterator->hasNext()) {
        Zona* z = dynamic_cast<Zona*> (iterator->getCurrent());
        dtORIZonas->add(z->obtenerReporteInmobiliaria(correo));
        iterator->next();
    }
    delete iterator;

    return new DtORIDep(this->nombre, dtORIZonas);
}