#include "Usuario.h"

Usuario::Usuario(string correo, string contrasenia) {
    this->correo = correo;
    this->contrasenia = contrasenia;
    this->codigo = codigo;
    codigo++; // codigo = generadorCodigo estatico para usuario
}

int Usuario::getCodigo() {
    return this->codigo;
}

string Usuario::getCorreo() {
    return this->correo;
}

string Usuario::getContrasenia() {
    return this->contrasenia;
}

void Usuario::setCorreo(string correo) {
    this->correo = correo;
}

void Usuario::setContrasenia(string contrasenia) {
    this->contrasenia = contrasenia;
}

Usuario::~Usuario() {

}

bool Usuario::control(string contrasenia) {
    return this->contrasenia == contrasenia;
}