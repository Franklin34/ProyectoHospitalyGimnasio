#include "NodoMedicion.h"

NodoMedicion::NodoMedicion()
{
	data = NULL;
	sig = NULL;
}

NodoMedicion::NodoMedicion(Medicion* a)
{
	this->data = a;
}

NodoMedicion::~NodoMedicion()
{
}

string NodoMedicion::imprimir(string id)
{
	stringstream x;
	x << data->toString(id);
	return x.str();
}

string NodoMedicion::imprimirperdida()
{
	stringstream x;
	x << data->imprimirperdidadegrasa();
	return x.str();
}

void NodoMedicion::setSig(NodoMedicion* a)
{
	this->sig = a;
}

NodoMedicion* NodoMedicion::getSig()
{
	return sig;
}

void NodoMedicion::setData(Medicion* a)
{
	this->data = a;
}

Medicion* NodoMedicion::getData()
{
	return data;
}
