/**
 * @file Ejercicio_3.cpp
 * @brief Programa que simula la compra de un producto en una tienda online.
 *
 * @details Este programa solicita al usuario ingresar el nombre de un producto, su precio, la cantidad de años de garantía
 * y el nombre del comprador.
 * Luego, muestra un mensaje confirmando la compra con los datos ingresados.
 *
 * Utiliza 'cin' para capturar los valores numéricos y 'getline(cin, variable)' para capturar cadenas de texto con espacios.
 * El programa finaliza mostrando un mensaje con el formato: "[Usuario] adquirió [Producto] por el precio
 * de [Precio], con garantía de [Garantía] años."
 * @authors [Lina Vanessa Cosme Arce - 2436459]--[Whitsell Stiven Diosa Villada - 2439170]
 * @mail [lina.cosme@correounivalle.edu.co]--[whitsell.diosa@correounivalle.edu.co]
 * @date 2025-03-02
 * @version 1.0
 *
 * @comentario: Se investigó sobre el 'getline(cin, variable)' y 'cin.ignore()' en la página https://en.cppreference.com/w/
 */

#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Declarar variables
    string nombre_producto;
    string precio;
    string garantia;
    string nombre_usuario;

    // Obtención de datos
    cout << "Nombre producto: ";
    getline(cin, nombre_producto);

    cout << "Precio: ";
    cin >> precio;

    cout << "Garantía (años): ";
    cin >> garantia;
    cin.ignore(); // Limpiar el buffer antes de obtener el nombre del usuario

    cout << "Nombre usuario: ";
    getline(cin, nombre_usuario);

    // Salida de datos
    cout << nombre_usuario << " adquirió " << nombre_producto << " por el precio de " << precio << ", con garantía de " << garantia << " años." << endl;

    return 0;
}