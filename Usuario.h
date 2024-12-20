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
		
		// Metodos
    	void cargarUsuarios();
    	void imprimirUsuarios();
    	void agregarUsuario();
    	void eliminarUsuario(int cedula);
    	void modificarUsuario(int cedula);
    	void guardarUsuarios();
    	int cantUsuarios();
    	int darCedula(int i);
    	void imprimirUsuario(int i);
    	void sumarUso(int i);
    	int cantUsosUsuario(int i);
    	void generarReporte(ofstream& reporte);
    	Usuario darUsuario(int pos);
};

#endif


    

