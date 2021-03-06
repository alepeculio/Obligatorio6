#ifndef APARTAMENTO_H
#define APARTAMENTO_H

#include "Propiedad.h"
#include "DtDireccion.h"
#include "InmoProp.h"
#include "DtApartamento.h"

#include <string>
#include <iostream>
using namespace std;

class Apartamento : public Propiedad {
private:
    int num;

public:
    Apartamento(int, int, int, int, bool, DtDireccion*, float, float,int);
    
    Apartamento(DtApartamento*);
    
    void setNum(int);

    int getNum();

    ~Apartamento();
};

#endif