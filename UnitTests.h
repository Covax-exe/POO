
/*
    Clase: UnitTests
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle

    Información CRC:

    Clase: UnitTests
    
    Descripción:
    Esta clase contiene métodos estáticos para realizar pruebas unitarias
    sobre la clase BloodDatabase. Las funciones ahora reciben una referencia
    a un objeto BloodDatabase compartido para mantener consistencia entre pruebas.

    Este es un proyecto del curso FPOO de la Universidad del Valle,
    desarrollado con fines académicos.

    Autor: Victor Bucheli
    Correo: victor.bucheli@correounivalle.edu.co
    Fecha: Octubre 2024
*/
#ifndef UNIT_TESTS_H
#define UNIT_TESTS_H

#include "BloodDatabase.h"
#include "Donor.h"
#include <string>

class UnitTests {
public:
    // Prueba la funcionalidad de obtener detalles del donante. Utiliza una instancia compartida de BloodDatabase para evitar entrada manual.
    static void testGetDonorDetails(BloodDatabase& db);

    // Verifica que los datos se escriban correctamente en el archivo. Utiliza los datos ya cargados en la instancia db.
    static void testWriteDataToFile(BloodDatabase& db);

    // Comprueba la búsqueda y visualización de donantes desde db.
    static void testSearchAndDisplay(BloodDatabase& db);

    // Prueba la eliminación de donantes usando los datos existentes en db.
    static void testDeleteDonor(BloodDatabase& db);

    // Verifica el cálculo y visualización de la distribución de tipos de sangre en db.
    static void testDisplayBloodTypeDistribution(BloodDatabase& db);

    // Ejecuta todas las pruebas unitarias sobre una misma instancia de BloodDatabase.
    static void runAllTests();
    // Agrega un donante de prueba a la base de datos para las pruebas.
    void searchAndDisplayAuto(int departamentoSeleccionado);
    // Elimina un donante de prueba de la base de datos para las pruebas.
    void deleteDonorAuto(const std::string& nombre, bool confirmar);

};

#endif // UNIT_TESTS_H


