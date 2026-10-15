
#include "HerramientaDeCorte.h"
#include <stdexcept>


// Al crear la herramienta, su desgaste comienza en cero.
HerramientaDeCorte::HerramientaDeCorte(int vidaInicial)
    : vidaUtil(vidaInicial), desgaste(0.0) {

    // Evita configurar una herramienta sin vida util valida.
    if (vidaInicial <= 0) {
        throw std::invalid_argument(
            "La vida util de la herramienta debe ser mayor que cero."
        );
    }
}

// Cada uso representa el trabajo realizado sobre una pieza.
void HerramientaDeCorte::registrarUso() {
    if (!estaDesgastado()) {
        desgaste += 1.0;
    }
}

// La herramienta necesita mantenimiento al alcanzar su limite.
bool HerramientaDeCorte::estaDesgastado() const {
    return desgaste >= vidaUtil;
}

// Reinicia el desgaste despues del mantenimiento.
void HerramientaDeCorte::restaurar() {
    desgaste = 0.0;
}

// Informa la duracion configurada para la herramienta.
int HerramientaDeCorte::getVidaUtil() const {
    return vidaUtil;
}

// Permite consultar cuanto se ha utilizado.
double HerramientaDeCorte::getDesgaste() const {
    return desgaste;
}