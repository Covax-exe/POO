#include "Agente.h"
#include <iostream>

using namespace std;

Agente::Agente(Laberinto *l) : laberinto(l)
{
    int N = Laberinto::getTamano();
    visitado = vector<vector<bool>>(N, vector<bool>(N, false)); // Inicializa matriz de visitados
    do
    {
        x = rand() % N;
        y = rand() % N;
    } while (laberinto->getCelda(x, y) == 0); // Asegura que el agente empiece en una celda valida
}

bool Agente::mover()
{
    return buscarSalidaDFS(); // Llama a DFS para moverse automaticamente
}

bool Agente::haLlegado() const
{
    int N = Laberinto::getTamano();
    return x == N - 1 && y == N - 1; // Verifica si está en la salida
}

void Agente::mostrarPos() const
{
    cout << "Posición actual: (" << x << "," << y << ")\n"; // Muestra coordenadas del agente
}

bool Agente::buscarSalidaDFS()
{
    return dfs(x, y); // Llama a la funcion DFS desde la posición actual
}

bool Agente::dfs(int i, int j)
{
    int N = Laberinto::getTamano();
    if (i < 0 || i >= N || j < 0 || j >= N)
        return false; // Verifica limites
    if (visitado[i][j] || laberinto->getCelda(i, j) == 0)
        return false;      // Ya visitado o precipicio
    visitado[i][j] = true; // Marca como visitado
    x = i;
    y = j;
    mostrarPos(); // Muestra la nueva posicion
    if (i == N - 1 && j == N - 1)
        return true; // Si llegó a la salida
    // Intenta en todas las direcciones
    return dfs(i + 1, j) || dfs(i - 1, j) || dfs(i, j + 1) || dfs(i, j - 1);
}