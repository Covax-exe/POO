/*
 * Asignatura: PROGRAMACIÓN ORIENTADA A OBJETOS (IPOO) 750015C
 * Archivo: Triangulo.h
 * Fecha creación: 10-mayo-2025
 * Versión: 0.1
 * Autores: Lina Vanessa Cosme Arce, Whitsell Stiven Diosa Villada
 *
 * ESCUELA DE INGENIERÍA DE SISTEMAS Y COMPUTACIÓN
 * UniValle
 * Clase: Triangulo
 * Responsabilidad: calcula el area, perimetro y agranda el triangulo.
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

#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "Figura.h" // Herencia de la clase base Figura

// Clase Triangulo, derivada de Figura
class Triangulo : public Figura
{
protected:
    double base, altura; // Dimensiones del triangulo

public:
    // Constructor
    Triangulo(double x, double y, double base, double altura);

    // Metodos sobrescritos
    double area() const override;
    double perimetro() const override;
    void agrandar(double factor) override;
};

#endif // TRIANGULO_H