#ifndef VISTA_H
#define VISTA_H

#include "Laberinto.h"
#include "Agente.h"

class Vista
{
public:
    static void mostrarLaberinto(const Laberinto &); // Muestra el laberinto
    static void mostrarEstado(const Agente &);       // Muestra la posicion del agente
};

#endif // VISTA_H