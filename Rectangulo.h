/*
 * Asignatura: PROGRAMACIÓN ORIENTADA A OBJETOS (IPOO) 750015C
 * Archivo: Rectangulo.h
 * Fecha creación: 10-mayo-2025
 * Versión: 0.1
 * Autores: Lina Vanessa Cosme Arce, Whitsell Stiven Diosa Villada
 *
 * ESCUELA DE INGENIERÍA DE SISTEMAS Y COMPUTACIÓN
 * UniValle
 * Clase: Rectangulo
 * Responsabilidad: calcula el area, perimetro y agranda el rectangulo.
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

#ifndef RECTANGULO_H
#define RECTANGULO_H

#include "Figura.h" // Hereda de Figura

// Clase Rectangulo, derivada de Figura
class Rectangulo : public Figura
{
protected:
    double base, alto; // Dimensiones del rectangulo

public:
    // Constructor
    Rectangulo(double x, double y, double base, double alto);

    // Metodos sobrescritos
    double area() const override;
    double perimetro() const override;
    void agrandar(double factor) override;
};

#endif // RECTANGULO_H