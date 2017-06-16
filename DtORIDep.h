#ifndef DTORIDEP_H
#define DTORIDEP_H

#include "ICollectible.h"
#include "ICollection.h"
#include <string.h>
#include <iostream>
using namespace std;

class DtORIDep : public ICollectible {
private:
    string nombre;
    ICollection* dtORIZonas;

public:
    DtORIDep(string, ICollection*);

    string getNombre();
    ICollection* getDtORIZonas();

    ~DtORIDep();
};

#endif