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

void ControladorUsuario::iniciarSesion(string email) {
    KeyString* key = new KeyString(email);

    if (usuarios->member(key))
        this->usuarioRecordado = dynamic_cast<Usuario*> (usuarios->find(key));
    else
        throw std::invalid_argument("Usuario no existe");
}

bool ControladorUsuario::ingresarContrasenia(string contrasenia) {
    return usuarioRecordado->control(contrasenia);
}

void ControladorUsuario::asignarSesion() {
    this->usuarioActual = this->usuarioRecordado;
    this->usuarioRecordado = NULL;
    this->primerCont = "";
}

bool ControladorUsuario::esUsuarioNuevo() {
    return this->usuarioRecordado->getContrasenia() == "";
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
}

void ControladorUsuario::ingresarInmobiliaria(string nombre, DtDireccion* direccion, string email) {
    KeyString* key = new KeyString(email);

    if (usuarios->member(key))
        throw std::invalid_argument("Usuario ya registrado con ese email");
    else
        usuarios->add(new Inmobiliaria(email, nombre, direccion), key);
}

void ControladorUsuario::ingresarInteresado(string nombre, string apellido, int edad, string email) {
    KeyString* key = new KeyString(email);

    if (usuarios->member(key))
        throw std::invalid_argument("Usuario ya registrado con ese email");
    else
        usuarios->add(new Interesado(email, edad, nombre, apellido), key);
}

Usuario* ControladorUsuario::getUsuarioActual() {
    return this->usuarioActual;
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

void ControladorUsuario::ingresarAdministrador(string correo, string contrasenia) {
    this->usuarios->add(new Administrador(correo, contrasenia), new KeyString(correo));
}

DtInmobiliaria* ControladorUsuario::mostrarInmobiliaria() {
}

int ControladorUsuario::cantPorZonaYdep() {
}

ControladorUsuario::~ControladorUsuario() {
    delete this->usuarios;
    delete this->usuarioActual;
    delete this->usuarioRecordado;
}