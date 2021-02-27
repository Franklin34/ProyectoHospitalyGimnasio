#include "Pabellon.h"
#include "Cama.h"
using namespace std;

class Contenedor2
{
private:
	Pabellon **pabellones;
	int cantidad;
	int tamano;
public:
	Contenedor2();
	string toString();
	Pabellon* getPabellones(int i);
	char asignarLetra(int i);
	~Contenedor2();
	Pabellon* buscarpabellon(char letrica);

};

