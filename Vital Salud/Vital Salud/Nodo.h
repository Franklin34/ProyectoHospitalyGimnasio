#ifndef NODO_H
#define NODO_H
#include <iostream>
#include <sstream>
#include "Instructor.h"

using namespace std;

class Nodo
{
private:
	Nodo* sig;
	Instructor* data;
public:
	Nodo();
	Nodo(Instructor*);
	~Nodo();
	string imprimir();
	Nodo* getSig();
	void setSig(Nodo*);
	Instructor* getData();
	void setData(Instructor*);
};
#endif