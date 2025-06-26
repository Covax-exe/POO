/*
 * @file Drogueria.cpp
 * @brief Implementacion de la clase Drogueria, que administra productos y permite su gestion.
 *
 * @details Este archivo contiene la implementacion de los metodos de la clase Drogueria,
 * incluyendo el registro, busqueda y verificacion de stock de los productos.
 *
 * @authors [Lina Vanessa Cosme Arce - 2436456] [Whitsell Stiven Diosa Villada - 2439170]
 * @mail [lina.cosme@correounivalle.edu.co] [whitsell.diosa@correounivalle.edu.co]
 * @date 2025-04-03
 * @version 1.0
 *
 * @comentario: Se consulto cppreference para el manejo de std::vector.
 * Referencia: https://en.cppreference.com/w/cpp/container/vector
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

#include "Drogueria.h"
#include <iostream>

// Constructor de la clase Drogueria.
Drogueria::Drogueria()
{
    // El vector "productos" se inicializa vacío automáticamente.
}

// Método para registrar un producto (se agrega al vector "productos").
void Drogueria::registrarProducto(const Producto &auxProducto)
{
    productos.push_back(auxProducto);
}

// Método que busca productos cuyo nombre contenga la subcadena especificada.
std::vector<Producto> Drogueria::buscarPorNombre(const std::string &nombre) const
{
    std::vector<Producto> encontrados; // Vector donde se almacenarán los productos encontrados.
    for (const auto &prod : productos)
    {
        // Se verifica si la subcadena "nombre" está presente en el nombre del producto.
        if (prod.getNombre().find(nombre) != std::string::npos)
        {
            encontrados.push_back(prod);
        }
    }
    return encontrados;
}

// Método que busca productos con un precio exacto.
std::vector<Producto> Drogueria::buscarPorPrecio(double precio) const
{
    std::vector<Producto> encontrados; // Vector para almacenar los productos que coincidan.
    for (const auto &prod : productos)
    {
        if (prod.getPrecio() == precio)
        {
            encontrados.push_back(prod);
        }
    }
    return encontrados;
}

// Método que recorre cada producto y muestra aquellos cuyo stock es menor que el stock mínimo.
void Drogueria::verificarStockMinimo(int stockMinimo) const
{
    for (const auto &prod : productos)
    {
        // Se invoca "verificarStockMinimo" (declared as const) en el objeto constante "prod".
        if (prod.verificarStockMinimo(stockMinimo))
        {
            std::cout << "El producto \"" << prod.getNombre()
                      << "\" tiene stock bajo: " << prod.getCantidadStock() << "\n";
        }
    }
}

// Retorna una referencia constante al vector de productos registrados.
const std::vector<Producto> &Drogueria::getProductos() const
{
    return productos;
}