#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>

#include "Grafo.h"

using namespace std;

// Constructor
Grafo::Grafo(int n){
	this->numSectores = n;
	
    // Inicializar la matriz de adyacencia con tama�o n x n y valores iniciales 0
    matrizAdyacencia.resize(n, vector<int>(n, 0));
    
    // Cargar las Aristas
    cargarAristas();
}

// Cargar los Datos de las Aristas del Grafo.txt
void Grafo::cargarAristas(){
	ifstream txtGrafo("Grafo.txt");
	
	string auxDatos, sector1, sector2, distancia;
	int sector1Int, sector2Int, distanciaInt;
	
	while(getline(txtGrafo, auxDatos)){
		
		stringstream input_stringstream(auxDatos);
		
		getline(input_stringstream, sector1, '-');
		sector1Int = atoi(sector1.c_str());
		getline(input_stringstream, sector2, '-');
		sector2Int = atoi(sector2.c_str());
		getline(input_stringstream, distancia, '-');
		distanciaInt = atoi(distancia.c_str());
		
		// Para un Grafo no Dirigido y Ponderado
		matrizAdyacencia[sector1Int][sector2Int] = distanciaInt;
        matrizAdyacencia[sector2Int][sector1Int] = distanciaInt; 
	}
	
	txtGrafo.close();
}

// Imprimir Matriz de Adyacencia
void Grafo::imprimirMatriz(){
	
	int i, j;
	for (i = 1; i <= numSectores; i++) {
            for (j = 1; j <= numSectores; j++) {
                cout << matrizAdyacencia[i][j] << " ";
            }
            cout << endl;
	}
}


