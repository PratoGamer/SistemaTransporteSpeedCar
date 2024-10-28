#include "Sector.h"
#include <string>
#include <iostream>
using namespace std;

Sector::Sector() {
    // Inicializar con valores predeterminados
    /*sectores = {"Centro", "La Concordia", "Barrio Obrero", "Pirineos", "Unidad Vecinal", 
                "La castra", "La Rotaria", "Terminal", "Santa Teresa", "Las lomas", 
                "Pueblo Nuevo", "Paramillo", "Machiri", "Barrio Sucre", "Puente Real", 
                "La Guyana", "Las pilas", "Palo Gordo", "Las Flores", "Cordero", "Palmira"}; */
}

void Sector::imprimirSectores() {
    for (size_t i = 0; i < sectores.size(); i++) {
        cout << (i + 1) << ". " << sectores[i] << endl;
    }
}

void Sector::agregarSector(string nuevoSector) {
    sectores.push_back(nuevoSector);
}
