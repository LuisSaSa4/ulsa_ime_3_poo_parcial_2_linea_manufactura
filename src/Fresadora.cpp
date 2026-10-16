
#include "Fresadora.h"
#include <iostream>
#include <stdexcept>


// Inicializa la parte heredada y los datos propios de la fresadora.
Fresadora::Fresadora(
    int id,
    const std::string& nombre,
    int tiempoPorPieza,
    int vidaUtilHerramienta
)
    : Maquina(id, nombre),
      tiempoPorPieza(tiempoPorPieza),
      herramienta(vidaUtilHerramienta) {

    // No se permite un tiempo de fresado nulo o negativo.
    if (tiempoPorPieza <= 0) {
        throw std::invalid_argument(
            "El tiempo por pieza debe ser mayor que cero."
        );
    }
}

// Lleva a cabo la operacion de fresado.
bool Fresadora::fresar() {

    // Primero se revisan las condiciones generales de la maquina.
    if (!puedeProcesar()) {
        std::cout << "La fresadora " << getNombre()
                  << " no esta disponible para trabajar.\n";
        return false;
    }

    // Si la herramienta ya alcanzo su limite, se detiene el proceso.
    if (herramienta.estaDesgastado()) {
        reportarFalla();
        return false;
    }

    std::cout << "Fresadora " << getNombre()
              << " trabajando sobre una pieza...\n";

    // Actualiza los datos de produccion de la clase base.
    registrarPieza();
    agregarTiempo(tiempoPorPieza);

    // El corte provoca desgaste en la herramienta.
    herramienta.registrarUso();

    std::cout << "Pieza fresada correctamente.\n";

    // La falla se registra al alcanzar la vida util configurada.
    if (herramienta.estaDesgastado()) {
        reportarFalla();
    }

    // El fresado de esta pieza termino, aunque la herramienta
    // pueda necesitar mantenimiento antes de la siguiente.
    return true;
}

// Consulta la vida util restante de la herramienta en piezas.
int Fresadora::piezasRestantesHerramienta() const {
    if (herramienta.estaDesgastado()) {
        return 0;
    }

    return herramienta.getVidaUtil()
        - static_cast<int>(herramienta.getDesgaste());
}

// Permite que Planta solicite la operacion sin conocer los detalles.
bool Fresadora::procesarOperacion() {
    return fresar();
}

// Combina la informacion comun con los datos de fresado.
void Fresadora::mostrarEstado() const {
    Maquina::mostrarEstado();

    std::cout << "--- Informacion de la Fresadora ---\n";
    std::cout << "Tiempo por pieza: "
              << tiempoPorPieza << " segundos\n";
    std::cout << "Vida util de la herramienta: "
              << herramienta.getVidaUtil() << '\n';
    std::cout << "Desgaste acumulado: "
              << herramienta.getDesgaste() << '\n';
}

// Restablece el componente y actualiza el estado de la maquina.
void Fresadora::realizarMantenimiento() {

    if (!estaEnFalla()) {
        std::cout << "La fresadora " << getNombre()
                  << " no requiere mantenimiento.\n";
        return;
    }

    std::cout << "Iniciando mantenimiento de la fresadora "
              << getNombre() << "...\n";

    // Se recupera la herramienta antes de liberar la falla.
    herramienta.restaurar();

    Maquina::realizarMantenimiento();

    std::cout << "Herramienta recuperada. Desgaste: "
              << herramienta.getDesgaste() << '\n';
}