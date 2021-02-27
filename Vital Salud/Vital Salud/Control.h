#ifndef CONTROL_H
#define CONTROL_H
#include <iostream>
#include <sstream>
#include "ListaRutina.h"
#include "Gotoxy.h"
#include "FechaYhora.h"
#include "ListaInstrutor.h"
#include "ListaEjercicio.h"
#include "ListaMedicion.h"

using namespace std;

class Control
{
private:
	bool datos;
	int contador;
public:
	Control();
	Instructor* DatosInstructor(ListaInstrutor*);
	Socio* DatosSocio(ListaInstrutor*,FechaHora*);
	Rutina* DatosRutina(ListaSocio* k,Socio*,ListaInstrutor*,ListaEjercicio*);
	Medicion* DatosMedicion(ListaSocio*,ListaMedicion*,ListaInstrutor*c);
	void mostrarHistorial(ListaSocio*, Socio*, ListaInstrutor*,ListaRutina*,FechaHora*);
	void rechazarDatos(bool);
	void rutinasvencidasporinstructor(ListaInstrutor* a, ListaRutina* s,FechaHora*);
	bool getDatos();
	void controlPrincipal(ListaInstrutor*,ListaSocio*,FechaHora*,Instructor*,Socio*,ListaRutina*,ListaEjercicio*,ListaMedicion*);
	void menuInstructores(ListaInstrutor* g,ListaSocio*,Socio*,ListaRutina*,ListaEjercicio*,FechaHora*,ListaMedicion*);
	void mostrarmejoresresultadosperdida(ListaMedicion*);
	
};
#endif
