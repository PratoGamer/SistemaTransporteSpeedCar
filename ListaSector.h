#ifndef LISTASECTOR_H
#define LISTASECTOR_H

#include <string>
#include <list>

#include "Chofer.h"

using namespace std;

class ListaSector {
private:
    list<Chofer> lista;
public:
	// Constructor
    ListaSector();
    
    // Metodos 
    void agregarFinal(Chofer user);
    //void eliminar(Chofer user);
    //Chofer obtener(int posicion);
    int cantElementos();
    bool vacia();
    
};

#endif
