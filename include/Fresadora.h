
#ifndef FRESADORA_H
#define FRESADORA_H

#include "Maquina.h"
#include "HerramientaDeCorte.h"

#include <string>

// Representa una fresadora dentro de la linea de manufactura.
class Fresadora : public Maquina {
private:
    int tiempoPorPieza;

    // La herramienta forma parte de la fresadora.
    HerramientaDeCorte herramienta;

public:
    // Configura la maquina y su herramienta de corte.
    Fresadora(int id, const std::string& nombre,
              int tiempoPorPieza, int vidaUtilHerramienta);

    // Ejecuta el fresado de una pieza.
    bool fresar();

    // Consulta cuantas piezas puede procesar antes de desgastar la herramienta.
    int piezasRestantesHerramienta() const;

    // Operacion que la planta invoca de manera polimorfica.
    bool procesarOperacion() override;

    // Presenta las estadisticas y el estado de la herramienta.
    void mostrarEstado() const override;

    // Atiende la falla y recupera la herramienta.
    void realizarMantenimiento() override;
};

#endif