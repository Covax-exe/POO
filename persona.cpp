/*
  Asignatura: PROGRAMACIÓN ORIENTADA A OBJETOS (IPOO) 750081M
  Archivo: persona.cpp
  Fecha creación: 30-octubre-2001
  Fecha última modificación: 09-marzo-2014
  Versión: 0.1
  Autor: Angel García Baños
  Modificad por: Cristian Leonardo Ríos López
  Modificad por: Víctor Bucheli
  ESCUELA DE INGENIERÍA DE SISTEMAS Y COMPUTACIÓN
  UniValle
*/

/*
 *   Proyecto: Banda de Músicos
 *   Curso: Fundamentos de Programacion Orientada a Objetos (FPOO)
 *   Universidad del Valle
 *   Autores: [Lina Vanessa Cosme Arce - 202436459], [Whitsell Stiven Diosa Villada - 202439170]
 *   Correo: [lina.cosme@correounivalle.edu.co], [whitsell.diosa@correounivalle.edu.co]
 *   Fecha: Mayo 2025
 */

#include "persona.h"

// Constructor de Persona lanza una exception si el nombre es vacio o de tamaño
// 0
Persona::Persona(string nombre)
{
    if (nombre.size() == 0)
    {
        throw 1;
    }
    this->nombre = nombre;
    age = 0;
}

Persona::~Persona() {}

void Persona::imprimir(ostream &flujo)
{
    if (nombre.size() == 0)
    {
        throw 2;
    }
    flujo << "El nombre es: " << this->nombre;
    flujo << endl;
}
string Persona::getNombre() const { return this->nombre; }

void Persona::setEdad(int age) { this->age = age; }
