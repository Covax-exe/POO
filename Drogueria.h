#ifndef DROGUERIA_H
#define DROGUERIA_H

#include <vector>
#include "Producto.h"   // Para manejar productos
#include "Categoria.h"  // Si es necesario usar categorías
#include "Cliente.h"    // No es utilizado directamente en este ejemplo, pero se incluye

// Declaración de la clase Drogueria que administra los productos.
class Drogueria {
private:
    std::vector<Producto> productos;  // Vector que almacena los productos registrados
public:
    // Constructor de la clase Drogueria.
    Drogueria();

    // Registra (agrega) un producto al vector de productos.
    void registrarProducto(const Producto &auxProducto);

    // Busca productos cuyo nombre contenga la subcadena proporcionada.
    std::vector<Producto> buscarPorNombre(const std::string &nombre) const;

    // Busca productos con un precio exacto.
    std::vector<Producto> buscarPorPrecio(double precio) const;

    // Verifica y muestra en consola los productos cuyo stock es menor que el stock mínimo especificado.
    void verificarStockMinimo(int stockMinimo) const;

    // Retorna una referencia constante al vector de productos registrados.
    const std::vector<Producto>& getProductos() const;
};

#endif // DROGUERIA_H