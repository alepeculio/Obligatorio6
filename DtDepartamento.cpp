#include "DtDepartamento.h"

DtDepartamento::DtDepartamento(string matricula, string nombre) {
    this->letra = matricula[0];
    this->matricula = matricula;
    this->nombre = nombre;
}

char DtDepartamento::getLetra() {
    return this->letra;
}

string DtDepartamento::getMatricula() {
    return this->matricula;
}

string DtDepartamento::getNombre() {
    return this->nombre;
}

DtDepartamento::~DtDepartamento() {
}