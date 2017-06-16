#include "Edificio.h"
#include "ListDicc.h"
#include "KeyInt.h"

Edificio::Edificio(string nombre, int cantPisos, float gastos) {
    this->nomEdificio = nombre;
    this->cantPisos = cantPisos;
    this->gastosComunes = gastos;
    this->apartamentos = new ListDicc();
}

void Edificio::setNomEdificio(string nombre) {
    this->nomEdificio = nombre;
}

void Edificio::setCantPisos(int cantPisos) {
    this->cantPisos = cantPisos;
}

void Edificio::setGastosComunes(int gastos) {
    this->gastosComunes = gastos;
}

void Edificio::setApartamento(IDictionary* apartamentos) {
    this->apartamentos = apartamentos;
}

string Edificio::getNomEdificio() {
    return this->nomEdificio;
}

int Edificio::getCantPisos() {
    return this->cantPisos;
}

int Edificio::getGastosComunes() {
    return this->gastosComunes;
}

IDictionary* Edificio::getApartamento() {
    return this->apartamentos;
}

Edificio::~Edificio() {
    delete this->apartamentos;
}

void Edificio::agregarApto(Apartamento* apartamento) {
    this->apartamentos->add(apartamento, new KeyInt(apartamento->getCodigo()));
}

void Edificio::eliminar(Propiedad* propiedad) {
    this->apartamentos->removeKey(new KeyInt(propiedad->getCodigo()));
}

DtEdificio* Edificio::getDatos() {
    DtEdificio* dte = new DtEdificio(this->nomEdificio,this->cantPisos,this->gastosComunes);
    return dte;
}