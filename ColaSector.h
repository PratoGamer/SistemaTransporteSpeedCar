#ifndef COLASECTOR_H
#define COLASECTOR_H

#include <string>
#include <queue>

#include "Usuario.h"

using namespace std;

class ColaSector {
private:
    queue<Usuario> cola;
public:
	// Constructor
    ColaSector();
    
    // Metodos 
    void agregar(Usuario user);
    void eliminar();
    Usuario obtener();
    int cantElementos();
    bool vacia();
    //void  mostrarCola();
    
};

#endif
