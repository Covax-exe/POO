/*
 * Asignatura: PROGRAMACIÓN ORIENTADA A OBJETOS (IPOO) 750015C
 * Archivo: Elipse.cpp
 * Fecha creación: 10-mayo-2025
 * Versión: 0.1
 * Autores: Lina Vanessa Cosme Arce, Whitsell Stiven Diosa Villada
 *
 * ESCUELA DE INGENIERÍA DE SISTEMAS Y COMPUTACIÓN
 * UniValle
 */

/*
 *   Proyecto: Figuras Geometricas
 *   Curso: Fundamentos de Programacion Orientada a Objetos (FPOO)
 *   Universidad del Valle
 *   Autores: [Lina Vanessa Cosme Arce - 202436459], [Whitsell Stiven Diosa Villada - 202439170]
 *   Correo: [lina.cosme@correounivalle.edu.co], [whitsell.diosa@correounivalle.edu.co]
 *   Fecha: Mayo 2025
 */

#include "Elipse.h"
#include <cmath> // Para usar sqrt()

// Constructor: inicializa x, y, a, b
Elipse::Elipse(double x, double y, double a, double b) : Figura(x, y), a(a), b(b) {}

// Calcula el area de la elipse con la formula π * a * b
double Elipse::area() const
{
    return 3.1416 * a * b;
}

// Aproximacion de perimetro usando formula de Ramanujan
double Elipse::perimetro() const
{
    return 2 * 3.1416 * std::sqrt((a * a + b * b) / 2);
}

// Escala los semiejes por un factor
void Elipse::agrandar(double factor)
{
    a *= factor;
    b *= factor;
}