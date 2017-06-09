#include "DtInmoProp.h"

DtInmoProp::DtInmoProp(int codigo, DtDireccion* direccion, bool alquiler, bool venta, int cantAmb, int cantDorm, int cantBanios, bool garage, float m2Edificados, float m2Tot, float m2EspVerde, int nroApto, string nombreInmob, string ubicacionInmob, string correo) {
    this->codigo = codigo;
    this->direccion = direccion;
    this->alquiler = alquiler;
    this->venta = venta;
    this->cantAmb = cantAmb;
    this->cantDorm = cantDorm;
    this->cantBanios = cantBanios;
    this->garage = garage;
    this->m2Edificados = m2Edificados;
    this->m2Tot = m2Tot;
    this->m2EspVerde = m2EspVerde;
    this->nroApto = nroApto;
    this->nombreInmob = nombreInmob;
    this->ubicacionInmob = ubicacionInmob;
    this->correo = correo;
}

int DtInmoProp::getCodigo() {
    return this->codigo;
}

DtDireccion* DtInmoProp::getDireccion() {
    return this->direccion;
}

bool DtInmoProp::getAlquiler() {
    return this->alquiler;
}

bool DtInmoProp::getVenta() {
    return this->venta;
}

int DtInmoProp::getCantAmb() {
    return this->cantAmb;
}

int DtInmoProp::getCantDorm() {
    return this->cantDorm;
}

int DtInmoProp::getCantBanios() {
    return this->cantBanios;
}

bool DtInmoProp::getGarage() {
    return this->garage;
}

float DtInmoProp::getM2Edificados() {
    return this->m2Edificados;
}

float DtInmoProp::getM2Tot() {
    return this->m2Tot;
}

float DtInmoProp::getM2EspVerde() {
    return this->m2EspVerde;
}

int DtInmoProp::getNroApto() {
    return this->nroApto;
}

string DtInmoProp::getNombreInmob() {
    return this->nombreInmob;
}

string DtInmoProp::getUbicacionInmob() {
    return this->ubicacionInmob;
}

string DtInmoProp::getCorreo() {
    return this->correo;
}

DtInmoProp::~DtInmoProp() {
    delete this->direccion;
}