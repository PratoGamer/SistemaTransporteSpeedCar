#include <iostream>
#include <string.h>

#include "Aplicacion.h"
#include "Sector.h"

using namespace std;

// Constructor por Defecto de la Clase
Aplicacion::Aplicacion(){
	eleccion = 0;
	terminarDia = false;
}

// Menu Principal
void Aplicacion::Menu(){
	while(true){
		cout << "\t *** Bienvenido a SpeedCar ***" << endl;
		cout << endl;
		cout << "\t 1 -> Usuario." << endl;
		cout << "\t 2 -> Servicio Diario." << endl;
		cout << "\t 3 -> Finalizar Dia." << endl;
		cout << endl;
		
		cout << "\t Ingrese su Seleccion: ";
		cin >> this->eleccion;
		system("cls");
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
	
	cout << "\t 1 -> Agregar." << endl;
	cout << "\t 2 -> Modificar." << endl;
	cout << "\t 3 -> Consultar." << endl;
	cout << "\t 4 -> Eliminar." << endl;
	cout << "\t 5 -> Salir." << endl;
	cout << endl;
	cout << "\t Ingrese su Seleccion: ";
	cin >> this->eleccion;
	
	switch(this->eleccion) {
		case 1:
			agregar();
			//system("pause");
		   	break;
		   	
		case 2:
			modificar();
		   	break;
		    	
		case 3:
			consultar();
		   	break;
		   	
		case 4:
			eliminar();
		   	break;
		
		case 5:
		   	break;
		   	
		default:
		  	cout << "\t Seleccion no Valida" << endl;
		  	cout << endl;
		}
		system("cls");
}

//Metodos MenuUsuario

void Aplicacion::agregar(){
	system("cls");
	cout << "\t *** Agregar ***" << endl;
	cout << endl;
	opciones();
	cout << endl;
	cout << "\t Ingrese su Seleccion: ";
	cin >> this->eleccion;
}

void Aplicacion::modificar(){
	system("cls");
	cout << "\t *** Modificar ***" << endl;
	cout << endl;
	opciones();
	cout << endl;
	cout << "\t Ingrese su Seleccion: ";
	cin >> this->eleccion;
}

void Aplicacion::consultar(){
	system("cls");
	cout << "\t *** Consultar ***" << endl;
	cout << endl;
	opciones();
	cout << endl;
	cout << "\t Ingrese su Seleccion: ";
	cin >> this->eleccion;
}

void Aplicacion::eliminar(){
	system("cls");
	cout << "\t *** Eliminar ***" << endl;
	cout << endl;
	opciones();
	cout << endl;
	cout << "\t Ingrese su Seleccion: ";
	cin >> this->eleccion;
}

void Aplicacion::opciones(){
	cout << "\t 1 -> Usuario." << endl;
	cout << "\t 2 -> Chofer." << endl;
	cout << "\t 3 -> Sector." << endl;
}


// Menu de Servicio Diario
void Aplicacion::MenuServicioDiario(){
	cout << "\t *** Menu de Servicio Diario ***" << endl;
	cout << endl;
	
	cout << "\t 1 -> Actualizar ubicacion del vehiculo." << endl;
	cout << "\t 2 -> Solicitar Traslado." << endl;
	cout << "\t 3 -> Salir." << endl;
	cout << endl;
	cout << "\t Ingrese su Seleccion: ";
	cin >> this->eleccion;
	
	switch(this->eleccion) {
		case 1:
			actualizarUbicacion();
		   	break;
		   	
		case 2:
			solicitarTraslado();
		   	break;
		
		case 3:
		   	break;
		   	
		default:
		  	cout << "\t Seleccion no Valida" << endl;
		  	cout << endl;
		}
		system("cls");
}
//Metodos MenuServicioDiario

void Aplicacion::actualizarUbicacion(){
	system("cls");
	cout << "\t *** Actualizar Ubicacion ***" << endl;
	cout << endl;
	
	cout << "\tNumero de Placa: "<< endl;
	cout << "\tSector Actual: "<< endl;
	
	system("pause");
}

void Aplicacion::solicitarTraslado(){
	system("cls");
	cout << "\t *** Solicitar Traslado ***" << endl;
	cout << endl;
	
	cout << "\tCedula: "<< endl;
	cout << "\tSector Origen: "<< endl;
	cout << "\tSector Destino: "<< endl;
	
	system("pause");
}

// Finalizar Dia
void Aplicacion::FinalizarDia(){
	cout << "\t *** Fin del Dia ***" << endl;
	cout << endl;
	
	
}
