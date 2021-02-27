#include "Pabellon.h"
#include "string.h"


Pabellon::Pabellon(char x)
{
	codigo = x;
	cantidad = 0;
	tamano = 20;
	vect = new Cama * [tamano];
	for (int i = 0; i < tamano; i++)
	{
		vect[i] = nullptr;
	}
	
}
Pabellon::Pabellon()
{
	cantidad = 0;
	tamano = 20;
	vect = new Cama * [tamano];
	for (int i = 0; i < tamano; i++)
	{
		vect[i] = nullptr;
	}
}
Pabellon::~Pabellon()
{
	cantidad = 0;
	for (int i = 0; i < cantidad; i++)
	{
		delete vect[i];
	}
	delete[] vect;
}
void Pabellon::setCodigo(char codigo)
{
	this->codigo = codigo;
}
char Pabellon::getCodigo()
{
	return codigo;
}
bool Pabellon::verificarcodigo(string x)
{
	for (int i = 0; i < tamano; i++) {
		if (vect[i]->getCodigo().compare(x) == 0) {
			return true;
		}
	}
	return false;
}
bool Pabellon::cambiar(string x, string y)
{
	for (int i = 0; i < cantidad; i++) {
		if (vect[i]->getEstado() == false && vect[i]->getCodigo() == y) {
			vect[i]->setEstado(true);
			vect[i]->setNombre(x);
			return true;
		}
	}
	return false;
}
int Pabellon::getCantCamas()
{
	return cantidad;
}
bool Pabellon::existeCamas()
{
	if (vect[0] || vect[1] || vect[2])
	{
		return true;
	}
	return false;
}
bool Pabellon::camasdisp(string c)
{
	bool band = false;
	for (int i = 0; i < cantidad; i++) {
		if (vect[i]->getCodigo() == c && vect[i]->getEstado() == false){
			band = true;
		}
	}
	if (band) {
		return true;
	}
	return false;
}
void Pabellon::insertarCama(Cama* c)
{
	for (int i = 0; i < tamano; i++)
	if (!vect[i])
	{
		vect[i] = c;
		cantidad++;
		return;
	}
}
bool Pabellon::eliminacama(string y)
{
	bool band = false;
	for (int i = 0; i < cantidad; i++) {
		if (vect[i]->getCodigo() == y && vect[i]->getEstado() == 0) {
			vect[i] = vect[i + 1];
			cantidad--;
			band = true;
		}	
	}
	if (band) {
		return true;
	}
	return false;
}

void Pabellon::cambiarcama(Cama*,string nombre)
{
	for (int i = 0; i < cantidad; i++) {
		if (vect[i]->getEstado() == false) {
			vect[i]->setEstado(true);
			vect[i]->setNombre(nombre);
		}
	}
}

bool Pabellon::cambiarcama2(string x)
{
	for (int i = 0; i < cantidad; i++) {
		if (vect[i]->getEstado() == true && vect[i]->getCodigo() == x) {
			vect[i]->setEstado(false);
			vect[i]->setNombre("Sin asignar");
			return true;
		}
	}
	return false;
}

string Pabellon::imprimacamas()
{
	
	stringstream x;
	string a = "";

	for (int i = 0; i < cantidad; i++) {
		stringstream d;
		cin.clear();
		d << getCodigo() << i + 1;
		a = d.str();
		vect[i]->setCodigo(a);
		if (vect[i]) {
			x << vect[i]->toString();
		}
		else if (!vect[i]) {
			x << '\n';
		}
		}
	return x.str();
}

bool Pabellon::eliminacama2(string y)
{
	bool band = false;
	for (int i = 0; i < cantidad; i++) {
		if (vect[i]->getCodigo() == y && vect[i]->getEstado() == true) {
			vect[i] = vect[i + 1];
			cantidad--;
			band = true;
		}
	}
	if (band) {
		return true;
	}
	return false;
}
