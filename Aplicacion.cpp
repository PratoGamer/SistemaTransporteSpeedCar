#include <iostream>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <sstream>

#include "Persona.h"
#include "Chofer.h"
#include "Usuario.h"

#include "Aplicacion.h"
#include "Sector.h"

using namespace std;

// Constructor por Defecto de la Clase
Aplicacion::Aplicacion(){
	eleccion = 0;
	terminarDia = false;
	cargarDatosChoferUsuario();
}

// Cargar los Datos de Chofer y Usuario
void Aplicacion::cargarDatosChoferUsuario(){
	
	/*
	Usuario user;
	
	cout << "Carga de usuarios" << endl << endl;
	
	for(int num = 0; num < usuarios.size(); num++){
		user = usuarios.at(num);
		user.mostrar();
	}
	
	cout << endl << endl;
	
	Chofer driver;
	
	cout << "Carga de choferes" << endl << endl;
	
	for(int num = 0; num < choferes.size(); num++){
		driver = choferes.at(num);
		driver.mostrar();
	}
	
	cout << endl << endl;
	
	cout << "Usuarios: " << usuarios.size() << " | Choferes: " << choferes.size() << endl;
	*/
	
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
void Aplicacion::agregar() {
    system("cls");
    cout << "\t *** Agregar ***" << endl;
    cout << endl;
    opciones();
    cout << endl;
    cout << "\t Ingrese su Seleccion: ";
    cin >> this->eleccion;
    system("cls");
    cout << "\t *** Agregar ***" << endl;
    cout << endl;
    if (eleccion == 1) { 
        // Agregar Usuario
        misUsuarios.agregarUsuario();
    } else if (eleccion == 2) {
        misChoferes.agregarChofer();
        
    } else if (eleccion == 3) {  
        // Agregar Sector
        cin.get();
        string sectornuevo;
        cout << "Agregar sector nuevo: ";
        getline(cin, sectornuevo);
        misSectores.agregarSector(sectornuevo);
    } else {
        cout << "\t Opcion no valida para agregar." << endl;
    }
    
    system("pause");
}


void Aplicacion::modificar(){
	system("cls");
	cout << "\t *** Modificar ***" << endl;
	cout << endl;
	opciones();
	cout << endl;
	cout << "\t Ingrese su Seleccion: ";
	cin >> this->eleccion;
	if (eleccion == 1) { 
       	system("cls");
       	int cedula;
       	cout << "Ingrese el numero de cedula: ";
       	cin >> cedula;
       	misUsuarios.modificarUsuario(cedula);
    } else if (eleccion == 2) {  
        system("cls");
        int cedula;
       	cout << "Ingrese el numero de cedula: ";
       	cin >> cedula;
        misChoferes.modificarChofer(cedula);
    } else if (eleccion == 3) {
		system("cls");  
        // Modificar Sectores
        cout << "\t *** Sectores ***" << endl;
        misSectores.imprimirSectores();
        cout << "Ingrese el numero del sector que desea modificar: " << endl;
        cin >> this->eleccion;
        string nuevoSector;
        cout << "Ingrese el nuevo sector: ";
        cin >> nuevoSector;
        misSectores.modificarSector(eleccion, nuevoSector);
    }
}

void Aplicacion::consultar(){
	system("cls");
	cout << "\t *** Consultar ***" << endl;
	cout << endl;
	opciones();
	cout << endl;
	cout << "\t Ingrese su Seleccion: ";
	cin >> this->eleccion;
	
	if (eleccion == 1) { 
		system("cls");
       	misUsuarios.imprimirUsuarios();
       	system("pause");
    } else if (eleccion == 2) {  
        system("cls");
        misChoferes.imprimirChoferes();
        cout << "Choferes consultados correctamente!" << endl;
        system("pause");
    } else if (eleccion == 3) {
		system("cls");  
        // Consultar Sectores
        cout << "\t *** Sectores ***" << endl;
        misSectores.imprimirSectores();
        cout << "Sector consultados correctamente!" << endl;
        system("pause"); 
    }
}

void Aplicacion::eliminar(){
	system("cls");
	cout << "\t *** Eliminar ***" << endl;
	cout << endl;
	opciones();
	cout << endl;
	cout << "\t Ingrese su Seleccion: ";
	cin >> this->eleccion;
	if (eleccion == 1) { 
		system("cls"); 
		int cedula;
       	cout << "Ingrese el numero de cedula: ";
       	cin >> cedula;
		misUsuarios.eliminarUsuario(cedula);
    } else if (eleccion == 2) {  
        system("cls");
        int cedula;
       	cout << "Ingrese el numero de cedula: ";
       	cin >> cedula;
		misChoferes.eliminarChofer(cedula);
    } else if (eleccion == 3) {
		system("cls");  
        // Eliminar Sectores
        int cedula;
        cout << "\t *** Sectores ***" << endl;
        misSectores.imprimirSectores();
        cout << "Ingrese el numero del sector que desea eliminar: " << endl;
        cin >> cedula;
        misSectores.eliminarSector(cedula);
    }
}

void Aplicacion::opciones(){
	cout << "\t 1 -> Usuario." << endl;
	cout << "\t 2 -> Chofer." << endl;
	cout << "\t 3 -> Sector." << endl;
}


// Menu de Servicio Diario
void Aplicacion::MenuServicioDiario(){
	// Variables Control
	bool salir = false;
	
	cout << "\t *** Menu de Servicio Diario ***" << endl << endl;
	
	cout << "\t 1 -> Actualizar Ubicacion del Vehiculo." << endl;
	cout << "\t 2 -> Solicitar Traslado." << endl;
	cout << "\t 3 -> Salir." << endl << endl;
	
	while(true){
		cout << "\t Ingrese su Seleccion: ";
		cin >> this->eleccion;
		cin.get();
		
		switch(this->eleccion) {
		case 1:
			misChoferes.actualizarUbicacion();
		   	break;
		   	
		case 2:
			solicitarTraslado();
		   	break;
		
		case 3:
			salir = true;
		   	break;
		   	
		default:
		  	cout << "\t Seleccion no Valida" << endl;
		  	cout << endl;
		}
		
		if(salir){
			break;
		}
		
	}
	system("cls");
}

// Metodos MenuServicioDiario


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
	
	misSectores.guardarSectores();
	misUsuarios.guardarUsuarios();
	misChoferes.guardarChoferes();
}
