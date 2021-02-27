#ifndef SOCIO_H
#define SOCIO_H
#include <iostream>
#include <sstream>
#include "Persona.h"
#include "Rutina.h"
using namespace std;

class Socio;
class Instructor;

class Socio : public Persona
{
private:
	Instructor* elInstructor;
	string correo;
	Rutina** vect;
	string fechaInscripcion;
	string Idinstructor;
	int tamano;
	int cantidad;
public:
	Socio();
	Socio(string elNombre);
	Socio(string nombre, string cedula, string telefono, string correo, string fechaInscripcion,string Idinstructor);
	~Socio();
	void setCorreo(string correo);
	string getCorreo();
	void setInstructor(Instructor*);
	Instructor* getInstructor();
	void setFechaInsc(string fechaInscripcion);
	string getFechaInsc();
	string toString();
	string toString2(string id);
	string getIdinstructor();

	bool insertarRutina(Rutina*x);
	void setTamano(int tamano);
	int gettamano();
};
#endif // !SOCIO_H
