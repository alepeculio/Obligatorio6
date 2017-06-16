#ifndef EDIFICIO_H
#define EDIFICIO_H

#include "ICollectible.h"
#include "Apartamento.h"
#include "Propiedad.h"
#include "IDictionary.h"
#include "DtEdificio.h"

#include <string>
#include <iostream>

using namespace std;

class Edificio : public ICollectible {
private:
    string nomEdificio;
    int cantPisos;
    float gastosComunes;
    IDictionary* apartamentos;

public:
    Edificio(string, int, float);

    void setNomEdificio(string);
    void setCantPisos(int);
    void setGastosComunes(int);
    void setApartamento(IDictionary*);

    string getNomEdificio();
    int getCantPisos();
    int getGastosComunes();
    IDictionary* getApartamento();
    
    ~Edificio();

    void agregarApto(Apartamento*);
    void eliminar(Propiedad*);
    DtEdificio* getDatos();
};

#endif