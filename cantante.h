/*
  Asignatura: PROGRAMACIÓN ORIENTADA A OBJETOS (IPOO) 750081M
  Archivo: cantante.h
  Fecha creación: 17-octubre-2001
  Fecha última modificación: 09-Noviembre-2014
  Versión: 0.1
  Autor: Angel García Baños
  Modificad por: Cristian Leonardo Ríos López
  Modificad por: Víctor Bucheli
  ESCUELA DE INGENIERÍA DE SISTEMAS Y COMPUTACIÓN
  UniValle
  Clase: cantante
 Responsabilidad:  canta bien o mal.
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

#ifndef __CLASSCANTANTE
#define __CLASSCANTANTE
#include "persona.h"
using namespace std;

class Cantante : public Persona // Herencia pública de Persona
{
private:
    bool cantaBien;
    string nombreArtistico;

public:
    Cantante(string nombre); // Constructor de Cantante (es necesario porque el constructor de Persona requiere un argumento)
    void setcantaBien(bool cantaBien);
    void setnombreArtistico(string nombreArtistico);
    void imprimir(ostream &flujo);
    virtual void cantar();
};

#endif