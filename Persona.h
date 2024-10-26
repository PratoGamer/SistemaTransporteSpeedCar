#ifndef PersonaH
#define PersonaH
#include <string> 

using namespace std;

class Persona {
<<<<<<< HEAD
protected:
    std::string nombre; 
    std::string apellido; 
    int edad;
    float cedula;
=======
private:
    string nombre; 
    string apellido; 
    string edad;
    string cedula;
>>>>>>> 9d5afcf59ae30b7bcb14adb1314f1c567b38514b

public:
    // Constructores
    Persona();
<<<<<<< HEAD
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
=======
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
>>>>>>> 9d5afcf59ae30b7bcb14adb1314f1c567b38514b
};

#endif

