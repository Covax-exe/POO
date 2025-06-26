// ARCHIVO ".cpp" de la clase Camion

/**
 * @file Camion.cpp
 * @brief Construcción de la clase Camion.
 *
 * @details Clase que modela un camión con una placa y capacidad máxima.
 * Permite cargar objetos y verificar si supera la capacidad.
 * @authors [Lina Vanessa Cosme Arce - 202436459] [Whitsell Stiven Diosa Villada - 202439170]
 * @mail [lina.cosme@correounivalle.edu.co] [whitsell.diosa@correounivalle.edu.co]
 * @date 2025-03-15
 * @version 1.0
 *
 * @comentario:
 * - Se corrigió un error en la función "cargarUnObjeto" donde se estaba
 *   restando en lugar de sumando el peso de los objetos transportados.
 * - Se arreglaron problemas de identación.
 * - Se verificó que el camión no pueda sobrepasar su capacidad máxima.
 * - Se usa la líbreria <string> para el número de placa.
 */

/**
 * Implementación de la clase: Camion
 * Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
 * Universidad del Valle
 *
 * Información CRC:
 *
 * Descripción:
 *    - Implementa los métodos de la clase Camion declarada en "Camion.h".
 *    - Permite registrar la placa y capacidad máxima del camión.
 *    - Permite cargar objetos verificando que no excedan la capacidad máxima.
 *    - Lleva un registro del peso total transportado.
 *
 * Este es un proyecto del curso FPOO de la Universidad del Valle,
 * desarrollado con fines académicos. Puede ser utilizado con fines
 * educativos dando los créditos de la autoría.
 *
 * Autor: Lina Vanessa Cosme Arce
 * Correo: lina.cosme@correounivalle.edu.co
 * Fecha: 15 Marzo 2025
 */

#include "Camion.h" // llama el archivo .h de la clase camion
#include <string>   // libreria string
using namespace std;

// constructor de la clase camion
Camion::Camion(string laPlaca, int laCapacidadMaxima) // inicializa la placa, la capacidad maxima y el peso transportado en 0
{
    placa = laPlaca;
    capacidadMaxima = laCapacidadMaxima;
    pesoTransportado = 0;
}

// carga un objeto en el camion si no excede su capacidad maxima
bool Camion::cargarUnObjeto(int pesoDelObjeto) // retorna true si se pudo cargar, false en caso contrario
{
    if (pesoTransportado + pesoDelObjeto <= capacidadMaxima)
    {
        pesoTransportado = pesoTransportado + pesoDelObjeto; // suma el peso al total transportado
        return true;
    }
    else
        return false;
}

int Camion::hacerMudanza() { return pesoTransportado; } // devuelve el peso total transportado por el camion
string Camion::cualEsLaPlaca() { return placa; }        // devuelve la placa del camion