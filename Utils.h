
/*
    Clase: Utils
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle

    Información CRC:

    Clase: Utils

    Responsabilidades:
        - Proporcionar funciones utilitarias comunes para todo el proyecto
        - Manejar operaciones de interfaz de usuario básicas
        - Validar y procesar cadenas de texto
        - Mostrar elementos visuales como banners

    Colaboradores:
        - Colabora con todas las clases del proyecto proporcionando
          funcionalidades comunes y utilitarias

    Este es un proyecto del curso FPOO de la Universidad del Valle,
    desarrollado con fines académicos. Puede ser utilizado con fines
    académicos dando los créditos de la autoría.

    Autor: Victor Bucheli
    Correo: victor.bucheli@correounivalle.edu.co
    Fecha: Octubre 2024
*/

#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <iostream>

class Utils {
public:
    // Limpia la pantalla de la consola
    static void clearScreen();
    
    // Espera a que el usuario presione una tecla
    static void waitForKey();
    
    // Elimina espacios en blanco al inicio y final de una cadena
    static std::string trim(const std::string& str);
    
    // Verifica si una cadena contiene solo números
    static bool isNumeric(const std::string& str);
    
    // Muestra el banner principal del sistema
    static void displayBanner();
};

#endif // UTILS_H
