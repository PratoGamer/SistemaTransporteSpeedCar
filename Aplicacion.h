#ifndef AplicacionH
#define AplicacionH
#include <string>

using namespace std;

class Aplicacion{
	private: 
		// Atributos
		int eleccion;
		bool terminarDia;
		
	public:
		// Constructor
		Aplicacion();
		
		// Destructor
		~Aplicacion();
		
		// Metodos
		void Menu();
		void MenuUsuario();
		void MenuServicioDiario();
		void FinalizarDia();
		//Metodos MenuUsuario
		void agregar();
		void modificar();
		void consultar();
		void eliminar();
		void opciones();
		//Metodos MenuServicioDiario
		void solicitarTraslado();
		void actualizarUbicacion();
};

#endif
