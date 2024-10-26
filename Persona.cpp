#include "Persona.h"

// Constructores
Persona::Persona() {
    this->nombre = "";
    this->apellido = "";
    this->edad = 0;
    this->cedula = 0.0f;
}

Persona::Persona(std::string nombre, std::string apellido, int edad, float cedula) {
    this->nombre = nombre;
    this->apellido = apellido;
    this->edad = edad;
    this->cedula = cedula;
}

// SET
void Persona::setNombre(std::string nombre) {
    this->nombre = nombre;
}

void Persona::setApellido(std::string apellido) {
    this->apellido = apellido;
}

void Persona::setEdad(int edad) {
    this->edad = edad;
}

void Persona::setCedula(float cedula) {
    this->cedula = cedula;
}

// GET
std::string Persona::getNombre() {
    return nombre;
}

std::string Persona::getApellido() {
    return apellido;
}

int Persona::getEdad() {
    return edad;
}

float Persona::getCedula() {
    return cedula;
}
