#include "ListaSector.h"

#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

// Constructor
ListaSector::ListaSector(){
	
}

void ListaSector::agregarFinal(Chofer user){
	lista.push_back(user);
}

/*
void ListaSector::eliminar(Chofer user){
	lista.remove(user);
}
*/

/*
Chofer ListaSector::obtener(int posicion){
	return lista[posicion];
}
*/

int ListaSector::cantElementos(){
	return lista.size();
}

bool ListaSector::vacia(){
	return lista.empty();
}

