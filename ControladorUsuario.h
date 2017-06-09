#ifndef CONTROLADORUSUARIO_H
#define CONTROLADORUSUARIO_H

#include "IUsuario.h"
#include <string>
#include <iostream>
using namespace std;

class ControladorUsuario : public IUsuario {
public:
    int getCodigoUsuario();
    IDictionary* getUsuario();
    void iniciarSesion(string);
    void asignarSesion();
    void primerContrasenia(string);
    bool verificarContrasenia(string);
    void activarUsuario(string);

    ~ControladorUsuario();
};

#endif