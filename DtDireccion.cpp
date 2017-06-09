#include "DtDireccion.h"
#include <string>
#include <iostream>
using namespace std;

DtDireccion::DtDireccion(string ciudad, string calle, int numero) {
    this->ciudad = ciudad;
    this->calle = calle;
    this->numero = numero;
}

DtDireccion :: DtDireccion(DtDireccion* d){
    this->ciudad = d->ciudad;
    this->calle = d->calle;
    this->numero = d->numero;
}
string DtDireccion::getCiudad() {
    return this->ciudad;
}

string DtDireccion::getCalle() {
    return this->ciudad;
}

int DtDireccion::getNumero() {
    return this->numero;
}

DtDireccion::~DtDireccion() {
}