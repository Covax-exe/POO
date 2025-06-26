/*
    Proyecto: BloodDatabase (Adaptado)
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle

    Descripción:
    Este archivo contiene el punto de entrada principal del sistema de gestión
    de donantes de sangre. Implementa el menú principal y la lógica de
    interacción con el usuario, permitiendo acceder a todas las funcionalidades
    del sistema.

    Funcionalidades principales:
    - Registro de nuevos donantes
    - Búsqueda de donantes
    - Eliminación de donantes
    - Visualización de estadísticas de tipos de sangre
    - Pruebas unitarias del sistema

    Este es un proyecto del curso FPOO de la Universidad del Valle,
    desarrollado con fines académicos. Puede ser utilizado con fines
    académicos dando los créditos de la autoría.

    Autor: Victor Bucheli
    Correo: victor.bucheli@correounivalle.edu.co
    Fecha: Octubre 2024
*/

#include "BloodDatabase.h"
#include "Donor.h"
#include "Utils.h"
#include <iostream>
#include <limits>
#include <string>
#include <cassert>

using namespace std;

#include "UnitTests.h"

int main() {
    std::string donorName;
    BloodDatabase database;
    int choice;

    while (true) {
        // Limpiar la interfaz para mejor visibilidad
        Utils::clearScreen();

        // Mostrar el banner del sistema
        Utils::displayBanner();

        // Mostrar menú de opciones
        std::cout << "1. Registrar donante\n";
        std::cout << "2. Buscar donante\n";
        std::cout << "3. Eliminar donante\n";
        std::cout << "4. Mostrar distribucion de tipos de sangre\n";
        std::cout << "5. Ejecutar pruebas unitarias\n";
        std::cout << "6. Salir\n";
        std::cout << "Ingrese su eleccion: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 5) {
            UnitTests::runAllTests();
            Utils::waitForKey();
            continue;
        }

        // Procesar la elección del usuario
        switch (choice) {
            case 1:
                database.getDonorDetails();
                database.writeDataToFile();
                break;
            case 2:
                database.searchAndDisplay();
                break;
            case 3:
                std::cout << "Ingrese el nombre del donante a eliminar: ";
                std::getline(std::cin, donorName);
                database.deleteDonor(donorName);
                Utils::waitForKey();
                break;
            case 4:
                database.displayBloodTypeDistribution();
                break;
            case 5:
                std::cout << "\nEjecutando todas las pruebas...\n";
                UnitTests::runAllTests();
                Utils::waitForKey();
                break;
            case 6:
                std::cout << "Gracias por usar el Sistema de la Cruz Roja" << std::endl;
                return 0;
            default:
                std::cout << "Opcion no valida. Intentalo de nuevo.\n";
                Utils::waitForKey();
                break;
        }
    }
}
/*
g++ mainSangre.cpp Donor.cpp BloodDataBase.cpp -o mainSangre
./mainSangre
*/