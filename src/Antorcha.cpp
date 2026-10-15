
#include "Antorcha.h"

#include <stdexcept>

// Inicializa la vida util y el desgaste de la antorcha.
Antorcha::Antorcha(int vidaInicial)
    : vidaUtil(vidaInicial), desgaste(0.0) {

    // La vida util debe ser mayor que cero.
    if (vidaInicial <= 0) {
        throw std::invalid_argument(
            "La vida util de la antorcha debe ser positiva."
        );
    }
}

// Cada pieza soldada aumenta el desgaste en una unidad.
void Antorcha::registrarUso() {
    if (!estaDesgastado()) {
        desgaste += 1.0;
    }
}

// Devuelve true cuando se alcanza el limite de uso.
bool Antorcha::estaDesgastado() const {
    return desgaste >= vidaUtil;
}

// El mantenimiento devuelve el desgaste a cero.
void Antorcha::restaurar() {
    desgaste = 0.0;
}

// Devuelve la vida util configurada.
int Antorcha::getVidaUtil() const {
    return vidaUtil;
}

// Devuelve el desgaste actual.
double Antorcha::getDesgaste() const {
    return desgaste;
}