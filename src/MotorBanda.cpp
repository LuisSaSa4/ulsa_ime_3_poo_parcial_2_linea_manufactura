
#include "MotorBanda.h"

#include <stdexcept>

// Inicialmente, el motor tiene toda su vida util disponible.
MotorBanda::MotorBanda(int vidaInicial)
    : vidaUtil(vidaInicial), desgaste(0.0) {

    // Se necesita una vida util valida para crear el componente.
    if (vidaInicial <= 0) {
        throw std::invalid_argument(
            "La vida util del motor debe ser mayor que cero."
        );
    }
}

// Aumenta el desgaste al transportar una pieza.
void MotorBanda::registrarUso() {
    if (!estaDesgastado()) {
        desgaste += 1.0;
    }
}

// Señala cuando el motor ya no debe seguir trabajando.
bool MotorBanda::estaDesgastado() const {
    return desgaste >= vidaUtil;
}

// Deja el contador de desgaste listo para otro ciclo.
void MotorBanda::restaurar() {
    desgaste = 0.0;
}

// Consulta la vida util configurada.
int MotorBanda::getVidaUtil() const {
    return vidaUtil;
}

// Consulta el desgaste acumulado.
double MotorBanda::getDesgaste() const {
    return desgaste;
}
