#ifndef MOTORBANDA_H
#define MOTORBANDA_H

// Motor encargado de mantener el movimiento de la banda.
class MotorBanda {
private:
    int vidaUtil;
    double desgaste;

public:
    // Establece el limite de funcionamiento del motor.
    MotorBanda(int vidaInicial);

    // Registra el esfuerzo de transportar una pieza.
    void registrarUso();

    // Revisa si el motor alcanzo su limite de uso.
    bool estaDesgastado() const;

    // Restablece el desgaste despues de la revision.
    void restaurar();

    // Devuelven informacion del estado del componente.
    int getVidaUtil() const;
    double getDesgaste() const;
};

#endif
