#ifndef LISTAINSTRUCTOR_H
#define LISTAINSTRUCTOR_H
#include <iostream>
#include <sstream>
#include "Nodo.h"
#include <string>
#include <stdlib.h>
#include "ListaSocio.h"
#include "ListaRutina.h"

class ListaInstrutor
{
private:
	Nodo* cabecera;
	int numerodenodos;
public:
	ListaInstrutor();
	~ListaInstrutor();
	void insertarInstructor(Instructor*);
	string mostrarInstructores();
	bool rechazarInstructor(string id);
	string imprimirnombre(string id);
	string imprimirSociosPorInstructor(ListaSocio*,string id);
	string mostrarRutinasvencidas(ListaRutina*,string id,FechaHora*);
};
#endif // !LISTAINSTRUCTOR_H
