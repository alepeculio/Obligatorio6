#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H

#include <string>
#include <iostream>

#include "DtDepartamento.h"
#include "ICollection.h"
#include "IDictionary.h"
#include "ICollectible.h"
using namespace std;

class Departamento : public ICollectible {
private:
    char letra;
    string matricula;
    string nombre;
    IDictionary* zonas;

public:
    Departamento(string, string);

    char getLetra();
    string getMatricula();
    string getNombre();
    IDictionary* getZonas();

    void setMatricula(string);
    void setNombre(string);
    void setZonas(IDictionary*);

    ~Departamento();

    DtDepartamento* getDatos();
    ICollection* listarZonas();
};

#endif