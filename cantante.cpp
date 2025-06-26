/*
  Asignatura: PROGRAMACIÓN ORIENTADA A OBJETOS (IPOO) 750081M
  Archivo: cantante.cpp
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

#include "cantante.h"
Cantante::Cantante(string nombre) : Persona(nombre)
{
    this->nombreArtistico = "nn";
    this->cantaBien = true;
}
void Cantante::setnombreArtistico(string nombreArtistico)
{
    this->nombreArtistico = nombreArtistico;
}
void Cantante::setcantaBien(bool cantaBien)
{
    this->cantaBien = cantaBien;
}

void Cantante::imprimir(ostream &flujo)
{
    if (nombreArtistico.size() == 0)
    {
        throw 5;
    }
    flujo << "El nombre es: " << this->getNombre();
    flujo << endl;
    flujo << "El nombre artistico es: " << this->nombreArtistico;
    flujo << endl;
    flujo << "La edad es: " << this->age;
    flujo << endl;
    if (cantaBien)
        flujo << "Canta bien" << endl;
    else
        flujo << "Canta mal" << endl;
}

void Cantante::cantar()
{
    cout << "YO CANTO" << endl;
}