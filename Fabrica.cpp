#include "Fabrica.h"
#include "ControladorUsuario.h"
#include "ControladorPropiedad.h"

IUsuario* Fabrica::getIUsuario() {
    return new ControladorUsuario();
}

IPropiedad* Fabrica::getIPropiedad() {
    return new ControladorPropiedad();
}

Fabrica::~Fabrica() {

}