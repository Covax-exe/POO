// ARCHIVO ".h" de la clase Camion

/**
 * @file Camion.h
 * @brief Definición de la clase Camion.
 *
 * @details Clase que modela un camión con una placa y capacidad máxima.
 * Permite cargar objetos y verificar si supera la capacidad.
 * @authors [Lina Vanessa Cosme Arce - 202436459] [Whitsell Stiven Diosa Villada - 202439170]
 * @mail [lina.cosme@correounivalle.edu.co] [whitsell.diosa@correounivalle.edu.co]
 * @date 2025-03-15
 * @version 1.0
 *
 * @comentario:
 * - Se usa la librería <string> para el número de placa, ya que no se va a operar con esta.
 * - Se cambió el nombre de pl; cm y ptc por nombres más intuitivos: placa, capacidadMaxima y pesoTransportado.
 */

/**
 * Clase: Camion
 * Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
 * Universidad del Valle
 *
 * Información CRC:
 *
 * Clase: Camion
 * Responsabilidades:
 *    - Representar un camión con placa y capacidad máxima de carga.
 *    - Permitir la carga de objetos hasta su capacidad máxima.
 *    - Indicar si un objeto excede la capacidad y debe ser cargado en otro camión.
 *    - Registrar el peso total transportado.
 *
 * Colaboradores:
 *    -
 *
 * Este es un proyecto del curso FPOO de la Universidad del Valle,
 * desarrollado con fines académicos. Puede ser utilizado con fines
 * educativos dando los créditos de la autoría.
 *
 * Autor: Lina Vanessa Cosme Arce
 * Correo: lina.cosme@correounivalle.edu.co
 * Fecha: 15 Marzo 2025
 */

#ifndef CAMION_H
#define CAMION_H

#include <string> // libreria string
using namespace std;

// nombre de la clase
class Camion
{
private:                  // encapsulamiento
    string placa;         // numero de la placa
    int capacidadMaxima;  // capacidad maxima en kg
    int pesoTransportado; // peso transportado en el camion

public:
    Camion(string laPlaca, int laCapacidadMaxima); // constructor de la clase. Recibe la placa y la capacidad maxima del camión.
    bool cargarUnObjeto(int pesoDelObjeto);        // intenta cargar un objeto al camion. true = se pudo hacer; false = no se pudo hacer
    int hacerMudanza();                            // retorna la carga que transportó
    string cualEsLaPlaca();                        // retorna el número de placa
};

#endif // CAMION_H