#include "Controlador.h"
#include <iostream>

Controlador::Controlador() : laberinto(), agente(&laberinto) {} // Enlaza objetos

void Controlador::ejecutar()
{
    Vista::mostrarLaberinto(laberinto); // Muestra el laberinto
    if (agente.mover())
        std::cout << "\n\u00a1El agente encontró la salida! YAYYY!!! :D \n"; // Éxito ☝🤓 ヾ(≧ ▽ ≦)ゝ
    else
        std::cout << "\nEl agente no encontró la salida. NAOOO!! :c\n"; // Fallo 👊😔  o(TヘTo)
}