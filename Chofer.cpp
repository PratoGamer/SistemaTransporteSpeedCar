#include "Chofer.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>

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

// Metodos
void Chofer::leer(){
	Persona::leer();
	cin.get();
	cout << "Ingrese la Marca del Vehiculo: ";
	getline(cin, marca);
	cout << "Ingrese el Modelo del Vehiculo: ";
	getline(cin, modelo);
	cout << "Ingrese la Placa del Vehiculo: ";
	getline(cin, placa);
	cout << "Ingrese el Anho del Vehiculo: ";
	cin >> anho;
	
}

void Chofer::mostrar(){
	Persona::mostrar();
	
	cout << "Marca: " << this->marca << " | Modelo: " << this->modelo << endl;
	cout << "Anho: " << this->anho << " | Placa: " << this->placa << " | Sector: " << this->sector << endl;
}

void Chofer::cargarChoferes(){
	// Cargar Datos de Choferes
	ifstream txtChoferes("Choferes.txt");
	
	// Variables Auxiliares
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
		
		auxSector = misSectores.darSector( rand() % (cantSectores + 1) );
		
		choferes.push_back(Chofer(auxNombre, auxApellido, auxEdadInt, auxCedulaInt, auxMarca, auxModelo, auxAnhoInt, auxPlaca, auxSector));
		
	}
	txtChoferes.close();
}

void Chofer::imprimirChoferes(){
    for (int i = 0; i < choferes.size(); ++i) {
        cout << choferes[i].getNombre() << ", "
             << choferes[i].getApellido() << ", "
             << choferes[i].getEdad() << ", "
             << choferes[i].getCedula() << ", "
             << choferes[i].getMarca() << ", "
             << choferes[i].getModelo() << ", "
             << choferes[i].getPlaca() << ", "
             << choferes[i].getAnho() << ", "
             << choferes[i].getSector() << endl;
    }
}

void Chofer::actualizarUbicacion(){
    string auxPlaca, nuevoSector;
    bool encontrado = false;

    // Solicitar Datos del Usuario
    cout << "Ingrese la placa del vehículo: ";
    getline(cin, auxPlaca);

    for (int i = 0; i < choferes.size(); ++i) {
        if (choferes[i].getPlaca() == auxPlaca) {
            // Mostrar el Sector Actual
            cout << "Ubicación actual: " << choferes[i].getSector() << endl;

            // Solicitar el Nuevo Sector
            cout << "Ingrese el nuevo sector: ";
            getline(cin, nuevoSector);

            choferes[i].setSector(nuevoSector);

            cout << "Ubicación del chofer modificada correctamente." << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout << "No se encontro ningun chofer con la placa: " << auxPlaca << endl;
    }
}


void Chofer::agregarChofer() {
    // Variables Auxiliares para los Datos del Nuevo Chofer
    int edad, cedula, anho;

    // Solicitar Datos del Usuario
    cout << "Ingrese el nombre: ";
    cin.ignore();
    getline(cin, nombre);
    cout << "Ingrese el apellido: ";
    getline(cin, apellido);
    cout << "Ingrese la edad: ";
    cin >> edad;
    cout << "Ingrese la cedula: ";
    cin >> cedula;
    cin.ignore();
    cout << "Ingrese la marca del vehiculo: ";
    getline(cin, marca);
    cout << "Ingrese el modelo del vehiculo: ";
    getline(cin, modelo);
    cout << "Ingrese la placa del vehiculo: ";
    getline(cin, placa);
    cout << "Ingrese el ano del vehiculo: ";
    cin >> anho;
    cin.ignore();
    cout << "Ingrese el sector: ";
    getline(cin, sector);

    Chofer nuevoChofer(nombre, apellido, edad, cedula, marca, modelo, anho, placa, sector);
    choferes.push_back(nuevoChofer);

    cout << "Nuevo chofer agregado correctamente." << endl;
}

void Chofer::modificarChofer(int cedula) {
    for (int i = 0; i < choferes.size(); ++i) {
        if (choferes[i].getCedula() == cedula) {
            string nuevoNombre, nuevoApellido, nuevaMarca, nuevoModelo, nuevaPlaca, nuevoSector;
            int nuevaEdad, nuevoAnho;
            cout << "Nuevo nombre: ";
            cin.ignore();
            getline(cin, nuevoNombre);
            cout << "Nuevo apellido: ";
            getline(cin, nuevoApellido);
            cout << "Nueva edad: ";
            cin >> nuevaEdad;
            cout << "Nueva marca del vehiculo: ";
            cin.ignore();
            getline(cin, nuevaMarca);
            cout << "Nuevo modelo del vehiculo: ";
            getline(cin, nuevoModelo);
            cout << "Nueva placa del vehiculo: ";
            getline(cin, nuevaPlaca);
            cout << "Nuevo anho del vehiculo: ";
            cin >> nuevoAnho;
            cin.ignore();
            cout << "Nuevo sector: ";
            getline(cin, nuevoSector);

            choferes[i] = Chofer(nuevoNombre, nuevoApellido, nuevaEdad, cedula, nuevaMarca, nuevoModelo, nuevoAnho, nuevaPlaca, nuevoSector);
            cout << "Chofer modificado correctamente." << endl;
            return;
        }
    }
    cout << "Chofer con la cedula " << cedula << " no encontrado." << endl;
}


void Chofer::eliminarChofer(int cedula) {
    for (int i = 0; i < choferes.size(); ++i) {
        if (choferes[i].getCedula() == cedula) {
            choferes.erase(choferes.begin() + i);
            cout << "Chofer eliminado correctamente." << endl;
            return;
        }
    }
    cout << "Chofer con la cedula " << cedula << " no encontrado." << endl;
}

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
                    << choferes[i].getAnho() << "-"
                    << choferes[i].getSector() << endl;
    }
    txtChoferes.close();
}
