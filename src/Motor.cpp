#include "Motor.h"
#include <iostream>
#include <stdexcept>

Motor::Motor(int vidaInicial)
    : vidaUtil(vidaInicial), desgaste(1.0) {   // desgaste fijo
    if (vidaInicial <= 0)
        throw std::invalid_argument("vidaInicial debe ser > 0");
}
