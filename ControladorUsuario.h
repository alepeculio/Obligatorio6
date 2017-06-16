#ifndef CONTROLADORUSUARIO_H
#define CONTROLADORUSUARIO_H

#include "Utiles.h"
#include "IUsuario.h"
#include "DtDireccion.h"
#include "DtInmobiliaria.h"
#include "Usuario.h"
#include "IPropiedad.h"
#include <string>
#include <iostream>
using namespace std;

class ControladorUsuario : public IUsuario {
private:
    IDictionary* usuarios;
    Usuario* usuarioActual;
    Usuario* usuarioRecordado;
    string primerCont;
    IPropiedad* iPropiedad;

public:
    ControladorUsuario();

    void iniciarSesion(string);
    bool ingresarContrasenia(string);
    void asignarSesion();
    bool esUsuarioNuevo();
    void primerContrasenia(string);
    bool verificarContrasenia(string);
    void activarUsuario();
    void cerrarSesion();
    void ingresarInmobiliaria(string, DtDireccion*, string);
    void ingresarInteresado(string, string, int, string);

    DtInmobiliaria* mostrarInmobiliaria();
    int cantPorZonaYdep();

    void ingresarAdministrador(string, string);
    Usuario* getUsuarioActual();

    int getCodigoUsuario();
    TipoUsuario getTipoUsuario();
    TipoUsuario getTipoUsuarioRecordado();
    
    void setIPropiedad(IPropiedad*);
    ICollection* obtenerReporteInmobiliarias();

    ~ControladorUsuario();
};

#endif