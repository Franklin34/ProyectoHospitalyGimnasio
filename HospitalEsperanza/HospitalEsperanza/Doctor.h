#ifndef DOCTOR_H
#define DOCTOR_H
#include <iostream>
#include <sstream>
#include <string>
#include "Especialidad.h"

using namespace std;

class Doctor
{
private:
	string nombre;
	int edad;
	string especialidad;
	string id;
	bool pacientes;
public:
	Doctor();
	Doctor(string nombre, int edad, string especialidad, string id,bool pacientes);
	~Doctor();
	void setNombre(string nombre);
	string getNombre();
	void setEdad(int edad);
	int getEdad();
	void setEspecialidad(string especialidad);
	string getEspecialidad1();
	void setID(string id);
	string getID();
	void setPacientes(bool pacientes);
	bool getPacientes();
	string toString();

};
#endif
