#ifndef NODOEJERCICIO_H
#define NODOEJERCICIO_H
#include <iostream>
#include <sstream>
#include "Ejercicio.h"

using namespace std;


class NodoEjercicio
{
private:
	NodoEjercicio* sig;
	Ejercicio* data;
public:
	NodoEjercicio();
	NodoEjercicio(Ejercicio*);
	~NodoEjercicio();
	string imprimir();
	NodoEjercicio* getSig();
	void setSig(NodoEjercicio*);
	Ejercicio* getData();
	void setData(Ejercicio*);
};
#endif // !NODOEJERCICIO_H
