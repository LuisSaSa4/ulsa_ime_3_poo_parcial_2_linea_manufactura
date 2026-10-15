#ifndef ESTACIONDEINSPECCION_H
#define ESTACIONDEINSPECCION_H

#include "Maquina.h"
#include "SensorInspeccion.h"

#include <string>


// Estacion que revisa las piezas antes de finalizar la produccion.
class EstacionDeInspeccion : public Maquina {
private:
    int tiempoPorPieza;

    // El sensor forma parte de la estacion de inspeccion.
    SensorInspeccion sensor;

public:
    // Configura el tiempo de revision y la vida util del sensor.
    EstacionDeInspeccion(int id, const std::string& nombre,
                         int tiempoPorPieza, int vidaUtilSensor);

    // Ejecuta la inspeccion de una pieza.
    bool inspeccionar();

    // Permite que Planta solicite la operacion.
    bool procesarOperacion() override;

    // Muestra los datos generales y los del sensor.
    void mostrarEstado() const override;

    // Recupera el sensor despues de una falla.
    void realizarMantenimiento() override;
};

#endif