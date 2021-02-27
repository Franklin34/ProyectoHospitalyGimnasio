#ifndef LISTAMEDICION_H
#define LISTAMEDICION_H
#include "NodoMedicion.h"

class ListaMedicion
{
private:
	NodoMedicion* cabecera;
public:
	ListaMedicion();
	~ListaMedicion();
	void insertarMedicion(Medicion*);
	void ordenarMedicion();
	string mostrarMedicion(string id);
	float calcularperdidadegrasa(string);
	string mostrarperdidadegrasa();
	string mejorinstructor();

};
#endif // !LISTAMEDICION_H
