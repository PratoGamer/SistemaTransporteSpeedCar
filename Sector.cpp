#include <string>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

class Sector {
private:
    vector<string> sectores;

public:
    Sector();
    void imprimirSectores();
    void agregarSector(string nuevoSector);
    void cargarSectoresDesdeArchivo(); 
    
};

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

void Sector::imprimirSectores() {
    for (size_t i = 0; i < sectores.size(); i++) {
        cout << (i + 1) << ". " << sectores[i] << endl;
    }
}

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


