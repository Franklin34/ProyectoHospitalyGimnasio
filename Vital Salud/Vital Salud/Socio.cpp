#include "Socio.h"

Socio::Socio()
{
	this->correo = "";
	this->fechaInscripcion = "";
	this->Idinstructor = "";

	cantidad = 0;
	tamano = 1;

	vect = new Rutina * [tamano];

	for (int i = 0; i < tamano; i++) {
		vect[i] = new Rutina();
	}
}

Socio::Socio(string elNombre)
{
	this->nombre = elNombre;
}

Socio::Socio(string nombre, string cedula, string telefono, string correo, string fechaInscripcion, string Idinstructor)
{
	this->nombre = nombre;
	this->Id = cedula;
	this->telefono = telefono;
	this->correo = correo;
	this->fechaInscripcion = fechaInscripcion;
	this->Idinstructor = Idinstructor;
}

Socio::~Socio()
{
}

void Socio::setCorreo(string correo)
{
	this->correo = correo;
}

string Socio::getCorreo()
{
	return correo;
}

void Socio::setInstructor(Instructor*d)
{
	this->elInstructor = d;
}

Instructor* Socio::getInstructor()
{
	return elInstructor;
}

void Socio::setFechaInsc(string fechaInscripcion)
{
	this->fechaInscripcion = fechaInscripcion;
}

string Socio::getFechaInsc()
{
	return fechaInscripcion;
}

string Socio::toString()
{
	stringstream x;
	x << "Nombre: " << this->nombre << endl;
	x << "Cedula: " << this->Id << endl;
	x << "Telefono: " << this->telefono << endl;
	x << "Correo: " << this->correo << endl;
	x << "Fecha de Inscripcion: " << this->fechaInscripcion << endl;
	x << "Identificacion del Instructor: " << Idinstructor << endl;

	return x.str();
}

string Socio::toString2(string id)
{
	stringstream x;

	if (id == Idinstructor) {

		x << "Nombre: " << this->nombre << endl;
		x << "Cedula: " << this->Id << endl;

		return x.str();
	}
	else {
		x << "";

		return x.str();
	}
	
}

string Socio::getIdinstructor()
{
	return Idinstructor;
}

bool Socio::insertarRutina(Rutina* x)
{
	if (cantidad < tamano) {
		vect[cantidad] = x;
		cantidad++;
		return true;
	}
	return false;
}

void Socio::setTamano(int tamano)
{
	this->tamano = tamano;
}

int Socio::gettamano()
{
	return tamano;



}

