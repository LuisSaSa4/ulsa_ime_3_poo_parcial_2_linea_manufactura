#include "BandaTransportadora.h"

#include <iostream>
#include <stdexcept>

// Construye la banda y establece sus parametros de operacion.
BandaTransportadora::BandaTransportadora(
    int id,
    const std::string& nombre,
    int tiempoPorPieza,
    int vidaUtilMotor
)
    : Maquina(id, nombre),
      tiempoPorPieza(tiempoPorPieza),
      motor(vidaUtilMotor) {

    // El traslado debe tomar al menos un segundo.
    if (tiempoPorPieza <= 0) {
        throw std::invalid_argument(
            "El tiempo por pieza debe ser mayor que cero."
        );
    }
}

// Realiza el traslado de una pieza por la banda.
bool BandaTransportadora::transportar() {

    // Comprueba que la banda pueda ponerse en movimiento.
    if (!puedeProcesar()) {
        std::cout << "La banda " << getNombre()
                  << " no puede transportar piezas.\n";
        return false;
    }

    // No se mueve ninguna pieza si el motor ya alcanzo su limite.
    if (motor.estaDesgastado()) {
        reportarFalla();
        return false;
    }

    std::cout << "Banda transportadora " << getNombre()
              << " trasladando una pieza...\n";

    // Actualiza los registros generales de produccion.
    registrarPieza();
    agregarTiempo(tiempoPorPieza);

    // El motor acumula desgaste durante el traslado.
    motor.registrarUso();

    std::cout << "Traslado completado correctamente.\n";

    // Si se agoto la vida util, se reporta la falla para el siguiente ciclo.
    if (motor.estaDesgastado()) {
        reportarFalla();
    }

    // El traslado actual se completo correctamente.
    return true;
}

// Permite a Planta utilizar la banda mediante la interfaz base.
bool BandaTransportadora::procesarOperacion() {
    return transportar();
}

// Complementa el reporte general con los datos del motor.
void BandaTransportadora::mostrarEstado() const {
    Maquina::mostrarEstado();

    std::cout << "--- Datos de la Banda Transportadora ---\n";
    std::cout << "Tiempo por pieza: "
              << tiempoPorPieza << " segundos\n";
    std::cout << "Vida util del motor: "
              << motor.getVidaUtil() << '\n';
    std::cout << "Desgaste del motor: "
              << motor.getDesgaste() << '\n';
}

// Atiende la falla y devuelve el motor a su estado inicial de desgaste.
void BandaTransportadora::realizarMantenimiento() {

    if (!estaEnFalla()) {
        std::cout << "La banda " << getNombre()
                  << " no necesita mantenimiento.\n";
        return;
    }

    std::cout << "Revisando el motor de la banda "
              << getNombre() << "...\n";

    // El componente se restaura antes de liberar la falla.
    motor.restaurar();

    Maquina::realizarMantenimiento();

    std::cout << "Motor restaurado. Desgaste actual: "
              << motor.getDesgaste() << '\n';
}
