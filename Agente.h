#ifndef AGENTE_H
#define AGENTE_H

#include "Laberinto.h"
#include <vector>

class Agente
{
private:
    int x, y;                                // Posicion actual del agente
    Laberinto *laberinto;                    // Puntero al laberinto
    std::vector<std::vector<bool>> visitado; // Celdas visitadas para DFS

public:
    Agente(Laberinto *l);    // Constructor con puntero al Laberinto
    bool mover();            // Inicia el algoritmo de busqueda
    bool haLlegado() const;  // Verifica si llegó a la salida
    void mostrarPos() const; // Muestra posicion actual
    bool buscarSalidaDFS();  // Inicia busqueda DFS
    bool dfs(int, int);      // Funcion recursiva DFS
};

#endif // AGENTE_H