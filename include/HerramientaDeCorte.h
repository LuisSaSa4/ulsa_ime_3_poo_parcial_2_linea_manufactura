#ifndef HERRAMIENTADECORTE_H
#define HERRAMIENTADECORTE_H

// Componente que se desgasta durante el fresado.
class HerramientaDeCorte {
private:
    int vidaUtil;
    double desgaste;

public:
    // Prepara una herramienta con la vida util indicada.
    HerramientaDeCorte(int vidaInicial);

    // Suma el desgaste producido por una pieza.
    void registrarUso();

    // Indica si la herramienta ya llego al limite de uso.
    bool estaDesgastado() const;

    // Deja la herramienta lista para volver a trabajar.
    void restaurar();

    // Consultas para mostrar la informacion del componente.
    int getVidaUtil() const;
    double getDesgaste() const;
};

#endif