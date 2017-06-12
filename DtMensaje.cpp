#include "DtMensaje.h"

DtMensaje::DtMensaje(DtFecha* fecha, DtHora* hora, string texto, bool cliente) {
    this->fecha = fecha;
    this->hora = hora;
    this->texto = texto;
    this->cliente = cliente;
}

DtFecha* DtMensaje::getFecha() {
    return this->fecha;
}

DtHora* DtMensaje::getHora() {
    return this->hora;
}

string DtMensaje::getTexto() {
    return this->texto;
}

bool DtMensaje::getCliente() {
    return this->cliente;
}

DtMensaje::~DtMensaje() {
    delete this->fecha;
    delete this->hora;
}