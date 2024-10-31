#ifndef ChoferH
#define ChoferH
#include "Persona.h"
#include "Sector.h"
#include <iostream>
#include <string> 
#include <vector>

using namespace std;

// Clase para los Choferes
class Chofer : public Persona {
private:
	vector <Chofer> choferes;
    string marca;
    string modelo;
    int anho;
    string placa;
    string sector;
    
    Sector misSectores;
public:
    // Constructores
    Chofer();
    Chofer(string nombre, string apellido, int edad, int cedula, string marca, string modelo, int anho, string placa, string sector);
    
    // SET
    void setMarca(string marca);
    void setModelo(string modelo);
    void setAnho(int anho);
    void setPlaca(string placa);
    void setSector(string sector);
    
    // GET
    string getMarca();
    string getModelo();
    int getAnho();
    string getPlaca();
    string getSector();
    
    // Metodos
    void leer();
    void mostrar();
    void cargarChoferes();
    void imprimirChoferes();
    void actualizarUbicacion();
    void agregarChofer();
    void modificarChofer(int cedula);
	void eliminarChofer(int cedula);
    void guardarChoferes();
    int cantChoferes();
    string darSector(int j);
    void imprimirChofer(int j);
    void sumarUso(int j);
    int cantUsosChofer(int j);
};

#endif

