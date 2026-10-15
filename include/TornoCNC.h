#ifndef TORNO_CNC_H
#define TORNO_CNC_H

#include <string>
#include "Maquina.h"
#include "Husillo.h"

class TornoCNC : public Maquina {
private:
    double velocidadHusillo;
    double desgasteHusillo;
    Husillo husillo; // Composición

public:
    // Constructor que recibe id, nombre, la vida útil del husillo y la velocidad inicial
    TornoCNC(int id, const std::string& nombre, double vidaUtilHusillo, double velInicial);

    // Métodos propios
    void cilindrar();
    void ajustarVelocidad(double nuevaVelocidad);
    
    // Métodos redefinidos de la clase base
    void procesarPieza();
    bool procesarOperacion() override;
    void realizarMantenimiento() override;
    void mostrarEstado() const override;

    // Getters para consultar los atributos propios
    double getVelocidadHusillo() const;
    double getDesgasteHusillo() const;
};

#endif