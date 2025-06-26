/*
 * Asignatura: PROGRAMACIÓN ORIENTADA A OBJETOS (IPOO) 750015C
 * Archivo: Triangulo.cpp
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

#include "Triangulo.h"
#include <cmath> // Para usar pow() y sqrt()

// Constructor: inicializa x, y, base y altura
Triangulo::Triangulo(double x, double y, double base, double altura) : Figura(x, y), base(base), altura(altura) {}

// Calcula el area usando formula: (base * altura) / 2
double Triangulo::area() const
{
    return 0.5 * base * altura;
}

// Calcula el perimetro suponiendo triangulo isoceles
double Triangulo::perimetro() const
{
    // Usa Pitagoras para los lados iguales
    double lado = std::sqrt(std::pow(base / 2, 2) + std::pow(altura, 2));
    return base + 2 * lado;
}

// Escala base y altura por el factor
void Triangulo::agrandar(double factor)
{
    base *= factor;
    altura *= factor;
}