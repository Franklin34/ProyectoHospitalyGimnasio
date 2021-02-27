#ifndef LISTASOCIO_H
#define LISTASOCIO_H
#include <iostream>
#include <sstream>
#include "NodoSocio.h"
#include <string>
#include <stdlib.h>
#include "ListaMedicion.h"

using namespace std;

class ListaSocio
{
private:
	NodoSocio* cabecera;
	int numdenodos;
public:
	ListaSocio();
	~ListaSocio();
	void insertarSocio(Socio*);
	string mostrarSocios();
	string mostrarSocios2(string id);
	string devolverNombre(string id);
	string devolverIdInstructor(string id);
	bool existeSocio(string id);
	string mostrarmedicion(string id,ListaMedicion*a);
	void mostrarmejoresresultadosenperdidadegrasa(ListaMedicion*);
	
};
#endif // !LISTASOCIO_H
