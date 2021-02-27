#ifndef PACIENTE_H
#define PACIENTE_H
#include <iostream>
#include <sstream>
#include "Doctor.h"
using namespace std;

class Doctor;
	
class Paciente
{
private:
	string nombre;
	string id;
	string apellidos;
	string direccion;
	string cirugia;
	string fecha;
	string doctor;
	string prioridad;
	bool estado;
	string cama;
	string patologia;
public:
	Paciente();
	Paciente(string id, string nombre,string apellidos,string direccion,string patologia,string cirugia, bool estado,string prioridad,string fecha,string cama, string doctor);
	string toString();
	void setNombre(string nombre);
	string getNombre();
	void setID(string id);
	string getID();
	void setApellidos(string apellidos);
	string getApellidos();
	void setDireccion(string direccion);
	string getDireccion();
	void setCirugia(string cirugia);
	string getCirugia();
	void setFecha(string fecha);
	string getFecha();
	void setDoctor(string doctor);
	string getDoctor();
	void setPrioridad(string prioridad);
	string getPrioridad();
	void setEstado(bool estado);
	bool getEstado();
	void setCama(string cama);
	string getCama();
	void setPatologia(string patologia);
	string getPatologia();
};
#endif 
