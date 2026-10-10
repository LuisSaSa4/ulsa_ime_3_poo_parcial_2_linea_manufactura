
#include "Maquina.h"

#include <iostream>

using namespace std;

// Constructor que inicializa los datos de la máquina.
Maquina::Maquina(int id, const string& nombre)
    : id(id),
      nombre(nombre),
      encendida(false),
      enFalla(false),
      piezasProcesadas(0),
      tiempoTrabajado(0),
      paros(0) {
}

// Encender la máquina.
void Maquina::encender() {
    encendida = true;
}

// Apagar la máquina.
void Maquina::apagar() {
    encendida = false;
}

// Consultar si está encendida.
bool Maquina::estaEncendida() const {
    return encendida;
}

// Consultar si está en falla.
bool Maquina::estaEnFalla() const {
    return enFalla;
}

// Verificar si puede procesar piezas.
bool Maquina::puedeProcesar() const {
    return encendida && !enFalla;
}

// Obtener el identificador.
int Maquina::getId() const {
    return id;
}

// Obtener el nombre.
string Maquina::getNombre() const {
    return nombre;
}

// Obtener las piezas procesadas.
int Maquina::getPiezasProcesadas() const {
    return piezasProcesadas;
}

// Obtener el tiempo trabajado.
int Maquina::getTiempoTrabajado() const {
    return tiempoTrabajado;
}

// Obtener la cantidad de paros.
int Maquina::getParos() const {
    return paros;
}

// Registrar una pieza procesada.
void Maquina::registrarPieza() {
    ++piezasProcesadas;
}

// Agregar tiempo de trabajo.
void Maquina::agregarTiempo(int segundos) {
    if (segundos > 0) {
        tiempoTrabajado += segundos;
    }
}

// Registrar que ocurrió una falla.
void Maquina::reportarFalla() {
    enFalla = true;
}

// Registrar el mantenimiento realizado.
void Maquina::registrarMantenimiento() {
    enFalla = false;
    ++paros;
}

// Realizar el mantenimiento general de la máquina.
void Maquina::realizarMantenimiento() {
    cout << "\nIniciando mantenimiento de "
         << nombre << "..." << endl;

    registrarMantenimiento();

    cout << "Mantenimiento general completado." << endl;
    cout << "La falla ha sido resuelta." << endl;
}

// Mostrar la información general de la máquina.
void Maquina::mostrarEstado() const {
    cout << "\n========== ESTADO DE LA MAQUINA =========="
         << endl;

    cout << "ID: " << id << endl;
    cout << "Nombre: " << nombre << endl;

    cout << "Estado: ";

    if (!encendida) {
        cout << "Apagada";
    } else if (enFalla) {
        cout << "En falla";
    } else {
        cout << "Encendida y disponible";
    }

    cout << endl;

    cout << "Piezas procesadas: "
         << piezasProcesadas << endl;

    cout << "Tiempo trabajado: "
         << tiempoTrabajado << " segundos" << endl;

    cout << "Paros por mantenimiento: "
         << paros << endl;

    cout << "========================================="
         << endl;
}
