#ifndef DTHORA_H
#define DTHORA_H

class DtHora {
private:
    int min;
    int hora;

public:
    DtHora(int, int);

    int getMin();
    int getHora();

    ~DtHora();
};

#endif