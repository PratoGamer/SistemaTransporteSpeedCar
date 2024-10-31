#include "Usuario.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>

using namespace std;

// Constructores
Usuario::Usuario() : Persona(){
	cargarUsuarios();
}

Usuario::Usuario(string nombre, string apellido, int edad, int cedula) : Persona(nombre, apellido, edad, cedula){
	
}

void Usuario::cargarUsuarios(){
	// Cargar Datos de los Usuarios
	ifstream txtUsuarios("Usuarios.txt");
	
	// Variables Auxiliares
	string auxDatos, auxNombre, auxApellido, auxEdad, auxCedula;
	int auxEdadInt, auxCedulaInt;
	
	while(getline(txtUsuarios, auxDatos)){
		
		stringstream input_stringstream(auxDatos);
		
		getline(input_stringstream, auxNombre, '-');
		getline(input_stringstream, auxApellido, '-');
		getline(input_stringstream, auxEdad, '-');
		auxEdadInt = atoi(auxEdad.c_str());
		getline(input_stringstream, auxCedula, '-');
		auxCedulaInt = atoi(auxCedula.c_str());
		
		usuarios.push_back(Usuario(auxNombre, auxApellido, auxEdadInt, auxCedulaInt));
		
	}
	txtUsuarios.close();
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

void Usuario::imprimirUsuarios() {
    for (int i = 0; i < usuarios.size(); ++i) {
        cout << usuarios[i].getNombre() << " "
             << usuarios[i].getApellido() << " "
             << usuarios[i].getEdad() << " "
             << usuarios[i].getCedula() << endl;
    }
}

void Usuario::agregarUsuario() {
    string nombre, apellido;
    int edad, cedula;

    // Solicitar Datos del Usuario
    cout << "Ingrese el nombre: ";
    cin.ignore();
    getline(cin, nombre);
    cout << "Ingrese el apellido: ";
    getline(cin, apellido);
    cout << "Ingrese la edad: ";
    cin >> edad;
    cout << "Ingrese la cedula: ";
    cin >> cedula;
    
    Usuario nuevoUsuario(nombre, apellido, edad, cedula);
    usuarios.push_back(nuevoUsuario);

    cout << "Nuevo usuario agregado correctamente." << endl;
}


void Usuario::eliminarUsuario(int cedula) {
    for (int i = 0; i < usuarios.size(); ++i) {
        if (usuarios[i].getCedula() == cedula) {
            usuarios.erase(usuarios.begin() + i);
            cout << "Usuario eliminado correctamente." << endl;
            return;
        }
    }
    cout << "Usuario con la cedula " << cedula << " no encontrado." << endl;
}

void Usuario::modificarUsuario(int cedula) {
    for (int i = 0; i < usuarios.size(); ++i) {
        if (usuarios[i].getCedula() == cedula) {
            string nuevoNombre, nuevoApellido;
            int nuevaEdad, nuevaCedula;

            cout << "Nuevo nombre: ";
            cin.ignore();
            getline(cin, nuevoNombre);
            cout << "Nuevo apellido: ";
            getline(cin, nuevoApellido);
            cout << "Nueva edad: ";
            cin >> nuevaEdad;
            cout << "Nueva cedula: ";
            cin >> nuevaCedula;

            usuarios[i] = Usuario(nuevoNombre, nuevoApellido, nuevaEdad, nuevaCedula);
            cout << "Usuario modificado correctamente." << endl;
            return;
        }
    }
    cout << "Usuario con la cedula " << cedula << " no encontrado." << endl;
}

//Guardar usuarios en el txt
void Usuario::guardarUsuarios() {
    ofstream txtUsuarios("Usuarios.txt");
    for (int i = 0; i < usuarios.size(); ++i) {
        txtUsuarios << usuarios[i].getNombre() << "-"
                    << usuarios[i].getApellido() << "-"
                    << usuarios[i].getEdad() << "-"
                    << usuarios[i].getCedula() << endl;
    }
    txtUsuarios.close();
}

int Usuario::cantUsuarios(){
	return usuarios.size();
}

int Usuario::darCedula(int i){
	return usuarios[i].getCedula();
}

void Usuario::imprimirUsuario(int i){
	cout << "\t Usuario: " << usuarios[i].getNombre() << " " << usuarios[i].getApellido() <<
			" - " << usuarios[i].getEdad() << " - " << usuarios[i].getCedula() << endl;
}

void Usuario::sumarUso(int i){
	usuarios[i].usado();
}

int Usuario::cantUsosUsuario(int i){
	return usuarios[i].cantUsos();
}
