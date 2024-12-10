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

