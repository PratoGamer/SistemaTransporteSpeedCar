#ifndef PersonaH
#define PersonaH
#include <string> 

using namespace std;

// Clase para Heredar
class Persona {
protected:
    string nombre; 
    string apellido; 
    int edad;
    int cedula;
    
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
    void leer();
    void mostrar();
};

#endif

