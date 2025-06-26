// SistemaLogin.h

/**
 * @file SistemaLogin.h
 * @brief Declaración de la clase SistemaLogin.
 *
 * @details Clase que modela un sistema de autenticación simple con inicio y cierre de sesión,
 * cambio y recuperación de contraseña.
 * @authors [Lina Vanessa Cosme Arce - 202436459] [Whitsell Stiven Diosa Villada - 202439170]
 * @mail [lina.cosme@correounivalle.edu.co] [whitsell.diosa@correounivalle.edu.co]
 * @date 2025-03-25
 * @version 1.0
 *
 * @comentario:
 * - Se organizó mejor la estructura de la clase para mayor claridad.
 * - Se agregaron comentarios explicativos en cada método.
 * - Se utilizó 'const' en métodos que no modifican atributos.
 */

/**
 * Declaración de la clase: SistemaLogin
 * Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
 * Universidad del Valle
 *
 * Información CRC:
 *
 * Descripción:
 *    - Declara la clase SistemaLogin para gestionar autenticación de usuarios.
 *    - Permite iniciar y cerrar sesión, cambiar y recuperar contraseñas.
 *    - Mantiene el estado de la sesión del usuario.
 *
 * Este es un proyecto del curso FPOO de la Universidad del Valle,
 * desarrollado con fines académicos. Puede ser utilizado con fines
 * educativos dando los créditos de la autoría.
 *
 * Autores: Lina Vanessa Cosme Arce; Whitsell Stiven Diosa Villada
 * Correo: lina.cosme@correounivalle.edu.co; whitsell.diosa@correounivalle.edu.co
 * Fecha: 25 Marzo 2025
 */

#ifndef SISTEMALOGIN_H
#define SISTEMALOGIN_H

#include <string>
using namespace std;

class SistemaLogin
{

private:
    string nombreUsuario; // Nombre de usuario asignado.
    string contrasena;    // Contraseña asignada.
    bool enSesion;        // Indica si el usuario ha iniciado sesión.

public:
    // Constructor: recibe el nombre de usuario y la contraseña.
    // Se usa 'const' para garantizar que los parámetros no se modificarán dentro del constructor.
    SistemaLogin(const string _nombreUsuario, const string _contrasena);

    // Método para iniciar sesión. Recibe las credenciales a verificar.
    void iniciarSesion(const string usuario, const string pass);

    // Método para cerrar la sesión.
    void cerrarSesion();

    // Método para cambiar la contraseña si se ha iniciado sesión.
    void cambiarContrasena(const string nuevaContrasena);

    // Método para recuperar la contraseña en caso de olvido.
    void olvidarContrasena();

    // Método que retorna el estado de la sesión.
    // El sufijo 'const' indica que este método no modifica ningún dato miembro del objeto.
    bool isEnSesion() const;
};

#endif