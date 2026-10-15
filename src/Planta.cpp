
#include "Planta.h"

#include <iostream>

// Inicializa el contador de produccion.
Planta::Planta()
    : piezasTerminadas(0) {
}

// Guarda la referencia a una maquina sin crear una copia.
void Planta::agregarMaquina(Maquina* maquina) {
    if (maquina == nullptr) {
        std::cout << "No se puede agregar una maquina nula.\n";
        return;
    }

    // Evita registrar dos veces el mismo objeto.
    for (Maquina* registrada : maquinas) {
        if (registrada == maquina) {
            std::cout << "La maquina ya esta registrada.\n";
            return;
        }
    }

    maquinas.push_back(maquina);

    std::cout << "Maquina agregada a la planta: "
              << maquina->getNombre() << '\n';
}

// Activa las maquinas respetando el orden de registro.
void Planta::encenderMaquinas() {
    for (Maquina* maquina : maquinas) {
        maquina->encender();
    }
}

// Detiene todos los equipos de la linea.
void Planta::apagarMaquinas() {
    for (Maquina* maquina : maquinas) {
        maquina->apagar();
    }
}
