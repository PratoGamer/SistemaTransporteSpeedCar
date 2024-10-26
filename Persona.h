#ifndef PersonaH
#define PersonaH
#include <string> 

using namespace std;

class Persona {
private:
    string nombre; 
    string apellido; 
    string edad;
    string cedula;

public:
    //constructores
    Persona();
    Persona(string nombre, string apellido, string edad, string cedula); 
    //set
    void setNombre(string nombre); 
    void setApellido(string apellido); 
    void setEdad(string edad);
    void setCedula(string cedula);
    //get
    string getNombre(); 
    string getApellido(); 
    string getEdad();
    string getCedula();
    
    void leer();
};

#endif

