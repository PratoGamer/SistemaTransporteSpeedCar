#include <iostream>

#include "Aplicacion.h"

using namespace std;

/* 	Autores:
	-> Luis Rojas CI: 28230278
	-> Elianny Romero CI: 30646057
	-> Gabriel Prato CI: 29907722
	-> Osmar Porras CI: 31509694
	
	Entrega:
	13-03-25
*/


int main(int argc, char** argv) {
	Aplicacion* app = new Aplicacion();
	
	app->Menu();
	
	cout << "\t Fin de la Aplicacion" << endl;
	system("PAUSE");
	
	exit(0);
}
