/**
 * @file SistemaLogin.cpp
 * @brief Implementación de la clase SistemaLogin.
 *
 * @details Clase que modela un sistema de autenticación simple con inicio y cierre de sesión,
 * cambio y recuperación de contraseña.
 * @authors [Lina Vanessa Cosme Arce - 202436459] [Whitsell Stiven Diosa Villada - 202439170]
 * @mail [lina.cosme@correounivalle.edu.co] [whitsell.diosa@correounivalle.edu.co]
 * @date 2025-03-25
 * @version 1.0
 *
 * @comentario:
 * - Se mejoraron los mensajes de salida para que sean más claros.
 * - Se corrigió un error en el cambio de contraseña.
 * - Se añadieron validaciones para evitar acciones sin haber iniciado sesión.
 */

/**
 * Implementación de la clase: SistemaLogin
 * Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
 * Universidad del Valle
 *
 * Información CRC:
 *
 * Descripción:
 *    - Implementa los métodos de la clase SistemaLogin declarada en "sistemaLogin.h".
 *    - Permite la autenticación de usuarios mediante inicio y cierre de sesión.
 *    - Permite cambiar y recuperar contraseñas.
 *    - Controla el estado de la sesión del usuario.
 *
 * Este es un proyecto del curso FPOO de la Universidad del Valle,
 * desarrollado con fines académicos. Puede ser utilizado con fines
 * educativos dando los créditos de la autoría.
 *
 * Autores: Lina Vanessa Cosme Arce; Whitsell Stiven Diosa Villada
 * Correo: lina.cosme@correounivalle.edu.co; whitsell.diosa@correounivalle.edu.co
 * Fecha: 25 Marzo 2025
 */

#include "sistemaLogin.h"
#include <iostream>
using namespace std;

SistemaLogin::SistemaLogin(const string _nombreUsuario, const string _contrasena)
{
    // Inicializa los atributos con los valores recibidos.
    nombreUsuario = _nombreUsuario;
    contrasena = _contrasena;
    enSesion = false; // Establece que el usuario no está en sesión inicialmente.
}

// Método constante que retorna el estado de la sesión sin modificar el objeto.
bool SistemaLogin::isEnSesion() const
{
    return enSesion;
}

// Inicia sesión si las credenciales son correctas.
void SistemaLogin::iniciarSesion(const string usuario, const string pass)
{
    if (usuario == nombreUsuario && pass == contrasena)
    {
        enSesion = true;
        cout << "Ingreso valido. ¡Bienvenido!" << endl;
    }
    else
    {
        cout << "Credenciales incorrectas." << endl;
    }
}

// Cierra la sesión, si estaba iniciada.
void SistemaLogin::cerrarSesion()
{
    if (enSesion)
    {
        enSesion = false;
        cout << "Has cerrado la sesion." << endl;
    }
    else
    {
        cout << "No hay sesion iniciada." << endl;
    }
}

// Cambia la contraseña si se ha iniciado sesión.
void SistemaLogin::cambiarContrasena(const string nuevaContrasena)
{
    if (enSesion == true)
    {
        contrasena = nuevaContrasena;
        cout << "Contrasena cambiada exitosamente." << endl;
    }
    else
    {
        cout << "Debes iniciar sesion para cambiar la contrasena." << endl;
    }
}

// Permite simular la recuperación de contraseña.
void SistemaLogin::olvidarContrasena()
{
    cout << "Proceso de recuperacion de contraseña iniciado." << endl;
    cout << "Ingrese su nueva contraseña: ";
    string nuevaContrasena;
    cin >> nuevaContrasena;
    contrasena = nuevaContrasena;
    cout << "Contraseña restablecida exitosamente." << endl;
}