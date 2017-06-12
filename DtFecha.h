#ifndef DTFECHA_H
#define DTFECHA_H

#include <iostream>
using namespace std;

class DtFecha {
private:
    int dia;
    int mes;
    int anio;

public:
    DtFecha(int, int, int);

    int getDia();
    int getMes();
    int getAnio();

    friend ostream& operator<<(ostream&, const DtFecha&);

    ~DtFecha();
};

#endif