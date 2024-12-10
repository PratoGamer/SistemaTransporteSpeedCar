#ifndef LISTASECTOR_H
#define LISTASECTOR_H

#include <string>
#include <vector>

#include "Chofer.h"

using namespace std;

class ListaSector {
private:
    vector<Chofer> lista;
public:
	// Constructor
    ListaSector();
    
    // Metodos 
    void agregar(Chofer user);
    void eliminar(int posicion);
    Chofer obtener(int posicion);
    int cantElementos();
    bool vacia();
    
};

#endif
