#ifndef FECHAHORA_H
#define FECHAHORA_H
#define _CRT_SECURE_NO_WARNINGS
#include<ctime>
#include<string>
#include<iostream>
#include<sstream>
using namespace std;

class FechaHora {

private:
	string hora;
	string fecha;
	int anno;
	int mes;
	int dia;
public:
	FechaHora();
	void calcularFecha();
	void calcularFecha2();
	void calcularHora2();
	void calcularHora();
	string getFecha();
	int getDia();
	int getMes();
	int getAnno();

};
#endif // !FECHAYHORA_H