#ifndef AplicacionH
#define AplicacionH

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
};

#endif
