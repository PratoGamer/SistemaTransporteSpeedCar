#ifndef PersonaH
#define PersonaH
#include <string> 

class Persona {
protected:
    std::string nombre; 
    std::string apellido; 
    int edad;
    float cedula;

public:
    // Constructores
    Persona();
    Persona(std::string nombre, std::string apellido, int edad, float cedula);
	 
    // SET
    void setNombre(std::string nombre); 
    void setApellido(std::string apellido); 
    void setEdad(int edad);
    void setCedula(float cedula);
    
    // GET
    std::string getNombre(); 
    std::string getApellido(); 
    int getEdad();
    float getCedula();
};

#endif

