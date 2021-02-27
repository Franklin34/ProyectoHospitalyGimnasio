#include "NodoEjercicio.h"

NodoEjercicio::NodoEjercicio()
{
	data = NULL;
	sig = NULL;
}

NodoEjercicio::NodoEjercicio(Ejercicio*a)
{
	this->data = a;
}

NodoEjercicio::~NodoEjercicio()
{
}

string NodoEjercicio::imprimir()
{
	stringstream x;
	x << data->toString();
	return x.str();
}

NodoEjercicio* NodoEjercicio::getSig()
{
	return sig;
}

void NodoEjercicio::setSig(NodoEjercicio*d)
{
	this->sig = d;
}

Ejercicio* NodoEjercicio::getData()
{
	return data;
}

void NodoEjercicio::setData(Ejercicio*a)
{
	this->data = a;
}
