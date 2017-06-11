#ifndef IUSUARIO_H
#define IUSUARIO_H

#include "DtInmobiliaria.h"
#include "IDictionary.h"
#include "DtDireccion.h"
#include "Usuario.h"
#include "Utiles.h"
#include <string>
#include <iostream>
using namespace std;

class IUsuario {
public:
    virtual int getCodigoUsuario() = 0;
    virtual TipoUsuario getTipoUsuario() = 0;
    virtual TipoUsuario getTipoUsuarioRecordado() = 0;
    virtual bool esUsuarioNuevo() = 0;

    virtual void iniciarSesion(string) = 0;
    virtual bool ingresarContrasenia(string) = 0;
    virtual void asignarSesion() = 0;
    virtual void primerContrasenia(string) = 0;
    virtual bool verificarContrasenia(string) = 0;
    virtual void activarUsuario() = 0;

    virtual void cerrarSesion() = 0;

    virtual void ingresarAdministrador(string, string) = 0;
    virtual void ingresarInmobiliaria(string, DtDireccion*, string) = 0;
    virtual void ingresarInteresado(string, string, int, string) = 0;

    virtual DtInmobiliaria* mostrarInmobiliaria() = 0;
    virtual int cantPorZonaYdep() = 0;
};

#endif