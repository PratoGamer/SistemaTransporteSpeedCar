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
    
    //GETS
    int getNumSectores(); // Obtener el número de sectores
   	vector< vector<int> > getMatrizAdyacencia(); // Obtener la matriz de adyacencia
    
    // Metodos
    void cargarAristas();
    void imprimirMatriz();
	vector<int> dijkstra(int origen, int destino);
	void imprimirRuta(vector<int> ruta);
};

#endif
