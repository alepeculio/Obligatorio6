#include "Apartamento.h"
#include "DtApartamento.h"

Apartamento::Apartamento(DtApartamento* dtApto)
: Propiedad(dtApto->getCodigo(), dtApto->getCantAmb(), dtApto->getCantDorm(), dtApto->getCantBanios(), dtApto->getGarage(), dtApto->getDireccion(), dtApto->getM2Edificados(), dtApto->getM2Tot()) {
    this->num = dtApto->getNum();
}

Apartamento::Apartamento(int codigo, int cantAmb, int cantDorm, int cantBanios, bool garage, DtDireccion* direccion, float m2Edificios, float m2Tot, int num)
: Propiedad(codigo, cantAmb, cantDorm, cantBanios, garage, direccion, m2Edificios, m2Tot) {
    this->num = num;
}

void Apartamento::setNum(int num) {
    this->num = num;
}

int Apartamento::getNum() {
    return this->num;
}

Apartamento::~Apartamento() {
}