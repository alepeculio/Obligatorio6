#include "DtORIDep.h"

DtORIDep::DtORIDep(string nombre, ICollection* dtORIZonas) {
    this->nombre = nombre;
    this->dtORIZonas = dtORIZonas;
}

string DtORIDep::getNombre() {
    return this->nombre;
}

ICollection* DtORIDep::getDtORIZonas() {
    return this->dtORIZonas;
}

DtORIDep::~DtORIDep() {
    delete dtORIZonas;
}