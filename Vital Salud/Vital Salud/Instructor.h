#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H
#include <iostream>
#include <sstream>
#include "Persona.h"
#include "Socio.h"

using namespace std;

class Socio;
class Instructor;

class Instructor : public Persona
{
private:
	Socio* elSocio;
	Socio** vect;
	int tamano;
	int cantidad;
public:
	Instructor();
	Instructor(string nombre);
	Instructor(string nombre, string id, string telefono);
	~Instructor();
	string toString();
	void asignarSocio(Socio*);
	Socio* getSocio();

	bool ingresarSocio(Socio*);
	void setTamano(int tamano);
	int getTamano();

};
#endif // !INSTRUCTOR_H
