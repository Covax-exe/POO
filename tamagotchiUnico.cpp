/*
 * @file tamagotchiUnico.cpp
 * @brief Implementación de la clase mascota para simular una mascota virtual (tamagotchi).
 *
 * @details En este archivo se implementan los métodos de la clase mascota,
 * incluyendo la nueva característica de llenura para mejorar la interacción con la mascota.
 * @authors [Lina Vanessa Cosme Arce - 2436456] [Whitsell Stiven Diosa Villada - 2439170]
 * @mail [lina.cosme@correounivalle.edu.co] [whitsell.diosa@correounivalle.edu.co]
 * @date 2025-03-22
 * @version 1.23.6
 *
 * @comentario: Se usó la librería <string> para el manejo de este tipo de datos.
 * Además, Se utilizó raw strings facilitando la inclusión de caracteres especiales y la estructura visual; se investigó en https://en.cppreference.com/w/cpp/language/string_literal.
 */

#include "tamagotchiUnico.h"
#include <iostream>
#include <string>
using namespace std;

// Constructor: Inicializa los atributos, incluido 'llenura'
mascota::mascota(string nombre)
{
    mascota::nombre = nombre;
    mascota::tipo = "n/a";
    mascota::comer = false;
    mascota::llenura = 5; // Inicializamos llenura en 5
}

// Setters y getters
void mascota::setNombre(string nombre)
{
    mascota::nombre = nombre;
}
string mascota::getNombre()
{
    return mascota::nombre;
}

void mascota::setTipo(string tipo)
{
    mascota::tipo = tipo;
}
string mascota::getTipo()
{
    return mascota::tipo;
}

void mascota::setComer(bool comer)
{
    mascota::comer = comer;
}
bool mascota::getComer()
{
    return mascota::comer;
}

// Setter para llenura
void mascota::setLlenura(int nivel)
{
    if (nivel >= 0 && nivel <= 10)
    {
        mascota::llenura = nivel;
    }
    else if (nivel < 0)
    {
        mascota::llenura = 0;
    }
    else if (nivel > 10)
    {
        mascota::llenura = 10;
    }
}

// Getter para llenura
int mascota::getLlenura()
{
    return mascota::llenura;
}

// Método: Saludar
void mascota::saludar()
{
    if (mascota::llenura > 0)
    {
        mascota::llenura--; // Disminuye llenura al saludar
        cout << "Hola, soy tu mascota " << mascota::nombre << endl;
        cout << R"(
          _...-""""""-..._
         /  _---_   _---_ \
        |0    O       O    0|
          \       ^       /    
           \    \___/    /
            \_____n_____/
        )" << endl;
    }
    else
    {
        cout << mascota::nombre << ": Estoy demasiado hambriento para saludarte. ¿Me das de comer?\n";
    }
}

// Método: Revisar el estado de llenura (siComio)
void mascota::siComio()
{
    if (mascota::llenura >= 7)
    {
        mascota::llenura--; // O, si prefieres, puedes no modificar la llenura al revisar
        cout << mascota::nombre << ": Mi nivel de llenura es: " << mascota::llenura << " no mas comida pls :(." << endl;
        cout << R"(
           !  1
        _...-""""""-..._!  !   
       /  -__-     -__-  \    NoOoo00Oo00!!!
      |0    #        #   0|   \___    
        \      ___      /     /           !
         \    /   \    /   0 /      0    
          \___________/_____/      1
        )" << endl;
    }
    else if (mascota::llenura > 4 && mascota::llenura < 7)
    {
        cout << mascota::nombre << ": Estoy ni taaaan lleno, ni taaaan hambriento, estoy ralajadito uwu." << endl;
        cout << R"(
                             <3

      <3
   ___________        __________ 
  /           \______/           \
/                                  \
|                   <3             | 
|               ___                |
|              /_ _\               |
 \     <3      \_U_/              /
   \           /| |\            /
     \       _/ /_\ \_        /
       \      _/   \_       /
         \               /
            \         /         <3
<3             \   /
                 _
        )" << endl;
    }
    else
    {
        cout << mascota::nombre << ": Creo que morire del hambre, pesimo amo!!" << endl;
        cout << R"(
        ____        0
       / x  x\
      |   ___|    0
       \____/
        |  |
         | |_______
        /    \  __   \         0
       / \    \     \_  
 \____/   \     \_____________|  
 \_  __  /       ___         _ _\
         /  \___/
        /   /       0          0
         \
          \  \
          /  /          0
           _
        )" << endl;
    }
}

// Método: Dar la pata
void mascota::darLaPata()
{
    if (mascota::llenura > 0)
    {
        mascota::llenura--; // Disminuye llenura
        cout << mascota::nombre << ": Toma patadon, Tomaaaaa!!!!" << endl;
        cout << R"(
            _   _   _   !
           | | | | | |  _          !
           | | | | | | | |
        __ | |_| |_| |/  /
       \  \             /
       \ _  \ BOOM!!   /    !
          \           /
           \_________/
                 \
            !     \
        !         /
            ___  /
           /_ _\/       !
           \_U_/
           /| |   !
         _/ /_\
          _/   \_
        )" << endl;
    }
    else
    {
        cout << mascota::nombre << ": Estoy demasiado débil para dar la pata, necesito comer.\n";
    }
}