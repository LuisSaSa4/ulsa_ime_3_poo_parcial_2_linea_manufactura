// Fresadora.cpp
 
#include "Fresadora.h"
#include <iostream>
 
// Constructor. Despues de los ":" se inicializan la clase base
// (Maquina) y la herramienta. Los demas atributos se validan dentro.
Fresadora::Fresadora(int id, const std::string& nombre,
                     int tiempoPorPieza, int vidaHerramienta,
                     double profundidadMm, int rpm)
    : Maquina(id, nombre), herramienta_(vidaHerramienta) {
 
    // Validacion del tiempo por pieza
    if (tiempoPorPieza > 0) {
        tiempoPorPieza_ = tiempoPorPieza;
    } else {
        tiempoPorPieza_ = 45;
    }
 
    // Validacion de la profundidad
    if (profundidadMm >= 0.5 && profundidadMm <= 20.0) {
        profundidadRanura_ = profundidadMm;
    } else {
        profundidadRanura_ = 5.0;
    }
 
    // Validacion de las rpm
    if (rpm >= 500 && rpm <= 12000) {
        velocidadRpm_ = rpm;
    } else {
        velocidadRpm_ = 3000;
    }
}
 
// Procesa una pieza: hace la ranura, gasta la herramienta y avisa a la base
void Fresadora::ranurar() {
    // Si esta apagada o en falla, rechaza la operacion
    if (puedeProcesar() == false) {
        std::cout << "[" << getNombre() << "] Operacion rechazada: apagada o en falla.\n";
        return;
    }
 
    herramienta_.usar();               // La herramienta se desgasta
    registrarPieza();                  // La base cuenta la pieza
    agregarTiempo(tiempoPorPieza_);    // La base suma el tiempo
 
    // Si esta pieza agoto la herramienta, la maquina entra en falla
    if (herramientaDesgastada()) {
        reportarFalla();
        std::cout << "[" << getNombre() << "] Herramienta desgastada: FALLA.\n";
    }
}
 
// Cuantas piezas mas aguanta la herramienta
int Fresadora::piezasRestantesHerramienta() const {
    int vida = herramienta_.getVidaUtil();
    int usadas = (int)herramienta_.getDesgaste();
    int restantes = vida - usadas;
    if (restantes < 0) {
        restantes = 0;
    }
    return restantes;
}
 
bool Fresadora::herramientaDesgastada() const {
    return herramienta_.estaDesgastada();
}
 
// Muestra el estado: primero lo de la base, luego lo propio
void Fresadora::mostrarEstado() const {
    Maquina::mostrarEstado();  // Reutiliza la version de la clase base
 
    std::cout << "  Tiempo por pieza: " << tiempoPorPieza_ << " s\n";
    std::cout << "  Ranura: " << profundidadRanura_ << " mm a "
              << velocidadRpm_ << " rpm\n";
    std::cout << "  Herramienta de corte: desgaste "
              << herramienta_.getDesgaste() << " / "
              << herramienta_.getVidaUtil()
              << " (quedan " << piezasRestantesHerramienta() << " piezas)";
    if (herramientaDesgastada()) {
        std::cout << " DESGASTADA";
    }
    std::cout << "\n";
}
 
// Mantenimiento: herramienta nueva y quita la falla
void Fresadora::realizarMantenimiento() {
    herramienta_.restaurar();
    registrarMantenimiento();  // La base quita la falla y cuenta el paro
    std::cout << "[" << getNombre() << "] Mantenimiento: herramienta cambiada.\n";
}