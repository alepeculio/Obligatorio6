#include "KeyString.h"
#include "Usuario.h"
#include "ListDicc.h"
#include "Interesado.h"
#include "Inmobiliaria.h"
#include "ControladorUsuario.h"

ControladorUsuario::ControladorUsuario() {
    this->usuarios = new ListDicc();
    this->usuarioActual = NULL;
    this->usuarioRecordado = NULL;
}

int ControladorUsuario::getCodigoUsuario() {

}

IDictionary* ControladorUsuario::getUsuario() {

}

void ControladorUsuario::iniciarSesion(string email) {
    KeyString* key = new KeyString(email);

    if (usuarios->member(key)) {
        this->usuarioRecordado = dynamic_cast<Usuario*> (usuarios->find(key));
    } else {
        emailRecordado = email;
    }
}

bool ControladorUsuario::ingresarContrasenia(string contrasenia) {
    return usuarioRecordado->control(contrasenia);
}

void ControladorUsuario::asignarSesion() {
    this->usuarioActual = this->usuarioRecordado;
}

void ControladorUsuario::primerContrasenia(string cont) {
    this->primerCont = cont;
}

bool ControladorUsuario::verificarContrasenia(string cont) {
    return this->primerCont == cont;
}

void ControladorUsuario::activarUsuario(string tipo) {
    Usuario* u = NULL;

    if (tipo == "Interesado")
        u = NULL; //new Interesado(emailRecordado, primerCont, 0, nombre, apellido);
    else if (tipo == "Inmobiliaria")
        u = NULL; //new Inmobiliaria(emailRecordado, primerCont, nombre, ubicacion);

    this->usuarios->add(u, new KeyString(u->getCorreo()));
}

ControladorUsuario::~ControladorUsuario() {
    delete this->usuarios;
    delete this->usuarioActual;
    delete this->usuarioRecordado;
}