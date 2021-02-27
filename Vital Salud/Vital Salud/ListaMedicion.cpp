#include "ListaMedicion.h"

ListaMedicion::ListaMedicion()
{
	cabecera = NULL;
}

ListaMedicion::~ListaMedicion()
{
}

void ListaMedicion::insertarMedicion(Medicion*a)
{
	NodoMedicion* nuevo_nodo = new NodoMedicion(a);
	NodoMedicion* temp = cabecera;

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
}

void ListaMedicion::ordenarMedicion()
{
	Medicion* aux;
	NodoMedicion* temp = cabecera;
	NodoMedicion* temp2 = temp;

	while (temp) {
		temp2 = temp;

		while (temp2->getSig()) {
			temp2 = temp2->getSig();

			float perdida1 = temp->getData()->getPerdidadegrasa();
			float perdida2 = temp2->getData()->getPerdidadegrasa();
			if (perdida1 < perdida2) {
				aux = temp->getData();
				temp->setData(temp2->getData());
				temp2->setData(aux);
			}
		}
		temp = temp->getSig();
	}

}

string ListaMedicion::mostrarMedicion(string id)
{

	stringstream x;

	NodoMedicion* temp = cabecera;

	if (!cabecera) {
		x << "No hay mediciones ingresadas" << endl;
	}
	else {
		while (temp) {
			x << temp->imprimir(id);
			if (!temp->getSig());
			temp = temp->getSig();
		}
	}
	x << endl << endl;

	return x.str();
}

float ListaMedicion::calcularperdidadegrasa(string id)
{

	NodoMedicion* temp = cabecera;

	if (!cabecera) {
		cout  << "" << endl;
	}
	else {
		while (temp) {
			if (temp->getData()->getIdSocio() == id) {
				return temp->getData()->getPorcentajedegrasa();
			}
			if (!temp->getSig());
			temp = temp->getSig();
		}
	}

	cout  << endl << endl;

	
}

string ListaMedicion::mostrarperdidadegrasa()
{
	ordenarMedicion();

	stringstream x;

	NodoMedicion* temp = cabecera;

	if (!cabecera) {
		x << "No hay mediciones ingresadas" << endl;
	}
	else {
		while (temp) {
			x << temp->imprimirperdida();
			if (!temp->getSig());
			temp = temp->getSig();
		}
	}
	x << endl << endl;

	return x.str();
}

string ListaMedicion::mejorinstructor()
{
	stringstream x;

	ordenarMedicion();

	NodoMedicion* temp = cabecera;

	if (!cabecera) {
		x << "No hay mediciones ingresadas" << endl;
	}
	else {
		while (temp) {
			x << temp->imprimirperdida() << endl;
			x << "Instructor con mejores resultados: " << temp->getData()->getInstructor() << endl << endl;
			temp = NULL;
		}
	}

	return x.str();
	x << endl << endl;
}
