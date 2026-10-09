// Herramienta_Corte.cpp
 
#include "Herramienta_Corte.h"
 
Herramienta_Corte::Herramienta_Corte(int vidaInicial)
    : desgaste_(0.0) {
    // Validacion: la vida util no puede ser 0 ni negativa
    if (vidaInicial > 0) {
        vidaUtil_ = vidaInicial;
    } else {
        vidaUtil_ = 1;
    }
}
 
bool Herramienta_Corte::estaDesgastada() const {
    // Esta desgastada cuando el desgaste alcanza la vida util
    if (desgaste_ >= vidaUtil_) {
        return true;
    }
    return false;
}
 
void Herramienta_Corte::usar() {
    desgaste_ = desgaste_ + 1.0;
}
 
void Herramienta_Corte::restaurar() {
    desgaste_ = 0.0;
}
 
int Herramienta_Corte::getVidaUtil() const {
    return vidaUtil_;
}
 
double Herramienta_Corte::getDesgaste() const {
    return desgaste_;
}
 