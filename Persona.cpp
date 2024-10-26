#include "Persona.h"
#include <string> 

using namespace std;

// constructores
Persona::Persona() {
    this->nombre = "";
    this->apellido = "";
    this->edad = "";
    this->cedula = "";
}

Persona::Persona(string nombre, string apellido, string edad, string cedula) {
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

void Persona::setEdad(string edad) {
    this->edad = edad;
}

void Persona::setCedula(string cedula) {
    this->cedula = cedula;
}

// get
string Persona::getNombre() {
    return nombre;
}

string Persona::getApellido() {
    return apellido;
}

string Persona::getEdad() {
    return edad;
}

string Persona::getCedula() {
    return cedula;
}

void Persona::leer(){
	cout << nombre;
}
