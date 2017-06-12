#include "DtPropiedad.h"

DtPropiedad::DtPropiedad(int codigo, int cantAmb, int cantDorm, int cantBanios, bool garage, DtDireccion* direccion, float m2Edificados, float m2Tot) {
    this->codigo = codigo;
    this->cantAmb = cantAmb;
    this->cantDorm = cantDorm;
    this->cantBanios = cantBanios;
    this->garage = garage;
    this->direccion = direccion;
    this->m2Edificados = m2Edificados;
    this->m2Tot = m2Tot;
}

int DtPropiedad::getCodigo() {
    return this->codigo;
}

int DtPropiedad::getCantAmb() {
    return this->cantAmb;
}

int DtPropiedad::getCantDorm() {
    return this->cantDorm;
}

int DtPropiedad::getCantBanios() {
    return this->cantBanios;
}

bool DtPropiedad::getGarage() {
    return this->garage;
}

DtDireccion* DtPropiedad::getDireccion() {
    return this->direccion;
}

float DtPropiedad::getM2Edificados() {
    return this->m2Edificados;
}

float DtPropiedad::getM2Tot() {
    return this->m2Tot;
}

DtPropiedad::~DtPropiedad() {
    delete this->direccion;
}