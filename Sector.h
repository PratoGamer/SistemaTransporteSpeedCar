#ifndef SECTOR_H
#define SECTOR_H

#include <string>
#include <vector>
using namespace std;

class Sector {
private:
    vector<string> sectores;
public:
    Sector();
    void imprimirSectores();
    void agregarSector(string nuevoSector);
};

#endif

