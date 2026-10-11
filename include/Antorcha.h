#ifndef ANTORCHA_H
#define ANTORCHA_h

class Antorcha{
    private:
    //Cantidad maxima de usos que soprta la antorcha
    int vidaUtil;

    //Cantidad de usos acumulados
    double desgaste;

    public:
    //Constructor que establece la vida util inicial
    explicit Antorcha(int vidaInicial);

    //Resistrar el uso del la antorcha
    void registrarUso();

    //Indica si la antorcha alcanzo si limite de desgaste
    bool estaDesgastado() const;

    //Reinicia el desgaste despues del mantenimiento
    void restaurar();

    //Obtener la vida util maxima de la antorcha
    int getVidaUtil() const;

    //Obtener la vida util maxima de la antorcha
    int getDesgaste() const;

};

#endif