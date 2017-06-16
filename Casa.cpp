#include "Casa.h"
#include "DtDireccion.h"

Casa::Casa(DtCasa* dtCasa)
: Propiedad(dtCasa->getCodigo(), dtCasa->getCantAmb(), dtCasa->getCantDorm(), dtCasa->getCantBanios(), dtCasa->getGarage(), dtCasa->getDireccion(), dtCasa->getM2Edificados(), dtCasa->getM2Tot()) {
    this->m2EspVerde = dtCasa->getM2EspVerde();
}

Casa::Casa(int codigo, int cantAmb, int cantDorm, int cantBanios, bool garage, DtDireccion* direccion, float m2Edificios, float m2Tot, float m2EspVerde)
: Propiedad(codigo, cantAmb, cantDorm, cantBanios, garage, direccion, m2Edificios, m2Tot) {
    this->m2EspVerde = m2EspVerde;
}

void Casa::setM2EspVerde(float m2EspVerde){
    this->m2EspVerde  = m2EspVerde;
}

float Casa::getM2EspVerde() {
    return this->m2EspVerde;
}

Casa::~Casa() {
}