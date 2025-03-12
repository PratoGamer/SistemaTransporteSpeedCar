#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <fstream>
#include <vector>
#include "Sector.h"

using namespace std;

class Grafo {
private:
	Sector misSectores;
    int numSectores; // Cantidad de Cectores
    vector< vector<int> > matrizAdyacencia; // Matriz de adyacencia
    
public:
    // Constructor
    Grafo();
    
    // Metodos
    void cargarAristas();
    void imprimirMatriz();

};

#endif
