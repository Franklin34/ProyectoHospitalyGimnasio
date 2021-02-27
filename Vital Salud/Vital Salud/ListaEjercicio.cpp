#include "ListaEjercicio.h"

ListaEjercicio::ListaEjercicio()
{
	cabecera = NULL;
	numdenodos = 0;
}

ListaEjercicio::~ListaEjercicio()
{
}

void ListaEjercicio::insertarEjercicio(Ejercicio*a)
{
	NodoEjercicio* nuevo_nodo = new NodoEjercicio(a);
	NodoEjercicio* temp = cabecera;

	if (!cabecera) {
		cabecera = nuevo_nodo;
	}
	else {
		nuevo_nodo->setSig(cabecera);
		cabecera = nuevo_nodo;

		while (temp->getSig() != NULL) {
			temp = temp->getSig();
		}
	}
	numdenodos++;
}

string ListaEjercicio::mostrarejercicios()
{
	stringstream x;

	NodoEjercicio* temp = cabecera;

	if (!cabecera) {
		x << "No hay ejercicios ingresados" << endl;
	}
	else {
		while (temp) {
			x << temp->imprimir();
			if (!temp->getSig());
				temp = temp->getSig();
		}
	}
	x << endl << endl;

	return x.str();
}
