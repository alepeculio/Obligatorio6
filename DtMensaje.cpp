#include "DtMensaje.h"
#include "DtFecha.h"
#include "DtHora.h"

DtMensaje::DtMensaje(DtFecha* fecha,DtHora* hora,string texto ,bool cliente){
    this->fecha = fecha;
    this->hora = hora;
    this->texto = texto;
    this->cliente = cliente;
}

DtFecha* DtMensaje::getFecha(){
    return fecha;
}

DtHora* DtMensaje::getHora(){
    return  hora;
}

string DtMensaje::getTexto(){
    return texto;
}

bool DtMensaje::getCliente(){
    return cliente;
}

DtMensaje::~DtMensaje(){
}