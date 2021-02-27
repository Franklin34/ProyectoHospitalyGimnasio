#include "Contenedor2.h"

Contenedor2::Contenedor2()
{
	cantidad = 0;
	tamano = 10;
	pabellones = new Pabellon * [tamano];
	for (int i = 0; i < tamano; i++)
	{
		pabellones[i] = new Pabellon(asignarLetra(i));
	}
}

Contenedor2::~Contenedor2()
{
	cantidad = 0;
	for (int i = 0; i < cantidad; i++)
		delete pabellones[i];
}
string Contenedor2::toString() {
	{
		stringstream s;
		for (int i = 0; i < tamano; i++)
		{
			if (getPabellones(i))
			{
				if (getPabellones(i)->existeCamas())
				{
					s << "Pabellon: " << getPabellones(i)->getCodigo() << endl;
					s << getPabellones(i)->imprimacamas() << endl << endl;
				}
			}
		}
		return s.str();
	}
}

Pabellon* Contenedor2::getPabellones(int i)
{
	return pabellones[i];
}
char Contenedor2::asignarLetra(int i)
{
	if (i == 0)
	{
		return 'A';
	}
	if (i == 1)
	{
		return 'B';
	}
	if (i == 2)
	{
		return 'C';
	}
	if (i == 3)
	{
		return 'D';
	}
	if (i == 4)
	{
		return 'E';
	}
	if (i == 5)
	{
		return 'F';
	}
	if (i == 6)
	{
		return 'G';
	}
	if (i == 7)
	{
		return 'H';
	}
	if (i == 8)
	{
		return 'I';
	}
	if (i == 9)
	{
		return 'J';
	}
}

Pabellon* Contenedor2::buscarpabellon(char letrica)
{
	for (int i = 0; i < tamano; i++)
	{
		if (getPabellones(i)->getCodigo() == letrica)
		{
			return getPabellones(i);
		}
	}
}