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
    Interesado(string, string, int, string, string);

    void setNombre(string); //Setters
    void setApellido(string);
    void setEdad(int);

    string getNombre(); //Getters
    string getApellido();
    int getEdad();

    ~Interesado();
};

#endif /* INTERESADO_H */

