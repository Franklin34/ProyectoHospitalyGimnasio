#include "Especialidad.h"

Especialidad::Especialidad(string especialidad)
{
	this->especialidad = especialidad;
}

Especialidad::Especialidad()
{
	especialidad = "";
}

Especialidad::~Especialidad()
{
}
string Especialidad::toString()
{
	stringstream x;
	
		x << "Especialidades del Hospital: ";
		x << especialidad << endl << endl;
	
	return x.str();
}

void Especialidad::setEspecialidad(string especialidad)
{
	this->especialidad = especialidad;
}

string Especialidad::getEspecialidad()
{
	return especialidad;
}
