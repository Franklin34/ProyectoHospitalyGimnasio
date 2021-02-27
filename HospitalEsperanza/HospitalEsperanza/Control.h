#ifndef CONTROL_H
#define CONTROL_H
#include "Contenedor.h"
#include "Contenedor3.h"
#include "Contenedor2.h"

class Control
{
public:

	void controlPrincipal();
	string imprimeDoctor(Contenedor*);
	string imprimenombredeldoctor(Contenedor*);
	string imprimeEspecialidad(Contenedor*);
	string imprimecamas(Pabellon*);
	bool insertaDoctor(Contenedor*);
	bool insertaEspecialidad(Contenedor*);
    bool insertarcama(Pabellon*, Contenedor3*,Contenedor*);
	void eliminarcama(Pabellon*,Contenedor2&);
	void menuespecialidad(Contenedor*);
	void menudoctor(Contenedor*, Doctor *, Contenedor3*);
	void menucamas(Pabellon*, Contenedor*, Contenedor2&, Contenedor3*);
	void menupacientes(Pabellon*, Contenedor*, Contenedor2&, Contenedor3*);
	string imprimedoctorporespecialidad(Contenedor*);
	string imprimepaciente(Contenedor3*);
	void dardealtapaciente(Contenedor3*,Pabellon*,Contenedor2&);
	void despidedoctor(Contenedor *);
	void cambiarDoctor(Contenedor3&, Contenedor*);
	bool cambiarcama(Pabellon*,Contenedor2&, Contenedor3* k, Contenedor* y);
	bool insertaPaciente(Contenedor2&,Contenedor*,Pabellon*,Contenedor3*k);
	string buscapaciente(Contenedor3*f);
	string imprimirpacientesdeldoctor( Contenedor3*);
	Pabellon* escogerPabellon(Contenedor2& cont);
	Pabellon* escogerPabellon2(Contenedor2& cont);
};
#endif // !CONTROL_H
