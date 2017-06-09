#ifndef EDIFICIO_H
#define EDIFICIO_H

#include <string>
#include <iostream>
using namespace std;

class Edificio : public ICollectible {
private:
    string nomEdificio;
    int cantPisos;
    float gastosComunes;
    ICollection* Apartamento;
public:
    Edificio(string, int, float, ICollection*);

    void setNomEdificio(string);
    void setCantPisos(int);
    void setGastosComunes(int);
    void setApartamento(ICollection*);

    string getNomEdificio();
    int getCantPisos();
    int getGastosComunes();
    ICollection* getApartamento();

    ~Edificio();

    void agregarApto(Apartamento*);
    void eliminar(Propiedad*);
};


#endif /* EDIFICIO_H */

