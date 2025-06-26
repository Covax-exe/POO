/*
  Asignatura: PROGRAMACIÓN ORIENTADA A OBJETOS (IPOO) 750081M
  Archivo: mariachi.h
  Fecha creación: 17-octubre-2001
  Fecha última modificación: 09-Noviembre-2014
  Versión: 0.1
  Autor: Angel García Baños
  Modificad por: Cristian Leonardo Ríos López
  Modificad por: Víctor Bucheli
  ESCUELA DE INGENIERÍA DE SISTEMAS Y COMPUTACIÓN
  UniValle
  Clase: mariachi
 Responsabilidad:  canta el mariachi.
 Colaboración: hereda de la clase base persona.
*/

/*
 *   Proyecto: Banda de Músicos
 *   Curso: Fundamentos de Programacion Orientada a Objetos (FPOO)
 *   Universidad del Valle
 *   Autores: [Lina Vanessa Cosme Arce - 202436459], [Whitsell Stiven Diosa Villada - 202439170]
 *   Correo: [lina.cosme@correounivalle.edu.co], [whitsell.diosa@correounivalle.edu.co]
 *   Fecha: Mayo 2025
 */

#include "cantante.h"
#ifndef _MARIACHI_H_
#define _MARIACHI_H_

class Mariachi : public Cantante
{
public:
  Mariachi(string nombre);
  ~Mariachi();
  void cantar();

protected:
private:
};
#endif