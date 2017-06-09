#ifndef DTCASA_H
#define DTCASA_H

class DtCasa {
private:
    int codigo;
    int cantAmb;
    int cantDorm;
    int cantBanios;
    bool garage;
    DtDireccion* direccion;
    float m2Edificados;
    float m2Tot;
    float m2EspVerde;
    InmoProp* inmoProp;
public:
    DtCasa(int, int, int, int, bool, DtDireccion*, float, float, float, InmoProp*);

    int getCodigo();
    int getCantAmb();
    int getCantDorm();
    int getCantBanios();
    bool getGarage();
    DtDireccion* getDireccion();
    float getM2Edificados();
    float getM2Tot();
    float getM2EspVerde();
    InmoProp* getInmoProp();

    ~DtCasa();
};

#endif /* DTCASA_H */

