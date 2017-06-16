#ifndef MENSAJE_H
#define MENSAJE_H

#include "DtMensaje.h"
#include "DtFecha.h"
#include "DtHora.h"
#include <string>
#include <iostream>
using namespace std;

class Mensaje : public ICollectible {
private:
    DtFecha* fecha;
    DtHora* hora;
    string texto;
    bool cliente;

public:
    Mensaje(DtFecha*, DtHora*, string, bool);

    void setFecha(DtFecha*);
    void setHora(DtHora*);
    void setTexto(string);
    void setCliente(bool);

    DtFecha* getFecha();
    DtHora* getHora();
    string getTexto();
    bool getCliente();

    ~Mensaje();

    DtMensaje* getDatos();
};

#endif