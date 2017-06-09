#ifndef DTINMOPROP_H
#define DTINMOPROP_H

#include "DtDireccion.h"
#include <string>
#include <iostream>
using namespace std;

class DtInmoProp {
private:
    int codigo;
    DtDireccion* direccion;
    bool alquiler;
    bool venta;
    int cantAmb;
    int cantDorm;
    int cantBanios;
    bool garage;
    float m2Edificados;
    float m2Tot;
    float m2EspVerde;
    int nroApto;
    string nombreInmob;
    string ubicacionInmob;
    string correo;

public:
    DtInmoProp(int, DtDireccion*, bool, bool, int, int, int, bool, float, float, float, int, string, string, string);

    int getCodigo();
    DtDireccion* getDireccion();
    bool getAlquiler();
    bool getVenta();
    int getCantAmb();
    int getCantDorm();
    int getCantBanios();
    bool getGarage();
    float getM2Edificados();
    float getM2Tot();
    float getM2EspVerde();
    int getNroApto();
    string getNombreInmob();
    string getUbicacionInmob();
    string getCorreo();

    ~DtInmoProp();
};

#endif