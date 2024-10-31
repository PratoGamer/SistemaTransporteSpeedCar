#include "Chofer.h"
#include <iostream>
#include <string> 

using namespace std;

// Constructores
Chofer::Chofer() : Persona() {
    this->marca = "";
    this->modelo = "";
    this->anho = 0;
    this->placa = "";
    this->sector = "";
}

Chofer::Chofer(string nombre, string apellido, int edad, int cedula, string marca, string modelo, int anho, string placa, string sector) 
    : Persona(nombre, apellido, edad, cedula) {
    this->marca = marca;
    this->modelo = modelo;
    this->anho = anho;
    this->placa = placa;
    this->sector = sector;
}

// SET
void Chofer::setMarca(string marca) {
    this->marca = marca;
}
void Chofer::setModelo(string modelo) {
    this->modelo = modelo;
}
void Chofer::setAnho(int anho) {
    this->anho = anho;
}
void Chofer::setPlaca(string placa) {
    this->placa = placa;
}
void Chofer::setSector(string sector) {
    this->sector = sector;
}

// GET
string Chofer::getMarca() {
    return marca;
}
string Chofer::getModelo() {
    return modelo;
}
int Chofer::getAnho() {
    return anho;
}
string Chofer::getPlaca() {
    return placa;
}
string Chofer::getSector() {
    return sector;
}

// Metodos
void Chofer::leer(){
	Persona::leer();
	cin.get();
	cout << "Ingrese la Marca del Vehiculo: ";
	getline(cin, marca);
	cout << "Ingrese el Modelo del Vehiculo: ";
	getline(cin, modelo);
	cout << "Ingrese la Placa del Vehiculo: ";
	getline(cin, placa);
	cout << "Ingrese el Anho del Vehiculo: ";
	cin >> anho;
	
}

void Chofer::mostrar(){
	Persona::mostrar();
	
	cout << "Marca: " << this->marca << " | Modelo: " << this->modelo << endl;
	cout << "Anho: " << this->anho << " | Placa: " << this->placa << " | Sector: " << this->sector << endl;
}

