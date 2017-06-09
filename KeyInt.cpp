#include "KeyInt.h"

KeyInt::KeyInt(int n) {
    this->n = n;
}

int KeyInt::getKeyInt() {
    return this->n;
}

bool KeyInt::equals(IKey* clave) {
    bool es = false;
    KeyInt* c = dynamic_cast<KeyInt*>(clave);
    if (c->getKeyInt() == this->getKeyInt()) {
        es = true;
    }
    return es;
}

KeyInt::~KeyInt() {
}
