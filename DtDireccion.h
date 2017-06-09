#ifndef DTDIRECCION_H
#define DTDIRECCION_H

#include <string>
#include <iostream>
using namespace std;

class DtDireccion {
private:
    string ciudad;
    string calle;
    int numero;

public:
    DtDireccion(string, string, int);
    DtDireccion(DtDireccion*);

    string getCiudad();
    string getCalle();
    int getNumero();

    ~DtDireccion();
};

#endif