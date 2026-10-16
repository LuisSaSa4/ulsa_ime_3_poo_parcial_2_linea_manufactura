#ifndef BANDATRANSPORTADORA_H
#define BANDATRANSPORTADORA_H

#include "Maquina.h"
#include "MotorBanda.h"

#include <string>

// Equipo que desplaza las piezas a lo largo de la linea de produccion.
class BandaTransportadora : public Maquina {
private:
    int tiempoPorPieza;

    // La banda contiene su propio motor.
    MotorBanda motor;

public:
    // Configura la banda, su tiempo de traslado y la vida del motor.
    BandaTransportadora(int id, const std::string& nombre,
                        int tiempoPorPieza, int vidaUtilMotor);

    // Traslada una pieza hacia la siguiente estacion.
    bool transportar();

    // Implementa la operacion comun exigida por Maquina.
    bool procesarOperacion() override;

    // Imprime las estadisticas de la banda y del motor.
    void mostrarEstado() const override;

    // Recupera el motor cuando se presenta una falla.
    void realizarMantenimiento() override;
};

#endif
