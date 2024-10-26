#ifndef PersonaH
#define PersonaH
#include <string> 

using namespace std;

class Persona {
private:
    string nombre; 
    string apellido; 
    int edad;
    float cedula;

public:
    //constructores
    Persona();
    Persona(string nombre, string apellido, int edad, float cedula); 
    //set
    void setNombre(string nombre); 
    void setApellido(string apellido); 
    void setEdad(int edad);
    void setCedula(float cedula);
    //get
    string getNombre(); 
    string getApellido(); 
    int getEdad();
    float getCedula();
};

#endif

