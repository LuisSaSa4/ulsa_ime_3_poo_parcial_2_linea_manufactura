#ifndef MOTOR_H
#define MOTOR_H

class Motor {
private:
    int vidaUtil;      // vida restante (entera)
    double desgaste;   // cuánta vida pierde por uso

public:
    explicit Motor(int vidaInicial);

    bool estaDesgastado() const;   // T si vidaUtil <= 0
    void restaurar();              // vuelve a la vida inicial
    void usar();                   // descuenta desgaste (auxiliar)

    int getVidaUtil() const;
    double getDesgaste() const;
    void mostrarEstado() const;
};

#endif    