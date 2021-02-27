#ifndef NODOSOCIO_H
#define NODOSOCIO_H
#include <iostream>
#include <sstream>
#include "Socio.h"


using namespace std;

class NodoSocio
{
private:
	NodoSocio* sig;
	Socio* data;
public:
	NodoSocio();
	NodoSocio(Socio*);
	~NodoSocio();
	string imprimirSocios();
	NodoSocio* getSig();
	void setSig(NodoSocio*);
	Socio* getData();
	void setData(Socio*);
	string imprimirSocios2(string id);
};
#endif // !NODOSOCIO_H
