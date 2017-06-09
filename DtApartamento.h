#ifndef DTAPARTAMENTO_H
#define DTAPARTAMENTO_H

class DtApartamento {
private:
    int codigo;
    int num;
    int cantAmb;
    int cantDorm;
    int cantBanios;
    bool garage;
    DtDireccion* direccion;
    float m2Edificados;
    float m2Tot;
    InmoProp* inmoProp;
public:
    DtCasa(int, int, int, int, int, bool, DtDireccion*, float, float, InmoProp*);

    int getCodigo();
    int getNum();
    int getCantAmb();
    int getCantDorm();
    int getCantBanios();
    bool getGarage();
    DtDireccion* getDireccion();
    float getM2Edificados();
    float getM2Tot() = 0;
    InmoProp* getInmoProp();

    ~DtCasa();
};

#endif /* DTAPARTAMENTO_H */

