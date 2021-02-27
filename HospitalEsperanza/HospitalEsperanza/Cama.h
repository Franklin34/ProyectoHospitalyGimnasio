#ifndef CAMA_H
#define CAMA_H
#include <iostream>
#include <sstream>

using namespace std;

class Cama
{
private:
	string codigo;
	bool estado;
	string nombre;
public:
	Cama();
	Cama(bool estado,string nombre);
	~Cama();
	string toString();
	void setEstado(bool estado);
	bool getEstado();
	void setNombre(string nombre);
	string getNombre();
	void setCodigo(string codigo);
	string getCodigo();
};
#endif
