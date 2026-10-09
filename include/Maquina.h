#ifndef MAQUINA_H
#define MAQUINA_H

#include <string>

// Clase base de todas las máquinas de la línea de manufactura.
//
// Este archivo es la INTERFAZ: declara los atributos y métodos
// generales de cualquier máquina.
//
// La implementación se encuentra en src/Maquina.cpp.

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
    // Suma una pieza procesada.
    void registrarPieza();

    // Acumula tiempo trabajado.
    // Los valores negativos o cero no se aceptan.
    void agregarTiempo(int segundos);

    // Pone la máquina en falla.
    void reportarFalla();

    // Quita la falla y suma un paro.
    void registrarMantenimiento();

public:
    // Constructor.
    Maquina(int id, const std::string& nombre);

    // Enciende la máquina. No elimina una falla.
    void encender();

    // Apaga la máquina.
    void apagar();

    // Consultas del estado de la máquina.
    bool estaEncendida() const;
    bool estaEnFalla() const;
    bool puedeProcesar() const;

    // Obtener información de la máquina.
    int getId() const;
    std::string getNombre() const;
    int getPiezasProcesadas() const;
    int getTiempoTrabajado() const;
    int getParos() const;

    // Muestra los datos generales de la máquina.
    void mostrarEstado() const;

    // Realiza el mantenimiento general de la máquina.
    void realizarMantenimiento();
};

#endif