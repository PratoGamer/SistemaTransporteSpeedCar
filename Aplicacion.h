#ifndef AplicacionH
#define AplicacionH
#include <string>

using namespace std;

class Aplicacion{
	private:
		int eleccion;
	
	public:
		Aplicacion();
		~Aplicacion();
		void Menu();
		void subMenu();
};

#endif
