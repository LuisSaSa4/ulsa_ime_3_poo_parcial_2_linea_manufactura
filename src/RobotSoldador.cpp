
#include "RobotSoldador.h"

#include <iostream>
#include <stdexcept>

// Constructor que inicializa el robot soldador y su componente.
RobotSoldador::RobotSoldador(
    int id,
    const std::string& nombre,int tiempoPorPieza,int vidaUtilAntorcha): Maquina(id, nombre),tiempoPorPieza(tiempoPorPieza),antorcha(vidaUtilAntorcha) {

    // Validar que el tiempo de soldadura sea mayor que cero.
    if (tiempoPorPieza <= 0) {
        throw std::invalid_argument(
            "El tiempo por pieza debe ser mayor que cero."
        );
    }
}

// Realizar el proceso de soldadura de una pieza.
bool RobotSoldador::soldar() {
    // Verificar que el robot esté encendido y no presente fallas.
    if (!puedeProcesar()) {
        std::cout << "El robot soldador no puede procesar: "
                  << "esta apagado o en falla.\n";
        return false;
    }

    // Mostrar el inicio del proceso de soldadura.
    std::cout << "Robot soldador soldando pieza "
              << getPiezasProcesadas() + 1 << "...\n";

    // Registrar la pieza procesada.
    registrarPieza();

    // Acumular el tiempo que tardó la soldadura.
    agregarTiempo(tiempoPorPieza);

    // Registrar el uso de la antorcha.
    antorcha.registrarUso();

    // Comprobar si la antorcha alcanzó su límite de desgaste.
    if (antorcha.estaDesgastado()) {
        std::cout << "FALLA DETECTADA: la antorcha alcanzo "
                  << "su limite de vida util.\n";

        // Registrar la falla en la máquina.
        reportarFalla();

        // Realizar el mantenimiento para restaurar la antorcha.
        realizarMantenimiento();
    }

    // Indicar que la pieza se procesó correctamente.
    return true;
}

// Mostrar el estado general del robot y de su antorcha.
void RobotSoldador::mostrarEstado() const {
    // Mostrar primero la información general de la máquina.
    Maquina::mostrarEstado();

    // Mostrar la información específica del robot soldador.
    std::cout << "Tiempo por pieza: "
              << tiempoPorPieza << " segundos\n";

    // Mostrar la vida útil y el desgaste de la antorcha.
    std::cout << "Vida util de la antorcha: "
              << antorcha.getVidaUtil() << " usos\n";

    std::cout << "Desgaste de la antorcha: "
              << antorcha.getDesgaste() << '\n';
}

// Realizar el mantenimiento específico del robot soldador.
void RobotSoldador::realizarMantenimiento() {
    std::cout << "\nIniciando mantenimiento del robot soldador...\n";

    // Restaurar el desgaste del componente.
    antorcha.restaurar();

    std::cout << "Desgaste de la antorcha reiniciado.\n";

    // Ejecutar el mantenimiento general de la clase base.
    // Esto elimina la falla y registra un paro.
    Maquina::realizarMantenimiento();
}
