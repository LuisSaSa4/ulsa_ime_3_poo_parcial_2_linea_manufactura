#include "CortadoraLaser.h"

#include <iostream>
#include <stdexcept>

// Construye la cortadora y configura su componente de corte.
CortadoraLaser::CortadoraLaser(
    int id,
    const std::string& nombre,
    int tiempoPorPieza,
    int vidaUtilTubo
)
    : Maquina(id, nombre),
      tiempoPorPieza(tiempoPorPieza),
      tubo(vidaUtilTubo) {

    // Un tiempo de corte invalido impediria calcular la produccion.
    if (tiempoPorPieza <= 0) {
        throw std::invalid_argument(
            "El tiempo por pieza debe ser mayor que cero."
        );
    }
}

// Corta una pieza si el equipo se encuentra disponible.
bool CortadoraLaser::cortar() {

    if (!puedeProcesar()) {
        std::cout << "La cortadora laser " << getNombre()
                  << " no esta disponible.\n";
        return false;
    }

    // Antes de iniciar, verifica la condicion del tubo.
    if (tubo.estaDesgastado()) {
        reportarFalla();
        return false;
    }

    std::cout << "Cortadora laser " << getNombre()
              << " cortando una pieza...\n";

    // Actualiza los registros heredados de Maquina.
    registrarPieza();
    agregarTiempo(tiempoPorPieza);

    // El proceso de corte incrementa el desgaste del tubo.
    tubo.registrarUso();

    std::cout << "Corte terminado correctamente.\n";

    // Si se agoto la vida util, se detendra para mantenimiento.
    if (tubo.estaDesgastado()) {
        reportarFalla();
    }

    // El corte de esta pieza se completo antes de detectar la falla.
    return true;
}

// Implementa la interfaz comun para procesar piezas.
bool CortadoraLaser::procesarOperacion() {
    return cortar();
}

// Muestra la informacion heredada y los datos particulares.
void CortadoraLaser::mostrarEstado() const {
    Maquina::mostrarEstado();

    std::cout << "--- Datos de la Cortadora Laser ---\n";
    std::cout << "Tiempo por pieza: "
              << tiempoPorPieza << " segundos\n";
    std::cout << "Vida util del tubo: "
              << tubo.getVidaUtil() << '\n';
    std::cout << "Desgaste del tubo: "
              << tubo.getDesgaste() << '\n';
}

// Deja el equipo listo para continuar con el siguiente ciclo.
void CortadoraLaser::realizarMantenimiento() {

    if (!estaEnFalla()) {
        std::cout << "La cortadora laser " << getNombre()
                  << " no necesita mantenimiento.\n";
        return;
    }

    std::cout << "Revisando la cortadora laser "
              << getNombre() << "...\n";

    // Se restaura el tubo antes de liberar el estado de falla.
    tubo.restaurar();

    Maquina::realizarMantenimiento();

    std::cout << "Tubo laser restaurado. Desgaste: "
              << tubo.getDesgaste() << '\n';
}
