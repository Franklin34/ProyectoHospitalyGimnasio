#ifndef PABELLON_H
#define PABELLON_H
#include <sstream>
#include <iostream>
#include "Cama.h"

using namespace std;

class Pabellon
{
private:
	Cama **vect;
	int cantidad;
	int tamano;
	char codigo;
public:
	Pabellon(char x);
	Pabellon();
	void insertarCama(Cama*);
	bool eliminacama(string y);
	void cambiarcama(Cama*,string);
	bool cambiarcama2( string);
	string imprimacamas();
	bool eliminacama2(string);
	~Pabellon();
	void setCodigo(char codigo);
	char getCodigo();
	bool camasdisp(string);
	bool verificarcodigo(string);
	bool cambiar(string, string);
	int getCantCamas();
	bool existeCamas(); 
	

};
#endif
