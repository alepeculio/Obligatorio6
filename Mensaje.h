#ifndef MENSAJE_H
#define MENSAJE_H

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
    Mensaje(DtFecha, DtHora, string, bool);

    void setFecha(DtFecha); //Setters
    void setHora(DtHora);
    void setTexto(string);
    void setCliente(bool);

    DtFecha* getFecha(); //Getters
    DtHora* getHora();
    string getTexto();
    bool getCliente();

    ~Mensaje();

    DtMensaje* getDatos(); //op propias
};

#endif