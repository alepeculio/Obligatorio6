#include "DtInmoProp.h"

DtInmoProp::DtInmoProp(DtPropiedad* dtPropiedad, DtInmobiliaria* dtInmbiliaria) {
    this->dtPropiedad = dtPropiedad;
    this->dtInmobiliaria = dtInmbiliaria;
}

DtPropiedad* DtInmoProp::getDtPropiedad() {
    return this->dtPropiedad;
}

DtInmobiliaria* DtInmoProp::getDtInmobiliaria() {
    return this->dtInmobiliaria;
}

DtInmoProp::~DtInmoProp() {
    delete this->dtPropiedad;
    delete this->dtInmobiliaria;
}