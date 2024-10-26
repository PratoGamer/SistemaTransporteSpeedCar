#include "Chofer.h"

// Constructores
Chofer::Chofer() : Persona() {
    this->marca = "";
    this->modelo = "";
    this->anho = 0;
    this->placa = "";
}

Chofer::Chofer(std::string nombre, std::string apellido, int edad, float cedula, std::string marca, std::string modelo, int anho, std::string placa) 
    : Persona(nombre, apellido, edad, cedula) {
    this->marca = marca;
    this->modelo = modelo;
    this->anho = anho;
    this->placa = placa;
}

// Setters
void Chofer::setMarca(std::string marca) {
    this->marca = marca;
}
void Chofer::setModelo(std::string modelo) {
    this->modelo = modelo;
}
void Chofer::setAnho(int anho) {
    this->anho = anho;
}
void Chofer::setPlaca(std::string placa) {
    this->placa = placa;
}

// Getters
std::string Chofer::getMarca() {
    return marca;
}
std::string Chofer::getModelo() {
    return modelo;
}
int Chofer::getAnho() {
    return anho;
}
std::string Chofer::getPlaca() {
    return placa;
}

