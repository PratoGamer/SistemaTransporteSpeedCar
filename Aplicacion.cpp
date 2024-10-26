#include <iostream>
#include <string.h>

#include "Aplicacion.h"
#include "Persona.h"
#include "Chofer.h"
#include "Usuario.h"

using namespace std;

Aplicacion::Aplicacion(){
	eleccion = 0;
}

void Aplicacion::Menu(){
	cout << "SpeedCar" << endl;
}

void Aplicacion::subMenu(){
	string nombre, apellido, edad, cedula;
	cout << "\t* * *Gestion de Usuario* * *" << endl << endl;
	cout << "Nombre: ";
	getline(cin, nombre);
	cout << "Apellido: ";
	getline(cin, apellido);
	cout << "Edad: ";
	getline(cin, edad);
	cout << "Cedula: ";
	getline(cin, cedula);
	Persona* agg = new Persona();
	agg = new Persona(nombre, apellido, edad, cedula);
	
	agg->leer();
}

