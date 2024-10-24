#ifndef ChoferH
#define ChoferH

#include <Persona.h>

class Chofer : public Persona{
	private:
		char marca;
		char modelo;
		int anho;
		char placa;
	public:
			//constructores
		Chofer();
		Chofer(char nombre, char apellido, int edad, float cedula, char marca, char modelo, int anho, char placa);
			//set
		void setMarca(char marca);
		void setModelo(char modelo);
		void setAnho(int anho);
		void setPlaca(char placa);
			//get
		char getMarca();
		char getModelo();
		int getAnho();
		char getPlaca();
};

#endif
