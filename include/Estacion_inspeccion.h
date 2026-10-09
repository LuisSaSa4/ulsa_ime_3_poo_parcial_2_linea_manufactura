#ifndef ESTACION_INSPECCION_H
#define ESTACION_INSPECCION_H

#include <string>
#include "Maquina.h"
#include "Sensor.h"

// Estacion de inspeccion: mide la pieza con un Sensor.
//   - Herencia:    EstacionInspeccion es una Maquina.
//   - Composicion: EstacionInspeccion contiene (y es duena de) un Sensor.
//
// Regla de falla: la estacion falla en la MISMA pieza que agota la
// calibracion del sensor (la pieza se termina y despues queda en falla).
// El mantenimiento recalibra el sensor, quita la falla y NO suma tiempo.
class EstacionInspeccion : public Maquina {
private:
    int segundosPorPieza;    // tiempo por pieza (> 0)
    double toleranciaMm;     // tolerancia de medicion en mm (> 0)
    Sensor sensor;           // componente (composicion)

public:
    EstacionInspeccion(int id, const std::string& nombre,
                       int segundosPorPieza, double toleranciaMm,
                       int calibracionSensor);

    // Metodos propios
    // Inspecciona una pieza. Devuelve true si la proceso, false si la rechazo.
    bool procesarPieza();
    // Recalibra el sensor y registra el mantenimiento (solo si esta en falla).
    void realizarMantenimiento();

    int getSegundosPorPieza() const;
    double getToleranciaMm() const;
    const Sensor& getSensor() const;

    // Redefine el de Maquina y reutiliza su version.
    void mostrarEstado() const;
};

#endif