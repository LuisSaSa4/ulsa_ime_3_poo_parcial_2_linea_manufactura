// HerramientaDeCorte.cpp
 
#include "HerramientaDeCorte.h"
 
HerramientaDeCorte::HerramientaDeCorte(int vidaInicial)
    : desgaste_(0.0) {
    // Validacion: la vida util no puede ser 0 ni negativa
    if (vidaInicial > 0) {
        vidaUtil_ = vidaInicial;
    } else {
        vidaUtil_ = 1;
    }
}
 
bool HerramientaDeCorte::estaDesgastada() const {
    // Esta desgastada cuando el desgaste alcanza la vida util
    if (desgaste_ >= vidaUtil_) {
        return true;
    }
    return false;
}
 
void HerramientaDeCorte::usar() {
    desgaste_ = desgaste_ + 1.0;
}
 
void HerramientaDeCorte::restaurar() {
    desgaste_ = 0.0;
}
 
int HerramientaDeCorte::getVidaUtil() const {
    return vidaUtil_;
}
 
double HerramientaDeCorte::getDesgaste() const {
    return desgaste_;
}
 