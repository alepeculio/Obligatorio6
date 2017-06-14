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
#include "Zona.h"
#include "KeyInt.h"
#include "ControladorUsuario.h"

ControladorPropiedad::ControladorPropiedad(IUsuario* iUsuario) {
    this->iUsuario = iUsuario;

    departamentos = new ListDicc();
    edificios = new ListDicc();

    departamentos->add(new Departamento("Mat1", "Dep1"), new KeyString("Dep1"));
    departamentos->add(new Departamento("Mat2", "Dep2"), new KeyString("Dep2"));
    departamentos->add(new Departamento("Mat3", "Dep3"), new KeyString("Dep3"));
    departamentos->add(new Departamento("Mat4", "Dep4"), new KeyString("Dep4"));
    departamentos->add(new Departamento("Mat5", "Dep5"), new KeyString("Dep5"));
}

ICollection* ControladorPropiedad::listarPropiedades(int codigo) {
    KeyInt* k = new KeyInt(codigo); 
    if(zonas->member(k)) {  
       Zona* z = dynamic_cast <Zona*> (zonas->find(k));
       return z->listarPropiedad();
    }
    delete k;
}

ICollection* ControladorPropiedad::listarMensajes(int codigo) {

}

void ControladorPropiedad::ingresarMensaje(string texto, string aov) {
    propiedad->ingresarMensaje(texto, aov, this->iUsuario->getUsuarioActual());
}
// agregue.
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

void ControladorPropiedad::ingresarEdificio(string nombre, int pisos, float gastos) {
    this->edificios->add(new Edificio(nombre, pisos, gastos), new KeyString(nombre));
}

DtInmoProp* ControladorPropiedad::selectPropiedad(int codigo) {

}

void ControladorPropiedad::seleccionarPropiedad(int codigo) {

}

void ControladorPropiedad::modificarApart(DtApartamento* dtApto) {
}

void ControladorPropiedad::modificarCasa(DtCasa* dtCasa) {
}

ControladorPropiedad::~ControladorPropiedad() {

}