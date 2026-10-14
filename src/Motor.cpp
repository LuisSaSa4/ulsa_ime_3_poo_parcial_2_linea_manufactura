#include "Motor.h"
#include <iostream>
#include <stdexcept>

Motor::Motor(int vidaInicial)
    : vidaUtil(vidaInicial), desgaste(1.0) {   // desgaste fijo
    if (vidaInicial <= 0)
        throw std::invalid_argument("vidaInicial debe ser > 0");
}
void Motor::usar() {
    if (vidaUtil > 0) {
        vidaUtil -= static_cast<int>(desgaste);
        if (vidaUtil < 0) vidaUtil = 0;
    }
}

bool Motor::estaDesgastado() const {
    return vidaUtil <= 0;
}

void Motor::restaurar() {
    // Ojo: necesitas guardar el valor inicial para restaurar.
    // Si el diagrama no lo pide, puedes asumir un valor fijo.
     vidaUtil = 50;   // ajustar???
}

int Motor::getVidaUtil() const { return vidaUtil; }
double Motor::getDesgaste() const { return desgaste; }

void Motor::mostrarEstado() const {
    std::cout << "    Motor -> vida: " << vidaUtil << "\n";
}
    