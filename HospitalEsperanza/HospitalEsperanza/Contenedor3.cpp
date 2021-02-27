#include "Contenedor3.h"

Contenedor3::Contenedor3()
{
	cantidad = 0;
	tamano = 200;
	pac = new Paciente * [tamano];
	for (int i = 0; i < tamano; i++) {
		pac[i] = new Paciente;
	}
}

Contenedor3::~Contenedor3()
{
	cantidad = 0;
	for (int i = 0; i < cantidad; i++) {
		delete pac[i];
	}delete[] pac;
}

bool Contenedor3::insertarpaciente(Paciente*p)
{
	if (cantidad < tamano) {
		pac[cantidad] = p;
		cantidad++;
		return true;
	}
	return false;
}



string Contenedor3::imprimepacientes()
{
	stringstream x;
	for (int i = 0; i < cantidad; i++) {
		x << "---Paciente " << i + 1 << endl;
		x << pac[i]->toString();
	}
	return x.str();
}

bool Contenedor3::eliminapacienteporID(string id)
{
	bool band = false;
	for (int i = 0; i < cantidad; i++) {
		if (pac[i]->getID().compare(id) == 0) {
			pac[i] = pac[i + 1];
			cantidad--;
			band = true;
		}
	}
	if (band) {
		return true;
	}
	return false;
}

bool Contenedor3::rechazar(string id)
{
	for (int i = 0; i < 20; i++) {
		if (pac[i]->getID().compare(id) == 0)
			return true;
	}
	return false;
}


string Contenedor3::buscarPaciente(string x)
{
	stringstream z;
	for (int i = 0; i < cantidad; i++) {
		if (pac[i]->getID().compare(x) == 0) {
			z << pac[i]->toString() << endl;
		}
	}
	return z.str();
}

string Contenedor3::listadepacientespordoctor(string y)
{
	stringstream x;
	for (int i = 0; i < cantidad; i++) {
		if (pac[i]->getDoctor().compare(y) == 0) {
			x << pac[i]->toString() << endl;
		}
	}
	return x.str();
}

bool Contenedor3::dardealta(string x,Pabellon*y)
{
	bool band = false;
	for (int i = 0; i < cantidad; i++) {
		if (pac[i]->getID() == x ) {
			pac[i] = pac[i + 1];
			cantidad--;
			band = true;
		}
	}
	if (band) {
		return true;
	}
	return false;
}

void Contenedor3::cambiardedoctor(string id, string doctor)
{
	for (int i = 0; i < cantidad; i++) {
		if (pac[i]->getID().compare(id) == 0) {
			pac[i]->setDoctor(doctor);
		}
	}

}

string Contenedor3::imprimenombres()
{
	stringstream x;
	for (int i = 0; i < cantidad; i++) {
		x << "---Paciente " << i + 1 << endl;
		x <<" Nombre: " << pac[i]->getNombre() << endl;
		x <<" ID: " << pac[i]->getID() << endl;
	}
	return x.str();

}

bool Contenedor3::existepacientes(string x)
{
	for (int i = 0; i < 20; i++) {
		if (pac[i]->getID().compare(x) == 0)
			return true;
	}
	return false;
}
