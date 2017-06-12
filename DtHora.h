#ifndef DTHORA_H
#define DTHORA_H

#include <iostream>
using namespace std;

class DtHora {
private:
    int min;
    int hora;

public:
    DtHora(int, int);

    int getMin();
    int getHora();

    friend ostream& operator<<(ostream&, const DtHora&);

    ~DtHora();
};

#endif