#ifndef PersonaH
#define PersonaH

class Persona{
	private:
		char nombre;
		char apellido;
		int edad;
		float cedula;
	public:
			//constructores
		Persona();
		Persona(char nombre, char apellido, int edad, float cedula);
			//set
		void setNombre(char nombre);
		void setApellido(char apellido);
		void setEdad(int edad);
		void setCedula(float cedula);
			//get
		char getNombre();
		char getApellido();
		int getEdad();
		float getCedula();
};

#endif
