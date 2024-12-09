#include "Chofer.h"
#include "Aplicacion.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

// Constructores
Chofer::Chofer() : Persona() {
    this->marca = "";
    this->modelo = "";
    this->anho = 0;
    this->placa = "";
    this->sector = "";
    cargarChoferes();
}

Chofer::Chofer(string nombre, string apellido, int edad, int cedula, string marca, string modelo, int anho, string placa, string sector) 
    : Persona(nombre, apellido, edad, cedula) {
    this->marca = marca;
    this->modelo = modelo;
    this->anho = anho;
    this->placa = placa;
    this->sector = sector;
    this->disponible = true;
}

// SET
void Chofer::setMarca(string marca) {
    this->marca = marca;
}
void Chofer::setModelo(string modelo) {
    this->modelo = modelo;
}
void Chofer::setAnho(int anho) {
    this->anho = anho;
}
void Chofer::setPlaca(string placa) {
    this->placa = placa;
}
void Chofer::setSector(string sector) {
    this->sector = sector;
}
void Chofer::setDisponible(bool disponible) {
    this->disponible = disponible;
}

// GET
string Chofer::getMarca() {
    return marca;
}
string Chofer::getModelo() {
    return modelo;
}
int Chofer::getAnho() {
    return anho;
}
string Chofer::getPlaca() {
    return placa;
}
string Chofer::getSector() {
    return sector;
}
bool Chofer::getDisponible() {
    return disponible;
}

//Metodos

//Cargando el vector
void Chofer::cargarChoferes(){
	ifstream txtChoferes("Choferes.txt");
	
	string auxDatos, auxNombre, auxApellido, auxEdad, auxCedula;
	int auxEdadInt, auxCedulaInt;
	string auxMarca, auxModelo, auxAnho, auxPlaca, auxSector;
	int auxAnhoInt;
	int cantSectores;
	
	cantSectores = misSectores.cantSectores();
	
	while(getline(txtChoferes, auxDatos)){
		
		stringstream input_stringstream(auxDatos);
		
		getline(input_stringstream, auxNombre, '-');
		getline(input_stringstream, auxApellido, '-');
		getline(input_stringstream, auxEdad, '-');
		auxEdadInt = atoi(auxEdad.c_str());
		getline(input_stringstream, auxCedula, '-');
		auxCedulaInt = atoi(auxCedula.c_str());
		getline(input_stringstream, auxMarca, '-');
		getline(input_stringstream, auxModelo, '-');
		getline(input_stringstream, auxPlaca, '-');
		getline(input_stringstream, auxAnho, '-');
		auxAnhoInt = atoi(auxAnho.c_str());
		//dando un sector de forma aleatoria
		auxSector = misSectores.darSector(rand() % cantSectores);
		
		choferes.push_back(Chofer(auxNombre, auxApellido, auxEdadInt, auxCedulaInt, auxMarca, auxModelo, auxAnhoInt, auxPlaca, auxSector));
		
	}
	txtChoferes.close();
}

//Mostrar datos
void Chofer::imprimirChoferes(){
    for (int i = 0; i < choferes.size(); ++i) {
        cout << "\t"<< (i + 1) << ". " << choferes[i].getNombre() << " "
             << choferes[i].getApellido() << " "
             << choferes[i].getEdad() << " "
             << choferes[i].getCedula() << " "
             << choferes[i].getMarca() << " "
             << choferes[i].getModelo() << " "
             << choferes[i].getPlaca() << " "
             << choferes[i].getAnho() << " "
             << choferes[i].getSector() <<endl;
    }
}

//Actualizar la ubicacion
int Chofer::actualizarUbicacion() {
    string auxPlaca, nuevoSector;
    int valorSector;
    bool encontrado = false;
    
    // Solicitar datos del chofer
    cout << "\t *** Actualizar Ubicacion del Vehiculo ***" << endl << endl;
    
    cout << "\t Ingrese la Placa del Vehiculo: ";
    getline(cin, auxPlaca);

    for (int i = 0; i < choferes.size(); ++i) {
        if (choferes[i].getPlaca() == auxPlaca) {
            // Mostrar el sector actual
            cout << endl << "\t Ubicacion Actual: " << choferes[i].getSector() << endl << endl;

            // Mostrando los sectores disponibles
            misSectores.imprimirSectores();
            
            // Solicitar el sector nuevo
            while(true){
                cout << endl << "\t Ingrese el Nuevo Sector: ";
                cin >> valorSector;
                if( (valorSector < 0) || (valorSector > misSectores.cantSectores()) ){
                    cout << endl << "\t Valor Invalido" << endl;
                }
                else{
                    break;
                }
            }
            
            nuevoSector = misSectores.darSector((valorSector - 1));

            cout << endl << "\t Sector Seleccionado: " << nuevoSector << endl;

            choferes[i].setSector(nuevoSector);

            cout << endl << "\t Ubicacion del Chofer Modificada Correctamente." << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << endl << "\t No se Encontro Ningun Chofer con la Placa: " << auxPlaca << endl;
        // Si no se encuentra el chofer, podemos retornar un valor especial, por ejemplo, -1.
        return -1;
    }
    system("PAUSE");
    system("cls");
    
    // Retornar el valor del sector seleccionado
    return valorSector;
}


// Agregar nuevo chofer
void Chofer::agregarChofer() {
    int edad, cedula, anho;

    // Solicitar Datos del chofer
    cout << "\tIngrese el nombre: ";
    cin.ignore();
    getline(cin, nombre);
    cout << "\tIngrese el apellido: ";
    getline(cin, apellido);
    cout << "\tIngrese la edad: ";
    cin >> edad;
    cout << "\tIngrese la cedula: ";
    cin >> cedula;
    cin.ignore();
    cout << "\tIngrese la marca del vehiculo: ";
    getline(cin, marca);
    cout << "\tIngrese el modelo del vehiculo: ";
    getline(cin, modelo);
    cout << "\tIngrese la placa del vehiculo: ";
    getline(cin, placa);
    cout << "\tIngrese el anho del vehiculo: ";
    cin >> anho;
    cin.ignore();
    cout << "\tIngrese el sector: ";
    getline(cin, sector);
	//guardandolos en el vector
    Chofer nuevoChofer(nombre, apellido, edad, cedula, marca, modelo, anho, placa, sector);
    choferes.push_back(nuevoChofer);

    cout << endl << "\tNuevo chofer agregado correctamente." << endl;
}

// Metodo para modificar
void Chofer::modificarChofer(int cedula) {
    for (int i = 0; i < choferes.size(); ++i) {
        if (choferes[i].getCedula() == cedula) {
        	// Pidiendo datos del chofer a modificar
            string nuevoNombre, nuevoApellido, nuevaMarca, nuevoModelo, nuevaPlaca, nuevoSector;
            int nuevaEdad, nuevoAnho;
            cout << "\tNuevo nombre: ";
            cin.ignore();
            getline(cin, nuevoNombre);
            cout << "\tNuevo apellido: ";
            getline(cin, nuevoApellido);
            cout << "\tNueva edad: ";
            cin >> nuevaEdad;
            cout << "\tNueva marca del vehiculo: ";
            cin.ignore();
            getline(cin, nuevaMarca);
            cout << "\tNuevo modelo del vehiculo: ";
            getline(cin, nuevoModelo);
            cout << "\tNueva placa del vehiculo: ";
            getline(cin, nuevaPlaca);
            cout << "\tNuevo anho del vehiculo: ";
            cin >> nuevoAnho;
            cin.ignore();
            cout << "\tNuevo sector: ";
            getline(cin, nuevoSector);
			// guardandolo en el vector
            choferes[i] = Chofer(nuevoNombre, nuevoApellido, nuevaEdad, cedula, nuevaMarca, nuevoModelo, nuevoAnho, nuevaPlaca, nuevoSector);
            cout << endl << "\tChofer modificado correctamente." << endl;
            return;
        }
    }
    cout << "\tChofer con la cedula " << cedula << " no encontrado." << endl;
    system("pause");
}

// Eliminar chofer
void Chofer::eliminarChofer(int cedula) {
    for (int i = 0; i < choferes.size(); ++i) {
    	// if para buscar el chofer a eliminar
        if (choferes[i].getCedula() == cedula) {
            choferes.erase(choferes.begin() + i);
            cout << endl << "\tChofer eliminado correctamente." << endl;
            return;
        }
    }
    cout << endl << "\tChofer con la cedula " << cedula << " no encontrado." << endl;
}

//Metodo para actualizar el txt donde se guardan los datos de choferes
void Chofer::guardarChoferes() {
    ofstream txtChoferes("Choferes.txt");
    for (int i = 0; i < choferes.size(); ++i) {
        txtChoferes << choferes[i].getNombre() << "-"
                    << choferes[i].getApellido() << "-"
                    << choferes[i].getEdad() << "-"
                    << choferes[i].getCedula() << "-"
                    << choferes[i].getMarca() << "-"
                    << choferes[i].getModelo() << "-"
                    << choferes[i].getPlaca() << "-"
                    << choferes[i].getAnho() << endl;
    }
    txtChoferes.close();
}
//obteniendo el tamanho del vector
int Chofer::cantChoferes(){
	return choferes.size();
}
//dando el sector del chofer
string Chofer::darSector(int j){
	return choferes[j].getSector();
}
// imprimiendo los choferes disponibles en el origen
void Chofer::imprimirChofer(int j){
	cout << "Nombre: " << choferes[j].getNombre() << " Marca: " << choferes[j].getMarca() << " Modelo: " << choferes[j].getModelo() << " Placa: " << choferes[j].getPlaca();
}
// suamando los traslados al chofer
void Chofer::sumarUso(int j){
	choferes[j].usado();
}
// obteniendo la cantidad de translados del chofer
int Chofer::cantUsosChofer(int j){
	return choferes[j].cantUsos();
}
// obteniendo si el chofer se encuentra disponible
bool Chofer::disponibilidad(int i) {
    return choferes[i].disponible;
}
// metodo para cuando el usuario selecciona al chofer pase a no disponible
void Chofer::noDisponible(int i){
	choferes[i].disponible = false;
}
// metodo para actualizar el sector del chofer
void Chofer::actualizarSector(int i, string destino){
	choferes[i].sector = destino;
}
// metodo para finalozar el traslado y pasar al chofer a disponible
void Chofer::finalizarTrasladoChofer(string placa) {
	for(int i = 0; i < choferes.size(); ++i) {
        if(choferes[i].placa == placa && !choferes[i].disponible) {
        	system("cls");
				
			float cobro;
			cobro = rand() % (30 + 1);
			cout << "\t\t*** Cobro ***" << endl << endl;
				
			cout << "\tCobro Hasta el destino: " << choferes[i].sector << endl;
			cout << "\t$: " << cobro << "usd | BS BCV: " << (cobro*42.02) << "bss" << endl;
        	
        	cout << endl << "\t   *** Fin del Traslado ***" << endl;
        	
        	system("pause");
        	system("cls");
        	// pasando el chofer a disponible
        	choferes[i].disponible = true;
            return;
        }
    }
    //mostrando mensaje en caso que no se a realizado un traslado
    cout << endl << "\tAun no a realizado un traslado" << endl;
    system("pause");
    system("cls");
}
// Generando el reporte de chofer
void Chofer::generarReporte(ofstream& reporte){
    for (int i = 0; i < choferes.size(); ++i) {
        if (choferes[i].cantUsos() > 0) {
            reporte << "\t" << left 
                << setw(15) << choferes[i].getNombre()
                << setw(15) << choferes[i].getApellido()
                << setw(15) << choferes[i].getCedula()
                << setw(15) << choferes[i].cantUsos() 
                << endl;
        }
    }
}
