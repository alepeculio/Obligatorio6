#include "Chat.h"
#include "Lista.h"
#include "Mensaje.h"
#include "DtMensaje.h"

Chat::Chat(Interesado* interesado) {
    this->interesado = interesado;
    mensajes = new Lista();
}

void Chat::setMensajes(ICollection* mensajes) {
    this->mensajes = mensajes;
}

void Chat::setInteresado(Interesado* interesado) {
    this->interesado = interesado;
}

ICollection* Chat::getMensajes() {
    return this->mensajes;
}

Interesado* Chat::getInteresado() {
    return this->interesado;
}

Chat::~Chat() {
    delete this->mensajes;
    delete this->interesado;
}

void Chat::ingresarMensaje(string texto) {
    this->mensajes->add(new Mensaje(new DtFecha(0, 0, 0), new DtHora(0, 0), texto, true)); // Cambiar fecha, hora y true
}

ICollection* Chat::getMensajes(int codigo) {
    ICollection* resultado = new Lista();

    int codInt = this->interesado->getCodigo();

    IIterator* iterator = this->mensajes->iterator();

    while (iterator->hasNext()) {
        Mensaje* mensaje = dynamic_cast<Mensaje*> (iterator->getCurrent());

        if (codigo == codInt)
            resultado->add(mensaje->getDatos());

        iterator->next();
    }

    delete iterator;

    return resultado;
}

void Chat::borrarLinkAviso() {
    if (mensajes) {
        IIterator* it = this->mensajes->iterator();
        while (it->hasNext()) {
            Mensaje* m = dynamic_cast<Mensaje*> (it->getCurrent());
            mensajes->remove(it->getCurrent());
            delete m;
            it->next();
        }
        delete it;
    }
}

int Chat::getCodigoInter() {
    return this->interesado->getCodigo();
}