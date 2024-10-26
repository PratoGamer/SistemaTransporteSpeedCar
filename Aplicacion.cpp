#include <iostream>
#include <string.h>

#include "Aplicacion.h"

using namespace std;

// Constructor por Defecto de la Clase
Aplicacion::Aplicacion(){
	eleccion = 0;
	terminarDia = false;
}

// Menu Principal
void Aplicacion::Menu(){
	cout << "\t *** Bienvenido a SpeedCar ***" << endl;
	cout << endl;
	
	while(true){
		cout << "\t 1 -> Usuario." << endl;
		cout << "\t 2 -> Servicio Diario." << endl;
		cout << "\t 3 -> Finalizar Dia." << endl;
		cout << endl;
		
		cout << "\t Ingrese su Seleccion: ";
		cin >> this->eleccion;
		
		switch(this->eleccion) {
			case 1:
				this->MenuUsuario();
		    	break;
		    	
		  	case 2:
		  		this->MenuServicioDiario();
		    	break;
		    	
		    case 3:
		    	this->FinalizarDia();
		    	terminarDia = true;
		    	break;
		    	
		  	default:
		  		cout << "\t Seleccion no Valida" << endl;
		  		cout << endl;
		}
		
		if(terminarDia){
			break;
		}
		
	}
}

// Menu de Usuario
void Aplicacion::MenuUsuario(){
	cout << "\t *** Menu de Usuario ***" << endl;
	cout << endl;
	
	
}

// Menu de Servicio Diario
void Aplicacion::MenuServicioDiario(){
	cout << "\t *** Menu de Servicio Diario ***" << endl;
	cout << endl;
	
	
}

// Finalizar Dia
void Aplicacion::FinalizarDia(){
	cout << "\t *** Fin del Dia ***" << endl;
	cout << endl;
	
	
}

