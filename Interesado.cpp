#include "Interesado.h"

Interesado::Interesado(string email, int edad, string nombre, string apellido)
: Usuario(email, "") {
    this->nombre = nombre;
    this->apellido = apellido;
    this->edad = edad;
}

void Interesado::setNombre(string nombre) {
    this->nombre = nombre;
}

void Interesado::setApellido(string apellido) {
    this->apellido = apellido;
}

void Interesado::setEdad(int edad) {
    this->edad = edad;
}

string Interesado::getNombre() {
    return this->nombre;
}

string Interesado::getApellido() {
    return this->apellido;
}

int Interesado::getEdad() {
    return this->edad;
}

Interesado::~Interesado() {
}