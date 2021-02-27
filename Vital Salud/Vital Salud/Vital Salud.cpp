#include "Control.h"
#include <iostream>
#include "Gotoxy.h"
#include "FechaYhora.h"

using namespace std;

int main()
{
	system("color 1f");

	ListaInstrutor* p = new ListaInstrutor();
	ListaSocio* o = new ListaSocio();
	FechaHora *y = new FechaHora();
	Instructor* op = new Instructor();
	Socio* t = new Socio();
	ListaRutina* a = new ListaRutina();
	ListaEjercicio* tp = new ListaEjercicio();
	ListaMedicion* qw = new ListaMedicion();

	Gotoxy cy;
	cy.display(75,0);
	y->calcularFecha();

	Control* q = new Control();

	q->controlPrincipal(p,o,y,op,t,a,tp,qw);

	delete q;
	delete o;
	delete y;
	delete op;
	delete t;
	delete a;
	delete tp;
	delete qw;
}

