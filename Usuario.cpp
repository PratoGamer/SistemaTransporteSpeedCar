#include "Usuario.h"
#include <iostream>
#include <string> 

using namespace std;

// Constructores
Usuario::Usuario() : Persona(){
	
}

Usuario::Usuario(string nombre, string apellido, int edad, int cedula) : Persona(nombre, apellido, edad, cedula){
	
}

// Metodos
void Usuario::leer(){
	Persona::leer();
	
	cout << endl;
	
	cout << "Ingresado Correctamente" << endl;
}

void Usuario::mostrar(){
	Persona::mostrar();
}
