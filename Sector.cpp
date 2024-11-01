#include "Sector.h"

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

// Constructor
Sector::Sector() {
    cargarSectores(); 
}

// Cargando datos
void Sector::cargarSectores() {
    ifstream archivo("Sectores.txt");
    string sector;
    while (getline(archivo, sector)) {
        if (!sector.empty()) {
            sectores.push_back(sector);  
        }
    }
    archivo.close();
}

// Da la Cantidad de Sectores
int Sector::cantSectores(){
	return sectores.size();
}

// Da un Sector
string Sector::darSector(int num){
	if( (num < 0) || (num > sectores.size() ) ){
		return " ";
	}
	else{
		return sectores.at(num);	
	}
}

// Imprimir los Sectores
void Sector::imprimirSectores() {
    for (int i = 0; i < sectores.size(); i++) {
        cout << "\t " << (i + 1) << ". " << sectores[i] << endl;
    }
}

// Agregar un sector
void Sector::agregarSector(string nuevoSector) {
    string sector;
    for (int i = 0; i < sectores.size(); i++) {
    	sector = sectores[i];
        if (sector == nuevoSector) {
            cout << endl <<  "\tEl sector '" << nuevoSector << "' ya existe." << endl;
            return;
        }
    }
	cout << endl << "\tSector agregado correctamente!" << endl;
    
    sectores.push_back(nuevoSector);
}

//eliminar sector
void Sector::eliminarSector(int posicion) { 
	if (posicion >= 1 && posicion <= sectores.size()){ 
		sectores.erase(sectores.begin() + posicion - 1); 
		cout << endl << "\tSector eliminado correctamente." << endl; 
	}else{
		cout << endl << "\tPosicion invalida." << endl;
	}
}

//Modificar sector
void Sector::modificarSector(int posicion){ 
		string nuevoSector;
	if (posicion >= 1 && posicion <= sectores.size()){
		cout << "\tIngrese el nuevo sector: ";
		cin.ignore();
        getline(cin , nuevoSector);
        for (int i = 0 ; i < sectores.size() ; i++){
        	if(sectores[i] == nuevoSector){
        		cout << "\tEste sector ya existe";
        		system("pause");
        		return;
			}
		}
		sectores[posicion - 1] = nuevoSector;;
		cout << endl << "\tSector modificado correctamente." << endl;
	}else{
		cout << endl << "\tPosicion invalida." << endl;
	}
	system("pause");
}

//Metodo para actualizar el txt donde se guardan los datos sectores
void Sector::guardarSectores(){
	ofstream archivo("sectores.txt");
	for(int i = 0; i < sectores.size(); i++){ 
		archivo << endl << sectores[i];
	}
	archivo.close();
}
