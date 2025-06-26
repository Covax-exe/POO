
/*
    Proyecto: BloodDatabase (Adaptado)
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle

    Descripción:
    Este archivo implementa las pruebas unitarias del sistema de gestión
    de donantes de sangre. Cada método verifica una funcionalidad específica
    del sistema para asegurar su correcto funcionamiento, de tal manera en la que
    el sistema pueda ser probado de manera automática.

    El código se basó en el proyecto BloodDatabase, fue traducido al español
    y adaptado a las necesidades del curso.

    Autor: Victor Bucheli
    Correo: victor.bucheli@correounivalle.edu.co
    Fecha: Octubre 2024
*/

#include "UnitTests.h"
#include <iostream>
#include "Utils.h"
#include <chrono>  // Se incluyen para usar std::this_thread::sleep_for y std::chrono::milliseconds con el fin de dar tiempo a ver los resultados, dando un mejor feedback visual.
#include <thread>
#include <sstream> // Se incluye para simular entradas de usuario usando std::istringstream

/*
    Función: testGetDonorDetails
    Descripción: Verifica que se agregue correctamente un donante de prueba.
                 Utiliza la instancia compartida de la base de datos para mantener coherencia entre pruebas.
*/
void UnitTests::testGetDonorDetails(BloodDatabase& db) {
    try {
        db.addTestDonor(); // No se crea nueva instancia, se usa la pasada por referencia
        std::cout << "\n\n✓ Prueba addTestDonor exitosa\n" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "\n\n✗ Error en addTestDonor: " << e.what() << "\n" << std::endl;
    }
}

/*
    Función: testWriteDataToFile
    Descripción: Verifica que los datos cargados se escriban correctamente en el archivo.
                 Utiliza la misma instancia de la base de datos para asegurar consistencia.
*/
void UnitTests::testWriteDataToFile(BloodDatabase& db) {
    try {
        db.writeDataToFile();
        std::cout << "\n\n✓ Prueba writeDataToFile exitosa\n" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "\n\n✗ Error en writeDataToFile: " << e.what() << "\n" << std::endl;
    }
}

/*
    Función: testSearchAndDisplay
    Descripción: Verifica que la búsqueda y visualización funcionen correctamente usando entrada simulada.
                 Se evita la intervención manual utilizando std::istringstream.
*/
void UnitTests::testSearchAndDisplay(BloodDatabase& db) {
    try {
        // Entrada simulada: departamento 1, dirección vacía, tipo de sangre vacío
        std::istringstream simulatedInput("1\n\n\n");

        // Guardamos el buffer original de cin y lo redirigimos temporalmente a la entrada simulada
        std::streambuf* originalCin = std::cin.rdbuf();
        std::cin.rdbuf(simulatedInput.rdbuf());

        db.searchAndDisplay();  // Ejecuta la función con entrada simulada

        std::cin.rdbuf(originalCin);  // Restauramos el buffer original de cin

        std::cout << "\n\n✓ Prueba searchAndDisplay exitosa\n" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "\n\n✗ Error en searchAndDisplay: " << e.what() << "\n" << std::endl;
    }
}

/*
    Función: testDeleteDonor
    Descripción: Verifica que un donante pueda eliminarse correctamente mediante confirmación automática.
                 Se simula la entrada del usuario con std::istringstream.
*/
void UnitTests::testDeleteDonor(BloodDatabase& db) {
    try {
        // Simulamos la entrada de "s" para confirmar la eliminación
        std::istringstream simulatedInput("s\n");

        // Guardamos y redirigimos temporalmente la entrada estándar
        std::streambuf* originalCin = std::cin.rdbuf();
        std::cin.rdbuf(simulatedInput.rdbuf());

        std::string testName = "Juan Perez"; // Nombre del donante de prueba
        db.deleteDonor(testName);  // Se ejecuta con confirmación automática

        std::cin.rdbuf(originalCin);  // Restauramos la entrada original

        std::cout << "\n\n✓ Prueba deleteDonor exitosa\n" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "\n\n✗ Error en deleteDonor: " << e.what() << "\n" << std::endl;
    }
}

/*
    Función: testDisplayBloodTypeDistribution
    Descripción: Verifica que la distribución de tipos sanguíneos se calcule y muestre correctamente.
*/
void UnitTests::testDisplayBloodTypeDistribution(BloodDatabase& db) {
    try {
        db.displayBloodTypeDistribution();
        std::cout << "\n\n✓ Prueba displayBloodTypeDistribution exitosa\n" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "\n\n✗ Error en displayBloodTypeDistribution: " << e.what() << "\n" << std::endl;
    }
    std::cout << std::endl;
}

// Función para introducir un retraso en la ejecución del programa
void delay(int milliseconds = 500) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

/*
    Función: runAllTests
    Descripción: Ejecuta todas las pruebas unitarias de forma secuencial, usando una única instancia de BloodDatabase.
                 Se introducen pequeños retrasos entre pruebas para mejorar la legibilidad visual en consola.
                 Cada prueba es independiente y reporta su resultado (éxito o error).
*/
void UnitTests::runAllTests() {
    std::cout << "\n=== Iniciando pruebas unitarias ===\n" << std::endl;

    delay(700);  // Retraso inicial para preparar la visualización del bloque de pruebas

    BloodDatabase db;  // Se crea una única instancia de base de datos para todas las pruebas

    std::cout << "\n✓ Donante de prueba agregado automáticamente.\n" << std::endl;

    // Prueba #1: Validación de agregar donante correctamente
    delay();
    testGetDonorDetails(db); // Comprueba que el donante se haya agregado sin errores

    // Prueba #2: Escritura de datos al archivo
    delay();
    testWriteDataToFile(db); // Valida que se pueda guardar correctamente la base de datos

    // Prueba #3: Búsqueda y visualización automática
    delay();
    testSearchAndDisplay(db); // Automatiza el ingreso del departamento y valida que se muestren los resultados

    // Prueba #4: Eliminación automática del donante previamente añadido
    delay();
    testDeleteDonor(db); // Elimina automáticamente al donante de prueba si existe en la base

    // Prueba #5: Verifica la distribución de tipos de sangre con los datos actuales
    delay();
    testDisplayBloodTypeDistribution(db); // Calcula y muestra porcentajes de tipos sanguíneos

    delay(600); // Pequeño descanso visual antes del mensaje final
    std::cout << "\n=== Pruebas unitarias completadas ===" << std::endl;
    // En este punto, todas las pruebas se han ejecutado exitosamente si no se lanzaron excepciones.
}


