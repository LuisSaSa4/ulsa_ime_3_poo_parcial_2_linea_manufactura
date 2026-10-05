#ifndef MAQUINA_H
#define MAQUINA_H

#include <string>

// Clase base de todas las máquinas de la línea de manufactura.
//
// Este archivo es solo la INTERFAZ: declara qué sabe y qué hace cualquier
// máquina. La implementación la escribe el equipo en src/Maquina.cpp.
//
// No modifiquen este archivo sin acuerdo del equipo. Si lo cambian,
// documenten el cambio en el README.md.
class Maquina {
private:
    int id;
    std::string nombre;
    bool encendida;        // true si la máquina está encendida
    bool enFalla;          // true si la máquina está en falla
    int piezasProcesadas;  // piezas procesadas en el turno
    int tiempoTrabajado;   // segundos trabajados en el turno
    int paros;             // mantenimientos realizados en el turno

protected:
    // Los métodos protegidos son para las clases derivadas: con ellos le
    // avisan a la base lo que ocurrió durante su operación.

    // Suma una pieza procesada.
    void registrarPieza();

    // Acumula tiempo trabajado. Cada máquina derivada lo llama con su
    // propio tiempo por pieza. Los valores negativos no se aceptan.
    void agregarTiempo(int segundos);

    // Pone la máquina en falla.
    void reportarFalla();

    // Quita la falla y suma un paro.
    void registrarMantenimiento();

public:
    // Crea una máquina apagada, sin falla y con sus contadores en cero.
    Maquina(int id, const std::string& nombre);

    // Enciende la máquina. Encender no quita una falla.
    void encender();

    // Apaga la máquina.
    void apagar();

    bool estaEncendida() const;
    bool estaEnFalla() const;

    // true solo si la máquina está encendida y sin falla.
    bool puedeProcesar() const;

    int getId() const;
    std::string getNombre() const;
    int getPiezasProcesadas() const;
    int getTiempoTrabajado() const;
    int getParos() const;

    // Muestra en pantalla los datos generales de la máquina.
    void mostrarEstado() const;
};

#endif
