#ifndef PersonaH
#define PersonaH
#include <string> 

using namespace std;

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
	 
    // set
    void setNombre(string nombre); 
    void setApellido(string apellido); 
    void setEdad(int edad);
    void setCedula(int cedula);
    
    // get
    string getNombre(); 
    string getApellido(); 
    int getEdad();
    int getCedula();

    void leer();
};

#endif

