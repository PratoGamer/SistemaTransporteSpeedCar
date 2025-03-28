#ifndef AplicacionH
#define AplicacionH
#include <vector>
#include <string>

#include "Persona.h"
#include "Chofer.h"
#include "Usuario.h"
#include "Sector.h"
#include "ColaSector.h"
#include "ListaSector.h"
#include "Grafo.h"

using namespace std;

class Aplicacion{
	private: 
		// Atributos
		int eleccion;
		bool terminarDia;
		Sector misSectores;
		Usuario misUsuarios;
		Chofer misChoferes;
		vector<ColaSector> misColasSectores;
		vector<ListaSector> misListasSectores;
		int auxNuevoSector;
		Grafo miGrafo;
		
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
		
		// Metodos para las Colas
		void cargarColas();
		void agregarUsuarioCola(int origen, int posUser);
		void obtenerCola(int posicion, int idChofer);
		
		// Metodos para las Listas
		void cargarListas();
		void agregarChoferesLista();
		void mostrarChoferesLista(int sector);
		
		// Metodos para el Grafo
		void mostrarGrafo();
};

#endif
