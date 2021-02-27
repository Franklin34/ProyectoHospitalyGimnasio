#ifndef CONTENEDOR_H
#define CONTENEDOR_H
#include "Especialidad.h"
#include "Doctor.h"
#include "Pabellon.h"
#include "Paciente.h"
class Contenedor
{
private:
	Especialidad **vect;
	Doctor **vector;
	int cantidad;
	int cantidad2;
	int tamano;
	int tamano2;
public:
	Contenedor();
	~Contenedor();
	bool insertaDoctor(Doctor *);
	string imprimeNombresdeldoctor();
	bool insertarEspecialidad(Especialidad* e);
	bool eliminaDoctor(string especialidad);
	bool despedirdoctor(string x);
	void cambiarestadopaciente(string);
	bool rechazaDoctor(string id);
	bool rechazaPaciente(string doctor);
	string imprimedoctorporespecialidad();
	string imprimeDoctores();
	string imprimeEspecialidad();
};
#endif 
