#include "ListaInstrutor.h"


ListaInstrutor::ListaInstrutor()
{
	cabecera = NULL;
	numerodenodos = 0;
}

ListaInstrutor::~ListaInstrutor()
{
}

void ListaInstrutor::insertarInstructor(Instructor* a)
{
	Nodo* nuevo_nodo = new Nodo(a);
	Nodo* temp = cabecera;

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
	numerodenodos++;
}

string ListaInstrutor::mostrarInstructores()
{
	stringstream x;

	Nodo* temp = cabecera;

	if (!cabecera) {
		x << "No hay instructores ingresados" << endl;
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

bool ListaInstrutor::rechazarInstructor(string id)
{
	Nodo* temp = cabecera;

	while (temp != NULL) {
		if (temp->getData()->getID() == id) {
			return true;
		}
		temp = temp->getSig();
	}
	return false;
}

string ListaInstrutor::imprimirnombre(string id)
{
	Nodo* temp = cabecera;

	while (temp != NULL) {
		if (temp->getData()->getID() == id) {
			return temp->getData()->getNombre();
			
		}
		temp = temp->getSig();
	}
}

string ListaInstrutor::imprimirSociosPorInstructor(ListaSocio*f,string id)
{
	stringstream x;

	Nodo* temp = cabecera;

	while (temp != NULL) {
		if (temp->getData()->getID() == id) {
			cout << endl;
			x << "Instructor: " << temp->getData()->getNombre() << endl<< endl;
			x << "Lista de Socios: " << endl;
			x << f->mostrarSocios2(id);
		}
		temp = temp->getSig();
	}

	return x.str();
}

string ListaInstrutor::mostrarRutinasvencidas(ListaRutina*a,string id,FechaHora*op)
{
	stringstream x;

	Nodo* temp = cabecera;

	while (temp != NULL) {
		if (temp->getData()->getID() == id) {
			cout << endl;
			x << "Instructor: " << temp->getData()->getNombre() << endl << endl;
			x << "Rutinas vencidas: " << endl;
			x << a->devolverRutinaVencida(op, temp->getData()->getNombre());
		}
		temp = temp->getSig();
	}

	return x.str();
}
