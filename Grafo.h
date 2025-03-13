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
    int numSectores; // Cantidad de Sectores
    vector< vector<int> > matrizAdyacencia; // Matriz de Adyacencia
    
public:
    // Constructor
    Grafo();
    
    // GETS
    int getNumSectores(); // Obtener el Numero de Sectores
   	vector< vector<int> > getMatrizAdyacencia(); // Obtener la Matriz de Adyacencia
    
    // Metodos
    void cargarAristas();
    void imprimirMatriz();
	vector<int> dijkstra(int origen, int destino);
	void imprimirRuta(vector<int> ruta);
	int obtenerDistanciaKm(vector<int> ruta);
};

#endif
