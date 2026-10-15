#include "Planta.h"
#include "BandaTransportadora.h"
#include "CortadoraLaser.h"
#include "TornoCNC.h"
#include "Fresadora.h"
#include "RobotSoldador.h"
#include "EstacionDeInspeccion.h"

#include <iostream>

int main() {
    std::cout << "========================================\n";
    std::cout << " SIMULADOR DE PLANTA DE MANUFACTURA\n";
    std::cout << "========================================\n";

    // Creamos las maquinas con sus tiempos y vidas utiles.
    BandaTransportadora banda(1, "Banda-01", 4, 7);
    CortadoraLaser laser(2, "Laser-01", 12, 6);
    TornoCNC torno(3, "Torno-01", 10, 8);
    Fresadora fresadora(4, "Fresadora-01", 8, 5);
    RobotSoldador robot(5, "Robot-01", 6, 9);
    EstacionDeInspeccion inspeccion(6, "Inspeccion-01", 5, 10);

    // Creamos la planta y registramos las estaciones en orden.
    Planta planta;

    planta.agregarMaquina(&banda);
    planta.agregarMaquina(&laser);
    planta.agregarMaquina(&torno);
    planta.agregarMaquina(&fresadora);
    planta.agregarMaquina(&robot);
    planta.agregarMaquina(&inspeccion);

    // Comprobamos que no se pueda procesar con las maquinas apagadas.
    std::cout << "\n--- PRUEBA CON MAQUINAS APAGADAS ---\n";
    planta.procesarPieza();

    // Encendemos todas las estaciones.
    std::cout << "\n--- ENCENDIENDO LAS MAQUINAS ---\n";
    planta.encenderMaquinas();

    // Procesamos un lote de veinte piezas.
    std::cout << "\n--- PROCESANDO EL LOTE ---\n";
    planta.procesarLote(20);

    // Mostramos los resultados de la produccion.
    planta.mostrarReporte();

    // Apagamos las maquinas al terminar.
    std::cout << "\n--- APAGANDO LAS MAQUINAS ---\n";
    planta.apagarMaquinas();

    std::cout << "\nSimulacion finalizada.\n";

    return 0;
}