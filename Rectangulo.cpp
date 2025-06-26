/*
 * Asignatura: PROGRAMACIÓN ORIENTADA A OBJETOS (IPOO) 750015C
 * Archivo: Rectangulo.cpp
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

#include "Rectangulo.h"

// Constructor: inicializa x, y, base y alto
Rectangulo::Rectangulo(double x, double y, double base, double alto) : Figura(x, y), base(base), alto(alto) {}

// Calcula el area: base * alto
double Rectangulo::area() const
{
    return base * alto;
}

// Calcula el perimetro: 2*(base + alto)
double Rectangulo::perimetro() const
{
    return 2 * (base + alto);
}

// Escala la base y el alto por el factor
void Rectangulo::agrandar(double factor)
{
    base *= factor;
    alto *= factor;
}