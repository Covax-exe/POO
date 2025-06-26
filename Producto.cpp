/*
 * @file Producto.cpp
 * @brief Implementacion de la clase Producto, que representa un articulo con atributos basicos.
 *
 * @details Este archivo contiene la implementacion de los metodos de la clase Producto, incluyendo sus atributos, metodos para obtener informacion, gestion de stock y manejo de categorias.
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
#include "Producto.h"
#include <iostream>
#include <algorithm>

// Constructor de la clase Producto
Producto::Producto(int _id, const std::string &_nombre, double _precio, int _cantidadStock)
    : id(_id), nombre(_nombre), precio(_precio), cantidadStock(_cantidadStock)
{
}

// Retorna el ID del producto
int Producto::getId() const {
    return id;
}

// Retorna el nombre del producto
const std::string& Producto::getNombre() const {
    return nombre;
}

// Retorna el precio del producto
double Producto::getPrecio() const {
    return precio;
}

// Retorna la cantidad en stock del producto
int Producto::getCantidadStock() const {
    return cantidadStock;
}

// Agrega una categoría al producto
void Producto::agregarCategoria(Categoria *auxCategoria) {
    // Añade la categoría al vector de categorías
    categorias.push_back(auxCategoria);
}

// Elimina una categoría del producto
void Producto::eliminarCategoria(Categoria *auxCategoria) {
    // Se utiliza std::remove para reorganizar y eliminar el puntero de la categoría
    categorias.erase(std::remove(categorias.begin(), categorias.end(), auxCategoria), categorias.end());
}

// Verifica si el stock es menor que el mínimo especificado.
// Nota: Este método está marcado con "const" para poder llamarlo desde objetos constantes.
bool Producto::verificarStockMinimo(int stockMinimo) const {
    return cantidadStock < stockMinimo;
}

// Actualiza la cantidad de stock del producto
void Producto::actualizarStock(int cantidad) {
    cantidadStock += cantidad;
}

// Muestra las categorías del producto
void Producto::verCategorias() const {
    std::cout << "Categorias del producto " << nombre << ":\n";
    // Recorre el vector de categorías e imprime el nombre de cada categoría
    for (Categoria *categoria : categorias) {
        std::cout << "- " << categoria->getCategoria() << std::endl;
    }
}