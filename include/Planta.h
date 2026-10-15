#ifndef PLANTA_H
#define PLANTA_H

#include "Maquina.h"

#include <vector>

class Planta {
private:
    std::vector<Maquina*> maquinas;
    int piezasTerminadas;

public:
    Planta();

    void agregarMaquina(Maquina* maquina);
    void encenderMaquinas();
    void apagarMaquinas();
};

#endif
