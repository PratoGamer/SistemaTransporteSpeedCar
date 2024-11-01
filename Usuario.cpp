#include "Usuario.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

// Constructores
Usuario::Usuario() : Persona(){
	cargarUsuarios();
}

Usuario::Usuario(string nombre, string apellido, int edad, int cedula) : Persona(nombre, apellido, edad, cedula){
	
}

// Metodos


//Cargando el vector
void Usuario::cargarUsuarios(){
	ifstream txtUsuarios("Usuarios.txt");
	
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

//Mostrar datos
void Usuario::imprimirUsuarios() {
    for (int i = 0; i < usuarios.size(); ++i) {
        cout << "\t" << (i + 1) << ". " << usuarios[i].getNombre() << " "
             << usuarios[i].getApellido() << " "
             << usuarios[i].getEdad() << " "
             << usuarios[i].getCedula() << endl;
    }
}
//Agregar usuarios
void Usuario::agregarUsuario() {
    string nombre, apellido;
    int edad, cedula;

    // Solicitar Datos del Usuario
    cout << "\tIngrese el nombre: ";
    cin.ignore();
    getline(cin, nombre);
    cout << "\tIngrese el apellido: ";
    getline(cin, apellido);
    cout << "\tIngrese la edad: ";
    cin >> edad;
    cout << "\tIngrese la cedula: ";
    cin >> cedula;
    // guardando datos en el vector
    Usuario nuevoUsuario(nombre, apellido, edad, cedula);
    usuarios.push_back(nuevoUsuario);

    cout << endl << "\tNuevo usuario agregado correctamente." << endl;
}

//Eliminar usuario
void Usuario::eliminarUsuario(int cedula) {
    for (int i = 0; i < usuarios.size(); ++i) {
    	// if para buscar el usuario a eliminar
        if (usuarios[i].getCedula() == cedula) {
            usuarios.erase(usuarios.begin() + i);
            cout << endl << "/tUsuario eliminado correctamente." << endl;
            return;
        }
    }
    cout << endl << "\tUsuario con la cedula " << cedula << " no encontrado." << endl;
}

//Modificar usuario
void Usuario::modificarUsuario(int cedula) {
    for (int i = 0; i < usuarios.size(); ++i) {
        if (usuarios[i].getCedula() == cedula) {
            string nuevoNombre, nuevoApellido;
            int nuevaEdad, nuevaCedula;
			// Pidiendo datos del usuario a modificar
            cout << "\tNuevo nombre: ";
            cin.ignore();
            getline(cin, nuevoNombre);
            cout << "\tNuevo apellido: ";
            getline(cin, nuevoApellido);
            cout << "\tNueva edad: ";
            cin >> nuevaEdad;
            cout << "\tNueva cedula: ";
            cin >> nuevaCedula;
			// guardandolo en el vector
            usuarios[i] = Usuario(nuevoNombre, nuevoApellido, nuevaEdad, nuevaCedula);
            cout << endl << "\tUsuario modificado correctamente." << endl;
            return;
        }
    }
    cout << "\tUsuario con la cedula " << cedula << " no encontrado." << endl;
    system("pause");
}

//Metodo para actualizar el txt donde se guardan los datos de usuario
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

//obteniendo el tamanho del vector
int Usuario::cantUsuarios(){
	return usuarios.size();
}
// enviando la cedula del usuario seleccionado
int Usuario::darCedula(int i){
	return usuarios[i].getCedula();
}

// imprimiendo usuario
void Usuario::imprimirUsuario(int i){
	cout << "\t Usuario: " << usuarios[i].getNombre() << " " << usuarios[i].getApellido() <<
			" - " << usuarios[i].getEdad() << " - " << usuarios[i].getCedula() << endl;
}

// sumando las solisitudes del usuario
void Usuario::sumarUso(int i){
	usuarios[i].usado();
}

// obteniendo la cantidad de solicitud del usuario
int Usuario::cantUsosUsuario(int i){
	return usuarios[i].cantUsos();
}

// Generando el reporte de usuario
void Usuario::generarReporte(ofstream& reporte){
    for (int i = 0; i < usuarios.size(); ++i) {
        if (usuarios[i].cantUsos() > 0) {
            reporte << "\t" << left 
                << setw(15) << usuarios[i].getNombre()
                << setw(15) << usuarios[i].getApellido()
                << setw(15) << usuarios[i].getCedula()
                << setw(15) << usuarios[i].cantUsos() 
                << endl;
        }
    }
}

