#include "Nodo.h"

Nodo::Nodo()
{
	data = NULL;
	sig = NULL;
}

Nodo::Nodo(Instructor*a)
{
	this->data = a;
}

Nodo::~Nodo()
{
}

string Nodo::imprimir()
{
	stringstream x;
	x << data->toString();
	return x.str();
}

Nodo* Nodo::getSig()
{
	return sig;
}

void Nodo::setSig(Nodo*d)
{
	this->sig = d;
}

Instructor* Nodo::getData()
{
	return data;
}

void Nodo::setData(Instructor*a)
{
	this->data = a;
}
