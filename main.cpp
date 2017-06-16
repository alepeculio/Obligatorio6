#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdexcept>
#include <iomanip>

#include "Fabrica.h"
#include "Usuario.h"
#include "Administrador.h"
#include "Inmobiliaria.h"
#include "Interesado.h"
#include "Aviso.h"
#include "Venta.h"
#include "DtDepartamento.h"
#include "DtZona.h"
#include "DtEdificio.h"
#include "DtInmoProp.h"
#include "DtMensaje.h"
#include "DtORIZona.h"
#include "DtORIDep.h"
#include "DtORIInmo.h"

using namespace std;

Fabrica* fabrica;
IUsuario* iUsuario;
IPropiedad* iPropiedad;

void iniciarSesion();
void cerrarSesion();
void altaInmobiliaria();
void altaInteresado();
void altaEdificio();
void altaPropiedad();
void consultarPropiedad();
void modificarPropiedad();
void eliminarPropiedad();
void enviarMensajeInteresado();
void enviarMensajeInmobiliaria();
void obtenerReporteInmobiliarias();

void menuAdmin();
void menuInmobiliaria();
void menuInteresado();

void str(string&);
DtDireccion* generarDireccion();
bool mensajeOpcion(string);
template<typename T> void elemento(T t, const int& ancho);

int main() {
    fabrica = new Fabrica();
    iUsuario = fabrica->getIUsuario();
    iPropiedad = fabrica->getIPropiedad(iUsuario);

    iUsuario->ingresarAdministrador("admin", "admin");

    while (true) {
        iniciarSesion();

        TipoUsuario tipoUsuario = iUsuario->getTipoUsuario();

        if (tipoUsuario == ADMINISTRADOR) {
            menuAdmin();
        } else {
            if (tipoUsuario == INMOBILIARIA) {
                menuInmobiliaria();
            } else {
                if (tipoUsuario == INTERESADO) {
                    menuInteresado();
                } else {
                    cout << "-----------------------------------------" << endl;
                    cout << "Logueo Denegado" << endl;
                }
            }
        }
    }

    return 0;
}

void menuAdmin() {
    int opcion = -1;

    cout << "-----------------------------------------" << endl;
    cout << "   Sesion Iniciada!" << endl;

    while (opcion != 0) {
        cout << "===== Menu Administrador ================" << endl;
        cout << endl;
        cout << " 1 - Alta Inmobiliaria" << endl;
        cout << " 2 - Alta Interesado" << endl;
        cout << " 3 - Obtener Reporte Inmobiliarias" << endl;
        cout << " 0 - Cerrar Sesion" << endl;
        cout << endl;
        cout << "opcion: ";

        cin >> opcion;

        switch (opcion) {
            case 1:
                altaInmobiliaria();
                break;
            case 2:
                altaInteresado();
                break;
            case 3:
                obtenerReporteInmobiliarias();
                break;
            case 0:
                cerrarSesion();
                break;
        }
    }
}

void menuInmobiliaria() {
    int opcion = -1;

    cout << "-----------------------------------------" << endl;
    cout << "   Sesion Iniciada!" << endl;

    while (opcion != 0) {
        cout << "===== Menu Inmobiliaria =================" << endl;
        cout << endl;
        cout << " 1 - Alta Edificio" << endl;
        cout << " 2 - Alta Propiedad" << endl;
        cout << " 3 - Consultar Propiedad" << endl;
        cout << " 4 - Modificar Propiedad" << endl;
        cout << " 5 - Eliminar Propiedad" << endl;
        cout << " 6 - Enviar Mensaje" << endl;
        cout << " 0 - Cerrar Sesion" << endl;
        cout << endl;
        cout << "opcion: ";

        cin >> opcion;

        switch (opcion) {
            case 1:
                altaEdificio();
                break;
            case 2:
                altaPropiedad();
                break;
            case 3:
                consultarPropiedad();
                break;
            case 4:
                modificarPropiedad();
                break;
            case 5:
                eliminarPropiedad();
                break;
            case 6:
                enviarMensajeInmobiliaria();
                break;
            case 0:
                cerrarSesion();
                break;
        }
    }
}

void menuInteresado() {
    int opcion = -1;

    cout << "-----------------------------------------" << endl;
    cout << "   Sesion Iniciada!" << endl;

    while (opcion != 0) {
        cout << "===== Menu Interesado ===================" << endl;
        cout << endl;
        cout << " 1 - Consultar Propiedad" << endl;
        cout << " 2 - Enviar Mensaje" << endl;
        cout << " 0 - Cerrar Sesion" << endl;
        cout << endl;
        cout << "opcion: ";

        cin >> opcion;

        switch (opcion) {
            case 1:
                consultarPropiedad();
                break;
            case 2:
                enviarMensajeInteresado();
                break;
            case 0:
                cerrarSesion();
                break;
        }
    }
}

void iniciarSesion() {
    string email;
    string cont;
    bool correcta = false;
    bool cancelar = false;
    bool verificada = false;

    cout << "===== Iniciar Sesion ====================" << endl;

    cout << "Email: ";
    str(email);

    try {
        iUsuario->iniciarSesion(email);
    } catch (const invalid_argument& e) {
        cout << "-----------------------------------------" << endl;
        cout << "   Error: " << e.what() << endl;
        return;
    }

    TipoUsuario tipoUsuario = iUsuario->getTipoUsuario();

    if (tipoUsuario == ADMINISTRADOR) {
        while (!correcta && !cancelar) {
            cout << "Contrasenia: ";
            str(cont);
            correcta = iUsuario->ingresarContrasenia(cont);

            if (!correcta)
                cancelar = !mensajeOpcion("Volver a intentar?");
        }

        if (correcta) {
            iUsuario->asignarSesion();
        }
    } else {
        if (iUsuario->esUsuarioNuevo()) {
            cout << "Contrasenia: ";
            str(cont);

            iUsuario->primerContrasenia(cont);

            cout << "Verificacion: ";
            str(cont);

            verificada = iUsuario->verificarContrasenia(cont);

            if (verificada) {
                iUsuario->activarUsuario();
                iUsuario->asignarSesion();
            }
        } else {
            while (!correcta && !cancelar) {
                cout << "Contrasenia: ";
                str(cont);
                correcta = iUsuario->ingresarContrasenia(cont);

                if (!correcta)
                    cancelar = !mensajeOpcion("Volver a intentar?");
            }

            if (correcta) {
                iUsuario->asignarSesion();
            }
        }
    }
}

void cerrarSesion() {
    iUsuario->cerrarSesion();

    cout << "-----------------------------------------" << endl;
    cout << "   Sesion Cerrada!" << endl;
}

void altaInmobiliaria() {
    string nombre;
    DtDireccion* direccion;
    string email;

    cout << "===== Alta Inmobiliaira =================" << endl;

    cout << "Nombre: ";
    str(nombre);
    direccion = generarDireccion();
    cout << "Email: ";
    str(email);

    try {
        iUsuario->ingresarInmobiliaria(nombre, direccion, email);
    } catch (const invalid_argument& e) {
        cout << "-----------------------------------------" << endl;
        cout << "   Error: " << e.what() << endl;
        return;
    }

    cout << "-----------------------------------------" << endl;
    cout << "   Inmobiliaria Ingresada!" << endl;
}

void altaInteresado() {
    string nombre;
    string apellido;
    int edad;
    string email;

    cout << "===== Alta Interesado ===================" << endl;

    cout << "Nombre: ";
    str(nombre);
    cout << "Apellido: ";
    str(apellido);
    cout << "Edad: ";
    cin >> edad;
    cout << "Email: ";
    str(email);

    try {
        iUsuario->ingresarInteresado(nombre, apellido, edad, email);
    } catch (const invalid_argument& e) {
        cout << "-----------------------------------------" << endl;
        cout << "   Error: " << e.what() << endl;
        return;
    }

    cout << "-----------------------------------------" << endl;
    cout << "   Interesado Ingresado!" << endl;
}

void altaEdificio() {
    string nombre;
    int pisos;
    float gastos;

    cout << "===== Alta Edificio =====================" << endl;

    cout << "Nombre: ";
    str(nombre);
    cout << "Pisos: ";
    cin >> pisos;
    cout << "Gastos: ";
    cin >> gastos;

    iPropiedad->ingresarEdificio(nombre, pisos, gastos);

    cout << "-----------------------------------------" << endl;
    cout << "   Edificio Ingresado!" << endl;
}

void altaPropiedad() {
    string depNombre;
    int zonaCodigo;
    int opcion = 0;
    string nombreEdificio;
    int precioV;
    int precioA;

    int codigo;
    int num;
    int cantAmb;
    int cantDorm;
    int cantBanios;
    bool garage;
    DtDireccion* direccion;
    float m2Edificados;
    float m2Tot;
    float m2EspVerde;

    cout << "===== Alta Propiedad ====================" << endl;

    ICollection* departamentos = iPropiedad->listarDepartamentos();
    IIterator* depIterator = departamentos->iterator();

    cout << endl << "Eliga departamento: " << endl << endl;
    elemento("Letra", 6);
    elemento("Matricula", 10);
    elemento("Nombre", 40);
    cout << endl;

    while (depIterator->hasNext()) {
        DtDepartamento* dtDep = dynamic_cast<DtDepartamento*> (depIterator->getCurrent());
        elemento(dtDep->getLetra(), 6);
        elemento(dtDep->getMatricula(), 10);
        elemento(dtDep->getNombre(), 40);
        cout << endl;

        depIterator->next();
    }
    delete depIterator;

    cout << endl << "Nombre: ";
    str(depNombre);

    ICollection* zonas;
    try {
        zonas = iPropiedad->listarZonas(depNombre);
    } catch (const invalid_argument& e) {
        cout << "-----------------------------------------" << endl;
        cout << "   Error: " << e.what() << endl;
        return;
    }

    IIterator* zonaIterator = zonas->iterator();

    cout << "-----------------------------------------" << endl;
    cout << "Zonas del departamento " << depNombre << ": " << endl << endl;
    elemento("Codigo", 7);
    elemento("Nombre", 10);
    cout << endl << endl;

    while (zonaIterator->hasNext()) {
        DtZona* dtZona = dynamic_cast<DtZona*> (zonaIterator->getCurrent());

        elemento(dtZona->getCodigo(), 7);
        elemento(dtZona->getNombre(), 10);
        cout << endl;

        zonaIterator->next();
    }
    delete zonaIterator;

    cout << endl << "Codigo: ";
    cin >> zonaCodigo;

    try {
        iPropiedad->selectZona(zonaCodigo);
    } catch (const invalid_argument& e) {
        cout << "-----------------------------------------" << endl;
        cout << "   Error: " << e.what() << endl;
        return;
    }

    cout << "-----------------------------------------" << endl;
    cout << " - Eliga tipo de propiedad:" << endl;
    cout << " 1 - Apartamento" << endl;
    cout << " 2 - Casa" << endl;
    cout << endl;

    while (true) {
        cout << "opcion: ";
        cin >> opcion;

        if (opcion == 1 || opcion == 2)
            break;
    }

    cout << "-----------------------------------------" << endl;
    if (opcion == 1) {
        ICollection* edificios = iPropiedad->listarEdificios();
        IIterator* edifIterator = edificios->iterator();

        cout << "Edificios:" << endl << endl;
        elemento("Nombre", 10);
        elemento("Pisos", 10);
        elemento("Gastos", 10);
        cout << endl;

        while (edifIterator->hasNext()) {
            DtEdificio* dtEdificio = dynamic_cast<DtEdificio*> (edifIterator->getCurrent());

            elemento(dtEdificio->getNomEdificio(), 10);
            elemento(dtEdificio->getCantPisos(), 10);
            elemento(dtEdificio->getGastosComunes(), 10);
            cout << endl;

            edifIterator->next();
        }
        delete edifIterator;

        cout << endl;
        if (mensajeOpcion("Desea dar de alta un edificio?")) {
            altaEdificio();
        }

        cout << "-----------------------------------------" << endl;
        cout << "En que edificio esta el apartamento?\nNombre: ";
        str(nombreEdificio);

        try {
            iPropiedad->selectEdificio(nombreEdificio);
        } catch (const invalid_argument& e) {
            cout << "-----------------------------------------" << endl;
            cout << "   Error: " << e.what() << endl;
            return;
        }

        cout << "-----------------------------------------" << endl;
        cout << "Caracteristicas del apartamento:" << endl << endl;
        if (mensajeOpcion("El apartamento esta en alquiler?")) {
            cout << "Precio Alquiler: ";
            cin >> precioA;
            iPropiedad->fijarAlquiler(precioA);
        }

        cout << "-----------------------------------------" << endl;
        if (mensajeOpcion("El apartamento esta en venta?")) {
            cout << "Precio Venta: ";
            cin >> precioV;
            iPropiedad->fijarVenta(precioV);
        }
        cout << "-----------------------------------------" << endl;

        cout << "Codigo: ";
        cin >> codigo;
        cout << "Numero: ";
        cin >> num;
        cout << "Cantidad Ambientes: ";
        cin >> cantAmb;
        cout << "Cantidad Dormitorios: ";
        cin >> cantDorm;
        cout << "Cantidad Banios: ";
        cin >> cantBanios;
        garage = mensajeOpcion("Tiene garage?");
        direccion = generarDireccion();
        cout << "Metros cuadrados edificados: ";
        cin >> m2Edificados;
        cout << "Metros cuadrados totales: ";
        cin >> m2Tot;

        try {
            iPropiedad->altaApto(new DtApartamento(codigo, cantAmb, cantDorm, cantBanios, garage, direccion, m2Edificados, m2Tot, num));
        } catch (const invalid_argument& e) {
            cout << "-----------------------------------------" << endl;
            cout << "   Error: " << e.what() << endl;
            return;
        }

        cout << "-----------------------------------------" << endl;
        cout << "   Apartamento Ingresado!" << endl;
    } else if (opcion == 2) {
        cout << "Caracteristicas del apartamento:" << endl << endl;
        bool alquiler = false;
        if (mensajeOpcion("La casa esta en alquiler?")) {
            cout << "Precio Alquiler: ";
            cin >> precioA;
            alquiler = iPropiedad->fijarAlquiler(precioA);
        }

        cout << "-----------------------------------------" << endl;
        if (!alquiler || mensajeOpcion("La casa esta en venta?")) {
            cout << "Precio Venta: ";
            cin >> precioV;
            iPropiedad->fijarVenta(precioV);
        }
        cout << "-----------------------------------------" << endl;

        cout << "Codigo: ";
        cin >> codigo;
        cout << "Cantidad Ambientes: ";
        cin >> cantAmb;
        cout << "Cantidad Dormitorios: ";
        cin >> cantDorm;
        cout << "Cantidad Banios: ";
        cin >> cantBanios;
        garage = mensajeOpcion("Tiene garage?");
        direccion = generarDireccion();
        cout << "Metros cuadrados edificados: ";
        cin >> m2Edificados;
        cout << "Metros cuadrados totales: ";
        cin >> m2Tot;
        cout << "Metros cuadrados de espacio verde: ";
        cin >> m2EspVerde;

        try {
            iPropiedad->altaCasa(new DtCasa(codigo, cantAmb, cantDorm, cantBanios, garage, direccion, m2Edificados, m2Tot, m2EspVerde));
        } catch (const invalid_argument& e) {
            cout << "-----------------------------------------" << endl;
            cout << "   Error: " << e.what() << endl;
            return;
        }

        cout << "-----------------------------------------" << endl;
        cout << "   Casa Ingresada!" << endl;
    }
}


void consultarPropiedad() {
    string depNombre;
    int zonaCodigo;
    int propiedadCodigo;

    cout << "===== Consultar Propiedad ===============" << endl;

    ICollection* departamentos = iPropiedad->listarDepartamentos();
    IIterator* depIterator = departamentos->iterator();

    cout << "Letra \t Matricula \t Nombre" << endl;
    while (depIterator->hasNext()) {
        DtDepartamento* dtDep = dynamic_cast<DtDepartamento*> (depIterator->getCurrent());
        cout << dtDep->getLetra() << "\t" << dtDep->getMatricula() << "\t" << dtDep->getNombre() << endl;
        depIterator->next();
    }
    delete depIterator;

    cout << endl << "Nombre: ";
    str(depNombre);

    ICollection* zonas = iPropiedad->listarZonas(depNombre);
    IIterator* zonaIterator = zonas->iterator();

    cout << "Codigo \t Nombre" << endl;
    while (zonaIterator->hasNext()) {
        DtZona* dtZona = dynamic_cast<DtZona*> (zonaIterator->getCurrent());
        cout << dtZona->getCodigo() << "\t" << dtZona->getNombre() << endl;
        zonaIterator->next();
    }
    delete zonaIterator;

    cout << endl << "Codigo Zona: ";
    cin >> zonaCodigo;

    ICollection* propiedades = iPropiedad->listarPropiedades(zonaCodigo);
    IIterator* propIterator = propiedades->iterator();

    cout << "Codigo \t Direccion \t Tipo " << endl;
    while (propIterator->hasNext()) {
        DtPropiedad* dtPropropiedad = dynamic_cast<DtPropiedad*> (propIterator->getCurrent());

        cout << dtPropropiedad->getCodigo() << " \t " << dtPropropiedad->getDireccion()->getCalle() << " " << dtPropropiedad->getDireccion()->getNumero();

        DtApartamento* dtApartamento = dynamic_cast<DtApartamento*> (dtPropropiedad);
        if (dtApartamento != NULL) {
            cout << " \t Apartamento" << endl;
        } else {
            DtCasa* dtCasa = dynamic_cast<DtCasa*> (dtPropropiedad);
            if (dtCasa != NULL) {
                cout << " \t Casa" << endl;
            }
        }

        propIterator->next();
    }
    delete propIterator;

    cout << endl << "Codigo Propiedad: ";
    cin >> propiedadCodigo;

    DtInmoProp* dtInmoProp = iPropiedad->selectPropiedad(propiedadCodigo);
    DtPropiedad* dtProp = dtInmoProp->getDtPropiedad();
    DtInmobiliaria* dtInmo = dtInmoProp->getDtInmobiliaria();
    DtApartamento* dtApto = dynamic_cast<DtApartamento*> (dtProp);
    DtCasa* dtCasa = dynamic_cast<DtCasa*> (dtProp);

    cout << endl;
    cout << "----- Propiedad -------------------------" << endl;
    cout << "Tipo: ";

    if (dtApto != NULL) {
        cout << "Apartamento" << endl;
        cout << "Numero: " << dtApto->getNum();
    } else if (dtCasa != NULL) {
        cout << "Casa" << endl;
    }

    cout << "Cantidad Ambientes: " << dtProp->getCantAmb() << endl;
    cout << "Cantidad Dormitorios: " << dtProp->getCantDorm() << endl;
    cout << "Cantidad Banios: " << dtProp->getCantBanios() << endl;
    cout << "Garage: " << (dtProp->getGarage() ? "Si" : "No") << endl;
    cout << "Direccion: " << dtProp->getDireccion()->getCiudad() << ", " << dtProp->getDireccion()->getCalle() << " " << dtProp->getDireccion()->getNumero() << endl;
    cout << "Metros Cuadrados Edificados: " << dtProp->getM2Edificados() << endl;
    cout << "Metros Cuadrados Totales: " << dtProp->getM2Tot() << endl;

    if (dtCasa != NULL) {
        cout << "Metros Cuadrados de Espacio Verde: " << dtCasa->getM2EspVerde() << endl;
    }

    cout << endl;
    cout << "----- Inmobiliaria ----------------------" << endl;
    cout << "Correo: " << dtInmo->getCorreo() << endl;
    cout << "Nomnbre: " << dtInmo->getNombre() << endl;
    cout << "Ubicacion: " << *dtInmo->getDireccion() << endl;
    cout << endl;
}

void modificarPropiedad() {
    int codigo;
    int num;
    int cantAmb;
    int cantDorm;
    int cantBanios;
    bool garage;
    DtDireccion* direccion;
    float n2Edificados;
    float m2Tot;
    float m2EspVerde;

    cout << "===== Modificar Propiedad ===============" << endl;

    cout << "Codigo Propiedad: ";
    cin >> codigo;

    iPropiedad->seleccionarPropiedad(codigo);

    if (true) {
        cout << "Numero: ";
        cin >> num;
        cout << "Cantidad Ambientes: ";
        cin >> cantAmb;
        cout << "Cantidad Dormitorios: ";
        cin >> cantDorm;
        cout << "Cantidad Banios: ";
        cin >> cantBanios;
        garage = mensajeOpcion("Tiene garage?");
        direccion = generarDireccion();
        cout << "Metros cuadrados edificados: ";
        cin >> n2Edificados;
        cout << "Metros cuadrados totales: ";
        cin >> m2Tot;

        iPropiedad->altaApto(new DtApartamento(0, cantAmb, cantDorm, cantBanios, garage, direccion, n2Edificados, m2Tot, num));

        cout << "-----------------------------------------" << endl;
        cout << "   Apartamento Modificado!" << endl;
    } else {
        cout << "Cantidad Ambientes: ";
        cin >> cantAmb;
        cout << "Cantidad Dormitorios: ";
        cin >> cantDorm;
        cout << "Cantidad Banios: ";
        cin >> cantBanios;
        garage = mensajeOpcion("Tiene garage?");
        direccion = generarDireccion();
        cout << "Metros cuadrados edificados: ";
        cin >> n2Edificados;
        cout << "Metros cuadrados totales: ";
        cin >> m2Tot;
        cout << "Metros cuadrados de espacio verde: ";
        cin >> m2EspVerde;

        iPropiedad->modificarCasa(new DtCasa(0, cantAmb, cantDorm, cantBanios, garage, direccion, n2Edificados, m2Tot, m2EspVerde));

        cout << "-----------------------------------------" << endl;
        cout << "   Casa Modificada!" << endl;
    }
}

void eliminarPropiedad() {
    int codigo;

    cout << "===== Eliminar Propiedad ================" << endl;

    cout << "Codigo Propiedad: ";
    cin >> codigo;

    iPropiedad->eliminarPropiedad(codigo);

    cout << "-----------------------------------------" << endl;
    cout << "   Propiedad Eliminada!" << endl;
}

void enviarMensajeInteresado() {
    string depNombre;
    int zonaCodigo;
    int propiedadCodigo;
    string mensajeNuevo;
    int tipo;

    cout << "===== Enviar Mensaje ====================" << endl;

    ICollection* departamentos = iPropiedad->listarDepartamentos();
    IIterator* depIterator = departamentos->iterator();

    cout << "Letra \t Matricula \t Nombre" << endl;
    while (depIterator->hasNext()) {
        DtDepartamento* dtDep = dynamic_cast<DtDepartamento*> (depIterator->getCurrent());
        cout << dtDep->getLetra() << "\t" << dtDep->getMatricula() << "\t" << dtDep->getNombre() << endl;
        depIterator->next();
    }
    delete depIterator;

    cout << endl << "Nombre: ";
    str(depNombre);

    ICollection* zonas = iPropiedad->listarZonas(depNombre);
    IIterator* zonaIterator = zonas->iterator();

    cout << "Codigo \t Nombre" << endl;
    while (zonaIterator->hasNext()) {
        DtZona* dtZona = dynamic_cast<DtZona*> (zonaIterator->getCurrent());
        cout << dtZona->getCodigo() << "\t" << dtZona->getNombre() << endl;
        zonaIterator->next();
    }
    delete zonaIterator;

    cout << endl << "Codigo Zona: ";
    cin >> zonaCodigo;

    ICollection* propiedades = iPropiedad->listarPropiedades(zonaCodigo);
    IIterator* propIterator = propiedades->iterator();

    cout << "Codigo \t Direccion \t Tipo " << endl;
    while (propIterator->hasNext()) {
        DtPropiedad* dtPropropiedad = dynamic_cast<DtPropiedad*> (propIterator->getCurrent());

        cout << dtPropropiedad->getCodigo() << " \t " << dtPropropiedad->getDireccion()->getCalle() << " " << dtPropropiedad->getDireccion()->getNumero();

        DtApartamento* dtApartamento = dynamic_cast<DtApartamento*> (dtPropropiedad);
        if (dtApartamento != NULL) {
            cout << " \t Apartamento" << endl;
        } else {
            DtCasa* dtCasa = dynamic_cast<DtCasa*> (dtPropropiedad);
            if (dtCasa != NULL) {
                cout << " \t Casa" << endl;
            }
        }

        propIterator->next();
    }
    delete propIterator;

    cout << endl << "Codigo Propiedad: ";
    cin >> propiedadCodigo;

    cout << "----- Mensajes ---------------------" << endl;

    ICollection* mensajes = iPropiedad->listarMensajes(propiedadCodigo);
    IIterator* msjIterator = mensajes->iterator();

    while (msjIterator->hasNext()) {
        DtMensaje* dtMsj = dynamic_cast<DtMensaje*> (msjIterator->getCurrent());

        cout << "[" << *dtMsj->getFecha() << " - " << dtMsj->getHora() << "]" << endl;
        cout << "   " << dtMsj->getTexto() << endl;
        cout << "------------------------------------" << endl;

        msjIterator->next();
    }
    delete msjIterator;

    cout << endl << "Mensaje Nuevo: ";
    str(mensajeNuevo);


    cout << endl << " - Ingresar en:" << endl;
    cout << " 1 - Alquiler" << endl;
    cout << " 2 - Venta" << endl;
    cout << endl;

    while (true) {
        cout << "opcion: ";
        cin >> tipo;

        if (tipo == 1 || tipo == 2)
            break;
    }

    iPropiedad->ingresarMensaje(mensajeNuevo, tipo == 1 ? "Alquiler" : "Venta");

    cout << "-----------------------------------------" << endl;
    cout << "   Mensaje Enviado!" << endl;
}

void enviarMensajeInmobiliaria() {
    cout << "===== Enviar Mensaje ====================" << endl;

    cout << "-----------------------------------------" << endl;
    cout << "   Mensaje Enviado!" << endl;

}

void obtenerReporteInmobiliarias() {
    cout << "===== Obtener Reporte Inmobiliarias =====" << endl;

    ICollection* dtORIInmos = iUsuario->obtenerReporteInmobiliarias();
    IIterator* inmos = dtORIInmos->iterator();
    while (inmos->hasNext()) {
        DtORIInmo* inmo = dynamic_cast<DtORIInmo*> (inmos->getCurrent());
        DtInmobiliaria* dtInmo = inmo->getInmobiliaria();
        cout << "Nombre: " << dtInmo->getNombre() << endl;
        cout << "Correo: " << dtInmo->getCorreo() << endl;
        cout << "Direccion: " << *dtInmo->getDireccion() << endl << endl;

        elemento("Departamento", 15);
        elemento("Zona", 8);
        elemento("Casas", 6);
        elemento("Apartamentos", 12);
        cout << endl << endl;

        ICollection* dtDeps = inmo->getDtORIDeps();
        IIterator* iDeps = dtDeps->iterator();
        while (iDeps->hasNext()) {
            DtORIDep* dtDep = dynamic_cast<DtORIDep*> (iDeps->getCurrent());

            ICollection* dtZonas = dtDep->getDtORIZonas();
            IIterator* iZonas = dtZonas->iterator();
            while (iZonas->hasNext()) {
                DtORIZona* dtZona = dynamic_cast<DtORIZona*> (iZonas->getCurrent());

                elemento(dtDep->getNombre(), 15);
                elemento(dtZona->getNombre(), 8);
                elemento(dtZona->getCantCasas(), 6);
                elemento(dtZona->getCantAptos(), 12);
                cout << endl;

                iZonas->next();
            }
            delete iZonas;

            iDeps->next();
        }
        delete iDeps;

        inmos->next();

        if (inmos->hasNext())
            cout << "-----------------------------------------" << endl;
    }
    delete inmos;
}


void str(string & str) {
    cin.clear();
    fflush(stdin);
    getline(cin, str);
}

DtDireccion* generarDireccion() {
    string ciudad;
    string calle;
    int numero;

    cout << "- Direccion -" << endl;
    cout << "   Ciudad: ";
    str(ciudad);
    cout << "   Calle: ";
    str(calle);
    cout << "   Numero: ";
    cin >> numero;
    cout << "-------------" << endl;

    return new DtDireccion(ciudad, calle, numero);
}

bool mensajeOpcion(string mensaje) {
    cout << mensaje << " [s / n]: ";

    char c;

    while (true) {
        cin >> c;

        if (c == 's' || c == 'S' || c == 'n' || c == 'N')
            break;
        else
            cout << "[Opcion Invalida] " << mensaje << " [s / n]: ";
    }

    return c == 's' || c == 'S';
}

template<typename T> void elemento(T t, const int& ancho) {
    cout << left << setw(ancho) << setfill(' ') << t;
}