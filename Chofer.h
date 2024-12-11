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
    bool disponible;
    
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
    void setDisponible(bool disponible);
    
    // GET
    string getMarca();
    string getModelo();
    int getAnho();
    string getPlaca();
    string getSector();
    bool getDisponible();
    
    // Metodos
    void cargarChoferes();
    void imprimirChoferes();
    string actualizarUbicacion();
    void agregarChofer();
    void modificarChofer(int cedula);
	void eliminarChofer(int cedula);
    void guardarChoferes();
    int cantChoferes();
    string darSector(int j);
    Chofer darChofer(int j);
    void imprimirChofer(int j);
    void sumarUso(int j);
    int cantUsosChofer(int j);
    bool disponibilidad(int i);
    void noDisponible(int i);
    void actualizarSector(int i, string destino);
    string finalizarTrasladoChofer(string placa);
    
    int darCedulaChofer(int j);
    
    // Mostrar el Chofer Completo
    void mostrarTodo(int j);
    
    // Metodo generarreporte
    void generarReporte(ofstream& reporte);
};

#endif

