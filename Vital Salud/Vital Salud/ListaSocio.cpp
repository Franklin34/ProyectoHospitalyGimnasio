#include "ListaSocio.h"

ListaSocio::ListaSocio()
{
	cabecera = NULL;
	numdenodos = 0;
}

ListaSocio::~ListaSocio()
{
}

void ListaSocio::insertarSocio(Socio*s)
{
	NodoSocio* nuevo_nodo = new NodoSocio(s);
	NodoSocio* temp = cabecera;

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

string ListaSocio::mostrarSocios()
{
	stringstream x;

	NodoSocio* temp = cabecera;

	if (!cabecera) {
		x << "No hay Socios ingresados" << endl;
	}
	else {
		while (temp) {
			x << endl;
			x << temp->imprimirSocios();
			if (!temp->getSig());
			temp = temp->getSig();
		}
	}
	x << endl << endl;

	return x.str();
}

string ListaSocio::mostrarSocios2(string id)
{
	stringstream x;

	NodoSocio* temp = cabecera;

	if (!cabecera) {
		x << "No hay Socios ingresados" << endl;
	}
	else {
		while (temp) {
			x << endl;
			x << temp->imprimirSocios2(id);
			if (!temp->getSig());
			temp = temp->getSig();
		}
	}
	x << endl << endl;

	return x.str();
}

string ListaSocio::devolverNombre(string id)
{
	NodoSocio* temp = cabecera;

	while (temp != NULL) {
		if (temp->getData()->getID() == id) {
			return temp->getData()->getNombre();

		}
		temp = temp->getSig();
	}
}

string ListaSocio::devolverIdInstructor(string id)
{
	NodoSocio* temp = cabecera;

	while (temp != NULL) {
		if (temp->getData()->getID() == id) {
			return temp->getData()->getIdinstructor();

		}
		temp = temp->getSig();
	}
}

bool ListaSocio::existeSocio(string id)
{
	NodoSocio* temp = cabecera;

	while (temp != NULL) {
		if (temp->getData()->getID() == id) {
			return true;

		}
		temp = temp->getSig();
	}
	return false;
}

string ListaSocio::mostrarmedicion(string id,ListaMedicion*a)
{
	stringstream x;

	NodoSocio* temp = cabecera;

	while (temp != NULL) {
		if (temp->getData()->getID() == id) {
			x << a->mostrarMedicion(id);
		}
		temp = temp->getSig();
	}

	return x.str();
}

void ListaSocio::mostrarmejoresresultadosenperdidadegrasa(ListaMedicion*a)
{

}
