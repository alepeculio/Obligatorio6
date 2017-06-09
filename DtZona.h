#ifndef DTZONA_H
#define DTZONA_H

#include <string>
#include <iostream>
using namespace std;

class DtZona {
private:
    int codigo;
    string nombre;
    
public:
    Dtzona(int,string);
    
    int getCodigo();
    string getNombre();
    
    ~DtZona();
};


#endif /* DTZONA_H */

