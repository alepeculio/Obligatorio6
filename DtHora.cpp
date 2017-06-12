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

ostream& operator<<(ostream& os, const DtHora& hora) {
    os << hora.min << ":" << hora.hora;
    return os;
}

DtHora::~DtHora() {
}