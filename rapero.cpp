/*
  Asignatura: PROGRAMACIÓN ORIENTADA A OBJETOS (IPOO) 750081M
  Archivo: rapero.cpp
  Fecha creación: 30-octubre-2001
  Fecha última modificación: 09-marzo-2014
  Versión: 0.1
  Autor: Angel García Baños
  Modificado por: Cristian Leonardo Ríos López
  Modificado por: Víctor Bucheli
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

#include <iostream>
using namespace std;
#include "rapero.h"

Rapero::Rapero(string nombre) : Cantante(nombre) {}

Rapero::~Rapero() {}

void Rapero::cantar()
{
  cout << "Uh, sama lamaa duma lamaa you assuming I'm a human What I gotta do "
          "to get it through to you I'm superhuman Innovative and I'm made of "
          "rubber"
       << endl;
}