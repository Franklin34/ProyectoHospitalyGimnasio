#include "Rutina.h"

Rutina::Rutina()
{
	this->codijo = 0;
	this->objetivo = "";
	this->fechaFinalizacion = "";
	this->fechaCreacion = "";
	this->instrucciones = "";
	this->listaeje = NULL;
}

Rutina::Rutina(int codijo, string objetivo, string fechaFinalizacion,string nombredelSocio, string fechaCreacion,ListaEjercicio*a,string nombreinstructor)
{
	this->codijo = codijo;
	this->objetivo = objetivo;
	this->fechaFinalizacion = fechaFinalizacion;
	this->fechaCreacion = fechaCreacion;
	this->nombredelSocio = nombredelSocio;
	this->listaeje = a;
	this->nombreinstructor = nombreinstructor;
}

Rutina::~Rutina()
{
}

void Rutina::setCodijo(int codijo)
{
	this->codijo = codijo;
}

int Rutina::getCodijo()
{
	return codijo;
}

void Rutina::setObjetivo(string objetivo)
{
	this->objetivo = objetivo;
}

string Rutina::getObjetivo()
{
	return objetivo;
}

void Rutina::setFechaFinalizacion(string fechaFinalizacion)
{
	this->fechaFinalizacion = fechaFinalizacion;
}

string Rutina::getFechaFinalizacion()
{
	return fechaFinalizacion;
}

void Rutina::setFechaCreacion(string fechaCreacion)
{
	this->fechaCreacion = fechaCreacion;
}

string Rutina::getFechaCreacion()
{
	return fechaCreacion;
}

void Rutina::setInstrucciones(string istrucciones)
{
	this->instrucciones = instrucciones;
}

string Rutina::getInstrucciones()
{
	return instrucciones;
}

string Rutina::toString(FechaHora*p)
{
	stringstream x;
	x << endl;

	if (anno > p->getAnno()) {
		x << "-> Codijo: " << codijo << endl;
		x << "Objetivo: " << objetivo << endl;
		x << "Fecha de Creacion: " << fechaCreacion << endl;
		x << "Fecha de Finalizacion: " << fechaFinalizacion << "(vigente)" << endl;
		x << "Nombre del Socio: " << nombredelSocio << endl;
		x << "Nombre del Instructor: " << nombreinstructor << endl;
		x << "Instrucciones: " << endl;
		x << listaeje->mostrarejercicios();

		return x.str();
	}
	else if (anno == p->getAnno() && mes > p->getMes()) {
		x << "Codijo: " << codijo << endl;
		x << "Objetivo: " << objetivo << endl;
		x << "Fecha de Creacion: " << fechaCreacion << endl;
		x << "Fecha de Finalizacion: " << fechaFinalizacion << "(vigente)" << endl;
		x << "Nombre del Socio: " << nombredelSocio << endl;
		x << "Nombre del Instructor: " << nombreinstructor << endl;
		x << "Instrucciones: " << endl;
		x << listaeje->mostrarejercicios();

		return x.str();
	}
	else if (anno == p->getAnno() && mes == p->getMes() && dia < p->getDia()) {
		x << "Codijo: " << codijo << endl;
		x << "Objetivo: " << objetivo << endl;
		x << "Fecha de Creacion: " << fechaCreacion << endl;
		x << "Fecha de Finalizacion: " << fechaFinalizacion << "(vencida)" << endl;
		x << "Nombre del Socio: " << nombredelSocio << endl;
		x << "Nombre del Instructor: " << nombreinstructor << endl;
		x << "Instrucciones: " << endl;
		x << listaeje->mostrarejercicios();

		return x.str();
	}
	else if (anno == p->getAnno() && mes == p->getMes() && dia > p->getDia()) {
		x << "Codijo: " << codijo << endl;
		x << "Objetivo: " << objetivo << endl;
		x << "Fecha de Creacion: " << fechaCreacion << endl;
		x << "Fecha de Finalizacion: " << fechaFinalizacion << "(vigente)" << endl;
		x << "Nombre del Socio: " << nombredelSocio << endl;
		x << "Nombre del Instructor: " << nombreinstructor << endl;
		x << "Instrucciones: " << endl;
		x << listaeje->mostrarejercicios();

		return x.str();
	}
	else {
		x << "Codijo: " << codijo << endl;
		x << "Objetivo: " << objetivo << endl;
		x << "Fecha de Creacion: " << fechaCreacion << endl;
		x << "Fecha de Finalizacion: " << fechaFinalizacion << "(vencida)" << endl;
		x << "Nombre del Socio: " << nombredelSocio << endl;
		x << "Nombre del Instructor: " << nombreinstructor << endl;
		x << "Instrucciones: " << endl;
		x << listaeje->mostrarejercicios();

		return x.str();
	}
}

string Rutina::toString2(FechaHora*p)
{
	stringstream x;

	if (anno > p->getAnno()) {
		x << "-> Codijo: " << codijo << endl;
		x << "Fecha de Creacion: " << fechaCreacion << "(vigente)" << endl;
		x << endl;
		return x.str();
	}
	else if (anno == p->getAnno() && mes > p->getMes()) {
		x << "-> Codijo: " << codijo << endl;
		x << "Fecha de Creacion: " << fechaCreacion << "(vigente)" << endl;
		x << endl;
		return x.str();
		
	}
	else if(anno == p->getAnno() && mes == p->getMes() && dia < p->getDia()) {
		x << "-> Codijo: " << codijo << endl;
		x << "Fecha de Creacion: " << fechaCreacion << "(vencida)" << endl;
		x << endl;


		return x.str();
	}
	else if (anno == p->getAnno() && mes == p->getMes() && dia > p->getDia()) {
		x << "-> Codijo: " << codijo << endl;
		x << "Fecha de Creacion: " << fechaCreacion << "(vigente)" << endl;
		x << endl;
		return x.str();
	}
	else {
		x << "-> Codijo: " << codijo << endl;
		x << "Fecha de Creacion: " << fechaCreacion << "(vencida)" << endl;
		x << endl;


		return x.str();
	}
}

string Rutina::getNombredelsocio()
{
	return nombredelSocio;
}

void Rutina::setDia(int dia)
{
	this->dia = dia;
}

int Rutina::getDia()
{
	return dia;
}

void Rutina::setMes(int mes)
{
	this->mes = mes;
}

int Rutina::getMes()
{
	return mes;
}

void Rutina::setAnno(int anno)
{
	this->anno = anno;
}

int Rutina::getAnno()
{
	return anno;
}

string Rutina::devolverRutinaVencida(FechaHora*p,string nombre)
{
	stringstream x;

	if (nombreinstructor == nombre) {

		if (anno < p->getAnno()) {

			x << "-> Nombre del socio: " << nombredelSocio << endl;
			x << "Codijo: " << codijo << endl;
			x << "Fecha de Vencimiento: " << fechaFinalizacion << endl;
			x << endl;
			return x.str();
		}
		else if (anno == p->getAnno() && mes < p->getMes()) {
			x << "-> Nombre del socio: " << nombredelSocio << endl;
			x << "Codijo: " << codijo << endl;
			x << "Fecha de Vencimiento: " << fechaFinalizacion << endl;
			x << endl;

			return x.str();

		}
		else if (anno == p->getAnno() && mes == p->getMes() && dia < p->getDia()) {
			x << "-> Nombre del socio: " << nombredelSocio << endl;
			x << "Codijo: " << codijo << endl;
			x << "Fecha de Vencimiento: " << fechaFinalizacion << endl;
			x << endl;

			return x.str();
		}
		else {
			x << "";

			return x.str();
		}
	}
	else {
		cout << "";

		return x.str();
	}
	

}

string Rutina::getNombredelInstructor()
{
	return nombreinstructor;
}
