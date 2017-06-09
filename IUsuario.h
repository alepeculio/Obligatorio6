#ifndef IUSUARIO_H
#define IUSUARIO_H

#include <string>
#include <iostream>

#include "IDictionary.h"
using namespace std;

class IUsuario {
public:
    virtual int getCodigoUsuario() = 0;
    virtual IDictionary* getUsuario() = 0;
    virtual void iniciarSesion(string) = 0;
    virtual void asignarSesion() = 0;
    virtual void primerContrasenia(string) = 0;
    virtual bool verificarContrasenia(string) = 0;
    virtual void activarUsuario(string) = 0;
    virtual void eliminarPropiedad(int) = 0;
};

#endif