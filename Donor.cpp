/*
    Proyecto: BloodDatabase (Adaptado)
    Curso: Fundamentos de Programación Orientada a Objetos (FPOO)
    Universidad del Valle

    Descripción:
    Este proyecto gestiona una base de datos de donantes de sangre, proporcionando
    funcionalidades para registrar, buscar y analizar la información de los donantes.

    El código se basó en el proyecto BloodDatabase, fue traducido al español
    y adaptado a las necesidades del curso.



    Autor: Victor Bucheli
    Correo: victor.bucheli@correounivalle.edu.co
    Fecha: Octubre 2024
*/
#include "Donor.h" // Se corrigió: se cambió "Donante.h" a "Donor.h" para mantener consistencia.
#include <sstream>
#include <iostream>
#include <algorithm>
#include "Utils.h" // Se incluye para usar métodos de Utils

// Implementación del constructor completo
Donor::Donor(int id, std::string donorName, std::string donorAddress, std::string type, int donorDistrict, std::string donorNumber)
{
    donorId = id;
    name = donorName;
    address = donorAddress;
    bloodType = type;
    district = donorDistrict;
    number = donorNumber;
}

// Getters
int Donor::getDonorId() const { return donorId; }
std::string Donor::getName() const { return name; }
std::string Donor::getAddress() const { return address; }
std::string Donor::getBloodType() const { return bloodType; }
int Donor::getDistrict() const { return district; }
std::string Donor::getNumber() const { return number; }

// Setters
void Donor::setDonorId(int id) { donorId = id; }
void Donor::setName(const std::string &n) { name = n; }
void Donor::setAddress(const std::string &a) { address = a; }
void Donor::setBloodType(const std::string &type) { bloodType = type; }
void Donor::setDistrict(int d) { district = d; }
void Donor::setNumber(const std::string &num) { number = num; }

void Donor::donorDetails() const
{
    std::cout << "Nombre del donante: " << name << std::endl;
    std::cout << "Distrito del donante: " << district << std::endl;
    std::cout << "Tipo de sangre del donante: " << bloodType << std::endl;
}

Donor Donor::parseLine(const std::string &line)
{
    Donor d;
    std::stringstream ss(line);
    std::string token;

    // Se extraen tokens separados por comas y se recortan los espacios.
    getline(ss, token, ',');
    d.donorId = std::stoi(trim(token));
    getline(ss, token, ',');
    d.name = trim(token);
    getline(ss, token, ',');
    d.address = trim(token);
    getline(ss, token, ',');
    d.district = std::stoi(trim(token));
    getline(ss, token, ',');
    d.bloodType = trim(token);
    getline(ss, token, ',');
    d.number = trim(token); // Se quita el stoi porque ahora es un string

    return d;
}
// Método trim para eliminar espacios en blanco al inicio y final de una cadena 
std::string Donor::trim(const std::string& str) {
    return Utils::trim(str);
}