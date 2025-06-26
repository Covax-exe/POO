/*
 * @Ejercicio_4.cpp
 * @brief Un programa que almacena las calificaciones de un estudiante y
 * al final muestra en pantalla su nota final.
 *
 * @details utiliza una funcion llamada *final* cuyos parametros son 3 numeros
 * flotantes, en cuyo caso son las notas que el usuario digita, practica, teorica y participativa, respectivamente.
 * Y con ellos calcula la nota final del estudiante.
 * @author [Lina Vanessa Cosme Arce - 2436459]--[Whitsell Stiven Diosa Villada - 2439170]
 * @mail [lina.cosme@correounivalle.edu.co]-- [whitsell.diosa@correounivalle.edu.co]
 * @date 2025-03-08
 * @version 1.23.6
 *
 * @comentario
 */

#include <iostream>
using namespace std;

// Prototipo de funcion
float final(float a, float b, float c);

int main()
{
    cout << "Este es un programa que tomara sus notas de participacion, teoricas y participativa para darle su nota final" << endl;
    float practica, teorica, partici;

    cout << "Ingrese su nota de practica: ";
    cin >> practica;
    cout << "Ingrese su nota teorica: ";
    cin >> teorica;

    cout << "Ingrese su nota participativa: ";
    cin >> partici;
    /*como la funcion final retorna un numero, entonces en la impresion se invoca la funcion con sus argumentos en orden para que nos retorne el resultado
    al evaluar las notas del usuario.*/
    cout << "Su nota definitiva es: " << final(practica, teorica, partici) << endl;

    return 0;
}

// Definicion de la funcion
// Los argumentos de la funcion son las notas de: practica, teorica y participativa respectivamente.
float final(float a, float b, float c)
{
    // se crea una variable llamada nota final que alamcenara el resultado de las operaciones de las notas.
    float notaFinal;
    a = a * 0.30;
    b = b * 0.60;
    c = c * 0.10;
    notaFinal = a + b + c;
    return notaFinal;
}