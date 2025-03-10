#include <iostream>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <queue>

#include "Persona.h"
#include "Chofer.h"
#include "Usuario.h"
#include "Sector.h"
#include "ColaSector.h"
#include "ListaSector.h"

#include "Aplicacion.h"
#include "Sector.h"
#include "Grafo.h"

using namespace std;

// Constructor por defecto de la clase
Aplicacion::Aplicacion(){
	eleccion = 0;
	terminarDia = false;
	cargarColas();
	cargarListas();
	agregarChoferesLista();
	miGrafo = new Grafo(misSectores.cantSectores());
}

// Menu principal
void Aplicacion::Menu(){
	//Mostrando el menu
	while(true){
		cout << "\t*** Bienvenido a SpeedCar ***" << endl << endl;
		cout << "\t1 -> Usuario." << endl;
		cout << "\t2 -> Servicio Diario." << endl;
		cout << "\t3 -> Finalizar Dia." << endl;
		cout << endl;
		
		cout << "\tIngrese su Seleccion: ";
		cin >> this->eleccion;
		system("cls");
		switch(this->eleccion) {
			case 1:
				//Menu de gestiones
				this->MenuUsuario();
		    	break;
		    	
		  	case 2:
		  		//Menu de Servicio diario
		  		this->MenuServicioDiario();
		    	break;
		    	
		    case 3:
		    	//Finalizar el dia
		    	this->FinalizarDia();
		    	terminarDia = true;
		    	break;
			default:
		  		cout << "\tSeleccion no Valida" << endl;
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
	//Mostrando opciones del menu gestiones
	while(true){
		system("cls");
		cout << "\t *** Menu de Usuario ***" << endl << endl;
	
		cout << "\t1 -> Agregar." << endl;
		cout << "\t2 -> Modificar." << endl;
		cout << "\t3 -> Consultar." << endl;
		cout << "\t4 -> Eliminar." << endl;
		cout << "\t5 -> Salir." << endl;
		cout << endl;
		cout << "\t Ingrese su Seleccion: ";
		cin >> this->eleccion;
	
		switch(this->eleccion) {
			case 1:
				// Submenu para el metodo para agregar
				agregar();
		   		break;
		   	
			case 2:
				// Submenu para el metodo modificar
				modificar();
		   		break;
		    	
			case 3:
				// Submenu para el metodo consultar
				consultar();
		   		break;
		   	
			case 4:
				// Submenu para el metodo eliminar
				eliminar();
		   		break;
		
			case 5:
				salir = true;
		   		break;
		   	
			default:
		  		cout << "\tSeleccion no Valida" << endl;
		  		cout << endl;
		}
		
		if(salir){
			break;
		}
	}
		system("cls");
}

//Metodos del submenude gestiones (MenuUsuario)

//Metodo para agregar
void Aplicacion::agregar() {
    system("cls");
    cout << "\t*** Agregar ***" << endl << endl;
    // Mostrando las opciones que tiene el submenu
    opciones();
    cout << endl;
    cout << "\tIngrese su Seleccion: ";
    cin >> this->eleccion;
    system("cls");
    cout << "\t*** Agregar ***" << endl;
    cout << endl;
    if (eleccion == 1) { 
        // Usando el metodo agregar de la clase Usuario
        misUsuarios.agregarUsuario();
    } else if (eleccion == 2) {
    	// Usando el metodo agregar de la clase Chofer
        misChoferes.agregarChofer();
    } else if (eleccion == 3) {  
        // Usando el metodo agregar de la clase Sector
        cin.get();
        string sectornuevo;
        cout << "\tAgregar sector nuevo: ";
        getline(cin, sectornuevo);
        misSectores.agregarSector(sectornuevo);
    } else if (eleccion == 4) {
    	return;
	}else {
        cout << "\tOpcion no valida." << endl;
    }
    system("pause");
}

//Metodo para modificar
void Aplicacion::modificar(){
	system("cls");
	cout << "\t*** Modificar ***" << endl << endl;
	// Mostrando las opciones que tiene el submenu
	opciones();
	cout << endl;
	cout << "\t Ingrese su Seleccion: ";
	cin >> this->eleccion;
	system("cls");
	cout << "\t*** Modificar ***" << endl;
	cout << endl;
	int cedula;
	if (eleccion == 1) { 
		// Usando el metodo modificar de la clase Usuario
       	cout << "\tIngrese el numero de cedula: ";
       	cin >> cedula;
       	cout << endl;
       	misUsuarios.modificarUsuario(cedula);
    } else if (eleccion == 2) {
    	// Usando el metodo modificar de la clase Chofer
       	cout << "\tIngrese el numero de cedula: ";
       	cin >> cedula;
       	cout << endl;
        misChoferes.modificarChofer(cedula);
    } else if (eleccion == 3) {
        // Usando el metodo modificar de la clase Sectores
        cout << "\t *** Sectores ***" << endl;
        misSectores.imprimirSectores();
        cout << "\tIngrese el numero del sector que desea modificar: " ;
        cin >> this->eleccion;
        
        misSectores.modificarSector(eleccion);
    } else if (eleccion == 4) {
    	return;
	} else {
        cout << "\tOpcion no valida." << endl;
    }
}

//Metodo para consultar
void Aplicacion::consultar(){
	system("cls");
	cout << "\t*** Consultar ***" << endl << endl;
	// Mostrando las opciones que tiene el submenu
	opciones();
	cout << endl;
	cout << "\tIngrese su Seleccion: ";
	cin >> this->eleccion;
	system("cls");
	cout << "\t*** Consultar ***" << endl;
	cout << endl;
	if (eleccion == 1) { 
	 	// Usando el metodo consultar de la clase Usuarios
       	misUsuarios.imprimirUsuarios();
       	cout << endl << "\tUsuarios consultados correctamente!" << endl;
       	system("pause");
    } else if (eleccion == 2) {
        // Usando el metodo consultar de la clase Choferes
	    misChoferes.imprimirChoferes();
        cout << endl << "\tChoferes consultados correctamente!" << endl;
        system("pause");
    } else if (eleccion == 3) {
        // Usando el metodo consultar de la clase Sectores
        misSectores.imprimirSectores();
        cout << endl << "\tSector consultados correctamente!" << endl;
        system("pause"); 
    }else if (eleccion == 4) {
    	return;
	}else {
        cout << "\tOpcion no valida para agregar." << endl;
    }
}

//Metodo para eliminar
void Aplicacion::eliminar(){
	system("cls");
	cout << "\t *** Eliminar ***" << endl << endl;
	// Mostrando las opciones que tiene el submenu
	opciones();
	cout << endl;
	cout << "\t Ingrese su Seleccion: ";
	cin >> this->eleccion;
	system("cls"); 
	cout << "\t *** Eliminar ***" << endl;
	cout << endl;
	int cedula;
	if (eleccion == 1) { 
		// Usando el metodo eliminar de la clase Usuario
       	cout << "\tIngrese el numero de cedula: ";
       	cin >> cedula;
		misUsuarios.eliminarUsuario(cedula);
		system("pause"); 
    } else if (eleccion == 2) {
        // Usando el metodo eliminar de la clase Chofer
       	cout << "\tIngrese el numero de cedula: ";
       	cin >> cedula;
		misChoferes.eliminarChofer(cedula);
		system("pause"); 
    } else if (eleccion == 3) {
        // Usando el metodo eliminar de la clase Sector
        misSectores.imprimirSectores();
        cout << "\tIngrese el numero del sector que desea eliminar: ";
        cin >> cedula;
        misSectores.eliminarSector(cedula);
        system("pause"); 
    }else if (eleccion == 4) {
    	return;
	}else {
        cout << "\tOpcion no valida para agregar." << endl;
    }
}

//opciones de submenu usuario
void Aplicacion::opciones(){
	cout << "\t1 -> Usuario." << endl;
	cout << "\t2 -> Chofer." << endl;
	cout << "\t3 -> Sector." << endl;
	cout << "\t4 -> Salir." << endl;	
}

// Menu de Servicio Diario
void Aplicacion::MenuServicioDiario(){
	bool salir = false;
	int valorsector, valorId, valorSectorAntiguo;
	string auxSector, auxId, auxNuevoSector, auxSectorAntiguo;
	ListaSector auxLista1, auxLista2;
	Chofer auxchofer;
	//Mostrando opciones del menu de Servicio Diario
	while(true){
		cout << "\t *** Menu de Servicio Diario ***" << endl << endl;
	
		cout << "\t1 -> Actualizar Ubicacion del Vehiculo." << endl;
		cout << "\t2 -> Solicitar Traslado." << endl;
		cout << "\t3 -> Finalizar Traslado." << endl;
		cout << "\t4 -> Salir." << endl << endl;
		
		cout << "\tIngrese su Seleccion: ";
		cin >> this->eleccion;
		cin.get();
		system("cls");
		switch(this->eleccion) {
		case 1:{
			// Submenu para el metodo para actualizar ubicacion
			auxNuevoSector = misChoferes.actualizarUbicacion();
			
			if(auxNuevoSector != "no"){
				//Separando los valores retornados
				stringstream input_stringstream(auxNuevoSector);
				
				getline(input_stringstream, auxSector, ',');
	    		getline(input_stringstream, auxId, ',');
	    		getline(input_stringstream, auxSectorAntiguo,',');
	    		
	    		valorSectorAntiguo=misSectores.buscarSectorPorNombre(auxSectorAntiguo);				
				valorsector = atoi(auxSector.c_str());
				valorId = atoi(auxId.c_str());
				//se extraen las listas de los sectores a modificar
				auxLista1 =misListasSectores[valorSectorAntiguo];
				auxLista2 =misListasSectores[valorsector-1];
				
				for(int i =0; i<auxLista1.cantElementos();i++){
					auxchofer = auxLista1.obtener(i);
					//se busca el chofer el cual se movera
					if(auxchofer.getCedula() == misChoferes.darCedulaChofer(valorId)){
						//se hacen las modificaciones para luego volver a guardar las listas
						auxLista1.eliminar(i);
						auxLista2.agregar(auxchofer);
						misListasSectores[valorSectorAntiguo] = auxLista1;
						misListasSectores[valorsector-1] = auxLista2;

					}
				}
				obtenerCola(valorsector - 1, valorId);
			}
			
		   	break;
		}
		   	
		case 2:
			// Submenu para el metodo para solicitar traslado
			solicitarTraslado();
		   	break;
		
		case 3:
			// Submenu para el metodo para finalizar traslado
			finalizarTraslado();
			break;
		
		case 4:
			salir = true;
		   	break;
		   	
		default:
		  	cout << "\tSeleccion no Valida" << endl;
		  	cout << endl;
		}
		
		if(salir){
			break;
		}
	}
	system("cls");
}

// Metodos del Menu Servicio Diario

//solicitar traslado
void Aplicacion::solicitarTraslado(){
	string auxSectorOrigen, auxSectorDestino;
	int auxCedula, sectorOrigen, sectorDestino, selChofer = 0, resp; 
	bool encontrado = false;
	bool choferDisponible = false;
	bool choferSelecionado = false;
	vector <int> valorChofer;
	
	cout << "\t*** Solicitar Traslado ***" << endl << endl;
	
	cout << "\tIngrese su Cedula: ";
	cin >> auxCedula;
	
	for(int i = 0; i < misUsuarios.cantUsuarios(); i++){
		if(auxCedula == misUsuarios.darCedula(i)){
			cout << endl;
			//Mostrando el usuario que pidio el traslado
			misUsuarios.imprimirUsuario(i);
			cout << endl;
			
			cout << "\t*** Sectores Disponibles ***" << endl;
			//Mostrando los sectores que estan disponibles
			misSectores.imprimirSectores();
			
			while(true){
				//Pidiendo donde se encuentra y comparando que sea una opc valida
            	cout << endl << "\tIngresar numero del sector de origen: ";
            	cin >> sectorOrigen;
            	if( (sectorOrigen < 0) || (sectorOrigen > misSectores.cantSectores()) ){
            		cout << endl << "\tValor Invalido" << endl;
				}
				else{
					break;
				}
			}
			
			while(true){
				//Pidiendo hacia donde se dirige y comparando que sea una opc valida
            	cout << endl << "\tIngresar numero del sector de Destino: ";
            	cin >> sectorDestino;
            	if( (sectorOrigen < 0) || (sectorDestino > misSectores.cantSectores()) ){
            		cout << endl << "\tValor Invalido" << endl;
				}
				else{
					break;
				}
			}
			
			//guardando origen y destino
			auxSectorOrigen = misSectores.darSector(sectorOrigen - 1);
			auxSectorDestino = misSectores.darSector(sectorDestino - 1);
			
			cout << endl << "\tSector Origen: " << auxSectorOrigen << "\t Sector Destino: " << auxSectorDestino << endl;
			
			system("PAUSE");
			system("cls");
			
			//Buscando choferes que se encuentren en el sector origen seleccionado
			cout << "\tBuscando Choferes en el Mismo Sector" << endl << endl;
			
			//revisando si hay chiferes disponibles
			for(int j = 0; j < misChoferes.cantChoferes(); j++){
				if( auxSectorOrigen.compare(misChoferes.darSector(j))==0 && misChoferes.disponibilidad(j)){
					choferDisponible = true;
				}
			}
			//mostrando los choferes disponibles
			mostrarChoferesLista(sectorOrigen-1);
			
			//En caso que no se encuentre un chofer en el sector origen se muestra este mensaje
			if(!choferDisponible){
				cout << endl << "\tNo hay Ningun Chofer Disponible en su Zona Intente Mas Tarde" << endl << endl;
				
				//CONSULTA PARA TOMAR LA COLA
				cout << "\tDesea entrar en la cola de espera? \n\t1 -> Si\n\t2 -> No"<<endl;
				cout << "\tIngrese su Seleccion: ";
				cin >>resp;
				// agregando el usuario a la cola en dado caso que si
				if(resp==1){
					agregarUsuarioCola(sectorOrigen - 1,i);
				}
			}else{
				// si se encuentran choferes se muestra una lista con las opc y se pide seleccionar uno
				while(true){
					cout << endl << "\tSeleccione su Chofer: "; 
					cin >> selChofer;
					
					ListaSector auxLista;
					Chofer auxChofer;
					
					auxLista = misListasSectores[sectorOrigen - 1];
					auxChofer = auxLista.obtener(selChofer - 1);
					//comparando el chofer de la lista y recuperando su posicion
					for(int j = 0; j < misChoferes.cantChoferes(); j++){
						if( auxChofer.getCedula() == misChoferes.darCedulaChofer(j) ){
							choferSelecionado = true;
							//Metodo para actualizar el sector del chofer al sector de destino
							misChoferes.actualizarSector(j, auxSectorDestino);
							misChoferes.noDisponible(j);
							break;
						}
					}
					
					if(!choferSelecionado){
						cout << endl << "\t Ingrese un Valor de los Choferes Disponibles en la Lista, Valor Incorrecto" << endl;
					}
					else{
						//sumando el traslado al chofer para luego mostrar en el reporte
						selChofer--;
						misChoferes.sumarUso(selChofer);
						break;
					}		
				}
			}
			// sumando la solicitud del usuario para luego mostrar en el reporte
			misUsuarios.sumarUso(i);
			
			encontrado = true;
			break;
		}
	}
	// en caso de que el usuario no se encuentre agg
	if(!encontrado){
		cout << endl << "\tNo se Encontro Ningun Usuario con la Cedula: " << auxCedula << endl;
	}
	//actualizando la lista
	misListasSectores.clear();
	cargarListas();
	agregarChoferesLista();
	
	system("pause");
	system("cls");
}

//finalizar traslado
void Aplicacion::finalizarTraslado() {
	string auxFinalizar, auxSector, auxId;
	int auxIdSector, valorId;
	cout << "\t *** Finalizar Traslado ***" << endl << endl;
	string placa;
	cout << "\tIngrese la placa: ";
	getline(cin, placa);
	
	//usando metodo de la clase chofer para finalizar el traslado
	auxFinalizar = misChoferes.finalizarTrasladoChofer(placa);
	// separando los valores retornados y separando
	stringstream input_stringstream(auxFinalizar);
				
	getline(input_stringstream, auxSector, ',');
	getline(input_stringstream, auxId, ',');
	
	valorId = atoi(auxId.c_str());
	
	auxIdSector = misSectores.buscarSectorPorNombre(auxSector);
	//viendo si existe una solicitud en el sector
	if(auxIdSector != -1){
		obtenerCola(auxIdSector, valorId);	
	}
	//actualizando las listas con el nuevo sector
	if(auxIdSector != -1){
		misListasSectores.clear();
		cargarListas();
		agregarChoferesLista();
	}
}

//Metodo Crear reporte
void Aplicacion::generarReporte() {
    ofstream reporte("Reporte.txt");

    reporte << "\t*******************************************************" << endl
        << setw(40) << "Choferes" << endl
        << "\t*******************************************************" << endl
        << "\t" << left << setw(15) << "Nombre" << setw(15) << "Apellido" 
        << setw(15) << "Cedula" << setw(15) << "Traslados" << endl
        << "\t*******************************************************" << endl;
	//Llamando al metodo que genera el reporte de chofer
	misChoferes.generarReporte(reporte);

	reporte << endl
        << "\t*********************************************************" << endl
        << right << setw(40) << "\tUsuarios" << endl
        << "\t*********************************************************" << endl
        << "\t" << left << setw(15) << "Nombre" << setw(15) << "Apellido" 
        << setw(15) << "Cedula" << setw(15) << "Solicitudes" << endl
        << "\t*********************************************************" << endl;
	//Llamando al metodo que genera el reporte de usuario
	misUsuarios.generarReporte(reporte);

    reporte.close();
    cout << "\tReporte generado correctamente." << endl <<endl;
}

// Metodo para Finalizar Dia
void Aplicacion::FinalizarDia(){
	cout << "\t*** Fin del Dia ***" << endl;
	cout << endl;
	// Guardando los cambios que se realizan (agregando/eliminando/modificando)
	misSectores.guardarSectores();
	misUsuarios.guardarUsuarios();
	misChoferes.guardarChoferes();
	//generando el reporte
	generarReporte();
}

// Metodos para las Colas
void Aplicacion::cargarColas(){
	int i;
	
	for(i = 0; i < misSectores.cantSectores(); i++){
		misColasSectores.push_back(ColaSector());
	}
	
}

//metodo para agregar los usuarios a las colas
void Aplicacion::agregarUsuarioCola(int origen, int posUser){
	
	ColaSector auxCola;
	Usuario auxUsuario;
	
	auxUsuario = misUsuarios.darUsuario(posUser); //se obtiene el usuario
	//Ajuste que se queria hacer para no dar servicio a alguien que ya estaba en una cola, no se pudo 
	//if(auxUsuario.getEspera()==false){
		
		auxCola = misColasSectores[origen];//se saca la cola del vector de cola
    	auxCola.agregar(auxUsuario);//se guarda el usuario en la cola
    	misColasSectores[origen] = auxCola;//se vuelve a guardar la cola ajustada con el nuevo usuario en espera
    	cout<<"\n\tSe ha agregado a "<<auxUsuario.getNombre()<<" a la cola"<<endl;
    	fflush(stdin);
	//}
}

// metodo para obtener las colas de cada sector
void Aplicacion::obtenerCola(int posicion, int idChofer){
	ColaSector auxColas;
	Usuario auxUsuario;
	auxColas = misColasSectores[posicion];
	
	// comparando si se encuentra una solicitud, mostrarla al chofer
	
	if(auxColas.vacia()){
		return;
	}else{
		// preguntando al chofer si desea el traslado o no
		cout << "\tSe encontro una Solicitud de traslado, desea aceptarla: ";
		cout << "\n\t1 -> Si";
		cout << "\n\t2 -> No";
		cout << endl;
		cout << "\tIngrese su Seleccion: ";
		cin >> this->eleccion;
		if(eleccion == 1){
			while(!auxColas.vacia()){
				system("cls");
				auxUsuario = auxColas.obtener();
			
				// Mostrar el Nombre del Usuario a Preguntar
				cout << "\t*** USUARIO: " << auxUsuario.getNombre() << " ***" << endl;
				
				// Seleccion
				cout << endl << "\tAun desea el traslado?: ";
				cout << endl << "\t1 -> Si";
				cout << endl << "\t2 -> No";
				cout << endl;
				cout << "\tIngrese su Seleccion: ";
				cin >> this->eleccion;
				// comparando la seleccion y haciendo la solicitud o eliminando el traslado
				if(eleccion == 1){
					misChoferes.noDisponible(idChofer);
					auxColas.eliminar();
					system("cls");
					misColasSectores[posicion] = auxColas;
					misListasSectores.clear();
					cargarListas();
					agregarChoferesLista();
					return;
				}else if(eleccion == 2){
					cout << endl << "Su Solicitud ha Sido Eliminada" << endl;
					auxColas.eliminar();
					system("pause");
				}
			}
			cout << endl << "No Hay mas Usuarios en Cola" << endl;
			system("pause");
		}
	}
	// Guardar los Cambios en el Sector que se Modifico
	misColasSectores[posicion] = auxColas;
	system("cls");
}

// Metodos para las Listas
void Aplicacion::cargarListas(){
	int i;
	//  creando listas por sector
	for(i = 0; i < misSectores.cantSectores(); i++){
		misListasSectores.push_back(ListaSector());
	}
	
}

// metodo para agregar los choferes a la lista
void Aplicacion::agregarChoferesLista() {
    int i, j, k;
    vector<Chofer> auxChoferes;

    // Verificar si los sectores y los choferes están inicializados
    if (misSectores.cantSectores() == 0 || misChoferes.cantChoferes() == 0) {
        cout << "Error: Sectores o choferes no inicializados correctamente." << std::endl;
        return;
    }

    for (i = 0; i < misSectores.cantSectores(); i++) {
        auxChoferes.clear();

        // Obtener el sector actual
        string sectorActual = misSectores.darSector(i);

        // Filtrar choferes que pertenecen al sector actual y están disponibles
        for (j = 0; j < misChoferes.cantChoferes(); j++) {
            string sectorChofer = misChoferes.darSector(j);

            // Comparar sectores (asegurando igualdad robusta)
            if (sectorActual == sectorChofer && misChoferes.disponibilidad(j)) {
                auxChoferes.push_back(misChoferes.darChofer(j));
            }
        }

        // Ordenar los choferes del sector por año del vehículo usando Bubble Sort
        if (auxChoferes.size() > 1) {
            for (j = 0; j < auxChoferes.size() - 1; j++) {
                for (k = 0; k < auxChoferes.size() - j - 1; k++) {
                    if (auxChoferes[k].getAnho() > auxChoferes[k + 1].getAnho()) {
                        Chofer temp = auxChoferes[k];
                        auxChoferes[k] = auxChoferes[k + 1];
                        auxChoferes[k + 1] = temp;
                    }
                }
            }
        }

        // virificando si hay choferes para agregar a la lista de sectores
        if (!auxChoferes.empty()) {
            // Viendo si la lista del sector esta inicializada
            if (!misListasSectores[i].estaInicializada()) {
                misListasSectores[i].inicializar();
            }

            // agregando los choferes ordenados a la lista correspondiente
            for (j = 0; j < auxChoferes.size(); j++) {
                misListasSectores[i].agregar(auxChoferes[j]);
            }
        }
    }
}

void Aplicacion::mostrarChoferesLista(int sector){
	int i;
	ListaSector auxLista;
	Chofer auxChofer;
	// obteniendo la lista del sector retornado
	auxLista = misListasSectores[sector];
	
	cout << "\t El Sector es: " << misSectores.darSector(sector) << endl;
	// verificando si hay choferes o no
	if(auxLista.vacia()){
		cout << "\t No hay Choferes en esta zona" << endl;
	}else{
		// mostrando los choferes encontrados
		for(i = 0; i < auxLista.cantElementos(); i++){
			auxChofer = auxLista.obtener(i);
			
			cout << "\t " << (i+1) << ". " << auxChofer.getNombre() << " / " << auxChofer.getMarca() << " / " << auxChofer.getModelo() << " / " << auxChofer.getAnho() << endl;
		}
	}
}

void Aplicacion::mostrarGrafo(){
	miGrafo->imprimirMatriz();
}






