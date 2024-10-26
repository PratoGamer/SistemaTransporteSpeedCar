#include "Chofer.h"
#include <string> 

using namespace std;

// Constructores
Chofer::Chofer() : Persona() {
    this->marca = "";
    this->modelo = "";
    this->anho = "";
    this->placa = "";
}

Chofer::Chofer(string nombre, string apellido, string edad, string cedula, string marca, string modelo, string anho, string placa) 
    : Persona(nombre, apellido, edad, cedula) {
    this->marca = marca;
    this->modelo = modelo;
    this->anho = anho;
    this->placa = placa;
}

// Setters
void Chofer::setMarca(string marca) {
    this->marca = marca;
}
void Chofer::setModelo(string modelo) {
    this->modelo = modelo;
}
void Chofer::setAnho(string anho) {
    this->anho = anho;
}
void Chofer::setPlaca(string placa) {
    this->placa = placa;
}

// Getters
string Chofer::getMarca() {
    return marca;
}
string Chofer::getModelo() {
    return modelo;
}
string Chofer::getAnho() {
    return anho;
}
string Chofer::getPlaca() {
    return placa;
}

