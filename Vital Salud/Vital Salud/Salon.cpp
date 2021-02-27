#include "Salon.h"

Salon::Salon()
{
	this->codijo = "";
	this->capacidad = 0;
	this->nombre = nombre;
}

Salon::Salon(string codijo, int capacidad, string nombre)
{
	this->codijo = codijo;
	this->capacidad = capacidad;
	this->nombre = nombre;
}

void Salon::setCodijo(string codijo)
{
	this->codijo = codijo;
}

string Salon::getCodijo()
{
	return codijo;
}

void Salon::setCapacidad(int capacidad)
{
	this->capacidad = capacidad;
}

int Salon::getCapacidad()
{
	return capacidad;
}

void Salon::setNombre(string nombre)
{
	this->nombre = nombre;
}

string Salon::getNombre()
{
	return nombre;
}

string Salon::toString()
{
	stringstream x;
	x << "Nombre: " << nombre << endl;
	x << "Capacidad: " << capacidad << endl;
	x << "Codijo: " << codijo << endl;

	return x.str();
}
