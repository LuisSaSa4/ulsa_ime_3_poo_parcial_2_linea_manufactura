
#ifndef PLANTA_H
#define PLANTA_H

#include "Maquina.h"

#include <vector>

// Coordina las estaciones y controla el avance de las piezas.
class Planta {
private:
    // Punteros a maquinas creadas fuera de la planta (agregacion).
    std::vector<Maquina*> maquinas;

    // Cantidad de piezas que terminaron todo el recorrido.
    int piezasTerminadas;

public:
    // La planta comienza sin maquinas registradas.
    Planta();

    // Incorpora una maquina al final de la linea de produccion.
    void agregarMaquina(Maquina* maquina);

    // Enciende todas las estaciones registradas.
    void encenderMaquinas();

    // Apaga los equipos al finalizar la jornada.
    void apagarMaquinas();

    // Procesa una pieza a traves de todas las estaciones.
    bool procesarPieza();

    // Repite el recorrido para la cantidad indicada de piezas.
    void procesarLote(int cantidad);

    // Presenta los resultados y el estado final de la linea.
    void mostrarReporte() const;
};

#endif
