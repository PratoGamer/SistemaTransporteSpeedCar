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

/*void ColaSector::mostrarCola(){
	int i;
	Usuario aux;
	cout<<"\n\tMostrando la cola\n"<<endl;
	for(i=0;i<cola.size();i++){
		aux=cola[i];
		cout<<aux.getNombre()<<endl;
	}
	for(auto it = cola.begin(); it!=cola.end();++it){
		aux = it;
		cout<<aux.getNombre()<<endl;
	}
}*/

