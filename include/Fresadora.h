
// Fresadora.h
// Maquina derivada de Maquina. Su operacion es ranurar la pieza.
 
#ifndef FRESADORA_H
#define FRESADORA_H
 
#include <string>
#include "Maquina.h"
#include "HerramientaDeCorte.h"
 
class Fresadora : public Maquina {
private:
    int tiempoPorPieza_;        // Segundos que tarda por pieza (mayor a 0)
    double profundidadRanura_;  // En mm, entre 0.5 y 20
    int velocidadRpm_;          // Entre 500 y 12000
    HerramientaDeCorte herramienta_;  // Composicion: la fresadora TIENE una herramienta
 
public:
    // Constructor. Los ultimos 4 datos tienen valor por defecto,
    // asi que se puede crear solo con id y nombre.
    Fresadora(int id, const std::string& nombre,
              int tiempoPorPieza = 45, int vidaHerramienta = 25,
              double profundidadMm = 5.0, int rpm = 3000);
 
    // Metodos propios (la clase Maquina no los tiene)
    void ranurar();
    int piezasRestantesHerramienta() const;
    bool herramientaDesgastada() const;
 
    // Metodos redefinidos de Maquina
    void mostrarEstado() const override;
    void realizarMantenimiento() override;
};
 
#endif