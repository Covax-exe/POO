/*
 * @file main.cpp
 * @brief Programa principal para simular la interacción con una mascota virtual (tamagotchi).
 *
 * @details En este archivo se crea una instancia de la clase mascota y se interactúa con ella.
 * Se pueden probar los métodos como saludar, alimentar, dar la pata y revisar el estado de llenura.
 * @authors [Lina Vanessa Cosme Arce - 2436456] [Whitsell Stiven Diosa Villada - 2439170]
 * @mail [lina.cosme@correounivalle.edu.co] [whitsell.diosa@correounivalle.edu.co]
 * @date 2025-03-22
 * @version 1.23.6
 *
 * @comentario:  Se utilizó la librería <iostream> para manejar la entrada y salida de datos,
 * además, se diseñó un menú interactivo utilizando un bucle do-while y una estructura switch
 * para gestionar las diferentes opciones del usuario de manera eficiente.
 */

#include <iostream>
#include "tamagotchiUnico.h"
using namespace std;

int main()
{
    string nombre;
    cout << "Digite el nombre de su mascota: ";
    cin >> nombre;

    // Crear una instancia de la clase mascota
    mascota miMascota(nombre);

    int opcion = 0;
    do
    {
        // Mostrar el menú
        cout << "\n----------------------\n";
        cout << "1. Saludar a la mascota\n";
        cout << "2. Alimentar a la mascota\n";
        cout << "3. Dar la pata\n";
        cout << "4. Revisar si comio\n";
        cout << "5. Salir\n";
        cout << "----------------------\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        // Procesar la opción seleccionada
        switch (opcion)
        {
        case 1:
            miMascota.saludar();
            break;
        case 2:
            miMascota.setComer(true);
            // Aumentamos llenura en 3 (se ajustará a 10 si excede el límite)
            miMascota.setLlenura(miMascota.getLlenura() + 3);
            cout << miMascota.getNombre() << " ha sido alimentado y está más lleno.\n";
            break;
        case 3:
            miMascota.darLaPata();
            break;
        case 4:
            miMascota.siComio();
            break;
        case 5:
            cout << "Saliendo del programa... ¡Adios!\n";
            break;
        default:
            cout << "Opción no válida. Por favor, intenta de nuevo.\n";
            break;
        }
    } while (opcion != 5);

    return 0;
}