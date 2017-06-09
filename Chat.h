#ifndef CHAT_H
#define CHAT_H

#include "Interesado.h"
#include <string>
#include <iostream>
using namespace std;

class Chat : public ICollectible {
private:
    ICollection* Mensajes;
    Interesado* interesado;
public:
    Chat(ICollection, Interesado*);

    void setMensaje(ICollection*);
    void setInteresado(Interesado*);

    ICollection* getMensajes();
    Interesado* getInteresado();

    ~Chat();

    void ingresarMensaje(string);
    void getMensajes(int);
    void borrarLinkAviso();
    int getCodigoInter();
};

#endif