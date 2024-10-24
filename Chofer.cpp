#include <Chofer.h>

Chofer::Chofer() : Persona(){
	this->marca = "";
	this->modelo = "";
	this->anho = 0;
	this->placa = "";
}
Chofer::Chofer(char nombre, char apellido, int edad, float cedula, char marca, char modelo, int anho, char placa) : Persona(nombre, apellido, edad, cedula){
	this->marca = marca;
	this->modelo = modelo;
	this->anho = anho;
	this->placa = placa;
}
	//set
void Chofer::setMarca(char marca){
	this->marca = marca;
}
void Chofer::setModelo(char modelo){
	this->modelo = modelo;
}
void Chofer::setAnho(int anho){
	this->anho = anho;
}
void Chofer::setPlaca(char placa){
	this->placa = placa;
}
	//get
char Chofer::getMarca(){
	return marca;
}
char Chofer::getModelo(){
	return modelo;
}
int Chofer::getAnho(){
	return anho;
}
float Chofer::getPlaca(){
	return placa;
}
