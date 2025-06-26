/*
    Clase: BloodDataBase
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle

    Información CRC:

    Clase: BloodDatabase

    Responsabilidades:
        - Gestionar una base de datos de donantes de sangre, almacenando
          un conjuto de objetos de tipo `Donor`.
        - Proveer métodos para agregar, eliminar y buscar donantes en la base de datos.
        - Facilitar el manejo de la información almacenada de forma eficiente y
          adecuada para su consulta y modificación.

    Colaboradores:
        - Colabora directamente con la clase `Donor`, ya que administra una colección
          de objetos `Donor`.

    Este es un proyecto del curso FPOO de la Universidad del Valle,
    desarrollado con fines académicos. Puede ser utilizado con fines
    académicos dando los créditos de la autoría.

    El código se basó en el proyecto BloodDatabase, fue traducido al español
    y adaptado a las necesidades del curso.

    Autor: Victor Bucheli
    Correo: victor.bucheli@correounivalle.edu.co
    Fecha: Octubre 2024
*/
#ifndef BLOODDATABASE_H
#define BLOODDATABASE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Donor.h" // Se corrigió: se cambió "Donante.h" a "Donor.h" para mantener consistencia.

class BloodDatabase
{
private:
  // Nombre del archivo de datos.
  const std::string fileName = "data.txt";
  // Vector que almacena los donantes (usado al registrar nuevos donantes en memoria).
  std::vector<Donor> donors;

  // Método estático privado que muestra un listado de departamentos.
  static void displayProvinces();

public:
  // Métodos estáticos para limpiar la consola, esperar pulsación de tecla y validar entradas.
  // Estos métodos ahora se obtienen de la clase Utils
  static int getValidatedInput(const std::string &prompt);

  // Métodos públicos para gestionar la base de datos.
  void getDonorDetails();
  void writeDataToFile();
  void searchAndDisplay() const;
  void deleteDonor(const std::string &donorName);
  void addTestDonor();// Método para la declaracion de pruebas un donante de prueba.

  // NUEVO MÉTODO: Calcula y muestra el porcentaje de donantes por cada tipo de sangre.
  void displayBloodTypeDistribution() const;

  // NUEVO MÉTODO: Valida la entrada de los departamentos.
  int getValidatedInputInRange(const std::string &prompt, int min, int max);

  // NUEVO MÉTODO: Valida la entrada de los números de teléfono
  std::string getValidatedInputPhone(const std::string &prompt);
};

#endif // BLOODDATABASE_H