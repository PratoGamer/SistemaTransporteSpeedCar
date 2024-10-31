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
    void cargarSectoresDesdeArchivo(); 
    string darSector(int num);
    int cantSectores();
    
    
};

#endif

