#include "Inmobiliaria.h"

Inmobiliaria::Inmobiliaria(string email, string nombre, DtDireccion* direccion)
: Usuario(email, "") {
    this->nombre = nombre;
    this->direccion = direccion;
}

void Inmobiliaria::setNombre(string nombre) {
    this->nombre = nombre;
}

void Inmobiliaria::setUbicacion(DtDireccion* direccion) {
    this->direccion = direccion;
}

string Inmobiliaria::getNombre() {
    return this->nombre;
}

DtDireccion* Inmobiliaria::getUbicacion() {
    return this->direccion;
}

Inmobiliaria::~Inmobiliaria() {
    delete this->direccion;
}