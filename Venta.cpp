#include "Venta.h"
#include "Lista.h"

Venta::Venta(float precioV)
: Aviso() {
    this->precioV = precioV;
}

void Venta::setPrecioV(int precioV) {
    this->precioV = precioV;
}

int Venta::getPrecioV() {
    return this->precioV;
}

string Venta::getTipo() {
    return "Venta";
}

Venta::~Venta() {
}