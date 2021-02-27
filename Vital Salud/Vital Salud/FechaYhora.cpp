#include "FechaYhora.h"

FechaHora::FechaHora() {

}

void FechaHora::calcularHora() {
	stringstream a;
	time_t tSac = time(NULL);
	struct tm* tmp = localtime(&tSac);
	a << tmp->tm_hour << ":" << tmp->tm_min << ":" << tmp->tm_sec;
	this->hora = a.str();
	cout << this->hora << endl;
}

string FechaHora::getFecha()
{
	return fecha;
}

int FechaHora::getDia()
{
	return dia;
}

int FechaHora::getMes()
{
	return mes;
}

int FechaHora::getAnno()
{
	return anno;
}

void FechaHora::calcularFecha() {
	stringstream b;
	time_t tSac = time(NULL);
	struct tm* tmp = localtime(&tSac);
	/*0 - 11 concatenacion*/
	b << tmp->tm_mday << "/" << tmp->tm_mon + 1 << "/" << tmp->tm_year + 1900;
	this->fecha = b.str();
	cout << this->fecha << endl;

	dia = tmp->tm_mday;
	mes = tmp->tm_mon + 1;
	anno = tmp->tm_year + 1900;
}

void FechaHora::calcularFecha2() {
	stringstream b;
	time_t tSac = time(NULL);
	std::tm bt{};
	string const fecha2;
	localtime_s(&bt, &tSac);
	b << bt.tm_mday << "-" << bt.tm_mon + 1 << "-" << bt.tm_year + 1900;
	this->fecha = b.str();
	cout << this->fecha << endl;
}

void FechaHora::calcularHora2() {
	stringstream a;
	time_t tSac = time(NULL);
	std::tm bt{};
	string const fecha2;
	localtime_s(&bt, &tSac);
	a << bt.tm_hour << ":" << bt.tm_min << ":" << bt.tm_sec;
	this->hora = a.str();
	cout << this->hora << endl;
}
