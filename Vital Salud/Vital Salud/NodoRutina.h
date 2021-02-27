#ifndef NODORUTINA_H
#define NODORUTINA_H
#include "Rutina.h"

class NodoRutina
{
private:
	NodoRutina* sig;
	Rutina* data;
public:
	NodoRutina();
	NodoRutina(Rutina*);
	~NodoRutina();
	string imprimir(FechaHora*);
	string imprimir2(FechaHora*);
	NodoRutina* getSig();
	void setSig(NodoRutina*);
	Rutina* getData();
	void setData(Rutina*);
	string imprimir(FechaHora*, string nombre);
};
#endif // !NODORUTIAN_H
