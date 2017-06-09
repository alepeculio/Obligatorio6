#ifndef AVISO_H
#define AVISO_H

#include <string>
#include <iostream>
using namespace std;

class Aviso : ICollectible {
private:
    ICollection* chat;

public:
    Aviso(ICollection*);

    virtual void setChat(ICollection*);

    virtual ICollection* getChat();

    virtual ~Aviso();

    virtual ICollection getMensajes(int);
    virtual void ingresarMensaje(string, int);
    virtual void borrarLinkAviso();
    virtual string getTipo();
};

#endif