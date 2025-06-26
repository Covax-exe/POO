/*
  Asignatura: PROGRAMACIÓN ORIENTADA A OBJETOS (IPOO) 750081M
  Archivo: musico.h
  Fecha creación: 17-octubre-2001
  Fecha última modificación: 09-Noviembre-2014
  Versión: 0.1
  Autor: Angel García Baños
  Modificad por: Cristian Leonardo Ríos López
  Modificad por: Víctor Bucheli
  ESCUELA DE INGENIERÍA DE SISTEMAS Y COMPUTACIÓN
  UniValle
  Clase: Musico
 Responsabilidad:  tocar un instrumento.
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

#ifndef __CLASSMUSICO
#define __CLASSMUSICO
#include "persona.h"
using namespace std;

class Musico : public Persona // Herencia pública de Persona
{
private:
    string instrumento;
    int cant;

public:
    Musico(string nombre); // Constructor de Cartero (es necesario porque el constructor de Persona requiere un argumento)
    void setInstrumento(string instrumento);
    void imprimir(ostream &flujo);
    int cuantas_instrumentos() const;
    void setCantInstrumento(int cant);
};

#endif