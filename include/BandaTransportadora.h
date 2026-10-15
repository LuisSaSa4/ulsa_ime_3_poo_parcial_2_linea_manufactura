#ifndef BANDA_TRANSPORTADORA_H
#define BANDA_TRANSPORTADORA_H

#include "Maquina.h"
#include "Motor.h"
#include <string>

class BandaTransportadora : public Maquina {
private:
    Motor motor;              // composición
    int tiempoPorPieza;      // segundos por pieza
    int piezasTransportadas;   //contador INDIVIDUAL de piezas

   public:
    BandaTransportadora(int id,
                        const std::string& nombre,
                        int tiempoPorPieza,
                        int vidaUtil);

    void procesarPieza();
    bool procesarOperacion() override;
    void mostrarEstado() const override;
    void realizarMantenimiento() override;

    // Métodos propios
    int getPiezasTransportadas() const;
    int getTiempoPorPieza() const;
    int getVidaMotor() const;
};

#endif