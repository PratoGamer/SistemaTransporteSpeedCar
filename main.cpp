#include <iostream>

#include "Aplicacion.h"

using namespace std;

/* 	Autores:
	-> Luis Rojas CI: 28230278
	-> Elianny Romero CI: 30646057
	-> Gabriel Prato CI: 29907722
	-> Osmar Porras CI: 31509694
	
	Entrega:
	11-12-24
*/


int main(int argc, char** argv) {
	Aplicacion* app = new Aplicacion();
	
	
	app->mostrarChoferesLista(19);
	
	
	//app->Menu();
	
	
	cout << "\tFin de la Aplicacion" << endl;
	system("PAUSE");
	
	exit(0);
}
