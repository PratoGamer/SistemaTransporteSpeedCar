#include <iostream>
#include <string.h>

#include "Aplicacion.h"
#include "Persona.h"
#include "Chofer.h"
#include "Usuario.h"

using namespace std;

/* 	Autores:
	-> Luis Rojas
	-> Gabriel Prato
	-> Elianny Romero
	
	Entrega:
	31-10-24
*/


int main(int argc, char** argv) {
	
	Aplicacion* app = new Aplicacion();
	app->Menu();
	
	exit(0);
}
