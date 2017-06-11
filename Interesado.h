#ifndef INTERESADO_H
#define INTERESADO_H

#include "Usuario.h"
#include <string>
#include <iostream>
using namespace std;

class Interesado : public Usuario {
private:
    string nombre;
    string apellido;
    int edad;

public:
    Interesado(string, int, string, string);

    void setNombre(string);
    void setApellido(string);
    void setEdad(int);

    string getNombre();
    string getApellido();
    int getEdad();

    ~Interesado();
};

#endif