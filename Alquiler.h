#ifndef ALQUILER_H
#define ALQUILER_H

#include <string>
#include <iostream>
using namespace std;

class Alquiler : public Aviso {
private:
    float precioA;

public:
    Alquiler(float, ICollection*);

    void setPrecioA(int);

    int getPrecioA();

    ~Alquiler();

};


#endif /* ALQUILER_H */

