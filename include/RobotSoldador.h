#ifndef ROBOT_SOLDADOR_H
#define ROBOT_SOLDADOR_H

#include "Maquina.h"
#include "Antorcha.h"


// Hereda los atributos y métodos generales de Maquina.
// Tiene una Antorcha como componente propio por composición.

class RobotSoldador : public Maquina {
private:
    // Tiempo necesario para soldar una pieza, en segundos.
    int tiempoPorPieza;

    // Componente que se desgasta con cada uso.
    Antorcha antorcha;

public:
    // Constructor que inicializa la máquina y su componente.
    RobotSoldador(int id, const std::string& nombre,
                  int tiempoPorPieza, int vidaUtilAntorcha);

    // Realiza el proceso de soldadura.
    // Devuelve true si la pieza fue procesada correctamente.
    bool soldar();

    // Muestra el estado general y la información de la antorcha.
    void mostrarEstado() const override;

    // Realiza el mantenimiento del robot y restaura la antorcha.
    void realizarMantenimiento() override;
};

#endif