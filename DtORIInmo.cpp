#include "DtORIInmo.h"

DtORIInmo::DtORIInmo(DtInmobiliaria* dtInmobiliaria, ICollection* dtORIDeps) {
    this->dtInmobiliaria = dtInmobiliaria;
    this->dtORIDeps = dtORIDeps;
}

DtInmobiliaria* DtORIInmo::getInmobiliaria() {
    return this->dtInmobiliaria;
}

ICollection* DtORIInmo::getDtORIDeps() {
    return this->dtORIDeps;
}

DtORIInmo::~DtORIInmo() {
    delete this->dtInmobiliaria;
    delete this->dtORIDeps;
}