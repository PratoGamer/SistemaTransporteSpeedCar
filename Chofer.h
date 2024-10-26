#ifndef ChoferH
#define ChoferH
#include "Persona.h"
#include <string> 

using namespace std;

class Chofer : public Persona {
private:
    string marca;
    string modelo;
    string anho;
    string placa;
public:
    // Constructores
    Chofer();
    Chofer(string nombre, string apellido, string edad, string cedula, string marca, string modelo, string anho, string placa);
    
    // Setters
    void setMarca(string marca);
    void setModelo(string modelo);
    void setAnho(string anho);
    void setPlaca(string placa);
    
    // Getters
    string getMarca();
    string getModelo();
    string getAnho();
    string getPlaca();
};

#endif

