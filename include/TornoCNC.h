#ifndef TORNO_CNC_H
#define TORNO_CNC_H

#include "Maquina.h"
#include "Husillo.h"

class TornoCNC : public Maquina {
private:
    double velocidadHusillo;
    double desgasteHusillo;
    Husillo husillo; // Composición

public:
    TornoCNC(int id, const std::string& nombre, double vidaUtilHusillo, double velInicial);

    // Métodos del diagrama
    void cilindrar();
    void ajustarVelocidad(double nuevaVelocidad);
    void procesarPieza();
    void realizarMantenimiento();
    void mostrarEstado() const override;

    double getVelocidadHusillo() const;
    double getDesgasteHusillo() const;
};

#endif