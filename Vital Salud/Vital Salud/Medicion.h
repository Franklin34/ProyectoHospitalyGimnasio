#ifndef MEDICION_H
#define MEDICION_H
#include <iostream>
#include <sstream>

using namespace std;

class Medicion
{
private:
	string idSocio;
	string fechaRegistro;
	int peso;
	float altura;
	float porcentajedegrasa;
	int perdidadegrasa;
	float IMC;
	string estado;
	string nombresocio;
	string instructor;
public:
	Medicion();
	Medicion(string idSocio, string fechaRegistro, int peso, float altura, float porcentajedegrasa,int perdidadegrasa);
	~Medicion();
	string getIdSocio();
	string toString(string id);
	float calcularIMC();
	string saberestado();
	int getPerdidadegrasa();
	float getPorcentajedegrasa();
	string imprimirperdidadegrasa();
	void setNombresocio(string nombre);
	void setInstructor(string instructor);
	string getInstructor();


};
#endif // !MEDICION_H
