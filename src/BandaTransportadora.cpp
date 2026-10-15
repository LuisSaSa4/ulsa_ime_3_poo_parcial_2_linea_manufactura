#include "BandaTransportadora.h"
#include <iostream>
#include <stdexcept> // ***manejo de errores

BandaTransportadora::BandaTransportadora(
        int id,
        const std::string& nombre,
        int tiempoPorPieza,
        int vidaUtil)
: Maquina(id, nombre),
      motor(vidaUtil),
      tiempoPorPieza(tiempoPorPieza),
      piezasTransportadas(0) {
    if (tiempoPorPieza <= 0)
        throw std::invalid_argument("tiempoPorPieza debe ser > 0");
}

void BandaTransportadora::procesarPieza() {
    if (!puedeProcesar()) {
        std::cout << "  [" << getNombre()
                  << "] no puede procesar (apagada o en falla).\n";
        return;
    }

    agregarTiempo(tiempoPorPieza);
    registrarPieza();
    piezasTransportadas++;

    motor.usar();

    if (motor.estaDesgastado()) {
        reportarFalla();
        std::cout << "  [" << getNombre()
                  << "] FALLA: motor agotado.\n";
    }
}

bool BandaTransportadora::procesarOperacion() {
    const int piezasAntes = getPiezasProcesadas();
    procesarPieza();
    return getPiezasProcesadas() > piezasAntes;
}

void BandaTransportadora::realizarMantenimiento() {
    motor.restaurar();
    Maquina::realizarMantenimiento();   // quita falla + suma paro + imprime
}

void BandaTransportadora::mostrarEstado() const {
    Maquina::mostrarEstado();
    std::cout << "  Tipo: BandaTransportadora"
              << " | tiempo/pieza: " << tiempoPorPieza << " s"
              << " | piezas: " << piezasTransportadas << "\n";
    motor.mostrarEstado();
}

int BandaTransportadora::getPiezasTransportadas() const {
    return piezasTransportadas;
}

int BandaTransportadora::getTiempoPorPieza() const {
    return tiempoPorPieza;
}

int BandaTransportadora::getVidaMotor() const {
    return motor.getVidaUtil();
}

