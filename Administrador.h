#ifndef ADMINISITRADOR_H
#define ADMINISITRADOR_H

#include "Usuario.h"
#include <string>
#include <iostream>
using namespace std;

class Administrador : public Usuario {
public:
    Administrador(string, string);

    ~Administrador();
};

#endif