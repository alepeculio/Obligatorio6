#ifndef DTMENSAJE_H
#define DTMENSAJE_H

#include "ICollectible.h"
#include "DtFecha.h"
#include "DtHora.h"
#include <string>
#include <iostream>
using namespace std;

class DtMensaje : public ICollectible {
private:
    DtFecha* fecha;
    DtHora* hora;
    string texto;
    bool cliente;

public:
    DtMensaje(DtFecha*, DtHora*, string, bool);

    DtFecha* getFecha();
    DtHora* getHora();
    string getTexto();
    bool getCliente();

    ~DtMensaje();

};



#endif /* DTMENSAJE_H */

