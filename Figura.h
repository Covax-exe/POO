/*
 * Asignatura: PROGRAMACIÓN ORIENTADA A OBJETOS (IPOO) 750015C
 * Archivo: Figura.h
 * Fecha creación: 10-mayo-2025
 * Versión: 0.1
 * Autores: Lina Vanessa Cosme Arce, Whitsell Stiven Diosa Villada
 *
 * ESCUELA DE INGENIERÍA DE SISTEMAS Y COMPUTACIÓN
 * UniValle
 * Clase: Figura
 * Responsabilidad: calcula el area, perimetro y agranda las figuras geometricas.
 * Colaboración:
 */

/*
 *   Proyecto: Figuras Geometricas
 *   Curso: Fundamentos de Programacion Orientada a Objetos (FPOO)
 *   Universidad del Valle
 *   Autores: [Lina Vanessa Cosme Arce - 202436459], [Whitsell Stiven Diosa Villada - 202439170]
 *   Correo: [lina.cosme@correounivalle.edu.co], [whitsell.diosa@correounivalle.edu.co]
 *   Fecha: Mayo 2025
 */

#ifndef FIGURA_H
#define FIGURA_H

// Clase abstracta base para todas las figuras geometricas
class Figura
{
protected:
    double x, y; // Coordenadas (x, y) del centro o posicion de la figura

public:
    // Constructor: inicializa x y y
    Figura(double x, double y) : x(x), y(y) {}
    // Destructor virtual: permite destruccion correcta de objetos derivados :)
    virtual ~Figura() {}

    // Metodos virtuales: deben ser implementados en clases hijas
    virtual double area() const = 0;          // Calculo del area
    virtual double perimetro() const = 0;     // Calculo del perimetro
    virtual void agrandar(double factor) = 0; // Escala la figura
};

#endif // FIGURA_H