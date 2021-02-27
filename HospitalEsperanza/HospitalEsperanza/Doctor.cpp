#include "Doctor.h"
#include "Paciente.h"

Doctor::Doctor() {
	pacientes = false;
	nombre = "";
	edad = 0;
	especialidad = "";
	id = "";
}



Doctor::Doctor(string nombre, int edad, string especialidad, string id, bool pacientes) {
	this->nombre = nombre;
	this->edad = edad;
	this->especialidad = especialidad;
	this->id = id;
	this->pacientes = pacientes;
}

Doctor::~Doctor()
{
}

void Doctor::setNombre(string nombre)
{
	this->nombre = nombre;
}

string Doctor::getNombre()
{
	return nombre;
}

void Doctor::setEdad(int edad)
{
	this->edad = edad;
}

int Doctor::getEdad()
{
	return edad;
}

void Doctor::setEspecialidad(string especialidad)
{
	this->especialidad = especialidad;
}

string Doctor::getEspecialidad1()
{
	return especialidad;
}

void Doctor::setID(string id)
{
	this->id = id;
}

string Doctor::getID()
{
	return id;
}

void Doctor::setPacientes(bool pacientes)
{
	this->pacientes = pacientes;
}

bool Doctor::getPacientes()
{
	return pacientes;
}

string Doctor::toString()
{
	stringstream x;
	x << "Nombre del Doctor: " << nombre << endl;
	x << "Edad del Doctor: " << edad << endl;
	x << "Especialidad del Doctor: " << especialidad << endl;
	x << "Identificacion del Doctor: " << id << endl << endl;
	return x.str();
}
