#ifndef CLASE_H
#define CLASE_H
#include <iostream>
#include <sstream>
#include "Instructor.h"

using namespace std;

class Clase
{
private:
	string codificacion;
	string nombre;
	string instructor;
	int salon;
	string horario;
public:
	Clase();
	Clase(string codificacion, string nombre, string instructor, int salon, string horario);
	~Clase();
	void setCodificacion(string codificacion);
	string getCodificacion();
	void setNombre(string nombre);
	string getNombre();
	void setInstructor(string instructor);
	string getInstructor();
	void setSalon(int salon);
	int getSalon();
	void setHorario(string horario);
	string getHorario();
	string toString();
};
#endif // !CLASE_
