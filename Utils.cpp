
/*
    Proyecto: BloodDatabase (Adaptado)
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle

    Descripción:
    Este archivo implementa funcionalidades utilitarias comunes utilizadas
    en todo el proyecto, incluyendo operaciones de interfaz de usuario y
    procesamiento de cadenas.

    El código se basó en el proyecto BloodDatabase, fue traducido al español
    y adaptado a las necesidades del curso.

    Autor: Victor Bucheli
    Correo: victor.bucheli@correounivalle.edu.co
    Fecha: Octubre 2024
*/

#include "Utils.h"
#include <algorithm>
#include <cctype>

// Limpia la pantalla de la consola según el sistema operativo
void Utils::clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    // system("clear");
#endif
}

// Pausa la ejecución hasta que el usuario presione una tecla
void Utils::waitForKey() {
    std::cout << "Presione cualquier tecla para continuar...";
    std::cin.ignore();
    std::cin.get();
}

// Elimina espacios en blanco al inicio y final de una cadena
std::string Utils::trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos)
        return "";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

// Verifica si una cadena contiene solo caracteres numéricos
bool Utils::isNumeric(const std::string& str) {
    return !str.empty() && 
           std::all_of(str.begin(), str.end(), ::isdigit);
}

// Muestra el banner principal del sistema con diseño ASCII
void Utils::displayBanner() {
    std::cout << R"(
        |---------------------------------------------------------|
        |                                                         |
        |     ___|   _ \  |   |__  /   _ \   _ \      |   \       |
        |     |     |   | |   |   /   |   | |   |     |  _ \      |
        |     |     __ <  |   |  /    __ <  |   | \   | ___ \     |
        |    \____|_| \_\\___/ ____| _| \_\\___/ \___/_/    _\    |
        |                                                         |
        |____________S_I_E_M_P_R_E__D_E__T_U__L_A_D_O_____________|
        )" << std::endl;
}
