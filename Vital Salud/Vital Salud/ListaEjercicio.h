#ifndef LISTAEJERCICIO_H
#define LISTAEJERCICIO_H
#include <iostream>
#include <sstream>
#include "NodoEjercicio.h"


class ListaEjercicio
{
private:
	NodoEjercicio* cabecera;
	int numdenodos;
public:
	ListaEjercicio();
	~ListaEjercicio();
	void insertarEjercicio(Ejercicio*);
	string mostrarejercicios();
};
#endif // !LISTAEJERCICIO_H
