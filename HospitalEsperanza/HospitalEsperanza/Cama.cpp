#include "Cama.h"

Cama::Cama()
{
	codigo = "";
	estado = false;
	nombre = "";
}

Cama::Cama(bool estado, string nombre)
{
	this->estado = estado;
	this->nombre = nombre;
	this->codigo = codigo;
}

Cama::~Cama()
{
}

string Cama::toString()
{
	stringstream x;
	    x << endl;
	    x << "Codigo: " << codigo << endl;
		if (estado == true) {
			x << "Estado: " << "Ocupada" << endl;
		}
		else {
			x << "Estado: " << "Desocupada" << endl;
		}
		x << "Nombre del paciente: " << nombre << endl;
	
	return x.str();
}

void Cama::setEstado(bool estado)
{
	this->estado = estado;
}

bool Cama::getEstado()
{
	return estado;
}

void Cama::setNombre(string nombre)
{
	this->nombre = nombre;
}

string Cama::getNombre()
{
	return nombre;
}

void Cama::setCodigo(string codigo)
{
	this->codigo = codigo;
}

string Cama::getCodigo()
{
	return codigo;
}
