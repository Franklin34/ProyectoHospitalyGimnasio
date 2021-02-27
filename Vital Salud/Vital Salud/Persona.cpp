#include "Persona.h"

Persona::Persona()
{
	this->nombre = "";
	this->Id = "";
	this->telefono = "";
}

Persona::~Persona()
{
}

void Persona::setNombre(string nombre)
{
	this->nombre = nombre;
}

string Persona::getNombre()
{
	return nombre;
}

void Persona::setID(string Id)
{
	this->Id = Id;
}

string Persona::getID()
{
	return Id;
}

void Persona::setTelefono(string telefono)
{
	this->telefono = telefono;
}

string Persona::getTelefono()
{
	return telefono;
}

string Persona::toString()
{
	stringstream x;
	x << "Nombre: " << nombre << endl;
	x << "Cedula: " << Id << endl;
	x << "Telefono: " << telefono << endl;

	return x.str();
}
