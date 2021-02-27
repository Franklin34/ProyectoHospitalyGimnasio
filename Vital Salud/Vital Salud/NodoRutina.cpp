#include "NodoRutina.h"

NodoRutina::NodoRutina()
{
	data = NULL;
	sig = NULL;
}

NodoRutina::NodoRutina(Rutina*a)
{
	this->data = a;
}

NodoRutina::~NodoRutina()
{
}

string NodoRutina::imprimir(FechaHora*op)
{
	stringstream x;
	x << data->toString(op);
	return x.str();
}

string NodoRutina::imprimir2(FechaHora*p)
{
	stringstream x;
	x << data->toString2(p);
	return x.str();
}

NodoRutina* NodoRutina::getSig()
{
	return sig;
}

void NodoRutina::setSig(NodoRutina*d)
{
	this->sig = d;
}

Rutina* NodoRutina::getData()
{
	return data;
}

void NodoRutina::setData(Rutina*a)
{
	this->data = a;
}

string NodoRutina::imprimir(FechaHora*a, string nombre)
{
	stringstream x;
	x << data->devolverRutinaVencida(a,nombre);
	return x.str();
}
