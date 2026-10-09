#include "EstacionInspeccion.h"
#include <iostream>

EstacionInspeccion::EstacionInspeccion(int id, const std::string& nombre,
                                       int segundosPorPieza, double toleranciaMm,
                                       int calibracionSensor)
    : Maquina(id, nombre),
      segundosPorPieza(10),
      toleranciaMm(0.05),
      sensor(calibracionSensor) {
    if (segundosPorPieza > 0) {
        this->segundosPorPieza = segundosPorPieza;
    } else {
        std::cout << getNombre() << ": segundos por pieza invalidos, se usa 10.\n";
    }
    if (toleranciaMm > 0.0) {
        this->toleranciaMm = toleranciaMm;
    } else {
        std::cout << getNombre() << ": tolerancia invalida, se usa 0.05 mm.\n";
    }
}

bool EstacionInspeccion::procesarPieza() {
    if (!puedeProcesar()) {
        std::cout << getNombre() << ": operacion rechazada ("
                  << (estaEnFalla() ? "esta en falla" : "esta apagada") << ").\n";
        return false;
    }

    sensor.medir();                 // el sensor se desgasta
    registrarPieza();               // avisa a la base
    agregarTiempo(segundosPorPieza);
    std::cout << getNombre() << ": pieza medida (tolerancia +/- "
              << toleranciaMm << " mm).\n";

    if (sensor.estaAgotado()) {     // falla en la pieza que agota el sensor
        reportarFalla();
        std::cout << getNombre() << ": FALLA, sensor descalibrado.\n";
    }
    return true;
}

void EstacionInspeccion::realizarMantenimiento() {
    if (!estaEnFalla()) {
        std::cout << getNombre() << ": no requiere mantenimiento.\n";
        return;
    }
    sensor.recalibrar();
    registrarMantenimiento();       // quita la falla y suma un paro
    std::cout << getNombre() << ": sensor recalibrado, mantenimiento registrado.\n";
}

int EstacionInspeccion::getSegundosPorPieza() const { return segundosPorPieza; }
double EstacionInspeccion::getToleranciaMm() const { return toleranciaMm; }
const Sensor& EstacionInspeccion::getSensor() const { return sensor; }

void EstacionInspeccion::mostrarEstado() const {
    Maquina::mostrarEstado();       // reutiliza la version base
    std::cout << "  Segundos por pieza: " << segundosPorPieza
              << " | Tolerancia: " << toleranciaMm << " mm\n";
    sensor.mostrarEstado();
}