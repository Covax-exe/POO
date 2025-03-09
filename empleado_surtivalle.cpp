/**
 * @file empleado_surtivalle.cpp
 * @brief Programa que permite almacenar los datos de un empleado en
 * Surtivalle.
 *
 * @details Este programa captura la información de un empleado, incluyendo su nombre, apellido,
 * número de identidad (NIT), cargo y salario. Luego, muestra estos datos en un formato legible.
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
    // Se declaran las variables de tipo string para almacenar los datos del empleado
    string nombre;   // Nombre del empleado
    string apellido; // Apellido del empleado
    string nit;      // Numero de Identidad (NIT) del empleado
    string cargo;    // Cargo del empleado
    string salario;  // Salario del empleado

    // Obtención de los datos
    cout << "Nombre: ";
    cin >> nombre;

    cout << "Apellido: ";
    cin >> apellido;

    cout << "NIT: ";
    cin >> nit;

    cout << "Cargo: ";
    cin >> cargo;

    cout << "Salario: ";
    cin >> salario;

    // Salida de los datos
    cout << nombre << ", identificad@ con el número de identidad " << nit << ", en el puesto de " << cargo << " recibe un pago mensual de " << salario << endl;

    return 0;
}
