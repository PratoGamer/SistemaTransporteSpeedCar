#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <limits>

#include "Grafo.h"

using namespace std;

// Constructor
Grafo::Grafo(){
	this->numSectores = misSectores.cantSectores();
	
    // Inicializar la matriz de adyacencia con tamaño n x n y valores iniciales 0
    matrizAdyacencia.resize(numSectores, vector<int>(numSectores, 0));
    
    // Cargar las Aristas
    cargarAristas();
}

// Cargar los Datos de las Aristas del Grafo.txt
void Grafo::cargarAristas() {
    ifstream txtGrafo("Grafo.txt");

    if (!txtGrafo.is_open()) {
        cerr << "Error: No se pudo abrir el archivo Grafo.txt" << endl;
        return;
    }

    string auxDatos, sector1, sector2, distancia;
    int sector1Int, sector2Int, distanciaInt;

    while (getline(txtGrafo, auxDatos)) {
        stringstream input_stringstream(auxDatos);

        getline(input_stringstream, sector1, '-');
        sector1Int = atoi(sector1.c_str());
        sector1Int--; // Ajustar índices (restar 1)
        getline(input_stringstream, sector2, '-');
        sector2Int = atoi(sector2.c_str());
        sector2Int--; // Ajustar índices (restar 1)
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
	for (i = 0; i < numSectores; i++) {
            for (j = 0; j < numSectores; j++) {
                cout << matrizAdyacencia[i][j] << " ";
            }
            cout << endl;
	}
}

// Getter para obtener el número de sectores
int Grafo::getNumSectores(){
    return numSectores;
}

// Getter para obtener la matriz de adyacencia
vector< vector<int> > Grafo::getMatrizAdyacencia(){
    return matrizAdyacencia;
}

// Algoritmo de Dijkstra
vector<int> Grafo::dijkstra(int origen, int destino) {
    vector<int> distancias(numSectores, numeric_limits<int>::max());
    vector<int> padres(numSectores, -1);
    vector<bool> visitados(numSectores, false);

    distancias[origen] = 0;

    for (int i = 0; i < numSectores; i++) {
        int nodo_actual = -1;
        int min_distancia = numeric_limits<int>::max();

        // Encontrar el nodo no visitado con la menor distancia
        for (int j = 0; j < numSectores; j++) {
            if (!visitados[j] && distancias[j] < min_distancia) {
                min_distancia = distancias[j];
                nodo_actual = j;
            }
        }

        if (nodo_actual == -1) break; // No hay más nodos alcanzables

        visitados[nodo_actual] = true;

        // Relajación de los vecinos del nodo actual
        for (int vecino = 0; vecino < numSectores; vecino++) {
            // Verificar que hay una conexión y que no se ha visitado el nodo
            if (matrizAdyacencia[nodo_actual][vecino] > 0 && !visitados[vecino]) {
                int nueva_distancia = distancias[nodo_actual] + matrizAdyacencia[nodo_actual][vecino];

                if (nueva_distancia < distancias[vecino]) {
                    distancias[vecino] = nueva_distancia;
                    padres[vecino] = nodo_actual;
                }
            }
        }
    }

    // Construir la ruta desde el destino al origen
    vector<int> ruta;
    for (int nodo = destino; nodo != -1; nodo = padres[nodo]) {
        ruta.push_back(nodo);
    }
    reverse(ruta.begin(), ruta.end());

    // Si el primer nodo en la ruta no es el origen, significa que no hay camino
    if (ruta.front() != origen) {
        ruta.clear(); // Vaciar el vector para indicar que no hay ruta posible
    }

    return ruta;
}


void Grafo::imprimirRuta(vector<int> ruta) {
        if (ruta.empty()) {
            cout << "No hay ruta disponible." << endl;
            return;
        }
        cout << "Ruta más corta: ";
        for (size_t i = 0; i < ruta.size(); i++) {
            cout << (ruta[i] + 1);
            if (i < ruta.size() - 1) cout << " -> ";
        }
        cout << endl;
    }
