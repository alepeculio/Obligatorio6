#ifndef USUARIO_H
#define USUARIO_H

#include "ICollectible.h"
#include <string>
#include <iostream>
using namespace std;

class Usuario : public ICollectible {
private:
    int codigo;
    string correo;
    string contrasenia;

public:
    Usuario(string, string);

    virtual int getCodigo();
    virtual string getCorreo();
    virtual string getContrasenia();

    virtual void setCorreo(string);
    virtual void setContrasenia(string);

    ~Usuario();

    virtual bool control(string);
};

#endif