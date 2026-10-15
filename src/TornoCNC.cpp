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
    std::cout << "El Torno CNC " << getNombre() << " está cilindrando a " << velocidadHusillo << " RPM.\n";
}

void TornoCNC::procesarPieza() {
    if (!puedeProcesar()) {
        std::cout << "El Torno CNC " << getNombre() << " no puede procesar (apagado o en falla).\n";
        return;
    }

    if (husillo.estaDesgastado()) {
        reportarFalla();
        std::cout << "¡Falla en el Torno CNC " << getNombre() << "! El husillo llegó al límite.\n";
        return;
    }

    // Ejecuta la operación de cilindrar
    cilindrar();

    // Actualiza los contadores de la clase base y del componente
    agregarTiempo(30); // 30 segundos por pieza (puedes ajustarlo)
    registrarPieza();
    
    husillo.usar(1.0);
    desgasteHusillo = husillo.getDesgaste();

    // Si con esta pieza se acabó el husillo, reporta la falla de inmediato
    if (husillo.estaDesgastado()) {
        reportarFalla();
    }
}

void TornoCNC::realizarMantenimiento() {
    // Restaura el componente interno
    husillo.darMantenimiento();
    desgasteHusillo = husillo.getDesgaste();

    // Llama al método protegido de la base para quitar la falla de la máquina y sumar un paro
    Maquina::registrarMantenimiento();
    
    std::cout << "Mantenimiento realizado en el Torno CNC " << getNombre() << ". Husillo restaurado.\n";
}

void TornoCNC::mostrarEstado() const {
    Maquina::mostrarEstado(); // Muestra los datos de la base
    std::cout << "  -> Velocidad Husillo: " << velocidadHusillo 
              << " RPM | Desgaste Husillo: " << desgasteHusillo << "/" << husillo.getVidaUtil() << "\n";
}

double TornoCNC::getVelocidadHusillo() const {
    return velocidadHusillo;
}

double TornoCNC::getDesgasteHusillo() const {
    return desgasteHusillo;
}