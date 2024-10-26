#include "Sector.h"
#include <string> 
#include <iostream>


using namespace std;

Sector::Sector() {
    
}

void Sector::imprimirSectores(){
	for (int i = 0; i < 21; i++) {
        cout << (i+1)<<". " <<sectores[i] << endl;
    }
}
