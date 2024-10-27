#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>

#include "Aplicacion.h"
#include "Persona.h"
#include "Chofer.h"
#include "Usuario.h"

using namespace std;

#include <vector>
#include <fstream>

/* 	Autores:
	-> Luis Rojas
	-> Elianny Romero
	-> Gabriel Prato
	
	Entrega:
	31-10-24
*/


int main(int argc, char** argv) {
	
	// Leer los datos de Usuarios en el TXT
	
	vector <Usuario> usuarios;
	
	ifstream txtUsuarios("Usuarios.txt");
	string auxDatos, auxNombre, auxApellido, auxEdad, auxCedula;
	int auxEdadInt, auxCedulaInt;
	int cont = 0;
	
	while(getline(txtUsuarios, auxDatos)){
		
		cout << auxDatos << endl;
		
		stringstream input_stringstream(auxDatos);
		
		
		getline(input_stringstream, auxNombre, '-');
		cout << auxNombre << endl;
		
		getline(input_stringstream, auxApellido, '-');
		cout << auxApellido << endl;
		
		getline(input_stringstream, auxEdad, '-');
		auxEdadInt = atoi(auxEdad.c_str());
		cout << auxEdadInt << endl;
		
		getline(input_stringstream, auxCedula, '-');
		auxCedulaInt = atoi(auxCedula.c_str());
		cout << auxCedulaInt << endl;
		
		usuarios.push_back(Usuario(auxNombre, auxApellido, auxEdadInt, auxCedulaInt));
		
	}
	txtUsuarios.close();
	
	cout << "cantidad de usuarios en el txt: " << usuarios.size() << endl;
	
	Usuario user; 
	
	for(int i = 0; i < usuarios.size() ; i++){
		user = usuarios.at(i);
		user.mostrar();
	}
	
	/*
	Aplicacion* app = new Aplicacion();
	app->Menu();
	*/
	
	
	cout << "\t Fin de la Aplicacion" << endl;
	system("PAUSE");
	
	exit(0);
}
