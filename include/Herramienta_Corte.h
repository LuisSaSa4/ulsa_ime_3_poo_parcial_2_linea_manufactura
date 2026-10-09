// Herramienta_Corte.h
// Componente de la Fresadora. Se desgasta con cada pieza que se procesa.
 
#ifndef HERRAMIENTA_CORTE_H
#define HERRAMIENTA_CORTE_H
 
class Herramienta_Corte {
private:
    int vidaUtil_;     // Cuantas piezas aguanta antes de desgastarse
    double desgaste_;  // Cuanto se ha desgastado (sube 1 por cada pieza)
 
public:
    // Constructor: recibe la vida util con la que nace la herramienta
    Herramienta_Corte(int vidaInicial);
 
    // Dice si la herramienta ya llego a su limite
    bool estaDesgastada() const;
 
    // Suma el desgaste de una pieza
    void usar();
 
    // Deja la herramienta como nueva (desgaste en 0)
    void restaurar();
 
    // Consultas
    int getVidaUtil() const;
    double getDesgaste() const;
};
 
#endif
 