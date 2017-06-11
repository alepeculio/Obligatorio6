#include "KeyString.h"
#include "Usuario.h"
#include "ListDicc.h"
#include "Interesado.h"
#include "Inmobiliaria.h"
#include "ControladorUsuario.h"
#include "Adminstrador.h"

ControladorUsuario::ControladorUsuario() {
    this->usuarios = new ListDicc();
    this->usuarioActual = NULL;
    this->usuarioRecordado = NULL;
}

int ControladorUsuario::getCodigoUsuario() {

}

TipoUsuario ControladorUsuario::getTipoUsuario() {
    Administrador* admin = dynamic_cast<Administrador*> (this->usuarioActual);

    if (admin != NULL) {
        return ADMINISTRADOR;
    } else {
        Inmobiliaria* inmobiliaria = dynamic_cast<Inmobiliaria*> (this->usuarioActual);

        if (inmobiliaria != NULL) {
            return INMOBILIARIA;
        } else {
            Interesado* interesado = dynamic_cast<Interesado*> (this->usuarioActual);

            if (interesado != NULL) {
                return INTERESADO;
            } else {
                return NULO;
            }
        }
    }
}

TipoUsuario ControladorUsuario::getTipoUsuarioRecordado() {
    Administrador* admin = dynamic_cast<Administrador*> (this->usuarioRecordado);

    if (admin != NULL) {
        return ADMINISTRADOR;
    } else {
        Inmobiliaria* inmobiliaria = dynamic_cast<Inmobiliaria*> (this->usuarioRecordado);

        if (inmobiliaria != NULL) {
            return INMOBILIARIA;
        } else {
            Interesado* interesado = dynamic_cast<Interesado*> (this->usuarioRecordado);

            if (interesado != NULL) {
                return INTERESADO;
            } else {
                return NULO;
            }
        }
    }
}

bool ControladorUsuario::esUsuarioNuevo() {
    return this->usuarioRecordado->getContrasenia() == "";
}

void ControladorUsuario::iniciarSesion(string email) {
    KeyString* key = new KeyString(email);

    if (usuarios->member(key)) {
        this->usuarioRecordado = dynamic_cast<Usuario*> (usuarios->find(key));
    } else {
        this->emailRecordado = email;
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

void ControladorUsuario::activarUsuario() {
    this->usuarioRecordado->setContrasenia(this->primerCont);
}

void ControladorUsuario::cerrarSesion() {
    this->usuarioActual = NULL;
    this->usuarioRecordado = NULL;
    this->emailRecordado = "";
    this->primerCont = "";
}

void ControladorUsuario::ingresarAdministrador(string correo, string contrasenia) {
    this->usuarios->add(new Administrador(correo, contrasenia), new KeyString(correo));
}

void ControladorUsuario::ingresarInmobiliaria(string nombre, DtDireccion* direccion, string email) {
    usuarios->add(new Inmobiliaria(email, nombre, direccion), new KeyString(email));
}

void ControladorUsuario::ingresarInteresado(string nombre, string apellido, int edad, string email) {
    usuarios->add(new Interesado(email, edad, nombre, apellido), new KeyString(email));
}

DtInmobiliaria* ControladorUsuario::mostrarInmobiliaria() {
}

int ControladorUsuario::cantPorZonaYdep() {
}

ControladorUsuario::~ControladorUsuario() { // Delete usuarioActual y usuarioRecordado?????????????????
    delete this->usuarios;
    delete this->usuarioActual;
    delete this->usuarioRecordado;
}