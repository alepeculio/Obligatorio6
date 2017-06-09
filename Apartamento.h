#ifndef APARTAMENTO_H
#define APARTAMENTO_H

#include <string>
#include <iostream>
using namespace std;

class Apartamento : public Propiedad {
private:
    int num;

public:
    Apartamento(int, int, int, int, int, bool, DtDireccion*, float, float, InmoProp*);

    void setNum(int);

    int getNum();

    ~Apartamento();
};

#endif