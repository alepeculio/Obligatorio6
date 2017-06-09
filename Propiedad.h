#ifndef PROPIEDAD_H
#define PROPIEDAD_H

#include "DtDireccion.h"
#include "DtPropiedad.h"

class Propiedad : public ICollectible {
private:
    int codigo;
    int cantAmb;
    int cantDorm;
    int cantBanios;
    bool garage;
    DtDireccion* direccion;
    float m2Edificados;
    float m2Tot;
    InmoProp* inmoProp;
public:
    Propiedad(int, int, int, int, bool, DtDireccion*, float, float, InmoProp*);
    virtual void setCodigo(int); //Setters
    virtual void setCantAmb(int);
    virtual void setCantDorm(int);
    virtual void setCantBanios(int);
    virtual void setGarage(bool);
    virtual void setDireccion(DtDireccion*);
    virtual void setM2Edificados(float);
    virtual void setM2Tot(float);
    virtual void setInmoProp(InmoProp*);

    virtual int getCodigo(); //Getters
    virtual int getCantAmb();
    virtual int getCantDorm();
    virtual int getCantBanios();
    virtual bool getGarage();
    virtual DtDireccion* getDireccion();
    virtual float getM2Edificados();
    virtual float getM2Tot();
    virtual InmoProp* getInmoProp();

    ~Propiedad();


    virtual DtPropiedad* getDatos(); // op Propias
    virtual ICollection* getMensajes(int);
    virtual void ingresarMensajes(string, string, int);
    virtual void borrarLinks();

};

#endif /* PROPIEDAD_H */

