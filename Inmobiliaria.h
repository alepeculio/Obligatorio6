#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H

#include <string>
#include <iostream>
using namespace std;

class Inmobiliaria : public Usuario {
private:
    string nombre;
    string ubicacion;

public:
    Inmobiliaria(string, string, string, string);

    void setNombre(string); //Setters
    void setUbicacion(string);

    string getNombre(); //Getters
    string getUbicacion();

    ~Inmobiliaria();

};

#endif