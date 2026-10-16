
#include "Planta.h"

#include <iostream>

// Inicializa el contador de produccion.
Planta::Planta()
    : piezasTerminadas(0) {
}

// Guarda la referencia a una maquina sin crear una copia.
void Planta::agregarMaquina(Maquina* maquina) {
    if (maquina == nullptr) {
        std::cout << "No se puede agregar una maquina nula.\n";
        return;
    }

    // Evita registrar dos veces el mismo objeto.
    for (Maquina* registrada : maquinas) {
        if (registrada == maquina) {
            std::cout << "La maquina ya esta registrada.\n";
            return;
        }
    }

    maquinas.push_back(maquina);

    std::cout << "Maquina agregada a la planta: "
              << maquina->getNombre() << '\n';
}

// Activa las maquinas respetando el orden de registro.
void Planta::encenderMaquinas() {
    for (Maquina* maquina : maquinas) {
        maquina->encender();
    }
}

// Detiene todos los equipos de la linea.
void Planta::apagarMaquinas() {
    for (Maquina* maquina : maquinas) {
        maquina->apagar();
    }
}

// Intenta que una pieza recorra todas las estaciones.
bool Planta::procesarPieza() {
    if (maquinas.empty()) {
        std::cout << "No hay maquinas registradas en la planta.\n";
        return false;
    }

    std::cout << "\nProcesando una nueva pieza...\n";

    for (Maquina* maquina : maquinas) {

        // No se puede continuar si la estacion esta apagada.
        if (!maquina->estaEncendida()) {
            std::cout << "La maquina " << maquina->getNombre()
                      << " esta apagada. Se detiene el recorrido.\n";
            return false;
        }

        // Si una operacion no puede realizarse por una falla,
        // se atiende la maquina y se vuelve a intentar la misma pieza.
        while (!maquina->procesarOperacion()) {

            if (!maquina->estaEnFalla()) {
                std::cout << "No fue posible procesar la pieza en "
                          << maquina->getNombre() << ".\n";
                return false;
            }

            std::cout << "La linea espera el mantenimiento de "
                      << maquina->getNombre() << ".\n";

            maquina->realizarMantenimiento();

            // Si la falla continua, no se repite indefinidamente.
            if (maquina->estaEnFalla()) {
                std::cout << "La falla no se pudo resolver.\n";
                return false;
            }
        }
    }

    // Solo cuenta la pieza cuando termino todas las operaciones.
    ++piezasTerminadas;

    std::cout << "La pieza completo todas las estaciones.\n";
    return true;
}

// Procesa el lote solicitado, en el orden de registro de las maquinas.
void Planta::procesarLote(int cantidad) {
    if (cantidad <= 0) {
        std::cout << "La cantidad de piezas debe ser positiva.\n";
        return;
    }

    if (maquinas.empty()) {
        std::cout << "No se puede procesar el lote sin maquinas.\n";
        return;
    }

    std::cout << "\n===== INICIO DEL LOTE =====\n";
    std::cout << "Piezas solicitadas: " << cantidad << '\n';

    for (int i = 0; i < cantidad; ++i) {
        std::cout << "\nPieza " << (i + 1)
                  << " de " << cantidad << '\n';

        // Si una estacion no puede continuar, se detiene el lote.
        if (!procesarPieza()) {
            std::cout << "El lote se detuvo antes de terminar.\n";
            break;
        }
    }

    std::cout << "\n===== FIN DEL LOTE =====\n";
}

// Resume la produccion y las estadisticas de cada equipo.
void Planta::mostrarReporte() const {
    int tiempoTotal = 0;
    int totalParos = 0;

    std::cout << "\n========== REPORTE DE PLANTA ==========\n";
    std::cout << "Piezas terminadas: " << piezasTerminadas << '\n';
    std::cout << "Cantidad de maquinas: " << maquinas.size() << '\n';

    for (Maquina* maquina : maquinas) {
        tiempoTotal += maquina->getTiempoTrabajado();
        totalParos += maquina->getParos();
    }

    std::cout << "Tiempo acumulado de trabajo: "
              << tiempoTotal << " segundos\n";
    std::cout << "Total de paros registrados: "
              << totalParos << '\n';

    std::cout << "\n--- Estado de las estaciones ---\n";

    for (Maquina* maquina : maquinas) {
        maquina->mostrarEstado();
    }

    std::cout << "\n=======================================\n";
}
