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
#include "BloodDatabase.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <stdexcept>
#include <cctype>
#include <algorithm>
#include <map>    // Se incluye para contar los tipos de sangre.
#include <array>  // Se incluye para que funcione la API
#include <memory> // Se incluye para 'unique_ptr'
#include <cstdio> // Se incluye para popen y pclose
#include "Utils.h" // Se incluye para usar métodos de Utils

using namespace std;

// Se reemplazó el acceso directo a miembros privados de Donor por métodos getters y setters

void BloodDatabase::displayProvinces()
{
    std::cout << "Elige el departamento:\n";
    std::cout << "1. Putumayo\n";
    std::cout << "2. Cauca\n";
    std::cout << "3. Valle del Cauca\n";
    std::cout << "4. Amazonas\n";
    std::cout << "5. Risaralda\n";
    std::cout << "6. Antioquia\n";
    std::cout << "7. Norte de Santander\n";
}

int BloodDatabase::getValidatedInput(const std::string &prompt)
{
    int value;
    std::string input;
    while (true)
    {
        std::cout << prompt;
        std::getline(std::cin, input);
        try
        {
            // Valida que la entrada contenga solo dígitos.
            if (!std::all_of(input.begin(), input.end(), ::isdigit))
            {
                throw std::invalid_argument("La entrada contiene caracteres no numericos");
            }
            value = std::stoi(input);
            break; // La conversión fue exitosa.
        }
        catch (const std::invalid_argument &e)
        {
            std::cout << "Entrada no valida: " << e.what()
                      << ". Por favor ingrese un numero valido." << std::endl;
        }
        catch (const std::out_of_range &)
        {
            std::cout << "Entrada fuera de rango. Por favor ingrese un numero valido." << std::endl;
        }
    }
    return value;
}

// Nuevo método para validar la entrada de los departamentos
int BloodDatabase::getValidatedInputInRange(const std::string &prompt, int min, int max)
{
    int value;
    std::string input;
    while (true)
    {
        std::cout << prompt;
        std::getline(std::cin, input);
        try
        {
            if (!std::all_of(input.begin(), input.end(), ::isdigit))
            {
                throw std::invalid_argument("La entrada contiene caracteres no numericos");
            }
            value = std::stoi(input);

            if (value < min || value > max)
            {
                std::cout << "Por favor ingrese un numero entre " << min << " y " << max << "." << std::endl;
                continue;
            }

            break;
        }
        catch (const std::invalid_argument &e)
        {
            std::cout << "Entrada no valida: " << e.what()
                      << ". Por favor ingrese un numero valido." << std::endl;
        }
        catch (const std::out_of_range &)
        {
            std::cout << "Entrada fuera de rango. Por favor ingrese un numero valido." << std::endl;
        }
    }
    return value;
}

// Nuevo método para validar la entrada de los números de teléfono.
std::string BloodDatabase::getValidatedInputPhone(const std::string &prompt) // Usa Numverify
{
    std::string input;
    std::string apiKey = "d8bc661acf19ba7fa4c4c5bce86bfa99"; // API key de Numverify

    while (true)
    {
        std::cout << prompt;
        std::getline(std::cin, input);

        try
        {
            if (input.length() != 10 || !std::all_of(input.begin(), input.end(), ::isdigit))
            {
                throw std::invalid_argument("El numero debe contener exactamente 10 dígitos numericos");
            }

            std::string comando = "curl -s \"http://apilayer.net/api/validate?access_key=" + apiKey + "&number=%2B57" + input + "\"";
            std::array<char, 128> buffer;
            std::string resultado;

            std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(comando.c_str(), "r"), pclose);
            if (!pipe)
            {
                throw std::runtime_error("No se pudo ejecutar el comando de validacion");
            }

            while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr)
            {
                resultado += buffer.data();
            }

            if (resultado.find("\"valid\":true") != std::string::npos)
            {
                return input;
            }
            else
            {
                std::cout << "Número invalido segun la API. Intente de nuevo.\n";
            }
        }
        catch (const std::invalid_argument &e)
        {
            std::cout << "Entrada no valida: " << e.what() << ". Por favor, intente de nuevo.\n";
        }
        catch (const std::runtime_error &e)
        {
            std::cout << "Error: " << e.what() << "\n";
        }
    }
}

void BloodDatabase::getDonorDetails()
{
    Utils::clearScreen();
    std::cout << "Ingrese los detalles del donante\n";

    Donor newDonor;
    newDonor.setDonorId(getValidatedInput("Id: "));
    std::string input;
    std::cout << "Nombre: ";
    std::getline(std::cin, input);
    newDonor.setName(input);
    std::cout << "Direccion: ";
    std::getline(std::cin, input);
    newDonor.setAddress(input);

    displayProvinces();
    newDonor.setDistrict(getValidatedInputInRange("Departamento (ingrese el numero correspondiente): ", 1, 7));
    std::cout << "Tipo de sangre: ";
    std::getline(std::cin, input);
    newDonor.setBloodType(input);
    newDonor.setNumber(getValidatedInputPhone("Numero: "));

    donors.push_back(newDonor);
}

void BloodDatabase::writeDataToFile()
{
    std::ofstream outfile(fileName, std::ios::app);

    if (!outfile)
    {
        std::cout << "Error al abrir el archivo para escribir." << std::endl;
        return;
    }

    // Se asume que se escribe el último donante registrado en memoria.
    Donor newDonor = donors.back();
    outfile << newDonor.getDonorId() << ",    " << newDonor.getName() << ",    " << newDonor.getAddress()
            << ",    " << newDonor.getDistrict() << ",    " << newDonor.getBloodType()
            << ",    " << newDonor.getNumber() << std::endl;

    outfile.close();
}

void BloodDatabase::searchAndDisplay() const
{
    Utils::clearScreen();
    displayProvinces();
    int provinceName = getValidatedInput("Ingrese el numero de la departamento: ");

    std::cout << "Ingrese la direccion (dejar en blanco para omitir): ";
    std::string addressFilter;
    std::getline(std::cin, addressFilter);

    std::cout << "Ingrese el tipo de sangre (dejar en blanco para omitir): ";
    std::string bloodTypeFilter;
    std::getline(std::cin, bloodTypeFilter);

    std::ifstream inFile(fileName);

    if (!inFile)
    {
        std::cout << "Error al abrir el archivo para leer." << std::endl;
        return;
    }

    std::vector<Donor> donors;
    std::string line;
    bool found = false;

    while (std::getline(inFile, line))
    {
        Donor d = Donor::parseLine(line);
        bool match = d.getDistrict() == provinceName &&
                     (addressFilter.empty() || d.getAddress().find(addressFilter) != std::string::npos) &&
                     (bloodTypeFilter.empty() || d.getBloodType() == bloodTypeFilter);

        if (match)
        {
            donors.push_back(d);
            found = true;
        }
    }

    if (!found)
    {
        std::cout << "No se encontraron personas de la departamento " << provinceName;
        if (!addressFilter.empty())
        {
            std::cout << " con direccion que contiene '" << addressFilter << "'";
        }
        if (!bloodTypeFilter.empty())
        {
            std::cout << " y tipo de sangre '" << bloodTypeFilter << "'";
        }
        std::cout << "." << std::endl;
    }
    else
    {
        std::cout << "Personas de la departamento " << provinceName;
        if (!addressFilter.empty())
        {
            std::cout << " con direccion que contiene '" << addressFilter << "'";
        }
        if (!bloodTypeFilter.empty())
        {
            std::cout << " y tipo de sangre '" << bloodTypeFilter << "'";
        }
        std::cout << ":" << std::endl;
        for (const auto &d : donors)
        {
            std::cout << "Nombre: " << d.getName() << std::endl;
            std::cout << "Direccion: " << d.getAddress() << std::endl;
            std::cout << "departamento: " << d.getDistrict() << std::endl;
            std::cout << "Tipo de sangre: " << d.getBloodType() << std::endl;
            std::cout << "Numero de móvil: " << d.getNumber() << std::endl;
            std::cout << std::endl;
        }
    }

    inFile.close();
    Utils::waitForKey();
}

void BloodDatabase::deleteDonor(const std::string &donorName)
{
    std::ifstream inFile(fileName);
    std::ofstream tempFile("temp.txt");

    if (!inFile)
    {
        std::cerr << "Error al abrir el archivo " << fileName << std::endl;
        return;
    }

    if (!tempFile)
    {
        std::cerr << "Error al crear el archivo temporal" << std::endl;
        return;
    }

    std::string line;
    bool found = false;

    while (std::getline(inFile, line))
    {
        Donor d = Donor::parseLine(line);
        if (d.getName() == donorName)
        {
            found = true;
            std::cout << "Nombre: " << d.getName() << std::endl;
            std::cout << "Direccion: " << d.getAddress() << std::endl;
            std::cout << "Tipo de sangre: " << d.getBloodType() << std::endl;
            std::cout << "Numero de movil: " << d.getNumber() << std::endl;
            std::cout << std::endl;
            std::cout << "¿Desea eliminar este donante? [s/n]: ";
            char sureChoice;
            std::cin >> sureChoice;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Se limpia el buffer.

            if (sureChoice == 's' || sureChoice == 'S')
            {
                // Si se confirma, se omite escribir esta línea en el archivo temporal.
                continue;
            }
        }
        tempFile << d.getDonorId() << ",    " << d.getName() << ",    " << d.getAddress()
                 << ",    " << d.getDistrict() << ",    " << d.getBloodType() << ",    " << d.getNumber() << std::endl;
    }

    inFile.close();
    tempFile.close();

    if (std::remove(fileName.c_str()) != 0)
    {
        std::cerr << "Error al eliminar el archivo original" << std::endl;
        return;
    }

    if (std::rename("temp.txt", fileName.c_str()) != 0)
    {
        std::cerr << "Error al renombrar el archivo temporal" << std::endl;
        return;
    }

    if (!found)
    {
        std::cout << "No se encontro ningun donante con el nombre " << donorName << std::endl;
    }
}

// NUEVO MÉTODO: Calcula y muestra el porcentaje de la población con cada tipo de sangre
// y determina cuál tipo de sangre es el más común.
void BloodDatabase::displayBloodTypeDistribution() const
{
    std::ifstream inFile(fileName);
    if (!inFile)
    {
        std::cout << "Error al abrir el archivo para leer." << std::endl;
        return;
    }

    std::map<std::string, int> bloodCount; // Mapa para contar cada tipo de sangre.
    std::string line;
    int total = 0;

    while (std::getline(inFile, line))
    {
        Donor d = Donor::parseLine(line);
        std::string tipo = d.getBloodType();

        // Limpiar y estandarizar
        tipo.erase(remove(tipo.begin(), tipo.end(), ' '), tipo.end());
        tipo.erase(remove(tipo.begin(), tipo.end(), '\r'), tipo.end());
        tipo.erase(remove(tipo.begin(), tipo.end(), '\n'), tipo.end());
        std::transform(tipo.begin(), tipo.end(), tipo.begin(), ::toupper);

        bloodCount[tipo]++;
        total++;
    }
    inFile.close();

    if (total == 0)
    {
        std::cout << "No hay datos de donantes para calcular la distribucion." << std::endl;
        Utils::waitForKey();
        return;
    }

    std::cout << "Distribucion de tipos de sangre:\n";

    std::string tipoMasComun = "";
    int cantidadMaxima = 0;

    for (const auto &entry : bloodCount)
    {
        double porcentaje = (entry.second * 100.0) / total;
        std::cout << "Tipo " << entry.first << ": " << porcentaje << "% ("
                  << entry.second << " de " << total << " donantes)\n";

        // Detectar tipo más común
        if (entry.second > cantidadMaxima)
        {
            cantidadMaxima = entry.second;
            tipoMasComun = entry.first;
        }
    }
}
// Método para agregar un donante de prueba a la base de datos para las pruebas unitarias, para que este sea automatico.
void BloodDatabase::addTestDonor() {
    Donor donor;
    donor.setDonorId(123);
    donor.setName("Juan Perez");
    donor.setAddress("Calle 123");
    donor.setDistrict(1);
    donor.setBloodType("A+");
    donor.setNumber("3012345678");

    donors.push_back(donor);
}