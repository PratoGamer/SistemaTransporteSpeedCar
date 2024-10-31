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
	
	while(true){
		cout << "\t *** Menu de Servicio Diario ***" << endl << endl;
	
		cout << "\t 1 -> Actualizar Ubicacion del Vehiculo." << endl;
		cout << "\t 2 -> Solicitar Traslado." << endl;
		cout << "\t 3 -> Salir." << endl << endl;
		
		cout << "\t Ingrese su Seleccion: ";
		cin >> this->eleccion;
		cin.get();
		
		switch(this->eleccion) {
		case 1:
			system("cls");
			misChoferes.actualizarUbicacion();
		   	break;
		   	
		case 2:
			system("cls");
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
	// Variables Auxiliares
	string auxSectorOrigen, auxSectorDestino;
	int auxCedula, sectorOrigen, sectorDestino, selChofer = 0; 
	bool encontrado = false;
	bool choferDisponible = false;
	bool choferSelecionado = false;
	vector <int> valorChofer;
	
	cout << "\t *** Solicitar Traslado ***" << endl << endl;
	
	cout << "\t Ingrese su Cedula: ";
	cin >> auxCedula;
	
	for(int i = 0; i < misUsuarios.cantUsuarios(); i++){
		if(auxCedula == misUsuarios.darCedula(i)){
			cout << endl;
			misUsuarios.imprimirUsuario(i);
			cout << endl;
			
			cout << "\t -Sectores Disponibles- " << endl;
			
			misSectores.imprimirSectores();
			
			while(true){
            	cout << endl << "\t Ingrese el Sector de Origen: ";
            	cin >> sectorOrigen;
            	if( (sectorOrigen < 0) || (sectorOrigen > misSectores.cantSectores()) ){
            		cout << endl << "\t Valor Invalido" << endl;
				}
				else{
					break;
				}
			}
			
			while(true){
            	cout << endl << "\t Ingrese el Sector de Destino: ";
            	cin >> sectorDestino;
            	if( (sectorOrigen < 0) || (sectorDestino > misSectores.cantSectores()) ){
            		cout << endl << "\t Valor Invalido" << endl;
				}
				else{
					break;
				}
			}
			auxSectorOrigen = misSectores.darSector(sectorOrigen - 1);
			auxSectorDestino = misSectores.darSector(sectorDestino - 1);
			
			cout << endl << "\t Sector Origen: " << auxSectorOrigen << "\t Sector Destino: " << auxSectorDestino << endl;
			
			system("PAUSE");
			system("cls");
			
			cout << "\t -Buscando Choferes en el Mismo Sector-" << endl << endl;
			
			for(int j = 0; j < misChoferes.cantChoferes(); j++){
				if( auxSectorOrigen.compare(misChoferes.darSector(j))==0 ){
					cout << "\t " << (j+1) << ". ";
					misChoferes.imprimirChofer(j);
					cout << endl;
					
					valorChofer.push_back( (j+1) );
					
					choferDisponible = true;
				}
			}
			
			if(!choferDisponible){
				cout << "\t -No hay Ningun Chofer Disponible en su Zona Intente Mas Tarde-" << endl;
			}
			else{
				while(true){
					cout << endl << "\t Seleccione su Chofer: "; 
					cin >> selChofer;
					
					for(int j = 0; j < valorChofer.size(); j++){
						if( selChofer == valorChofer[j] ){
							choferSelecionado = true;
							break;
						}
					}
					
					if(!choferSelecionado){
						cout << endl << "\t Ingrese un Valor de los Choferes Disponibles en la Lista, Valor Incorrecto" << endl;
					}
					else{
						selChofer--;
						misChoferes.sumarUso(selChofer);
						break;
					}
				}
			}
			misUsuarios.sumarUso(i);
			
			if(!choferSelecionado){
				
			}
			else{
				system("PAUSE");
				system("cls");
				
				float cobro;
				cobro = rand() % (30 + 1);
				cout << "\t -Cobro-" << endl << endl;
				
				cout << "\t Cobro desde: " << auxSectorOrigen << " - Hasta: " << auxSectorDestino << endl;
				cout << "\t $: " << cobro << " | BS BCB: " << (cobro*42.02) << endl;
				
				cout << endl << "\t -Fin del Traslado-" << endl;
			}
			
			encontrado = true;
			break;
		}
	}
	
	if(!encontrado){
		cout << endl << "\t No se Encontro Ningun Usuario con la Cedula: " << auxCedula << endl;
	}
	
	
	system("pause");
	system("cls");
}

// Finalizar Dia
void Aplicacion::FinalizarDia(){
	cout << "\t *** Fin del Dia ***" << endl;
	cout << endl;
	
	misSectores.guardarSectores();
	misUsuarios.guardarUsuarios();
	misChoferes.guardarChoferes();
}
