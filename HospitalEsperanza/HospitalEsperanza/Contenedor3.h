#include "Paciente.h"
#include "Contenedor.h"

class Contenedor3
{
private:
	Paciente **pac;
	int cantidad;
	int tamano;
public:
	Contenedor3();
	~Contenedor3();
	bool insertarpaciente(Paciente*);
	string imprimepacientes();
	bool eliminapacienteporID(string id);
	bool rechazar(string id);
	string buscarPaciente(string);
	string listadepacientespordoctor(string);
	bool dardealta(string,Pabellon*);
	void cambiardedoctor(string,string);
	string imprimenombres();
	bool existepacientes(string);

};

