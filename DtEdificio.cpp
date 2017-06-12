#include "DtEdificio.h"

DtEdificio::DtEdificio(string nombre, int cantPisos, float gastos) {
    this->nomEdificio = nombre;
    this->cantPisos = cantPisos;
    this->gastosComunes = gastos;
}

string DtEdificio::getNomEdificio() {
    return this->nomEdificio;
}

int DtEdificio::getCantPisos() {
    return this->cantPisos;
}

float DtEdificio::getGastosComunes() {
    return this->gastosComunes;
}

DtEdificio::~DtEdificio() {
}
