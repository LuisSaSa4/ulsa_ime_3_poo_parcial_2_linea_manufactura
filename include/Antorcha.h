
#ifndef ANTORCHA_H
#define ANTORCHA_H

// Componente utilizado por el RobotSoldador.
// Controla su vida util y el desgaste acumulado.
class Antorcha {
private:
    int vidaUtil;
    double desgaste;

public:
    // Constructor del componente.
    Antorcha(int vidaInicial);

    // Registra el uso de la antorcha al soldar una pieza.
    void registrarUso();

    // Comprueba si la antorcha alcanzo su vida util.
    bool estaDesgastado() const;

    // Restaura la antorcha despues del mantenimiento.
    void restaurar();

    // Permiten consultar el estado del componente.
    int getVidaUtil() const;
    double getDesgaste() const;
};

#endif