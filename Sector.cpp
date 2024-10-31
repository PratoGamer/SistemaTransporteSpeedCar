#include "Sector.h"

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

// Constructor
Sector::Sector() {
    cargarSectoresDesdeArchivo(); 
}

// Cargar sectores desde el archivo
void Sector::cargarSectoresDesdeArchivo() {
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
    for (size_t i = 0; i < sectores.size(); i++) {
        cout << "\t " << (i + 1) << ". " << sectores[i] << endl;
    }
}

// Agregar un Sector
void Sector::agregarSector(string nuevoSector) {
    string sector;
    for (size_t i = 0; i < sectores.size(); i++) {
    	sector = sectores[i];
        if (sector == nuevoSector) {
            cout << "El sector '" << nuevoSector << "' ya existe." << endl;
            return;
        }
    }
	cout << "Sector agregado correctamente!" << endl;
    
    sectores.push_back(nuevoSector);

    
    ofstream archivo("Sectores.txt", ios::app); 
    if (archivo.is_open()) {
        archivo << endl << nuevoSector; 
        archivo.close(); 
        
    } else {
        cout << "Error al abrir el archivo Sectores.txt" << endl;
    }
}


