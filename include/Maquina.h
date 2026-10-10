
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
    bool encendida;
    bool enFalla;
    int piezasProcesadas;
    int tiempoTrabajado;
    int paros;

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

    // Destructor virtual para permitir la destrucción correcta
    // de objetos de clases derivadas.
    virtual ~Maquina() = default;

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
    // Es virtual para permitir que las clases derivadas
    // muestren también la información de sus propios atributos.
    virtual void mostrarEstado() const;

    // Realiza el mantenimiento general de la máquina.
    // Las clases derivadas pueden redefinir este método
    // para restaurar primero sus propios componentes.
    virtual void realizarMantenimiento();
};

#endif
