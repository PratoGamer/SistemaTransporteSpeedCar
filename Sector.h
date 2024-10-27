#ifndef SectorH
#define SectorH
#include <string> 

using namespace std;

class Sector {
private:
    string sectores[21] = {
        "Centro", "La Concordia", "Barrio Obrero", "Pirineos", "Unidad Vecinal", "La castra",
        "La Rotaria", "Terminal", "Santa Teresa", "Las lomas", "Pueblo Nuevo", "Paramillo",
        "Machiri", "Barrio Sucre", "Puente Real", "La Guyana", "Las pilas",
        "Palo Gordo", "Las Flores", "Cordero", "Palmira"
    };
public:
	Sector();
	void imprimirSectores();
};

#endif

