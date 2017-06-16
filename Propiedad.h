#ifndef PROPIEDAD_H
#define PROPIEDAD_H

#include "DtDireccion.h"
#include "DtPropiedad.h"
#include "InmoProp.h"
#include "DtInmoProp.h"
#include "ICollection.h"
#include "ICollectible.h"
#include "Usuario.h"
#include "Inmobiliaria.h"
#include "Zona.h"
class Zona;

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
    Zona* zona;


public:
    Propiedad(int, int, int, int, bool, DtDireccion*, float, float);

    virtual void setCodigo(int);
    virtual void setCantAmb(int);
    virtual void setCantDorm(int);
    virtual void setCantBanios(int);
    virtual void setGarage(bool);
    virtual void setDireccion(DtDireccion*);
    virtual void setM2Edificados(float);
    virtual void setM2Tot(float);
    virtual void setInmoProp(Inmobiliaria*);
    virtual void setZona(Zona*);

    virtual int getCodigo();
    virtual int getCantAmb();
    virtual int getCantDorm();
    virtual int getCantBanios();
    virtual bool getGarage();
    virtual DtDireccion* getDireccion();
    virtual float getM2Edificados();
    virtual float getM2Tot();
    virtual InmoProp* getInmoProp();
    virtual Zona* getZona();

    virtual void setAlquiler(float);
    virtual void setVenta(float);
    ~Propiedad();



    virtual DtPropiedad* getDatos();
    virtual ICollection* getMensajes(int);
    virtual void ingresarMensaje(string, string, Usuario*);
    virtual void borrarLinks();
    virtual DtInmoProp* selectPropiedad();
    virtual bool perteneceA(string);


};

#endif