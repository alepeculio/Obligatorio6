#include "Aviso.h"
#include "Lista.h"
#include "Chat.h"
#include "DtMensaje.h"

Aviso::Aviso() {
    this->chats = new Lista();
}

void Aviso::setChats(ICollection* chats) {
    this->chats = chats;
}

ICollection* Aviso::getChats() {
    return this->chats;
}

Aviso::~Aviso() {
    delete this->chats;
}

ICollection* Aviso::getMensajes(int codigo) {
    ICollection* resultado = new Lista();

    IIterator* iterator = this->chats->iterator();
    while (iterator->hasNext()) {
        Chat* chat = dynamic_cast<Chat*> (iterator->getCurrent());

        ICollection* res = chat->getMensajes(codigo);

        IIterator* resIterator = res->iterator();
        while (resIterator->hasNext()) {
            resultado->add(resIterator->getCurrent());
            resIterator->next();
        }
        delete resIterator;

        iterator->next();
    }

    delete iterator;

    return resultado;
}

void Aviso::ingresarMensaje(string texto, Usuario* usuario) {
    int codigo = -1;

    IIterator* iterator = this->chats->iterator();
    while (iterator->hasNext()) {
        Chat* c = dynamic_cast<Chat*> (iterator->getCurrent());
        codigo = c->getCodigoInter();

        if (codigo == usuario->getCodigo())
            c->ingresarMensaje(texto);

        iterator->next();
    }

    delete iterator;

    if (codigo == -1) {
        Chat* c = new Chat(dynamic_cast<Interesado*> (usuario));
        c->ingresarMensaje(texto);
        this->chats->add(c);
    }
}

void Aviso::borrarLinkAviso() {
    if (chats) {
        IIterator* it = this->chats->iterator();
        while (it->hasNext()) {
            Chat* ch = dynamic_cast<Chat*> (it->getCurrent());
            ch->borrarLinkAviso();
            chats->remove(it->getCurrent());
            delete ch;
            it->next();
        }
        delete it;
    }
}