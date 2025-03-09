/**
 * @file calificacion.cpp
 * @brief Programa que dada una calicación para el empleado, muestre la
 * calicación en palabras de esta manera:
 * ● Si es a, la calicación es aceptable
 * ● Si es b; la calicación es buena
 * ● Si es e, la calicación es excelente.
 * ● Si es otra calificacion(s): no se clasificó.
 *
 * @details Este programa permite ingresar una calificación y devuelve su equivalente en palabras.
 * @authors Lina Vanessa Cosme Arce; Whitsell Stiven Diosa Villada.
 * @codes 202436459; 202439170
 * @mails lina.cosme@correounivalle.edu.co; whitsell.diosa@correounivalle.edu.co
 * @date 2025-03-02
 * @version 1.0
 */

#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Se declara la variable para almacenar la calificación ingresada
    string calificacion;

    // Se le solicita la calificación al usuario
    cout << "Ingrese la calificación del empleado: " << endl;
    cin >> calificacion; // Se lee la entrada del usuario

    // Se evalúa la calificación ingresada y se imprime el resultado correspondiente
    if (calificacion == "a")
    {
        cout << "aceptable" << endl; // Si es "a" se imprime "aceptable"
    }
    else if (calificacion == "b")
    {
        cout << "bueno" << endl; // Si es "b" se imprime "bueno"
    }
    else if (calificacion == "e")
    {
        cout << "excelente" << endl; // Si es "e" se imprime "excelente"
    }
    else
    {
        cout << "no se clasificó" << endl; // Si no es ninguna se imprime "no se clasificó"
    }

    cout << endl; // Asegurar un salto de línea adicional al final de la salida

    return 0;
}