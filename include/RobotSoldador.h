
#ifndef ROBOTSOLDADOR_H
#define ROBOTSOLDADOR_H

#include "Maquina.h"
#include "Antorcha.h"

#include <string>

// Maquina encargada de realizar operaciones de soldadura.
// Hereda las caracteristicas generales de Maquina.
class RobotSoldador : public Maquina {
private:
    int tiempoPorPieza;

    // Composicion: el robot contiene su propia antorcha.
    Antorcha antorcha;

public:
    // Constructor del robot soldador.
    RobotSoldador(int id, const std::string& nombre,
                 int tiempoPorPieza, int vidaUtilAntorcha);

    // Operacion especifica del robot.
    bool soldar();

    // Implementa la operacion requerida por Maquina.
    bool procesarOperacion() override;

    // Muestra el estado general y los datos del robot.
    void mostrarEstado() const override;

    // Restaura la antorcha y registra el mantenimiento.
    void realizarMantenimiento() override;
};

#endif