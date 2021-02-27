#ifndef ESPECIALIDAD_H
#define ESPECIALIDAD_H
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Especialidad
{
private:
	string especialidad;
public:
	Especialidad(string especialidad);
	Especialidad();
	~Especialidad();
	string toString();
	void setEspecialidad(string especialidad);
	string getEspecialidad();

};
#endif 
