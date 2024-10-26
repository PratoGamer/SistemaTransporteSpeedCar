#ifndef PersonaH
#define PersonaH
#include <string> 

class Persona {
private:
    std::string nombre; 
    std::string apellido; 
    int edad;
    float cedula;

public:
    //constructores
    Persona();
    Persona(std::string nombre, std::string apellido, int edad, float cedula); 
    //set
    void setNombre(std::string nombre); 
    void setApellido(std::string apellido); 
    void setEdad(int edad);
    void setCedula(float cedula);
    //get
    std::string getNombre(); 
    std::string getApellido(); 
    int getEdad();
    float getCedula();
};

#endif

