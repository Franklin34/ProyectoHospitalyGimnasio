#ifndef EJERCICIO_H
#define EJERCICIO_H
#include <iostream>
#include <sstream>

using namespace std;

class Ejercicio
{
private:
	string partedecuerpo;
	string nombredelejercicio;
	int series;
	int repeticiones;
public:
	Ejercicio();
	Ejercicio(string partedecuerpo, string nombredelejercicio, int series, int repeticiones);
	virtual ~Ejercicio();
	void setParte(string partedelcuerpo);
	string getParte();
	void setNombEjercicio(string nombredelejercicio);
	string getNombEjercicio();
	void setSeries(int series);
	int getSeries();
	void setRepeticiones(int repeticiones);
	int getRepeticiones();
	string toString();
};
#endif
