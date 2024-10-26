#include "Persona.h"
#include <string> 

using namespace std;

// Constructores
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

<<<<<<< HEAD
// SET
void Persona::setNombre(std::string nombre) {
=======
// set
void Persona::setNombre(string nombre) {
>>>>>>> 9d5afcf59ae30b7bcb14adb1314f1c567b38514b
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

<<<<<<< HEAD
// GET
std::string Persona::getNombre() {
=======
// get
string Persona::getNombre() {
>>>>>>> 9d5afcf59ae30b7bcb14adb1314f1c567b38514b
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
