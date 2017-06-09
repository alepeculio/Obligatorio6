#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H

#include <string>
#include <iostream>

#include "DtDepartamento.h"
#include "ICollectible.h"
using namespace std;

class Departamento {
private:
    char letra;
    string matricula;
    string nombre;

public:
    Departamento(string, string);

    char getLetra();
    string getMatricula();
    string getNombre();

    void setMatricula(string);
    void setNombre(string);

    ~Departamento();

    DtDepartamento* getDatos();
    ICollectible* listarZonas();
};

#endif