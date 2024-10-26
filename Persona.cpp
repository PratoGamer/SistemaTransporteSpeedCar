#include "Persona.h"
#include <string> 

using namespace std;

// constructores
Persona::Persona() {
    this->nombre = "";
    this->apellido = "";
    this->edad = 0;
    this->cedula = 0.0f;
}

Persona::Persona(string nombre, string apellido, int edad, float cedula) {
    this->nombre = nombre;
    this->apellido = apellido;
    this->edad = edad;
    this->cedula = cedula;
}

// set
void Persona::setNombre(string nombre) {
    this->nombre = nombre;
}

void Persona::setApellido(string apellido) {
    this->apellido = apellido;
}

void Persona::setEdad(int edad) {
    this->edad = edad;
}

void Persona::setCedula(float cedula) {
    this->cedula = cedula;
}

// get
string Persona::getNombre() {
    return nombre;
}

string Persona::getApellido() {
    return apellido;
}

int Persona::getEdad() {
    return edad;
}

float Persona::getCedula() {
    return cedula;
}
