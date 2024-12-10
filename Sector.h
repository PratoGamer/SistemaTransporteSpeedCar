#ifndef SECTOR_H
#define SECTOR_H

#include <string>
#include <vector>
using namespace std;

class Sector {
private:
    vector<string> sectores;
public:
	// Constructor
    Sector();
    
    // Metodos 
    void imprimirSectores();
    void agregarSector(string nuevoSector);
    void cargarSectores(); 
    string darSector(int num);
    int cantSectores();
    void eliminarSector(int posicion);
    void modificarSector(int posicion);
    void guardarSectores();
    int buscarSectorPorNombre(string nombreSector);
    
};

#endif

