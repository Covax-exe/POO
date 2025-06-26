#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <string>
#include <vector>
#include "Categoria.h"  // Necesario para declarar el vector de punteros a Categoria

// Declaración de la clase Producto que representa un producto en la droguería.
class Producto {
private:
    int id;                              // Identificador único del producto
    std::string nombre;                  // Nombre del producto
    double precio;                       // Precio del producto
    int cantidadStock;                   // Cantidad en stock del producto
    std::vector<Categoria *> categorias; // Lista de categorías asociadas al producto

public:
    // Constructor de la clase Producto
    Producto(int id, const std::string &nombre, double precio, int cantidadStock);

    // Métodos getters para obtener información del producto
    int getId() const;
    const std::string& getNombre() const;
    double getPrecio() const;
    int getCantidadStock() const;

    // Métodos para gestionar categorías
    void agregarCategoria(Categoria *auxCategoria);
    void eliminarCategoria(Categoria *auxCategoria);

    // Verifica si el stock es menor que el stock mínimo especificado.
    // Se declara "const" para poder utilizarlo en objetos constantes.
    bool verificarStockMinimo(int stockMinimo) const;

    // Actualiza la cantidad de stock del producto (se suma el valor).
    void actualizarStock(int cantidad);

    // Muestra las categorías del producto.
    // Lo declaramos como const para no modificar el objeto.
    void verCategorias() const;
};

#endif // PRODUCTO_H