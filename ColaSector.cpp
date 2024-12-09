#include "ColaSector.h"

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

// Constructor
ColaSector::ColaSector(){
	
}

void ColaSector::agregar(Usuario user){
	cola.push(user);
}

void ColaSector::eliminar(){
	cola.pop();
}

Usuario ColaSector::obtener(){
	return cola.front();
}

int ColaSector::cantElementos(){
	return cola.size();
}

bool ColaSector::vacia(){
	return cola.empty();
}

