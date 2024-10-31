#ifndef UsuarioH
#define UsuarioH
#include <iostream>
#include <string> 
#include <vector>

#include "Persona.h"

using namespace std;

// Clase para los Usuarios
class Usuario : public Persona{
	private:
		vector <Usuario> usuarios;
	public:
		// Constructores
		Usuario();
		Usuario(string nombre, string apellido, int edad, int cedula);
		
		// SET
		
		// GET
		
		// Metodos
		void leer();
    	void mostrar();
    	void cargarUsuarios();
    	void imprimirUsuarios();
    	void eliminarUsuario(int cedula);
    	void modificarUsuario(int cedula);
};

#endif


    

