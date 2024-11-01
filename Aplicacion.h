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
		Usuario misUsuarios;
		Chofer misChoferes;
		
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
		void finalizarTraslado();
		void actualizarUbicacion();
		
		// Metodo Crear reporte
		void generarReporte();
};

#endif
