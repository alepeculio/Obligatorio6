#ifndef ZONA_H
#define ZONA_H

#include <string>
#include <iostream>
using namespace std;

class Zona : public ICollectible {
private:
    int codigo;
    string nombre;
    ICollection* Propiedades;

public:
    Zona(int, string, ICollection*);

    void setCodigo(int);
    void setNombre(string);
    void setPropiedades(ICollection*);

    int getCodigo();
    string getNombre();
    ICollection* getPropiedades();

    ~Zona();

    ICollection* listarPropiedad();
    DtZona* getDatos();
    void agregar(Propiedad*);
    void eliminar(Propiedad*);
};


#endif /* ZONA_H */

