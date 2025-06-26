#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "Laberinto.h"
#include "Agente.h"
#include "Vista.h"

class Controlador
{
private:
    Laberinto laberinto; // Instancia del laberinto
    Agente agente;       // Instancia del agente

public:
    Controlador();   // Constructor
    void ejecutar(); // Ejecuta el juego completo
};

#endif // CONTROLADOR_H