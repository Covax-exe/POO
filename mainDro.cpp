/*
 * @file main.cpp
 * @brief Programa principal para la gestion de una drogueria.
 *
 * @details Este archivo contiene la funcion main, que permite interactuar con
 * el sistema de gestion de productos de la drogueria. A traves de un menu, los
 * usuarios pueden registrar productos, buscar por nombre o precio, verificar el stock
 * y administrar la canasta de compras de un cliente.
 *
 * @authors [Lina Vanessa Cosme Arce - 2436456] [Whitsell Stiven Diosa Villada - 2439170]
 * @mail [lina.cosme@correounivalle.edu.co] [whitsell.diosa@correounivalle.edu.co]
 * @date 2025-04-03
 * @version 1.0
 *
 * @referencias:
 * C++ Reference: https://en.cppreference.com
 * Learn C++: https://www.learncpp.com
 * GeeksforGeeks (C++): https://www.geeksforgeeks.org/c-plus-plus/
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

#include <iostream>    // Incluye la biblioteca para entrada/salida estándar (std::cout, std::cin)
#include "Drogueria.h" // Incluye la definición de la clase Drogueria
#include "Producto.h"  // Incluye la definición de la clase Producto
#include "Categoria.h" // Incluye la definición de la clase Categoria
#include "Cliente.h"   // Incluye la definición de la clase Cliente

using namespace std; // Permite usar nombres estándar sin "std::" (por ejemplo, cout en vez de std::cout)

int main()
{
    // Crear instancia de la droguería, que gestionará el registro y búsqueda de productos.
    Drogueria miDrogueria;

    // Crear una categoría por defecto llamada "Medicamentos".
    // Esta categoría se asignará a los productos que se registren.
    Categoria categoriaDef("Medicamentos");

    // Crear un cliente, en este ejemplo "Juan Perez", para simular la compra de productos.
    Cliente cliente("Juan Perez");

    int opcion = -1; // Variable que almacenará la opción elegida por el usuario. Se inicializa con -1 para entrar al bucle.

    // Bucle principal del menú. Se repetirá hasta que el usuario ingrese 0 para salir.
    while (opcion != 0)
    {
        // Mostrar el menú principal.
        cout << "\n=== MENU ===\n";
        cout << "1. Registrar Producto\n";                        // Opción 1: Registrar un nuevo producto.
        cout << "2. Mostrar Productos\n";                         // Opción 2: Mostrar todos los productos registrados.
        cout << "3. Verificar Stock Minimo\n";                    // Opción 3: Mostrar productos con stock bajo un umbral.
        cout << "4. Agregar Producto a la Canasta del Cliente\n"; // Opción 4: Agregar un producto a la "canasta" del cliente.
        cout << "5. Mostrar Canasta de Compras del Cliente\n";    // Opción 5: Ver los productos en la canasta del cliente.
        cout << "0. Salir\n";                                     // Opción 0: Salir del programa.
        cout << "Seleccione una opcion: ";                        // Se pide al usuario que elija una opción.

        cin >> opcion;          // Lee la opción ingresada por el usuario.
        cin.ignore(1000, '\n'); // Limpia el buffer de entrada (descarta hasta 1000 caracteres o hasta encontrar un '\n').

        // Procesa la opción elegida mediante una estructura if/else.
        if (opcion == 1)
        {                  // Opción 1: Registrar Producto.
            int id, stock; // Variables para almacenar el ID y la cantidad en stock del producto.
            double precio; // Variable para almacenar el precio del producto.
            string nombre; // Variable para almacenar el nombre del producto.

            cout << "\nRegistrar Producto\n"; // Encabezado para la opción de registro.
            cout << "Ingrese ID: ";           // Solicita el ID del producto.
            cin >> id;                        // Lee el ID.
            cin.ignore(1000, '\n');           // Limpia el buffer de entrada.

            cout << "Ingrese Nombre: "; // Solicita el nombre del producto.
            getline(cin, nombre);       // Lee el nombre completo (puede contener espacios).

            cout << "Ingrese Precio: "; // Solicita el precio del producto.
            cin >> precio;              // Lee el precio.

            cout << "Ingrese Stock: "; // Solicita la cantidad en stock del producto.
            cin >> stock;              // Lee el stock.
            cin.ignore(1000, '\n');    // Limpia el buffer después de la lectura.

            // Se crea un objeto Producto con los datos ingresados.
            Producto nuevoProducto(id, nombre, precio, stock);
            // Se asigna la categoría "Medicamentos" al producto.
            nuevoProducto.agregarCategoria(&categoriaDef);
            // Se registra el producto en la droguería.
            miDrogueria.registrarProducto(nuevoProducto);
            cout << "Producto registrado.\n"; // Informa al usuario que el producto se registró correctamente.
        }
        else if (opcion == 2)
        { // Opción 2: Mostrar Productos.
            // Se obtiene la lista de productos registrados en la droguería.
            const auto &productos = miDrogueria.getProductos();
            cout << "\nLista de Productos:\n"; // Encabezado para la lista de productos.
            // Se recorre la lista e imprime la información de cada producto.
            for (const auto &prod : productos)
            {
                cout << "ID: " << prod.getId()
                     << " | Nombre: " << prod.getNombre()
                     << " | Precio: " << prod.getPrecio()
                     << " | Stock: " << prod.getCantidadStock() << "\n";
            }
        }
        else if (opcion == 3)
        {                                         // Opción 3: Verificar Stock Minimo.
            int stockMin;                         // Variable para almacenar el valor de stock mínimo ingresado por el usuario.
            cout << "\nVerificar Stock Minimo\n"; // Encabezado para la verificación de stock.
            cout << "Ingrese el stock minimo: ";  // Solicita el umbral de stock.
            cin >> stockMin;                      // Lee el valor ingresado.
            cin.ignore(1000, '\n');               // Limpia el buffer de entrada.
            // Llama al método para verificar y mostrar productos con stock inferior al umbral.
            miDrogueria.verificarStockMinimo(stockMin);
        }
        else if (opcion == 4)
        {                                                // Opción 4: Agregar Producto a la Canasta del Cliente.
            int idBuscar;                                // Variable para almacenar el ID del producto que se desea agregar.
            cout << "\nAgregar Producto a la Canasta\n"; // Encabezado para agregar productos.
            cout << "Ingrese el ID del producto: ";      // Solicita el ID del producto.
            cin >> idBuscar;                             // Lee el ID.
            cin.ignore(1000, '\n');                      // Limpia el buffer de entrada.

            bool encontrado = false; // Bandera para determinar si se encontró el producto.
            // Obtiene la lista de productos registrados.
            const auto &productos = miDrogueria.getProductos();
            // Recorre la lista para buscar el producto con el ID ingresado.
            for (const auto &prod : productos)
            {
                if (prod.getId() == idBuscar)
                { // Si el producto tiene el ID buscado...
                    // Se utiliza const_cast para obtener un puntero al producto (ya que los productos están almacenados por valor)
                    Producto *prodPtr = const_cast<Producto *>(&prod);
                    // Se agrega el producto a la canasta del cliente.
                    cliente.agregarProductoComprado(prodPtr);
                    cout << "Producto agregado a la canasta.\n";
                    encontrado = true; // Se marca que el producto fue encontrado.
                    break;             // Se abandona el bucle al encontrarse el producto.
                }
            }
            // Si no se encontró el producto, se informa al usuario.
            if (!encontrado)
            {
                cout << "Producto no encontrado.\n";
            }
        }
        else if (opcion == 5)
        {                                      // Opción 5: Mostrar Canasta de Compras del Cliente.
            cout << "\nCanasta de Compras:\n"; // Encabezado para la canasta.
            // Se llama al método del cliente para mostrar los productos en la canasta.
            cliente.verCanastadeCompras();
        }
        else if (opcion == 0)
        {                              // Opción 0: Salir del programa.
            cout << "\nSaliendo...\n"; // Informa que se saldrá del programa.
        }
        else
        {                                   // Si la opción ingresada no corresponde a ninguna válida.
            cout << "\nOpción inválida.\n"; // Informa al usuario que la opción no es válida.
        }

    } // Fin del bucle del menú

    return 0; // Termina el programa con un código de salida 0 (ejecución exitosa)
}