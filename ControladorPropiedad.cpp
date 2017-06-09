#include "ControladorPropiedad.h"
#include "IDictionary.h"
#include "ICollection.h"
#include "IIterator.h"
#include "ListDiccIterator.h"
#include "ListDiccIteratorObj.h"
#include "ICollectible.h"
#include "ListDicc.h"
#include "IKey.h"
#include "Lista.h"
#include "Departamento.h"

IDictionary* ControladorPropiedad::listarPropiedad(int codigo) {

}

ICollection* ControladorPropiedad::listarMensajes(int codigo) {

}

void ControladorPropiedad::ingresarMensaje(string texto, string aov) {

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

}

void ControladorPropiedad::selectZona(int codigo) {

}

void ControladorPropiedad::selectEdificio(string nombreEdificio) {

}

bool ControladorPropiedad::fijarAlquiler(float precioAlquiler) {

}

bool ControladorPropiedad::fijarVenta(float precioVenta) {

}

int ControladorPropiedad::altaApto(DtApartamento* dtApto) {

}

int ControladorPropiedad::altaCasa(DtCasa* dtCasa) {

}

void ControladorPropiedad::eliminarPropiedad(int codigo) {

}

ControladorPropiedad::~ControladorPropiedad() {

}