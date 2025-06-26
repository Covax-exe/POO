/*
    Clase: Donor
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle

    Información CRC:

    Clase: Donor

    Responsabilidades:
        - Almacenar y gestionar la información de un donante,
          incluyendo detalles como nombre, tipo de sangre,
          distrito de residencia y otros datos relevantes.
        - Proveer métodos para obtener y manipular dicha información,
          como  obtener datos del donante.
        - Ofrecer funcionalidades para procesar y mostrar la información
          de los donantes en formato adecuado.

    Colaboradores:
        - Colabora con la clase BloodDatabase, que gestiona una colección
          de objetos Donor para administrar la base de datos de donantes
          de sangre.

    Este es un proyecto del curso FPOO de la Universidad del Valle,
    desarrollado con fines académicos. Puede ser utilizado con fines
    académicos dando los créditos de la autoría.

    El código se basó en el proyecto BloodDatabase, fue traducido al español
    y adaptado a las necesidades del curso.

    Autor: Victor Bucheli
    Correo: victor.bucheli@correounivalle.edu.co
    Fecha: Octubre 2024
*/
#ifndef DONOR_H
#define DONOR_H

#include <string>

class Donor
{

private: // encapsulamiento
  // Se pasan los atributos a privados para almacenar datos del donante.
  int donorId, district;
  std::string name, address, bloodType, number; // Se convierte 'number' a cadena de texto.

  // Método auxiliar estático para "trim" (recortar espacios al inicio y final de una cadena).
  static std::string trim(const std::string &str);

public:
  // Constructor completo
  Donor(int id, std::string donorName, std::string donorAddress, std::string type, int donorDistrict, std::string donorNumber);

  // Constructor por defecto
  Donor() = default;

  // Getters
  int getDonorId() const;
  std::string getName() const;
  std::string getAddress() const;
  std::string getBloodType() const;
  int getDistrict() const;
  std::string getNumber() const;

  // Setters
  void setDonorId(int id);
  void setName(const std::string &n);
  void setAddress(const std::string &a);
  void setBloodType(const std::string &type);
  void setDistrict(int d);
  void setNumber(const std::string &num);

  // Método que imprime los detalles del donante.
  void donorDetails() const;

  // Método estático que convierte una línea (formato CSV) en objeto Donor.
  static Donor parseLine(const std::string &line);
};

#endif // DONOR_H