/*
 * @file Categoria.cpp
 * @brief Implementacion de la clase Categoria, que representa una categoria a la que puede pertenecer un producto.
 *
 * @details Este archivo contiene la implementacion de los metodos de la clase Categoria, incluyendo la asignacion y obtencion del nombre de la categoria.
 *
 * @authors [Lina Vanessa Cosme Arce - 2436456] [Whitsell Stiven Diosa Villada - 2439170]
 * @mail [lina.cosme@correounivalle.edu.co] [whitsell.diosa@correounivalle.edu.co]
 * @date 2025-04-03
 * @version 1.0
 *
 * @comentario:
 */

/*
 *   Proyecto: Drogueria
 *   Curso: Fundamentos de Programacion Orientada a Objetos (FPOO)
 *   Universidad del Valle
 *
 *   Descripcion:
 *   Este proyecto gestiona una Drogueria, proporcionando
 *   funcionalidades para registrar, buscar y analizar la informacion de la drogueria.
 *
 *   Autores: [Lina Vanessa Cosme Arce - 202436459], [Whitsell Stiven Diosa Villada - 202439170]
 *   Correo: [lina.cosme@correounivalle.edu.co], [whitsell.diosa@correounivalle.edu.co]
 *   Fecha: Abril 2025
 */

#include "Categoria.h"

// Constructor: inicializa la categoría asignándole el nombre recibido.
Categoria::Categoria(const std::string &categoria)
    : categoria(categoria)
{
}

// Retorna el nombre de la categoría.
std::string Categoria::getCategoria() const
{
    return categoria;
}