#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Fabrica.h"
#include "Usuario.h"
#include "Adminstrador.h"
#include "Inmobiliaria.h"
#include "Interesado.h"

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

DtDireccion* generarDireccion();
void str(string&);

int main() {
    fabrica = new Fabrica();
    iUsuario = fabrica->getIUsuario();
    iPropiedad = fabrica->getIPropiedad();

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

    iUsuario->iniciarSesion(email);

    TipoUsuario tipoUsuario = iUsuario->getTipoUsuario();

    if (tipoUsuario == ADMINISTRADOR) {
        while (!correcta && !cancelar) {
            cout << "Contrasenia: ";
            str(cont);
            correcta = iUsuario->ingresarContrasenia(cont);

            if (!correcta) {
                cout << "Volver a intentar? [s / n]: ";
                char o;
                cin >> o;
                cancelar = o == 'n';
            }
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

                if (!correcta) {
                    cout << "Volver a intentar? [s / n]: ";
                    char o;
                    cin >> o;
                    cancelar = o == 'n';
                }
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

    iUsuario->ingresarInmobiliaria(nombre, direccion, email);

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

    iUsuario->ingresarInteresado(nombre, apellido, edad, email);

    cout << "-----------------------------------------" << endl;
    cout << "   Interesado Ingresado!" << endl;
}

void altaEdificio() {
    cout << "===== Alta Edificio =====================" << endl;
}

void altaPropiedad() {
    cout << "===== Alta Propiedad ====================" << endl;
}

void consultarPropiedad() {
    cout << "===== Consultar Propiedad ===============" << endl;
}

void modificarPropiedad() {
    cout << "===== Modificar Propiedad ===============" << endl;
}

void eliminarPropiedad() {
    cout << "===== Eliminar Propiedad ================" << endl;
}

void enviarMensajeInteresado() {
    cout << "===== Enviar Mensaje ====================" << endl;
}

void enviarMensajeInmobiliaria() {
    cout << "===== Enviar Mensaje ====================" << endl;
}

void obtenerReporteInmobiliarias() {
    cout << "===== Obtener Reporte Inmobiliarias =====" << endl;
}

DtDireccion* generarDireccion() {
    string ciudad;
    string calle;
    int numero;

    cout << " - Direccion" << endl;
    cout << " Ciudad: ";
    str(ciudad);
    cout << " Calle: ";
    str(calle);
    cout << " Numero: ";
    cin >> numero;

    return new DtDireccion(ciudad, calle, numero);
}

void str(string& str) {
    cin.clear();
    fflush(stdin);

    getline(cin, str);
}