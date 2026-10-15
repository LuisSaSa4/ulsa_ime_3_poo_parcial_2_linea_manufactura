<<<<<<< HEAD
#include "Sensorinspeccion.h"
#include <iostream>
=======
#include "SensorInspeccion.h"
>>>>>>> 3613b4f81592a6c98bcfda0dcfb094dcae1d3935

#include <stdexcept>

// Inicializa el sensor sin desgaste acumulado.
SensorInspeccion::SensorInspeccion(int vidaInicial)
    : vidaUtil(vidaInicial), desgaste(0.0) {

    if (vidaInicial <= 0) {
        throw std::invalid_argument(
            "La vida util del sensor debe ser mayor que cero."
        );
    }
}

// Registra una inspeccion realizada.
void SensorInspeccion::registrarUso() {
    if (!estaDesgastado()) {
        desgaste += 1.0;
    }
}

// Comprueba si el sensor llego a su limite.
bool SensorInspeccion::estaDesgastado() const {
    return desgaste >= vidaUtil;
}

// Restablece el desgaste despues del mantenimiento.
void SensorInspeccion::restaurar() {
    desgaste = 0.0;
}

// Consulta la vida util configurada.
int SensorInspeccion::getVidaUtil() const {
    return vidaUtil;
}

// Consulta el desgaste acumulado.
double SensorInspeccion::getDesgaste() const {
    return desgaste;
}