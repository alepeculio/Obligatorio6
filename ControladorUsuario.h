#ifndef CONTROLADORUSUARIO_H
#define CONTROLADORUSUARIO_H

#include "Utiles.h"
#include "IUsuario.h"
#include "DtDireccion.h"
#include "DtInmobiliaria.h"
#include "Usuario.h"
#include <string>
#include <iostream>
using namespace std;

class ControladorUsuario : public IUsuario {
private:
    IDictionary* usuarios;
    Usuario* usuarioActual;
    Usuario* usuarioRecordado;
    string emailRecordado;
    string primerCont;

public:
    ControladorUsuario();

    int getCodigoUsuario();
    TipoUsuario getTipoUsuario();
    TipoUsuario getTipoUsuarioRecordado();
    bool esUsuarioNuevo();

    void iniciarSesion(string);
    bool ingresarContrasenia(string);
    void asignarSesion();
    void primerContrasenia(string);
    bool verificarContrasenia(string);
    void activarUsuario();

    void cerrarSesion();

    void ingresarAdministrador(string, string);
    void ingresarInmobiliaria(string, DtDireccion*, string);
    void ingresarInteresado(string, string, int, string);

    DtInmobiliaria* mostrarInmobiliaria();
    int cantPorZonaYdep();

    ~ControladorUsuario();
};

#endif