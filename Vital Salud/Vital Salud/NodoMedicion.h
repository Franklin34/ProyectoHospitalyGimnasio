#ifndef NODOMEDICION_H
#define NODOMEDICIION_H
#include <iostream>
#include <sstream>
#include "Medicion.h"

using namespace std;

class NodoMedicion
{
private:
	NodoMedicion* sig;
	Medicion* data;
public:
	NodoMedicion();
	NodoMedicion(Medicion*a);
	~NodoMedicion();
	string imprimir(string id);
	string imprimirperdida();
	void setSig(NodoMedicion* a);
	NodoMedicion* getSig();
	void setData(Medicion* a);
	Medicion* getData();
};
#endif // !NODOMEDICION_H
