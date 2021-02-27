#ifndef SALON_H
#define SALON_H
#include <iostream>
#include <sstream>

using namespace std;

class Salon
{
private:
	string codijo;
	int capacidad;
	string nombre;
public:
	Salon();
	Salon(string codijo, int capacida, string nombre);
	void setCodijo(string codijo);
	string getCodijo();
	void setCapacidad(int capacidad);
	int getCapacidad();
	void setNombre(string nombre);
	string getNombre();
	string toString();
};
#endif // !SALON_H
