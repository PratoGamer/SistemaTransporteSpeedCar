#include <iostream>

#include "Aplicacion.h"

using namespace std;

/* 	Autores:
	-> Luis Rojas
	-> Elianny Romero
	-> Gabriel Prato
	
	Entrega:
	31-10-24
*/


int main(int argc, char** argv) {
	Aplicacion* app = new Aplicacion();
	app->Menu();
	
	cout << "\t Fin de la Aplicacion" << endl;
	system("PAUSE");
	
	exit(0);
}
