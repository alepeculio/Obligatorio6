#include <valarray>

#include "ControladorPropiedad.h"
#include "IDictionary.h"
#include "ICollection.h"
#include "IIterator.h"
#include "ListDiccIterator.h"
#include "ListDiccIteratorObj.h"
#include "ICollectible.h"
#include "ListDicc.h"
#include "IKey.h"
#include "Departamento.h"
#include "Lista.h"
#include "Edificio.h"
#include "KeyString.h"
#include "KeyInt.h"
#include "Zona.h"
#include "Apartamento.h"
#include "Casa.h"
#include "IUsuario.h"

ControladorPropiedad::ControladorPropiedad(IUsuario* iUsuario) {
    this->iUsuario = iUsuario;
    this->departamentos = new ListDicc();
    this->edificios = new ListDicc();
    this->propiedades = new ListDicc();
    this->zonasRecordadas = new ListDicc();
    this->zonaRecordada = NULL;
    this->propiedadesRecordadas = new ListDicc();
    this->propiedadRecordada = NULL;
    this->edificioRecordado = NULL;
    this->precioA = 0;
    this->precioV = 0;
}

void ControladorPropiedad::ingresarEdificio(string nombre, int pisos, float gastos) {
    KeyString* key = new KeyString(nombre);

    if (this->edificios->member(key))
        throw std::invalid_argument("El edificio ya existe");
    else
        this->edificios->add(new Edificio(nombre, pisos, gastos), key);
}

ICollection* ControladorPropiedad::listarDepartamentos() {
    IIterator* iter = departamentos->getIteratorObj();
    ICollection* res = new Lista();
    while (iter->hasNext()) {
        Departamento* dep = dynamic_cast<Departamento*> (iter->getCurrent());
        ICollectible* dtdep = dep->getDatos();
        res->add(dtdep);
        iter->next();
    }

    delete iter;
    return res;
}

ICollection* ControladorPropiedad::listarZonas(string nombreDep) {
    IKey* clave = new KeyString(nombreDep);
    ICollection* resultado = NULL;
    if (departamentos->member(clave)) {
        Departamento* dep = dynamic_cast<Departamento*> (departamentos->find(clave));
        this->zonasRecordadas = dep->getZonas();
        resultado = dep->listarZonas();
    } else
        throw std::invalid_argument("El departamento no existe");

    return resultado;
}

void ControladorPropiedad::selectZona(int codigo) {
    KeyInt* k = new KeyInt(codigo);

    if (this->zonasRecordadas->member(k))
        this->zonaRecordada = dynamic_cast<Zona*> (this->zonasRecordadas->find(k));
    else
        throw std::invalid_argument("La zona no existe");
}

ICollection* ControladorPropiedad::listarEdificios() {
    ICollection* resultado = new Lista();

    IIterator* iterator = this->edificios->getIteratorObj();
    while (iterator->hasNext()) {
        Edificio* e = dynamic_cast<Edificio*> (iterator->getCurrent());
        resultado->add(e->getDatos());
        iterator->next();
    }
    delete iterator;

    return resultado;
}

void ControladorPropiedad::selectEdificio(string nombreEdificio) {
    KeyString* k = new KeyString(nombreEdificio);

    if (this->edificios->member(k))
        this->edificioRecordado = dynamic_cast<Edificio*> (this->edificios->find(k));
    else
        throw std::invalid_argument("El edificio no existe");
}

bool ControladorPropiedad::fijarAlquiler(float precioAlquiler) {
    precioA = precioAlquiler;
}

bool ControladorPropiedad::fijarVenta(float precioVenta) {
    precioV = precioVenta;
}

int ControladorPropiedad::altaApto(DtApartamento* dtApto) {
    KeyInt* k = new KeyInt(dtApto->getCodigo());

    if (this->propiedades->member(k))
        throw std::invalid_argument("El apartamento ya existe");
    else {
        Apartamento* apto = new Apartamento(dtApto);
        this->propiedades->add(apto, k);

        zonaRecordada->agregar(apto);

        Inmobiliaria* inmo = dynamic_cast<Inmobiliaria*> (iUsuario->getUsuarioActual());

        apto->setInmoProp(inmo);

        if (precioA != 0)
            apto->setAlquiler(precioA);

        if (precioV != 0)
            apto->setVenta(precioV);

        int codigo = apto->getCodigo();

        edificioRecordado->agregarApto(apto);

        return codigo;
    }
}

int ControladorPropiedad::altaCasa(DtCasa* dtCasa) {
    KeyInt* k = new KeyInt(dtCasa->getCodigo());

    if (this->propiedades->member(k))
        throw std::invalid_argument("La casa ya existe");
    else {
        Casa* casa = new Casa(dtCasa);
        this->propiedades->add(casa, k);

        zonaRecordada->agregar(casa);

        Inmobiliaria* inmo = dynamic_cast<Inmobiliaria*> (iUsuario->getUsuarioActual());

        casa->setInmoProp(inmo);

        if (precioA != 0)
            casa->setAlquiler(precioA);

        if (precioV != 0)
            casa->setVenta(precioV);

        int codigo = casa->getCodigo();

        return codigo;
    }
}

ICollection* ControladorPropiedad::listarPropiedades(int codigo) {
    IKey* c = new KeyInt(codigo);
    ICollection* dtp = new Lista();

    if (zonasRecordadas->member(c)) {
        Zona* z = dynamic_cast<Zona*> (zonasRecordadas->find(c));
        dtp = z->listarPropiedad();
        propiedadesRecordadas = z->getPropiedades();
    } else {
        throw std::invalid_argument("La zona no existe");
    }
    return dtp;
}

ICollection* ControladorPropiedad::listarMensajes(int codigo) {

    IKey* c = new KeyInt(codigo);
    ICollection* dtMens = new Lista();
    if (propiedadesRecordadas->member(c)) {
        Propiedad* p = dynamic_cast<Propiedad*> (propiedadesRecordadas->find(c));
        int codUser = this->iUsuario->getCodigoUsuario();
        dtMens = p->getMensajes(codUser);
        this->propiedadRecordada = p;
    } else {
        throw std::invalid_argument("La Propiedad no existe");
    }

    return dtMens;

}

void ControladorPropiedad::ingresarMensaje(string texto, string aov) {
    Usuario* user = this->iUsuario->getUsuarioActual();
    this->propiedadRecordada->ingresarMensaje(texto, aov, user);

}

void ControladorPropiedad::eliminarPropiedad(int codigo) {
    IKey* clave = new KeyInt(codigo);
    if (propiedades->member(clave)) {
        Propiedad* p = dynamic_cast<Propiedad*> (propiedades->find(clave));
        p->borrarLinks();
        propiedades->removeKey(clave);
        if (dynamic_cast<Apartamento*> (p)) {
            IIterator* it = edificios->getIteratorObj();
            while (it->hasNext()) {
                Edificio* e = dynamic_cast<Edificio*> (it->getCurrent());
                if (e->getApartamento()->member(clave)) {
                    e->getApartamento()->removeKey(clave);
                    break;
                }
                it->next();
            }
            delete it;
        }
        delete p;
    } else
        throw std::invalid_argument("La Propiedad no existe");
}

DtInmoProp* ControladorPropiedad::selectPropiedad(int codigo) {
    IKey* clave = new KeyInt(codigo);
    if (this->propiedades->member(clave)) {
        Propiedad* p = dynamic_cast<Propiedad*> (this->propiedades->find(clave));
        return p->selectPropiedad();
    } else {
        throw std::invalid_argument("La Propiedad no existe");
    }
}

void ControladorPropiedad::seleccionarPropiedad(int codigo) {
    KeyInt* k = new KeyInt(codigo);

    if (this->propiedadesRecordadas->member(k))
        this->propiedadRecordada = dynamic_cast<Propiedad*> (this->propiedadesRecordadas->find(k));
    else
        throw std::invalid_argument("La Propiedad no existe");
}

void ControladorPropiedad::modificarApart(DtApartamento* dtApto) {
    IKey* c = new KeyInt(dtApto->getCodigo());

    if (this->propiedades->member(c)) {
        Apartamento* apto = dynamic_cast<Apartamento*> (this->propiedades->find(c));
        if (!apto) {
            apto->setCantAmb(dtApto->getCantAmb());
            apto->setCantDorm(dtApto->getCantDorm());
            apto->setCantBanios(dtApto->getCantBanios());
            apto->setGarage(dtApto->getGarage());
            apto->setDireccion(dtApto->getDireccion());
            apto->setM2Edificados(dtApto->getM2Edificados());
            apto->setM2Tot(dtApto->getM2Tot());
            apto->setNum(dtApto->getNum());
        } else {
            throw std::invalid_argument("El codigo intruducido no es de un Apartamento");
        }
    } else {
        throw std::invalid_argument("La Propiedad no existe");
    }
}

void ControladorPropiedad::modificarCasa(DtCasa* dtCasa) {
    IKey* c = new KeyInt(dtCasa->getCodigo());

    if (this->propiedades->member(c)) {
        Casa* casa = dynamic_cast<Casa*> (this->propiedades->find(c));
        if (!casa) {
            casa->setCantAmb(dtCasa->getCantAmb());
            casa->setCantDorm(dtCasa->getCantDorm());
            casa->setCantBanios(dtCasa->getCantBanios());
            casa->setGarage(dtCasa->getGarage());
            casa->setDireccion(dtCasa->getDireccion());
            casa->setM2Edificados(dtCasa->getM2Edificados());
            casa->setM2Tot(dtCasa->getM2Tot());
            casa->setM2EspVerde(dtCasa->getM2EspVerde());
        } else {
            throw std::invalid_argument("El codigo intruducido no es de una Casa");
        }
    } else {
        throw std::invalid_argument("La Propiedad no existe");
    }

}

ICollection* ControladorPropiedad::obtenerReporteInmobiliaria(string correo) {
    ICollection* resultado = new Lista();

    IIterator* iterator = departamentos->getIteratorObj();
    while (iterator->hasNext()) {
        Departamento* d = dynamic_cast<Departamento*> (iterator->getCurrent());
        resultado->add(d->obtenerReporteInmobiliaria(correo));
        iterator->next();
    }
    delete iterator;

    return resultado;
}

IDictionary* ControladorPropiedad::listarConversaciones() {
}

ICollection* ControladorPropiedad::listarMensajesConversacion(int) {
}

void ControladorPropiedad::ingresarMensajeConversacion(string, string) {
}

ControladorPropiedad::~ControladorPropiedad() {

}
