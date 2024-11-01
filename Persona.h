#ifndef PersonaH
#define PersonaH
#include <string> 

#include "Sector.h"

using namespace std;

// Clase para Heredar
class Persona {
protected:
    string nombre; 
    string apellido; 
    int edad;
    int cedula;
    int uso;
    
public:
    // Constructores
    Persona();
    Persona(string nombre, string apellido, int edad, int cedula);
	 
    // SET
    void setNombre(string nombre); 
    void setApellido(string apellido); 
    void setEdad(int edad);
    void setCedula(int cedula);
    
    // GET
    string getNombre(); 
    string getApellido(); 
    int getEdad();
    int getCedula();

	// Metodos
    void usado();
    int cantUsos();
};

#endif

