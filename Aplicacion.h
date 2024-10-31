#ifndef AplicacionH
#define AplicacionH
#include <vector>
#include <string>

#include "Persona.h"
#include "Chofer.h"
#include "Usuario.h"
#include "Sector.h"

using namespace std;

class Aplicacion{
	private: 
		// Atributos
		int eleccion;
		bool terminarDia;
		Sector misSectores;
		
		// Vectores para Almacenar 
		vector <Chofer> choferes;
		vector <Usuario> usuarios;
		
	public:
		// Constructor
		Aplicacion();
		
		// Cargar Datos
		void cargarDatosChoferUsuario();
		
		// Destructor
		~Aplicacion();
		
		// Metodos
		void Menu();
		void MenuUsuario();
		void MenuServicioDiario();
		void FinalizarDia();
		
		// Metodos MenuUsuario
		void agregar();
		void modificar();
		void consultar();
		void eliminar();
		void opciones();
		
		// Metodos MenuServicioDiario
		void solicitarTraslado();
		void actualizarUbicacion();
		
		void cargarSectores();
		
		
		
};

#endif
