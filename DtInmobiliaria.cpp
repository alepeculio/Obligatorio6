#include "DtInmobiliaria.h"

DtInmobiliaria::DtInmobiliaria(string correo, string nombre, DtDireccion* direccion) {
    this->nombre = nombre;
    this->correo = correo;
    this->direccion = direccion;
}

string DtInmobiliaria::getCorreo() {
    return this->correo;
}

string DtInmobiliaria::getNombre() {
    return this->nombre;
}

DtDireccion* DtInmobiliaria::getDireccion() {
    return this->direccion;
}

DtInmobiliaria::~DtInmobiliaria() {
    delete this->direccion;
}