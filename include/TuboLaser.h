
#ifndef TUBOLASER_H
#define TUBOLASER_H

// Componente que proporciona el laser para realizar los cortes.
class TuboLaser {
private:
    int vidaUtil;
    double desgaste;

public:
    // Define cuanto tiempo de uso tiene disponible el tubo.
    TuboLaser(int vidaInicial);

    // Registra el uso del laser durante el corte.
    void registrarUso();

    // Comprueba si el componente ya llego al limite establecido.
    bool estaDesgastado() const;

    // Recupera la vida de uso del componente.
    void restaurar();

    // Consultan los valores actuales del tubo.
    int getVidaUtil() const;
    double getDesgaste() const;
};

#endif