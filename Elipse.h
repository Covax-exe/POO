/*
 * Asignatura: PROGRAMACIÓN ORIENTADA A OBJETOS (IPOO) 750015C
 * Archivo: Elipse.h
 * Fecha creación: 10-mayo-2025
 * Versión: 0.1
 * Autores: Lina Vanessa Cosme Arce, Whitsell Stiven Diosa Villada
 *
 * ESCUELA DE INGENIERÍA DE SISTEMAS Y COMPUTACIÓN
 * UniValle
 * Clase: Elipse
 * Responsabilidad: calcula el area, perimetro y agranda la elipse.
 * Colaboración: hereda de la clase base Figura.
 */

/*
 *   Proyecto: Figuras Geometricas
 *   Curso: Fundamentos de Programacion Orientada a Objetos (FPOO)
 *   Universidad del Valle
 *   Autores: [Lina Vanessa Cosme Arce - 202436459], [Whitsell Stiven Diosa Villada - 202439170]
 *   Correo: [lina.cosme@correounivalle.edu.co], [whitsell.diosa@correounivalle.edu.co]
 *   Fecha: Mayo 2025
 */

#ifndef ELIPSE_H
#define ELIPSE_H

#include "Figura.h" // Incluye la clase base Figura

// Clase Elipse, derivada de Figura
class Elipse : public Figura
{
protected:
    double a, b; // Semiejes mayor (a) y menor (b)

public:
    // Constructor
    Elipse(double x, double y, double a, double b);

    // Metodos sobrescritos
    double area() const override;
    double perimetro() const override;
    void agrandar(double factor) override;
};

#endif // ELIPSE_H