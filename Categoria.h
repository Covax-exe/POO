#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <string>

// Declaración de la clase Categoria, que representa una categoría de producto.
class Categoria {
private:
    std::string categoria;  // Nombre de la categoría
public:
    // Constructor que inicializa la categoría usando el nombre dado.
    Categoria(const std::string &categoria);

    // Retorna el nombre de la categoría.
    std::string getCategoria() const;
};

#endif // CATEGORIA_H