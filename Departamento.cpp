#include "Departamento.h"
#include "ICollection.h"
#include "DtDepartamento.h"

Departamento::Departamento(string matricula, string nombre) {
    this->matricula = matricula;
    this->nombre = nombre;
    this ->letra = matricula[0];
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
}