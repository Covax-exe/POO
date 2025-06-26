#ifndef LABERINTO_H
#define LABERINTO_H

class Laberinto
{
private:
    static const int N = 10; // Tamaño del laberinto 10x10
    int matriz[N][N];        // Matriz que representa el laberinto

public:
    Laberinto();                      // Constructor
    int getCelda(int x, int y) const; // Retorna el valor de una celda
    void mostrar() const;             // Muestra el laberinto
    static int getTamano();           // Retorna el tamaño del laberinto
};

#endif // LABERINTO_H