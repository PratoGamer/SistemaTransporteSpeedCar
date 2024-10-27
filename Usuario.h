#ifndef UsuarioH
#define UsuarioH
#include <iostream>
#include <string> 

#include "Persona.h"

using namespace std;

// Clase para los Usuarios
class Usuario : public Persona{
	private:
		
	public:
		// Constructores
		Usuario();
		Usuario(string nombre, string apellido, int edad, int cedula);
		
		// SET
		
		// GET
		
		// Metodos
		void leer();
    	void mostrar();
};

#endif


    

