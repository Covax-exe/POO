#include "Laberinto.h"
#include <iostream>
#include <cstdlib> // Para el funcionamiento del rand()
#include <ctime>   // Para el funcionamiento de srand() y que sea mas aleatorio

using namespace std;

Laberinto::Laberinto()
{
    srand(time(0)); // Inicializa la semilla para numeros aleatorios
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            matriz[i][j] = (rand() % 100 < 70) ? 1 : 0; // 70% de probabilidad de camino (1)
    matriz[N - 1][N - 1] = 1;                           // Asegura que la salida sea accesible
}

int Laberinto::getCelda(int x, int y) const
{
    if (x < 0 || x >= N || y < 0 || y >= N)
        return 0; // Fuera de limites es precipicio
    return matriz[x][y];
}

void Laberinto::mostrar() const
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << matriz[i][j] << " "; // Imprime cada celda
        cout << endl;
    }
}

int Laberinto::getTamano()
{
    return N; // Devuelve tamaño del laberinto
}