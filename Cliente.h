#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <vector>
#include "Producto.h"  // Para poder usar punteros a Producto

// Declaración de la clase Cliente que representa a un cliente de la droguería.
class Cliente {
private:
    std::string nombre;                         // Nombre del cliente
    std::vector<Producto *> productosComprados; // Vector de punteros a productos comprados (o en la canasta)

public:
    // Constructor que inicializa el cliente con un nombre.
    Cliente(const std::string &nombre);

    // Método para obtener el nombre del cliente.
    std::string getNombre() const;

    // Agrega un producto (por puntero) a la canasta del cliente.
    void agregarProductoComprado(Producto *auxProducto);

    // Muestra los productos que el cliente ha comprado (o agregado a la canasta).
    void verCanastadeCompras() const;
};

#endif // CLIENTE_H