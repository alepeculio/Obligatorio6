#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <iostream>
using namespace std;

class Usuario : public ICollectible {
private:
    string correo;
    string contrasenia;

public:
    Usuario(string, string);

    virtual string getCorreo();
    virtual string getContrasenia();

    virtual void setCorreo(string);
    virtual void setContrasenia(string);

    ~Usuario();

    virtual bool control(string);


};

#endif