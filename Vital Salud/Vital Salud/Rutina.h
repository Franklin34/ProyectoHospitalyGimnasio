#ifndef RUTINA_H
#define RUTINA_H
#include <iostream>
#include <sstream>
#include "Ejercicio.h"
#include "ListaEjercicio.h"
#include "FechaYhora.h"
#include <string.h>

using namespace std;

class Rutina
{
private:
	int codijo;
	string objetivo;
	string fechaFinalizacion;
	string fechaCreacion;
	string instrucciones;
	string nombredelSocio;
	ListaEjercicio* listaeje;
	int dia;
	int mes;
	int anno;
	string nombreinstructor;
public:
	Rutina();
	Rutina(int codijo, string fechacreacion, string fechaFinalizacion, 
		string nombredelSocio, string objetivo,ListaEjercicio *,string nombreinstructor);
	~Rutina();
	void setCodijo(int codijo);
	int getCodijo();
	void setObjetivo(string objetivo);
	string getObjetivo();
	void setFechaFinalizacion(string fechaFinalizacion);
	string getFechaFinalizacion();
	void setFechaCreacion(string fechaCreacion);
	string getFechaCreacion();
	void setInstrucciones(string instrucciones);
	string getInstrucciones();
	string toString(FechaHora*);
	string toString2(FechaHora*);
	string getNombredelsocio();
	void setDia(int dia);
	int getDia();
	void setMes(int mes);
	int getMes();
	void setAnno(int anno);
	int getAnno();
	string devolverRutinaVencida(FechaHora*p,string id);
	string getNombredelInstructor();

};
#endif // !RUTINA_H
