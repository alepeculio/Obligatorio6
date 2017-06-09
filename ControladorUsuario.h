#ifndef CONTROLADORUSUARIO_H
#define CONTROLADORUSUARIO_H

#include "IUsuario.h"
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
    IDictionary* getUsuario();
    void iniciarSesion(string);
    bool ingresarContrasenia(string);
    void asignarSesion();
    void primerContrasenia(string);
    bool verificarContrasenia(string);
    void activarUsuario(string);

    ~ControladorUsuario();
};

#endif