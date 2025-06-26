/*
  Asignatura: PROGRAMACIÓN ORIENTADA A OBJETOS (IPOO) 750081M
  Archivo: espectador.h
  Fecha creación: 17-octubre-2001
  Fecha última modificación: 09-Noviembre-2014
  Versión: 0.1
  Autor: Angel García Baños
  Modificad por: Cristian Leonardo Ríos López
  Modificad por: Víctor Bucheli
  ESCUELA DE INGENIERÍA DE SISTEMAS Y COMPUTACIÓN
  UniValle
  Clase: espectador
 Responsabilidad: le gusta o no le gusta  la banda.
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

#ifndef _ESPECTADOR_H_
#define _ESPECTADOR_H_
#include "persona.h"

class Espectador : public Persona
{
public:
    Espectador(string nombre);
    ~Espectador();
    void setGustarBanda(bool gusto);
    void imprimir(ostream &flujo);

protected:
private:
    bool gusto;
};
#endif