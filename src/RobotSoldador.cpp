
#include "RobotSoldador.h"

#include <iostream>
#include <stdexcept>

// Constructor del RobotSoldador.
// Inicializa la clase base, el tiempo de soldadura y la antorcha.
RobotSoldador::RobotSoldador(
    int id,
    const std::string& nombre,
    int tiempoPorPieza,
    int vidaUtilAntorcha
)
    : Maquina(id, nombre),
      tiempoPorPieza(tiempoPorPieza),
      antorcha(vidaUtilAntorcha) {

    // El tiempo de procesamiento debe ser positivo.
    if (tiempoPorPieza <= 0) {
        throw std::invalid_argument(
            "El tiempo por pieza debe ser mayor que cero."
        );
    }
}

// Realiza la soldadura de una pieza.
bool RobotSoldador::soldar() {

    // Verifica que el robot este encendido y sin fallas.
    if (!puedeProcesar()) {
        std::cout << "El robot " << getNombre()
                  << " no puede soldar.\n";
        return false;
    }

    // Comprueba el desgaste antes de comenzar.
    if (antorcha.estaDesgastado()) {
        reportarFalla();
        return false;
    }

    std::cout << "Robot " << getNombre()
              << " soldando una pieza...\n";

    // Registra las estadisticas de la operacion.
    registrarPieza();
    agregarTiempo(tiempoPorPieza);

    // Cada pieza soldada desgasta la antorcha.
    antorcha.registrarUso();

    std::cout << "Pieza soldada correctamente.\n";

    // Si la antorcha llego a su limite, se reporta la falla.
    if (antorcha.estaDesgastado()) {
        reportarFalla();
    }

    // La pieza actual se completo correctamente.
    return true;
}

// Metodo que Planta utilizara para procesar una pieza.
bool RobotSoldador::procesarOperacion() {
    return soldar();
}

// Muestra el estado general y particular del robot.
void RobotSoldador::mostrarEstado() const {

    // Reutiliza el metodo de la clase base.
    Maquina::mostrarEstado();

    std::cout << "--- Datos del Robot Soldador ---\n";
    std::cout << "Tiempo por pieza: "
              << tiempoPorPieza << " segundos\n";

    std::cout << "Vida util de la antorcha: "
              << antorcha.getVidaUtil() << '\n';

    std::cout << "Desgaste de la antorcha: "
              << antorcha.getDesgaste() << '\n';
}

// Realiza el mantenimiento del robot soldador.
void RobotSoldador::realizarMantenimiento() {

    // Solo se realiza si existe una falla.
    if (!estaEnFalla()) {
        std::cout << "El robot " << getNombre()
                  << " no necesita mantenimiento.\n";
        return;
    }

    std::cout << "Realizando mantenimiento al robot "
              << getNombre() << "...\n";

    // Primero se restaura el componente.
    antorcha.restaurar();

    // Despues se registra el mantenimiento general.
    Maquina::realizarMantenimiento();

    std::cout << "Antorcha restaurada. Desgaste actual: "
              << antorcha.getDesgaste() << '\n';
}
