#include "Alquiler.h"
#include "Lista.h"

Alquiler::Alquiler(float precioA) : Aviso() {
    this->precioA = precioA;
}

void Alquiler::setPrecioA(int precioA) {
    this->precioA = precioA;
}

int Alquiler::getPrecioA() {
    return this->precioA;
}

string Alquiler::getTipo() {
    return "Alquiler";
}

Alquiler::~Alquiler() {
}