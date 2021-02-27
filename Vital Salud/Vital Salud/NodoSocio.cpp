#include "NodoSocio.h"

NodoSocio::NodoSocio()
{
	data = NULL;
	sig = NULL;
}

NodoSocio::NodoSocio(Socio*s)
{
	this->data = s;
}

NodoSocio::~NodoSocio()
{
}

string NodoSocio::imprimirSocios()
{
	stringstream x;
	x << data->toString() << "->";
	return x.str();
}

NodoSocio* NodoSocio::getSig()
{
	return sig;
}

void NodoSocio::setSig(NodoSocio*s)
{
	this->sig = s;
}

Socio* NodoSocio::getData()
{
	return data;
}

void NodoSocio::setData(Socio*s)
{
	this->data = s;
}

string NodoSocio::imprimirSocios2(string id)
{
	stringstream x;
	x << data->toString2(id);
	return x.str();
}
