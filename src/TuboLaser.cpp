
#include "TuboLaser.h"

#include <stdexcept>

// El tubo comienza nuevo, sin desgaste acumulado.
TuboLaser::TuboLaser(int vidaInicial)
    : vidaUtil(vidaInicial), desgaste(0.0) {

    if (vidaInicial <= 0) {
        throw std::invalid_argument(
            "La vida util del tubo laser debe ser mayor que cero."
        );
    }
}

// Cada corte consume una unidad de vida util.
void TuboLaser::registrarUso() {
    if (!estaDesgastado()) {
        desgaste += 1.0;
    }
}

// Indica cuando el tubo necesita mantenimiento.
bool TuboLaser::estaDesgastado() const {
    return desgaste >= vidaUtil;
}

// Reinicia el desgaste despues de atender la falla.
void TuboLaser::restaurar() {
    desgaste = 0.0;
}

// Devuelve el limite de uso configurado.
int TuboLaser::getVidaUtil() const {
    return vidaUtil;
}

// Permite conocer el desgaste registrado.
double TuboLaser::getDesgaste() const {
    return desgaste;
}
