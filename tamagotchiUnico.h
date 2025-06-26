/*
 * @file tamagotchiUnico.h
 * @brief Es el archivo donde se declara la clase de mascota para simular una mascota virtual (tamagotchi).
 *
 * @details A comparación del archivo.h original en este se le añadió una nueva característica a la mascota,
 * llenura, con el fin de hacer la interacción con la mascota más natural, es decir, que le dé hambre o que esté lleno.
 * @authors [Lina Vanessa Cosme Arce - 2436456] [Whitsell Stiven Diosa Villada - 2439170]
 * @mail [lina.cosme@correounivalle.edu.co] [whitsell.diosa@correounivalle.edu.co]
 * @date 2025-03-22
 * @version 1.23.6
 *
 * @comentario: Se utilizó la librería <string> para manejar datos textuales y permitir una mejor gestión del nombre y tipo de la mascota.
 * Se utilizó el encapsulamiento para proteger los atributos de la mascota, se definieron métodos accesores para modificar su estado.
 */
/*
 * Clase: Tamagotchi
 * Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
 * Universidad del Valle
 *
 * Información CRC:
 *
 * Clase: Tamagotchi
 * Responsabilidades:
 *    - Representar una mascota virtual con nombre, tipo y nivel de llenura.
 *    - Permitir la interacción con la mascota a través de saludos, alimentación y trucos.
 *    - Indicar el estado de llenura de la mascota.
 *
 * Colaboradores:
 *    -
 *
 * Este es un proyecto del curso FPOO de la Universidad del Valle,
 * desarrollado con fines académicos. Puede ser utilizado con fines
 * educativos dando los créditos de la autoría.
 */

#ifndef TAMAGOTCHI_H
#define TAMAGOTCHI_H

#include <string>
using namespace std;

class mascota
{
private:
    int llenura; // Nuevo Atributo para el nivel de llenura
    string nombre;
    string tipo;
    bool comer;

public:
    // Constructor
    mascota(string nombre);

    // Setters
    void setNombre(string nombre);
    void setTipo(string tipo);
    void setComer(bool comer);
    void setLlenura(int nivel); // Declaración del setter de llenura

    // Getters
    string getNombre();
    string getTipo();
    bool getComer();
    int getLlenura(); // Declaración del getter de llenura

    // Funciones
    void saludar();
    void siComio();
    void darLaPata();
};

#endif // TAMAGOTCHI_H