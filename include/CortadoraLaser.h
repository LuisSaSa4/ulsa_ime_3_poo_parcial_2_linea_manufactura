
#ifndef CORTADORALASER_H
#define CORTADORALASER_H

#include "Maquina.h"
#include "TuboLaser.h"

#include <string>

// Equipo encargado de cortar piezas mediante un laser.
class CortadoraLaser : public Maquina {
private:
    int tiempoPorPieza;

    // El tubo laser es un componente interno de la cortadora.
    TuboLaser tubo;

public:
    // Inicializa la cortadora con su tiempo de corte y tubo.
    CortadoraLaser(int id, const std::string& nombre,
                   int tiempoPorPieza, int vidaUtilTubo);

    // Ejecuta el corte de una pieza.
    bool cortar();

    // Permite que Planta solicite el trabajo de esta maquina.
    bool procesarOperacion() override;

    // Presenta las estadisticas generales y el estado del tubo.
    void mostrarEstado() const override;

    // Atiende la falla y recupera el componente.
    void realizarMantenimiento() override; 
};

#endif
