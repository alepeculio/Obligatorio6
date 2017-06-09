#ifndef DTAPARTAMENTO_H
#define DTAPARTAMENTO_H

#include "DtDireccion.h"
#include "DtPropiedad.h"

class DtApartamento : public DtPropiedad {
private:
    int num;

public:
    DtApartamento(int, int, int, int, bool, DtDireccion*, float, float, int);

    int getNum();

    ~DtApartamento();
};

#endif