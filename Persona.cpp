#include <Persona.h>
	//constructores
Persona::Persona(){
	this->nombre = "";
	this->apellido = "";
	this->edad = 0;
	this->cedula = 0.0f;
}
Persoma::Persona(char nombre, char apellido, int edad, float cedula){
	this->nombre = nombre;
	this->apellido = apellido;
	this->edad = edad;
	this->cedula = cedula;
}
	//set
void Persona::setNombre(char nombre){
	this->nombre = nombre;
}
void Persona::setApellido(char apellido){
	this->apellido = apellido;
}
void Persona::setEdad(int edad){
	this->edad = edad;
}
void Persona::setCedula(float cedula){
	this->cedula = cedula;
}
	//get
char Persona::getNombre(){
	return nombre;
}
char Persona::getApellido(){
	return apellido;
}
int Persona::getEdad(){
	return edad;
}
float Persona::getCedula(){
	return cedula;
}
