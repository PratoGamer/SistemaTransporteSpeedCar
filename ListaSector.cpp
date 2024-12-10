#include "ListaSector.h"

#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

// Constructor
ListaSector::ListaSector(){
	
}

void ListaSector::agregar(Chofer user){
	lista.push_back(user);
}

void ListaSector::eliminar(int posicion){
	lista.erase(lista.begin() + posicion);
}

Chofer ListaSector::obtener(int posicion){
	return lista[posicion];
}

int ListaSector::cantElementos(){
	return lista.size();
}

bool ListaSector::vacia(){
	return lista.empty();
}

bool ListaSector::estaInicializada() {
    // Verifica si la lista tiene elementos o si está preparada para almacenar datos.
    return !lista.empty();
}

void ListaSector::inicializar() {
    // Inicializa la lista de choferes, dejando el contenedor preparado para almacenar datos.
    lista.clear();
}
