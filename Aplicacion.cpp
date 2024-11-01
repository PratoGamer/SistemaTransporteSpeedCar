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
	bool salir = false;
	while(true){
		system("cls");
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

//Metodos MenuUsuario

//Metodo para agregar
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
    	// Agregar Chofer
        misChoferes.agregarChofer();
    } else if (eleccion == 3) {  
        // Agregar Sector
        cin.get();
        string sectornuevo;
        cout << "\tAgregar sector nuevo: ";
        getline(cin, sectornuevo);
        misSectores.agregarSector(sectornuevo);
    } else {
        cout << "\t Opcion no valida para agregar." << endl;
    }
    system("pause");
}
//Metodo para modificar
void Aplicacion::modificar(){
	system("cls");
	cout << "\t *** Modificar ***" << endl;
	cout << endl;
	opciones();
	cout << endl;
	cout << "\t Ingrese su Seleccion: ";
	cin >> this->eleccion;
	system("cls");
	cout << "\t *** Modificar ***" << endl;
	cout << endl;
	int cedula;
	if (eleccion == 1) { 
		// Modificar Usuario
       	cout << "\tIngrese el numero de cedula: ";
       	cin >> cedula;
       	cout << endl;
       	misUsuarios.modificarUsuario(cedula);
    } else if (eleccion == 2) {
    	// Modificar Chofer
       	cout << "\tIngrese el numero de cedula: ";
       	cin >> cedula;
       	cout << endl;
        misChoferes.modificarChofer(cedula);
    } else if (eleccion == 3) {
        // Modificar Sectores
        cout << "\t *** Sectores ***" << endl;
        misSectores.imprimirSectores();
        cout << "\tIngrese el numero del sector que desea modificar: " << endl;
        cin >> this->eleccion;
        string nuevoSector;
        cout << "\tIngrese el nuevo sector: ";
        cin >> nuevoSector;
        misSectores.modificarSector(eleccion, nuevoSector);
    }
}

//Metodo para consultar
void Aplicacion::consultar(){
	system("cls");
	cout << "\t *** Consultar ***" << endl;
	cout << endl;
	opciones();
	cout << endl;
	cout << "\t Ingrese su Seleccion: ";
	cin >> this->eleccion;
	system("cls");
	cout << "\t *** Consultar ***" << endl;
	cout << endl;
	if (eleccion == 1) { 
	 	// Consultar Usuarios
       	misUsuarios.imprimirUsuarios();
       	cout << endl << "\tUsuarios consultados correctamente!" << endl;
       	system("pause");
    } else if (eleccion == 2) {
        // Consultar Choferes
	    misChoferes.imprimirChoferes();
        cout << endl << "\tChoferes consultados correctamente!" << endl;
        system("pause");
    } else if (eleccion == 3) {
        // Consultar Sectores
        misSectores.imprimirSectores();
        cout << endl << "\tSector consultados correctamente!" << endl;
        system("pause"); 
    }
}

//Metodo para eliminar
void Aplicacion::eliminar(){
	system("cls");
	cout << "\t *** Eliminar ***" << endl;
	cout << endl;
	opciones();
	cout << endl;
	cout << "\t Ingrese su Seleccion: ";
	cin >> this->eleccion;
	system("cls"); 
	cout << "\t *** Eliminar ***" << endl;
	cout << endl;
	int cedula;
	if (eleccion == 1) { 
		// Eliminar Usuario
       	cout << "\tIngrese el numero de cedula: ";
       	cin >> cedula;
		misUsuarios.eliminarUsuario(cedula);
    } else if (eleccion == 2) {
        // Eliminar Chofer
       	cout << "\tIngrese el numero de cedula: ";
       	cin >> cedula;
		misChoferes.eliminarChofer(cedula);
    } else if (eleccion == 3) {
        // Eliminar Sector
        misSectores.imprimirSectores();
        cout << "\tIngrese el numero del sector que desea eliminar: " << endl;
        cin >> cedula;
        misSectores.eliminarSector(cedula);
    }
}
//opciones de submenu usuario
void Aplicacion::opciones(){
	cout << "\t 1 -> Usuario." << endl;
	cout << "\t 2 -> Chofer." << endl;
	cout << "\t 3 -> Sector." << endl;
}

// Menu de Servicio Diario
void Aplicacion::MenuServicioDiario(){
	bool salir = false;
	
	while(true){
		cout << "\t *** Menu de Servicio Diario ***" << endl << endl;
	
		cout << "\t 1 -> Actualizar Ubicacion del Vehiculo." << endl;
		cout << "\t 2 -> Solicitar Traslado." << endl;
		cout << "\t 3 -> Finalizar Traslado." << endl;
		cout << "\t 4 -> Salir." << endl << endl;
		
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
			system("cls");
			finalizarTraslado();
			break;
		
		case 4:
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

//soliictar traslado
void Aplicacion::solicitarTraslado(){
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
				if( auxSectorOrigen.compare(misChoferes.darSector(j))==0 && misChoferes.disponibilidad(j)){
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
							//aqui
							misChoferes.actualizarSector(selChofer - 1, auxSectorDestino);
							misChoferes.noDisponible(selChofer - 1);
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

//finalizar traslado
void Aplicacion::finalizarTraslado() {
	cout << "\t *** Finalizar Traslado ***" << endl << endl;
	string placa;
	cout << "\tIngrese la placa: ";
	getline(cin, placa);
	misChoferes.disponiblePorPlaca(placa);
}

//Metodo Crear reporte

void Aplicacion::generarReporte() {
    ofstream reporte("Reporte.txt");

    // Escribir encabezado para Choferes
    reporte << "Choferes:" << endl;
    misChoferes.generarReporte(reporte);

    // Separador entre secciones
    reporte << endl << "Usuarios:" << endl;
    misUsuarios.generarReporte(reporte);

    reporte.close();
    cout << "Reporte generado correctamente." << endl;
}

// Finalizar Dia
void Aplicacion::FinalizarDia(){
	cout << "\t *** Fin del Dia ***" << endl;
	cout << endl;
	
	misSectores.guardarSectores();
	misUsuarios.guardarUsuarios();
	misChoferes.guardarChoferes();
	generarReporte();
}
