#ifndef SENSOR_H
#define SENSOR_H

// Componente de la EstacionInspeccion (relacion de COMPOSICION).
// Modelo de desgaste: el sensor tiene una "calibracion" medida en piezas.
// Cada medicion consume 1 unidad. Al llegar a 0 el sensor esta descalibrado
// (agotado) y necesita recalibrarse.
class Sensor {
private:
    int calibracionMaxima;   // mediciones que aguanta entre calibraciones (> 0)
    int calibracionActual;   // mediciones que le quedan
    int recalibraciones;     // veces que se ha recalibrado

public:
    // Si calibracionMaxima <= 0 se usa un valor por omision (30) y se avisa.
    explicit Sensor(int calibracionMaxima);

    // Consume una unidad de calibracion. Devuelve false si ya estaba agotado.
    bool medir();

    // Restaura la calibracion al maximo y cuenta la recalibracion.
    void recalibrar();

    bool estaAgotado() const;
    int getCalibracionActual() const;
    int getCalibracionMaxima() const;
    int getRecalibraciones() const;
    double getPorcentajeCalibracion() const;

    void mostrarEstado() const;
};

#endif