#ifndef IUSUARIO_H
#define IUSUARIO_H

#include <string>
#include <iostream>
using namespace std;

class IUsuario {
public:
    virtual int getCodigoUsuario() = 0;
    /*Usuario*/ virtual void getUsuario() = 0;
    virtual void iniciarSesion(string) = 0;
    virtual void asignarSesion() = 0;
    virtual void primerContrasenia(string) = 0;
    virtual bool verificarContrasenia(string) = 0;
    virtual void activarUsuario(string) = 0;
    virtual void eliminarPropiedad(int) = 0;
};

#endif