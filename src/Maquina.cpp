#include "Maquina.h"

#include <iostream>

// Constructor de la clase Maquina.
Maquina::Maquina(int id, const std::string& nombre)
    : id(id),
      nombre(nombre),
      encendida(false),
      enFalla(false),
      piezasProcesadas(0),
      tiempoTrabajado(0),
      paros(0) {
}

// Enciende la máquina.
// Encenderla no elimina una falla existente.
void Maquina::encender() {
    encendida = true;

    std::cout << "Maquina " << nombre << " encendida.\n";
}

// Apaga la máquina.
void Maquina::apagar() {
    encendida = false;

    std::cout << "Maquina " << nombre << " apagada.\n";
}

// Consulta si la máquina está encendida.
bool Maquina::estaEncendida() const {
    return encendida;
}

// Consulta si la máquina está en falla.
bool Maquina::estaEnFalla() const {
    return enFalla;
}

// Comprueba si la máquina puede procesar una pieza.
bool Maquina::puedeProcesar() const {
    return encendida && !enFalla;
}

// Devuelve el identificador de la máquina.
int Maquina::getId() const {
    return id;
}

// Devuelve el nombre de la máquina.
std::string Maquina::getNombre() const {
    return nombre;
}

// Devuelve la cantidad de piezas procesadas.
int Maquina::getPiezasProcesadas() const {
    return piezasProcesadas;
}

// Devuelve el tiempo total trabajado en segundos.
int Maquina::getTiempoTrabajado() const {
    return tiempoTrabajado;
}

// Devuelve la cantidad de paros por mantenimiento.
int Maquina::getParos() const {
    return paros;
}

// Registra una pieza procesada.
void Maquina::registrarPieza() {
    ++piezasProcesadas;
}

// Acumula el tiempo de trabajo en segundos.
void Maquina::agregarTiempo(int segundos) {
    if (segundos > 0) {
        tiempoTrabajado += segundos;
    }
}

// Registra una falla en la máquina.
void Maquina::reportarFalla() {
    if (!enFalla) {
        enFalla = true;

        std::cout << "FALLA: La maquina " << nombre
                  << " ha dejado de operar.\n";
    }
}

// Registra el mantenimiento y permite volver a operar.
void Maquina::registrarMantenimiento() {
    if (enFalla) {
        ++paros;
        enFalla = false;

        std::cout << "Mantenimiento terminado en la maquina "
                  << nombre << ".\n";
    }
}

// Realiza el mantenimiento general de la máquina.
void Maquina::realizarMantenimiento() {
    if (enFalla) {
        registrarMantenimiento();
    } else {
        std::cout << "La maquina " << nombre
                  << " no necesita mantenimiento.\n";
    }
}

// Muestra el estado general de la máquina.
void Maquina::mostrarEstado() const {
    std::cout << "\n--- Estado de la maquina ---\n";
    std::cout << "ID: " << id << '\n';
    std::cout << "Nombre: " << nombre << '\n';
    std::cout << "Encendida: "
              << (encendida ? "Si" : "No") << '\n';
    std::cout << "En falla: "
              << (enFalla ? "Si" : "No") << '\n';
    std::cout << "Piezas procesadas: "
              << piezasProcesadas << '\n';
    std::cout << "Tiempo trabajado: "
              << tiempoTrabajado << " segundos\n";
    std::cout << "Paros por mantenimiento: "
              << paros << '\n';
}
