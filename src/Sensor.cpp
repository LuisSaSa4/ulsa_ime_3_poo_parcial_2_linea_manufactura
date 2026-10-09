#include "Sensor.h"
#include <iostream>

Sensor::Sensor(int calibracionMaxima)
    : calibracionMaxima(30), calibracionActual(30), recalibraciones(0) {
    if (calibracionMaxima > 0) {
        this->calibracionMaxima = calibracionMaxima;
        calibracionActual = calibracionMaxima;
    } else {
        std::cout << "Sensor: calibracion invalida (" << calibracionMaxima
                  << "), se usa 30.\n";
    }
}

bool Sensor::medir() {
    if (estaAgotado()) {
        return false;
    }
    calibracionActual--;
    return true;
}

void Sensor::recalibrar() {
    calibracionActual = calibracionMaxima;
    recalibraciones++;
}

bool Sensor::estaAgotado() const { return calibracionActual <= 0; }
int Sensor::getCalibracionActual() const { return calibracionActual; }
int Sensor::getCalibracionMaxima() const { return calibracionMaxima; }
int Sensor::getRecalibraciones() const { return recalibraciones; }

double Sensor::getPorcentajeCalibracion() const {
    return 100.0 * calibracionActual / calibracionMaxima;
}

void Sensor::mostrarEstado() const {
    std::cout << "  Sensor: calibracion " << calibracionActual << "/" << calibracionMaxima
              << " (" << getPorcentajeCalibracion() << "%), recalibraciones: "
              << recalibraciones << (estaAgotado() ? " [DESCALIBRADO]" : "") << "\n";
}