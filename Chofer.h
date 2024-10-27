#ifndef ChoferH
#define ChoferH
#include "Persona.h"
#include <iostream>
#include <string> 

using namespace std;

// Clase para los Choferes
class Chofer : public Persona {
private:
    string marca;
    string modelo;
    int anho;
    string placa;
public:
    // Constructores
    Chofer();
    Chofer(string nombre, string apellido, int edad, int cedula, string marca, string modelo, int anho, string placa);
    
    // SET
    void setMarca(string marca);
    void setModelo(string modelo);
    void setAnho(int anho);
    void setPlaca(string placa);
    
    // GET
    string getMarca();
    string getModelo();
    int getAnho();
    string getPlaca();
    
    // Metodos
    void leer();
    void mostrar();
};

#endif

