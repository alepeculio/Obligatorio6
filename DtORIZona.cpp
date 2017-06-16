#include "DtORIZona.h"

DtORIZona::DtORIZona(string nombre, int cantCasas, int cantAptos) {
    this->nombre = nombre;
    this->cantCasas = cantCasas;
    this->cantAptos = cantAptos;
}

string DtORIZona::getNombre() {
    return this->nombre;
}

int DtORIZona::getCantCasas() {
    return this->cantCasas;
}

int DtORIZona::getCantAptos() {
    return this->cantAptos;
}

DtORIZona::~DtORIZona() {
}