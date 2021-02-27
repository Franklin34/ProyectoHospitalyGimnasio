#include "Instructor.h"

Instructor::Instructor()
{
	elSocio = NULL;

	tamano = 1;
	cantidad = 0;

	vect = new Socio * [tamano];
	for (int i = 0; i < tamano; i++) {
		vect[i] = new Socio();
	}
}

Instructor::Instructor(string nombre)
{
	this->nombre = nombre;
}

Instructor::Instructor(string nombre, string id, string telefono)
{
	this->nombre = nombre;
	this->Id = id;
	this->telefono = telefono;
}

Instructor::~Instructor()
{
}

string Instructor::toString()
{
	stringstream x;

	x << "-> Nombre: " << this->nombre << endl;
	x << "Cedula: " << this->Id << endl;
	x << "Telefono: " << this->telefono << endl;
	x << endl;

	return x.str();
}

void Instructor::asignarSocio(Socio*s)
{
	if (this->elSocio != NULL)
	{
		delete this->elSocio;
	}
	this->elSocio = s;
}

Socio* Instructor::getSocio()
{
	return elSocio;

}

bool Instructor::ingresarSocio(Socio*d)
{
	if (cantidad < tamano) {
		vect[cantidad] = d;
		cantidad++;
		return true;
	}
	return false;
}

void Instructor::setTamano(int tamano)
{
	this->tamano = tamano;
}

int Instructor::getTamano()
{
	return tamano;
	
}
