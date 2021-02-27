#include "Ejercicio.h"

Ejercicio::Ejercicio()
{
	partedecuerpo = "";
	nombredelejercicio = "";
	series = 0;
	repeticiones = 0;
}

Ejercicio::Ejercicio(string partedecuerpo, string nombredelejercicio, int series, int repeticiones)
{
	this->partedecuerpo = partedecuerpo;
	this->nombredelejercicio = nombredelejercicio;
	this->series = series;
	this->repeticiones = repeticiones;
}

Ejercicio::~Ejercicio()
{
}

void Ejercicio::setParte(string partedelcuerpo)
{
	this->partedecuerpo = partedecuerpo;
}

string Ejercicio::getParte()
{
	return partedecuerpo;
}

void Ejercicio::setNombEjercicio(string nombredelejercicio)
{
	this->nombredelejercicio = nombredelejercicio;
}

string Ejercicio::getNombEjercicio()
{
	return nombredelejercicio;
}

void Ejercicio::setSeries(int series)
{
	this->series = series;
	
}

int Ejercicio::getSeries()
{
	return series;
}

void Ejercicio::setRepeticiones(int repeticiones)
{
	this->repeticiones = repeticiones;
}

int Ejercicio::getRepeticiones()
{
	return repeticiones;
}

string Ejercicio::toString()
{
	stringstream x;

	x << "-> Parte del cuerpo: " << partedecuerpo << endl;
	x << "Nombre: " << nombredelejercicio << endl;
	x << "Series: " << series << endl;
	x << "Repeticiones: " << repeticiones << endl;
	x << endl;
	
	return x.str();
}