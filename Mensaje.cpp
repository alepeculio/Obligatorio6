#include "Mensaje.h"

Mensaje::Mensaje(DtFecha* fecha, DtHora* hora, string texto, bool cliente) {
    this->fecha = fecha;
    this->hora = hora;
    this->texto = texto;
    this->cliente = cliente;
}

void Mensaje::setFecha(DtFecha* fecha) {
    this->fecha = fecha;
}

void Mensaje::setHora(DtHora* hora) {
    this->hora = hora;
}

void Mensaje::setTexto(string texto) {
    this->texto = texto;
}

void Mensaje::setCliente(bool cliente) {
    this->cliente = cliente;
}

DtFecha* Mensaje::getFecha() {
    return this->fecha;
}

DtHora* Mensaje::getHora() {
    return this->hora;
}

string Mensaje::getTexto() {
    return this->texto;
}

bool Mensaje::getCliente() {
    return this->cliente;
}

Mensaje::~Mensaje() {
    delete this->fecha;
    delete this->hora;
}

DtMensaje* Mensaje::getDatos() {
    return new DtMensaje(this->fecha, this->hora, this->texto, this->cliente);
}