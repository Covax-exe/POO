/**
 * @file tabla_de_multiplicar.cpp
 * @brief Programa que muestra las tablas de multiplicar, de cero(0) al cinco (5).
 *
 * @details Este programa imprime las tablas de multiplicar del 0 al 5 en formato de matriz.
 * Cada fila representa la multiplicación de un número del 0 al 5 con los números del 0 al 5.
 * @authors Lina Vanessa Cosme Arce; Whitsell Stiven Diosa Villada.
 * @codes 202436459; 202439170
 * @mails lina.cosme@correounivalle.edu.co; whitsell.diosa@correounivalle.edu.co
 * @date 2025-03-02
 * @version 1.0
 */

#include <iostream>
using namespace std;

int main()
{
    // Imprimir los primeros numeros
    cout << "  0 1 2 3 4 5" << endl;

    // Generar las tablas de multiplicar de 0 a 5
    for (int i = 0; i <= 5; i++)
    {
        cout << i << " "; // Imprimir numero de la tabla
        for (int j = 0; j <= 5; j++)
        {
            cout << i * j << " "; // Imprimir multiplicación
        }
        cout << endl; // Salto de linea al final de cada fila
    }

    return 0;
}
