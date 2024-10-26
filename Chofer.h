#ifndef ChoferH
#define ChoferH
#include "Persona.h"

class Chofer : public Persona {
private:
    std::string marca;
    std::string modelo;
    int anho;
    std::string placa;
public:
    // Constructores
    Chofer();
    Chofer(std::string nombre, std::string apellido, int edad, float cedula, std::string marca, std::string modelo, int anho, std::string placa);
    
    // Setters
    void setMarca(std::string marca);
    void setModelo(std::string modelo);
    void setAnho(int anho);
    void setPlaca(std::string placa);
    
    // Getters
    std::string getMarca();
    std::string getModelo();
    int getAnho();
    std::string getPlaca();
};

#endif

