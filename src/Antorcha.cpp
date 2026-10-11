#include "Antorcha.h"

#include <stdexcept>//Biblioteca estandar de c++ que tiene herramientas para manejar errores y lanzar excepsiones

// Constructor que inicializa la vida útil y el desgaste de la antorcha.
Antorcha::Antorcha(int vidaInicial)
    : vidaUtil(vidaInicial),
      desgaste(0) { 

    // Validar que la vida útil sea mayor que cero.
    if (vidaInicial <= 0) { 
        throw std::invalid_argument( //Rechaza una vida util iual o menor a cero
            "La vida util de la antorcha debe ser mayor que cero."
        );
    }
}

// Registrar el uso de la antorcha.
void Antorcha::registrarUso() {
    // Aumentar el desgaste solo si no se ha alcanzado el límite.
    if (!estaDesgastado()) {
        ++desgaste;
    }
}

// Verificar si la antorcha alcanzó su límite de desgaste.
bool Antorcha::estaDesgastado() const {
    return desgaste >= vidaUtil;
}

// Restaurar la antorcha después del mantenimiento.
void Antorcha::restaurar() {
    desgaste = 0;
}

// Obtener la vida útil máxima de la antorcha.
int Antorcha::getVidaUtil() const {
    return vidaUtil;
}

// Obtener el desgaste acumulado.
int Antorcha::getDesgaste() const {
    return desgaste;
}