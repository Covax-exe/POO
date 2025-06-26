#include "Vista.h"
#include <iostream>

using namespace std;

void Vista::mostrarLaberinto(const Laberinto &l)
{
    l.mostrar(); // Llama al metodo mostrar del Laberinto
}

void Vista::mostrarEstado(const Agente &a)
{
    a.mostrarPos(); // Llama al metodo mostrarPos del Agente
}
