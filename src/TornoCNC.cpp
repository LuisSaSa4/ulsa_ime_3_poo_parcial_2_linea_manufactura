#include "TornoCNC.h"
#include <iostream>

TornoCNC::TornoCNC(int id, const std::string& nombre, double vidaUtilHusillo, double velInicial)
    : Maquina(id, nombre), velocidadHusillo(velInicial), desgasteHusillo(0.0), husillo(vidaUtilHusillo) {}

void TornoCNC::ajustarVelocidad(double nuevaVelocidad) {
    if (nuevaVelocidad > 0) {
        velocidadHusillo = nuevaVelocidad;
    }
}

void TornoCNC::cilindrar() {
    std::cout << "El Torno CNC " << getNombre() << " está cilindrando la pieza a " << velocidadHusillo << " RPM.\n";
}

void TornoCNC::procesarPieza() {
    if (!puedeProcesar()) {
        std::cout << "El Torno CNC " << getNombre() << " no puede procesar (apagado o en falla).\n";
        return;
    }

    if (husillo.estaDesgastado()) {
        reportarFalla();
        std::cout << "¡Falla crítica! El husillo del Torno CNC ha llegado al límite de desgaste.\n";
        return;
    }

    // Ejecuta la operación propia
    cilindrar();

    // Actualiza tiempos y contadores de la base y del componente
    agregarTiempo(30); // 30 segundos por pieza (puedes ajustarlo)
    registrarPieza();
    
    husillo.usar(1.0);
    desgasteHusillo = husillo.getDesgaste();

    if (husillo.estaDesgastado()) {
        reportarFalla();
    }
}

void TornoCNC::realizarMantenimiento() {
    husillo.darMantenimiento();
    desgasteHusillo = husillo.getDesgaste();
    registrarMantenimiento(); // Método protegido de Maquina que quita la falla y suma un paro
}

void TornoCNC::mostrarEstado() const {
    Maquina::mostrarEstado();
    std::cout << "  [Torno CNC] Velocidad Husillo: " << velocidadHusillo 
              << " RPM | Desgaste: " << desgasteHusillo << "/" << husillo.getVidaUtil() << "\n";
}

double TornoCNC::getVelocidadHusillo() const {
    return velocidadHusillo;
}

double TornoCNC::getDesgasteHusillo() const {
    return desgasteHusillo;
}