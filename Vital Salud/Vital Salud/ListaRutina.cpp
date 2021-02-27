#include "ListaRutina.h"

ListaRutina::ListaRutina()
{
	cabecera = NULL;
	numeronodos = 0;
}

ListaRutina::~ListaRutina()
{
}

void ListaRutina::insertarRutina(Rutina*a)
{
	NodoRutina* nuevo_nodo = new NodoRutina(a);
	NodoRutina* temp = cabecera;

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
	numeronodos++;
}


string ListaRutina::devolverRutinaVencida(FechaHora*a, string nombre)
{
	stringstream x;

	NodoRutina* temp = cabecera;

	if (!cabecera) {
		x << "No hay Rutinas" << endl;
	}
	else {
		while (temp) {
			x << endl;
			x << temp->imprimir(a,nombre);
			if (!temp->getSig());
			temp = temp->getSig();
		}
	}
	x << endl << endl;

	return x.str();
}

string ListaRutina::imprimirrutinasdesocio(string nombre,FechaHora*s)
{
	stringstream x;

	NodoRutina* temp = cabecera;

	if (!cabecera) {
		x << "No tiene rutinas" << endl;
	}
	else {
		while (temp) {
			if (temp->getData()->getNombredelsocio() == nombre) {
				x << temp->imprimir2(s);
				if (!temp->getSig());
			}
			temp = temp->getSig();
		}
	}
	x << endl << endl;

	return x.str();
}

string ListaRutina::imprimirRutinaespecifica(int id,FechaHora*p)
{
	stringstream x;

	NodoRutina* temp = cabecera;

	if (!cabecera) {
		x << "No hay Rutinas ingresados" << endl;
	}
	else {
		while (temp) {
			if (temp->getData()->getCodijo() == id) {
				x << temp->imprimir(p);
				if (!temp->getSig());
			}
			temp = temp->getSig();
		}
	}
	x << endl << endl;

	return x.str();

}
