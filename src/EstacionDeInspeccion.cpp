#include "EstacionDeInspeccion.h"

#include <iostream>
#include <stdexcept>

// Prepara la estacion con los valores indicados.
EstacionDeInspeccion::EstacionDeInspeccion(
    int id,
    const std::string& nombre,
    int tiempoPorPieza,
    int vidaUtilSensor
)
    : Maquina(id, nombre),
      tiempoPorPieza(tiempoPorPieza),
      sensor(vidaUtilSensor) {

    // No se admiten tiempos de inspeccion iguales o inferiores a cero.
    if (tiempoPorPieza <= 0) {
        throw std::invalid_argument(
            "El tiempo por pieza debe ser mayor que cero."
        );
    }
}

// Revisa una pieza y registra el trabajo realizado.
bool EstacionDeInspeccion::inspeccionar() {

    // La inspeccion solo se realiza si la maquina esta disponible.
    if (!puedeProcesar()) {
        std::cout << "La estacion " << getNombre()
                  << " no puede inspeccionar en este momento.\n";
        return false;
    }

    // Si el sensor ya se desgasto, primero debe atenderse la falla.
    if (sensor.estaDesgastado()) {
        reportarFalla();
        return false;
    }

    std::cout << "Estacion " << getNombre()
              << " inspeccionando una pieza...\n";

    // Actualiza los contadores heredados de Maquina.
    registrarPieza();
    agregarTiempo(tiempoPorPieza);

    // La inspeccion tambien cuenta como uso del sensor.
    sensor.registrarUso();

    std::cout << "Inspeccion completada correctamente.\n";

    // Al llegar al limite, se detiene la estacion para mantenimiento.
    if (sensor.estaDesgastado()) {
        reportarFalla();
    }

    // La pieza ya fue inspeccionada, aunque el sensor necesite atencion.
    return true;
}

// Metodo que utiliza Planta para solicitar una inspeccion.
bool EstacionDeInspeccion::procesarOperacion() {
    return inspeccionar();
}

// Complementa el reporte general con informacion del sensor.
void EstacionDeInspeccion::mostrarEstado() const {
    Maquina::mostrarEstado();

    std::cout << "--- Datos de la Estacion de Inspeccion ---\n";
    std::cout << "Tiempo por pieza: "
              << tiempoPorPieza << " segundos\n";
    std::cout << "Vida util del sensor: "
              << sensor.getVidaUtil() << '\n';
    std::cout << "Desgaste del sensor: "
              << sensor.getDesgaste() << '\n';
}

// Restablece el sensor y registra el paro correspondiente.
void EstacionDeInspeccion::realizarMantenimiento() {

    if (!estaEnFalla()) {
        std::cout << "La estacion " << getNombre()
                  << " no requiere mantenimiento.\n";
        return;
    }

    std::cout << "Realizando mantenimiento en la estacion "
              << getNombre() << "...\n";

    // El sensor vuelve a tener toda su vida util disponible.
    sensor.restaurar();

    Maquina::realizarMantenimiento();

    std::cout << "Sensor restaurado. Desgaste actual: "
              << sensor.getDesgaste() << '\n';
}