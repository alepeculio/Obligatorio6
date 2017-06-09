#include "DtCasa.h"
#include "DtPropiedad.h"

DtCasa::DtCasa(int codigo, int cantAmb, int cantDorm, int cantBanios, bool garage, DtDireccion* direccion, float m2Edificios, float m2Tot, float m2EspVerde)
: DtPropiedad(codigo, cantAmb, cantDorm, cantBanios, garage, direccion, m2Edificios, m2Tot) {
    this->m2EspVerde = m2EspVerde;
}

float DtCasa::getM2EspVerde() {
    return this->m2EspVerde;
}

DtCasa::~DtCasa() {
}