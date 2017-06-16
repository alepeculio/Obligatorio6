#ifndef AVISO_H
#define AVISO_H

#include "ICollection.h"
#include "Usuario.h"
#include <string>
#include <iostream>
using namespace std;

class Aviso : public ICollectible {
private:
    ICollection* chats;

public:
    Aviso();

    virtual void setChats(ICollection*);

    virtual ICollection* getChats();

    virtual ~Aviso();

    virtual ICollection* getMensajes(int);
    virtual void ingresarMensaje(string, Usuario*);
    virtual void borrarLinkAviso();
    virtual string getTipo() = 0;
};

#endif