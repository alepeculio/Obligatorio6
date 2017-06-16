#include "DtApartamento.h"

DtApartamento::DtApartamento(int codigo, int cantAmb, int cantDorm, int cantBanios, bool garage, DtDireccion* direccion, float m2Edificios, float m2Tot, int num)
: DtPropiedad(codigo, cantAmb, cantDorm, cantBanios, garage, direccion, m2Edificios, m2Tot) {
    this->num = num;
}

int DtApartamento::getNum() {
    return this->num;
}

DtApartamento::~DtApartamento() {
}