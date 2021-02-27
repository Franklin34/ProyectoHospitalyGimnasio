#ifndef LISTARUTINA_H
#define LISTARUTINA_H
#include <iostream>
#include <sstream>
#include "NodoRutina.h"
#include "ListaSocio.h"

class ListaRutina
{
private:
	NodoRutina* cabecera;
	int numeronodos;
public:
	ListaRutina();
	~ListaRutina();
	void insertarRutina(Rutina*);
	string devolverRutinaVencida(FechaHora*, string);
	string imprimirrutinasdesocio(string id,FechaHora*);
	string imprimirRutinaespecifica(int id,FechaHora*);


};
#endif // !LISTARUTINA_H
