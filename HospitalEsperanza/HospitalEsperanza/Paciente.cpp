#include "Paciente.h"
#include "Contenedor.h"
Paciente::Paciente()
{
	id = "";
	nombre = "";
	apellidos = "";
	direccion = "";
	patologia = "";
	cirugia = "";
	estado = false;
	prioridad = "";
	fecha = "";
	cama = "";
	doctor = "";
}

Paciente::Paciente(string id, string nombre, string apellidos, string direccion, string patologia, string cirugia, bool estado, string prioridad, string fecha, string cama, string doctor)
{
	this->id = id;
	this->nombre = nombre;
	this->apellidos = apellidos;
	this->direccion = direccion;
	this->patologia = patologia;
	this->cirugia = cirugia;
	this->estado = estado;
	this->prioridad = prioridad;
	this->fecha = fecha;
	this->cama = cama;
	this->doctor = doctor;
}

string Paciente::toString()
{
	stringstream x;
	x << "ID del paciente: " << id << endl;
	x << "Nombre del paciente: " << nombre << endl;
	x << "Apellidos del paciente: " << apellidos << endl;
	x << "Direccion del paciente: " << direccion << endl;
	x << "Patologia del paciente: " << patologia << endl;
	x << "Tipo de cirugia del paciente: " << cirugia << endl;
	if (estado == true) {
		x << "El estado del paciente es: " << "Internado" << endl;
	}
	else {
		x << "El estado del paciente es: " << "Dado de alta" << endl;
	}
	x << "Prioridad del paciente: " << prioridad << endl;
	x << "Fecha: " << fecha << endl;
	x << "Cama: " << cama << endl;
	x << "Doctor: "<< doctor << endl;

	return x.str();
}

void Paciente::setNombre(string nombre)
{
	this->nombre = nombre;
}

string Paciente::getNombre()
{
	return nombre;
}

void Paciente::setID(string id)
{
	this->id = id;
}

string Paciente::getID()
{
	return id;
}

void Paciente::setApellidos(string apellidos)
{
	this->apellidos = apellidos;
}

string Paciente::getApellidos()
{
	return apellidos;
}

void Paciente::setDireccion(string direccion)
{
	this->direccion = direccion;
}

string Paciente::getDireccion()
{
	return direccion;
}

void Paciente::setCirugia(string cirugia)
{
	this->cirugia = cirugia;
}

string Paciente::getCirugia()
{
	return cirugia;
}

void Paciente::setFecha(string fecha)
{
	this->fecha = fecha;
}

string Paciente::getFecha()
{
	return fecha;
}

void Paciente::setDoctor(string doctor)
{
	this->doctor = doctor;
}

string Paciente::getDoctor()
{
	return doctor;
}

void Paciente::setPrioridad(string prioridad)
{
	this->prioridad = prioridad;
}

string Paciente::getPrioridad()
{
	return prioridad;
}

void Paciente::setEstado(bool estado)
{
	this->estado = estado;
}

bool Paciente::getEstado()
{
	return estado;
}

void Paciente::setCama(string cama)
{
	this->cama = cama;
}

string Paciente::getCama()
{
	return cama;
}

void Paciente::setPatologia(string patologia)
{
	this->patologia = patologia;
}

string Paciente::getPatologia()
{
	return patologia;
}

