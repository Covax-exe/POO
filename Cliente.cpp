/*
 * @file Cliente.cpp
 * @brief Implementación de la clase Cliente, que representa a un cliente de la droguería.
 *
 * @details Este archivo contiene la implementación de los métodos de la clase Cliente, incluyendo la gestión de productos comprados y la visualización de la canasta de compras.
 *
 * @authors [Lina Vanessa Cosme Arce - 2436456] [Whitsell Stiven Diosa Villada - 2439170]
 * @mail [lina.cosme@correounivalle.edu.co] [whitsell.diosa@correounivalle.edu.co]
 * @date 2025-04-03
 * @version 1.0
 *
 * @comentario: Se consultó cppreference para el manejo de std::vector.
 * Referencia: https://en.cppreference.com/w/cpp/container/vector
 */

/*
 *   Proyecto: Drogueria
 *   Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
 *   Universidad del Valle
 *
 *   Descripción:
 *   Este proyecto gestiona una Drogueria, proporcionando
 *   funcionalidades para registrar, buscar y analizar la información de la drogueria.
 *
 *   Autores: [Lina Vanessa Cosme Arce - 202436459], [Whitsell Stiven Diosa Villada - 202439170]
 *   Correo: [lina.cosme@correounivalle.edu.co], [whitsell.diosa@correounivalle.edu.co]
 *   Fecha: Abril 2025
 */

#include "Cliente.h"
#include <iostream>

 // Constructor que inicializa el nombre del cliente
Cliente::Cliente(const std::string &nombre)
    : nombre(nombre)
{
}

 // Método para obtener el nombre del cliente
std::string Cliente::getNombre() const {
    return nombre;
}

 // Agrega un producto al vector de productos comprados
 void Cliente::agregarProductoComprado(Producto *auxProducto) {
    productosComprados.push_back(auxProducto);
}

 // Muestra los productos que el cliente ha comprado
void Cliente::verCanastadeCompras() const {
    std::cout << "Productos comprados por " << nombre << ":\n";
     if (productosComprados.empty()) {  // Verifica si la canasta está vacía
        std::cout << "No hay productos en la canasta.\n";
        return;
    }
     // Recorre e imprime el nombre de cada producto en la canasta
     for (const Producto *producto : productosComprados) {
        std::cout << "- " << producto->getNombre() << "\n";
    }
}