#include "Medicion.h"

Medicion::Medicion()
{
	idSocio = "";
	fechaRegistro = "";
	peso = 0;
	altura = 0.0;
	porcentajedegrasa = 0.0;
	IMC = 0.0;
	estado = "";
	perdidadegrasa = 0.0;
}

Medicion::Medicion(string idSocio, string fechaRegistro, int peso, float altura, float porcentajedegrasa,int perdidadegrasa)
{
	this->idSocio = idSocio;
	this->fechaRegistro = fechaRegistro;
	this->peso = peso;
	this->altura = altura;
	this->porcentajedegrasa = porcentajedegrasa;
	this->perdidadegrasa = perdidadegrasa;
}

Medicion::~Medicion()
{
}

string Medicion::getIdSocio()
{
	return idSocio;
}

string Medicion::toString(string id)
{
	stringstream x;

	if (idSocio == id) {
		x << "Fecha de registro: " << fechaRegistro << endl;
		x << "Peso: " << peso << endl;
		x << "Altura: " << altura << endl;
		x << "IMC: " << calcularIMC() << endl;
		x << "% Grasa: " << porcentajedegrasa << endl;
		x << "Estado: " << saberestado() << endl;
		x << endl;

		return x.str();
	}
	else {
		x << "";
		return x.str();
	}
	
	
}

float Medicion::calcularIMC()
{
	IMC = peso / (altura * altura);

	return IMC;
}

string Medicion::saberestado()
{
	if (IMC < 18.5) {
		estado = "Bajo Peso";
		return estado;
	}
	else if (IMC >= 18.5 && IMC <= 24.9) {
		estado = "Normal";
		return estado;
	}
	else if (IMC >= 25 && IMC <= 29.9) {
		estado = "Sobre Peso";
		return estado;
	}
	else if (IMC >= 30 && IMC <= 34.9) {
		estado = "Obesidad 1";
		return estado;
	}
	else if (IMC >= 35 && IMC <= 39.9) {
		estado = "Obesidad 2";
		return estado;
	}
	else if (IMC >= 40 && IMC <= 49.9) {
		estado = "Obesidad 3";
		return estado;
	}
	else if (IMC >= 50) {
		estado = "Obesidad 4";
		return estado;
	}
	else {
		estado = "No disponible";
		return estado;
	}
}

int Medicion::getPerdidadegrasa()
{
	return perdidadegrasa;
}

float Medicion::getPorcentajedegrasa()
{
	return porcentajedegrasa;
}

string Medicion::imprimirperdidadegrasa()
{
	stringstream x;

	if (perdidadegrasa > 0) {
		x << "Nombre: " << nombresocio << endl;
		x << "Id del socio: " << idSocio << endl;
		x << "Perdida de grasa: " << perdidadegrasa << "%" << endl;
		x << endl;
	}
	else {
		x << "";
	}
	

	return x.str();

	
}

void Medicion::setNombresocio(string nombre)
{
	this->nombresocio = nombre;
}

void Medicion::setInstructor(string instructor)
{
	this->instructor = instructor;
}

string Medicion::getInstructor()
{
	return instructor;
}
