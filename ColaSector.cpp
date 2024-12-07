#include "ColaSector.h"

#include <string>
#include <vector>
#include <queue>
#include <fstream>
#include <iostream>

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
	return cola.back();
}

int ColaSector::cantElementos(){
	return cola.size();
}

bool ColaSector::vacia(){
	return cola.empty();
}

