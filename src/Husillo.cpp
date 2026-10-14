#include "Husillo.h"

Husillo::Husillo(int vidaMax) : vidaUtilMaxima(vidaMax), desgasteActual(0) {}

void Husillo::desgastar(int cantidad) {
    desgasteActual += cantidad;
    if (desgasteActual > vidaUtilMaxima) {
        desgasteActual = vidaUtilMaxima;
    }
}

void Husillo::restaurar() {
    desgasteActual = 0;
}

bool Husillo::estaDañado() const {
    return desgasteActual >= vidaUtilMaxima;
}

int Husillo::getDesgasteActual() const {
    return desgasteActual;
}

int Husillo::getVidaUtilMaxima() const {
    return vidaUtilMaxima;
}