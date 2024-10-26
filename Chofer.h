#ifndef ChoferH
#define ChoferH
#include "Persona.h"
#include <string> 

using namespace std;

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
    
    // Setters
    void setMarca(string marca);
    void setModelo(string modelo);
    void setAnho(int anho);
    void setPlaca(string placa);
    
    // Getters
    string getMarca();
    string getModelo();
    int getAnho();
    string getPlaca();
};

#endif

