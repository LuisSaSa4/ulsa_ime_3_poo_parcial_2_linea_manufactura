#ifndef HUSILLO_H
#define HUSILLO_H

class Husillo {
private:
    double vidaUtil;
    double desgaste;

public:
    Husillo(double vidaUtilInicial);
    
    void usar(double cantidad = 1.0);
    void darMantenimiento();
    bool estaDesgastado() const;

    double getVidaUtil() const;
    double getDesgaste() const;
};

#endif