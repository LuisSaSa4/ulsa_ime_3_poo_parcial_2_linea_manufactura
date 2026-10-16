
#ifndef MAQUINA_H
#define MAQUINA_H

#include <string>

// Clase base de todas las máquinas de la planta.
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
    // Registra una pieza procesada.
    void registrarPieza();

    // Acumula el tiempo de trabajo en segundos.
    void agregarTiempo(int segundos);

    // Registra una falla en la máquina.
    void reportarFalla();

    // Registra el mantenimiento y permite volver a operar.
    void registrarMantenimiento();

public:
    // Constructor de la clase Maquina.
    Maquina(int id, const std::string& nombre);

    // Permite destruir correctamente objetos de clases derivadas.
    virtual ~Maquina() = default;

    // Enciende la máquina.
    // Encenderla no elimina una falla existente.
    void encender();

    // Apaga la máquina.
    void apagar();

    // Consulta si la máquina está encendida.
    bool estaEncendida() const;

    // Consulta si la máquina está en falla.
    bool estaEnFalla() const;

    // Comprueba si la máquina puede procesar una pieza.
    bool puedeProcesar() const;

    // Devuelve el identificador de la máquina.
    int getId() const;

    // Devuelve el nombre de la máquina.
    std::string getNombre() const;

    // Devuelve la cantidad de piezas procesadas.
    int getPiezasProcesadas() const;

    // Devuelve el tiempo total trabajado en segundos.
    int getTiempoTrabajado() const;

    // Devuelve la cantidad de paros por mantenimiento.
    int getParos() const;

    // Muestra el estado general de la máquina.
    // Las clases derivadas pueden agregar información propia.
    virtual void mostrarEstado() const;

    // Cada máquina implementa su propia operación.
    virtual bool procesarOperacion() = 0;

    // Realiza el mantenimiento general de la máquina.
    // Las clases derivadas pueden restaurar su componente.
    virtual void realizarMantenimiento();
};

#endif

