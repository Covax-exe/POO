/*
  Asignatura: PROGRAMACIÓN ORIENTADA A OBJETOS (IPOO) 750081M
  Archivo: persona.h
  Fecha creación: 17-octubre-2001
  Fecha última modificación: 09-Noviembre-2014
  Versión: 0.1
  Autor: Angel García Baños
  Modificad por: Cristian Leonardo Ríos López
  Modificad por: Víctor Bucheli
  ESCUELA DE INGENIERÍA DE SISTEMAS Y COMPUTACIÓN
  UniValle
  Clase: Persona
  Responsabilidad: tiene un nombre y tiene actitudes para tocar un instrumento o para escuchar del auditorio.
  Colaboración:
*/

/*
 *   Proyecto: Banda de Músicos
 *   Curso: Fundamentos de Programacion Orientada a Objetos (FPOO)
 *   Universidad del Valle
 *   Autores: [Lina Vanessa Cosme Arce - 202436459], [Whitsell Stiven Diosa Villada - 202439170]
 *   Correo: [lina.cosme@correounivalle.edu.co], [whitsell.diosa@correounivalle.edu.co]
 *   Fecha: Mayo 2025
 */

#ifndef __CLASSPERSONA
#define __CLASSPERSONA

#include <string>
#include <iostream>
#include <exception>
#include <vector>

using namespace std;

class Persona
{
private:
public:
  Persona(string nombre);
  ~Persona();
  virtual void imprimir(ostream &flujo);
  string getNombre() const;
  void setEdad(int age);

protected:
  string nombre;
  int age;
};

#endif