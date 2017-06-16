#include "Propiedad.h"
#include "InmoProp.h"
#include "Aviso.h"
#include "DtInmoProp.h"
#include "KeyInt.h"
#include "Zona.h"

Propiedad::Propiedad(int codigo, int cantAmb, int cantDorm, int cantBanios, bool garage, DtDireccion* direccion, float m2Edificados, float m2Tot) {
    this->codigo = codigo;
    this->cantAmb = cantAmb;
    this->cantDorm = cantDorm;
    this->cantBanios = cantBanios;
    this->garage = garage;
    this->direccion = direccion;
    this->m2Edificados = m2Edificados;
    this->m2Tot = m2Tot;

}

void Propiedad::setCodigo(int codigo) {
    this->codigo = codigo;
}

void Propiedad::setCantAmb(int cantAmb) {
    this->cantAmb = cantAmb;
}

void Propiedad::setCantDorm(int cantDorm) {
    this->cantDorm = cantDorm;
}

void Propiedad::setCantBanios(int cantBanios) {
    this->cantBanios = cantBanios;
}

void Propiedad::setGarage(bool garage) {
    this->garage = garage;
}

void Propiedad::setDireccion(DtDireccion* direccion) {
    this->direccion = direccion;
}

void Propiedad::setM2Edificados(float m2Edificados) {
    this->m2Edificados = m2Edificados;
}

void Propiedad::setM2Tot(float m2Tot) {
    this->m2Tot = m2Tot;
}

void Propiedad::setInmoProp(Inmobiliaria* inmo) {
    this->inmoProp = new InmoProp(inmo);
}

void Propiedad::setZona(Zona* zona) {
    this->zona = zona;
}

int Propiedad::getCodigo() {
    return this->codigo;
}

int Propiedad::getCantAmb() {
    return this->cantAmb;
}

int Propiedad::getCantDorm() {
    return this->cantDorm;
}

int Propiedad::getCantBanios() {
    return this->cantBanios;
}

bool Propiedad::getGarage() {
    return this->garage;
}

DtDireccion* Propiedad::getDireccion() {
    return this->direccion;
}

float Propiedad::getM2Edificados() {
    return this->m2Edificados;
}

float Propiedad::getM2Tot() {
    return this->m2Tot;
}

InmoProp* Propiedad::getInmoProp() {
    return this->inmoProp;
}

Propiedad::~Propiedad() {
    delete this->direccion;
    delete this->inmoProp;
}

DtPropiedad* Propiedad::getDatos() {
    DtPropiedad* d = new DtPropiedad(this->codigo, this->cantAmb, this->cantDorm, this->cantBanios, this->garage, this->direccion, this->m2Edificados, this->m2Tot);
    return d;
}

ICollection* Propiedad::getMensajes(int) {
    ICollection* mensajes = this->inmoProp->getMensajes(codigo);
    return mensajes;

}

void Propiedad::ingresarMensaje(string texto, string aov, Usuario* interesado) {
    this->inmoProp->ingresarMensaje(texto, aov, interesado);
}

void Propiedad::setAlquiler(float precioA) {
    inmoProp->setAlquiler(precioA);
}

void Propiedad::setVenta(float precioV) {
    inmoProp->setVenta(precioV);
}

Zona* Propiedad::getZona() {
    return this->zona;
}

void Propiedad::borrarLinks() {
    this->inmoProp->borrarLinkInmoProp();
    this->zona->eliminar(new KeyInt(this->getCodigo()));
    delete inmoProp;
}

DtInmoProp* Propiedad::selectPropiedad() {
    DtInmoProp * dtip = new DtInmoProp(this->getDatos(), this->inmoProp->selectPropiedad());
    return dtip;
}

bool Propiedad::perteneceA(string correo) {
    return this->inmoProp->getInmobiliaria()->getCorreo() == correo;
}