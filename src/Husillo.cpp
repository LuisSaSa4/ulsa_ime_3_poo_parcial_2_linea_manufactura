#include "Husillo.h"

Husillo::Husillo(double vidaUtilInicial) : vidaUtil(vidaUtilInicial), desgaste(0.0) {}

void Husillo::usar(double cantidad) {
    desgaste += cantidad;
    if (desgaste > vidaUtil) {
        desgaste = vidaUtil;
    }
}

void Husillo::darMantenimiento() {
    desgaste = 0.0;
}

bool Husillo::estaDesgastado() const {
    return desgaste >= vidaUtil;
}

double Husillo::getVidaUtil() const {
    return vidaUtil;
}

double Husillo::getDesgaste() const {
    return desgaste;
}