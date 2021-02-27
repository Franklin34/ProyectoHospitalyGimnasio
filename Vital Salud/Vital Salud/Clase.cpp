#include "Clase.h"

Clase::Clase()
{
	codificacion = "";
	nombre = "";
	instructor = "";
	salon = 0;
	horario = "";
}

Clase::Clase(string codificacion, string nombre, string instructor, int salon, string horario)
{
	this->codificacion = codificacion;
	this->nombre = nombre;
	this->instructor = instructor;
	this->salon = salon;
	this->horario = horario;
}

Clase::~Clase()
{
}

void Clase::setCodificacion(string codificacion)
{
	this->codificacion = codificacion;
}

string Clase::getCodificacion()
{
	return codificacion;
}

void Clase::setNombre(string nombre)
{
	this->nombre = nombre;
}

string Clase::getNombre()
{
	return nombre;
}

void Clase::setInstructor(string instructor)
{
	this->instructor = instructor;
}

string Clase::getInstructor()
{
	return instructor;
}

void Clase::setSalon(int salon)
{
	this->salon = salon;
}

int Clase::getSalon()
{
	return salon;
}

void Clase::setHorario(string horario)
{
	this->horario = horario;
}

string Clase::getHorario()
{
	return horario;
}

string Clase::toString()
{
	stringstream x;

	x << "Codificacion Automatica: " << codificacion << endl;
	x << "Nombre de la Clase: " << nombre << endl;
	x << "Instructor de la clase: " << instructor << endl;
	x << "Salon de la Clase: " << salon << endl;
	x << "Horario de la Clase: " << horario << endl;

	return x.str();
}
