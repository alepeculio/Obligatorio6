#ifndef CHAT_H
#define CHAT_H

#include "Interesado.h"
#include "ICollection.h"
#include <string>
#include <iostream>
using namespace std;

class Chat : public ICollectible {
private:
    ICollection* mensajes;
    Interesado* interesado;

public:
    Chat(Interesado*);

    void setMensajes(ICollection*);
    void setInteresado(Interesado*);

    ICollection* getMensajes();
    Interesado* getInteresado();

    ~Chat();

    void ingresarMensaje(string);
    ICollection* getMensajes(int);
    void borrarLinkAviso();
    int getCodigoInter();
};

#endif