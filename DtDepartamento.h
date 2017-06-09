#ifndef DTDEPARTAMENTO_H
#define DTDEPARTAMENTO_H

#include <string>
#include <iostream>

#include "ICollectible.h"
using namespace std;

class DtDepartamento : public ICollectible {
private:
    char letra;
    string matricula;
    string nombre;

public:
    DtDepartamento(string, string);

    char getLetra();
    string getMatricula();
    string getNombre();

    ~DtDepartamento();
};

#endif