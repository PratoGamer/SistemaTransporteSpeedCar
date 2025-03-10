#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

class Grafo {
private:
    int numSectores; // Número de sectores
    vector< vector<int> > matrizAdyacencia; // Matriz de adyacencia

public:
    // Constructor
    Grafo(int n);
    
    // Metodos
    void cargarAristas();
    void imprimirMatriz();

};

#endif
