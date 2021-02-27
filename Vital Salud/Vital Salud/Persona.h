#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
#include <sstream>
using namespace std;

class Persona
{
protected:
	string nombre;
	string Id;
	string telefono;
public:
	Persona();
	~Persona();
	void setNombre(string nombre);
	string getNombre();
	void setID(string Id);
	string getID();
	void setTelefono(string telefono);
	string getTelefono();
	string toString();
};
#endif // !PERSONA_H
