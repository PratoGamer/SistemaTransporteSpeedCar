#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>

#include "Aplicacion.h"
#include "Persona.h"
#include "Chofer.h"
#include "Usuario.h"
#include "Sector.h"

using namespace std;

#include <vector>
#include <fstream>

/* 	Autores:
	-> Luis Rojas
	-> Elianny Romero
	-> Gabriel Prato
	
	Entrega:
	31-10-24
*/


int main(int argc, char** argv) {
	
	Aplicacion* app = new Aplicacion();
	//app->MenuServicioDiario();
	app->Menu();
	
	cout << "\t Fin de la Aplicacion" << endl;
	system("PAUSE");
	
	exit(0);
}
