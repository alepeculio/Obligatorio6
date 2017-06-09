#include "DtHora.h"

DtHora::DtHora(int min, int hora) {
    this->min = min;
    this->hora = hora;
}

int DtHora::getMin() {
    return this->min;
}

int DtHora::getHora() {
    return this->hora;
}

DtHora ::~DtHora(){}