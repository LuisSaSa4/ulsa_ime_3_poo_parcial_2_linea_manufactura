#ifndef BANDA_TRANSPORTADORA_H
#define BANDA_TRANSPORTADORA_H

#include "Maquina.h"
#include "Motor.h"
#include <string>

class BandaTransportadora : public Maquina {
private:
    Motor motor;              // composición
    double velocidadBanda;    // valor km/h o m/s???
    double desgasteBanda;     // desgaste acumulado ****INDIVIDUAl*****

