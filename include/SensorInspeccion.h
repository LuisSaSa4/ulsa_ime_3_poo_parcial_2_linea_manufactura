#ifndef SENSORINSPECCION_H
#define SENSORINSPECCION_H

// Componente que revisa las piezas de la linea de produccion.
class SensorInspeccion {
private:
    int vidaUtil;
    double desgaste;

public:
    // Configura la vida util inicial del sensor.
    SensorInspeccion(int vidaInicial);

    // Registra el uso durante una inspeccion.
    void registrarUso();

    // Comprueba si el sensor alcanzo su limite.
    bool estaDesgastado() const;

    // Reinicia el desgaste despues del mantenimiento.
    void restaurar();

    // Permiten consultar los datos del componente.
    int getVidaUtil() const;
    double getDesgaste() const;
};

#endif