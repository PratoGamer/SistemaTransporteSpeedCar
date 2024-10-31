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

void Usuario::eliminarUsuario(int cedula) {
    for (int i = 0; i < usuarios.size(); ++i) {
        if (usuarios[i].getCedula() == cedula) {
            usuarios.erase(usuarios.begin() + i);
            cout << "Usuario eliminado correctamente." << endl;
            return;
        }
    }
    cout << "Usuario con la cédula " << cedula << " no encontrado." << endl;
}

void Usuario::modificarUsuario(int cedula) {
    for (int i = 0; i < usuarios.size(); ++i) {
        if (usuarios[i].getCedula() == cedula) {
            string nuevoNombre, nuevoApellido;
            int nuevaEdad, nuevaCedula;

            cout << "Ingrese el nuevo nombre: ";
            cin.ignore();
            getline(cin, nuevoNombre);
            cout << "Ingrese el nuevo apellido: ";
            getline(cin, nuevoApellido);
            cout << "Ingrese la nueva edad: ";
            cin >> nuevaEdad;
            cout << "Ingrese la nueva cédula: ";
            cin >> nuevaCedula;

            usuarios[i] = Usuario(nuevoNombre, nuevoApellido, nuevaEdad, nuevaCedula);
            cout << "Usuario modificado correctamente." << endl;
            return;
        }
    }
    cout << "Usuario con la cédula " << cedula << " no encontrado." << endl;
}
