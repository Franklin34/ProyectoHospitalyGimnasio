#include "Contenedor.h"
#include "Doctor.h"
#include "Especialidad.h"
#include "Cama.h"

Contenedor::Contenedor() {
	cantidad = 0;
	tamano = 20;
	tamano2 = 10;
	cantidad2 = 0;
	vect = new Especialidad * [tamano2];
	for (int i = 0; i < tamano2; i++) {
		vect[i] = new Especialidad;
	}
	vector = new Doctor * [tamano];
	for (int i = 0; i < tamano; i++) {
		vector[i] = new Doctor;
	}
}

Contenedor::~Contenedor()
{
	cantidad = 0;
	cantidad2 = 0;
	for (int i = 0; i < cantidad; i++) {
		delete vector[i];
	}
	delete[] vector;

	for (int i = 0; i < cantidad2; i++) {
		delete vect[i];
	}
	delete[] vect;

}

bool Contenedor::insertaDoctor(Doctor *i)
{
	if (cantidad2 < tamano) {
		vector[cantidad2] = i;
		cantidad2++;
		return true;
	}
	return false;
}

string Contenedor::imprimeNombresdeldoctor()
{
	stringstream x;
	for (int i = 0; i < cantidad2; i++) {
		x << "---Doctor " << i + 1 << endl;
		x << vector[i]->getNombre() << endl << endl;
	}
	return x.str();
}

bool Contenedor::insertarEspecialidad(Especialidad* e)
{
	if (cantidad < tamano2) {
		vect[cantidad] = e;
		cantidad++;
		return true;
	}
	return false;
}

bool Contenedor::eliminaDoctor(string especialidad)
{
	for (int i = 0; i < 10; i++) {
		if (vect[i]->getEspecialidad().compare(especialidad) == 0) 
			return true;
	}
	return false;
}
bool Contenedor::despedirdoctor(string x)
{
	bool band = false;
	for (int i = 0; i < cantidad2; i++) {
		if (vector[i]->getNombre() == x && vector[i]->getPacientes() == false) {
			vect[i] = vect[i + 1];
			cantidad2--;
			band = true;
		}
	}
	if (band) {
		return true;
	}
	return false;
}

void Contenedor::cambiarestadopaciente(string x)
{ 
	for (int i = 0; i < cantidad2; i++) {
		if (vector[i]->getPacientes() == false && vector[i]->getNombre() == x) {
			vector[i]->setPacientes(true);
		}
		}
	}

bool Contenedor::rechazaDoctor(string id)
{
	for (int i = 0; i < 20; i++) {
		if (vector[i]->getID().compare(id) == 0) 
			return true;
	}
	return false;
}


bool Contenedor::rechazaPaciente(string doctor)
{
	for (int i = 0; i < 20; i++) {
		if (vector[i]->getNombre().compare(doctor) == 0)
			return true;
	}
	return false;
}

string Contenedor::imprimedoctorporespecialidad()
{
	stringstream x;
	for (int i = 0; i < cantidad2; i++) {
		if (vector[i]->getEspecialidad1().compare(vect[i]->getEspecialidad()) == 0) {
			x << "---Especialidad: " << vect[i]->getEspecialidad() << endl;
			x << vector[i]->toString() << endl;
		}
	}
	return x.str();
}

string Contenedor::imprimeDoctores()
{
	stringstream x;
	for (int i = 0; i < cantidad2; i++) {
		x << "---Doctor " << i+1 << endl;
		x << vector[i]->toString();
	}
	return x.str();
}

string Contenedor::imprimeEspecialidad()
{
	stringstream x;
	for (int i = 0; i < cantidad; i++) {
		x << "---Especialidad " << i + 1 << endl;
		x << vect[i]->toString();
	}
	return x.str();
}

